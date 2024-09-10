#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int peso;
    int valor;

    Item(int p, int v) : peso(p), valor(v) {}
};

int mochila(int capacidade, const std::vector<Item>& itens) {
    int peso_total = 0;
    int valor_total = 0;

    for (const auto& item : itens) {
        if (peso_total + item.peso <= capacidade) {
            peso_total += item.peso;
            valor_total += item.valor;
        }
    }

    return valor_total;
}

bool compara_valor(const Item& a, const Item& b) {
    return a.valor > b.valor;
}

int mais_caro_primeiro(int capacidade, std::vector<Item>& itens) {
    std::sort(itens.begin(), itens.end(), compara_valor);
    return mochila(capacidade, itens);
}

bool compara_peso(const Item& a, const Item& b) {
    return a.peso < b.peso;
}

int mais_leve_primeiro(int capacidade, std::vector<Item>& itens) {
    std::sort(itens.begin(), itens.end(), compara_peso);
    return mochila(capacidade, itens);
}

void aplicar_heuristicas(int capacidade, std::vector<Item> itens) {
    std::vector<Item> itens_copia = itens;

    int resultado_caro = mais_caro_primeiro(capacidade, itens);
    std::cout << "Valor total (mais caro primeiro): " << resultado_caro << std::endl;

    int resultado_leve = mais_leve_primeiro(capacidade, itens_copia);
    std::cout << "Valor total (mais leve primeiro): " << resultado_leve << std::endl;
}

int main() {
    std::cout << "Cenário 1: Mais valioso primeiro muito melhor que mais leve primeiro\n";
    int capacidade_1 = 10;
    std::vector<Item> itens_1 = {
        {9, 100}, {8, 90}, {1, 1}, {2, 5}, {3, 10}
    };
    aplicar_heuristicas(capacidade_1, itens_1);

    std::cout << "\n";

    std::cout << "Cenário 2: Mais leve primeiro muito melhor que mais valioso primeiro\n";
    int capacidade_2 = 10;
    std::vector<Item> itens_2 = {
        {7, 20}, {6, 19}, {1, 50}, {1, 40}, {2, 45}
    };
    aplicar_heuristicas(capacidade_2, itens_2);

    return 0;
}
