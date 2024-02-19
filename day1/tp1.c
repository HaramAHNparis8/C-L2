#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// exo1
void echange(int * a, int * b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Ech(void){
	int x= 0, y = 1;
	echange(&x,&y);
	printf("x : %d, y : %d", x,y);
}

//exo2
void afficher_tableau(int n,int* T){
	int i;

	for(i = 0; i < n; i++){
		
		printf("%d\t", T[i]);
	}

}

//exo3
int genererAlea(int a, int b) {
	
	int num;

	if(a > b){
		echange(&a,&b);
	}

	srand(time(NULL));
	num = a + rand() % (b - a + 1);
	
	return num;
}

int main(void){
	
	int Tableau[] = {1,2,3,4,5};
	int n = 5,a = 1 , b = 5;

	//Ech();
	//afficher_tableau(n,Tableau);
	//printf("%d", genererAlea(a,b));
	return 0;
}
