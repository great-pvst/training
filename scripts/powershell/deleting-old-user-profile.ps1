# Profiles to save
$profilsAconserver = @("Admin", "admin", "Administrateur", "User", "user")

# user profile list recovery
$recuperationProfils = Get-CimInstance -ClassName Win32_UserProfile | Where-Object { !$_.Special -and !$profilsAconserver.Contains($_.LocalPath.Split("\")[-1]) }

# 6 months old
$dateLimite = (Get-Date).AddMonths(-6)

# deleting user profiles
foreach ($profils in $recuperationProfils) {
    
    $dateDerniereUtilisation = $profils.LastUseTime

    if ($dateDerniereUtilisation -ge $dateLimite) {
        Write-Host "$($profils.LocalPath) profile is new" `n
    }
    else {
        Write-Host "Unused profile deleting : $($profils.LocalPath)"
        Remove-Item $profils.LocalPath -Confirm:$false
        Remove-CimInstance -InputObject $profils -Confirm:$false
    }
}

Clear-RecycleBin -Force -ErrorAction:Ignore