//refer by https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "Stack.h"

static int pop_implc( Stack *self ){
    if( self -> isEmpty(self) ){
        return INT_MIN;
    }
    return self -> array[ self -> top--];
}

static int peek_implc( Stack *self ){
    if(self -> isEmpty(self)){
        return INT_MIN; 
    }
    return self -> array[ self -> top ];
}

static int isFULL_implc( Stack *self ){
    return (self->top == self->capacity - 1 );
}

static int isEmpty_implc( Stack *self ){
    return (self -> top == -1);
}

static void push_implc( Stack *self, int val ){
    if(self -> isFULL(self)){
        return;
    }
    self -> array[++self -> top] = val;
    return;
}

void init_stack( Stack **stack, int capacity ){
    if(((*stack) = (Stack *)malloc( sizeof(Stack) )) == NULL){
        printf("alloc stack error");
        return;
    }
    if(((*stack) -> array = (int *)malloc(sizeof(int) * capacity)) == NULL){
        printf("alloc stack error");
        return;
    }
    (*stack) -> top = -1;
    (*stack) -> capacity = capacity;
    (*stack) -> pop = pop_implc;
    (*stack) -> peek = peek_implc;
    (*stack) -> isFULL = isFULL_implc;
    (*stack) -> isEmpty = isEmpty_implc;
    (*stack) -> push = push_implc;
}
