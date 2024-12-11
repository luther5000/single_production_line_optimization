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

    explicit solucao(const solucao *solucao);

    explicit solucao(const instancia_problema &i_problema);

    void calcula_solucao_inicial();

    llong simula_solucao_two_swap(ulong i, ulong j) const;

    void calcula_solucao_two_swap(ulong i, ulong j);

    llong simula_solucao_opt(ulong i, ulong j) const;

    void calcula_solucao_opt(ulong i, ulong j);

    llong simula_solucao_reinsertion(ulong i, ulong j) const;

    void calcula_solucao_reinsertion(ulong i, ulong j);

    solucao* criaCopia();

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
