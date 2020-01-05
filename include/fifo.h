#ifndef _ULID_FIFO_H_
#define _ULID_FIFO_H_

#include "common.h"
#include "error.h"
#include "qnode.h"

#define INITIAL_FIFO_SIZE   50
#define FIFO_STRUCT_CODE    0x0001 

typedef struct fifo_t {
    int size, max;
    QNode * head;
    QNode * tail;
    char type[10];
    
    /* Call sign of this structure for deallocations purposes. */
    int struct_code;
    
} Fifo;

/* Allocates a Fifo queue structure */
Fifo * fifo_alloc();

/* Frees a fifo queue structure */
int fifo_free(Fifo * queue, int (*dealloc_cb)(void *));

/* Pushes a node into the queue. */
int fifo_push(Fifo * queue, void * data);

/* Removes the first node in the queue. */
void * fifo_pop(Fifo * queue);

/* returns the current size of the queue. */
int fifo_getSize(Fifo * queue);

/* Changes the new max size in the queue. */
int fifo_setMaxSize(Fifo * queue, int size);

/* Sets the type of data allocated into the queue. */
int fifo_setType(Fifo * queue, const char * type);

#endif /* _ULID_FIFO_H_ */
