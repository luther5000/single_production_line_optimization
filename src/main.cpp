#include "instancia_problema.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Insira um arquivo como entrada!" << std::endl;
        return 1;
    }
    instancia_problema test(argv[1]);
    test.algoritmo_guloso();
    test.calcula_solucao();
    test.exibe();

    return 0;
}
