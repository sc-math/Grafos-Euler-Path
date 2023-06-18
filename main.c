#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grafo.h"

int findFirstVertex();
bool isBridge(int v, int w);
void fleuryAlgorithm(int v);
bool eulerianCheck();
void addEulerPath(int vertex);
void euler();

Graph *graph;
int *eulerPath;
int eulerPathIterator = 0;

int main()
{
    /**
     * Input das variaveis n e m para criação do Grafo
    */
    int n, m;

    scanf("%d %d", &n, &m);

    graph = createGraph(n);

    /**
     * Input das arestas do grafo
    */
    int a, b;
    for(int i = 0; i < m; i ++){
        
        setbuf(stdin, NULL);
        scanf("%d %d", &a, &b);

        addEdge(graph, a-1, b-1);
    }

    /**
     * Print das Informações
    */
    printGraph(graph);


    /**
     * Aloca o array que guardará o Percurso de Euler
    */
    eulerPath = calloc(graph->numEdge, sizeof(int));


    /**
     * Chama a função Euler
    */
    euler();

    return 0;
}

/**
 * Busca o vertice inicial
 * returna um vertice impar caso tenha
 * se todos os vertices forem pares, retorna 0
*/
int findFirstVertex(){

    for(int i = 0; i < graph->numVertex; i++){

        if(vertexDegree(graph, i) % 2 != 0) //Verifica se o vertice i é impar, se for retorne-o
            return i;
    }

    return 0;
}

/**
 * Verifica se a aresta (v,w) forma uma ponte
*/
bool isBridge(int v, int w){

    int degree = 0;

    if(vertexDegree(graph, w) > 1) //Se o grau do vertice w for > 1, a aresta (v,w) não é ponte
        return false;
    
    return true;
}

/**
 * Algoritmo de Fleury
*/
void fleuryAlgorithm(int v){
    
    //Recebe o numero de arestas do Grafo
    int edgeNum = graph->numEdge;

    //Faz a busca por vertices adjacentes ao vertice v
    for(int u = 0; u < graph->numVertex; u++){
        if(graph->adj[v][u] == 1){

            /**
             * Verifica se a aresta (v,u) não é ponte ou se é a única opção
             * adiciona o vertice u no caminho de euler e remove a aresta (v,u)
             * avança na chamada recursiva da função fleury
             */
            if(edgeNum <= 1 || !isBridge(v, u)){

                addEulerPath(u);

                removeEdge(graph, v, u);

                fleuryAlgorithm(u);
            }
        }
    }
}

/**
 * Verifica se o grafo é Euleriano ou Semi-Euleriano
*/
bool eulerianCheck(){

    int oddVertex = 0;
    int degree;

    //Verifica o grau de todos os vertices do grafo
    for(int i = 0; i < graph->numVertex; i++){

        degree = vertexDegree(graph, i);

        if(degree == 1) //Retorna false se encontrar um vertice de grau 1
            return false;
        else if(degree % 2 != 0){
            oddVertex++;
        }
    }

    //Retorna true se o grafo tiver todos os vertices pares ou exatamente 2 vertices impares
    if(oddVertex == 0 || oddVertex == 2)
        return true;

    return false;
}


/**
 * Função que adiciona o vertice no percurso de Euler
*/
void addEulerPath(int vertex){
    eulerPath[eulerPathIterator] = vertex+1;
    eulerPathIterator++;
}

/**
 * Função Principal para achar o caminho de Euler
*/
void euler(){

    //Faz a verificação do grafo
    if(!eulerianCheck()){
        printf("IMPOSSIVEL");
        return;
    }
        
    int inicialVertex = findFirstVertex(); //Procura o primeiro vertice para o algoritmo

    addEulerPath(inicialVertex); //Adiciona ele no Percurso de euler

    fleuryAlgorithm(inicialVertex); //Chama o Algoritmo de Fleury

    //Imprime o Percurso de Euler
    if(eulerPath[0] != eulerPath[eulerPathIterator-1])
        printf("Percurso de Euler (Grafo Semi-Euleriano): \n");
    else
        printf("Percurso de Euler: \n");

    for(int i = 0; i < eulerPathIterator; i++)
        printf("%d ", eulerPath[i]);
}

