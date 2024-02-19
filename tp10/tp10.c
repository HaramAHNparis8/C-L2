#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int s; // sommet
   int e; // etiquette (poids)
} couple_t;

#define MAX_SOMMET 40

typedef struct {
   couple_t liste[MAX_SOMMET][MAX_SOMMET];
   int n; // nombre de sommets
} grapheE_t;

void creerGraphe(grapheE_t* g, FILE* grDesc) {
    int d, a, e;
    fscanf(grDesc, "%d", &g->n); // Lire le nombre de sommets

    // Initialisation du graphe avec -1 (pas d'arête)
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            g->liste[i][j].s = j;
            g->liste[i][j].e = -1;
        }
    }

    // Lecture des arêtes
    while (fscanf(grDesc, "%d->%d:%d", &d, &a, &e) != EOF) {
        g->liste[d][a].e = e;
    }
}
void dijikstra(grapheE_t* g, int depart, couple_t t[MAX_SOMMET]) {
    int dist[MAX_SOMMET], pred[MAX_SOMMET];
    int visites[MAX_SOMMET], count, mindist, nextnode, i, j;

    // Initialisation des distances et prédécesseurs
    for (i = 0; i < g->n; i++) {
        dist[i] = g->liste[depart][i].e;
        pred[i] = depart;
        visites[i] = 0;
    }

    dist[depart] = 0;
    visites[depart] = 1;
    count = 1;

    while (count < g->n - 1) {
        mindist = -1;

        // Prochain noeud à distance minimale
        for (i = 0; i < g->n; i++)
            if (dist[i] != -1 && visites[i] == 0 && (mindist == -1 || dist[i] < mindist)) {
                mindist = dist[i];
                nextnode = i;
            }

        visites[nextnode] = 1;
        for (i = 0; i < g->n; i++)
            if (!visites[i])
                if (mindist != -1 && g->liste[nextnode][i].e != -1 && (dist[i] == -1 || mindist + g->liste[nextnode][i].e < dist[i])) {
                    dist[i] = mindist + g->liste[nextnode][i].e;
                    pred[i] = nextnode;
                }
        count++;
    }

    // Remplir le tableau t avec les distances et prédécesseurs
    for (i = 0; i < g->n; i++) {
        t[i].e = dist[i];
        t[i].s = pred[i];
    }
}
void afficheChemin(int s, couple_t t[MAX_SOMMET]) {
    int chemin[MAX_SOMMET], count = 0, i = s;

    // Remplissage du chemin
    while (t[i].e != 0) { // 0 indique le sommet de départ
        chemin[count++] = i;
        i = t[i].s;
    }
    chemin[count] = i; // Ajouter le sommet de départ

    // Affichage du chemin
    printf("Chemin: ");
    for (i = count; i >= 0; i--)
        printf("%d ", chemin[i]);
    printf("\n");
}
#include <stdio.h>

int main() {
    FILE *file = fopen("graphe.txt", "r"); // Remplacer par le nom de votre fichier
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    grapheE_t graphe;
    creerGraphe(&graphe, file);
    fclose(file);

    int sommetDepart = 0; // Choisissez le sommet de départ
    couple_t resultats[MAX_SOMMET];
    dijikstra(&graphe, sommetDepart, resultats);

    printf("Distances depuis le sommet %d:\n", sommetDepart);
    for (int i = 0; i < graphe.n; i++) {
        printf("Sommet %d: Distance = %d, Prédécesseur = %d\n", i, resultats[i].e, resultats[i].s);
    }

    printf("\nChemins les plus courts depuis le sommet %d:\n", sommetDepart);
    for (int i = 0; i < graphe.n; i++) {
        printf("Chemin vers le sommet %d: ", i);
        afficheChemin(i, resultats);
    }

    return 0;
}

