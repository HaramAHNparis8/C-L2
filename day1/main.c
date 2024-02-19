#include <stdio.h>
#include "maBibli.h" // maBibli 라이브러리의 헤더 파일을 포함

int main() {
	int t[] = {1,2,3,4,5},res1, res2, n = sizeof(t)/sizeof(int);
	res1 = somme(n,t);
	res2 = produit(n,t);

	printf("Res_sum : %d\n", res1);
	printf("res_produit : %d\n",res2);
	return 0;
}

