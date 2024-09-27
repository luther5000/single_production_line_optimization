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
private:
    int size;
    vector<suco_t> sucos;
    vector<suco_t> solucao;
    long long solucao_valor;
    vector<vector<int>> troca_suco;

public:
    instancia_problema(const string& endereco);

    void algoritmo_guloso();

    void calcula_solucao();

    long long getsolucao_valor() const;

    void exibe() const;
};

#endif //INSTANCIA_PROBLEMA_H
