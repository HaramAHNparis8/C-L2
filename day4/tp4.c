#include <stdio.h>
#include <time.h>
#include <stdlib.h>

unsigned long long recursiveFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

unsigned long long iterativeFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long result;

    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}
void letempprisrecursivite(int n){
	
	clock_t commence, fin;
	double cpu_temps_pris;
	commence = clock();
	unsigned long long recursiveResult = recursiveFibonacci(n);
	fin = clock();
	cpu_temps_pris = ((double)(fin - commence)) / CLOCKS_PER_SEC;
	printf("Fibonacci(%d) (récursif) = %llu, temps d'exécution : %f secondes\n", n, recursiveResult, cpu_temps_pris);

}

void letempprisiter(int n){
    clock_t commence, fin;
    double cpu_temps_prise;
    commence = clock();
    unsigned long long iterativeResult = iterativeFibonacci(n);
    fin = clock();
    cpu_temps_prise = ((double)(fin - commence)) / CLOCKS_PER_SEC;
    printf("Fibonacci(%d) (itératif) = %llu, temps d'exécution : %f secondes\n", n, iterativeResult, cpu_temps_prise);
}

int puissance(int a, int n) {
	int temp;
	if (n == 0) {
		return 1;
	} 
	else if (n % 2 == 0) {
		temp = puissance(a, n / 2);
		return temp * temp;
	} else {
		temp = puissance(a, (n - 1) / 2);
		return a * temp * temp;
    }
}
void affichage(int taille, int* tab){
	int i;

	for (i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
}

void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *tab, int debut, int fin) {
	int pivot = tab[fin];
	int i = (debut - 1),j; 

	for (j = debut; j <= fin - 1; j++) {
        
        if (tab[j] <= pivot) {
            i++; 
            echanger(&tab[i], &tab[j]);
        }
    }
    echanger(&tab[i + 1], &tab[fin]);
    return (i + 1);
}

void quicksort(int *tab, int debut, int fin) {
	int pi;

	if (debut < fin) {

        pi = partition(tab, debut, fin);

        quicksort(tab, debut, pi - 1);
        quicksort(tab, pi + 1, fin);
    }
}

void triRapide(int n, int *tab) {
    quicksort(tab, 0, n - 1);
}

void fusion(int *tab, int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1, n2 = fin - milieu,i,j,k;
    int gauche[n1], droite[n2];

       for (i = 0; i < n1; i++)
        gauche[i] = tab[debut + i];
    for (j = 0; j < n2; j++)
        droite[j] = tab[milieu + 1 + j];

        i = 0;
	j = 0;     
	k = debut;

    while (i < n1 && j < n2) {
        if (gauche[i] <= droite[j]) {
            tab[k] = gauche[i];
            i++;
        } else {
            tab[k] = droite[j];
            j++;
        }
        k++;
    }

        while (i < n1) {
        tab[k] = gauche[i];
        i++;
        k++;
    }

        while (j < n2) {
        tab[k] = droite[j];
        j++;
        k++;
    }
}
void tri_fusion_rec(int *tab, int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;

        tri_fusion_rec(tab, debut, milieu);
        tri_fusion_rec(tab, milieu + 1, fin);

	fusion(tab, debut, milieu, fin);
    }
}
void tri_fusion(int *tab, int taille) {

	tri_fusion_rec(tab, 0, taille - 1);
}
int main() {
    int n = 40,valpuissance1 = 2, valpuissance2 = 10; 
    int tab[] = {10, 7, 8, 9, 1, 5};
    int nb = sizeof(tab) / sizeof(tab[0]);
    //letempprisrecursivite(n);
    //letempprisiter(n);
    //printf("%d ",puissance(valpuissance1,valpuissance2));
    //triRapide(nb, tab);//testez sans ce ligne ou avec ce ligne
    //affichage(nb,tab);
    tri_fusion(tab, nb);
    affichage(nb,tab);
    return 0;
}

