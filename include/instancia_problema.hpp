#ifndef PROJETOAPA_INCLUDE_INSTANCIAPROBLEMA_H_
#define PROJETOAPA_INCLUDE_INSTANCIAPROBLEMA_H_

#include "solucao.hpp"
#include "customTypes.hpp"
#include <fstream>
#include <iostream>
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

#endif //PROJETOAPA_INCLUDE_INSTANCIAPROBLEMA_H_
