#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int num_iterations = 1000;

    if (world_rank == 0) {
        num_iterations = 5000; // Configuração no processo raiz
    }

    MPI_Bcast(&num_iterations, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Simulação do cálculo
    for (int i = 0; i < num_iterations; i++) {}

    std::cout << "Processo " << world_rank << " completou " << num_iterations << " iterações." << std::endl;

    MPI_Finalize();
    return 0;
}
