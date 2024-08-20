#include <iostream>
#include <vector>
#include <string>

struct Item {
    std::string nome;
    int quantidade;
};

void adicionarItem(std::vector<Item>& estoque) {
    Item item;
    std::cout << "Nome do item: ";
    std::cin >> item.nome;
    std::cout << "Quantidade: ";
    std::cin >> item.quantidade;
    estoque.push_back(item);
}

void removerItem(std::vector<Item>& estoque) {
    std::string nome;
    std::cout << "Nome do item a ser removido: ";
    std::cin >> nome;

    for (auto it = estoque.begin(); it != estoque.end(); ++it) {
        if (it->nome == nome) {
            estoque.erase(it);
            std::cout << "Item removido." << std::endl;
            return;
        }
    }
    std::cout << "Item não encontrado." << std::endl;
}

void visualizarEstoque(const std::vector<Item>& estoque) {
    std::cout << "Estoque atual:" << std::endl;
    for (const auto& item : estoque) {
        std::cout << "Item: " << item.nome << " | Quantidade: " << item.quantidade << std::endl;
    }
}

int main() {
    std::vector<Item> estoque;
    int escolha;

    do {
        std::cout << "1. Adicionar Item\n2. Remover Item\n3. Visualizar Estoque\n4. Sair\nEscolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1: adicionarItem(estoque); break;
            case 2: removerItem(estoque); break;
            case 3: visualizarEstoque(estoque); break;
            case 4: std::cout << "Saindo..." << std::endl; break;
            default: std::cout << "Opção inválida." << std::endl; break;
        }
    } while (escolha != 4);

    return 0;
}
