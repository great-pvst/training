#coding:utf-8
import xlsxwriter

#----------------------------------------------------------------------------------------------------------------------------------------------------

compname = []
compos = []
composversion = []
win10 = [[], []]
win11 = [[], []]
otherOS = [[], []]
word = ""
win = 0
compteur = 0

#----------------------------------------------------------------------------------------------------------------------------------------------------

#opening and reading
file = open('your-csv-that-contains-computer-list.csv', 'r')

for row in file :
    word = row.split(";")
    compname.append(word[0])
    compos.append(word[1])
    composversion.append(word[2])

file.close()

#----------------------------------------------------------------------------------------------------------------------------------------------------
#separating osversion

file = open('your-csv-that-contains-computer-list.csv', 'r')
j = 0
for row in file :
    word = row.split(";")
    
    win = word[1].split(None)
    #print("\n",type(win))
    if (len(win) > 1):
        winVersionNumber = win[1]
        if (winVersionNumber == '11') :
            win11.append([[compname[j]], [compos[j]]])
        elif (winVersionNumber == '10') :
            win10.append([[compname[j]], [compos[j]]])
        else :
            otherOS.append([[compname[j]], [compos[j]]])
    else :
        otherOS.append([[compname[j]], [compos[j]]])
    j += 1
#print(len(compname)-10)
file.close()


#----------------------------------------------------------------------------------------------------------------------------------------------------
#gen excel file

# Create an new Excel file and add a worksheet.
workbook = xlsxwriter.Workbook('filename.xlsx')
worksheet = workbook.add_worksheet()

# Widen the first column to make the text clearer.
worksheet.set_column('A:B', 30)

# Add a bold format to use to highlight cells.
bold = workbook.add_format({'bold': True})

worksheet.write(0, 0, "Nom de machines")
worksheet.write(0, 1, "Système d'exploitation")

while j > 0 : 

    worksheet.write(compteur+1, 0, compname[compteur])
    worksheet.write(compteur+1, 1, compos[compteur])
    compteur += 1
    j -=1

workbook.close()

#----------------------------------------------------------------------------------------------------------------------------------------------------
