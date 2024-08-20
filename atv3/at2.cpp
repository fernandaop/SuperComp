#include <iostream>

int main() {
    double num1, num2;
    char op;

    std::cout << "Insira o primeiro número: ";
    std::cin >> num1;

    std::cout << "Insira a operação (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Insira o segundo número: ";
    std::cin >> num2;

    double resultado;

    switch(op) {
        case '+': resultado = num1 + num2; break;
        case '-': resultado = num1 - num2; break;
        case '*': resultado = num1 * num2; break;
        case '/': 
            if (num2 != 0) resultado = num1 / num2; 
            else std::cout << "Erro: divisão por zero!" << std::endl; return 1;
            break;
        default: 
            std::cout << "Operação inválida!" << std::endl; return 1;
    }

    std::cout << "Resultado: " << resultado << std::endl;
    return 0;
}
