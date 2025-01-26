#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//programme qui dit combien de fois un caractère est présent dans une chaîne

int recherche_caractere(char mot[], char caractere[]);

int main(int argc, char *argv[]){
    char mot_saisi[200], caractere_saisi[100];
    printf("  Ce code affiche le nombre de fois un caractère est présent dans une chaîne.\n\n");
    printf("Saisissez un mot (même insignifiant) : "); scanf("%s", &mot_saisi);
    printf("Quel caractère cherchez-vous (respectez la casse) : "); scanf("%s", &caractere_saisi);
    int nb_fois = recherche_caractere(mot_saisi, caractere_saisi);
    printf("Le caractère %s se trouve %d fois dans le mot %s !\n", caractere_saisi, nb_fois, mot_saisi);
    return 0;
}

int recherche_caractere(char mot[], char caractere[]){
    int nb_fois = 0;
    for (int i = 0; i <= strlen(mot); i++){ //mot[i] != ' '
        if (mot[i] == caractere[0])
            nb_fois++;
        }

    return nb_fois;
}


/*#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf

/**
 * Compte combien de fois un caractère est présent dans une chaîne.
 * La chaîne de caractères et le caractère cherché sont passés en paramètres
 * @author SD
 * @param texte (char[]) : Chaîne de caractère (terminée par '\0')
 * @param car (char) : Caractère à rechercher dans 'texte'
 * @return (int) Nombre de fois que le caractère a été trouvé
*
int nombreOccurence(char texte[], char car);

int main()
{
    char leTexte[] = "Fonction qui cherche combien de fois un caractère est présent dans une chaîne";

    printf("\n%s", leTexte);

    printf("\n\nLe caractère 'e' est présent %d fois", nombreOccurence(leTexte, 'e'));

    printf("\n\nLe caractère 'Y' est présent %d fois", nombreOccurence(leTexte, 'Y'));

    return 0;
}

// Définition de la fonction
int nombreOccurence(char texte[], char car) {
    int nbCar = 0;
    int i;

    i = 0;
    while(texte[i] != '\0') {
    //  Si le caractère = car
        if(texte[i] == car) nbCar++;

        i++;
    }

    return nbCar;
}

*/
