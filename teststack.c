#include <stdio.h>
#include "Stack.c"

int main(){
    Stack *stack;
    init_stack(&stack, 5);
    stack -> push( stack, 1);
    stack -> push( stack, 2);
    stack -> push( stack, 3);
    stack -> push( stack, 4);
    stack -> push( stack, 5);
    for( int i = stack -> top; i >=0; i-- ){
        printf("%d ", stack -> array[i]);
        stack -> pop(stack);
    }
    printf("\n");
    free(stack);
    return 0;
}