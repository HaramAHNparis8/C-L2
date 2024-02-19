#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void exo1(){
	printf("bonjour");
}

void exo2(){

	short int z=0;
	int a=4; // on sait que sizeof(int)==4
	char b=2;
	short int c=1;
	printf("%p\n",&a);
	printf("%d\n",b);
	printf("%p\n",&c);

}

void exo3(){

    int a,b;
    int *p = &a;
    *p = 1;
    p = &b;
    *p = a + 3;
    printf("%d\n",a);
    printf("%d\n",b);
    
}

void exo6(){
	int a=3;
	int b=4;
	int *p=malloc(sizeof(a)*3);
	char* pc=(char*) p;
	p[1]=0;
	p[4]=0;
	pc[1]=0;
	printf("taille %ld\n",sizeof(int));
	printf("taille %ld\n",sizeof(int*));
	printf("&a:%p\n",&a);
	printf("&b:%p\n",&b);
	printf("&p:%p\n",&p);
	printf(" p:%p\n",p);
}
void exo7(){
	 int i;
	 int *ptr = malloc(sizeof(int) * 1000);
         ptr=malloc(sizeof(int)*1000);
         for(i=0;i<1000;i++){
		 ptr[i]=i;
	 }
	 for(i = 0; i < 1000; i++){
		 printf("%d\n",ptr[i]);
		
	 
	 }	 

}

void exo8(){

	int a=1;
	int* p;
	int b=2;
	int** h=&p;
	p=&a;
	int* d=&b;
	*h=&b;
	**h=4;
	*p=5;
	printf("a:%d,b%d\n",a,b);
}

void exo9(int argc, char **argv){
	int n, i;
	char *p;
	if (argc > 0) {
		n = strlen(argv[0]);
		p = (char *)malloc(sizeof(char) * (n + 1));
	}
	for (i = 0; i < n; i++){
            p[i] = argv[0][n - i - 1];
	    
	    p[n] = '\0';
	    printf("%s\n", p);
	    free(p);
	}

}
//exo10
typedef struct{

	float x;
	float y;
}Vecteur;

Vecteur somme(Vecteur a, Vecteur b){
	
	Vecteur res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;

	return res;
}

Vecteur sommeTab(int n, Vecteur* tab){
	Vecteur res = {0.0,0.0};
	int i;
	for(i = 0; i < n; i++){
		res = somme(res,tab[i]);
	}

	return res;
}
int main(void){
	//exo1();
	//exo2();
	//exo3();
	//exo6();
	//exo7();
	//exo8();
	//char **H ={'H','E','L','L','O'};
	//exo9(5,**H);
	//Vecteur vec1 = {1.0, 2.0};
	//Vecteur vec2 = {3.0, 4.0};
	//Vecteur res = somme(vec1,vec2);
	//printf("c'est le res : x = %f\t y = %f\t",res.x,res.y)
	//Vecteur vecteurs[] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
	//int n = sizeof(vecteurs) / sizeof(vecteurs[0]);
	//Vecteur res = sommeTab(n, vecteurs);
       	//printf("res: x=%f, y=%f\n", res.x, res.y);
	return 0;

}
