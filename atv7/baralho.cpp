#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

// Estrutura para armazenar informações dos itens
struct Item {
    int peso;
    int valor;
};

// Função para ler os dados de um arquivo
bool lerArquivo(const std::string& nomeArquivo, std::vector<Item>& itens, int& capacidade) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    int N;
    arquivo >> N >> capacidade;
    itens.resize(N);

    for (int i = 0; i < N; ++i) {
        arquivo >> itens[i].peso >> itens[i].valor;
    }

    arquivo.close();
    return true;
}

// Função para embaralhar o vetor de itens
void embaralharItens(std::vector<Item>& itens) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(itens.begin(), itens.end(), g);
}

// Função gulosa para preencher a mochila
int mochilaGulosa(const std::vector<Item>& itens, int capacidade) {
    int valorTotal = 0;
    int pesoAtual = 0;

    for (const auto& item : itens) {
        if (pesoAtual + item.peso <= capacidade) {
            pesoAtual += item.peso;
            valorTotal += item.valor;
        }
    }

    return valorTotal;
}

// Função recursiva para busca exaustiva
int mochilaExaustiva(const std::vector<Item>& itens, int capacidade, int idx) {
    if (idx >= itens.size()) return 0;

    // Não incluir o item atual
    int valorSemIncluir = mochilaExaustiva(itens, capacidade, idx + 1);

    // Incluir o item atual, se couber
    int valorComIncluir = 0;
    if (itens[idx].peso <= capacidade) {
        valorComIncluir = itens[idx].valor + mochilaExaustiva(itens, capacidade - itens[idx].peso, idx + 1);
    }

    return std::max(valorSemIncluir, valorComIncluir);
}

int main() {
    std::string arquivos[] = {"entrada_3.txt", "entrada_4.txt"};

    for (const std::string& nomeArquivo : arquivos) {
        std::vector<Item> itens;
        int capacidade;

        if (!lerArquivo(nomeArquivo, itens, capacidade)) {
            continue;
        }

        std::cout << "Processando o arquivo: " << nomeArquivo << std::endl;

        // Heurística gulosa
        auto startGuloso = std::chrono::high_resolution_clock::now();
        embaralharItens(itens);
        int valorGuloso = mochilaGulosa(itens, capacidade);
        auto endGuloso = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoGuloso = endGuloso - startGuloso;

        // Busca exaustiva
        auto startExaustiva = std::chrono::high_resolution_clock::now();
        int valorExaustiva = mochilaExaustiva(itens, capacidade, 0);
        auto endExaustiva = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoExaustiva = endExaustiva - startExaustiva;

        // Resultados
        std::cout << "Valor obtido pela heurística gulosa: " << valorGuloso << std::endl;
        std::cout << "Tempo de execução da heurística gulosa: " << tempoGuloso.count() << " segundos" << std::endl;

        std::cout << "Valor obtido pela busca exaustiva: " << valorExaustiva << std::endl;
        std::cout << "Tempo de execução da busca exaustiva: " << tempoExaustiva.count() << " segundos" << std::endl;

        std::cout << "----------------------------------" << std::endl;
    }

    return 0;
}
