#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int entrezlenombre(void){
	
	int n = 0;
	printf("Entrez un nombre n :\t");
	scanf("%d", &n);
	return n;
}

void verification_valeur(int *n){
	
	while(*n <= 0){

		printf("la val est pas bien\n");
		*n = entrezlenombre();
	}
}

void creationfichier(void){
	
	int n = 0,num_al,i;

	n = entrezlenombre();
	verification_valeur(&n);
	
	FILE *fichier = fopen("alea.nb", "w");

	srand(time(NULL));
	for (i = 0; i < n; i++) {
        num_al = rand() % 101;
        fprintf(fichier, "%d ", num_al);
	 
    }
	fclose(fichier);

}

int main(void){
	creationfichier();
}
