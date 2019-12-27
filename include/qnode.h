#ifndef _ULID_NODE_H_
#define _ULID_NODE_H_

#include <stdlib.h>

#include "error.h"

/**
 *@author Jacob R. Pratt
 *@Date 12/26/2019
 *
 * Implementation of a  generic queue node to be used in a fifo queue
 */

/* Initial definition of queue node */
struct qnode_t;

/* Represents a queue used interanally */
struct qnode_t {
    void * data;
    struct qnode_t * next;
    void (*dealloc_node_cb);
};

/* Allocates a node data type to be added this queue */
struct qnode_t * qnode_alloc(void * data);

/* Deallocates a node struct. */
void qnode_free(struct qnode_t * node);

/* Connections two nodes. */
int qnode_connect(struct qnode_t * curr, struct qnode_t * next);

/* Sets the callback for the node data type to destroy the */
int qnode_deallocCallback(void (*dealloc_node_cb)());


#endif /* _ULID_NODE_H_ */
