#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdbool.h>
#include "list.h"



/* Read in values from a file,
 * First line is: nvertices nedges (seperator is space) */
void  fread_into_graph(char * filename, bool directed);



#endif
