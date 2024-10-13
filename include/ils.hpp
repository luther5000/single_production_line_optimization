#ifndef PROJETOAPA_INCLUDE_ILS_H_
#define PROJETOAPA_INCLUDE_ILS_H_

#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "customTypes.hpp"
#include <vector>
#include <list>
#include <random>

using namespace std;

solucao metaHeuristica(const solucao& entrada, const prepararLinha& troca_suco, const uint& numIteracoes);

/**
 * Perturbação para o ILS que quebra o vetor em dois e copia a primeira
 * metade para a segunda metade do vetor, e copia a segunda metade para a
 * primeira metade do vetor.
 *
 * Essa perturbação é O(n).
 *
 * @param linhaProducao O vetor a ser alterado.
 */
void twoDividePerturbation(vector<suco_t>& linhaProducao);

/**
 * Perturbação que irá quebrar o vetor em duas partes e chama a
 * {@code twoDividePerturbation} para cada uma delas.
 *
 * Essa perturbação é O(n)
 *
 * @param linhaProducao O vetor a ser alterado.
 */
void fourDividePerturbation(vector<suco_t>& linhaProducao);

/**
 * Faz o swap entre todo par de elementos do vetor. Eventualmente todos
 * os elementos pares estarão em locais ímpares e vice-versa.
 *
 * Essa perturbação é O(n)
 *
 * @param linhaProducao O vetor a ser alterado.
 */
void changeOdsEven(vector<suco_t>& linhaProducao);

/**
 * Rotaciona os elementos do vetor n / 4 índices para
 * a direita.
 *
 * Algoritmo roda em O(n).
 */
void rotate(vector<suco_t>& linhaProducao);

/**
 * Realiza n * peso / 2 swaps aleatórios no vetor.
 *
 * Algoritmo roda em O(n * peso)
 *
 * @param linhaProducao O vetor a ser alterado.
 * @param peso Quantidade de interações sem melhora da solução.
 */
void multipleSwaps(vector<suco_t>& linhaProducao, const uint& peso);

/**
 * Rotaciona os elementos de indice par do vetor para a direita.
 *
 * Essa perturbação é O(n)
 *
 * */
void rotateEvens(vector<suco_t>& linhaProducao);

#endif//PROJETOAPA_INCLUDE_ILS_H_
