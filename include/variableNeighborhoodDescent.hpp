#ifndef PROJETOAPA_INCLUDE_VARIABLENEIGHBORHOODDESCENT_H_
#define PROJETOAPA_INCLUDE_VARIABLENEIGHBORHOODDESCENT_H_

#include "solucao.hpp"
#include <vector>

using namespace std;
/**
 * Implementacao do VND. Ele recebe uma solucao como entrada e a matriz que
 * contem o custo para iniciar a producao de um outro suco dado o suco atual.
 * O loop while eh mantido testando o insertSwap ate que ele nao encontre uma
 * solucao melhor, ai depois testa uma proxima vizinhanca. Sempre que um re-
 * sultado melhor eh encontrado, voltamos ao insertSwap. A busca termina quando
 * nenhuma vizinhanca obter um resultado melhor que o atual.
 * */
solucao variableNeighborhoodDescent(const solucao& entrada, const vector<vector<int>>& troca_suco);

#endif//PROJETOAPA_INCLUDE_VARIABLENEIGHBORHOODDESCENT_H_
