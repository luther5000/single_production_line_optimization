#include "solucao.hpp"
#include <vector>
#include <iostream>

solucao::solucao(const vector<suco_t>& solucao, const vector<vector<int>>& troca_suco) {
    this->linhaProducao = solucao;
    this->calcula_solucao(troca_suco);
}

void solucao::calcula_solucao(const vector<vector<int>>& troca_suco) {
    long long tempo = 0;
    this->multaTotal = 0;
    long long ultimoLinha = 0;
    long long tempoPassado;

    for (unsigned long i = 0; i < linhaProducao.size(); ++i) {
        tempo += troca_suco[ultimoLinha][linhaProducao[i].indice] + linhaProducao[i].tempo;
        tempoPassado = tempo - linhaProducao[i].prazo;

        if (tempoPassado > 0)
            multaTotal += tempoPassado*linhaProducao[i].multa;

        ultimoLinha = linhaProducao[i].indice + 1;
    }
}

void solucao::exibe() {
    printf("Valores da solucao:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(suco_t cs: this->linhaProducao) {
        printf("%7lld: %7lld %7lld %7lld\n", cs.indice, cs.tempo, cs.prazo, cs.multa);
    }
    printf("\n");
    printf("Valor da solucao: %lld\n", this->multaTotal);
}
