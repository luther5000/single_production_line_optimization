#include "vizinhancas.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"

void twoSwap(solucao &entrada, const instancia_problema &i_problema) {
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;
    llong melhorSolucao = entrada.multaTotal;


    for(ulong i = 0; i + 1 < i_problema.size; ++i) {
        for(ulong j = i + 1; j < i_problema.size; ++j) {

            llong solucaoAtual = entrada.simula_solucao_two_swap(i, j);

            if(solucaoAtual < melhorSolucao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                melhorSolucao = solucaoAtual;
            }
        }
    }
    entrada.calcula_solucao_two_swap(iMelhorSolucao, jMelhorSolucao);
}

void opt(solucao &entrada, const instancia_problema &i_problema) {
    llong valorMelhorProducao = entrada.multaTotal;
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;

    for (ulong i = 0; i < i_problema.size; ++i) {
        for (ulong j = i + 3; j < i_problema.size; ++j) {
            llong solucaoAtual = entrada.simula_solucao_opt(i, j);

            if (solucaoAtual < valorMelhorProducao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                valorMelhorProducao = solucaoAtual;
            }
        }
    }
    entrada.calcula_solucao_opt(iMelhorSolucao, jMelhorSolucao);
}

void reinsertion(solucao &entrada, const instancia_problema &i_problema){
    llong valorMelhorProducao = entrada.multaTotal;
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;

    for (ulong i = 0; i < i_problema.size; ++i) {
        for (ulong j = i + 2; j < i_problema.size; ++j) {
            llong solucaoAtual = entrada.simula_solucao_reinsertion(i, j);

            if (solucaoAtual < valorMelhorProducao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                valorMelhorProducao = solucaoAtual;
            }
        }
    }
    entrada.calcula_solucao_reinsertion(iMelhorSolucao, jMelhorSolucao);
}
