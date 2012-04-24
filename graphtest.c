#include "dbg.h"
#include "graph.h"

int main(int argc, char** argv){
    check(argc == 2, "Need to specify a filename");

    graph_p g = create_graph(10, 1);
    check(g->nvertices ==10, "create failed");
    check(g->vertex_array !=NULL, "create failed");
    destroy_graph(g);
    log_success("Graph intializaion");

    
    g = graph_from_file(argv[1],false);
    check(vertex_length(g,1)==2,"error in length");
    check(vertex_length(g,6)==1,"error in length");
    check(g->nedges==10,"error in summing edges");
    bfs(g, 0);
    destroy_graph(g);
    log_success("vertex lengths");
    log_success(BOLDBLUE"End of test."RESET);
    return 0;
error:
    return -1;
}
