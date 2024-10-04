//
// Created by lutero on 27/09/24.
//

#ifndef __VIZINHANCAS_HPP
#define __VIZINHANCAS_HPP

#include "solucao.hpp"
#include "customTypes.hpp"
#include <list>

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
solucao twoSwap(const solucao& solucao, const prepararLinha& troca_suco);

/**
 * Essa vizinhanca eh gerada da seguinte forma:
 *
 * Para cada indice centro e cada inteiro r, fazemos swap dos r elementos na
 * borda do vetor mais proximos do centro com seus respectivos elementos
 * diametralmente opostos em relacao ao centro. Por exemplo
 *
 * 0 1 2 3 4 5
 *
 * Escolhendo o centro 3, para raio 1, teriamos
 *
 * 0 5 2 3 4 1
 *
 * E para raio 2
 *
 * 0 5 4 3 2 1
 *
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada A solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * @return A melhor solucao encontrada na vizinhanca.
 * */
solucao pivoSwap(const solucao& entrada, const prepararLinha& troca_suco);

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
solucao reverseSwap(const solucao& entrada, const prepararLinha& troca_suco);

/**
 * Função que calcula o valor de uma solução a partir de uma list ao invés
 * de um vector.
 * @param linhaProducao Contém a ordem dos sucos a serem produzidos.
 * @param trocaSuco O tempo necessário para trocar os sucos de lugar.
 * @return A multa paga para se executar essa linha de produção.
 */
llong calculaSolucao(const list<suco_t>& linhaProducao, const prepararLinha& trocaSuco);

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 * Para cada inteiro shift, 0 < shift < n, onde n eh o tamanho da linha de
 * produco, faz a linha de producao ir de
 *
 * 0, 1, 2, ..., n
 *
 * para
 *
 * 0 + shift, 1 + shift, 2 + shift, ..., n + shift
 *
 * Com todos esses valores tomados modulo n.
 *
 * @note Essa vizinhanca eh varrida em O(n^2)
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 * */
solucao rotateSwap(const solucao& entrada, const prepararLinha& troca_suco);

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

#endif //__VIZINHANCAS_HPP
