#include <mpi.h>
#include <iostream>
#include <cstring> // Para funções de manipulação de strings

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char message[30] = "Mensagem do processo "; // Aumenta o tamanho do array

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            MPI_Send(message, 30, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            MPI_Recv(message, 30, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            std::cout << "Processo 0 recebeu de " << i << ": " << message << std::endl;
        }
    } else {
        MPI_Recv(message, 30, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Processo " << rank << " respondeu ao processo 0." << std::endl;
        MPI_Send(message, 30, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
