#include "variableNeighborhoodDescent.hpp"
#include "customTypes.hpp"
#include "solucao.hpp"
#include "vizinhancas.hpp"

solucao variableNeighborhoodDescent(const solucao& entrada,
                                    const prepararLinha& troca_suco) {

    constexpr int num_vizinhancas = 5;
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
            case 4: { //fiveFactorialSwap
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
            case 5: { //threeSwap
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
