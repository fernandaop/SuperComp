#include <mpi.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int array_size = 100;
    std::vector<int> array(array_size);
    std::vector<int> local_array(array_size / world_size);

    int max_value;

    if (world_rank == 0) {
        for (int i = 0; i < array_size; i++) {
            array[i] = rand() % 100;
        }
        max_value = *std::max_element(array.begin(), array.end());
    }

    MPI_Bcast(&max_value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(array.data(), array_size / world_size, MPI_INT, local_array.data(),
                array_size / world_size, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < local_array.size(); i++) {
        local_array[i] = static_cast<double>(local_array[i]) / max_value;
    }

    MPI_Gather(local_array.data(), array_size / world_size, MPI_DOUBLE, array.data(),
               array_size / world_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        std::cout << "Array normalizado: ";
        for (const auto &val : array) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    MPI_Finalize();
    return 0;
}
