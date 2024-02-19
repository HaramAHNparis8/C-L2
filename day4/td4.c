#include<stdio.h>
#include<stdlib.h>
int recherche(int n,int* tab,int val){
	int i,v,r;
	if(n < 1) return -1;
	i = n /2;
	v = tab[i];
	if(i == val){
		return i;
	}
	else{
		r = i + 1 +recherche(n - i -1,tab + 1,val);
		if(n == 1) return -1;
		return r + i + 1;

	}
	

}
void echange(int * a, int * b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* tab, int debut, int fin){
	int pivot, i,j;
	pivot = tab[fin];
	i = (debut - 1);
	for(j = debut; j <= fin - 1; j++){
		if(tab[j] <= pivot){
			i++;
			echange(&tab[i],&tab[j]);
		}
	}
	echange(&tab[i + 1], &tab[fin]);
	return (i + 1);

}

void triRapide(int* tab, int debut, int fin){
	int pivotidx;

	if(debut < fin){

		pivotidx = partition(tab,debut,fin);
		triRapide(tab,debut,pivotidx - 1);
		triRapide(tab,pivotidx + 1,fin);
	}
}

void triRapideWrapper(int* tab, int taille){
	triRapide(tab,0,taille - 1);
}

void fusion(int n1, int* t1, int n2, int* t2, int* t)
{
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (t1[i] < t2[j]) {
            t[k++] = t1[i++];
        } else {
            t[k++] = t2[j++];
        }
    }
    
    while (i < n1) {
        t[k++] = t1[i++];
    }
    
    while (j < n2) {
        t[k++] = t2[j++];
    }
}
void copie(int n, int* dest, int* src) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void triFusion(int n, int* tab, int* tabT) {
	int n1 = n / 2,n2 = n - n1;

	if (n > 1) {
                
        triFusion(n1, tab, tabT);
        triFusion(n2, tab + n1, tabT + n1);
        
        fusion(n1, tab, n2, tab + n1, tabT);
        
        copie(n, tab, tabT);
    }
}

void affichage(int* tab, int taille){
	int i;
	for(i = 0;i < taille; i++){
		printf("%d ",tab[i]);
	}
}

void Fusion(int* T1, int tailleT1, int* T2, int tailleT2, int* T) {
    int i = 0, j = 0, k = 0;

    while (i < tailleT1 && j < tailleT2) {
        if (T1[i] <= T2[j]) {
            T[k] = T1[i];
            i++;
        } else {
            T[k] = T2[j];
            j++;
        }
        k++;
    }

    while (i < tailleT1) {
        T[k] = T1[i];
        i++;
        k++;
    }

    while (j < tailleT2) {
        T[k] = T2[j];
        j++;
        k++;
    }
}


void tri_fusion_t(int* T, int taille, int* Tableau_temporaire) {
	int milieu = taille / 2,i;

	if (taille <= 1) {
		return;     
	}
	tri_fusion_t(T, milieu, Tableau_temporaire);     
	tri_fusion_t(T + milieu, taille - milieu, Tableau_temporaire); 
	Fusion(T, milieu, T + milieu, taille - milieu, Tableau_temporaire); 
	for (i = 0; i < taille; i++) {
		T[i] = Tableau_temporaire[i];
    }
}


int tri_fusion(int* T, int taille) {
    int* Tableau_temporaire = (int*)malloc(taille * sizeof(int));
    if (Tableau_temporaire == NULL) {

	    return -1;     
    }

    tri_fusion_t(T, taille, Tableau_temporaire);
    free(Tableau_temporaire);

    return 0;
}


int main(void){
	int tab[] = {23,21,232,122,32,22,657};
	int n = sizeof(tab) / sizeof(tab[0]);
	int* tab_tmp = (int*)malloc(n * sizeof(int));
	//printf("indice : %d", recherche(5,tab,2));
	//triRapideWrapper(tab, n);
	//affichage(tab,n);
	//tri_fusion_t(tab,n,tab_tmp);

	affichage(tab,n);
	
	
	return 0;
}
