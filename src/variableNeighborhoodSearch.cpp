#include "variableNeighborhoodSearch.hpp"
#include "solucao.hpp"
#include "vizinhancaSwap.hpp"

using namespace std;

solucao variableNeighborhoodSearch(const solucao& entrada, const vector<vector<int>>& troca_suco) {
    const int num_vizinhancas = 1;
    solucao melhorSolucao = entrada;
    int k = 1;
    while(k <= num_vizinhancas) {
        switch(k) {
            case 1: { //twoSwap
                solucao melhorVizinho = vizinhaca2Swap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                } else {
                    k += 1;
                }
                break;
            }
            default:
                break;
        }
    }
    return melhorSolucao;
}
