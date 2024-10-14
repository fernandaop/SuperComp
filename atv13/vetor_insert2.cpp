#include <vector>
#include <iostream>
#include <omp.h>

double conta_complexa(int i) {
    return 2 * i;
}

int main() {
    int N = 10000; 
    std::vector<double> vec(N);

    double init_time = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        vec[i] = conta_complexa(i);
    }
    double final_time = omp_get_wtime();

    std::cout << "Tempo de execução com pré-alocação: " << final_time - init_time << " segundos" << std::endl;
    return 0;
}
