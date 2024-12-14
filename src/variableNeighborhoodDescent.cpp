#include "variableNeighborhoodDescent.hpp"
#include "customTypes.hpp"
#include "solucao.hpp"
#include "vizinhancas.hpp"

void variableNeighborhoodDescent(solucao &entrada, const instancia_problema &i_problema) {

    constexpr int num_vizinhancas = 3;
    constexpr ulong k_reinsertion = 1;
    llong melhorSolucao = entrada.multaTotal;
    int k = 1;
    while(k <= num_vizinhancas) {
        switch(k) {
            case 1: { //reinsertion
                ulong i = 1;

                while (i <= k_reinsertion) {
                    reinsertion(entrada, i_problema, i);

                    if (entrada.multaTotal < melhorSolucao) {
                        melhorSolucao = entrada.multaTotal;
                        i = 1;
                    } else {
                        ++i;
                    }
                }
                break;
            }
            case 2: { //opt
                opt(entrada, i_problema);
                break;
            }
            case 3: { //twoswap
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
            ++k;
        }
    }
}
