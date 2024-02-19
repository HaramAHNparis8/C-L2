#include<stdio.h>

//On : complexcite en temps de ostap dans le prie des cas et dans le cas moyens
void triBulle(int taille,int* T) {
   int echangeFait=1;
   int i;
   while(echangeFait) {
      echangeFait=0;
      for(i=0;i<taille-1;i++)
         if(T[i+1] < T[i]) { // ici comparaison
            echange(T+i,T+i+1);
            echangeFait=1;
	 } 
   }//T : complexcite en temps de tarass dans le prie des cas et le cas moyens

}
int ostap(int n) {// seta(n) - complexcite temporelle
		  //seta(1) - complexcite en espace- seta(1) + seta(1) + seta(1) + seta(1)
   int S=0,i;
   for(i=0;i<n;i++)
      S+=i;
   return S;
}
int tarass(int n)
{
   int S=0,i;
   for(i=0;i*i<n;i++)// rascine n으로 취
      S+=i;
   return S;
   
}

int T[81];
int colonne(int i){

	return i / 9;
}
int ligne(int i){

	return i % 9;
}
int indice(int l,int c){
	return l * 9 + c;
}
int main(void){


	return 0;
}
