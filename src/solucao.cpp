#include "solucao.hpp"

#include <algorithm>

solucao::solucao(const solucao *solucao): i_problema(solucao->i_problema) {
    this->linhaProducao = solucao->linhaProducao;
    this->multaTotal = solucao->multaTotal;
}

solucao::solucao(const instancia_problema &i_problema): i_problema(i_problema) {
    this->multaTotal = 0;
    this->linhaProducao.resize(i_problema.size);
    this->solucaoInfo.resize(i_problema.size);
}

void solucao::calcula_solucao_inicial() {
    llong tempo = 0;
    this->multaTotal = 0;
    llong ultimoLinha = 0;


    for (ulong i = 0; i < i_problema.size; ++i) {
        tempo += i_problema.trocaSuco[ultimoLinha][linhaProducao[i]]
                 + i_problema.sucos[linhaProducao[i]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i]].prazo;

        if (tempoPassado > 0)
            multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i]].multa;

        solucaoInfo[i].multaAtual = multaTotal;
        solucaoInfo[i].tempoDecorrido = tempo;

        ultimoLinha = linhaProducao[i] + 1;
    }
}

llong solucao::simula_solucao_two_swap(const ulong i, const ulong j) const {
    llong tempo = 0;
    llong multaAtual = 0;
    llong ultimaLinha = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaAtual = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    }

    for (ulong k = i; k < i_problema.size; ++k) {
        ulong l = k;

        if (k == i)
            l = j;

        if (k == j)
            l = i;

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[l]]
                 + i_problema.sucos[linhaProducao[l]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[l]].prazo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[l]].multa;

        ultimaLinha = linhaProducao[l] + 1;
    }

    return multaAtual;
}

void solucao::calcula_solucao_two_swap(ulong i,const ulong j) {
    if (i == j && i == 0)
        return;

    llong tempo = 0;
    llong ultimaLinha = 0;
    multaTotal = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaTotal = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    } 

    swap(linhaProducao[i], linhaProducao[j]);

    for (; i < i_problema.size; ++i) {

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i]]
                 + i_problema.sucos[linhaProducao[i]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i]].prazo;

        if (tempoPassado > 0)
            this->multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i]].multa;

        solucaoInfo[i].multaAtual = multaTotal;
        solucaoInfo[i].tempoDecorrido = tempo;

        ultimaLinha = linhaProducao[i] + 1;
    }
}

llong solucao::simula_solucao_opt(ulong i, ulong j) const {
    llong tempo = 0;
    llong multaAtual = 0;
    llong ultimaLinha = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaAtual = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    }

    ulong l = j;
    for (ulong k = i; k < i_problema.size; ++k) {
        ulong m = k;

        if (k >= i && k <= j) {
            m = l;
            --l;
        }

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[m]]
                 + i_problema.sucos[linhaProducao[m]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[m]].prazo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[m]].multa;

        ultimaLinha = linhaProducao[m] + 1;
    }

    return multaAtual;
}

void solucao::calcula_solucao_opt(ulong i, ulong j) {
    if (i == j && i == 0)
        return;

    llong tempo = 0;
    multaTotal = 0;
    llong ultimaLinha = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaTotal = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    }

    reverse(linhaProducao.begin() + i, linhaProducao.begin() + j+1);

    for (; i < i_problema.size; ++i) {
        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i]]
                 + i_problema.sucos[linhaProducao[i]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i]].prazo;

        if (tempoPassado > 0)
            this->multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i]].multa;

        solucaoInfo[i].multaAtual = multaTotal;
        solucaoInfo[i].tempoDecorrido = tempo;

        ultimaLinha = linhaProducao[i] + 1;
    }
}

