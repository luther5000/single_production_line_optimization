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
void reinsertion(solucao &entrada, const instancia_problema &i_problema, const ulong l);

void opt(solucao &entrada, const instancia_problema &i_problema);

#endif//PROJETOAPA_INCLUDE_VIZINHANCAS_H_
