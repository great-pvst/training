#coding:utf-8

#les fonctions

#part 1 : procédure table
import math

def table(base, debut, fin, inc) :
   for i in range(debut, fin+1, inc) :
      print("",i,"*",base,"=", i*base)
   
print("Le programme affiche la table de multiplication d'un nombre donné")

base = int(input("Entrez le multiplicateur : "))
debut = int(input("Valeur de départ : "))
fin = int(input("Valeur de fin : "))
pas = int(input("Par pas de combien : "))

table(base, debut, fin, pas)
