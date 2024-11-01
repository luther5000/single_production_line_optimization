#include "guloso.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"


solucao* algoritmo_guloso(instancia_problema &i_problema) {
    solucao *solucao = new ::solucao;
    solucao->linhaProducao.resize(i_problema.size);

    for (int i = 0; i < i_problema.size; ++i) {
        solucao->linhaProducao[i].indice = i;
    }

    sort(solucao->linhaProducao.begin(), solucao->linhaProducao.end(), [i_problema]
        (const solucaoInfo_t &a, const solucaoInfo_t &b) {
        return i_problema.sucos[a.indice].prazo < i_problema.sucos[b.indice].prazo;
    });

    return solucao;
}
