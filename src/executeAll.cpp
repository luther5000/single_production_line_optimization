#include "executeAll.hpp"

void executeAll(){
    vector<string> enderecos = {
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
        instancia_problema instancia(endereco);

        guloso guloso(instancia.size, instancia.sucos, instancia.trocaSuco);
        solucao *solucao = guloso.algoritmo_guloso_2();

        //variableNeighborhoodDescent(*solucao, instancia.trocaSuco).exibe(endereco);
        metaHeuristica(*solucao, instancia.trocaSuco, 15).exibe(endereco);
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