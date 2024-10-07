#include "executeAll.hpp"
#include "ils.hpp"

void executeAll(){
    const vector<string> enderecos = {
        "instancias/n60A.txt",
        "instancias/n60B.txt",
        "instancias/n60C.txt",
        "instancias/n60D.txt",
        "instancias/n60E.txt",
        "instancias/n60F.txt",
        "instancias/n60G.txt",
        "instancias/n60H.txt",
        "instancias/n60I.txt",
        "instancias/n60J.txt",
        "instancias/n60K.txt",
        "instancias/n60L.txt",
        "instancias/n60M.txt",
        "instancias/n60N.txt",
        "instancias/n60O.txt",
        "instancias/n60P.txt"
    };

    for (string endereco : enderecos) {
        printf("%s\n", endereco.c_str());
        instancia_problema instancia(endereco);

#define GULOSO_1
//#define GULOSO_2

#ifdef GULOSO_1
        printf("Guloso 1: ");
        guloso guloso1(instancia.size, instancia.sucos, instancia.trocaSuco);
        solucao *solucao1 = guloso1.algoritmo_guloso();
        solucao1->exibeReduzido();

        printf("VND 1: ");
        variableNeighborhoodDescent(*solucao1, instancia.trocaSuco).exibeReduzido();

        printf("ILS 1: ");
        metaHeuristica(*solucao1, instancia.trocaSuco, 15).exibeReduzido();
#endif
#ifdef GULOSO_2
        printf("Guluso 2: ");
        guloso guloso2(instancia.size, instancia.sucos, instancia.trocaSuco);
        solucao *solucao2 = guloso2.algoritmo_guloso_2();
        solucao2->exibeReduzido();

        printf("VND 2: ");
        variableNeighborhoodDescent(*solucao2, instancia.trocaSuco).exibeReduzido();

        printf("ILS 2: ");
        metaHeuristica(*solucao2, instancia.trocaSuco, 15).exibeReduzido();
#endif
        printf("=====================================\n");
    }
}

void executeOneSeveralTimes(const string& endereco){
    long long total = 0;
    for (int i = 0; i < 10; ++i){
        instancia_problema instancia(endereco);

        guloso guloso(instancia.size, instancia.sucos, instancia.trocaSuco);
        solucao *solucao = guloso.algoritmo_guloso_2();

        //variableNeighborhoodDescent(*solucao, instancia.trocaSuco).exibe(endereco);
        *solucao = metaHeuristica(*solucao, instancia.trocaSuco, 15);
        solucao->exibe(endereco);

        total += solucao->multaTotal;
    }

    cout << "Média: " << total / 10 << endl;
}
