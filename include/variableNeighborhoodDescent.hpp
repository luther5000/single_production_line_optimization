#ifndef __VARIABLE_NEIGHBORHOOD_SEARCH_HPP
#define __VARIABLE_NEIGHBORHOOD_SEARCH_HPP

#include "solucao.hpp"
#include <vector>

/**
 * Implementacao do VND. Ele recebe uma solucao como entrada e a matriz que
 * contem o custo para iniciar a producao de um outro suco dado o suco atual.
 * O loop while eh mantido testando o insertSwap ate que ele nao encontre uma
 * solucao melhor, ai depois testa uma proxima vizinhanca. Sempre que um re-
 * sultado melhor eh encontrado, voltamos ao insertSwap. A busca termina quando
 * nenhuma vizinhanca obter um resultado melhor que o atual.
 * */
solucao variableNeighborhoodDescent(const solucao& entrada, const vector<vector<int>>& troca_suco);

#endif//__VARIABLE_NEIGHBORHOOD_SEARCH_HPP
