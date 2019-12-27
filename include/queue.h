#ifndef _ULID_QUEUE_H_
#define _ULID_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "error.h"

/**
 *@author Jacob R. Pratt
 *@Date 12/15/2019
 *
 * Implementation of a concurrent queue set at the user level.
 */

/** Represents a queue structure to be used throughout ulid */
typedef struct ulid_queue_t {
    int size;
    char qname[10]; // specifies the type of the queue for type checking
    struct qnode_t * head;
    struct qnode_t * tail;
} Queue;

/** Allocates a queue structure. Sets the memory and returns the queue structure or
    a null pointer if fails. Set queue type which can be a 4 byte char string. */
Queue * queue_alloc();

/** Frees the queue and returns nothing */
int queue_free(Queue * queue);

/** Pops and element off of the queue. If the queue is empty it returrns null. */
void * queue_pop(Queue * queue);

/** Pushes and element into the queue. */
int queue_push(Queue * queue, void * element);

/** Provides the size of the queue. */
int queue_getSize(Queue * queue);

/** Returns the name of the queu.*/
char * queue_getName(Queue * queue);

/* MACROS */



#endif
