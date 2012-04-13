#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dbg.h"
#include "graph.h"
#include "list.h"

int main(int argc, char** argv){
    check(argc == 2, "Need to specify a filename");

    graph_p g = create_graph(10);
    check(g->nvertices ==10, "create failed");
    check(g->edge_list !=NULL, "create failed");
    log_success("Graph intializaion");
    destroy_graph(g);
    g = graph_from_file(argv[1], 0);
    destroy_graph(g);

    log_success(BOLDBLUE"End of test."RESET);
    return 0;
error:
    return -1;
}
