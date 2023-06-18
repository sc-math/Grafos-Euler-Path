#ifndef __GRAFO_MATRIZ_H
#define __GRAFO_MATRIZ_H

#include <stdbool.h>

typedef struct grafo{
    int numVertex;
    int numEdge;
    int **adj;
}Graph;

int **adjMatrix(int, int);

Graph *createGraph (int);

void addEdge(Graph*, int, int);

void removeEdge(Graph*, int, int);

void printGraph(Graph*);

int vertexDegree(Graph*, int);

#endif