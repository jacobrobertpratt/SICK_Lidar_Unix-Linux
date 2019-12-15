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
 *
 */

/* Initial definition of queue node */
struct qnode_t;

/* Represents a queue used interanally */
struct qnode_t {
    void * data;
    struct qnode_t * next;
    void (*dealloc_cb);
};

/** Represents a queue structure to be used throughout ulid */
typedef struct ulid_queue_t {
    int size;
    char qname[10]; // specifies the type of the queue for type checking
    struct qnode_t * head;
    struct qnode_t * tail;
} Queue;



/* NODE */

/* Allocates a node data type to be added this queue */
static struct qnode_t * qnode_alloc(void * data, void (*dealloc_cb)());

/* Deallocates a node struct. */
static void qnode_free(struct qnode_t * node);

/* Connections two nodes. */
static int qnode_connect(struct qnode_t * curr, struct qnode_t * next);




/* QUEUE */

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
