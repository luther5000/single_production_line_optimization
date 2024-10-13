#include "guloso.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"

guloso::guloso(const int& size, const vector<suco_t>& sucos,
    const prepararLinha& trocaSuco) {
    this->trocaSuco = trocaSuco;
    this->sucos = sucos;
    this->size = size;
}

solucao* guloso::algoritmo_guloso() {
    solucao.resize(size);
    for (int i = 0; i < size; ++i) {
        solucao[i] = sucos[i];
    }

    sort(solucao.begin(), solucao.end(), [](suco_t const& a, suco_t const& b) {
        return a.prazo < b.prazo;
    });

    return new class solucao(this->solucao, this->trocaSuco);
}
