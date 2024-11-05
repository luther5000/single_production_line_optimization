#include "vizinhancas.hpp"
#include "solucao.hpp"
#include "customTypes.hpp"

void twoSwap(solucao &entrada, const instancia_problema &i_problema) {
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;
    llong melhorSolucao = entrada.multaTotal;


    for(ulong i = 0; i + 1 < i_problema.size; ++i) {
        for(ulong j = i + 1; j < i_problema.size; ++j) {

            // Realiza a simulação do swap entre i e j e calcula o valor
            // da solução caso ele fosse realizado.
            llong solucaoAtual = entrada.simula_solucao_two_swap(i, j);

            if(solucaoAtual < melhorSolucao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                melhorSolucao = solucaoAtual;
            }
        }
    }

    entrada.calcula_solucao_two_swap(iMelhorSolucao, jMelhorSolucao);
}

void opt(solucao &entrada, const instancia_problema &i_problema) {
    llong valorMelhorProducao = entrada.multaTotal;
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;

    for (ulong i = 0; i < i_problema.size; ++i) {
        for (ulong j = i + 3; j < i_problema.size; ++j) {
            llong solucaoAtual = entrada.simula_solucao_opt(i, j);

            if (solucaoAtual < valorMelhorProducao) {
                iMelhorSolucao = i;
                jMelhorSolucao = j;
                valorMelhorProducao = solucaoAtual;
            }
        }
    }

    entrada.calcula_solucao_opt(iMelhorSolucao, jMelhorSolucao);
}

void reinsertion(solucao &entrada, const instancia_problema &i_problema){
    llong valorMelhorProducao = entrada.multaTotal;
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;

    for (ulong i = 0; i < i_problema.size; ++i) {
        for (ulong j = i + 2; j < i_problema.size; ++j) {

        }
    }
}




