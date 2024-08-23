#include <iostream>
#include <vector>

// Classe Vector para manipulação de vetores
class Vector {
public:
    // Construtor que inicializa um vetor de tamanho 'tamanho'
    Vector(int tamanho) : tam(tamanho), capacidade(tamanho) {
        dados = new int[tamanho];
    }

    // Destrutor para liberar a memória alocada
    ~Vector() {
        delete[] dados;
    }

    // Inicializa o vetor com um valor específico
    void inicializa(int valor) {
        for (int i = 0; i < tam; ++i) {
            dados[i] = valor;
        }
    }

    // Obtém o valor no índice especificado
    int get(int index) const {
        return dados[index];
    }

    // Define o valor no índice especificado
    void set(int index, int valor) {
        dados[index] = valor;
    }

    // Insere um valor no índice especificado
    void inserir(int index, int valor) {
        if (index < 0 || index >= tam) {
            std::cerr << "Índice fora dos limites!" << std::endl;
            return;
        }
        dados[index] = valor;
    }

    // Remove o valor no índice especificado (por simplicidade, não altera o tamanho)
    void remover(int index) {
        if (index < 0 || index >= tam) {
            std::cerr << "Índice fora dos limites!" << std::endl;
            return;
        }
        dados[index] = 0;  // Apenas define como zero para simular remoção
    }

    // Imprime os valores do vetor
    void imprime() const {
        for (int i = 0; i < tam; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }

    // Método para multiplicar todos os valores por um escalar
    void multiplicarPorEscalar(int escalar) {
        for (int i = 0; i < tam; ++i) {
            dados[i] *= escalar;
        }
    }

private:
    int* dados;     // Ponteiro para os dados do vetor
    int tam;        // Tamanho do vetor
    int capacidade; // Capacidade do vetor
};

int main() {
    int tamanho = 5; // Tamanho do vetor
    Vector vec(tamanho); // Cria um vetor de tamanho 5

    vec.inicializa(1); // Inicializa todos os elementos com o valor 1
    std::cout << "Vetor inicial: ";
    vec.imprime();

    vec.multiplicarPorEscalar(3); // Multiplica todos os valores por 3
    std::cout << "Vetor após multiplicação por 3: ";
    vec.imprime();

    vec.set(2, 10); // Define o valor no índice 2 como 10
    std::cout << "Vetor após definir o valor no índice 2 como 10: ";
    vec.imprime();

    vec.remover(1); // Remove o valor no índice 1 (define como 0)
    std::cout << "Vetor após remoção do valor no índice 1: ";
    vec.imprime();

    return 0;
}
