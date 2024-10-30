#include <mpi.h>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            std::ostringstream msg;
            msg << "Mensagem para o processo " << i;
            MPI_Send(msg.str().c_str(), msg.str().size() + 1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }
    } else {
        char message[50];
        MPI_Recv(message, 50, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Processo " << rank << " recebeu: " << message << std::endl;
    }

    MPI_Finalize();
    return 0;
}
