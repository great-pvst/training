// programme qui affiche un tableau de 10 nombres (1-10)

#include <stdio.h>
#include <stdlib.h>
#define TAILLETAB 100
/*

*/


int main (int argc, char* argv[]){
	//code qui affiche 10 entiers séparés par une virgule
	int tabInt[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; i++){
		printf("%d", *(tabInt + i));
		if (i == 9){
			break;
		} else {
			printf(",");
		}
	};
	printf("\n\n");

	//code qui affiche 100 entiers en grille de 10x10
	int tabInt2[TAILLETAB];
	for (int i = 0; i < TAILLETAB; i++){
		tabInt2[i] = i;
		printf("%d", *(tabInt2 + i));
		if (i == 99){
                	break;
                } else {
                       	printf(",");
			if ((i + 1) % 10 == 0){
				printf("\n");
			}
		}
        };
	printf("\n");

	return 0;
}

/*	autre approche

#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf
int main() {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("%d", tab[0]);
    for(int i = 1 ; i < 10 ; i++) printf(", %d", tab[i]);

	return 0;
}

*/

/*	autre approche code2
#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf
int main() {
    const int TAB_SIZE = 100;
    const int LINE_SIZE = 10;
    int tab[TAB_SIZE];
    
    // Remplir le tableau avec les nombres de 0 à TAB_SIZE
    for(int i = 0 ; i < TAB_SIZE ; i++) tab[i] = i;
 
    // Aficher le tableau en limitant à LINE_SIZE valeurs par lignes
    for(int i = 0 ; i < TAB_SIZE ; i++) {
        if((i+1) % LINE_SIZE == 0) { // Si arrivé en fin de ligne
            printf("%2d\n", tab[i]); //    Ajout d'un saut de ligne
        }
        else {                      // Sinon
            printf("%2d,", tab[i]); //    Ajout d'une virgule
        }
    }
    
	return 0;
}
*/
