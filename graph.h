#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdbool.h>


struct edge_node {
    DATATYPE data;
    struct edge_node * next;
};
typedef struct edge_node edge_node;
struct graph {
     edge_node  ** vertex_array;  //  {(a,b),(b,c),(b,d)...}
    long int * vertex_degree_array; // {(a,1),(b,2)...}
    long int nedges; // {(4)}
    long int nvertices; // {(8)} *sparse
    bool directed; //{ (a,b)(b,a), (b,c)(...}
};

typedef struct graph * graph_p;

enum state{
    undiscovered, 
    discovered, 
    processed
    };

    
graph_p create_graph(long int size, bool directed);

void destroy_graph(graph_p graph);

/* Read in values from a file,
 * First line is: nvertices nedges (seperator is whitespace) */
graph_p  graph_from_file(char * filename, bool directed);

void insert_edge(graph_p, DATATYPE, DATATYPE, bool); 

long int vertex_length(graph_p g, DATATYPE n);

void bfs(graph_p, DATATYPE);

void process_vertex_early(DATATYPE v);
void process_vertex_late(DATATYPE v);
void process_edge(DATATYPE x, DATATYPE v);

#endif
