//#include<stdio.h>
//bonjour, j'ai essaye plusieur fois a calculer la taille de tableau qui a recu par sizeof mais a cause de la convertissement des tableau vers la pointeur, ce n'est pas possible pour calculer alors je n'utilise pas sizeof.

#include "maBibli.h"


int somme(int n, int* T){
	int s = 0,i;


	for(i = 0; i < n; i++){
		s += T[i];
	}
	if(s == 0 && n == 0){//pour savoir la liste est vide
		return 0;
	}
	
	return s;
}

int produit(int n, int* T){
	int s = 1,i;

	for(i = 0; i < n; i++){
		s *= T[i];
	}
	if(s == 1 && n == 0){//pour savoir la liste est vide
		return 1;
	}
	return s;
}


//int main(void){
	//int t[] = {1,2,3,4,5}, test[] = {};
	//int n = sizeof(t) / sizeof(int), len = sizeof(test) / sizeof(int);
	//printf("%d", n);
	//printf("%d",len);

//	printf("%d",somme(n,t));
//	printf("%d", somme(len,test));
//	printf("%d\n",produit(n,t));
//	printf("%d\n",produit(len,test));
//	return 0;
//}
