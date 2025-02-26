//transmission sous forme d'une trame
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_TAB 256

int main()
{
char trame[TAILLE_TAB];
long checksum = 0;
char temp[TAILLE_TAB];
//---------------------------------------------------------------------------------------------------------------------
//Invitation à la saisie
printf("\t***Veuillez saisir un message à transmettre***\n");
scanf("%s", temp);
strcpy(trame,temp);

//calcul du checksum
for (unsigned long i = 0; i < strlen(trame); i++)
{
	checksum = (checksum + trame[i]) % 65536;
}

//affichage de la trame
printf("Trame : 0x%02X 0x%02X 0x%02X ", 0x02, strlen(trame) >> 8, strlen(trame) & 0xFF);
for (unsigned long i = 0; i < strlen(trame); i++)
{
	printf("0x%2X ", trame[i]);	
}
printf("0x%02X 0x%02X 0x%02X\n", checksum >> 8, checksum & 0xFF, 0x03);


return 0;
}
