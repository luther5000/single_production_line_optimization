#ifndef PROJETOAPA_INCLUDE_SOLUCAO_H_
#define PROJETOAPA_INCLUDE_SOLUCAO_H_

#include <iostream>
#include <vector>
#include <string>

#include "instancia_problema.hpp"
#include "customTypes.hpp"

using namespace std;

/**
 * Uma classe que contem um vector de sucos, representando uma linha de
 * producao, e um long long representando o valor da multa que é obtido ao se
 * executar essa linha de producao. 
 *
 * @note A classe não garante que o campo
 * multaTotal é de fato a multa total associada a linha de producao.
 * @param linhaProducao O vector de sucos representando a linha de producao.
 * @param multaTotal A multa total associada a essa linha de producao.
 * */
class solucao {
public:
    vector<solucaoInfo_t> linhaProducao;
    llong multaTotal;
    const instancia_problema &i_problema;


    explicit solucao(const instancia_problema &i_problema);

    /**
     * Calcula quanto vale a solucao atual armazenada no campo linhaProducao
     * E guarda no campo multaTotal.
     *
     * @note Essa função é executada em O(n)
     * @param troca_suco A matriz que guarda o custo para parar a produção de
     * um tipo de suco e iniciar a produção de outro.
     * */
    void calcula_solucao_inicial();

    llong simula_solucao_two_swap(ulong i, ulong j) const;

    void calcula_solucao_two_swap(ulong i, ulong j);

    llong simula_solucao_opt(ulong i, ulong j) const;

    void calcula_solucao_opt(ulong i, ulong j);

    llong simula_solucao_reinsertion(ulong i, ulong j) const;

    void calcula_solucao_reinsertion(ulong i, ulong j);

    /**
     * Exibe a solução armazenada na tela.
     * */
    void exibe(const instancia_problema &i_problema) const;

    /**
     * Exibe apenas o valor da solução na tela.
     * */
    void exibeReduzido();
};

#endif//PROJETOAPA_INCLUDE_SOLUCAO_H_
