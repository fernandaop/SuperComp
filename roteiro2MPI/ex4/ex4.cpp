#include <mpi.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

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

    double local_mean = std::accumulate(local_array.begin(), local_array.end(), 0.0) / local_array.size();
    double local_variance = 0.0;
    for (const auto& val : local_array) {
        local_variance += (val - local_mean) * (val - local_mean);
    }
    local_variance /= local_array.size();

    std::vector<double> global_means(world_size), global_variances(world_size);
    MPI_Gather(&local_mean, 1, MPI_DOUBLE, global_means.data(), 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Gather(&local_variance, 1, MPI_DOUBLE, global_variances.data(), 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        double global_mean = std::accumulate(global_means.begin(), global_means.end(), 0.0) / world_size;
        double global_variance = std::accumulate(global_variances.begin(), global_variances.end(), 0.0) / world_size;
        double stddev = sqrt(global_variance);
        std::cout << "Desvio padrão global: " << stddev << std::endl;
    }

    MPI_Finalize();
    return 0;
}
