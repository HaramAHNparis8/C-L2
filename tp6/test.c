#include<stdio.h>
int mystere(int n, int* t){
	if(n < 1){

		return 1;
	}
	printf("%d\n", *t);
	return mystere(n - 1, t + 2) + *t;
}


int main(void){

	int T[5] = {-2,1,6,-5,-2};
	printf("%d\n", mystere(3,T));
	return 0;
}
