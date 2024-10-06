#ifndef INSTANCIA_PROBLEMA_H
#define INSTANCIA_PROBLEMA_H

#include "solucao.hpp"
#include "customTypes.hpp"
#include <vector>
#include <string>

using namespace std;

class instancia_problema {
public:
    int size;
    vector<suco_t> sucos;
    prepararLinha trocaSuco;

    /**
     * Builder da classe instancia_problema.
     * Recebe um path como endereco, e extrai os dados necessarios dele.
     *
     * @param endereco O endereco do arquivo para ser lido como entrada.
     * */
    instancia_problema(const string& endereco);

    /**
     * Exibe a solução armazenada na tela.
     * */
    void exibe() const;
};

#endif //INSTANCIA_PROBLEMA_H
