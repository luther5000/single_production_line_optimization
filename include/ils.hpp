//
// Created by lutero on 01/10/24.
//
#ifndef ILS_HPP
#define ILS_HPP

#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "customTypes.hpp"
#include <vector>
#include <list>
#include <random>

using namespace std;

solucao metaHeuristica(const solucao& entrada, const prepararLinha& troca_suco, const int& numIteracoes);

void twoDividePerturbation(vector<suco_t>& linhaProducao);

void fourDividePerturbation(vector<suco_t>& linhaProducao);

void changeOdsEven(vector<suco_t>& linhaProducao);

void rotate(vector<suco_t>& linhaProducao);

void multipleSwaps(vector<suco_t>& linhaProducao);

void rotateEvens(vector<suco_t>& linhaProducao);

#endif //ILS_HPP
