//
// Created by lutero on 27/09/24.
//

#include "guloso.hpp"

guloso::guloso(const int &size, const vector<suco_t> &sucos,
    const vector<vector<int> > &trocaSuco) {

    this->solucao.resize(size);
    this->trocaSuco = trocaSuco;
    this->sucos = sucos;
    this->size = size;
    this->solucaoValor = 0;
}

void guloso::algoritmo_guloso() {
    solucao.resize(size);
    for (int i = 0; i < size; ++i) {
        solucao[i] = sucos[i];
    }

    sort(solucao.begin(), solucao.end(), [](suco_t const& a, suco_t const& b) {
        return a.prazo < b.prazo;
    });
}

void guloso::calcula_solucao() {
    long long tempo = 0;
    solucaoValor = 0;
    long long ultimo_linha = 0;

    for (int i = 0; i < size; ++i) {
        tempo += trocaSuco[ultimo_linha][solucao[i].indice] + solucao[i].tempo;
        long long tempoPassado = tempo - solucao[i].prazo;

        if (tempoPassado > 0)
            solucaoValor += tempoPassado*solucao[i].multa;

        ultimo_linha = solucao[i].indice + 1;
    }
}
