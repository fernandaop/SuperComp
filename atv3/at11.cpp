#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() {
    std::ifstream arquivoEntrada("entrada.txt");
    std::ofstream arquivoSaida("estatisticas.txt");

    if (!arquivoEntrada) {
        std::cerr << "Erro ao abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    std::string linha;
    int totalPalavras = 0, totalLinhas = 0;
    std::map<std::string, int> frequenciaPalavras;

    while (std::getline(arquivoEntrada, linha)) {
        std::stringstream ss(linha);
        std::string palavra;
        while (ss >> palavra) {
            ++frequenciaPalavras[palavra];
            ++totalPalavras;
        }
        ++totalLinhas;
    }

    std::string palavraMaisFrequente;
    int maxFrequencia = 0;
    for (const auto& par : frequenciaPalavras) {
        if (par.second > maxFrequencia) {
            maxFrequencia = par.second;
            palavraMaisFrequente = par.first;
        }
    }

    double mediaPalavrasPorLinha = totalLinhas > 0 ? static_cast<double>(totalPalavras) / totalLinhas : 0;

    arquivoSaida << "Número total de palavras: " << totalPalavras << std::endl;
    arquivoSaida << "Número total de linhas: " << totalLinhas << std::endl;
    arquivoSaida << "Número médio de palavras por linha: " << mediaPalavrasPorLinha << std::endl;
    arquivoSaida << "Palavra mais frequente: " << palavraMaisFrequente << " (" << maxFrequencia << " vezes)" << std::endl;

    arquivoEntrada.close();
    arquivoSaida.close();

    std::cout << "Estatísticas calculadas e salvas em 'estatisticas.txt'." << std::endl;

    return 0;
}
