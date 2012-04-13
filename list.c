#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "dbg.h"

list_p create_list(){
	list_p list = (list_p) malloc(sizeof(struct list));
    check_hard(list, "Could not create memory for list");
	list->length = 0;
	list->first = NULL;
	list->last = NULL;
	return list;
}

void destroy_list(list_p list){
	node_p cur = list->first;
	node_p next;
	while(cur){
		next = cur->next;
		free(cur);
		cur = next;
	}
    check_hard(list,"Free will be undefined for list.");
	free(list);
}


void list_add(list_p list,long int d){
	node_p node = (node_p)malloc(sizeof(struct linked_node));
    check_hard(node, "Could not create memory for node pointer");
    node->data = d;
    if(list->first==NULL){
            node->prev = NULL;
            node->next = NULL;
            list->first = node;
            list->last = node;
        }
        else{
            list->last->next = node;
            node->prev = list->last;
            node->next = NULL;
            list->last = node;
        }
        list->length++;
}


node_p list_first(list_p list){
	return list->first;
}

node_p list_last(list_p list){
	return list->last;
}

node_p list_pop(list_p list){
	node_p last = list->last;
    /* no nodes in the list to begin with */
	if(last == NULL){
        return NULL;
    /* List of 1 node careful with end pointers */
    } else if(list->length==1) {
        list->first = NULL;
        list->last = NULL;
    } else {
        /* we have more nodes to work with */
        last->prev->next = NULL;
    }
    node_p node = last;
    list->length--;
	return node;
}

node_p list_poll(list_p list){
	node_p first = list->first;
    /* No nodes to begin with */
	if(first == NULL){
        return NULL;
    } else if(list->length==1) {
    /* List of 1 node careful with end pointers */
        list->first = NULL;
        list->last = NULL;
    } else {
    /* we have more nodes to work with */
	list->first = first->next;
	first->next->prev = NULL;
    }
	node_p node = first;
    list->length--;
	return node;
}

void list_remove(list_p list, char end){
	if(end == FRONT)
		free(list_poll(list));
	else if (end == BACK)
		free(list_pop(list));
	else return;
}



