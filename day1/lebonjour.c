#include<stdio.h>
#include<stdlib.h>
#define n 1000

void lebonjour(){

	char nom[n];

	printf("Quel est votre nom?\n");
	scanf("%s", nom);

	printf("Bonjour %s au revoir", nom);
	exit(0);

}

int main(void){

	lebonjour();



	return 0;
}
