#include <stdio.h>
#include <stdlib.h>

typedef struct noeud_s_t {
    int v; // étiquette du noeud
    struct noeud_s_t* g; // pointeur vers la racine du sous arbre gauche
    struct noeud_s_t* d; // pointeur vers la racine du sous-arbre droit
} noeud_t;

int max(noeud_t* racine, int v) {
        if (racine == NULL) {

		return v;
    }

        int maxGauche = max(racine->g, v);

        int maxDroit = max(racine->d, v);

        int maxCourant = racine->v;
    if (maxGauche > maxCourant) {
        maxCourant = maxGauche;
    }
    if (maxDroit > maxCourant) {
        maxCourant = maxDroit;
    }

    return maxCourant;
}

void prefixeAux(int* a, int n, int i) {
    if (i >= n || a[i] == -1) { 
        printf("V ");
        return;
    }

        printf("%d ", a[i]);

        prefixeAux(a, n, 2 * i + 1);

        prefixeAux(a, n, 2 * i + 2);
}

void prefixe(int* a, int n) {
    prefixeAux(a, n, 0); 
}

int hgAux(noeud_t* r, int* t) {
    if (r == NULL) {
        return 1;
    }

    int gauche = compteNoeuds(r->g);
    int droit = compteNoeuds(r->d);

    if (gauche < droit) {
        return 0;
    }

    *t += 1; 

    return hgAux(r->g, t) && hgAux(r->d, t);
}

int hg(noeud_t* r, int* t) {
    *t = 0;     
    return hgAux(r, t);
}


int main() {



    return 0;
}

