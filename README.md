# Grafos Euler Path

Repositório da Atividade realizada na disciplina de Teoria de Grafos.

## Problema

Dada uma entrada contendo informações de quantas ruas uma cidade tem, precisamos verificar se há como visitar todos as ruas sem passar por ruas que já foram visitadas.

## O Código

- O código da Implementação do Grafo está em Grafo.c e as funções para verificar o Tour de Euler está implementado no arquivo Main.c
- O arquivo Raizes.pdf é o pdf que contem o problema.

## Exemplos

### Exemplo 1:

![Grafo 1](https://raw.githubusercontent.com/sc-math/Grafos-Euler-Path/main/imgs/grafo-1.png)

É um grafo Euleriano então possui o seguinte Tour de Euler: 1 > 2 > 3 > 5 > 4 > 2 > 6 > 3 > 1

![Resultado do Grafo 1 no programa](https://raw.githubusercontent.com/sc-math/Grafos-Euler-Path/main/imgs/grafo-1-result.png)

### Exemplo 2:

![Grafo 2](https://raw.githubusercontent.com/sc-math/Grafos-Euler-Path/main/imgs/grafo-2.png)

É um grafo Semi-Euleriano, então é possivel visitar todas ruas mas no fim do percurso não estará na rua inicial: 1 > 2 > 3 > 1 > 6 > 5 > 4 > 3

![Resultado do Grafo 2 no programa](https://raw.githubusercontent.com/sc-math/Grafos-Euler-Path/main/imgs/grafo-2-result.png)

### Exemplo 3:

![Grafo 3](https://raw.githubusercontent.com/sc-math/Grafos-Euler-Path/main/imgs/grafo-3.png)

Não é um grafo Euleriano então não é possivel encontrar um Tour de Euler e o programa retorna "IMPOSSIVEL".

![Resultado do Grafo 3 no programa](https://raw.githubusercontent.com/sc-math/Grafos-Euler-Path/main/imgs/grafo-3-result.png)
