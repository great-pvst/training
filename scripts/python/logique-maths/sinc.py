#coding:utf-8

#calcul du sinc(x)
from math import *
print("Calcul du sinc de -3 à 3.")
for i in range(-3,3):
    try:
        sinc = sin(i)/i
        print("sinc(",i,") = ", sinc)
    except (ValueError, ZeroDivisionError):
        print("No result for ", i)