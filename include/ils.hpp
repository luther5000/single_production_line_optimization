//
// Created by lutero on 01/10/24.
//
#ifndef ILS_HPP
#define ILS_HPP

#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include <vector>
#include <random>
#include <iostream>

using namespace std;

solucao metaHeuristica(const solucao& entrada, const vector<vector<int>>& troca_suco, const int& numIteracoes);

void divisaoPerturbacao(vector<suco_t>& vector);

#endif //ILS_HPP
