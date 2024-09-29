#include "vizinhancas.hpp"
#include "solucao.hpp"
#include <utility>
#include <vector>
/*
 * Troca todos os pares de elementos de lugar, e verifica quais desses gera uma
 * melhor solucao. Eh valido ressaltar que os unicos pares trocados sao da
 * solucao passada como entrada: ele para assim que todos os pares forem testa-
 * dos, e nao quando um minimo local for encontrado.
 * Entradas:
 *  - const solucao& entrada: uma solucao qualquer. É copiada no corpo da funcao
 *  portanto nao eh alterada.
 *  - const vector<vector<int>>& troca_suco: a matriz que contem as trocas de
 *  contexto da linha de producao
 * Saida:
 *  Retorna um objeto solucao, contendo a melhor solucao encontrada na
 *  vizinhanca.
 * Complexidade:
 *  - Cubico em relacao ao tamanho do vector linhaProducao interno a solucao;
 * */
solucao twoSwap(const solucao& entrada,
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

// Essa vizinhanca esta contida na reverseSwap, entao seu uso eh redundante.
/* Define um pivo como centro, e vai trocando os elementos ao redor dele, e
 * verifica quais desses geram uma melhor solucao. Por exemplo:
 * 0 1 2 3 4 5
 * Escolhendo o pivo 3, para raio 1, teriamos
 * 0 1 4 3 2 5
 * E para raio 2
 * 0 5 4 3 2 1
 * Ele testa todas a vizinhaca, com todos os centros e raios possiveis, retor-
 * nando a melhor solucao dentre todos estes.
 * Entradas:
 *  - const solucao& entrada: uma solucao qualquer. Eh copiada no corpo da
 *  funcao, portanto nao eh alterada.
 *  - const vector<vector<int>>& troca_suco: a matriz que contem as trocas de
 *  contexto da linha de producao
 * Saida:
 *  Retorna um objeto solucao, contendo a melhor solucao encontrada na
 *  vizinhanca.
 * Complexidade:
 *  - Cubico em relacao ao tamanho do vector linhaProducao interno a solucao.
 *  */
solucao pivoSwap(const solucao& entrada,
        const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n)
    unsigned long centroMelhorSolucao = 0;
    unsigned long raioMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;

    // testamos todos os centros validos
    // lembrando que o size() eh um unsigned, entao eh melhor so subtrair dele
    // quando houver certeza que o resultado nao dara overflow.
    for(unsigned long centro = 1; centro + 1 < entrada.linhaProducao.size(); ++centro) {
        unsigned long raio;
        // No geral, a quantidade de vezes que esse loop interno vai rodar eh
        // proporcional a O(n^2)
        for(raio = 1; centro >= raio && centro + raio < entrada.linhaProducao.size(); ++raio) {
            std::swap(copiaEntrada.linhaProducao[centro + raio], copiaEntrada.linhaProducao[centro - raio]);

            // Calcular a solucao eh proporcional a O(n)
            // E portanto essa linha tera peso O(n^3) no total
            copiaEntrada.calcula_solucao(troca_suco);
            // Essa parte eh O(1)
            if(copiaEntrada.multaTotal < melhorSolucao) {
                centroMelhorSolucao = centro;
                raioMelhorSolucao = raio;
                melhorSolucao = copiaEntrada.multaTotal;
            }
        }
        // Voltar a solucao pro estado inicial tem custo proporcional a O(n)
        // E portanto essa linha tem custo proporcional a O(n^2)
        while(raio > 0) {
            --raio;
            std::swap(copiaEntrada.linhaProducao[centro + raio], copiaEntrada.linhaProducao[centro - raio]);
        }
    }

    // Regerar a melhor solucao encontrada tem custo proporcional a O(n)
    for(unsigned long i = 1; i <= raioMelhorSolucao; ++i) {
        std::swap(copiaEntrada.linhaProducao[centroMelhorSolucao + i], copiaEntrada.linhaProducao[centroMelhorSolucao - i]);
    }
    copiaEntrada.multaTotal = melhorSolucao;

    return copiaEntrada;
}

solucao reverseSwap(const solucao& entrada,
        const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n);
    unsigned long inicioMelhorSolucao = 0;
    unsigned long fimMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;
    unsigned long i;
    unsigned long j;


    // Escolhemos todos os pares de inicio e fim validos e sem repeticao
    // e damos um reverse nos elementos entre esses dois, com eles inclusos.
    // O numero de pares eh proporcional a n^2, e portanto o custo de testar
    // todos os pares eh O(n^2)
    for(unsigned long inicio = 0; inicio + 1 < entrada.linhaProducao.size(); ++inicio) {
        for(unsigned long fim = inicio + 1; fim < entrada.linhaProducao.size(); ++fim) {
            i = inicio;
            j = fim;
            // Invertemos os elementos entre inicio e fim
            // Isso custa O(n), dando um total de O(n^3)
            while(i < j) {
                std::swap(copiaEntrada.linhaProducao[i], copiaEntrada.linhaProducao[j]);
                ++i;
                --j;
            }

            // Calcula o valor dessa solucao
            // Isso custa O(n), dando um total de O(n^3)
            copiaEntrada.calcula_solucao(troca_suco);

            // Essa parte eh O(1)
            if(copiaEntrada.multaTotal < melhorSolucao) {
                inicioMelhorSolucao = inicio;
                fimMelhorSolucao = fim;
                melhorSolucao = copiaEntrada.multaTotal;
            }

            // Invertemos os elementos entre o inicio e o fim novamente
            // para voltarmos ao vector original
            // Isso custa O(n), dando um custo total de O(n^3)
            i = inicio;
            j = fim;
            while(i < j) {
                std::swap(copiaEntrada.linhaProducao[i], copiaEntrada.linhaProducao[j]);
                ++i;
                --j;
            }
        }
    }

    // Regerar a melhor solucao encontrada tem custo proporcional a O(n)
    while(inicioMelhorSolucao < fimMelhorSolucao) {
        std::swap(copiaEntrada.linhaProducao[inicioMelhorSolucao], copiaEntrada.linhaProducao[fimMelhorSolucao]);
        ++inicioMelhorSolucao;
        --fimMelhorSolucao;
    }
    copiaEntrada.multaTotal = melhorSolucao;

    return copiaEntrada;
}
