//
// Created by lutero on 27/09/24.
//

#include "guloso.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"


guloso::guloso(const int& size, const vector<suco_t>& sucos,
    const prepararLinha& trocaSuco) {
    this->trocaSuco = trocaSuco;
    this->sucos = sucos;
    this->size = size;
}

solucao* guloso::algoritmo_guloso() {
    solucao.resize(size);
    for (int i = 0; i < size; ++i) {
        solucao[i] = sucos[i];
    }

    sort(solucao.begin(), solucao.end(), [](suco_t const& a, suco_t const& b) {
        return a.prazo < b.prazo;
    });

    return new class solucao(this->solucao, this->trocaSuco);
}

solucao* guloso::algoritmo_guloso_2() {
    list<suco_t> values;
    solucao.resize(size);
    for(int i = 0; i < size; ++i) {
        values.push_back(sucos[i]);
    }

    llong tempoAtual = 0;
    llong ultimaLinha = 0;

    for(int i = 0; i < size; ++i) {
        list<suco_t>::iterator it1, it2;
        it2 = values.begin();
        llong multaAtual = INT64_MAX;

        for(it1 = values.begin(); it1 != values.end(); ++it1) {

            int passouPrazo = (tempoAtual - (*it1).prazo + (*it1).tempo 
                + trocaSuco[ultimaLinha][(*it1).indice]);

            if(passouPrazo > 0) {
                if(passouPrazo * (*it1).multa < multaAtual) {
                    it2 = it1;
                    multaAtual = passouPrazo * (*it1).multa;
                } else if(passouPrazo * (*it1).multa == multaAtual) {
                    if((*it1).prazo < (*it2).prazo) {
                        it2 = it1;
                    }
                }
            } else {
                if((*it1).prazo < (*it2).prazo) {
                        it2 = it1;
                }
            }
        }

        solucao[i] = *it2;
        values.erase(it2);
        tempoAtual += solucao[i].tempo + trocaSuco[ultimaLinha][solucao[i].indice];
        ultimaLinha = solucao[i].indice + 1;

    }

    return new class solucao(this->solucao, this->trocaSuco);
}
