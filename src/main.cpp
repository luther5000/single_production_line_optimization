#include "instancia_problema.hpp"
#include "guloso.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Insira um arquivo como entrada!" << std::endl;
        return 1;
    }
    instancia_problema test(argv[1]);
    test.exibe();

    guloso guloso(test.size, test.sucos, test.trocaSuco);
    guloso.algoritmo_guloso();
    guloso.calcula_solucao();

    cout << guloso.solucaoValor << endl;

    return 0;
}
