#include <stdio.h>
#include <stdlib.h>

//demande à l'utilisateur d'entrer des notes entre 0 et 20 sinon s'arrête et affiche le nombre de notes saisies
int main (int argc, char *argv[]){
float note_saisie = 0;
int nb_notes = 0;
//float somme = 0;
float moyenne = 0; //afin de calculer la moyenne à la fin
float note_plus_basse_saisie = 20,
    note_plus_haute_saisie = 0;
printf("Vous allez saisir des notes. Les notes vont de 0 à 20. Si vous entrez une note en dehors de cet intervalle, vous ne pourrez plus en saisir !\n");
printf("\nSaisissez vos notes\n");
while (note_saisie >= 0 && note_saisie <= 20) {
    scanf("%f", &note_saisie);
    if (note_saisie >= 0 && note_saisie <= 20){
    moyenne = moyenne + note_saisie; //somme des notes
    if (note_saisie > note_plus_haute_saisie){
        note_plus_haute_saisie = note_saisie;
        }
    if (note_saisie < note_plus_basse_saisie){
        note_plus_basse_saisie = note_saisie;
        }
    }
nb_notes++;
}
nb_notes--;
if (nb_notes > 0) {
    moyenne = moyenne / nb_notes;
    printf("Vous avez saisi %d note(s).\n", nb_notes);
    printf("La plus basse note saisie : %.2f\n", note_plus_basse_saisie);
    printf("Moyenne = %.2f\n", moyenne);
    printf("La plus haute note saisie : %.2f\n", note_plus_haute_saisie);
} else {
    printf("Erreur : vous n'avez saisi aucune note !\n");
}
return 0;
}
