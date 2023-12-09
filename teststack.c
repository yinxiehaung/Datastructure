#include <stdio.h>
#include "Stack.c"

#define smart_point\
  __attribute__((cleanup(free_stack)))

__attribute__((always_inline)) 
inline void free_stack( void *stack ){
    free(*(void **)stack);
} 

int main(){
    smart_point Stack *stack;
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
    return 0;
}