#ifndef PROJETOAPA_INCLUDE_ILS_H_
#define PROJETOAPA_INCLUDE_ILS_H_

#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "customTypes.hpp"
#include "guloso.hpp"
#include <vector>
#include <list>
#include <random>

using namespace std;

solucao *metaHeuristica(const instancia_problema& i_problema, uint numIteracoes);

/**
 * Perturbação para o ILS que quebra o vetor em dois e copia a primeira
 * metade para a segunda metade do vetor, e copia a segunda metade para a
 * primeira metade do vetor.
 *
 * Essa perturbação é O(n).
 *
 * @param linhaProducao O vetor a ser alterado.
 */
void twoDividePerturbation(vector<solucaoInfo_t>& linhaProducao);

/**
 * Faz o swap entre todo par de elementos do vetor. Eventualmente todos
 * os elementos pares estarão em locais ímpares e vice-versa.
 *
 * Essa perturbação é O(n)
 *
 * @param linhaProducao O vetor a ser alterado.
 */
void changeOdsEven(vector<solucaoInfo_t>& linhaProducao);

/**
 * Rotaciona os elementos do vetor n / 4 índices para
 * a direita.
 *
 * Algoritmo roda em O(n).
 */
void rotate(vector<solucaoInfo_t>& linhaProducao);

/**
 * Realiza n * peso / 2 swaps aleatórios no vetor.
 *
 * Algoritmo roda em O(n * peso)
 *
 * @param linhaProducao O vetor a ser alterado.
 * @param peso Quantidade de interações sem melhora da solução.
 */
void multipleSwaps(vector<solucaoInfo_t>& linhaProducao, const uint& peso);

/**
 * Rotaciona os elementos de indice par do vetor para a direita.
 *
 * Essa perturbação é O(n)
 *
 * */
void rotateEvens(vector<solucaoInfo_t>& linhaProducao);

#endif//PROJETOAPA_INCLUDE_ILS_H_