/*llong solucao::simula_solucao_reinsertion(ulong i, ulong j) const {
    llong tempo = 0;
    llong multaAtual = 0;
    llong ultimaLinha = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaAtual = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    }

    for (ulong k = i; k < i_problema.size; ++k) {
        if (k == i)
            continue;

        if (k == j + 1) {
            tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i]]
                 + i_problema.sucos[linhaProducao[i]].tempo;
            llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i]].prazo;

            if (tempoPassado > 0)
                multaAtual += tempoPassado * i_problema.sucos[linhaProducao[i]].multa;

            ultimaLinha = linhaProducao[i] + 1;
        }

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[k]]
                 + i_problema.sucos[linhaProducao[k]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[k]].tempo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[k]].multa;

        ultimaLinha = linhaProducao[k] + 1;
    }

    if (j == i_problema.size - 1) {
        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i]]
                 + i_problema.sucos[linhaProducao[i]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i]].tempo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[i]].multa;
    }
    return multaAtual;
}*/

llong solucao::simula_solucao_reinsertion(ulong i, ulong j, ulong l) const {
    llong tempo = 0;
    llong multaAtual = 0;
    llong ultimaLinha = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaAtual = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    }

    for (ulong k = i; k < i_problema.size; ++k) {
        if (k == i) {
            k += l-1;
            continue;
        }

        if (k == j + 1) {
            for (uint m = 0; m < l; ++m) {
                tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i + m]]
                     + i_problema.sucos[linhaProducao[i + m]].tempo;
                llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i + m]].prazo;

                if (tempoPassado > 0)
                    multaAtual += tempoPassado * i_problema.sucos[linhaProducao[i + m]].multa;

                ultimaLinha = linhaProducao[i + m] + 1;
            }
        }

        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[k]]
                 + i_problema.sucos[linhaProducao[k]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[k]].tempo;

        if (tempoPassado > 0)
            multaAtual += tempoPassado * i_problema.sucos[linhaProducao[k]].multa;

        ultimaLinha = linhaProducao[k] + 1;
    }

    if (j == i_problema.size - 1) {
        for (uint m = 0; m < l; ++m) {
            tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i + m]]
                 + i_problema.sucos[linhaProducao[i + m]].tempo;
            llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i + m]].prazo;

            if (tempoPassado > 0)
                multaAtual += tempoPassado * i_problema.sucos[linhaProducao[i + m]].multa;

            ultimaLinha = linhaProducao[i + m] + 1;
        }
    }
    return multaAtual;
}

void solucao::calcula_solucao_reinsertion(ulong i, ulong j, ulong l) {
    if (i == j && i == 0)
        return;

    llong tempo = 0;
    multaTotal = 0;
    llong ultimaLinha = 0;

    if (i > 0) {
        tempo = solucaoInfo[i-1].tempoDecorrido;
        multaTotal = solucaoInfo[i-1].multaAtual;
        ultimaLinha = linhaProducao[i-1] + 1;
    }

    for (uint m = 0; m < l; ++m) {
        uint s = linhaProducao[i + m];
        linhaProducao.erase(linhaProducao.begin() + i + m);
        linhaProducao.insert(linhaProducao.begin() + j + m, s);
    }

    for (; i < i_problema.size; ++i) {
        tempo += i_problema.trocaSuco[ultimaLinha][linhaProducao[i]]
                 + i_problema.sucos[linhaProducao[i]].tempo;
        llong tempoPassado = tempo - i_problema.sucos[linhaProducao[i]].prazo;

        if (tempoPassado > 0)
            this->multaTotal += tempoPassado * i_problema.sucos[linhaProducao[i]].multa;

        solucaoInfo[i].multaAtual = multaTotal;
        solucaoInfo[i].tempoDecorrido = tempo;

        ultimaLinha = linhaProducao[i] + 1;
    }
}

solucao* solucao::criaCopia() {
    return new solucao(*this);
}

void solucao::exibe(const instancia_problema &i_problema) const{
    printf("Valores da solucao:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(ulong i = 0; i < i_problema.size; ++i) {
        printf("%7u: %7lld %7lld %7lld\n",
            linhaProducao[i],
            i_problema.sucos[linhaProducao[i]].tempo,
            i_problema.sucos[linhaProducao[i]].prazo,
            i_problema.sucos[linhaProducao[i]].multa);
    }
    printf("\n");
    printf("Valor da solucao: %lld\n\n", this->multaTotal);
}

void solucao::exibeReduzido() {
    printf("Valor da solucao: %lld\n", this->multaTotal);
}
