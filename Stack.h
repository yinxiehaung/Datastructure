#ifndef _STACK_H
#define _STACK_H
typedef struct Stack Stack;
typedef int (*funs)(Stack *stack);
typedef unsigned int u_int;

static int peek_implc( Stack *self );
static int isFULL_implc( Stack *self );
static int isEmpty_implc( Stack *self );
static void push_implc( Stack *self, int val );
void init_stack( Stack **stack, int capacity );

struct Stack{
    int *array;
    u_int top;
    u_int capacity;
    funs pop, peek, isFULL, isEmpty;
    void (*push)(Stack *stack, int val);
};
#endif