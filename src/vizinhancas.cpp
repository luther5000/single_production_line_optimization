#include "vizinhancas.hpp"
#include "solucao.hpp"
#include <iostream>
#include <algorithm>
/**
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 *  Para cada par de indices i e j, i < j, trocamos o valor na posicao i com
 *  o valor na posicao j.
 * 
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
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

/** 
 * Essa vizinhanca eh gerada da seguinte forma:
 *
 * Para cada indice centro e cada inteiro r, fazemos swap dos r elementos na
 * borda do vetor mais proximos do centro com seus respectivos elementos
 * diametralmente opostos em relacao ao centro. Por exemplo
 *
 * 0 1 2 3 4 5
 *
 * Escolhendo o centro 3, para raio 1, teriamos
 *
 * 0 5 2 3 4 1
 *
 * E para raio 2
 *
 * 0 5 4 3 2 1
 *
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada A solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * @return A melhor solucao encontrada na vizinhanca.
 * */
solucao pivoSwap(const solucao& entrada,
        const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n)
    unsigned long centroMelhorSolucao = 0;
    unsigned long rMelhorSolucao = 0;
    long long melhorSolucao = entrada.multaTotal;
    const unsigned long n = entrada.linhaProducao.size();

    // testamos todos os centros validos
    // lembrando que o size() eh um unsigned, entao eh melhor so subtrair dele
    // quando houver certeza que o resultado nao dara overflow.
    for(unsigned long centro = 1; centro + 1 < n; ++centro) {
        unsigned long r = 0;

        // Nesse caso, estamos mais proximos do comeco do vetor do que do final.
        // No total, os loops dentro de ambas branchs serao executados um numero
        // de vezes proporcional a O(n^2)
        if(centro < n - centro) {
            for(r = 0; r < centro; ++r) {
                // fazemos swap dos elementos de fora para dentro para fora, em
                // direcao ao centro
                std::swap(copiaEntrada.linhaProducao[r],
                        copiaEntrada.linhaProducao[2*centro - r]);

                // O calculo do valor da solucao eh proporcional a O(n)
                // O que no total adiciona O(n^3) de custo a solucao
                copiaEntrada.calcula_solucao(troca_suco);
                // Essa parte eh O(1)
                if(copiaEntrada.multaTotal < melhorSolucao) {
                    centroMelhorSolucao = centro;
                    rMelhorSolucao = r;
                    melhorSolucao = copiaEntrada.multaTotal;
                }
            }
            // Voltar a solucao pro estado inicial tem custo proporcional a O(n)
            // E portanto essa linha tem custo proporcional a O(n^2)
            for(r = 0; r < centro; ++r) {
                std::swap(copiaEntrada.linhaProducao[r],
                        copiaEntrada.linhaProducao[2*centro - r]);
            }
        // Caso contrario, estamos mais proximos do fim do array
        } else {
            for(r = 0; r < n - centro - 1; ++r) {
                std::swap(copiaEntrada.linhaProducao[2*centro - n + 1 + r],
                        copiaEntrada.linhaProducao[n - r - 1]);

                copiaEntrada.calcula_solucao(troca_suco);
                // Essa parte eh O(1)
                if(copiaEntrada.multaTotal < melhorSolucao) {
                    centroMelhorSolucao = centro;
                    rMelhorSolucao = r;
                    melhorSolucao = copiaEntrada.multaTotal;
                }
            }
            for(r = 0; r < n - centro - 1; ++r) {
                std::swap(copiaEntrada.linhaProducao[2*centro - n + 1 + r],
                        copiaEntrada.linhaProducao[n - r - 1]);
            }
        }
    }


    // geramos novamente a melhor solucao
    // essa linha tem custo proporcional a O(n)
    if(centroMelhorSolucao < n - centroMelhorSolucao) {
        for(unsigned long r = 0; r <= rMelhorSolucao; ++r) {
            std::swap(copiaEntrada.linhaProducao[r],
                    copiaEntrada.linhaProducao[2*centroMelhorSolucao - r]);
        }
    } else {
        for(unsigned long r = 0; r <= rMelhorSolucao; ++r) {
            std::swap(copiaEntrada.linhaProducao[2*centroMelhorSolucao - n + 1 + r],
                    copiaEntrada.linhaProducao[n - r - 1]);
        }
    }
    copiaEntrada.multaTotal = melhorSolucao;

    return copiaEntrada;
}

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 *
 * Para cada par de indices, inicio e fim, invertemos a ordem dos elementos
 * entre esses dois indices, com eles inclusos.
 *
 * @note Essa vizinhanca eh varrida em O(n^3).
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao
 * @return A melhor solucao encontrada na vizinhanca.
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
 * @return A multa paga para se executar essa linha de produção.
 */
