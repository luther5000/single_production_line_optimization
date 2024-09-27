#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include "instancia_problema.hpp"

using namespace std;

/*
 * Builder da classe instancia_problema.
 * Recebe um path como endereco, e extrai os dados necessarios dele.
 * */
instancia_problema::instancia_problema(const string& endereco) {
    ifstream file;
    file.open(endereco.c_str(), ios::in);
    if(!file.is_open()) {
        cout << "fuck";
        perror("Erro");
    }

    size = 0;
    file >> size;
    solucao_valor = -1;

    sucos.resize(size);

    for (int i = 0; i < size; ++i) {
        sucos[i].indice = i;
        file >> sucos[i].tempo;
    }

    for (int i = 0; i < size; ++i)
        file >> sucos[i].prazo;

    for (int i = 0; i <size; ++i)
        file >> sucos[i].multa;

    troca_suco.resize(size + 1);

    for (int i = 0; i < size + 1; ++i) {
        troca_suco[i].resize(size);
        for (int j = 0; j < size; ++j) {
            file >> troca_suco[i][j];
        }
    }

    file.close();
}

void instancia_problema::algoritmo_guloso() {
    solucao.resize(size);
    for (int i = 0; i < size; ++i) {
        solucao[i] = sucos[i];
    }

    sort(solucao.begin(), solucao.end(), [](suco_t const& a, suco_t const& b) {
        return a.prazo < b.prazo;
    });
}

void instancia_problema::calcula_solucao() {
    long long tempo = 0;
    solucao_valor = 0;
    long long ultimo_linha = 0;

    for (int i = 0; i < size; ++i) {
        tempo += troca_suco[ultimo_linha][solucao[i].indice] + solucao[i].tempo;
        long long tempo_passado = tempo - solucao[i].prazo;

        if (tempo_passado > 0)
            solucao_valor += tempo_passado*solucao[i].multa;

        ultimo_linha = solucao[i].indice + 1;
    }
}

long long instancia_problema::getsolucao_valor() const {
    return solucao_valor;
}

void instancia_problema::exibe() const {
    printf("Valores de entrada:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(suco_t cs: sucos) {
        printf("%7lld: %7lld %7lld %7lld\n", cs.indice, cs.tempo, cs.prazo, cs.multa);
    }
    printf("\n");
    printf("Valores da solucao:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(suco_t cs: solucao) {
        printf("%7lld: %7lld %7lld %7lld\n", cs.indice, cs.tempo, cs.prazo, cs.multa);
    }
    printf("\n");
    printf("Valor da solucao: %lld\n", solucao_valor);
}