/*solucao reverseSwap(const solucao& entrada, const prepararLinha& troca_suco) {
    vector<suco_t> cLinhaProducao = entrada.linhaProducao; // O(n);
    ulong inicioMelhorSolucao = 0;
    ulong fimMelhorSolucao = 0;
    llong melhorSolucao = entrada.multaTotal;
    const ulong n = entrada.linhaProducao.size();

    // Escolhemos todos os pares de inicio e fim, inicio < fim
    // e damos um reverse nos elementos entre esses dois, com eles inclusos.
    // O numero de pares eh proporcional a n^2, e portanto o custo de testar
    // todos os pares eh O(n^2)
    for(ulong inicio = 0; inicio + 1 < n; ++inicio) {
        for(ulong fim = inicio + 1; fim < n; ++fim) {
            ulong i = inicio;
            ulong j = fim;

            // Invertemos os elementos entre inicio e fim
            // Isso custa O(n), dando um total de O(n^3)
            while(i < j) {
                std::swap(cLinhaProducao[i], cLinhaProducao[j]);
                ++i;
                --j;
            }

            // Calcula o valor dessa solucao
            // Isso custa O(n), dando um total de O(n^3)
            solucao aux(cLinhaProducao, troca_suco);

            // Essa parte eh O(1)
            if(aux.multaTotal < melhorSolucao) {
                inicioMelhorSolucao = inicio;
                fimMelhorSolucao = fim;
                melhorSolucao = aux.multaTotal;
            }

            // Invertemos os elementos entre o inicio e o fim novamente
            // para voltarmos ao vector original
            // Isso custa O(n), dando um custo total de O(n^3)
            i = inicio;
            j = fim;
            while(i < j) {
                std::swap(cLinhaProducao[i], cLinhaProducao[j]);
                ++i;
                --j;
            }
        }
    }

    // Regerar a melhor solucao encontrada tem custo proporcional a O(n)
    while(inicioMelhorSolucao < fimMelhorSolucao) {
        std::swap(cLinhaProducao[inicioMelhorSolucao],
                  cLinhaProducao[fimMelhorSolucao]);
        ++inicioMelhorSolucao;
        --fimMelhorSolucao;
    }

    return solucao(cLinhaProducao, melhorSolucao);
}


solucao fiveFactorialSwap(const solucao& entrada, const prepararLinha& troca_suco) {
    ulong indexMelhorSolucao = 0;
    vector<int> permutacaoMelhorSolucao = {0, 1, 2, 3, 4};
    llong melhorSolucao = entrada.multaTotal;

    for(ulong i = 0; i + 4 < entrada.linhaProducao.size(); ++i) {
        // a permutacao identidade
        // iniciamos com ela e vamos ate a maior permutacao lexicografica
        // que seria {4, 3, 2, 1, 0}
        vector<int> permutacaoAtual = {0, 1, 2, 3, 4};
        while(1) {
            llong multa = 0;
            llong tempo = 0;
            llong ultimaLinha = 0;
            ulong j = 0;

            // Esse trecho seguinte encontra a proxima permutacao em ordem
            // lexicografica ou sai do laco se ja estivermos na maior permutacao

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
            std::reverse(permutacaoAtual.begin() + k+1, permutacaoAtual.end());

            // Calculamos a multa ate o suco i
            for(j = 0; j < i; ++j) {
                suco_t suco_atual = entrada.linhaProducao[j];

                tempo += troca_suco[ultimaLinha][suco_atual.indice] +
                         suco_atual.tempo;

                llong tempoPassado = tempo - suco_atual.prazo;

                if (tempoPassado > 0)
                    multa += tempoPassado*suco_atual.multa;

                ultimaLinha = suco_atual.indice + 1;
            }

            // calculamos a multa dos sucos i ate i + 4 com
            // a permutacao atual aplicada
            for(k = 0; k < 5; ++k) {
                ulong nIndice = j + permutacaoAtual[k];
                suco_t suco_atual = entrada.linhaProducao[nIndice];

                tempo += troca_suco[ultimaLinha][suco_atual.indice] +
                         suco_atual.tempo;

                llong tempoPassado = tempo - suco_atual.prazo;

                if (tempoPassado > 0)
                    multa += tempoPassado*suco_atual.multa;

                ultimaLinha = suco_atual.indice + 1;
            }

            // depois prosseguimos o calculo normalmente
            // ate o fim da linha de producao
            for(j += 5; j < entrada.linhaProducao.size(); ++j) {
                suco_t suco_atual = entrada.linhaProducao[j];

                tempo += troca_suco[ultimaLinha][suco_atual.indice] +
                         suco_atual.tempo;

                llong tempoPassado = tempo - suco_atual.prazo;

                if (tempoPassado > 0)
                    multa += tempoPassado*suco_atual.multa;

                ultimaLinha = suco_atual.indice + 1;
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
    for(ulong i = 0; i < 5; ++i) {
        copiaEntrada.linhaProducao[indexMelhorSolucao + i] =
            entrada.linhaProducao[indexMelhorSolucao + permutacaoMelhorSolucao[i]];
    }
    copiaEntrada.multaTotal = melhorSolucao;

    return copiaEntrada;
}

solucao threeSwap(const solucao& entrada, const prepararLinha& troca_suco) {
    solucao copiaEntrada = entrada; // O(n)
    ulong iMelhorSolucao = 0;
    ulong jMelhorSolucao = 0;
    ulong kMelhorSolucao = 0;
    int qualPermutacao = 0;
    llong melhorSolucao = entrada.multaTotal;
    ulong n = entrada.linhaProducao.size();

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
    for(ulong i = 0; i < n; ++i) {
        for(ulong j = i + 1; j < n; ++j) {
            for(ulong k = j + 1; k < n; ++k) {
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

long long calculaSolucao(const list<suco_t>& linhaProducao, const prepararLinha& trocaSuco) {
    llong valor = 0;
    llong tempo = 0;
    llong tempoPassado;
    llong ultimaLinha = 0;

    for (suco_t suco : linhaProducao) { //O(n)
        tempo += trocaSuco[ultimaLinha][suco.indice] +  suco.tempo;
        tempoPassado = tempo - suco.prazo;

        if (tempoPassado > 0) {
            valor += tempoPassado*suco.multa;
        }

        ultimaLinha = suco.indice;
    }

    return valor;
}*/
