#include "customTypes.hpp"
#include "executeAll.hpp"
#include <cstdlib>
#include <vizinhancas.hpp>
#include "variableNeighborhoodDescent.hpp"

int main(int argc, char **argv) {

    switch(argc) {
        case 4: {
            llong total = 0;
            llong tempo_total = 0;
            int num = atoi(argv[2]);
            int numExecucoes = atoi(argv[3]);
            for(int i = 0; i < num; ++i) {
                pair<llong, long> saida = executeOne(argv[1], numExecucoes);
                total += saida.first;
                tempo_total += saida.second;
                printf("===================================================\n");
            }
            printf("Média das solucoes: %lld\n\n", total / num);
            printf("Média do tempo de execução: %lld milissegundos\n\n",
                    tempo_total / num);
            break;
        }
        case 3: {
            executeOne(argv[1], atoi(argv[2]));
            break;
        }
        case 2: {
            executeAll(atoi(argv[1]));
            break;
        }
        default: {
            printf("Uso: projeto_apa.exe [<num_ILS>]\n"
               "     projeto_apa.exe [<instância>] [<num_ILS>]\n"
               "     projeto_apa.exe [<instância>] [<num>] [<num_ILS>]\n");
            return 1;
        }
    }

    /*instancia_problema instancia(argv[1]);
    solucao *solucao = algoritmo_guloso(instancia);
    solucao->exibe(instancia);

    variableNeighborhoodDescent(*solucao, instancia);
    solucao->exibe(instancia);*/

    return 0;
}
