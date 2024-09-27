#include "instancia_problema.hpp"
#include "solucao.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Insira um arquivo como entrada!" << std::endl;
        return 1;
    }
    instancia_problema test(argv[1]);
    test.exibe();

    solucao valor(test.sucos, test.troca_suco);
    valor.exibe();

    return 0;
}