long long calculaSolucao(const list<suco_t>& linhaProducao, const vector<vector<int>>& trocaSuco) {
    long long valor = 0;
    long long tempo = 0;
    long long tempoPassado;
    long long ultimaLinha = 0;

    for (suco_t suco : linhaProducao) { //O(n)
        tempo += trocaSuco[ultimaLinha][suco.indice] +  suco.tempo;
        tempoPassado = tempo - suco.prazo;

        if (tempoPassado > 0) {
            valor += tempoPassado*suco.multa;
        }

        ultimaLinha = suco.indice;
    }

    return valor;
}

/** 
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
 * @note Essa vizinhanca eh varrida em O(n^2)
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
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

/**
 * Função que verifica para cada suco todos os possíveis locais que o suco pode ser inserido
 * e guarda o melhor vizinho obtido para retornar ele.
 *
 * Ex: Caso selecionemos 2 no vetor abaixo
 *
 * 1 2 3 4 5
 *
 * Os possíveis locais de inserção seria:
 *
 * 2 1 3 4 5
 * 1 3 2 4 5
 * 1 3 4 2 5
 * 1 3 4 5 2
 *
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 */
solucao insertSwap(const solucao& entrada, const vector<vector<int>>& troca_suco){
    long long valorMelhorProducao = entrada.multaTotal;
    long long valorLinhaAtual;

    long long indiceLocalInsercao = -1;
    suco_t sucoInserido;

    for (suco_t suco : entrada.linhaProducao){
        /* 
        * Fazemos uma cópia da linha de produção inicial sem o suco que estaremos
        * inserindo em várias posições diferentes
        */
        list<suco_t> linhaProducaoAtual;
        for (suco_t sucoCopia : entrada.linhaProducao){
            if (sucoCopia.indice != suco.indice)
                linhaProducaoAtual.push_back(sucoCopia);
        }

        /*
         * Agora iremos analisar para cada um dos sucos todas as posições
         * em que ele pode ser inserido na linha de produção.
         */
        list<suco_t>::iterator iterator = linhaProducaoAtual.begin();
        for (unsigned int i = 0; i < linhaProducaoAtual.size() + 1; ++i){
            linhaProducaoAtual.insert(iterator, suco);
            valorLinhaAtual = calculaSolucao(linhaProducaoAtual, troca_suco);  

            // Caso o valor da solução seja melhor, salvamos ele para reconstruir a solução depois
            if (valorLinhaAtual < valorMelhorProducao){
                valorMelhorProducao = valorLinhaAtual;
                indiceLocalInsercao = i;
                sucoInserido = suco;
            }
            
            --iterator;
            iterator = linhaProducaoAtual.erase(iterator);
            ++iterator;
        }
    }

    //Caso a entrada seja a melhor solução, retornamos ela
    if (indiceLocalInsercao == -1)
        return entrada;

    //Reconstruímos a solução ótima obtida pelo algoritmo
    vector<suco_t> melhorLinhaProducao(entrada.linhaProducao.size());
    melhorLinhaProducao[indiceLocalInsercao] = sucoInserido;

    unsigned int j = 0;
    for (unsigned long i = 0; i < entrada.linhaProducao.size(); ++i){
        if (entrada.linhaProducao[i].indice == sucoInserido.indice) {
            continue;
        }
        if (j == indiceLocalInsercao) {
            ++j;
            --i;
            continue;
        }

        melhorLinhaProducao[j] = entrada.linhaProducao[i];
        ++j;
    }

    return solucao(melhorLinhaProducao, valorMelhorProducao);
}

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 * 
 *  Para cada indice index, pegamos os valores [index, index + 5)
 *  e testamos todas as permutacoes desses elementos
 * 
 * @note Essa vizinhanca eh varrida em O(n^2)
 * 
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 */
solucao fiveFactorialSwap(const solucao& entrada, const vector<vector<int>>& troca_suco) {
    unsigned long indexMelhorSolucao = 0;
    vector<int> permutacaoMelhorSolucao = {0, 1, 2, 3, 4};
    long long melhorSolucao = entrada.multaTotal;

    for(unsigned long i = 0; i < entrada.linhaProducao.size() - 4; ++i) {
        // a permutacao identidade
        // iniciamos com ela e vamos ate a maior permutacao lexicografica
        // que seria {4, 3, 2, 1, 0}
        vector<int> permutacaoAtual = {0, 1, 2, 3, 4};
        while(1) {
            long long multa = 0;
            long long tempo = 0;
            long long ultimaLinha = 0;
            unsigned long j = 0;

            // Esse trecho seguinte encontra a proxima permutacao em ordem lexicografica
            // Ou sai do laco se ja estivermos na maior permutacao

            // encontramos o maior k tal que p[k] < p[k + 1]
            int k = 3;
            while(k >= 0 && permutacaoAtual[k] >= permutacaoAtual[k + 1]) {
                k--;
            }

            // se nenhum k for encontrado, estamos na maior permutacao
            // entao saia
            if(k < 0) {
                break;
            }

            // encontre o maior l tal que p[l] > p[k]
            int l = 4;
            while(permutacaoAtual[k] >= permutacaoAtual[l]) {
                l--;
            }

            // troque p[l] e p[k] de posicao
            std::swap(permutacaoAtual[k], permutacaoAtual[l]);

            // inverta os elementos a frente de k
            // isso mantem o crescimento lexicografico
            std::reverse(permutacaoAtual.begin() + k + 1, permutacaoAtual.end());

            // Calculamos a multa ate o suco i
            for(j = 0; j < i; ++j) {
                tempo +=
                    troca_suco[ultimaLinha][entrada.linhaProducao[j].indice] +
                    entrada.linhaProducao[j].tempo;

                long long tempoPassado = tempo - entrada.linhaProducao[j].prazo;

                if (tempoPassado > 0)
                    multa += tempoPassado*entrada.linhaProducao[j].multa;

                ultimaLinha = entrada.linhaProducao[i].indice + 1;
            }

            // calculamos a multa dos sucos i ate i + 4 com
            // a permutacao atual aplicada
            for(k = 0; k < 5; ++k) {
                tempo +=
                    troca_suco[ultimaLinha][entrada.linhaProducao[j + permutacaoAtual[k]].indice] +
                    entrada.linhaProducao[j + permutacaoAtual[k]].tempo;

                long long tempoPassado = tempo - entrada.linhaProducao[j + permutacaoAtual[k]].prazo;

                if (tempoPassado > 0)
                    multa += tempoPassado*entrada.linhaProducao[j + permutacaoAtual[k]].multa;

                ultimaLinha = entrada.linhaProducao[j + permutacaoAtual[k]].indice + 1;
            }

            // depois prosseguimos o calculo normalmente
            // ate o fim da linha de producao
            for(j += 5; j < entrada.linhaProducao.size(); ++j) {
                tempo +=
                    troca_suco[ultimaLinha][entrada.linhaProducao[j].indice] +
                    entrada.linhaProducao[j].tempo;

                long long tempoPassado = tempo - entrada.linhaProducao[j].prazo;

                if (tempoPassado > 0)
                    multa += tempoPassado*entrada.linhaProducao[j].multa;

                ultimaLinha = entrada.linhaProducao[i].indice + 1;
            }

            // se encontrarmos uma solucao melhor que a atual
            // salvamos ela
            if(multa < melhorSolucao) {
                indexMelhorSolucao = i;
                for(int m = 0; m < 5; ++m) {
                    permutacaoMelhorSolucao[m] = permutacaoAtual[m];
                }
                melhorSolucao = multa;
            }
        }
    }

    // construimos a melhor solucao obtida e retornamos ela
    solucao copiaEntrada = entrada;
    for(unsigned long i = 0; i < 5; ++i) {
        copiaEntrada.linhaProducao[indexMelhorSolucao + i] = 
            entrada.linhaProducao[indexMelhorSolucao + permutacaoMelhorSolucao[i]];
    }
    copiaEntrada.multaTotal = melhorSolucao;

    return copiaEntrada;

}

