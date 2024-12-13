#include "variableNeighborhoodDescent.hpp"
#include "customTypes.hpp"
#include "solucao.hpp"
#include "vizinhancas.hpp"

void variableNeighborhoodDescent(solucao &entrada, const instancia_problema &i_problema) {

    constexpr int num_vizinhancas = 3;
    llong melhorSolucao = entrada.multaTotal;
    int k = 1;
    while(k <= num_vizinhancas) {
        switch(k) {
            case 1: { //twoSwap
                reinsertion(entrada, i_problema, 1);
                break;
            }
            case 2: { //opt
                opt(entrada, i_problema);
                break;
            }
            case 3: { //reinsertion
                twoSwap(entrada, i_problema);
                break;
            }
            default:
                break;
        }
        if (entrada.multaTotal < melhorSolucao) {
            melhorSolucao = entrada.multaTotal;
            k = 1;
        } else {
            k += 1;
        }
    }
}
