#include "Stack.c"

typedef struct Queue{
    Stack *store;
    Stack *temp;    
    void (*enQueue)(struct Queue *q, int val);
    int (*deQueue)(struct Queue *q);
}Queue;

static int deQueue_implc( Queue *self ){
    if(((self -> store) -> isEmpty( self -> store ))){
        return -1;
    }
    return (self -> store)-> pop(self -> store); 
}

static void enQueue_implc( Queue *self, int val ){
    while( !((self -> store) -> isEmpty( self -> store )) ){
        self -> temp -> push(self -> temp, (self -> store) -> peek( self -> store)); 
        self -> store -> pop( self -> store );
    }
    self -> store -> push( self -> store, val);
    while( !((self -> temp) -> isEmpty(self -> temp)) ){
        self -> store -> push( self -> store, (self -> temp) -> peek(self -> temp) );
        self -> temp -> pop( self -> temp);
    }
}

void init_Queue( Queue **q, int capacity){
    if( ((*q) = (Queue *)malloc(sizeof(Queue))) == NULL ){
        printf("alloc queue error");
        return;
    }
    init_stack(&((*q) -> store), capacity);
    init_stack(&((*q) -> temp), capacity);
    (*q) -> deQueue = deQueue_implc;
    (*q) -> enQueue = enQueue_implc;   
}

