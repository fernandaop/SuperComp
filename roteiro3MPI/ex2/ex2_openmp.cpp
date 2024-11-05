#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000 // Tamanho da matriz

void calculaQuadrado(int *submatriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        submatriz[i] *= submatriz[i];
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elementosPorProcesso = N * N / size;
    int *matriz = NULL;
    int *submatriz = (int*) malloc(elementosPorProcesso * sizeof(int));

    if (rank == 0) {
        matriz = (int*) malloc(N * N * sizeof(int));
        for (int i = 0; i < N * N; i++) {
            matriz[i] = i;
        }
    }

    MPI_Scatter(matriz, elementosPorProcesso, MPI_INT, submatriz, elementosPorProcesso, MPI_INT, 0, MPI_COMM_WORLD);
    
    calculaQuadrado(submatriz, elementosPorProcesso);

    MPI_Gather(submatriz, elementosPorProcesso, MPI_INT, matriz, elementosPorProcesso, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Matriz processada.\n");
        free(matriz);
    }

    free(submatriz);
    MPI_Finalize();
    return 0;
}
