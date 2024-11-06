#ifndef PROJETOAPA_INCLUDE_EXECUTEALL_H_
#define PROJETOAPA_INCLUDE_EXECUTEALL_H_

#include "instancia_problema.hpp"
#include "guloso.hpp"
#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "ils.hpp"
#include "customTypes.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <chrono>

using namespace chrono;
using namespace std;

void executeAll(uint numExecucoes);

pair<llong, long> executeOne(const string& endereco, uint numExecucoes);

#endif // PROJETOAPA_INCLUDE_EXECUTEALL_H_
