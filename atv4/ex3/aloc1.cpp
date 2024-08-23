#include <iostream>
#include <chrono>

int main() {
    int N = 1000;  // Define o tamanho da matriz como N x N

    // Alocação dinâmica de memória para uma matriz N x N.
    int** matriz = new int*[N];
    for (int i = 0; i < N; ++i) {
        matriz[i] = new int[N];
    }

    // Preenchendo a matriz com valores e calculando a soma dos elementos
    auto start = std::chrono::high_resolution_clock::now();
    long long soma = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = i + j;  // Exemplo de preenchimento
            soma += matriz[i][j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Soma dos elementos: " << soma << std::endl;
    std::cout << "Tempo de execução (alocação dinâmica): " << elapsed.count() << " segundos" << std::endl;

    // Liberação da memória alocada dinamicamente
    for (int i = 0; i < N; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
