#ifndef __LIST_H__
#define __LIST_H__

/* A C implementation of a doubly-linked list. 
 * Contains void pointer values.
 * Can be used as a LIFO stack or FIFO queue.
 */

#ifndef DATATYPE
#define DATATYPE long int
#endif

#define FRONT 0
#define BACK 1

#ifndef LISTPOINTER
#define LISTPOINTER  list_p
#endif




struct linked_node{
    DATATYPE data;
	struct linked_node* next;
	struct linked_node* prev;
};

typedef struct linked_node * node_p;

struct list{
	int length;
	node_p first;
	node_p last;
};

typedef struct list * LISTPOINTER;

LISTPOINTER create_list(void);

void destroy_list(LISTPOINTER list);

void list_add(LISTPOINTER list,DATATYPE d);

node_p list_first(LISTPOINTER list);

node_p list_last(LISTPOINTER list);

/* must free node once its out of list */
node_p list_pop(LISTPOINTER list);

/* must free node once its out of list */
node_p list_poll(LISTPOINTER list);

void list_remove(LISTPOINTER list, char end);

#endif
