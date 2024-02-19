#include<stdio.h>
#include<stdlib.h>


typedef struct s_noeud_t{

   int v;
   struct s_noeud_t* g;
   struct s_noeud_t* d;
} noeud_t;

noeud_t* consA(noeud_t* gau, noeud_t* droit,int etiquette){
	noeud_t* nvnoeud = (noeud_t*)malloc(sizeof(noeud_t));
	if(nvnoeud == NULL){

		return NULL;
	}

	nvnoeud -> v = etiquette;
	nvnoeud -> g = gau;
	nvnoeud -> d = droit;

	return nvnoeud;

}
void liberer(noeud_t* a) {
	if (a != NULL) {
		liberer(a->g);
		liberer(a->d);
		free(a);
    }
}

void parcourirPref(noeud_t* a){
	if (a == NULL) {
        return; 
    }

    printf("%d ", a->v);
    parcourirPref(a->g);
    parcourirPref(a->d);

}

void parcourirPost(noeud_t* a){
	 if(a == NULL){
		 return;
	 }
	 parcourirPost(a -> g);
	 parcourirPost(a -> d);
	 printf("%d ", a -> v);


 }
void parcourirInfix(noeud_t* a){
	if(a == NULL){

		return;
	}
	parcourirInfix(a -> g);
	printf("%d ", a -> v);
	parcourirInfix(a -> d);
}

int taille(noeud_t* arbre) {
    if (arbre == NULL) {
        return 0;
    }
    return 1 + taille(arbre->g) + taille(arbre->d);
}

int nbFeuilles(noeud_t* arbre) {
    if (arbre == NULL) {
        return 0;
    }

    if (arbre->g == NULL && arbre->d == NULL) {
        return 1;
    }
    return nbFeuilles(arbre->g) + nbFeuilles(arbre->d);
}
int hauteur(noeud_t* a){
    int htGauche, htDroite;
    if(a == NULL){
        return -1;
    }
    htGauche = hauteur(a->g);
    htDroite = hauteur(a->d); 
    if(htGauche > htDroite){
        return htGauche + 1;
    } 
    else {
        return htDroite + 1;
    }
}
int estDans(noeud_t* a, int v) {
    if (a == NULL) {
        return 0;
    }

    if (a->v == v) {
        return 1;
    }

    return estDans(a->g, v) || estDans(a->d, v);
}
void construirePref(noeud_t** a) {
	int val;
	scanf("%d", &val); 
	if (val == -1) {
		*a = NULL;
		return;
	} 
	else {
		*a = (noeud_t*)malloc(sizeof(noeud_t));
		(*a)->v = val;
		construirePref(&((*a)->g));
		construirePref(&((*a)->d)); 
	}
}
void afficherArbre(noeud_t* a) {
	if (a != NULL) {
		printf("%d ", a->v);
		afficherArbre(a->g);
		afficherArbre(a->d);
	}
}



int main(void){
	int tab[] = {1, 3, 4, -1, -1, 5, -1, -1, 2, -1, -1};
	noeud_t *arbre1 = NULL;
	noeud_t *arbre2 = NULL;
	noeud_t* arbre = consA(consA(consA(NULL, NULL, 4), consA(NULL, NULL, 5), 3), consA(NULL, NULL, 2), 1);
	 //parcourirPref(arbre);
	 //parcourirPost(arbre);
	 //parcourirInfix(arbre);
	 //liberer(arbre);
	 //printf("%d",taille(arbre));
	 //printf("%d",nbFeuilles(arbre));
	 //printf("%d ",hauteur(arbre));
	 //printf("%d ",estDans(arbre,0));
	 printf("Arbre 1 : Entrez les valeurs (terminez avec -1 pour un noeud vide):\n");
	 construirePref(&arbre1);
	 printf("Arbre 1 en préfixe: ");
	 afficherArbre(arbre1);
	 printf("\n");

	 return 0;
}
