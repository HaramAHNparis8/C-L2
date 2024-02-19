typedef struct s_noeud_t{

   int v; // étiquette du noeud (v pour valeur)
   struct s_noeud_t* g; // pointeur vers la racine du sous-arbre  gauche
   struct s_noeud_t* d; // pointeur vers la racine du sous-arbre droit

} noeud_t;

//exo1
noeud_t* consA(noeud_t* ga,noeud_t* da,int va){
	noeud_t* n = (noeud_t*)malloc(sizeof*n);
	if(n == NULL){
		exit(1);

	}
	n -> v = va;
	n -> g = ga;
	n -> d = da;

	return m;
}
//exo2
//
int taille(noeud_t * head){
	
	if(head == NULL){
		return 0;

	}
	return 1 + taille (a ->g) + taille(a -> d);
}
void liberer(noeud_t* a){
	if(a == NULL){
		return;
	}
	liberer(a->g);
	liberer(a->d);
	a = NULL;
}


int main(void){

}
