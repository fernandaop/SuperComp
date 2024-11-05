#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000 // Tamanho da matriz, altere conforme necessário

void calculaQuadradoMatriz(int **matriz, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] *= matriz[i][j];
        }
    }
}

int main() {
    int **matriz = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matriz[i] = (int*) malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            matriz[i][j] = i + j;
        }
    }

    double inicio = omp_get_wtime();
    calculaQuadradoMatriz(matriz, N);
    double fim = omp_get_wtime();
    
    printf("Tempo de execução com OpenMP: %f segundos\n", fim - inicio);

    for (int i = 0; i < N; i++) free(matriz[i]);
    free(matriz);

    return 0;
}
