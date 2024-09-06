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

// Função para calcular o valor total da mochila e verificar se o peso está dentro da capacidade
int calcularValor(const std::vector<Item>& itens, const std::vector<bool>& solucao, int capacidade) {
    int valorTotal = 0;
    int pesoAtual = 0;

    for (size_t i = 0; i < itens.size(); ++i) {
        if (solucao[i]) {
            if (pesoAtual + itens[i].peso <= capacidade) {
                pesoAtual += itens[i].peso;
                valorTotal += itens[i].valor;
            } else {
                return -1; // Solução inválida
            }
        }
    }

    return valorTotal;
}

// Função para gerar uma solução aleatória
std::vector<bool> gerarSolucaoAleatoria(size_t tamanho) {
    std::vector<bool> solucao(tamanho);
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    for (size_t i = 0; i < tamanho; ++i) {
        solucao[i] = distrib(g);
    }

    return solucao;
}

// Algoritmo Mochila Cheia
std::vector<bool> mochilaCheia(const std::vector<Item>& itens, int capacidade) {
    size_t n = itens.size();
    std::vector<bool> melhorSolucao(n, false);
    int melhorValor = 0;

    for (int i = 0; i < 1000; ++i) { // Número de iterações
        auto solucao = gerarSolucaoAleatoria(n);
        int valorAtual = calcularValor(itens, solucao, capacidade);
        if (valorAtual > melhorValor) {
            melhorValor = valorAtual;
            melhorSolucao = solucao;
        }
    }

    return melhorSolucao;
}

// Função para aplicar a Substituição de Objeto
std::vector<bool> substituicaoObjeto(const std::vector<Item>& itens, int capacidade) {
    std::vector<bool> solucao = mochilaCheia(itens, capacidade);
    size_t n = itens.size();
    bool melhorou;

    do {
        melhorou = false;
        for (size_t i = 0; i < n; ++i) {
            if (solucao[i]) { // Tenta remover o item i
                auto novaSolucao = solucao;
                novaSolucao[i] = false;
                for (size_t j = 0; j < n; ++j) {
                    if (!solucao[j]) { // Tenta adicionar o item j
                        novaSolucao[j] = true;
                        int valorAtual = calcularValor(itens, novaSolucao, capacidade);
                        if (valorAtual > calcularValor(itens, solucao, capacidade)) {
                            solucao = novaSolucao;
                            melhorou = true;
                            break;
                        }
                        novaSolucao[j] = false; // Remove o item j se não melhorou
                    }
                }
                if (melhorou) break; // Se houve melhoria, reinicia a verificação
            }
        }
    } while (melhorou);

    return solucao;
}

// Função para aplicar Hill Climbing
std::vector<bool> hillClimbing(const std::vector<Item>& itens, int capacidade) {
    size_t n = itens.size();
    auto solucao = mochilaCheia(itens, capacidade);
    int melhorValor = calcularValor(itens, solucao, capacidade);
    bool melhorou;

    do {
        melhorou = false;
        for (size_t i = 0; i < n; ++i) {
            std::vector<bool> vizinho = solucao;
            vizinho[i] = !vizinho[i]; // Inverte o bit i

            int valorVizinho = calcularValor(itens, vizinho, capacidade);
            if (valorVizinho > melhorValor) {
                solucao = vizinho;
                melhorValor = valorVizinho;
                melhorou = true;
            }
        }
    } while (melhorou);

    return solucao;
}

int main() {
    std::string arquivos[] = {"entrada_1.txt", "entrada_2.txt", "entrada_3.txt"};

    for (const std::string& nomeArquivo : arquivos) {
        std::vector<Item> itens;
        int capacidade;

        if (!lerArquivo(nomeArquivo, itens, capacidade)) {
            continue;
        }

        std::cout << "Processando o arquivo: " << nomeArquivo << std::endl;

        // Executando a Mochila Cheia
        auto startCheia = std::chrono::high_resolution_clock::now();
        auto solucaoCheia = mochilaCheia(itens, capacidade);
        int valorCheia = calcularValor(itens, solucaoCheia, capacidade);
        auto endCheia = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoCheia = endCheia - startCheia;

        std::cout << "Mochila Cheia:" << std::endl;
        std::cout << "Valor obtido: " << valorCheia << std::endl;
        std::cout << "Tempo de execução: " << tempoCheia.count() << " segundos" << std::endl;

        // Executando a Substituição de Objeto
        auto startSubstituicao = std::chrono::high_resolution_clock::now();
        auto solucaoSubstituicao = substituicaoObjeto(itens, capacidade);
        int valorSubstituicao = calcularValor(itens, solucaoSubstituicao, capacidade);
        auto endSubstituicao = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoSubstituicao = endSubstituicao - startSubstituicao;

        std::cout << "Substituição de Objeto:" << std::endl;
        std::cout << "Valor obtido: " << valorSubstituicao << std::endl;
        std::cout << "Tempo de execução: " << tempoSubstituicao.count() << " segundos" << std::endl;

        // Executando o Hill Climbing
        auto startHillClimbing = std::chrono::high_resolution_clock::now();
        auto solucaoHillClimbing = hillClimbing(itens, capacidade);
        int valorHillClimbing = calcularValor(itens, solucaoHillClimbing, capacidade);
        auto endHillClimbing = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tempoHillClimbing = endHillClimbing - startHillClimbing;

        std::cout << "Hill Climbing:" << std::endl;
        std::cout << "Valor obtido: " << valorHillClimbing << std::endl;
        std::cout << "Tempo de execução: " << tempoHillClimbing.count() << " segundos" << std::endl;

        std::cout << "----------------------------------" << std::endl;
    }

    return 0;
}
