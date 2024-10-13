#ifndef PROJETOAPA_INCLUDE_CUSTOMTYPES_H_
#define PROJETOAPA_INCLUDE_CUSTOMTYPES_H_

#include <vector>

using namespace std;

/**
 * Um alias para o tipo unsigned int
 * */
typedef unsigned int uint;

/**
 * Um alias para o tipo long long.
 * */
typedef long long llong;

/**
 * Um alias para o tipo unsigned long.
 * */
typedef unsigned long ulong;

/**
 * Um alias para o tipo unsigned long long.
 * */
typedef unsigned long long ullong;

/**
 * Um alias para a matriz que guarda o tempo necessário para ir de uma linha
 * de produção para outra.
 * @note A interpreção a ser realizada é: O valor em v[i][j] representa o
 * custo de tempo para sair da linha i e ir para a linha j.
 * Se i for igual a 0, ele representa o tempo gasto ao se iniciar nesse linha.
 * */
typedef vector<vector<int>> prepararLinha;

/**
 * Essa estrutura representa um suco no código, contendo:
 * @param indice A posição desse suco no documento de entrada.
 * @param tempo O tempo necessário para produzir o suco.
 * @param prazo O prazo com o qual o suco deve ser produzido.
 * @param multa A multa para cada unidade de tempo que exceder o prazo de
 * producao do suco.
 * */
typedef struct {
    long long indice;
    long long tempo;
    long long prazo;
    long long multa;
} suco_t;

#endif//PROJETOAPA_INCLUDE_CUSTOMTYPES_H_
