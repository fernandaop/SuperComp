#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000

double calculaSoma(int *array, int tamanho) {
    double soma = 0.0;
    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elementosPorProcesso = N / size;
    int *array = NULL;
    int *subarray = (int*) malloc(elementosPorProcesso * sizeof(int));

    if (rank == 0) {
        array = (int*) malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            array[i] = 1;  // Inicializando com 1 para simplificar a média
        }
    }

    MPI_Scatter(array, elementosPorProcesso, MPI_INT, subarray, elementosPorProcesso, MPI_INT, 0, MPI_COMM_WORLD);

    double somaParcial = calculaSoma(subarray, elementosPorProcesso);
    double somaTotal = 0.0;

    MPI_Reduce(&somaParcial, &somaTotal, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Média: %f\n", somaTotal / N);
        free(array);
    }

    free(subarray);
    MPI_Finalize();
    return 0;
}
