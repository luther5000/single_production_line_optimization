#ifndef PROJETOAPA_INCLUDE_GULOSO_H_
#define PROJETOAPA_INCLUDE_GULOSO_H_

#include "customTypes.hpp"
#include "solucao.hpp"
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


/**
* Função que aplica a seguinte lógica gulosa ao conteúdo do objeto:
*
* Para cada posição do vector, escolha o suco de menor prazo ainda não
* selecionado para ocupar essa posição.
*
* Devido a simplicidade desse algoritmo, sua execução é apenas um sort
* no campo prazo dos sucos.
*
* @note Esse algoritmo é executado em n*lg(n).
* @return Um ponteiro para a solução gerada.
* */
solucao *algoritmo_guloso(instancia_problema &i_problema);

#endif//PROJETOAPA_INCLUDE_GULOSO_H_
