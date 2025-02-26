#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//demande le resultat d'un produit entier à l'utilisateur, si faux l'utilisateur tente de nouveau
int main (int argc, char *argv[]) {
printf("Tapez le bon résultat pour quitter\n\n");

int nb_entre = 0, essai = 0, a = 0, b = 0;

do {
	essai++;
	srand(time(NULL));
	
	a =  rand() % 100 + 1; b =  rand() % 100 + 1;
	printf("%d * %d = ", a, b); scanf("%d", &nb_entre);
	
	if (a * b == nb_entre) printf("Bravo ! Vous avez trouvé en %d essai(s).\n", essai);
	else printf("Faux, recommencez !\n");
} while (nb_entre != a*b);

return 0;
}
