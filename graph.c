#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dbg.h"
#include "list.h"
#include "graph.h"


void  fread_into_graph( char * filename,bool directed)
{
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
        debug("Added edge (%ld,%ld) to vertex list %d",
                vertex_a,vertex_b,vertex_a);
    }

}
