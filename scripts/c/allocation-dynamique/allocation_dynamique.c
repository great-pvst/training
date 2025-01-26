#include <stdio.h>
#include <stdlib.h>


/*
déclarer une variable = allouer de la mémoire.
sizeof() = opérateur qui permet de vérifier la taille de chaque type. c'est juste unc fonctionnalité du langage, pas
une fonction.
on peut aussi utiliser sizeof() pour connaître la taille d'une structure créer.

malloc = memory allocation, fonction qui demande la permission à l'os d'utiliser la mémoire.
free = fonction pour libérer la mémoire allouée. (libre en français)

allocation manuelle de mémoire (étapes) :
    appeler la fonction malloc
    vérifier la valeur retournée par malloc
    libérer la mémoire avec la fonction free.

la fonction exit() permet d'arrêter immédiatement un programme. mettre en paramètre la valeur qui doit être retournée

allocation dynamique
    on s'en sert le plus souvent pour créer des tableaux. elle permet de créer un tableau qui a exactement la taille
    d'une variable.
*/

//prototype malloc
void* malloc(size_t nombre_octets_necessaires);
/*
cette fonction renvoie un pointeur indiquant l'adresse reservée par le système. ce sera un pointeur sur n'importe
quel type. on peut dire que c'est un pointeur universel.
si l'allocation échoue, notre pointeur contiendra l'adresse NULL.
*/

//prototype free
void free(void* pointeur); //ici pointeur = memoire_allouee

int main (int argc, char* argv[]){

    printf("taille de int = %d octets\n", sizeof(int));

    int* memoire_allouee = NULL;

    memoire_allouee = malloc(sizeof(int)); //la fonction malloc inscrit l'adresse qui a été reservéé

    if (memoire_allouee == NULL) // Si l'allocation a échoué
    {
        exit(0); // On arrête immédiatement le programme
    }

    // On peut continuer le programme normalement sinon
    printf("\nQuel âge avez-vous ? ");
    scanf("%d", memoire_allouee);
    printf("Vous avez %d ans\n\n", *memoire_allouee);

    //fin d'utilisation de la mémoire, on la libère
    free(memoire_allouee);

    //illustration allocation dynamique
    int nombre_d_amis = 0, i = 0;
    int* age_amis = NULL; // Ce pointeur va servir de tableau après l'appel du malloc

    // On demande le nombre d'amis à l'utilisateur
    printf("Combien d'amis avez-vous ? ");
    scanf("%d", &nombre_d_amis);

    if (nombre_d_amis > 0) // Il faut qu'il ait au moins un ami
    {
        age_amis = malloc(nombre_d_amis * sizeof(int)); // On alloue de la mémoire pour le tableau
        if (age_amis == NULL) // On vérifie si l'allocation a marché ou non
        {
            exit(0);
        }

        // On demande l'âge des amis un à un
        for (i = 0 ; i < nombre_d_amis ; i++)
        {
            printf("Quel âge a l'ami numero %d ? ", i + 1);
            scanf("%d", &age_amis[i]);
        }

        // On affiche les âges stockés un à un
        printf("\n\nVos amis ont les âges suivants :\n");
        for (i = 0 ; i < nombre_d_amis ; i++)
        {
            printf("%d ans\n", age_amis[i]);
        }

        // On libère la mémoire allouée avec malloc, on n'en a plus besoin
        free(age_amis);

    return 0;
    }
}
