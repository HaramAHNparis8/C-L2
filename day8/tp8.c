#include<stdio.h>
#include<stdlib.h>
typedef struct s_noeudh_t {
    int v; 
    struct s_noeudh_t* g;
    struct s_noeudh_t* d; 
    int h; 
} noeudh_t;

int ajouterABR(noeudh_t** a, int x) {

    if (*a == NULL) {
        *a = malloc(sizeof(noeudh_t));
        if (*a == NULL) { 
            return -1; 
        }
        (*a)->v = x;
        (*a)->g = (*a)->d = NULL;
        (*a)->h = 0; 
        return 1;
    }
    

    if (x < (*a)->v) {
        return ajouterABR(&((*a)->g), x);
    } else if (x > (*a)->v) {
        return ajouterABR(&((*a)->d), x);
    }

    
    return 0;
}

int chercher(noeudh_t* a, int x) {
    if (a == NULL) {
        
        return 0;
    }
    if (x == a->v) {
        
        return 1;
    } else if (x < a->v) {

        return chercher(a->g, x);
    } else {

        return chercher(a->d, x);
    }
}

int extraireMaxABR(noeudh_t** a) {
    if (*a == NULL) {

	    return -1;     
    }
    
    if ((*a)->d == NULL) {
	    noeudh_t* temp = *a;
	    int maxVal = temp->v;
	    *a = (*a)->g;
	    free(temp);         
	    return maxVal;

    } 
    else {

	    return extraireMaxABR(&((*a)->d));
    }
}


int extraireMinABR(noeudh_t** a) {
    if (*a == NULL) {

	    return -1;     
    }
    
    if ((*a)->g == NULL) {
	    noeudh_t* temp = *a;
	    int minVal = temp->v;
	    *a = (*a)->d;
	    free(temp);         
	    return minVal;

    } 
    else {

	    return extraireMinABR(&((*a)->g));
    }
}

int supprimerABR(noeudh_t** a, int x) {
    if (*a == NULL) {
        return 0;  
    }

    if (x < (*a)->v) {
	    return supprimerABR(&((*a)->g), x);      
    } 
    else if (x > (*a)->v) {
	    return supprimerABR(&((*a)->d), x);      
    } 
    else {
        
        return 1;      
    }
}

int hauteurAVL(noeudh_t* r) {
    if (r == NULL) {
	    return -1; 
    } 
    else {
	    return r->h; 
    }
}

void miseAJHaut(noeudh_t* r) {
    if (r == NULL) {
        return;
    }

    int hauteurGauche = -1;
    int hauteurDroite = -1;

    if (r->g != NULL) {
        hauteurGauche = r->g->h;
    }
    if (r->d != NULL) {
        hauteurDroite = r->d->h;
    }

    r->h = (hauteurGauche > hauteurDroite ? hauteurGauche : hauteurDroite) + 1;
}
void rotationG(noeudh_t** r) {

    if (r == NULL || (*r)->d == NULL) {

        return; 
    }
    
    noeudh_t* temp = (*r)->d;
    (*r)->d = temp->g;
    temp->g = *r;
    *r = temp;

    
}
int main(void){

	noeudh_t* arbre = NULL;
	ajouterABR(&arbre, 5);
	ajouterABR(&arbre, 3);
	ajouterABR(&arbre, 8);
	ajouterABR(&arbre, 1);
	ajouterABR(&arbre, 4);

    	//printf("verification: %d\n", chercher(arbre, 4));
    	//printf("verification: %d\n", chercher(arbre, 7));

        int maxVal = extraireMaxABR(&arbre), Minval = extraireMinABR(&arbre);
	//printf("Extra max val: %d\n", maxVal);
	//printf("Extra min val: %d",Minval);
	//supprimerABR(&arbre,4);

	return 0;
}
