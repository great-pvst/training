# Paramètres
$OUPath = "OU=AUTO,OU=Users,OU=HQ,DC=wsl2024,DC=org"
$UserPassword = ConvertTo-SecureString "P@ssw0rd" -AsPlainText -Force

# Vérification de l'existence de l'OU
$OU = Get-ADOrganizationalUnit -Filter {Name -eq "AUTO"} -SearchBase "OU=Users,OU=HQ,DC=wsl2024,DC=org"

if ($OU) {
    Write-Host "L'OU AUTO a été trouvée. Création des utilisateurs..."

    # Créer les utilisateurs
    for ($i = 1; $i -le 1000; $i++) {
        $UserName = "wslusr" + "{0:D3}" -f $i
        $UserPrincipalName = $UserName + "@wsl2024.org"
        $DisplayName = $UserName

        # Définir l'utilisateur dans le groupe "FirstGroup" pour les 500 premiers utilisateurs, et "LastGroup" pour les 500 derniers
        if ($i -le 500) {
            $Group = "FirstGroup"
        } else {
            $Group = "LastGroup"
        }

        # Créer l'utilisateur
        New-ADUser -SamAccountName $UserName `
                   -UserPrincipalName $UserPrincipalName `
                   -Name $UserName `
                   -GivenName "User" `
                   -Surname "wslusr" `
                   -DisplayName $DisplayName `
                   -Path $OUPath `
                   -AccountPassword $UserPassword `
                   -Enabled $true

        Write-Host "Utilisateur $UserName créé avec succès!"

        # Ajouter l'utilisateur au groupe approprié
        Add-ADGroupMember -Identity $Group -Members $UserName
        Write-Host "Utilisateur $UserName ajouté au groupe $Group"
    }

    Write-Host "Création des 1000 utilisateurs terminée."

} else {
    Write-Host "L'OU 'AUTO' n'a pas été trouvée dans 'OU=Users,OU=HQ'."
}
