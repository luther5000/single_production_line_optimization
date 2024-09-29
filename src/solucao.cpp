#include "solucao.hpp"
#include <iostream>

solucao::solucao(const vector<suco_t>& solucao, const vector<vector<int>>& troca_suco) {
    this->linhaProducao = solucao;
    this->calcula_solucao(troca_suco);
}

solucao::solucao() {
    this->linhaProducao.resize(0);
    this->multaTotal = 0;
}

void solucao::calcula_solucao(const vector<vector<int>>& troca_suco) {
    long long tempo = 0;
    this->multaTotal = 0;
    long long ultimoLinha = 0;
    long long tempoPassado;

    for (suco_t i: linhaProducao) {
        tempo += troca_suco[ultimoLinha][i.indice] + i.tempo;
        tempoPassado = tempo - i.prazo;

        if (tempoPassado > 0)
            multaTotal += tempoPassado*i.multa;

        ultimoLinha = i.indice + 1;
    }
}

void solucao::exibe() {
    printf("Valores da solucao:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(suco_t cs: this->linhaProducao) {
        printf("%7lld: %7lld %7lld %7lld\n", cs.indice, cs.tempo, cs.prazo, cs.multa);
    }
    printf("\n");
    printf("Valor da solucao: %lld\n\n", this->multaTotal);
}
