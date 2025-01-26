import-module activedirectory

Get-ADComputer -Filter * -Properties Name,Operatingsystem,OperatingSystemVersion,IPv4Address |
Sort-Object -Property Operatingsystem | Select-Object -Property Name,Operatingsystem,OperatingSystemVersion,IPv4Address | 
Export-Csv -Path "C:\Users\Administrateur.DOM_CFA\Pictures\computerlist.csv" -Encoding UTF8 -Delimiter ";" `
-NoTypeInformation