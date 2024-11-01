#include "customTypes.hpp"
#include "executeAll.hpp"
#include <cstdlib>

int main(int argc, char **argv) {

    /*if(argc > 3) {
        printf("Uso: projeto_apa.exe\n"
               "     projeto_apa.exe [<instância>]\n"
               "     projeto_apa.exe [<instância>] [<num>]\n");
        return 1;
    }
    switch(argc) {
        case 3: {
            llong total = 0;
            llong tempo_total = 0;
            int num = atoi(argv[2]);
            for(int i = 0; i < num; ++i) {
                pair<llong, long> saida = executeOne(argv[1]);
                total += saida.first;
                tempo_total += saida.second;
                printf("===================================================\n");
            }
            printf("Média das solucoes: %lld\n\n", total / num);
            printf("Média do tempo de execução: %lld milissegundos\n\n",
                    tempo_total / num);
            break;
        }
        case 2: {
            executeOne(argv[1]);
            break;
        }
        case 1: {
            executeAll();
            break;
        }
    }*/

    instancia_problema instancia(argv[1]);
    solucao *solucao = algoritmo_guloso(instancia);
    solucao->exibe(instancia);

    return 0;
}
