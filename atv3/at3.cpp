#include <iostream>

int main() {
    int num;
    std::cout << "Insira um número: ";
    std::cin >> num;

    if (num % 2 == 0)
        std::cout << num << " é par." << std::endl;
    else
        std::cout << num << " é ímpar." << std::endl;

    return 0;
}
