#include<stdio.h>

int calcUI(int n){
	if(n == 0){

		return 1;
	}
	else{

	return 3 * calcUI(n - 1) + 1;
	}

}
int calcUI_itr(int n){
	int i,res = 1;

	for(i = 0; i < n; i++){

		res = 3 * res + 1;
	}

	return res;

}


void hanoi(int n,char d,char i,char a){
	if(n == 0){
		return;

	}
	
	hanoi(n - 1, d,a,i);
	printf("%c -> %c\n",d,a);
	hanoi(n -1,i,d,a);
	
}

int compte(int t, int E[], int S){
	if(s == 0){
		return 1;
	}
	if(t==0){
		return 0;
	}
	return compte(t - 1, E,S) || compte(t -1, E,S-E[t - 1]);
}

int main(void){
	//printf("%d\n",calcUI(3));
	//printf("%d\n",calcUI_itr(3));
	//hanoi(3,'A','B','C');
	int E = {1, 5, 7, 9, 14} ;
	int s = 13;
	compte(sizeof(E),&E,s);

	return 0;
}
