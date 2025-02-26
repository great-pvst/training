#coding:utf-8

#import math
import base64

#fonctions
def Chiffrement(nombre, cle):
    return (nombre+cle)%128 # ascii table

def Dechiffrement(nombre, cle):
    return (nombre-cle)%128

def ChiffrementCesarMot(mot, cle):
    #afin de recevoir chaque lettre cryptée puis reconstituer la chaîne de caractère
    mot_crypte = ""
    for lettre in mot:
        nombre = ord(lettre) #ascci to int
        nombreCrypte = Chiffrement(nombre, cle)
        lettreCryptee = chr(nombreCrypte) # int to ascii
        mot_crypte += lettreCryptee
    return mot_crypte

def DechiffrementCesarMot(mot, cle):
    mot_decrypte = ""
    for lettre in mot:
        nombre = ord(lettre)
        nombreDeccrypte = Dechiffrement(nombre, cle)
        lettreDecryptee = chr(nombreDeccrypte)
        mot_decrypte += lettreDecryptee
    return mot_decrypte

def InvitationChiffrementMot():
    print ("Chiffrement de César.\n")
    mot = input("Entrez le mot : ")
    cle = int(input("Entrez la clé : "))
    print ("Chiffrement en cours...\nMot chiffré : ", ChiffrementCesarMot(mot, cle))

def InvitationChiffrementNombre():
    print ("Chiffrement de César.\n")
    nombre = int(input("Entrez le nombre : "))
    cle = int(input("Entrez la clé : "))
    print ("Chiffrement en cours...\nNombre chiffré : ", Chiffrement(nombre, cle))

def InvitationDechiffrementMot():
    print ("Déchiffrement de César.\n")
    mot = input("Entrez le mot : ")
    cle = int(input("Entrez la clé : "))
    print ("Déchiffrement en cours...\nMot déchiffré : ", DechiffrementCesarMot(mot, cle))

def InvitationDechiffrementNombre():
    print ("Déchiffrement de César.\n")
    nombre = int(input("Entrez le nombre : "))
    cle = int(input("Entrez la clé : "))
    print ("Déchiffrement en cours...\nNombre déchiffré : ", Dechiffrement(nombre, cle))

################################################### main ################################################### 
demandeAction = input("Quelle action souhaitez-vous faire ? C[hiffrer] ou D[échiffrer] : ")

if (demandeAction.upper() == "C"):
    saisie = input("Que souhaitez-vous chiffrer ? N[ombre] ou M[ot] : ")
    if (saisie.upper() == "M") : InvitationChiffrementMot()
    elif (saisie.upper() == "N"): InvitationChiffrementNombre()
    else : print("Opération non permise. Fin du programmme !\n"); exit

elif (demandeAction.upper() == "D"):
    saisie = input("Que souhaitez-vous déchiffrer ? N[ombre] ou M[ot] : ")
    if (saisie.upper() == "M"): InvitationDechiffrementMot()
    elif (saisie.upper() == "N"): InvitationDechiffrementNombre()
    else : print("Opération non permise. Fin du programmme !\n"); exit

else : print("Opération non permise. Fin du programmme !\n"); exit
