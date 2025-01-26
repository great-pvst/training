#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//programme qui remplace les voyelles (majuscules et minuscules) d'un mot par des espaces

void change_voyelle(char mot[]);

int main(){
    char chaine[255];
    printf("\tCe code remplace les voyelles par un espace\n\n");
    printf("Saisissez un mot : "); scanf("%s", chaine);
    change_voyelle(chaine);
    printf("%s", chaine);


    return 0;
}

void change_voyelle(char mot[]){
    char voyelle[]= {"aAeEiIoOuUyY"};
    int i = 0;
    while (i < strlen(mot)){
        for (int j = 0; j < strlen(voyelle); j++){
            if (mot[i] == voyelle[j])
                mot[i] = ' ';
            }
        i++;
    }
    //printf("%s", mot);
}

/*


/**
 * Remplace les voyelles (minuscules et majuscules) par des espaces
 * dans la chaîne text[], renvoie le nombre de caractères remplacés
 * @author SD
 * @param text (char[]) : Chaîne de caractère (terminée par '\0')
 * @return (int) Nombre de caractères qui ont été remplacés dans la chaîne 'text' reçue en paramètre
*
int remplaceVoyellesParEspaces(char text[]);
////////////////////////////////////////////////////////////////////////////
/**
 * Détermine si un caractère passé en paramètre est une voyelle.
 * @author SD
 * @param c (char) : Caractère à tester
 * @return (int) 1 si le caractère reçu en paramètre est une voyelle, 0 sinon
*
int estUneVoyelle(char c);

int main() {
	char leTexte[50];

	printf("Entrez un  mot : ");
	scanf("%s", leTexte);

	int n = remplaceVoyellesParEspaces(leTexte);

	printf("%d caractères ont été remplacés   %s", n, leTexte);

	return 0;
}

// Définition des fonctions (code)
int remplaceVoyellesParEspaces(char text[]) {
    int i, nbRemplacement = 0;

    i = 0;
    while(text[i] != '\0') {
    //    Si le caractère est une voyelle (majuscule ou minuscule)    || = OU
        if(estUneVoyelle(text[i])) {

            text[i] = ' ';

            nbRemplacement++;
        }
        i++;
    }

    return nbRemplacement;
}

int estUneVoyelle(char c) {
    char tVoyelle[] = "aAeEiIoOUuYy";

    for(int i=0 ; i<12 ; i++) {
        if(c == tVoyelle[i])
            return 1;
    }
    return 0;
}
*/
