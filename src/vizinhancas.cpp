#include "vizinhancas.hpp"
#include "solucao.hpp"
/*
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 *  Para cada par de indices i e j, i < j, trocamos o valor na posicao i com
 *  o valor na posicao j.
 * 
 * Essa vizinhaca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return {@code solucao} Contendo a melhor solucao encontrada na vizinhanca.
 * */
solucao twoSwap(const solucao& entrada,
        const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n)
    unsigned long iMelhorSolucao = 0;
    unsigned long jMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;

    // O(n^2)
    for(unsigned long i = 0; i + 1 < entrada.linhaProducao.size(); ++i) {
        for(unsigned long j = i + 1; j < entrada.linhaProducao.size(); ++j) {
            std::swap(copiaEntrada.linhaProducao[i],
                    copiaEntrada.linhaProducao[j]);

            // Calcula solucao custa O(n)
            // Como eh realizad O(n^2) vezes, o custo total
            // eh O(n^3)
            // Uma otimizacao possivel eh calcular os valores e salvar em um
            // vetor. Depois, eh necessario apenas calcular a partir da ultima
            // alteracao do vetor. Isso nao melhora a complexidade, mas torna
            // o codigo mais eficiente.
            copiaEntrada.calcula_solucao(troca_suco);

            // O resto do corpo da funcao eh O(1)
            if(copiaEntrada.multaTotal < melhorSolucao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                melhorSolucao = copiaEntrada.multaTotal;
            }

            // Desfaz o swap
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
// 
/* 
 * Essa vizinhanca eh gerada da seguinte forma:
 *
 * Para cada indice centro e cada inteiro raio, que nao cause OutOfBounds
 * "Giramos" os elementos ao redor do centro, ou seja, fazemos swap de elemen-
 * tos diametralmente opostos. Por exemplo
 *
 * 0 1 2 3 4 5
 *
 * Escolhendo o centro 3, para raio 1, teriamos
 *
 * 0 1 4 3 2 5
 *
 * E para raio 2
 *
 * 0 5 4 3 2 1
 *
 * Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada A solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * @return {@code solucao} Contendo a melhor solucao encontrada na vizinhanca.
 * */
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

/*
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 * Para cada par de indices, inicio e fim, invertemos a ordem dos elementos
 * entre esses dois indices, com eles inclusos.
 *
 * Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao
 * @return {@code solucao} Contendo a melhor solucao encontrada na vizinhanca.
 * */
solucao reverseSwap(const solucao& entrada,
        const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n);
    unsigned long inicioMelhorSolucao = 0;
    unsigned long fimMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;
    unsigned long i;
    unsigned long j;


    // Escolhemos todos os pares de inicio e fim, inicio < fim
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

/**
 * Função que calcula o valor de uma solução a partir de uma list ao invés
 * de um vector.
 * @param linhaProducao Contém a ordem dos sucos a serem produzidos.
 * @param trocaSuco O tempo necessário para trocar os sucos de lugar.
 * @return {@code long long} contendo a multa paga para se executar essa linha de produção.
 */
long long calculaSolucao(const list<suco_t>& linhaProducao, const vector<vector<int>>& trocaSuco) {
    long long valor = 0;
    long long tempo = 0;
    long long tempoPassado;
    long long ultimaLinha = 0;

    for (suco_t suco : linhaProducao) { //O(n)
        if (suco.indice == linhaProducao.back().indice)
            break;

        tempo += trocaSuco[ultimaLinha][suco.indice] +  suco.tempo;
        tempoPassado = tempo - suco.prazo;

        if (tempoPassado > 0) {
            valor += tempoPassado*suco.multa;
        }

        ultimaLinha = suco.indice;
    }

    return valor;
}

/*
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 * Para cada inteiro shift, 0 < shift < n, onde n eh o tamanho da linha de
 * produco, faz a linha de producao ir de
 *
 * 0, 1, 2, ..., n
 *
 * para
 *
 * 0 + shift, 1 + shift, 2 + shift, ..., n + shift
 *
 * Com todos esses valores tomados modulo n.
 *
 * Essa vizinhanca eh varrida em O(n^2)
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return {@code solucao} Contendo a melhor solucao encontrada na vizinhanca.
 * */
solucao rotateSwap(const solucao& entrada, const vector<vector<int>>& troca_suco) {
    unsigned long shiftMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;
    long long n = entrada.linhaProducao.size();

    // Esse laco vai rodar n - 1 vezes
    for(unsigned long shift = 1; shift < entrada.linhaProducao.size(); ++shift) {

        long long multa = 0;
        long long tempo = 0;
        long long ultimaLinha = 0;

        // calculamos o valor da solucao que comeca em shift ao inves de 0
        // Isso custa O(n), gerando um custo total de O(n^2)
        for (unsigned long i = 0; i < entrada.linhaProducao.size(); ++i) {
            tempo += 
                troca_suco[ultimaLinha][entrada.linhaProducao[(i + shift) % n].indice] +
                entrada.linhaProducao[(i + shift) % n].tempo;

            long long tempoPassado = tempo - entrada.linhaProducao[(i + shift) % n].prazo;

            if (tempoPassado > 0)
                multa += tempoPassado*entrada.linhaProducao[(i + shift) % n].multa;

            ultimaLinha = entrada.linhaProducao[(i + shift) % n].indice + 1;
        }

        // Se essa solucao eh melhor que a obtida ate o momento, a atualizamos
        if(multa < melhorSolucao) {
            shiftMelhorSolucao = shift;
            melhorSolucao = multa;
        }
    }

    solucao copiaEntrada;

    copiaEntrada.linhaProducao.resize(n);

    // usamos o melhor valor de shift encontrado para gerar a solucao otima
    for(int i = 0; i < n; ++i) {
        copiaEntrada.linhaProducao[i] = entrada.linhaProducao[(i + shiftMelhorSolucao) % n];
    }
    copiaEntrada.multaTotal = melhorSolucao;

    return copiaEntrada;
}
