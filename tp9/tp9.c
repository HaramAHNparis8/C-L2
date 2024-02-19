#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SOMMET 40

#define INFINITE -1
//exo 1
void processGraph(const char* filename, int startVertex);


typedef struct {
    int liste[MAX_SOMMET][MAX_SOMMET];
    int n; // nombre de sommets
} graphe_t;

void creerGraphe(graphe_t* g, FILE* grDesc) {
    int d, a;
    fscanf(grDesc, "%d", &(g->n)); // Lire le nombre de sommets

    // Initialiser la matrice d'adjacence
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            g->liste[i][j] = 0;
        }
    }

    // Lire les arêtes et mettre à jour la matrice d'adjacence
    while (fscanf(grDesc, "%d->%d", &d, &a) == 2) {
        if (d < g->n && a < g->n) {
            g->liste[d][a] = 1;
        }
    }
}


void affichage(graphe_t* g,FILE* grDesc){

	creerGraphe(g, grDesc);
	// Affichage de la matrice d'adjacence pour vérification
	for (int i = 0; i < g -> n; i++) {
		
		for (int j = 0; j < g->n; j++) {

			printf("%d ", g->liste[i][j]);
        }
		printf("\n");
    }


}

//exo2 -> accessible 

void bfs(graphe_t* g, int s, int* acces) {
	int visited[MAX_SOMMET] = {0}; // Visited array
	int queue[MAX_SOMMET];         // Queue for BFS
	int front = 0, rear = 0;

    // Initialize the queue with the start vertex and mark it as visited
     
	queue[rear++] = s;
	visited[s] = 1;
	while (front < rear) {
		int current = queue[front++];

		for (int i = 0; i < g->n; i++) {
			if (g->liste[current][i] && !visited[i]) {
				queue[rear++] = i;
				visited[i] = 1;
				acces[i] = 1; // Mark as accessible
            }
        }
    }
}

void accessible(graphe_t* g, int s, int* acces) {
	for (int i = 0; i < g->n; i++) {

		acces[i] = 0; // Initialize all vertices as not accessible
    }
	bfs(g, s, acces); // Perform BFS to find accessible vertices
}
void affichage_exo2(int* acces, int n) {
	
	for (int i = 0; i < n; i++) {
		
		printf("%d ", acces[i]);
	}

	printf("\n");
}


int dfs(graphe_t* g, int v, int visited[], int recStack[]) {
    if(!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for(int i = 0; i < g->n; i++) {
            if(g->liste[v][i]) {
                if(!visited[i] && dfs(g, i, visited, recStack))
                    return 1;
                else if(recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0; // remove the vertex from recursion stack
    return 0;
}

int sansCircuit(graphe_t* g) {
    int visited[MAX_SOMMET] = {0};
    int recStack[MAX_SOMMET] = {0};

    for(int i = 0; i < g->n; i++) {
        if(dfs(g, i, visited, recStack))
            return 0; // cycle found
    }
    return 1; // no cycle
}

void verifierCircuit(graphe_t* g) {
    int hasCycle = sansCircuit(g);
    if (hasCycle) {
        printf("Le graphe ne contient pas de circuit.\n");
    } else {
        printf("Le graphe contient un circuit.\n");
    }
}


int dfsForet(graphe_t* g, int v, int visited[], int parent) {
    visited[v] = 1;
    for (int i = 0; i < g->n; i++) {
        if (g->liste[v][i]) {
            if (!visited[i]) {
                if (!dfsForet(g, i, visited, v)) {
                    return 0; 
                }
            } else if (i != parent) {
                
                return 0;
            }
        }
    }
    return 1;
}


int estForet(graphe_t* g) {
    int visited[MAX_SOMMET] = {0};

    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
        
            if (!dfsForet(g, i, visited, -1)) {
                return 0;
            }
        }
    }
    return 1; 
}


void verifierForet(graphe_t* g) {
    int isForest = estForet(g);
    if (isForest) {
        printf("Le graphe est une forêt.\n");
    } else {
        printf("Le graphe n'est pas une forêt.\n");
    }
}
void distance(graphe_t* g, int s, int* dist) {
    int visited[MAX_SOMMET] = {0}; // Array to track visited vertices
    int queue[MAX_SOMMET];         // Queue for BFS
    int front = 0, rear = 0;

    // Initialize distances as infinite (or -1 to indicate not reachable)
    for (int i = 0; i < g->n; i++) {
        dist[i] = INFINITE;
    }

    // Start with the source vertex
    queue[rear++] = s;
    visited[s] = 1;
    dist[s] = 0; // Distance to itself is 0

    // BFS
    while (front < rear) {
        int current = queue[front++];

        for (int i = 0; i < g->n; i++) {
            
		if (g->liste[current][i] && !visited[i]) {
                queue[rear++] = i;                   
		visited[i] = 1;       
                dist[i] = dist[current] + 1; 
            }
        }
    }
}

void dfsTopo(Graphe* g, int v, int visited[], int* stack, int* index) {
    visited[v] = 1;
    for (int i = 0; i < g->n; i++) {
        if (g->liste[v][i] && !visited[i]) {
            dfsTopo(g, i, visited, stack, index);
        }
    }
    stack[(*index)++] = v;
}

void triTopo(Graphe* g, int* tab) {
    int visited[MAX_SOMMET] = {0};
    int stack[MAX_SOMMET], index = 0;

    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            dfsTopo(g, i, visited, stack, &index);
        }
    }
    for (int i = 0; i < g->n; i++) {
        tab[i] = stack[g->n - i - 1];
    }
}


