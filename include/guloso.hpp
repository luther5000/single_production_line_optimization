//
// Created by lutero on 27/09/24.
//

#ifndef GULOSO_HPP
#define GULOSO_HPP

#include <algorithm>
#include "customTypes.hpp"
#include "solucao.hpp"
#include <vector>

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

    /**
     * Função que aplica a seguinte lógica gulosa ao conteúdo do objeto:
     *
     * Para cada posição do vector, escolha o suco que gera menor multa no
     * momento que ainda não tenha sido selecionado. Se houver mais de um,
     * escolha aquele de menor prazo.
     *
     * Como esse algoritmo precisa sempre buscar o suco que gera menor multa,
     * e a escolha de um suco afeta o valor da multa de todos os futuros
     * sucos, esse algoritmo precisa varrer a lista de sucos por inteiro a
     * cada busca.
     *
     * @note Esse algortimo é executado em n^2
     * @return Um ponteiro para a solução gerada.
     * */
    class solucao *algoritmo_guloso_2();

};
#endif //GULOSO_HPP
