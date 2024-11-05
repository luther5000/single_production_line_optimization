#ifndef PROJETOAPA_INCLUDE_VIZINHANCAS_H_
#define PROJETOAPA_INCLUDE_VIZINHANCAS_H_

#include <algorithm>
#include <list>

#include "solucao.hpp"
#include "customTypes.hpp"
#include "instancia_problema.hpp"

using namespace std;

/**
 * Esta vizinhanca é gerada da seguinte forma:
 *
 *  Para cada par de indices i e j, i < j, trocamos o valor na posicao i com
 *  o valor na posicao j.
 *
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 * */
void twoSwap(solucao &solucao, const instancia_problema &i_problema);

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 * Para cada par de indices, inicio e fim, invertemos a ordem dos elementos
 * entre esses dois indices, com eles inclusos.
 *
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao
 * @return A melhor solucao encontrada na vizinhanca.
 * */
void reinsertion(solucao &entrada, const instancia_problema &i_problema);

void opt(solucao &entrada, const instancia_problema &i_problema);

/**
 * Função que calcula o valor de uma solução a partir de uma list ao invés
 * de um vector.
 * @param linhaProducao Contém a ordem dos sucos a serem produzidos.
 * @param trocaSuco O tempo necessário para trocar os sucos de lugar.
 * @return A multa paga para se executar essa linha de produção.
 */
llong calculaSolucao(const list<suco_t>& linhaProducao, const prepararLinha& trocaSuco);

/**
 * Função que verifica para cada suco todos os possíveis locais que o
 * suco pode ser inserido e guarda o melhor vizinho obtido para retornar ele.
 *
 * Ex: Caso selecionemos 2 no vetor abaixo
 *
 * 1 2 3 4 5
 *
 * Os possíveis locais de inserção seria:
 *
 * 2 1 3 4 5
 * 1 3 2 4 5
 * 1 3 4 2 5
 * 1 3 4 5 2
 *
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 */
solucao insertSwap(const solucao& entrada, const prepararLinha& troca_suco);

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 *  Para cada indice index, pegamos os valores [index, index + 5)
 *  e testamos todas as permutacoes desses elementos
 *
 * @note Essa vizinhanca eh varrida em O(n^2)
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 */
solucao fiveFactorialSwap(const solucao& entrada, const prepararLinha& troca_suco);

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 *  Para cada tripla de indices i, j e k, i < j < k, trocamos
 *  os valores i, j e k de posicao. As trocas que o twoSwap
 *  varre sao excluidas
 *
 * @note Essa vizinhanca eh varrida em O(n^4)
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 */
solucao threeSwap(const solucao& entrada, const prepararLinha& troca_suco);

#endif//PROJETOAPA_INCLUDE_VIZINHANCAS_H_
