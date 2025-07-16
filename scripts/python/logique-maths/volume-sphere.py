#coding:utf-8

# volume of the sphere
import math

def calculCube(nombre):
    return nombre*nombre*nombre

def volumeSphere(rayon):
    return (4*math.pi*calculCube(rayon))/3

print("Ce programme calcule le volume d'une sphere")

print("Volume de la sphere = ", format(volumeSphere(float(input("Rayon : "))), '.3f'))