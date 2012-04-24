#include <stdlib.h> // malloc, calloc, exit, free
#include <stdbool.h> //bool

#define DATATYPE edge_node 

#include "dbg.h"
#include "graph.h"
#include "queue.h"


graph_p create_graph(long int num, bool directed) {

    graph_p graph;
    long int  *degree; // pointer to pointer 
    edge_node ** edges;
    long int size = num+1; // just in case 

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

void insert_edge(graph_p graph, long int x, long int y, bool directed) {
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

long int vertex_length(graph_p g, long int n){
    return g->vertex_degree_array[n];
}

void bfs(graph_p g, long int start){

    long int SIZE = g->nvertices+1; // compensate for create_graph adding 1

    long int i; // counter
    queue_p queue;
    edge_node * tempnode;
    edge_node  vertex;
    long int parent[SIZE];
    long int vertex_state[SIZE];

    queue = create_queue();
    for(i=0;i<SIZE;i++) vertex_state[i]= undiscovered;
    for(i=0;i<SIZE;i++) parent[i]= -1;

    // get the actually node from the array
    enqueue(queue, *(g->vertex_array[start]));
    vertex_state[start] = discovered;

    log_info("Starting Breadth first search");
    while(!queue_empty(queue)){
        vertex =  dequeue(queue);
        //process_vertex_early(vertex);
        check_hard(vertex.data!=1,"it should be %ld", vertex.data);
        vertex_state[vertex.data] = processed;
        tempnode = vertex.next;
        while(tempnode){
            debug("tempnode data is %ld", tempnode->data);
            debug("GOOD");
            debug("tempnode data is %ld", tempnode->data);
            if(vertex_state[tempnode->data]!=processed || g->directed){
                debug("GOOD");
                process_edge(vertex, *tempnode);
            }
            if(vertex_state[tempnode->data]==undiscovered){
                enqueue(queue, (*g->vertex_array[tempnode->data]));
                vertex_state[tempnode->data] == discovered;
                parent[tempnode->data] == vertex.data;
            }
            tempnode = tempnode->next;
        }
        process_vertex_late(vertex);
    }
    destroy_queue(queue);
    log_info("Finished Search through graph");
}

void process_vertex_early(edge_node  v){
}
void process_vertex_late(edge_node  v){
}
void process_edge(edge_node x, edge_node v){
}


