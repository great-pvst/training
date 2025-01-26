//code d'affichage et de saisie des notes

#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 100

/*

*/


int main (void) {
float notes[TAILLE_MAX] = {0};
float plusG = 0, plusP = 0, somme = 0, moyenne = 0;
int p = 0, g = 0, supMoyenne = 0, compteur = 0;

printf("Saisissez des notes (entre 0 et 20, sinon erreur) !\n\n");
//saisie et stockage des notes
for (int i = 0; i < TAILLE_MAX; i++){
	scanf("%f", &notes[i]);
	if ((notes[i] >= 0) && (notes[i] <= 20)){
		somme += notes[i];
		compteur++;
	} else {
		printf("Erreur lors de la saisie de notes.\n");
		notes[i] = 0;
		break;
	}
}

//affichage notes
for (int i = 0; i < compteur; i++){ //notes[i] != 0
	printf("%.2f", notes[i]);
	if(i+1 == 0)
		break;
	else
		printf(", ");

}
printf("\nVous avez saisi %d notes.\n", compteur);

moyenne = somme/compteur; printf("Moyenne = %.2f\n", moyenne);
for (int i = 0; i < compteur; i++){ //notes[i] != 0
	if (notes[i] > moyenne){
		printf("%.2f supérieur à la moyenne\n", notes[i]);
		supMoyenne++;
	}
	else if (notes[i] < moyenne)
		printf("%.2f inférieur à la moyenne\n", notes[i]);
	else
		printf("%.2f égal à la moyenne\n", notes[i]);
}
printf("%i note(s) est ou sont supérieure(s) à la moyenne.\n", supMoyenne);

plusG = plusP = notes[0];
for (int i = 0; i < compteur; i++){ //notes[i] != 0
	if (notes[i] >= plusG){
		plusG = notes[i];
		g = i+1;
	}
}
for (int i = 0; i < compteur; i++){ //notes[i] != 0
	if(notes[i] <= plusP){
		plusP = notes[i];
		p = i+1;
	}
}

printf("Note max = %.2f, trouvée à la position %d.\n", plusG, g);
printf("Note min = %.2f, trouvée à la position %d.\n", plusP, p);

return 0;
}

/* autre solution

#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf
int main() {
	const int NB_MAX_NOTES = 50;
	int nbNotes;
	float note, sommeDesNotes;
	float tabNotes[NB_MAX_NOTES]; // Déclare un tableau de 50 réels
	
	printf("Entrez des notes (entre 0 et 20)\nPour stopper, saisir une note hors de cet interval.\n");
	
	nbNotes = 0;
	// A. Saisir les notes et les mémoriser dans un tableau
	// + B. Compter les notes saisies et afficher leur nombre
	do {
		scanf("%f", &note);
		tabNotes[nbNotes] = note; // tabNotes[nbNotes] <-- note
		nbNotes++;
	} while((note >= 0) && (note <= 20) && (nbNotes < NB_MAX_NOTES));
	
	if((note < 0) || (note > 20)) nbNotes--; // La dernière note saisie n'est pas valide
	else printf("\nVous avez ateint le nombre maximum de notes possible.");

	printf("\nVous avez saisi %d notes", nbNotes);
	
	// C. Calcul et affichage de la moyenne 
	sommeDesNotes = 0;
	int i;
	for(i = 0 ; i < nbNotes ; i++) {
	    sommeDesNotes = sommeDesNotes + tabNotes[i];
	}
	
	float moyenne = sommeDesNotes / nbNotes; 
	printf("\n\nLa moyenne des notes est : %.2f\n", moyenne);
	
	// D. Comparer chaque note à la moyenne et ajouter, dans l’affichage précédent "égal",
	//    "inférieur" ou "supérieur à la moyenne"
	// + E. Compter et afficher combien il y a de notes supérieures à la moyenne
	int nbNotesSupMoy = 0;
	for(i = 0 ; i < nbNotes ; i++) {
	    printf("\n%d : %.2f", i+1, tabNotes[i]);
	    
	    if(tabNotes[i] > moyenne) {
	        printf(" > à la moyenne");
	        nbNotesSupMoy++;
	    }
	    else if(tabNotes[i] < moyenne)
	        printf(" < à la moyenne");
	    else
	        printf(" = à la moyenne");
	}
	
	printf("\n\nIl y a %d notes > à la moyenne.", nbNotesSupMoy);
	
	// F. Dans le tableau de notes, chercher la note la plus petite 
	float noteLaPlusFaible = 21;
	int positionNoteLaPlusFaible;
	for(i = 0 ; i < nbNotes ; i++) {
	    if(tabNotes[i] < noteLaPlusFaible) {
	        noteLaPlusFaible = tabNotes[i];
	        positionNoteLaPlusFaible = i + 1;
	    }
	}
	
	// F. (suite) Afficher cette note et sa position dans le tableau
	printf("\n\nLa note la plus basse est %.2f, sa position est %d", noteLaPlusFaible, positionNoteLaPlusFaible);

	// G. Dans le tableau de notes, chercher la note la plus haute 
	float noteLaPlusHaute = -1;
	int positionNoteLaPlusHaute;
	for(i = 0 ; i < nbNotes ; i++) {
	    if(tabNotes[i] > noteLaPlusHaute) {
	        noteLaPlusHaute = tabNotes[i];
	        positionNoteLaPlusHaute = i + 1;
	    }
	}
	
	// G. (suite) Afficher cette note et sa position dans le tableau
	printf("\n\nLa note la plus haute est %.2f, sa position est %d", noteLaPlusHaute, positionNoteLaPlusHaute);
	
	return 0;
}
*/
