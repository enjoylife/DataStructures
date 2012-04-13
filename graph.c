#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dbg.h"
#include "list.h"
#include "graph.h"


graph_p create_graph(long int num) {

    graph_p graph;
    list_p * edges; // pointer to pointer of lists 
    long int size = num+1; // just in case 
    long int i;

    graph = (graph_p) malloc(sizeof(struct graph));
    check_hard(graph, "Could not create memory for graph");

    edges = (list_p*) malloc(size*sizeof(list_p));
    check_hard(edges, "Could not create memory for edges");


    for(i=0;i<size;i++) edges[i] = create_list();

    graph->nedges = 0;
    graph->nvertices = num;
    graph->edge_list = edges;
    return graph;
}

void destroy_graph(graph_p graph) {

    long int i;
    long int size = graph->nvertices+1;
    for(i=0;i<size;i++){
        /* destroy actuall lists */
        destroy_list(graph->edge_list[i]);
    }
    free(graph->edge_list);
    free(graph);
}

graph_p graph_from_file(char * filename,bool directed) {

    FILE * fp; // 
    graph_p graph;
    long  int numvert, numedge; // Number vertices and  of edges 
    long  int vertex_a, vertex_b; // vertices in an edge(a,b) 

    fp = fopen(filename, "r");
    check_hard(fp,"Could not find or open file");

    /* Read in the header line */
    fscanf(fp, "%ld %ld", &numvert,&numedge);
    graph = create_graph(numvert);
    log_info("Graph: %ld vertices, and %ld edges",numvert, numedge);
    log_info("Starting to reading edges");

    while(fscanf(fp, "%ld %ld", &vertex_a, &vertex_b)!=EOF) {
        debug("Inserting new edge  %ld",vertex_a);
        insert_edge(graph,vertex_a, vertex_b, directed);
    }
    fclose(fp);
    return graph;
}

void insert_edge(graph_p graph, long int x, long int y, bool directed) {

    list_add(graph->edge_list[x],y);
    if(directed){
        list_add(graph->edge_list[y],x);
    }
}

