#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "dbg.h"

void lazy_add(LISTPOINTER l, int y);

int main(int argc, char** argv){

    LISTPOINTER list = create_list(); /* test lists */

    /*tester vars */
    int a; 
    node_p node, newn;

	log_info("The size of (list): %ld", sizeof(struct list));
    log_info("The size of (LISTPOINTER): %ld", sizeof(LISTPOINTER)); 
    log_info("The size of (linked_node): %ld", sizeof(struct linked_node));
    log_info("The size of (node_p): %ld", sizeof(node_p));

    /* Simple base cases */
    a = 10;
    list_add(list,a);

    node = list_first(list);
    check(node->data == 10,"Failed First node");

    check(list->length ==1,"Incorrect Length increment?");
    check(list_last(list)->data==10,"Wrong pointers to list TAIL?");
    check(list_first(list)->data==10,"Wrong pointers to list HEAD?");
    check(list_first(list)->next==NULL,"Wrong pointers to list next?");
    log_success("creationism?");

    newn = list_pop(list);
    check(newn, "Pop didnt return a node_p?");
    check(list->length ==0,"Incorrect Length increment?");
    check(newn->data==10, "incorrect data in  popped node");
    free(newn);
    log_success("Pop those nodes!");

    list_add(list,a);
    newn = list_poll(list);
    check(newn->data==10, "data didnt transfer from poll");
    check(list->length==0, "length didnt adjust in poll");
    free(newn);
    log_success("Poll those nodes!");

    check(list->first==NULL,"Error in pop?");
    lazy_add(list,10);
    check(list->length==10,"Incorrect lazy add");
    destroy_list(list);
    // remember now that you have node outside of list you
    // must free it on your own 
    log_success("No leaks here Mario!");

    list = create_list();
    lazy_add(list, 5);
    list_remove(list,FRONT);
    check(list->length==4,"poll within remove error?");
    list_remove(list,BACK);
    check(list->length==3,"Pop within remove error?");
    destroy_list(list);
    log_success("Whoa whoses popping and polling without me!?");

    log_success(BOLDBLUE"End of test."RESET);
	return 0;
error:
    return 1;
}

void lazy_add(LISTPOINTER l, int y){
    int z;
    for(z=0;z<y;z++){
            list_add(l,z);
        }
}

