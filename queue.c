#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "list.h"
#include "dbg.h"


queue_p create_queue(void){
    return create_list();
}

void enqueue(queue_p q, DATATYPE d){
    return list_add(q, d);
}

DATATYPE dequeue(queue_p q){
    return list_poll(q)->data;
}

bool isempty(queue_p q){
    return !q->length;
}

