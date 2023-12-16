#ifndef _LINKLIST_H
#define _LINKLIST_H
typedef struct node node;
typedef void (*func_v)( node**, int );
 
struct node{
    int val;
    node *next;
    func_v push, insert;
    void (*pop)( node** ); 
};

static void push_implc( node**, int );
static void insert_implc( node**, int);
static void pop_implc(node**);
void init_node( node **, int);
#endif