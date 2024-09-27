//
// Created by lutero on 27/09/24.
//

#include "guloso.hpp"
#include "solucao.hpp"

guloso::guloso(const int &size, const vector<suco_t> &sucos,
    const vector<vector<int> > &trocaSuco) {

    this->solucao.resize(size);
    this->trocaSuco = trocaSuco;
    this->sucos = sucos;
    this->size = size;
    this->solucaoValor = 0;
}

solucao *guloso::algoritmo_guloso() {
    solucao.resize(size);
    for (int i = 0; i < size; ++i) {
        solucao[i] = sucos[i];
    }

    sort(solucao.begin(), solucao.end(), [](suco_t const& a, suco_t const& b) {
        return a.prazo < b.prazo;
    });

    return new solucao::solucao(this->solucao, this->trocaSuco);
}