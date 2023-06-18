#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "grafo.h"

/**
 * Funções Básicas de Criação de Grafo,
 * Inserção de Arestas,
 * Remover Arestas,
 * Imprime Grafo
 * Verifica Grau
*/

int **adjMatrix(int order, int value){
    int i, j;
    int **m = malloc(order * sizeof(int *));
    for(i = 0; i < order; i++){
        m[i] = malloc(order * sizeof(int *));
        for(j = 0; j < order; j++){
            m[i][j] = value;
        }
    }

    return m;
}

Graph *createGraph (int order){
    Graph *G = malloc(sizeof(Graph));
    G->numVertex = order;
    G->numEdge = 0;
    G->adj = adjMatrix(order, 0);
    return G;
}

void addEdge(Graph *G, int v, int w){
    if( v != w && G->adj[v][w] == 0){
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
        G->numEdge++;
    }
}

void removeEdge(Graph *G, int v, int w){
    if(G->adj[v][w] == 1){
        G->numEdge--;
        G->adj[v][w] = 0;
        G->adj[w][v] = 0;
    }
}

void printGraph(Graph *G){
    int v, w;
    printf("\nGraph\nV:%d\tE:%d\n", G->numVertex, G->numEdge);
    for(v = 0; v < G->numVertex; v++){
        printf("%2d:", v+1);
        for(w = 0; w < G->numVertex; w++){
            if(G->adj[v][w] == 1)
                printf(" %2d", w+1);
        }
        printf("\n");
    }
    printf("\n");
}

int vertexDegree(Graph *G, int vertex){
    int degree = 0;
    for(int i = 0; i < G->numVertex; i++){
        if(G->adj[vertex][i] == 1)
            degree++;
    }

    return degree;
}
