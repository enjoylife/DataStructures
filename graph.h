#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef int * degree_p;
struct graph {
    list_p * edge_list;
    degree_p degrees;
    long int nedges;
    long int nvertices;
};

typedef struct graph * graph_p;
    

graph_p create_graph(long int size);
void destroy_graph(graph_p graph);
/* Read in values from a file,
 * First line is: nvertices nedges (seperator is whitespace) */
void  fread_into_graph(char * filename, bool directed);

void insert_edge(list_p *, long int, long int, bool); 



#endif
