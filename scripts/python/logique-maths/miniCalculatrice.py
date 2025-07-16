### simulate a mini calculator

#coding:utf-8
import os

def message():
    print("Bienvenue sur la mini-calculatrice !")
    
def input_two_number():
    nb1 = float(input("Entrez nombre 1 : "))
    nb2 = float(input("Entrez nombre 2 : "))

    return nb1, nb2

def menu_and_get_choice():
    print("=== MENU ===")
    print("1. Addition")
    print("2. Soustraction")
    print("3. Multiplication")
    print("4. Division")

    user_choice = input("Entrez votre choix (1-4) : ")
    while user_choice not in ["1", "2", "3", "4"]:
        user_choice = input("Choix invalide. Entrez votre choix (1-4) : ")
    return user_choice

def sum(a, b):
    return a + b
    
def substraction(a, b):
    return a - b

def multiplication(a, b):
    return a * b

def division(a, b):
    if b != 0:
        return a / b
        
    else:
        print("Erreur : division par zéro")


def run_calculation(choice):
	num1, num2 = input_two_number()
	match user_choice:
		case '1':
			result = sum(num1, num2)
		
		case '2':
			result = substraction(num1, num2)
		
		case '3':
			result = multiplication(num1, num2)
			
		case '4':
			result = division(num1, num2)
			
		case _:
			print("Choix invalide.")

	return result


if __name__ == '__main__':
	message()
	user_choice = menu_and_get_choice()
	result = run_calculation(user_choice)
	print(result)