#include <iostream>

int main() {
    int vetor[10];

    std::cout << "Insira 10 números:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cin >> vetor[i];
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (vetor[j] > vetor[j + 1]) {
                std::swap(vetor[j], vetor[j + 1]);
            }
        }
    }

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
