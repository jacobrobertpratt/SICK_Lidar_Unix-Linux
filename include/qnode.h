#ifndef _ULID_QNODE_H_
#define _ULID_QNODE_H_

#include <stdlib.h>

#include "common.h"
#include "error.h"

/**
 *@author Jacob R. Pratt
 *@Date 12/26/2019
 *
 * Implementation of a  generic queue node to be used in a fifo queue
 */

#define QNODE_STRUCT_CODE 0x0003

/* Initial definition of queue node */
struct qnode_t;

/* Represents a queue used interanally */
typedef struct qnode_t {
    
    void * data;
    
    struct qnode_t * next;
    
    /* Call sign of this structure for deallocations purposes. */
    int struct_code;
    
}QNode;

/* Allocates a node data type to be added this queue */
QNode * qnode_alloc(void);

/* Deallocates a node struct. */
int qnode_free(QNode * node);

/* Sets the data referernce for the node, else it's null. */
int qnode_setData(QNode * node, void * data);

/* Returns the data provided to the node. */
void * qnode_getData(QNode * node);

/* Connections two nodes. */
int qnode_connect(QNode * curr, QNode * next);

#endif /* _ULID_QNODE_H_ */
