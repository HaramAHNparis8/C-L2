#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int sum = 0,num;
    	if (argc != 2) {
        	printf("Utilisation : %s <fichier>\n", argv[0]);
        	return 1;
    	}

    	FILE *file = fopen(argv[1], "r");

    	if (file == NULL) {
        	printf("Impossible d'ouvrir le fichier.\n");
        	return 1;
    }

    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
    }

    fclose(file);

    printf("La somme des nombres dans le fichier '%s' est : %d\n", argv[1], sum);

    return 0;
}

