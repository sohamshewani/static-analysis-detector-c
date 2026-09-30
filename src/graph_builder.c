#include "graph_builder.h"
#include <stdlib.h>

Graph* build_graph(TokenList* tokens) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->head = NULL;

    for (int i = 0; i < tokens->size; i++) {
        GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
        node->id = i;
        node->tokens = tokens->tokens[i].value;
        node->next = graph->head;
        graph->head = node;
    }
    return graph;
}
