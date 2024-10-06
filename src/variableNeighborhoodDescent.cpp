#include "variableNeighborhoodDescent.hpp"
#include "solucao.hpp"
#include "vizinhancas.hpp"

using namespace std;

solucao variableNeighborhoodDescent(const solucao& entrada, const vector<vector<int>>& troca_suco) {
    const int num_vizinhancas = 7;
    solucao melhorSolucao = entrada;
    int k = 1;
    while(k <= num_vizinhancas) {
        switch(k) {
            case 1: { //insertSwap
                solucao melhorVizinho = insertSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                } else {
                    k += 1;
                }
                break;
            }
            case 2: { //twoSwap
                solucao melhorVizinho = twoSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                }
                else {
                    k += 1;
                }
                break;
            }
            case 3: { //reverseSwap
                solucao melhorVizinho = reverseSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                }
                else {
                    k += 1;
                }
                break;
            }
            case 4: { //rotateSwap
                solucao melhorVizinho = rotateSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                }
                else {
                    k += 1;
                }
                break;
            }
            case 5: { //pivoSwap
                solucao melhorVizinho = pivoSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                }
                else {
                    k += 1;
                }
                break;
            }
            case 6: { //fiveFactorialSwap
                solucao melhorVizinho = fiveFactorialSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                }
                else {
                    k += 1;
                }
                break;
            }
            case 7: { //threeSwap
                solucao melhorVizinho = threeSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                }
                else {
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
