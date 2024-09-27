#ifndef __SOLUCAO_H
#define __SOLUCAO_H

#include <vector>

using namespace std;

typedef struct {
    long long indice;
    long long tempo;
    long long prazo;
    long long multa;
} suco_t;

class solucao {
public:
    vector<suco_t> linhaProducao;
    long long multaTotal;

    explicit solucao(const vector<suco_t>& solucao, const vector<vector<int>>& troca_suco);
    void calcula_solucao(const vector<vector<int>>& troca_suco);
    void exibe();
};

#endif //__SOLUCAO_H
