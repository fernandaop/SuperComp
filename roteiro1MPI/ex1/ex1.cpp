#include <mpi.h>
#include <iostream>
#include <cstring> // Inclui o cabeçalho necessário para strcpy
#include <string>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    char message[10]; // Aumenta o tamanho para evitar overflow

    if (rank == 0) {
        strcpy(message, "Olá");
        MPI_Send(message, 10, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(message, 10, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Processo 0 recebeu: " << message << std::endl;
    } else if (rank == 1) {
        MPI_Recv(message, 10, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Processo 1 recebeu: " << message << std::endl;
        strcpy(message, "Oi");
        MPI_Send(message, 10, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
