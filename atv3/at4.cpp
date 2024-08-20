#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Insira uma string: ";
    std::getline(std::cin, str);

    std::cout << "Número de caracteres: " << str.length() << std::endl;
    return 0;
}
