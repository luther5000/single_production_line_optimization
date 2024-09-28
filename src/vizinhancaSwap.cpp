#include "vizinhancaSwap.hpp"
/*
 * Troca todos os pares de elementos de lugar, e verifica quais desses gera uma
 * melhor solucao. Eh valido ressaltar que os unicos pares trocados sao da
 * solucao passada como entrada: ele para assim que todos os pares forem testa-
 * dos, e nao quando um minimo local for encontrado.
 * Entradas:
 *  - const solucao& entrada: uma solucao qualquer. É copiada no corpo da funcao
 *  portanto nao eh alterada.
 *  - const vector<vectir<int>>& troca_suco: a matriz que contem as trocas de
 *  contexto da linha de producao
 * Saida:
 *  - Um novo objeto solucao com a melhor solucao encontrada.
 * Complexidade:
 *  - Cubico em relacao ao tamanho do vector linhaProducao interno a solucao;
 * */
solucao vizinhaca2Swap(const solucao& entrada,
        const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n)
    unsigned long iMelhorSolucao = 0;
    unsigned long jMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;

    // O(n^2)
    for(unsigned long i = 0; i < entrada.linhaProducao.size() - 1; ++i) {
        for(unsigned long j = i + 1; j < entrada.linhaProducao.size() - 1; ++j) {

            std::swap(copiaEntrada.linhaProducao[i],
                    copiaEntrada.linhaProducao[j]);

            // Calcula solucao custa O(n)
            // Como eh realizad O(n^2) vezes, o custo total
            // eh O(n^3)
            // Uma otimizacao possivel eh calcular os valores
            // apenas onde a alteracao ocorreu
            // Isso faria essa chamada ser O(1), derrubando a
            // complexidade para O(n^2).
            copiaEntrada.calcula_solucao(troca_suco);

            // O resto do corpo da funcao eh O(1)
            if(copiaEntrada.multaTotal < melhorSolucao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                melhorSolucao = copiaEntrada.multaTotal;
            }
            std::swap(copiaEntrada.linhaProducao[i],
                    copiaEntrada.linhaProducao[j]);
        }
    }

    // Tambem eh O(1)
    std::swap(copiaEntrada.linhaProducao[iMelhorSolucao],
            copiaEntrada.linhaProducao[jMelhorSolucao]);
    copiaEntrada.multaTotal = melhorSolucao;

    // O compilador otimiza essa saida para um move, e nao uma copia
    // Portanto ela eh realizada em O(1)
    return copiaEntrada;
}
