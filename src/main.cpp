#include "instancia_problema.hpp"
#include "guloso.hpp"
#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "vizinhancas.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Insira um arquivo como entrada!" << std::endl;
        return 1;
    }
    instancia_problema test(argv[1]);
    test.exibe();

    guloso guloso(test.size, test.sucos, test.trocaSuco);
    solucao *solucao = guloso.algoritmo_guloso();

    solucao->exibe();
    insertSwap(*solucao, test.trocaSuco);

    //variableNeighborhoodDescent(*solucao, test.trocaSuco).exibe();

    return 0;
}
