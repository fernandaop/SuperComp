#include <iostream>
#include <string>

int main() {
    std::string str, strReversa;
    std::cout << "Insira uma string: ";
    std::getline(std::cin, str);

    strReversa = std::string(str.rbegin(), str.rend());

    if (str == strReversa)
        std::cout << "A string é um palíndromo." << std::endl;
    else
        std::cout << "A string não é um palíndromo." << std::endl;

    return 0;
}
