#include<stdio.h>
typedef struct node_t{
	int v;
	struct node_t * g;
	struct node_t * d;
} node_st

void Dtom(int n){
	if(n < 1){
		return;
	}
	motd(n - 1);
	printf("y");
	Dtom(n - 1);
}

void motd(int n){
	if(n < 1){
		return;
	}
	motD(n - 1);
	printf("x");
	Dtom(n - 1);
}

void fusion(node_st ** g,node_st ** d){
	node_st * t;
	while(*d != NULL){
		if((*g) !=NULL && (*g) -> v > (*d)->v){
			t = *d;
			*d = (*d) -> s;
			t -> s= *g;
		}
		*g = t;
		g = &(*g) -> s;
	}
}

int calcule_postfixe(char* tab){

}

int main(void){


	return 0;
}
