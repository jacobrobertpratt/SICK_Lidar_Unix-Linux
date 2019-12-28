#ifndef _ULID_FIFO_H_
#define _ULID_FIFO_H_

#include <stdlib.h>

#include "error.h"
#include "qnode.h"

typedef struct fifo_t {
    int size, max;
    QNode * head;
    QNode * tail;
    void (*dealloc_cb)();
    char type[5];
}Fifo;

/* Allocates a Fifo queue structure */
Fifo * fifo_alloc();

/* Frees a fifo queue structure */
int fifo_free(Fifo * queue);

/* Resets the fifo queue with zero elements. */
int fifo_reset(Fifo * queue);

/* Pushes a node into the queue. */
int fifo_push(Fifo * queue, QNode * node);

/* Removes the first node in the queue. */
void * fifo_pop(Fifo * queue);

/* copys and returns the data in the first node of the queue. */
void * fifo_peek(Fifo * queue);

/* returns the current size of the queue. */
int fifo_getSize();

/* Changes the new max size in the queue. */
int fifo_setMaxSize(int size);

/* Sets the dealloc callback for the node data */
int fifo_setDealloc_Callback(void (*dealloc_cb)());

/* Sets the type of data allocated into the queue. */
int fifo_setType(const char * type);

#endif /* _ULID_FIFO_H_ */
