#ifndef EXECUTEALL_HPP
#define EXECUTEALL_HPP

#include <iostream>
#include <vector>
#include "instancia_problema.hpp"
#include "guloso.hpp"
#include "solucao.hpp"
#include "variableNeighborhoodDescent.hpp"
#include "ils.hpp"

using namespace std;

void executeAll();

void executeOneSeveralTimes(const string& endereco);

#endif // EXECUTEALL_HPP
