#include <stdio.h>
#include <time.h>

int main() {
    int n = 1000; 
    double total_time = 0.0;
    double total_iterations = 0;

    while (1) {
        clock_t start_time = clock();

        for (int i = 0; i < n; i++) {
            
        }

        clock_t end_time = clock();
        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        double iterations_per_ms = (double)n / (elapsed_time * 1000);

        total_time += elapsed_time;
        total_iterations += n;

        printf("operations: %d, temps_passe  : %.6f ms, op/ms: %.6f\n", n, elapsed_time, iterations_per_ms);

        n = (int)(n * 1.1);
    }

    return 0;
}

