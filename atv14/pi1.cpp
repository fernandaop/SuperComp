#include <iostream>
#include <random>
#include <cmath>
#include <omp.h>

int main() {
    const int N = 100000;
    int pontosDentro = 0;

    double start = omp_get_wtime();

    #pragma omp parallel reduction(+:pontosDentro)
    {
        // Criar um gerador de números aleatórios para cada thread
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            double x = dis(gen);
            double y = dis(gen);

            if (x * x + y * y <= 1) {
                ++pontosDentro;
            }
        }
    }

    double pi = 4.0 * pontosDentro / N;
    double tempoExecucao = omp_get_wtime() - start;

    std::cout << "Valor estimado de pi (paralelizado com gerador próprio): " << pi << std::endl;
    std::cout << "Tempo de execução (paralelizado com gerador próprio): " << tempoExecucao << " segundos" << std::endl;

    return 0;
}
