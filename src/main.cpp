#include "customTypes.hpp"
#include "executeAll.hpp"
#include <cstdlib>

int main(int argc, char **argv) {

    if(argc > 3) {
        printf("Uso: projeto_apa.exe"
               "     projeto_apa.exe [<instância>]"
               "     projeto_apa.exe [<instância>] [<num>]");
        return 1;
    }
    switch(argc) {
        case 3: {
            llong total = 0;
            int num = atoi(argv[2]);
            for(int i = 0; i < num; ++i) {
                total += executeOne(argv[1]);
            }
            printf("Média das solucoes: %lld\n\n", total / num);
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
    }

    return 0;
}
