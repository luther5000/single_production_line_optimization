#include <iostream>
#include "instancia_problema.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    instancia_problema test("instancias/n60A.txt");
    test.algoritmo_guloso();
    test.calcula_solucao();
    std::cout << test.getsolucao_valor() << std::endl;

    return 0;
}
