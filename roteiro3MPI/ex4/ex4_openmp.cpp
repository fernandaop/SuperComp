#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define VALOR_BUSCA 5

void buscaValor(int *array, int tamanho, int valor, int *posicoes, int *contador) {
    #pragma omp parallel for
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            int idx = __sync_fetch_and_add(contador, 1);
            posicoes[idx] = i;
        }
    }
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
            array[i] = rand() % 10;  // Inicializando com valores aleatórios de 0 a 9
        }
    }

    MPI_Scatter(array, elementosPorProcesso, MPI_INT, subarray, elementosPorProcesso, MPI_INT, 0, MPI_COMM_WORLD);

    int *posicoesLocais = (int*) malloc(elementosPorProcesso * sizeof(int));
    int contador = 0;

    buscaValor(subarray, elementosPorProcesso, VALOR_BUSCA, posicoesLocais, &contador);

    int totalContador;
    MPI_Reduce(&contador, &totalContador, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total de ocorrências de %d: %d\n", VALOR_BUSCA, totalContador);
        free(array);
    }

    free(subarray);
    free(posicoesLocais);
    MPI_Finalize();
    return 0;
}
