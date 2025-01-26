#include <stdio.h>
#include <stdlib.h>
/*
on veut écrire une fonction qui renvoie deux valeurs. Cette fonction renverra le nombre d'heures et
de minutes. (On peut résoudre le problème d'une autre façon mais le but ici est d'utiliser les pointeurs.

en effet, on a 0 h 90 min car lorsqu'on appelle une fonction, une copie des variables est réalisée et
celle-ci est détruite en sortie de la fonction. donc la variable heure par exemple, n'est pas la même
dans la fonction decoupe_minutes et main.
En mettant un type int (ou autre), on ne pourra renvoyer qu'une valeur à la fois (soit heure soit minute).

On peut afficher (ou utiliser d'ailleurs) l'adresse d'une variable. c-à-d le lieu où elle est stockée.
instruction simple : printf("adresse variable x = %p", &nom_variable);
    %p = afficher l'adresse de la variable.

pointeur = variable qui contient l'adresse d'une autre variable. on utilise le symbole * pour créer un
pointeur. On indique le type de variable pour laquelle le pointeur va contenir l'adresse. c'est pk on
écrit : type *nom_pointeur = &nom_variable avec type = int, float, double, char, etc.
"le pointeur pointe sur la variable"

pour afficher la valeur de la variable se trouvant à l'adresse indiquée dans un point pointeur, on
met le symbole * avant le nom de la variable : printf("%d", *nom_pointeur);
sinon, l'ordinateur renverra la valeur du pointeur.

les pointeurs vont permettre de renvoyer plusieurs valeurs.
en somme, les pointeurs permettent de manipuler la valeur d'une variable contenue dans une autre adresse.

[VARIABLES]
	ma_variable : valeur de la variable
	&ma_variable : adresse de la variable

[POINTEURS]
	mon_pointeur : adresse de la variable pointée (correspond aussi à la valeur du pointeur)
	*mon_pointeur : valeur de la variable pointée
	&mon_pointeur : adresse du pointeur

*/
void triple(int *pointeur);
void decoupe_minutes(int *heure, int *minute);

int main (int argc, char *argv[]) {

//test d'envoi d'un pointeur dans une focntion

//création d'un pointeur
int *pointeur = NULL;
//ou int* pointeur (pour ne déclarer qu'un seul sur une ligne)
int nombre = 10,
    heure = 0,
    minute = 90;
//normalement heure doit valoir 1 et minute 30 après appel de notre fonction
decoupe_minutes(&heure, &minute);
printf("%d h %d min.\n", heure, minute);
triple(&nombre);
printf("%d\n", nombre); //la fonction va directement modifier la valeur de la variable car elle
                    //connaissait son adresse.
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
