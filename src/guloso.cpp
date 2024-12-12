#include "guloso.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"


solucao* algoritmo_guloso(const instancia_problema &i_problema) {
    solucao *solucao = new ::solucao(i_problema);

    for (ulong i = 0; i < i_problema.size; ++i) {
        solucao->linhaProducao[i] = i;
    }

    sort(solucao->linhaProducao.begin(), solucao->linhaProducao.end(), [i_problema]
        (const uint a, const uint b) {
        return i_problema.sucos[a].prazo < i_problema.sucos[b].prazo;
    });

    solucao->calcula_solucao_inicial();

    return solucao;
}
