#include <mpi.h>
#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int array_size = 100;
    std::vector<int> array(array_size);
    std::vector<int> local_array(array_size / world_size);

    if (world_rank == 0) {
        for (int i = 0; i < array_size; i++) {
            array[i] = rand() % 100;
        }
    }

    MPI_Scatter(array.data(), array_size / world_size, MPI_INT, local_array.data(),
                array_size / world_size, MPI_INT, 0, MPI_COMM_WORLD);

    double local_sum = std::accumulate(local_array.begin(), local_array.end(), 0.0);
    double local_mean = local_sum / local_array.size();

    double global_means[world_size];
    MPI_Gather(&local_mean, 1, MPI_DOUBLE, global_means, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        double global_mean = std::accumulate(global_means, global_means + world_size, 0.0) / world_size;
        std::cout << "Global mean: " << global_mean << std::endl;
    }

    MPI_Finalize();
    return 0;
}
