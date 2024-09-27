#ifndef INSTANCIA_PROBLEMA_H
#define INSTANCIA_PROBLEMA_H

#include "solucao.hpp"
#include <vector>
#include <string>

using namespace std;

class instancia_problema {
public:
    int size;
    vector<suco_t> sucos;
    vector<vector<int>> troca_suco;

    instancia_problema(const string& endereco);
    void exibe() const;
};

#endif //INSTANCIA_PROBLEMA_H
