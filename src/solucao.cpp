#include "solucao.hpp"

solucao::solucao(const vector<suco_t>& sucos, const prepararLinha& troca_suco) {
    this->linhaProducao = sucos;
    this->calcula_solucao(troca_suco);
}

solucao::solucao(const vector<suco_t>& sucos, const llong& valorMulta){
    this->linhaProducao = sucos;
    this->multaTotal = valorMulta;
}

solucao::solucao() {
    this->linhaProducao.resize(0);
    this->multaTotal = 0;
}

void solucao::calcula_solucao(const prepararLinha& troca_suco) {
    llong tempo = 0;
    this->multaTotal = 0;
    llong ultimoLinha = 0;
    llong tempoPassado;

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
        printf("%7lld: %7lld %7lld %7lld\n",
            cs.indice, cs.tempo, cs.prazo, cs.multa);
    }
    printf("\n");
    printf("Valor da solucao: %lld\n\n", this->multaTotal);
}

void solucao::exibeReduzido() {
    printf("Valor da solucao: %lld\n", this->multaTotal);
}
