# Parameters
$OUPath = "OU=YourOUname,DC=lan,DC=local"
$UserPassword = ConvertTo-SecureString "PutYourStrongPasswordHere" -AsPlainText -Force

# Checking OU presence
$OU = Get-ADOrganizationalUnit -Filter {Name -eq "TheOUnameYouSearched"} -SearchBase $OUPath

if ($OU) {
    Write-Host "The OU has been found. Starting to create user ..."

    # Create users process (it's an example : user001 - user1000)
    for ($i = 1; $i -le 1000; $i++) {
        $UserName = "user" + "{0:D3}" -f $i
        $UserPrincipalName = $UserName + "@lan.local"
        $DisplayName = $UserName

        # Users who are < 500 --> in FirstGroup (nameOfGroup) and who are > 500 in LastGroup
        if ($i -le 500) {
            $Group = "FirstGroup"
        } else {
            $Group = "LastGroup"
        }

        # Creating
        New-ADUser -SamAccountName $UserName `
                   -UserPrincipalName $UserPrincipalName `
                   -Name $UserName `
                   -GivenName "User" `
                   -Surname "user" `
                   -DisplayName $DisplayName `
                   -Path $OUPath `
                   -AccountPassword $UserPassword `
                   -Enabled $true

        Write-Host "Success created $UserName user"

        # adding created user in right group
        Add-ADGroupMember -Identity $Group -Members $UserName
        Write-Host "$UserName user added in $Group group"
    }

    Write-Host "1000 user creation ended"

} else {
    Write-Host "No OU found."
}
