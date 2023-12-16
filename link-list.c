#include <stdio.h>
#include "LinkList.h"

static void push_implc( node** self, int data ){
    node *Node;
    init_node(&Node, data);
    Node -> next = *self;
    (*self) = Node; 
}

static void insert_implc( node **self, int data ){
    node *Node;
    init_node(&Node, data);
    Node -> next = ((*self) -> next);
    (*self) -> next = Node;
}

static void pop_implc( node **self ){
    if( *self == NULL){
        return;
    }
    node *tmp = *self;
    *self = (*self)->next;
    free(tmp);
}

void init_node( node **self, int data ){
    if(((*self) = malloc(sizeof(node))) == NULL){
        return;
    }
    (*self) -> val = data;
    (*self) -> push = push_implc;
    (*self) -> insert = insert_implc;
    (*self) -> pop = pop_implc;
    (*self) -> next = NULL;
}

void printlist( node **list ){
    while((*list) != NULL){
        printf("%d ", (*list) -> val);
        list = &((*list) -> next);
    }
    printf("\n");
}
