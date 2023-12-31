#include "Stack.h"
#ifndef _QUEUE_H
#define _QUEUE_H
typedef struct Queue{
    Stack *store;
    Stack *temp;    
    void (*enQueue)(struct Queue *q, int val);
    int (*deQueue)(struct Queue *q);
}Queue;

#endif