#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Estrutura para representar um item
struct Item {
    int peso;
    int valor;
};

// Função para calcular o valor total e o peso da mochila
int calcularValor(const std::vector<Item>& itens, const std::vector<bool>& mochila) {
    int valorTotal = 0;
    for (size_t i = 0; i < itens.size(); ++i) {
        if (mochila[i]) {
            valorTotal += itens[i].valor;
        }
    }
    return valorTotal;
}

int calcularPeso(const std::vector<Item>& itens, const std::vector<bool>& mochila) {
    int pesoTotal = 0;
    for (size_t i = 0; i < itens.size(); ++i) {
        if (mochila[i]) {
            pesoTotal += itens[i].peso;
        }
    }
    return pesoTotal;
}

// Função para gerar uma solução aleatória
std::vector<bool> gerarSolucaoAleatoria(size_t numItens) {
    std::vector<bool> solucao(numItens);
    for (size_t i = 0; i < numItens; ++i) {
        solucao[i] = rand() % 2; // 0 ou 1 aleatoriamente
    }
    return solucao;
}

// Função para realizar a substituição de objetos
std::vector<bool> substituirObjetos(const std::vector<Item>& itens, int capacidade) {
    size_t numItens = itens.size();
    std::vector<bool> mochila = gerarSolucaoAleatoria(numItens);

    bool melhorou;
    do {
        melhorou = false;
        int valorAtual = calcularValor(itens, mochila);
        int pesoAtual = calcularPeso(itens, mochila);

        for (size_t i = 0; i < numItens; ++i) {
            if (!mochila[i]) { // Verificar se o item i não está na mochila
                // Tentar incluir o item i e verificar se melhora a solução
                mochila[i] = true;
                int pesoNovo = calcularPeso(itens, mochila);

                if (pesoNovo <= capacidade) {
                    int valorNovo = calcularValor(itens, mochila);
                    if (valorNovo > valorAtual) {
                        valorAtual = valorNovo;
                        melhorou = true;
                    } else {
                        mochila[i] = false; // Reverter se não houver melhora
                    }
                } else {
                    mochila[i] = false; // Reverter se exceder a capacidade
                }
            }
        }
    } while (melhorou);

    return mochila;
}

// Função para ler os dados de um arquivo
bool lerDadosArquivo(const std::string& nomeArquivo, std::vector<Item>& itens, int& capacidade) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    std::string linha;
    std::getline(arquivo, linha);
    std::istringstream iss(linha);
    int numItens;
    iss >> numItens >> capacidade;

    itens.resize(numItens);
    for (int i = 0; i < numItens; ++i) {
        std::getline(arquivo, linha);
        iss.clear();
        iss.str(linha);
        iss >> itens[i].peso >> itens[i].valor;
    }

    arquivo.close();
    return true;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Inicializar o gerador de números aleatórios

    // Arquivos de entrada
    std::string arquivosEntrada[] = {"entrada1.txt", "entrada2.txt", "entrada3.txt", "entrada4.txt"};

    for (const std::string& nomeArquivo : arquivosEntrada) {
        std::vector<Item> itens;
        int capacidade;

        if (lerDadosArquivo(nomeArquivo, itens, capacidade)) {
            // Encontrar a solução usando a estratégia de substituição de objetos
            std::vector<bool> melhorMochila = substituirObjetos(itens, capacidade);

            // Imprimir a solução
            int valorTotal = calcularValor(itens, melhorMochila);
            int pesoTotal = calcularPeso(itens, melhorMochila);

            std::cout << "Solução para o arquivo " << nomeArquivo << ":\n";
            for (size_t i = 0; i < melhorMochila.size(); ++i) {
                if (melhorMochila[i]) {
                    std::cout << "Item " << i << " (Peso: " << itens[i].peso << ", Valor: " << itens[i].valor << ")\n";
                }
            }
            std::cout << "Valor Total: " << valorTotal << "\n";
            std::cout << "Peso Total: " << pesoTotal << "\n\n";
        }
    }

    return 0;
}
