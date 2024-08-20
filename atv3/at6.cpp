#include <iostream>

int main() {
    int vetor[10];
    std::cout << "Insira 10 números:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> vetor[i];
    }

    int maior = vetor[0];
    for (int i = 1; i < 10; ++i) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    std::cout << "Maior número: " << maior << std::endl;
    return 0;
}
