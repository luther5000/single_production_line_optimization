#include "ils.hpp"
#include "customTypes.hpp"

solucao metaHeuristica(const solucao& entrada, const prepararLinha& troca_suco, const uint& numIteracoes) {
    uint cont = 0;
    uint forcaPerturbacao = 1;
    solucao melhorSolucao = entrada;
    solucao solucaoParaVnd = entrada;
    do {
        solucao solucaoAtual = variableNeighborhoodDescent(solucaoParaVnd, troca_suco);

        if (solucaoAtual.multaTotal < melhorSolucao.multaTotal) {
            melhorSolucao = solucaoAtual;
            solucaoParaVnd = melhorSolucao;

            /*
             * Caso a solução gerada pelo VND for melhor que a solução que tinhamos
             * anteriormente, iremos reiniciar a força das perturbações aplicadas.
             */
            forcaPerturbacao = 1;
        } else {
            /*
             * Caso a solução gerada tenha sido pior, iremos aumentar gradualmente
             * a força das perturbações a serem aplicadas.
             */
            ++forcaPerturbacao;
        }

        switch (forcaPerturbacao) {
            case 1: {
                twoDividePerturbation(solucaoParaVnd.linhaProducao);
                rotate(solucaoParaVnd.linhaProducao);
                multipleSwaps(solucaoParaVnd.linhaProducao, forcaPerturbacao);
                break;
            }
            case 2: {
                fourDividePerturbation(solucaoParaVnd.linhaProducao);
                changeOdsEven(solucaoParaVnd.linhaProducao);
                multipleSwaps(solucaoParaVnd.linhaProducao, forcaPerturbacao);
                break;
            }
            default: {
                rotateEvens(solucaoParaVnd.linhaProducao);
                multipleSwaps(solucaoParaVnd.linhaProducao, forcaPerturbacao);
                break;
            }
        }

        solucaoParaVnd.calcula_solucao(troca_suco);
        ++cont;

    } while (cont < numIteracoes);
    return melhorSolucao;
}

void twoDividePerturbation(vector<suco_t>& linhaProducao) {
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

void fourDividePerturbation(vector<suco_t> &linhaProducao) {
    vector<suco_t> primeiraMetade;
    vector<suco_t> segundaMetade;
    int size = linhaProducao.size();

    for (int i = 0; i < size / 2; ++i) {
        primeiraMetade.push_back(linhaProducao[i]);
        segundaMetade.push_back(linhaProducao[size / 2 + i]);
    }

    if (size % 2 != 0)
        segundaMetade.push_back(linhaProducao[size - 1]);

    twoDividePerturbation(primeiraMetade);
    twoDividePerturbation(segundaMetade);

    for (suco_t suco : segundaMetade) {
        primeiraMetade.push_back(suco);
    }
    linhaProducao = primeiraMetade;
}

void changeOdsEven(vector<suco_t> &linhaProducao) {
    ulong i = 0;
    ulong j = 1;

    while (i < linhaProducao.size() && j < linhaProducao.size()) {
        swap(linhaProducao[i], linhaProducao[j]);

        i += 2;
        j += 2;
    }
}

void rotate(vector<suco_t>& linhaProducao){
    uint n = linhaProducao.size();

    list<suco_t> lista;
    for (uint i = 0; i < n; ++i)
        lista.push_back(linhaProducao[i]);

    for (uint i = 0; i < n / 4; ++i){
        lista.push_front(lista.back());
        lista.pop_back();
    }

    int i = 0;
    for (suco_t suco : lista){
        linhaProducao[i] = suco;
        ++i;
    }
}

void multipleSwaps(vector<suco_t>& linhaProducao, const uint& peso){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, linhaProducao.size() - 1);

    for (uint k = 0; k < linhaProducao.size()*peso / 2; ++k){
        uint i = distr(gen);
        uint j = distr(gen);

        swap(linhaProducao[i], linhaProducao[j]);
    }
}

void rotateEvens(vector<suco_t>& linhaProducao) {
    ulong n = linhaProducao.size();
    if(n % 2 == 0) {
        suco_t value0 = linhaProducao[0];
        for(ulong i = 0; i < n - 2; i += 2) {
            linhaProducao[i] = linhaProducao[i + 2];
        }
        linhaProducao[n - 2] = value0;
    } else {
        suco_t value0 = linhaProducao[0];
        for(ulong i = 0; i < n - 1; i += 2) {
            linhaProducao[i] = linhaProducao[i + 2];
        }
        linhaProducao[n - 1] = value0;
    }
}
