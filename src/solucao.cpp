#include "solucao.hpp"

#include <algorithm>

solucao::solucao(const instancia_problema &i_problema): i_problema(i_problema) {
    this->multaTotal = 0;
}

void solucao::calcula_solucao_inicial() {
    llong tempo = 0;
    this->multaTotal = 0;
    llong ultimoLinha = 0;


    for (ulong i = 0; i < i_problema.size; ++i) {
        tempo += i_problema.trocaSuco[ultimoLinha][linhaProducao[i].indice]
                 + i_problema.sucos[linhaProducao[i].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i].indice].tempo;

        if (tempoPassado > 0)
            multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i].indice].multa;

        linhaProducao[i].multaAtual = multaTotal;
        linhaProducao[i].tempoDecorrido = tempo;

        ultimoLinha = linhaProducao[i].indice + 1;
    }
}

llong solucao::simula_solucao_two_swap(const ulong i, const ulong j) const {
    llong tempo = linhaProducao[i-1].tempoDecorrido;
    llong multaAtual = linhaProducao[i-1].multaAtual;
    llong ultimaLinha = linhaProducao[i-1].indice + 1;

    for (ulong k = i; k < i_problema.size; ++k) {
        ulong l = k;

        if (k == i)
            l = j;

        if (k == j)
            l = i;

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[l].indice]
                 + i_problema.sucos[linhaProducao[l].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[l].indice].tempo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[l].indice].multa;

        ultimaLinha = linhaProducao[l].indice + 1;
    }

    return multaAtual;
}

void solucao::calcula_solucao_two_swap(ulong i,const ulong j) {
    if (i == j && i == 0)
        return;

    llong tempo = linhaProducao[i-1].tempoDecorrido;
    this->multaTotal = linhaProducao[i-1].multaAtual;
    llong ultimaLinha = linhaProducao[i-1].indice + 1;

    swap(linhaProducao[i], linhaProducao[j]);

    for (; i < i_problema.size; ++i) {

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i].indice]
                 + i_problema.sucos[linhaProducao[i].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i].indice].tempo;

        if (tempoPassado > 0)
            this->multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i].indice].multa;

        linhaProducao[i].multaAtual = multaTotal;
        linhaProducao[i].tempoDecorrido = tempo;

        ultimaLinha = linhaProducao[i].indice + 1;
    }
}

llong solucao::simula_solucao_opt(ulong i, ulong j) const {
    llong tempo = linhaProducao[i-1].tempoDecorrido;
    llong multaAtual = linhaProducao[i-1].multaAtual;
    llong ultimaLinha = linhaProducao[i-1].indice + 1;

    ulong l = j;
    for (ulong k = i; k < i_problema.size; ++k) {
        ulong m = k;

        if (k >= i && k <= j) {
            m = l;
            --l;
        }

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[m].indice]
                 + i_problema.sucos[linhaProducao[m].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[m].indice].tempo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[m].indice].multa;

        ultimaLinha = linhaProducao[m].indice + 1;
    }

    return multaAtual;
}

void solucao::calcula_solucao_opt(ulong i, ulong j) {
    if (i == j && i == 0)
        return;

    llong tempo = linhaProducao[i-1].tempoDecorrido;
    multaTotal = linhaProducao[i-1].multaAtual;
    llong ultimaLinha = linhaProducao[i-1].indice + 1;

    reverse(linhaProducao.begin() + i, linhaProducao.begin() + j+1);

    for (; i < i_problema.size; ++i) {
        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i].indice]
                 + i_problema.sucos[linhaProducao[i].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i].indice].tempo;

        if (tempoPassado > 0)
            this->multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i].indice].multa;

        linhaProducao[i].multaAtual = multaTotal;
        linhaProducao[i].tempoDecorrido = tempo;

        ultimaLinha = linhaProducao[i].indice + 1;
    }
}

llong solucao::simula_solucao_reinsertion(ulong i, ulong j) const {
    llong tempo = linhaProducao[i-1].tempoDecorrido;
    llong multaAtual = linhaProducao[i-1].multaAtual;
    llong ultimaLinha = linhaProducao[i-1].indice + 1;

    for (ulong k = i; k < i_problema.size; ++k) {
        ulong l = k;

        if (k == i)
            continue;

        if (k == j) {
            tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i].indice]
                 + i_problema.sucos[linhaProducao[i].indice].tempo;
            llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i].indice].tempo;

            if (tempoPassado > 0)
                multaAtual += tempoPassado * i_problema.sucos[linhaProducao[i].indice].multa;

            ultimaLinha = linhaProducao[i].indice + 1;
        }

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[l].indice]
                 + i_problema.sucos[linhaProducao[l].indice].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[l].indice].tempo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[l].indice].multa;

        ultimaLinha = linhaProducao[l].indice + 1;
    }

    return multaAtual;
}

void solucao::calcula_solucao_reinsertion(ulong i, ulong j) {

}






void solucao::exibe(const instancia_problema &i_problema) const{
    printf("Valores da solucao:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(ulong i = 0; i < i_problema.size; ++i) {
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
