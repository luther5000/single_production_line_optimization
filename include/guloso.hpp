#ifndef PROJETOAPA_INCLUDE_GULOSO_H_
#define PROJETOAPA_INCLUDE_GULOSO_H_

#include "customTypes.hpp"
#include "solucao.hpp"
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class guloso {
public:
    int size;
    vector<suco_t> solucao;
    vector<suco_t> sucos;
    prepararLinha trocaSuco;

    /**
     * Construtor da classe guloso.
     *
     * @param size O tamanho do vector de sucos
     * @param sucos O vector de sucos que representa a linha de produção.
     * @param trocaSuco A matriz que contém os custos para iniciar a produção
     * de um suco a partir de outro.
     * */
    guloso(const int& size , const vector<suco_t>& sucos, const prepararLinha& trocaSuco);

    /**
     * Função que aplica a seguinte lógica gulosa ao conteúdo do objeto:
     *
     * Para cada posição do vector, escolha o suco de menor prazo ainda não
     * selecionado para ocupar essa posição.
     *
     * Devido a simplicidade desse algoritmo, sua execução é apenas um sort
     * no campo prazo dos sucos.
     *
     * @note Esse algoritmo é executado em n*lg(n).
     * @return Um ponteiro para a solução gerada.
     * */
    class solucao *algoritmo_guloso();

};
#endif//PROJETOAPA_INCLUDE_GULOSO_H_
