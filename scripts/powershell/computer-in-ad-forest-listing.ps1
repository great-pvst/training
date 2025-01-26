import-module activedirectory

Get-ADComputer -Filter * -Properties Name,Operatingsystem,OperatingSystemVersion,IPv4Address |
Sort-Object -Property Operatingsystem | Select-Object -Property Name,Operatingsystem,OperatingSystemVersion,IPv4Address | 
Export-Csv -Path "path\to\your\save\file.csv" -Encoding UTF8 -Delimiter ";" `
-NoTypeInformation