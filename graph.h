#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdbool.h>


struct edge_node {
    long int data;
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

#define undiscovered 0 
#define discovered  1
#define processed 2

    
graph_p create_graph(long int size, bool directed);

void destroy_graph(graph_p graph);

/* Read in values from a file,
 * First line is: nvertices nedges (seperator is whitespace) */
graph_p  graph_from_file(char * filename, bool directed);

void insert_edge(graph_p, long int, long int, bool); 

long int vertex_length(graph_p g, long int n);

void bfs(graph_p, long int);

void process_vertex_early(edge_node );
void process_vertex_late(edge_node );
void process_edge(edge_node , edge_node);

#endif
