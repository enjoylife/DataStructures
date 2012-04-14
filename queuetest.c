#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "queue.h"
#include "dbg.h"

int main(int argc, char **argv){

    log_warn("Starting test Watch for red");
    queue_p q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    check_hard(q->length==3, "erro in queue length");
    check_hard(dequeue(q) ==1,"wrong removing order");
    check_hard(q->length==2,"");
    enqueue(q,4);
    check_hard(q->length==3,"");
    check_hard(dequeue(q) ==2,"wrong removing order");
    check_hard(dequeue(q) ==3,"wrong removing order");
    check_hard(q->length==1,"Wrong length");
    check_hard(!isempty(q), "cant test for emptyness");
    check_hard(dequeue(q) ==4,"wrong removing order");
    check_hard(isempty(q), "cant test for emptyness");
    log_success("END TEST");
    return 0;
}
