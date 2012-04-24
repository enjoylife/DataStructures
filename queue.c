#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "list.h"
#include "dbg.h"


queue_p create_queue(void){
    return create_list();
}

void destroy_queue(queue_p q){
    destroy_list(q);
}

void enqueue(queue_p q, DATATYPE d){
    return list_add(q, d);
}

DATATYPE dequeue(queue_p q){
    DATATYPE temp;
    temp = list_first(q)->data;
    list_remove(q, FRONT);
    return temp;
}

bool queue_empty(queue_p q){
    return !q->length;
}
