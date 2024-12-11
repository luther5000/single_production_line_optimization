#include "guloso.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"


solucao* algoritmo_guloso(const instancia_problema &i_problema) {
    solucao *solucao = new ::solucao(i_problema);
    solucao->linhaProducao.resize(i_problema.size);

    for (ulong i = 0; i < i_problema.size; ++i) {
        solucao->linhaProducao[i].indice = i;
    }

    sort(solucao->linhaProducao.begin(), solucao->linhaProducao.end(), [i_problema]
        (const solucaoInfo_t &a, const solucaoInfo_t &b) {
        return i_problema.sucos[a.indice].prazo < i_problema.sucos[b.indice].prazo;
    });

    solucao->calcula_solucao_inicial();

    return solucao;
}
