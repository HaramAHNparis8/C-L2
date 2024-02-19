#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int estUnTas(int n, int* T) {

	int i;

	for (i = 0; i <= (n - 2) / 2; i++) {

        if (T[i] < T[2*i + 1] || (2*i + 2 < n && T[i] < T[2*i + 2])) {
            return 0;
        }
    }
    return 1; 
}

typedef struct {
    int capacity;
    int size;
    int* elements;
} tas_t;

void vider(tas_t* t) {
    t->size = 0;
}

void ajouter(tas_t* t, int v) {
    if (t->size == t->capacity) {
        printf("Heap is full\n");
        return;
    }

       t->size++;
    int i = t->size - 1;
    t->elements[i] = v;

  
    while (i != 0 && t->elements[(i - 1) / 2] > t->elements[i]) {
        int temp = t->elements[i];
        t->elements[i] = t->elements[(i - 1) / 2];
        t->elements[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}


int extraireMin(tas_t* t) {
    if (t->size <= 0) {
        return INT_MAX;
    }
    if (t->size == 1) {
        t->size--;
        return t->elements[0];
    }


    int root = t->elements[0];
    t->elements[0] = t->elements[t->size - 1];
    t->size--;

    int i = 0;
    while (i < t->size) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < t->size && t->elements[left] < t->elements[smallest])
            smallest = left;
        if (right < t->size && t->elements[right] < t->elements[smallest])
            smallest = right;

        if (smallest != i) {
            int temp = t->elements[i];
            t->elements[i] = t->elements[smallest];
            t->elements[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }

    return root;
}

void echanger(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void siftDown(int *t, int start, int end) {
    int racine = start;

    while ((racine * 2 + 1) <= end) {
        int enfant = racine * 2 + 1;
        int swap = racine;

        if (t[swap] < t[enfant]) {
            swap = enfant;
        }
        if ((enfant + 1) <= end && t[swap] < t[enfant + 1]) {
            swap = enfant + 1;
        }
        if (swap == racine) {
            return;
        } else {
            echanger(&t[racine], &t[swap]);
            racine = swap;
        }
    }
}

void triParTas(int n, int *t) {

    int i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        siftDown(t, i, n - 1);
    }

    
    for (i = n - 1; i > 0; i--) {
        echanger(&t[i], &t[0]);
        siftDown(t, 0, i - 1);
    }
}







void affichage(int* t, int n){
	int i;

	for(i = 0; i < n; i++){

		printf("%d ", t[i]);
	}
	
}
int main(void){
	int T[] = {10, 9, 8, 7, 6, 5, 4};
	int n = sizeof(T)/sizeof(T[0]);

	//tas_t myHeap;
	//int heapCapacity = 10;
	//myHeap.elements = (int*)malloc(heapCapacity * sizeof(int));
	//myHeap.capacity = heapCapacity;
	//vider(&myHeap);
	//ajouter(&myHeap, 3);
	//ajouter(&myHeap, 2);
	//ajouter(&myHeap, 15);
	//ajouter(&myHeap, 5);
	//ajouter(&myHeap, 4);
	//ajouter(&myHeap, 45);
	//printf("min: %d\n", extraireMin(&myHeap));
	//printf("min: %d\n", extraireMin(&myHeap));
	//printf("min: %d\n", extraireMin(&myHeap));

	//free(myHeap.elements);
	triParTas(n, T);
	affichage(T,n);

	return 0;
}
