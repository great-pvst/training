#include <stdio.h>
#include <stdlib.h>
//programme qui renvoie un mot en inversant le sens des lettres (sens inverse du mot)

int longueur_mot(char chaine[]);
void affichage_inverse_mot(char mot[]);

int main (int argc, char *argv[]){
	int nb_caractere = 0;
	char tableau_mot[100];

    printf("Saisissez un mot : ");
    scanf("%s", tableau_mot);
    //nb_caractere = longueur_mot(tableau_mot);
    affichage_inverse_mot(tableau_mot);

    return 0;
}

//fonction qui détermine la longueur du mot
int longueur_mot(char chaine[]){
    int taille_mot = 0;

    while (chaine[taille_mot] != '\0')
        taille_mot++;

    return taille_mot;
}

//afffichage en sens inverse
void affichage_inverse_mot(char mot[]){
    int taille_mot = longueur_mot(mot);
    for (int i = taille_mot - 1; i >= 0; i--)
        printf("%c", mot[i]);
}


/*
//autre solution

#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf

// Déclaration des fonctions
/**
 * Renvoie le nombre de caractères d'une chaîne de caractères
 * passée en paramètre
 * @author SD
 * @param texte (char[]) : Chaîne de caractère (terminée par '\0')
 * @return (int) Nombre de caractères qui compose la chaîne 'texte' reçue en paramètre
*
int longueurChaine(char texte[]);
/////////////////////////////////////////////////////////////////////////////////////
/**
 * Échange les valeurs de 2 variables de type char passées en paramètres
 * @author SD
 * @param c1 (char*) : Pointeur sur le premier caractère
 * @param c2 (char*) :  Pointeur sur le deuxième caractère
*
void echange(char* c1, char* c2);
/////////////////////////////////////////////////////////////////////////////////////
/**
 * Inverse une chaîne de caractères passée en paramètre. Ex : ELISA => ASILE
 * @author SD
 * @param texte (char[]) : Chaîne de caractère à inverser
*
void inverseChaine(char texte[]);

// Utilisation dans main()
int main() {
  int nbCar;
  char tMot[30];

  printf("Saisissez un mot : ");
  scanf("%s", tMot);

  inverseChaine(tMot);

  printf("\n%s", tMot);
}

// Définition des fonctions (code)
void inverseChaine(char texte[]) {
  int nbCar, i;
  char temp;

  nbCar = longueurChaine(texte);

  for(i = 0; i < nbCar / 2; i++) {
    echange(&texte[i], &texte[nbCar - 1 - i]);
  }
}

void echange(char* c1, char* c2) {
  char temp = *c1;

  *c1 = *c2;
  *c2 = temp;
}

int longueurChaine(char texte[]) {
  int longueur = 0;

  while(texte[longueur] != '\0') longueur++;

  return longueur;
}

*/
