#include <mpi.h>
#include <iostream>
#include <cstring> // Inclui o cabeçalho necessário para strcpy
#include <string>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char message[20]; // Aumenta o tamanho para evitar overflow

    if (rank == 0) {
        strcpy(message, "Olá mundo");
        MPI_Send(message, 20, MPI_CHAR, rank + 1, 0, MPI_COMM_WORLD);
    } else {
        MPI_Recv(message, 20, MPI_CHAR, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Processo " << rank << " recebeu: " << message << std::endl;
        if (rank < size - 1) {
            MPI_Send(message, 20, MPI_CHAR, rank + 1, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
