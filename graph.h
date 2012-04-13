#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

struct graph {
    list_p * edge_list;
    long int nedges;
    long int nvertices;
};

typedef struct graph * graph_p;
    
graph_p create_graph(long int size);

void destroy_graph(graph_p graph);

/* Read in values from a file,
 * First line is: nvertices nedges (seperator is whitespace) */
graph_p  graph_from_file(char * filename, bool directed);

void insert_edge(graph_p graph, long int, long int, bool); 

int vertex_length(graph_p g, long int n);

#endif
