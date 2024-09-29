#include "variableNeighborhoodDescent.hpp"
#include "solucao.hpp"
#include "vizinhancas.hpp"

using namespace std;

/*
 * Implementacao do VND. Ele recebe uma solucao como entrada e a matriz que
 * contem o custo para iniciar a producao de um outro suco dado o suco atual.
 * O loop while eh mantido testando o twoSwap ate que ele nao encontre uma
 * solucao melhor, ai depois testa uma proxima vizinhanca. Sempre que um re-
 * sultado melhor eh encontrado, voltamos ao twoSwap. A busca termina quando
 * nenhuma vizinhanca obter um resultado melhor que o atual.
 * */
solucao variableNeighborhoodDescent(const solucao& entrada, const vector<vector<int>>& troca_suco) {
    const int num_vizinhancas = 3;
    solucao melhorSolucao = entrada;
    int k = 1;
    while(k <= num_vizinhancas) {
        switch(k) {
            case 1: { //twoSwap
                solucao melhorVizinho = twoSwap(melhorSolucao, troca_suco);
                if(melhorVizinho.multaTotal < melhorSolucao.multaTotal) {
                    melhorSolucao = std::move(melhorVizinho);
                    k = 1;
                } else {
                    k += 1;
                }
                break;
            }
            case 2: { //reverseSwap
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
            case 3: { //rotateSwap
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
            default:
                break;
        }
    }
    return melhorSolucao;
}
