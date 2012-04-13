#ifndef __LIST_H__
#define __LIST_H__

/* A C implementation of a doubly-linked list. 
 * Contains void pointer values.
 * Can be used as a LIFO stack or FIFO queue.
 */

#define FRONT 0
#define BACK 1

struct linked_node{
    long int data;
	struct linked_node* next;
	struct linked_node* prev;
};

typedef struct linked_node * node_p;

struct list{
	int length;
	node_p first;
	node_p last;
};

typedef struct list * list_p;

list_p create_list(void);

void destroy_list(list_p list);

void list_add(list_p list,long int d);

node_p list_first(list_p list);

node_p list_last(list_p list);

/* must free node once its out of list */
node_p list_pop(list_p list);

/* must free node once its out of list */
node_p list_poll(list_p list);

void list_remove(list_p list, char end);

#endif
