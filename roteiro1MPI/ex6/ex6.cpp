#include <mpi.h>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char message[20] = "Mensagem do processo ";

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            MPI_Send(message, 20, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            MPI_Recv(message, 20, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            std::cout << "Processo 0 recebeu de " << i << ": " << message << std::endl;
        }
    } else {
        MPI_Recv(message, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(message, 20, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        std::cout << "Processo " << rank << " respondeu ao processo 0." << std::endl;
    }

    MPI_Finalize();
    return 0;
}
