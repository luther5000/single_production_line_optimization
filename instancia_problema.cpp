//
// Created by lutero on 21/09/24.
//
#include <algorithm>
#include  <vector>
#include <fstream>
#include <iostream>

using namespace std;

typedef struct {
    long long indice;
    long long tempo;
    long long prazo;
    long long multa;
} suco_t;

class instancia_problema {
private:
    int size = 0;
    vector<suco_t> sucos;
    vector<suco_t> solucao;
    long long solucao_valor;
    vector<vector<int>> troca_suco;

    explicit instancia_problema(const string& endereco) {
        ifstream file(endereco);
        file >> size;
        solucao_valor = -1;

        sucos.resize(size);
        int i;
        for (i = 0; i < size; ++i) {
            sucos[i].indice = i;
            file >> sucos[i].tempo;
        }
        for (i = 0; i < size; ++i)
            file >> sucos[i].prazo;
        for (i = 0; i <size; ++i)
            file >> sucos[i].multa;

        troca_suco.resize(size+1);
        for (i = 0; i < size+1; ++i) {
            troca_suco[i].resize(size);
            for (int j = 0; j < size; ++j) {
                file >> troca_suco[i][j];
            }
        }

        file.close();
    }

public:
    void algoritmo_guloso() {
        for (int i = 0; i < size; ++i) {
            solucao[i] = sucos[i];
        }

        sort(solucao.begin(), solucao.end(), [](suco_t a, suco_t b) {
            return a.prazo > b.prazo;
        });
    }

    void calcula_solucao() {
        long long tempo = 0;
        solucao_valor = 0;
        for (int i = 0; i < size+1; ++i) {
            tempo += troca_suco[i][solucao[i].indice] + solucao[i].tempo;
            long long tempo_passado = tempo - solucao[i].prazo;
            if (tempo_passado > 0)
                solucao_valor += tempo_passado*solucao[i].multa;
        }
    }

    long long getsolucao_valor(){
        return solucao_valor;
    }
};
