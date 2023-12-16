#include "Queue.h"

#define autofree \
__attribute__((cleanup(free_queue)))
__attribute__((always_inline))
inline void free_queue(void *self){
    free(*(void **)self);
}


int main(){
    Queue *q;
    init_Queue(&q, 5);
    q -> enQueue(q, 1);
    q -> enQueue(q, 2);
    q -> enQueue(q, 3);
    printf("%d\n", q -> deQueue(q));
    printf("%d\n", q -> deQueue(q));
    printf("%d\n", q -> deQueue(q));
    return 0;    
}