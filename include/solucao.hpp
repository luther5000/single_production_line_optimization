#ifndef PROJETOAPA_INCLUDE_SOLUCAO_H_
#define PROJETOAPA_INCLUDE_SOLUCAO_H_

#include <iostream>
#include <vector>
#include <string>

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
    vector<suco_t> linhaProducao;
    llong multaTotal;

    /**
     * Um construtor da classe solucao.
     *
     * O argumento sucos é copiado diretamente para o campo linhaProducao
     * da classe. Já a multa total é calculada na inicialização usando
     * troca_suco, a qual contem o custo para mudar de uma linha para outra,
     * e esse valor é armazenado no campo multaTotal.
     *
     * @note Esse construtor garante que o valor armazenado em multaTotal é de
     * fato correspondente ao vector de sucos linhaProducao após sua
     * inicializacao.
     * */
    solucao(const vector<suco_t>& sucos, const prepararLinha& troca_suco);

    /**
     * Um construtor da classe solucao.
     *
     * O argumento sucos é copiada diretamente para o campo linhaProducao da
     * classe. De forma semelhante, o argumento valorMulta é copiada direta-
     * mente para o campo multaTotal.
     *
     * @note Esse construtor não garante que o valor armazendo em multaTotal é
     * de fato correspondente ao vector de sucos linhaProducao.
     * */
    solucao(const vector<suco_t>& sucos, const llong& valorMulta);

    /**
     * Um construtor da classe solucao.
     *
     * A solucao é iniciada de forma vazia, com o campo linhaProducao contendo
     * um vector vazio, e a multaTotal contendo 0.
     * */
    solucao();

    /**
     * Calcula quanto vale a solucao atual armazenada no campo linhaProducao
     * E guarda no campo multaTotal.
     *
     * @note Essa função é executada em O(n)
     * @param troca_suco A matriz que guarda o custo para parar a produção de
     * um tipo de suco e iniciar a produção de outro.
     * */
    void calcula_solucao(const prepararLinha& troca_suco);

    /**
     * Exibe a solução armazenada na tela.
     * */
    void exibe();

    /**
     * Exibe apenas o valor da solução na tela.
     * */
    void exibeReduzido();
};

#endif//PROJETOAPA_INCLUDE_SOLUCAO_H_