void fillOrder(Graphe* g, int v, int visited[], int* stack, int* index) {
    visited[v] = 1;
    for (int i = 0; i < g->n; i++) {
        if (g->liste[v][i] && !visited[i]) {
            fillOrder(g, i, visited, stack, index);
        }
    }
    stack[(*index)++] = v;
}

void dfs(Graphe* g, int v, int visited[]) {
    visited[v] = 1;
    for (int i = 0; i < g->n; i++) {
        if (g->liste[v][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

void memeCompos(Graphe* g, int s, int* tabl) {

    for (int i = 0; i < g->n; i++) {
        tabl[i] = 0;
    }

    int visited[MAX_SOMMET] = {0};
    dfs(g, s, visited);

    for (int i = 0; i < g->n; i++) {
        if (visited[i]) {
            int reverseVisited[MAX_SOMMET] = {0};
            dfs(g, i, reverseVisited);
            if (reverseVisited[s]) {
                tabl[i] = 1;
            }
        }
    }
}
void dfsTopo(Graphe* g, int v, int visited[], int* stack, int* index) {
    visited[v] = 1;
    for (int i = 0; i < g->n; i++) {
        if (g->liste[v][i] && !visited[i]) {
            dfsTopo(g, i, visited, stack, index);
        }
    }
    stack[(*index)++] = v;
}

void triTopo(Graphe* g, int* tab) {
    int visited[MAX_SOMMET] = {0};
    int stack[MAX_SOMMET], index = 0;

    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            dfsTopo(g, i, visited, stack, &index);
        }
    }

    // Reverse the stack to get topological ordering
    for (int i = 0; i < g->n; i++) {
        tab[i] = stack[g->n - i - 1];
    }
}


int main(void) {
	   //graphe_t g;
	   //int acces[MAX_SOMMET];
	   //FILE* grDesc = fopen("graph.txt", "r");
	   const char* filename = "graph.txt";
	   int startVertex = 0;
	   processGraph(filename, startVertex);

	   //if (grDesc == NULL) {
		   //printf("Erreur lors de l'ouverture du fichier.\n");
		   //return 1;
    //}
	   //affichage(&g, grDesc);  
	    
	   //creerGraphe(&g, grDesc);
	   //fclose(grDesc);
	   //verifierForet(&g);
	   //accessible(&g, 2, acces);
	   //verifierCircuit(&g);
	   //affichage_exo2(acces, g.n);

	   
        return 0;
}
void processGraph(const char* filename, int startVertex) {
    graphe_t g;
    int dist[MAX_SOMMET];

    FILE* grDesc = fopen(filename, "r");
    if (grDesc == NULL) {
        printf("c'est pas possible d'ouvrier %s\n", filename);
        return;
    }

    creerGraphe(&g, grDesc);
    fclose(grDesc);

    distance(&g, startVertex, dist);

    printf("la distance de sommet%d:\n", startVertex);
    for (int i = 0; i < g.n; i++) {
        if (dist[i] == -1) {
            printf("sommet %d: accese impossible\n", i);
        } else {
            printf("sommet %d: %d\n", i, dist[i]);
        }
    }
}
