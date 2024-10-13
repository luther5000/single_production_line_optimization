#include "instancia_problema.hpp"

instancia_problema::instancia_problema(const string& endereco) {
    ifstream file;
    file.open(endereco, ios::in);

    if(!file.is_open()) {
        perror("Erro");
    }

    size = 0;
    file >> size;

    sucos.resize(size);

    for (int i = 0; i < size; ++i) {
        sucos[i].indice = i;
        file >> sucos[i].tempo;
    }

    for (int i = 0; i < size; ++i)
        file >> sucos[i].prazo;

    for (int i = 0; i <size; ++i)
        file >> sucos[i].multa;

    trocaSuco.resize(size + 1);

    for (int i = 0; i < size + 1; ++i) {
        trocaSuco[i].resize(size);
        for (int j = 0; j < size; ++j) {
            file >> trocaSuco[i][j];
        }
    }

    file.close();
}

void instancia_problema::exibe() const {
    printf("Valores de entrada:\n");
    printf(" Indice: Tempo   Prazo   Multa\n");
    for(suco_t cs: sucos) {
        printf("%7lld: %7lld %7lld %7lld\n",
                cs.indice,
                cs.tempo,
                cs.prazo,
                cs.multa);
    }
    printf("\n");
}
