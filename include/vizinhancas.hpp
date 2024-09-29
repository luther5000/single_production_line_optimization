//
// Created by lutero on 27/09/24.
//

#ifndef __VIZINHANCAS_HPP
#define __VIZINHANCAS_HPP

#include "solucao.hpp"
#include <vector>
#include <list>

using namespace std;

solucao twoSwap(const solucao& solucao, const vector<vector<int>>& troca_suco);

solucao pivoSwap(const solucao& entrada, const vector<vector<int>>& troca_suco);

solucao reverseSwap(const solucao& entrada, const vector<vector<int>>& troca_suco);

solucao rotateSolucao(const solucao& entrada, const vector<vector<int>>& trocaSuco);

long long calculaSolucao(const list<suco_t>& linhaProducao, const vector<vector<int>>& trocaSuco);

#endif //__VIZINHANCAS_HPP
