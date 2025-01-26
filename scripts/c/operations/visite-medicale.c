//indice de masse corporelle : visite médicale
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculImc(float m, float t){
    //int carre = t*t;//for (int i = 0; i <= taille; i++)
    return m/(t*t);
}

int main () {
printf("\t***Pour des raisons de sécurité et de qualité, les médecins ne traiteront pas plus de 30 patients par jour***\n");
const int TAILLE_TAB = 30;
int nombrePatient = 0;
int compteur = 0;
float tailleMoyenne = 0;
float masseMoyenne = 0;
//printf("Combien de patients sont prévus pour la visite ?");scanf("%d", &nombrePatient);
float taillePatient[TAILLE_TAB];
float massePatient[TAILLE_TAB];
float imc[TAILLE_TAB];
printf("\nEntrez les différentes tailles (en mètres) des patients (Tapez 0 pour arrêter la saisie) : ");
//récupératon de la taille
for (nombrePatient = 0; nombrePatient < TAILLE_TAB; nombrePatient++)
{
	scanf("%e", &taillePatient[nombrePatient]);
	if (taillePatient[nombrePatient] == 0)
        break;
    //printf("");
};
printf("Taille patient %d = %.2f m.\n", nombrePatient, taillePatient[nombrePatient-1]);
printf("\nLes patients sont au nombre de %d.\n", nombrePatient);

printf("Entrez, cette fois, votre masse (en kilogrammes) : ");
//récupération de la masse
for (compteur = 0; compteur <= nombrePatient; compteur++)
{
	scanf("%e", &massePatient[compteur]);
	if (massePatient[compteur] == 0)
        break;
    //printf("");
}

//calcul et affichage de la moyenne de taille et masse.
for(int i = 0; i <= nombrePatient; i++){
	tailleMoyenne += taillePatient[i];
	masseMoyenne += massePatient[i];
}
tailleMoyenne = tailleMoyenne/nombrePatient; masseMoyenne = masseMoyenne/nombrePatient;
printf("\nLes patients ont en moyenne une taille de %.2f m pour une masse moyenne de %.2f kg.\n", tailleMoyenne, masseMoyenne);
printf("%d\n", nombrePatient);

//calcul de l'indice de masse corporelle (IMC)
for (compteur = 0; compteur < nombrePatient; compteur++)
{
	imc[compteur] = calculImc((float)massePatient[compteur], (float)taillePatient[compteur]);
}

//affichage de celui-ci pour chaque utilisateur
for(int i = 0; i < nombrePatient; i++){
	if (imc[i] == 0){
        printf("Aucun calcul d'IMC n'a été effectué !\n");
        //break;
    }
	else {
        if (imc[i] < 18.5)
            printf("Patient %d, IMC = %.2f (faible)\n", i+1, imc[i]);
        else if(imc[i] > 25)
            printf("Patient %d, IMC = %.2f (trop)\n", i+1, imc[i]);
        else
            printf("Patient %d, IMC = %.2f (normal)\n", i+1, imc[i]);
        }
}

return 0;
}

/*
#include <stdio.h>  // Inclure la bibliothèque STanDard Input Output
                    // permet d'utiliser, entre autre, printf et scanf
int main() 
{
    const int TAB_SIZE = 30;
	int i, nbPatient;
	float tTaille[TAB_SIZE], tMasse[TAB_SIZE], imc, somme;
	
	// A.	Enregistrer la taille t en mètres de tous les patients qui se présentent 
	//		(arrêt par la saisie d’un nombre ≤ 0)
	printf("Entrez la taille des patients (en mètre) :\n");
	i = 0;
	do {
		printf("  Taille du patient %d : ", i + 1);
		scanf("%f", &tTaille[i]);
		i = i + 1;
	} while ((tTaille[i-1] > 0) && (i < TAB_SIZE));
	
	// B.	Après la saisie, afficher le nombre total des patients.
	nbPatient = i;
	if(tTaille[i-1] < 0) nbPatient--; // La dernière taille saisie n'est pas valide
	else printf("\nVous avez ateint le nombre maximum de %d patients possible.", TAB_SIZE);
	
	printf("\nIl y a %d patients.\n\n", nbPatient);
	
	// C.	Pour chaque patient précédemment mesuré, enregistrer la masse m en kilogrammes.
	printf("Entrez la masse des patients (en kg) :\n");
	for(i = 0; i < nbPatient; i++) {
		printf("  Masse du patient %d : ", i + 1);
		scanf("%f", &tMasse[i]);	
	}
	
	// D.	Calculer et afficher la taille et le poids moyens.
	printf("\n");
		// Taille moyenne
	somme = 0;
	for(i = 0 ; i < nbPatient ; i++) {
		somme = somme + tTaille[i];
	}
	printf("\nLa taille moyenne des patients est : %.2f\n", somme / nbPatient);
	    // Poids moyen
	somme = 0;
	for(i = 0; i < nbPatient; i++) {
		somme = somme + tMasse[i];
	}
	printf("\nLa masse moyenne des patients est : %.2f\n", somme / nbPatient);
	
	//	E.	Pour chaque patient, calculer l’indice de masse corporelle : IMC = m/t*t 
	// 		et afficher : pas assez , trop ou normal selon son IMC
	for(i = 0; i < nbPatient; i++) {
		imc = tMasse[i] / (tTaille[i] * tTaille[i]);
		
		printf("\nIMC patient %d : %.2f", i + 1, imc);

		if(imc < 18.5) {
			printf(" => Pas assez");
		} else {
			if(imc > 25) {
				printf(" => Trop");
			} else {
				printf(" => Normal");
			}
		}
	}	
		
	return 0;
}*/
