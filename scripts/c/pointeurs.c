#include <stdio.h>
#include <stdlib.h>
/*
On veut écrire une fonction qui renverra le nombre d'heures et de minutes.
(On peut résoudre le problème d'une autre façon mais le but ici est d'utiliser les pointeurs.)

En effet,lorsqu'on appelle une fonction, une copie des variables est réalisée et celle-ci est détruite en sortie de la fonction.
En mettant un type int (ou autre), on ne pourra renvoyer qu'une valeur à la fois (soit heure soit minute).

pointeur = variable qui contient l'adresse d'une autre variable.
			 on utilise le symbole * pour créer un pointeur.
			 On indique le type de variable pour laquelle le pointeur va contenir l'adresse.
			 C'est pourquoi on écrit : type *nom_pointeur = &nom_variable
			 
			"le pointeur pointe sur la variable"

			Pour afficher la valeur de la variable se trouvant à l'adresse indiquée dans un point pointeur, 
			On met le symbole * avant le nom de la variable sinon, l'ordinateur renverra la valeur du pointeur.

les pointeurs vont permettre de renvoyer plusieurs valeurs.

En somme, les pointeurs permettent de manipuler la valeur d'une variable contenue dans une autre adresse.

AVEC LES VARIABLES
	ma_variable : valeur de la variable
	&ma_variable : adresse de la variable

AVEC LES POINTEURS
	mon_pointeur : adresse de la variable pointée correspond aussi à la valeur du pointeur)
	*mon_pointeur : valeur de la variable pointée
	&mon_pointeur : adresse du pointeur

*/

void triple(int *pointeur);
void decoupe_minutes(int *heure, int *minute);

int main (int argc, char *argv[]) {

//création d'un pointeur
int *pointeur = NULL;

int nombre = 10,
    heure = 0,
    minute = 90;

// heure vaut 1 et minute 30 après appel de notre fonction
decoupe_minutes(&heure, &minute);
printf("Affichage de l'heure : %d h %d min.\n", heure, minute);

//la fonction va directement modifier la valeur de la variable car elle connaît son adresse.
triple(&nombre); 
printf("Modification directe d'un nombre : %d.\n",nombre);

return 0;
}

void triple(int *pointeur){
*pointeur *=3;
}

void decoupe_minutes(int *heure, int *minute)
{
    *heure = *minute / 60;  // 90 / 60 = 1
    *minute = *minute % 60; // 90 % 60 = 30
}