/**
 * Esta vizinhanca eh gerada da seguinte forma:
 * 
 *  Para cada tripla de indices i, j e k, i < j < k, trocamos
 *  os valores i, j e k de posicao. As trocas que o twoSwap
 *  varre sao excluidas
 * 
 * @note Essa vizinhanca eh varrida em O(n^4)
 * 
 * @param entrada Uma solucao inicial para ser explorada.
 * @param troca_suco A matriz que contem o custo das trocas de contexto da
 * linha de producao.
 * @return A melhor solucao encontrada na vizinhanca.
 */
solucao threeSwap(const solucao& entrada, const vector<vector<int>>& troca_suco) {
    solucao copiaEntrada = entrada; // O(n)
    unsigned long iMelhorSolucao = 0;
    unsigned long jMelhorSolucao = 0;
    unsigned long kMelhorSolucao = 0;
    int qualPermutacao = 0;
    long long melhorSolucao = entrada.multaTotal;

    // existem 6 permutacoes de 3 elementos
    // 0 1 2
    // 0 2 1
    // 1 0 2
    // 1 2 0
    // 2 0 1
    // 2 1 0
    // As 3 primeiras sao irrelevantes, pois ou geram a mesma solucao
    // Os dois seguintes sao gerados pelo twoSwap
    // Mesma coisa com a ultima
    // Logo, resta testar 1 2 0 e 2 0 1.
    for(unsigned long i = 0; i < entrada.linhaProducao.size(); ++i) {
        for(unsigned long j = i + 1; j < entrada.linhaProducao.size(); ++j) {
            for(unsigned long k = j + 1; k < entrada.linhaProducao.size(); ++k) {
                suco_t a = copiaEntrada.linhaProducao[i];
                suco_t b = copiaEntrada.linhaProducao[j];
                suco_t c = copiaEntrada.linhaProducao[k];

                // Testamos com 1 2 0
                copiaEntrada.linhaProducao[i] = b;
                copiaEntrada.linhaProducao[j] = c;
                copiaEntrada.linhaProducao[k] = a;

                copiaEntrada.calcula_solucao(troca_suco);

                // O resto do corpo da funcao eh O(1)
                if(copiaEntrada.multaTotal < melhorSolucao) {
                    iMelhorSolucao = i;
                    jMelhorSolucao = j;
                    kMelhorSolucao = k;
                    qualPermutacao = 1;
                    melhorSolucao = copiaEntrada.multaTotal;
                }

                // Testamos com 2 0 1
                copiaEntrada.linhaProducao[i] = c;
                copiaEntrada.linhaProducao[j] = a;
                copiaEntrada.linhaProducao[k] = b;

                copiaEntrada.calcula_solucao(troca_suco);

                // O resto do corpo da funcao eh O(1)
                if(copiaEntrada.multaTotal < melhorSolucao) {
                    iMelhorSolucao = i;
                    jMelhorSolucao = j;
                    kMelhorSolucao = k;
                    qualPermutacao = 2;
                    melhorSolucao = copiaEntrada.multaTotal;
                }

                copiaEntrada.linhaProducao[i] = a;
                copiaEntrada.linhaProducao[j] = b;
                copiaEntrada.linhaProducao[k] = c;
            }
        }
    }

    // reconstruimos a solucao e retornamos ela
    suco_t a = copiaEntrada.linhaProducao[iMelhorSolucao];
    suco_t b = copiaEntrada.linhaProducao[jMelhorSolucao];
    suco_t c = copiaEntrada.linhaProducao[kMelhorSolucao];

    if(qualPermutacao == 0) {
        return copiaEntrada;
    } else if(qualPermutacao == 1) {
        // 1 2 0
        copiaEntrada.linhaProducao[iMelhorSolucao] = b;
        copiaEntrada.linhaProducao[jMelhorSolucao] = c;
        copiaEntrada.linhaProducao[kMelhorSolucao] = a;

        copiaEntrada.multaTotal = melhorSolucao;

        return copiaEntrada;
    } else {
        // 2 0 1
        copiaEntrada.linhaProducao[iMelhorSolucao] = c;
        copiaEntrada.linhaProducao[jMelhorSolucao] = a;
        copiaEntrada.linhaProducao[kMelhorSolucao] = b;

        copiaEntrada.multaTotal = melhorSolucao;

        return copiaEntrada;
    }

}