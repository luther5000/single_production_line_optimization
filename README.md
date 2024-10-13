# Projeto final da disciplina de Análise e Projeto de Algoritmos

## Equipe

- Michel Diniz Medeiros - 20220054928
- Lutero Lima Goulart - 20220005816

## Compilando

A compilação do projeto pode ser feita gerando um `Makefile` ou um `build.ninja` na raiz do projeto a partir do `CMakeLists.txt`. Para isso, basta executar o `cmake` na raiz do projeto:

- Para gerar um `Makefile`
    ```
    cmake .
    ```

- Para gerar um `build.ninja` (Requer o pacote `ninja-build`)
    ```
    cmake -G Ninja .
    ```

Após isso, basta executar um comando `make` ou `ninja` na raiz do projeto, dependendo da forma escolhida.

## Funcionamento

Existem 3 formas de executar o programa:

- Passando nenhum argumento:

    ```
    ./bin/projeto_apa.exe
    ```

    Este modo executará cada uma das instâncias em `instancias/` que possuem 60 elementos, com o *ILS* sendo executado 20 vezes com um fator de 15. Apenas o valor de cada solução é exibido na tela.

- Passando apenas um argumento:

    ```
    ./bin/projeto_apa.exe [<instancia>]
    ```

    Este modo executará a instância passada como argumento apenas vez, com o *ILS* sendo executado com um fator de 20. Tanto o valor como a lista de sucos são exibidos na tela.

- Passando dois argumentos:

    ```
    ./bin/projeto_apa.exe [<instancia>] [<num>]
    ```

    Este modo executará a instância passada *num* vezes, com o *ILS* sendo executado com um fator de 20. Ao final, o valor médio das soluções é gerado, bem como o tempo médio de execução. O valor e a lista de sucos são exibidos uma vez para cada solução gerada, em um total de *num* vezes.

Passar mais argumentos do que o necessário gera uma mensagem de erro. Ademais, nenhum tratamento de entrada foi feito.
