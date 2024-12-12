#include "ils.hpp"
#include "customTypes.hpp"

solucao *metaHeuristica(const instancia_problema& i_problema, const uint numIteracoes) {
    uint cont = 0;
    uint forcaPerturbacao = 1;

    solucao *solucaoAtual = algoritmo_guloso(i_problema);
    variableNeighborhoodDescent(*solucaoAtual, i_problema);

    solucao *melhorSolucao = solucaoAtual->criaCopia();

    do {
        if (solucaoAtual->multaTotal < melhorSolucao->multaTotal) {
            melhorSolucao = solucaoAtual->criaCopia();
            /*
             * Caso a solução gerada pelo VND for melhor que a solução que tinhamos
             * anteriormente, iremos reiniciar a força das perturbações aplicadas.
             */
            forcaPerturbacao = 1;
        } else if (cont != 0) {
            solucaoAtual = melhorSolucao->criaCopia();
            /*
             * Caso a solução gerada tenha sido pior, iremos aumentar gradualmente
             * a força das perturbações a serem aplicadas.
             */
            ++forcaPerturbacao;
        }

        switch (forcaPerturbacao) {
            case 1: {
                //twoDividePerturbation(solucaoParaVnd->linhaProducao);
                rotate(solucaoAtual->linhaProducao);
                multipleSwaps(solucaoAtual->linhaProducao, forcaPerturbacao);
                break;
            }
            case 2: {
                changeOdsEven(solucaoAtual->linhaProducao);
                multipleSwaps(solucaoAtual->linhaProducao, forcaPerturbacao);
                break;
            }
            default: {
                rotateEvens(solucaoAtual->linhaProducao);
                multipleSwaps(solucaoAtual->linhaProducao, forcaPerturbacao);
                break;
            }
        }

        solucaoAtual->calcula_solucao_inicial();
        variableNeighborhoodDescent(*solucaoAtual, i_problema);

        ++cont;
    } while (cont < numIteracoes);
    return melhorSolucao;
}

void twoDividePerturbation(vector<uint>& linhaProducao) {
    /*
     * Iremos efetuar o swap entre cada um dos elementos da primeira
     * metade do vetor e o seu diametralmente oposto.
     */
    if (linhaProducao.size() % 2 == 0) {
        for (uint i = 0; i < linhaProducao.size() / 2; ++i) {
            swap(linhaProducao[i], linhaProducao[(linhaProducao.size() / 2) + i]);
        }
    } else {
        /*
         * Caso seja ímpar o número de elementos do vetor, a gente preserva o elemento do meio
         * em sua posição atual.
         */
        for (uint i = 0; i < (linhaProducao.size() - 1) / 2; ++i) {
            swap(linhaProducao[i], linhaProducao[(linhaProducao.size() + 1) / 2 + i]);
        }
    }
}

void changeOdsEven(vector<uint>& linhaProducao) {
    ulong i = 0;
    ulong j = 1;

    while (i < linhaProducao.size() && j < linhaProducao.size()) {
        swap(linhaProducao[i], linhaProducao[j]);

        i += 2;
        j += 2;
    }
}

void rotate(vector<uint>& linhaProducao){
    uint n = linhaProducao.size();
    vector<uint> novo;
    novo.resize(linhaProducao.size());

    uint j = n - n/4;
    for (uint i = 0; i < n; ++i) {
        novo[i] = linhaProducao[j % n];
        ++j;
    }

    for (uint i = 0; i < n; ++i)
        linhaProducao[i] = novo[i];

}

void multipleSwaps(vector<uint>& linhaProducao, const uint peso){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, linhaProducao.size() - 1);

    for (uint k = 0; k < linhaProducao.size()*peso / 2; ++k){
        uint i = distr(gen);
        uint j = distr(gen);

        swap(linhaProducao[i], linhaProducao[j]);
    }
}

void rotateEvens(vector<uint>& linhaProducao) {
    ulong n = linhaProducao.size();
    if(n % 2 == 0) {
        uint value0 = linhaProducao[0];
        for(ulong i = 0; i < n - 2; i += 2) {
            linhaProducao[i] = linhaProducao[i + 2];
        }
        linhaProducao[n - 2] = value0;
    } else {
        uint value0 = linhaProducao[0];
        for(ulong i = 0; i < n - 1; i += 2) {
            linhaProducao[i] = linhaProducao[i + 2];
        }
        linhaProducao[n - 1] = value0;
    }
}
