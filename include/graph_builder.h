#ifndef GRAPH_BUILDER_H
#define GRAPH_BUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

// GraphNode and Graph structures
typedef struct GraphNode {
    int id;
    Token* tokens;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    GraphNode* head;
} Graph;

// GraphBuilder interface
Graph* build_graph(TokenList* tokens);

#endif // GRAPH_BUILDER_H
