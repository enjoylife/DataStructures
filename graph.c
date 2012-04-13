#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dbg.h"
#include "list.h"
#include "graph.h"

graph_p create_graph(long int size) {
    long int i;
    degree_p degree;
    graph_p graph;
    /* pointer to pointer of lists */
    list_p * edges;

    graph = (graph_p) malloc(sizeof(struct graph));
    check_hard(graph, "Could not create memory for graph");

    edges = (list_p*) malloc(sizeof(list_p));
    check_hard(edges, "Could not create memory for edges");

    degree = (int*) calloc(size, sizeof(int));
    check_hard(degree, "Could not create memory for degree pointer");

    for(i=0;i<size;i++){
        /* create actuall lists */
        edges[i] = create_list();
    }


    graph->nedges = 0;
    graph->nvertices = 0;
    graph->degrees = degree;
    graph->edge_list = edges;
    return graph;
}

void destroy_graph(graph_p graph) {
    long int i;
    long int size = graph->nvertices;
    list_p * list = graph->edge_list;
    for(i=0;i<size;i++){
        /* destroy actuall lists */
        destroy_list(list[i]);
    }
    free(graph);
}

void  fread_into_graph( char * filename,bool directed) {

    FILE * fp;
    long int i;
    long  int numvertices, numedges; /* Number vertices and  of edges */
    long  int vertex_a, vertex_b; /* vertices in an edge(a,b) */

    fp = fopen(filename, "r");
    if(!fp){
    log_err("Failed to open Graph for Reading");
    exit(1);
    }
    /* Read in the header line */
    fscanf(fp, "%ld %ld",&numvertices,&numedges);

    /* create array of  pointers to lists */

    list_p * graph= calloc(numvertices+2, sizeof(list_p));
    for(i=0;i<numvertices+2;i++){
        /* create actuall lists */
        graph[i] = create_list();
    }

    log_info("Going to be reading in %ld vertices, and %ld edges",
            numvertices, numedges);
    log_info("Reading Edges");

    while(fscanf(fp, "%ld %ld", &vertex_a, &vertex_b)!=EOF)
    {
        debug("Inserting new edge list for %ld",vertex_a);
        list_add(graph[vertex_a], vertex_b);
        debug("Added edge (%ld,%ld) to vertex list %ld",
                vertex_a,vertex_b,vertex_a);
    }

}

void insert_edge(list_p * l, long int x, long int y, bool directed) {

    list_add(l[x],y);
    if(directed){
        list_add(l[y],x);
    }
}

