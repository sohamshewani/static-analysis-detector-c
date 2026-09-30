#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_builder.h"

// Analyzer interface
void detect_dead_code_and_memory_leaks(Graph* graph);

#endif // ANALYZER_H
