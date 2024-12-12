#include "executeAll.hpp"
#include "ils.hpp"

void executeAll(const uint numExecucoes){
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

        /*printf("Guloso 1 \n");

        auto begin = high_resolution_clock::now();
        solucao *solucao1 = algoritmo_guloso(instancia);
        auto end = high_resolution_clock::now();
        solucao1->exibeReduzido();

        auto duration = duration_cast<milliseconds>(end - begin);
        printf("Duração: %ld milisegundos\n", duration.count());

        printf("\nVND \n");

        solucao *solucao2 = new solucao(solucao1);
        begin = high_resolution_clock::now();
        variableNeighborhoodDescent(*solucao2, instancia);
        end = high_resolution_clock::now();
        solucao2->exibeReduzido();

        duration = duration_cast<milliseconds>(end - begin);
        printf("Duração: %ld milissegundos\n", duration.count());

        printf("\nILS \n");*/
        ullong tempoTotal = 0;
        ullong multaTotal = 0;

        for (uint i = 0; i < 10; ++i) {
            auto begin = high_resolution_clock::now();
            solucao *solucaoAtual = metaHeuristica(instancia, numExecucoes);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - begin);

            tempoTotal += duration.count();
            multaTotal += solucaoAtual->multaTotal;
            solucaoAtual->exibeReduzido();
        }
        printf("Média da solução: %lld\n", multaTotal / 10);
        printf("Tempo médio gasto: %lld milissegundos\n\n", tempoTotal / 10);
        printf("=====================================\n\n");
    }
}

pair<llong, long> executeOne(const string& endereco, const uint numExecucoes){
    instancia_problema instancia(endereco);

    //variableNeighborhoodDescent(*solucao, instancia.trocaSuco).exibe(endereco);
    auto begin = high_resolution_clock::now();
    solucao *solucao = metaHeuristica(instancia, numExecucoes);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - begin);

    solucao->exibe(instancia);
    printf("Tempo gasto: %ld milissegundos\n\n", duration.count());

    pair<llong, long> saida(solucao->multaTotal, duration.count());

    return saida;
}
