#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dbg.h"
#include "graph.h"


graph_p create_graph(DATATYPE num, bool directed) {

    graph_p graph;
    long int  *degree; // pointer to pointer 
     edge_node ** edges;
    DATATYPE size = num+1; // just in case 

    graph = (graph_p) malloc(sizeof(struct graph));
    check_hard(graph, "Could not create memory for graph");

    edges =  calloc(size, sizeof(long int));
    check_hard(edges, "Could not create memory for edges");

    degree =  (long int *)calloc(size, sizeof(long int));
    check_hard(degree, "Could not create memory for degrees");

    graph->vertex_array = edges;
    graph->vertex_degree_array = degree;
    graph->nedges = 0;
    graph->nvertices = num;
    graph->directed = directed;
    return graph;
}

void destroy_graph(graph_p graph) {

    long int i;
    edge_node * node, *next;
    long int size = graph->nvertices+1;
    for(i=0;i<size;i++){
        // destroy actuall lists 
       node = graph->vertex_array[i];
           while(node){
               next = node->next;
               free(node);
               node = next;
           }
    }
    free(graph->vertex_array);
    free(graph->vertex_degree_array);
    free(graph);
}

graph_p graph_from_file(char * filename,bool directed) {

    FILE * fp; // 
    graph_p graph;
    long  int numvert, numedge; // Number vertices and  of edges 
    long  int vertex_a, vertex_b; // vertices in an edge(a,b) 

    fp = fopen(filename, "r");
    check_hard(fp,"Could not find or open file");

    // Read in the header line 
    fscanf(fp, "%ld %ld", &numvert,&numedge);
    graph = create_graph(numvert, directed);
    log_info("Graph: %ld vertices, and %ld edges",numvert, numedge);
    log_info("Starting to reading edges");

    while(fscanf(fp, "%ld %ld", &vertex_a, &vertex_b)!=EOF) {
        //debug("Inserting new edge  %ld",vertex_a);
        insert_edge(graph,vertex_a, vertex_b, graph->directed);
    }
    log_info("Finished reading edges");
    fclose(fp);
    return graph;
}

void insert_edge(graph_p graph, DATATYPE x, DATATYPE y, bool directed) {
    edge_node * node; 

    node = (edge_node*)malloc(sizeof(edge_node));
    // add the adjencent node
    node->data = y;
    // link to fron of list 
    node->next = graph->vertex_array[x];
    graph->vertex_array[x] = node;

    //graph book keeping
    graph->vertex_degree_array[x]++;

    if(directed){
        insert_edge(graph, y, x, true);
    } else{ graph->nedges++;}
}

long int vertex_length(graph_p g, DATATYPE n){
    return g->vertex_degree_array[n];
}


/*
void bfs(graph_p g, DATATYPE start){

    DATATYPE SIZE = g->nvertices+1; // compensate for create_graph()

    DATATYPE i; // counter
    list_p queue, vertex;
    node_p edge;
    DATATYPE parent[SIZE];
    DATATYPE vertex_state[SIZE];
    enum state state;

    for(i=0;i<SIZE;i++) vertex_state[i]= undiscovered;
    queue = create_list(0);

    list_add(queue, graph->edge_list[start]);
    vertex_state[start] = discovered;
    while(queue->length!=0){
        vertex = list_poll(queue);
        process_vertex_early(g->edge_list[vertex->id]->data);
        vertex_state[vertex->id] = processed;
        edge = vertex->first;
        while(edge){
            if(vertex_state[graph->edge_list[edge->data]]!=processed
                    || g->directed){
                process_edge(


        }
    }



}

void process_vertex_early(DATATYPE v){
}
void process_vertex_late(DATATYPE v){
}
void process_edge(DATATYPE x, DATATYPE v){
}

*/
