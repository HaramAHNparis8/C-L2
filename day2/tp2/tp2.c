#include<stdio.h>
#include <stdlib.h>
#include <time.h>


  int fonction(int a){
     srand(time(0));
     return (rand()*a)%100;
}
 void rebour(int n){
  if(n<0) return;
      rebour(n - 1);
      printf("%d\n",n);
      
   }
void remplirRecTab(int taille,int* tabl){
	if(taille == 0){
		return;
	}
	tabl[taille] = fonction(taille);
	printf("tab : %d \n",tabl[taille]);
	remplirRecTab(taille - 1, tabl);

}
int sommeChiffres(int a){
	if (a < 10){
		return 0;
	}

	return(a % 10) + sommeChiffres(a / 10);



}

int  rechercherRecTab(int taille, int* tab, int val) {
	if(taille == 0){

		return -1;
	}
	if(val == tab[taille -1]){
		
		return taille -1;
	}
	return rechercherRecTab(taille -1,tab,val);
}
int test_recherche_func(int taille, int* tab, int val,int indice){
	if(val == tab[indice])return indice;	
	if(indice == taille -1)return -1;
	return test_recherche_func(taille,tab,val,indice + 1);
}

int test_recherche(int taille, int* tab, int val){
	return test_recherche_func(taille,tab,val,0);
}
float racineCarreeRecur(float a, float s, float precision){
	float S = 0.5 * (s + a / s);
	if ((S * S - a) < precision){ 

		return S;
    } 
	return racineCarreeRecur(a, S, precision);
}


float racineCarree_terminal(float a, float precision) {
    return racineCarreeRecur(a,a,precision);
}

//exo6 -option1

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}
void triertab(int taille, int* tab){
	int i;
	if(taille <= 1)return;
	
	for(i = 0; i < taille - 1; i++){
		if(tab[i] > tab[i +1]){
			swap(&tab[i],&tab[i + 1]);
		}
	}
	triertab(taille - 1, tab);
}
//exo6 -option2
void trier_avec_insert(int taille, int* tab){
	if(taille <= 1)return;

	trier_avec_insert(taille - 1, tab);

	int dernier = tab[taille - 1], i = taille - 2;

	while(i >= 0 && tab[i] > dernier){
		tab[i + 1] = tab[i];
		i = i -1;
	}

	tab[i + 1] = dernier;


}

//exo6 -option3
void trier_avec_select_funct(int taille,int* tab, int current_indice){
	int min_indice, i;
	
	if(current_indice == taille - 1){
		return;
	}
	min_indice = current_indice;
	for(i = current_indice + 1; i < taille; i++){
		if(tab[i] < tab[min_indice]){
			min_indice = i;
		}
	}
	swap(&tab[current_indice],&tab[min_indice]);
	trier_avec_select_funct(taille,tab,current_indice + 1);

}
void trier_avec_select(int taille, int* tab){
	return trier_avec_select_funct(taille,tab,0);
}

//exo6 -option4
int division_tab(int* tab, int enbas, int enhaut){
	int division = tab[enhaut],i,j;
	i = (enbas - 1);
	for(j = enbas; j < enhaut; j++){
		
		if(tab[j] < division){
		   i++;
	   	   swap(&tab[i], &tab[j]);	   
		}
	}

	swap(&tab[i + 1], &tab[enhaut]);

	return (i + 1);
}

void trier_quickSort_recursion(int* tab, int enbas, int enhaut) {
	
	int div;
	if(enbas > enhaut){
		div = division_tab(tab,enbas,enhaut);
		trier_quickSort_recursion(tab,enbas,div -1);
		trier_quickSort_recursion(tab,div + 1,enhaut);
	}
}
void trier_quickSort_recursion_terminal(int taille, int* tab){
	return trier_quickSort_recursion(tab,0,taille -1);

}
void affichage_tab(int taille, int* tab){
	int i;

	for(i = 0; i < taille; i++){
		printf("%d\t", tab[i]);
	}
}
int sacADos(int taille, int* M, int* V, int m){
	
	int prendre,prendpas;

	if(taille == 0 || m == 0){
		return 0;
	}
	if(M[taille - 1] > m){
		return sacADos(taille - 1,M, V,m);
	}

	prendre =  V[taille - 1] + sacADos(taille - 1, M, V, m - M[taille - 1]);
	prendpas = sacADos(taille - 1, M, V, m);

	return (prendre > prendpas) ? prendre : prendpas;

}
int main(void){
	int taille = 10, n = 5;
	int tabl[taille],tab_exo4[] = {22,12,3,5,2};
	float a = 25.0, precision = 0.001;
	int M[] = {2,3,4,5},V[] = {3,4,5,6};
	int m = 5;
	//rebour(10);
	//remplirRecTab(taille,tabl);
	//printf("somme chiffres : %d\n",sommeChiffres(123));
	//printf("indice : %d\n",rechercherRecTab(n,tab_exo4,3));
	//printf("test : indice : %d\n",test_recherche(n,tab_exo4,0));
	//printf("%f\n",racineCarree_terminal(a,precision));
//	option1
	//triertab(5,tab_exo4);
// 	option2
	//trier_avec_insert(5,tab_exo4);
	//option3 -> je sais que c'est recursivite terminalc'est complique de nommer alors
	//trier_avec_select(5,tab_exo4);
	//option4
	//trier_quickSort_recursion_terminal(5,tab_exo4);
//afin de tester le résulat de la function trié des tableau exécultez avec la function nommé affichage_tab.
	
	//affichage_tab(5,tab_exo4);
	//printf("la val de max est : %d",sacADos(4,M,V,m));
	return 0;
}
