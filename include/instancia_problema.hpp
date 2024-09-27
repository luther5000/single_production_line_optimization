#ifndef INSTANCIA_PROBLEMA_H
#define INSTANCIA_PROBLEMA_H

#include <vector>
#include <string>

using namespace std;

typedef struct {
    long long indice;
    long long tempo;
    long long prazo;
    long long multa;
} suco_t;

class instancia_problema {
public:
    int size;
    vector<suco_t> sucos;
    vector<suco_t> solucao;
    long long solucaoValor;
    vector<vector<int>> trocaSuco;

    instancia_problema(const string& endereco);

    long long getsolucao_valor() const;

    void exibe() const;
};

#endif //INSTANCIA_PROBLEMA_H
