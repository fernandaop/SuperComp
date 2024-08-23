#include <iostream>
#include <vector>
#include <chrono>

int main() {
    int N = 1000;  // Define o tamanho da matriz como N x N

    // Alocação dinâmica usando std::vector
    auto start = std::chrono::high_resolution_clock::now();
    long long soma = 0;

    std::vector<std::vector<int>> matriz(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = i + j;  // Exemplo de preenchimento
            soma += matriz[i][j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Soma dos elementos: " << soma << std::endl;
    std::cout << "Tempo de execução (std::vector): " << elapsed.count() << " segundos" << std::endl;

    return 0;
}
