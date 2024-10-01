//
// Created by lutero on 01/10/24.
//
#include "ils.hpp"

solucao metaHeuristica(const solucao& entrada, const vector<vector<int>>& troca_suco, const int& numIteracoes) {
    unsigned int cont = 0;
    solucao melhorSolucao = entrada;
    solucao solucaoParaVnd = entrada;
    do {
        solucao solucaoAtual = variableNeighborhoodDescent(solucaoParaVnd, troca_suco);
        if (solucaoAtual.multaTotal < melhorSolucao.multaTotal) {
            melhorSolucao = solucaoAtual;
            solucaoParaVnd = melhorSolucao;
        }

        divisaoPerturbacao(solucaoParaVnd.linhaProducao);
        solucaoParaVnd.calcula_solucao(troca_suco);
        ++cont;

    } while (cont < numIteracoes);
    return melhorSolucao;
}

void divisaoPerturbacao(vector<suco_t>& vector) {
    if (vector.size() % 2 == 0) {
        for (int i = 0; i < vector.size() / 2; ++i) {
            swap(vector[i], vector[(vector.size() / 2) + i]);
        }
    } else {
        for (int i = 0; i < (vector.size() - 1) / 2; ++i) {
            swap(vector[i], vector[(vector.size() + 1) / 2 + i]);
        }
    }
}