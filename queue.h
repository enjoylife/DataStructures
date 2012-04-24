#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

#define LISTPOINTER queue_p

#include "list.h"

queue_p create_queue(void);

void destroy_queue(queue_p q);

void enqueue(queue_p, DATATYPE d);

DATATYPE dequeue(queue_p);

bool queue_empty(queue_p);

#endif
