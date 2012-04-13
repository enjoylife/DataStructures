#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dbg.h"
#include "graph.h"
#include "list.h"

int main(int argc, char** argv){
    check(argc == 2, "Need to specify a filename");

    fread_into_graph(argv[1], 0);

		return 0;
error:
    return -1;
}
