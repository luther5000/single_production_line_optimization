//
// Created by lutero on 01/10/24.
//
#include "ils.hpp"

solucao metaHeuristica(const solucao& entrada, const vector<vector<int>>& troca_suco, const int& numIteracoes) {
    unsigned int cont = 0;
    solucao melhorSolucao = entrada;
    solucao solucaoParaVnd = entrada;
    do {
        solucao solucaoAtual = variableNeighborhoodDescent(solucaoParaVnd, troca_suco);

        if (solucaoAtual.multaTotal < melhorSolucao.multaTotal) {
            /*
             * Caso a solução gerada pelo VND for melhor que a solução que tinhamos
             * anteriormente, iremos pegar essa solução e aplicar a perturbação
             * {@code twoCodePerturbation}.
             */
            melhorSolucao = solucaoAtual;
            solucaoParaVnd = melhorSolucao;

            twoDividePerturbation(solucaoParaVnd.linhaProducao);
        } else {
            /*
             * Caso a solução gerada tenha sido pior, em cima da solução calculada
             * na iteração anterior do ILS iremos aplicar as perturbações
             * {@changeOdsEven} e {@fourDividePerturbation}.
             */
            changeOdsEven(solucaoParaVnd.linhaProducao);
            fourDividePerturbation(solucaoParaVnd.linhaProducao);
        }

        solucaoParaVnd.calcula_solucao(troca_suco);
        ++cont;

    } while (cont < numIteracoes);
    return melhorSolucao;
}

/**
 * Perturbação para o ILS que quebra o vetor em dois e copia a primeira
 * metade para a segunda metade do vetor, e copia a segunda metade para a
 * primeira metade do vetor.
 *
 * Essa perturbação é o(n).
 * @param linhaProducao O vetor a ser alterado.
 */
void twoDividePerturbation(vector<suco_t>& linhaProducao) {
    /*
     * Iremos efetuar o swap entre cada um dos elementos da primeira
     * metade do vetor e o seu diametralmente oposto.
     */
    if (linhaProducao.size() % 2 == 0) {
        for (int i = 0; i < linhaProducao.size() / 2; ++i) {
            swap(linhaProducao[i], linhaProducao[(linhaProducao.size() / 2) + i]);
        }
    } else {
        /*
         * Caso seja ímpar o número de elementos do vetor, a gente preserva o elemento do meio
         * em sua posição atual.
         */
        for (int i = 0; i < (linhaProducao.size() - 1) / 2; ++i) {
            swap(linhaProducao[i], linhaProducao[(linhaProducao.size() + 1) / 2 + i]);
        }
    }
}

/**
 * Perturbação que irá quebrar o vetor em duas partes e chama a
 * {@code twoDividePerturbation} para cada uma delas.
 * @param linhaProducao O vetor a ser alterado.
 */
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

/**
 * Faz o swap entre todo par de elementos do vetor. Eventualmente todos
 * os elementos pares estarão em locais ímpares e vice-versa.
 * @param linhaProducao O vetor a ser alterado.
 */
void changeOdsEven(vector<suco_t> &linhaProducao) {
    int i = 0;
    int j = 1;

    while (i < linhaProducao.size() && j < linhaProducao.size()) {
        swap(linhaProducao[i], linhaProducao[j]);

        i += 2;
        j += 2;
    }
}