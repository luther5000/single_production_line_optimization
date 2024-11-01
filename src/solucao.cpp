#include "solucao.hpp"

solucao::solucao(const vector<solucaoInfo_t> &linhaProducao,
                 const instancia_problema &i_problema) {

    this->linhaProducao = linhaProducao;
    this->calcula_solucao_inicial(i_problema);
}

solucao::solucao() {
    this->linhaProducao.resize(0);
    this->multaTotal = 0;
}

void solucao::calcula_solucao_inicial(const instancia_problema &i_problema) {
    llong tempo = 0;
    this->multaTotal = 0;
    llong ultimoLinha = 0;


    for (int i = 0; i < linhaProducao.size(); ++i) {
        tempo += i_problema.trocaSuco[ultimoLinha][linhaProducao[i].indice]
                 + i_problema.sucos[linhaProducao[i].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i].indice].tempo;

        if (tempoPassado > 0)
            multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i].indice].multa;

        linhaProducao[i].multaAtual = multaTotal;
        linhaProducao[i].tempoDecorrido = (tempoPassado > 0) ? tempoPassado : 0;

        ultimoLinha = linhaProducao[i].indice + 1;
    }
}

void solucao::exibe(const instancia_problema &i_problema) {
    printf("Valores da solucao:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(int i = 0; i < i_problema.size; ++i) {
        printf("%7u: %7lld %7lld %7lld\n",
            linhaProducao[i].indice,
            i_problema.sucos[linhaProducao[i].indice].tempo,
            i_problema.sucos[linhaProducao[i].indice].prazo,
            i_problema.sucos[linhaProducao[i].indice].multa);
    }
    printf("\n");
    printf("Valor da solucao: %lld\n\n", this->multaTotal);
}

void solucao::exibeReduzido() {
    printf("Valor da solucao: %lld\n", this->multaTotal);
}
