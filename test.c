#include<stdio.h>

int main(void){


	
   pileI_t p; // pile d’int
   fileI_t f; // file d’int
   initialiserPI(&p);
   initialiserFI(&f);
   emPilerI(&p,1);
   enFilerI(&f,2);
   emPilerI(&p,3);
   emPilerI(&p,4);
   enFilerI(&f,5);
   printf("%d\n",deFilerI(&f));
   printf("%d\n",dePilerI(&p));
   emPilerI(&p,6);


	return 0;
}





