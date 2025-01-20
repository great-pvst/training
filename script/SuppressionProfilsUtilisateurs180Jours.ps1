# Profils à conserver
$profilsAconserver = @("Admin", "admin", "Administrateur", "User", "user")
# Récupération de la liste des profils utilisateurs
$recuperationProfils = Get-CimInstance -ClassName Win32_UserProfile | Where-Object { !$_.Special -and !$profilsAconserver.Contains($_.LocalPath.Split("\")[-1]) }
# Récupération de la date limite (180 jours en arrière)
$dateLimite = (Get-Date).AddMonths(-6)

# Suppression des profils inutilisés
foreach ($profils in $recuperationProfils) {
    #Date dernière utilisation du profil
    $dateDerniereUtilisation = $profils.LastUseTime

    if ($dateDerniereUtilisation -ge $dateLimite) {
        Write-Host "Le profil $($profils.LocalPath) est récent" `n
    }
    else {
        Write-Host "Suppression du profil inutilisé : $($profils.LocalPath)"
        Remove-Item $profils.LocalPath -Confirm:$false
        Remove-CimInstance -InputObject $profils -Confirm:$false
    }
}

Clear-RecycleBin -Force -ErrorAction:Ignore

<#
$profilsAconserver = @("Admin", "admin", "Administrateur", "administrateur", "ADMIN", "Administrator", "User", "user")
Get-CimInstance -ClassName Win32_UserProfile | Where-Object {!$_.Special -and !$profilsAconserver.Contains($_.LocalPath.Split("\")[-1]) } | Where-Object { (($_.LastUseTime) -lt (Get-Date).AddDays((-180)))} | Format-Table LocalPath | Remove-CimInstance
Clear-RecycleBin -Force 
#>