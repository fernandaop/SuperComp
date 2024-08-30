#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // Para medir o tempo de execução
using namespace std;

// Estrutura para armazenar peso e valor de cada item
struct Item {
    int peso;
    int valor;
};

// Função recursiva para calcular o valor máximo da mochila
int mochilaRecursiva(int capacidade, vector<Item>& itens, int n) {
    if (n == 0 || capacidade == 0)
        return 0;

    if (itens[n-1].peso > capacidade)
        return mochilaRecursiva(capacidade, itens, n-1);
    else {
        int incluir = itens[n-1].valor + mochilaRecursiva(capacidade - itens[n-1].peso, itens, n-1);
        int excluir = mochilaRecursiva(capacidade, itens, n-1);
        return max(incluir, excluir);
    }
}

int main() {
    // Medição de tempo para cada entrada
    auto start = chrono::high_resolution_clock::now();

    // Entrada 1
    int capacidade1 = 10;
    vector<Item> itens1 = {{3, 70}, {8, 56}, {6, 17}, {4, 91}, {5, 77}, {10, 69}, {1, 98}, {9, 54}, {3, 13}, {3, 54}};
    auto start1 = chrono::high_resolution_clock::now();
    int valor1 = mochilaRecursiva(capacidade1, itens1, itens1.size());
    auto end1 = chrono::high_resolution_clock::now();
    cout << "Entrada 1 -> Peso ocupado: " << capacidade1 << " Kg, Valor alcançado: " << valor1 << " dinheiros";
    cout << ", Tempo de execução: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << " microssegundos" << endl;

    // Entrada 2
    int capacidade2 = 2;
    vector<Item> itens2 = {{1, 50}, {1, 94}, {2, 40}, {2, 39}, {1, 62}};
    auto start2 = chrono::high_resolution_clock::now();
    int valor2 = mochilaRecursiva(capacidade2, itens2, itens2.size());
    auto end2 = chrono::high_resolution_clock::now();
    cout << "Entrada 2 -> Peso ocupado: " << capacidade2 << " Kg, Valor alcançado: " << valor2 << " dinheiros";
    cout << ", Tempo de execução: " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << " microssegundos" << endl;

    // Entrada 3
    int capacidade3 = 100;
    vector<Item> itens3 = {{58, 95}, {90, 32}, {36, 37}, {53, 54}, {8, 9}, {98, 29}, {31, 43}, {37, 59}, {36, 3}, {6, 98}};
    auto start3 = chrono::high_resolution_clock::now();
    int valor3 = mochilaRecursiva(capacidade3, itens3, itens3.size());
    auto end3 = chrono::high_resolution_clock::now();
    cout << "Entrada 3 -> Peso ocupado: " << capacidade3 << " Kg, Valor alcançado: " << valor3 << " dinheiros";
    cout << ", Tempo de execução: " << chrono::duration_cast<chrono::microseconds>(end3 - start3).count() << " microssegundos" << endl;

    // Entrada 4
    int capacidade4 = 10;
    vector<Item> itens4 = {{1, 5}, {1, 10}, {2, 5}, {1, 20}, {8, 25}};
    auto start4 = chrono::high_resolution_clock::now();
    int valor4 = mochilaRecursiva(capacidade4, itens4, itens4.size());
    auto end4 = chrono::high_resolution_clock::now();
    cout << "Entrada 4 -> Peso ocupado: " << capacidade4 << " Kg, Valor alcançado: " << valor4 << " dinheiros";
    cout << ", Tempo de execução: " << chrono::duration_cast<chrono::microseconds>(end4 - start4).count() << " microssegundos" << endl;

    return 0;
}
