#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int n;   
   int* tab; 
   int tMax;  

} pileI_t;


pileI_t* initialiserPI(void) {
    pileI_t* p = (pileI_t*)malloc(sizeof(pileI_t));
    if (!p) return NULL; 

    p->n = 0;
    p->tMax = 100;
    p->tab = (int*)malloc(p->tMax * sizeof(int));
    if (!p->tab) { 
        free(p);
        return NULL;
    }

    return p;
}


void emPilerI(pileI_t* p, int a) {
    if (p->n == p->tMax) { 
        int newMax = p->tMax + 100;
        int* newTab = (int*)realloc(p->tab, newMax * sizeof(int));
        if (!newTab) return;

        p->tab = newTab;
        p->tMax = newMax;
    }

    p->tab[p->n++] = a;
}


int dePilerI(pileI_t* p) {
    if (p->n == 0) {
        printf("Stack est vide\n");
        return -1; 
    }
    return p->tab[--p->n];
}


int estVidePI(pileI_t* p) {
    return p->n == 0;
}


void detruirePI(pileI_t* p) {
    if (p != NULL) {
        free(p->tab); 
        free(p);      
    }
}

int calcul_postfixe(char* tab) {
    pileI_t* stack = initialiserPI();
    int i = 0, a, b, result;

    while (tab[i] != '\0') {
        if (tab[i] >= '0' && tab[i] <= '9') { 
            emPilerI(stack, tab[i] - '0');
        } else if (tab[i] == '+' || tab[i] == '*') {
            a = dePilerI(stack);
            b = dePilerI(stack);

            if (tab[i] == '+') {
                emPilerI(stack, b + a);
            } else if (tab[i] == '*') {
                emPilerI(stack, b * a);
            }
        }
        i++;
    }

    result = dePilerI(stack);
    detruirePI(stack);
    return result;
}
int main() {
    pileI_t* myStack = initialiserPI();
    if (myStack == NULL) {
        printf("probleme avec stact");
        return 1;
    }
    
    emPilerI(myStack, 10);
    printf("Pop: %d\\n", dePilerI(myStack));

    if (estVidePI(myStack)) {
        printf("stack est vide\\n");
    } else {
        printf("stack est non vide\\n");
    }
    
    detruirePI(myStack);
    char tab[] = "732+*";
    int result = calcul_postfixe(tab);
    printf("Res: %d\n", result);
    return 0;
}

