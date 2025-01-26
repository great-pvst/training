#include <stdio.h>
#include <stdlib.h>

//demande le resultat d'un produit entier à l'utilisateur, si faux l'utilisateur tente de nouveau
int main (int argc, char *argv[]) {
int nb_entre = 0;
int essai = 1; //affiche le nombre d'essais
do {
printf("2 x 2 = "); scanf("%d", &nb_entre);
if (nb_entre == 4){
printf("Bravo ! Vous avez trouvé en %d essai(s).\n", essai);
}
else {
printf("Faux, recommencez !\n");
} essai++;
} while (nb_entre != 4);

//affichage de tous les nombres pairs après que l'utilisateur ait entré un nombre
unsigned int nb_entre_positif = 0;
printf("\n***Ce bout affiche tous les nombres pairs entre 0 et le nombre entré.***\n");
printf("Entrez un entier positif : "); scanf("%d", &nb_entre_positif);
for (int i = 0; i < nb_entre_positif; i += 2){
//if (i % 2 == 0){
printf("%d, ", i);
//}
}

return 0;
}
