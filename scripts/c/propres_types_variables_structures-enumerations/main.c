#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/*
structure = assemblage de variables de types différents(int, long, double, char,...) ou pas.
les structures se mettent souvent dans le fichier header (en .h) comme les protypes et les
define.

//définition d'une structure
    struct nom_structure {placer les variables}; NE PAS OUBLIER LE POINT-VIRGULE.
    exemple
        struct Coordonees {
            int x;
            int y;
        };

on peut placer des tableaux dans une structure. il n'y a pas de limites au nombre de tableaux.
    struct Personne {
        char nom[100];
        char prenom[100];
        char adresse[1000];
        int age;
        int etudiant;

//structure dans une fonction
typedef = créer un alias de structure
    typedef struct nom_structure alias;
l'usage d'un alias permet de créer une variable de la structure sans utiliser le mot-clé
struct.

énumérations = liste de valeurs possibles pour une variable. une énumération ne contient pas de sous-variables.
elle ne prend qu'une case en mémoire et celle-ci ne peut prendre qu'une seule des valeurs à la fois.

//définition énumération
enum nom_enumeration {placer la liste de variables}; NE PAS OUBLIER LE POINT-VIRGULE.
    exemple
        enum Coordonees {
            NORD, EST, SUD, OUEST
        };
on peut associer des valeurs à chacun, par exemple NORD = 90.

union : sert à regrouper plusieurs données qui accèderont à la même zone mémoire.

*/

void initialiser_coordonnees(Coordonnees *point);


int main()
{
    // création d'une variable user1 de types Personne
    //struct Identite personne; //cette variable est donc composée des 5 sous-variables.
    Identite personne1; // autre façon de créer en utilisant l'alias

    //accès direct au variable de la structure en utilisant la notation dot (pointée, ".")

    printf("Quel est votre nom ? "); scanf("%s", personne1.nom);
    /*personne.nom[300] = "Ockandji";
    personne.prenom[300] = "Ardy";
    personne.adresse[1000] = "37 Rue Georges Clémenceau";
    personne.age = 19;*/
    printf("Vous êtes %s.\n", personne1.nom);

    //initialiser une structure : elle se fait comme avec les tableaux
    Identite personne2 = {"a", "v", "rien", 100};
    printf("%s\n", personne2.nom);
    Coordonnees point1 = {1,2,3};
    //printf("%d\n", point1.y);

    //pointeur sur une structure : elle se crée de la même manière qu'un pointeur int, double, etc.
    Coordonnees *point2 = NULL;

    //structure dans une fonction
    Coordonnees point3;
    initialiser_coordonnees(&point3);
    printf("(%d;%d;%d)\n", point3.x, point3.y, point3.z);

    //enumeration initialisation
    Mention maths = EXCELLENT;
    //EXCELLENT vaut 3. cette valeur est assignée automatiquement par le compilateur par rapport à sa position

    return 0;
}


void initialiser_coordonnees(Coordonnees *point){
    //sans parenthèses, on n'accède qu'à point au lieu de *point
    (*point).x = 4;
    point->y = 5; // raccourci, à n'utiliser que sur les pointeurs.
    (*point).z = 6;

}
