#include<stdio.h>
#include<stdlib.h>

void tabulle(int n, int t[]){
	int i,j,tmp;
	for(i = 0; i < n; i++){

		for(j = 0; j < n - i - 1; j++){

			if(t[j] > t[j +1]){
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}
	}
}

//recursivite Rn = 1 + 1 R n -1 + R n -2 + 1
//
//la recursivite au moin autant que f n + le grand que 0(n)
int fiboR(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return fiboR(n - 2) + fiboR(n - 1);
}
int fiboni(int n){
	int i;
	int f1,f2,r;
	if(n < 2){

		return n;
	}
	for(i = 2; i < n; i++){

		r = f2 + f1;
		f2 = f1;
		f1 = r;
	}

	return r;

}
//null est un liste vide,  Null mahqye la fin de liste
typedef struct cellule_t{
	int v; //valeur 

	struct cellule_t* s;	 //
} cellule_t;

int somme(cellule_t * l){
	int s = 0;

	while(l != NULL){
		s += (*l).v;
		l =(*l).s;
	}

	return s;
}
cellule_t* alloue(int va,cellule_t* su){

	cellule_t* n = (cellule_t *) malloc(sizeof(cellule_t));
	if (n == NULL){
		exit(1);
	}

	n -> v = va;
	n -> s = su;
	return n;


}


void ajouteTele(int n, cellule_t **liste){

	*liste = alloue(n, *liste);
}

void LibererL(cellule_t **l){
	
	if(*l == NULL){
		return;
	}
	LibererL(&(*l) -> s);
	free(*l);
	*l = NULL;
}
int main(void){

	int t[] = {3,233,21,26,5}, i;
	tabulle(5,t);
	cellule_t *liste = NULL;
	ajouteTele(5,&liste);
	ajouteTele(5,&liste);
	printf("%d ",somme(liste));
	return 0;
}

//une liste chainee est une maniere d'organiser la memoire pour representer une liste de valeurs, elle est composee de zone memoires appelle 'cellule'. Chaque cellule memorise deux choses - valeur(int, float, char*,...), l'adresse memoire suivant de cellile suivant 
//remrque(convantion en C)
//- on passe une liste a une fonction par l'adresse de sa premier cellule
