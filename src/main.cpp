#include "instancia_problema.hpp"
#include "guloso.hpp"
#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "vizinhancas.hpp"
#include "ils.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Insira um arquivo como entrada!" << std::endl;
        return 1;
    }
    instancia_problema test(argv[1]);
    //test.exibe();

    guloso gul = guloso(test.size, test.sucos, test.trocaSuco);

    solucao *sul = gul.algoritmo_guloso();
    sul->exibe();

    variableNeighborhoodDescent(*sul, test.trocaSuco).exibe();

    metaHeuristica(*sul, test.trocaSuco, 15).exibe();
    return 0;
}
