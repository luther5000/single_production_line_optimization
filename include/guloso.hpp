//
// Created by lutero on 27/09/24.
//

#ifndef GULOSO_HPP
#define GULOSO_HPP

#include <algorithm>
#include <instancia_problema.hpp>
#include "solucao.hpp"
#include <vector>

using namespace std;

class guloso {
public:
    int size;
    vector<suco_t> solucao;
    vector<suco_t> sucos;
    vector<vector<int>> trocaSuco;

    guloso(const int& size , const vector<suco_t>& sucos, const vector<vector<int>>& trocaSuco);

    class solucao *algoritmo_guloso();

    class solucao *algoritmo_guloso_2();

};
#endif //GULOSO_HPP
