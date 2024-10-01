//
// Created by lutero on 01/10/24.
//
#ifndef ILS_HPP
#define ILS_HPP

#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include <vector>

using namespace std;

solucao metaHeuristica(const solucao& entrada, const vector<vector<int>>& troca_suco, const int& numIteracoes);

void twoDividePerturbation(vector<suco_t>& linhaProducao);

void fourDividePerturbation(vector<suco_t>& linhaProducao);

void changeOdsEven(vector<suco_t>& linhaProducao);

#endif //ILS_HPP
