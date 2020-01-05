#ifndef _ULID_QNODE_H_
#define _ULID_QNODE_H_

#include <stdlib.h>

#include "common.h"
#include "error.h"

/**
 * CLASS DEFINITION:
 * QNode represents a node in a queue, specifically a fist-in first-out queue. The nodes hold
 *  data values, a reference to the next node, and a structure code unique to qnode types.
 *  This class is meant to reduce the complexity when programming queues and is used
 *  in the Fifo class.
 *  @author Jacob R. Pratt
 *  @Date 12/26/2019
 */

#define QNODE_STRUCT_CODE 0x0003

struct qnode_t;

/**
 * This structure represents a node to be used in a Fifo queue.
 */
typedef struct qnode_t {
    /* Data or structure associated with this node */
    void * data;
    /* next node */
    struct qnode_t * next;
    /* Call sign of this structure for deallocations purposes. */
    int struct_code;
} QNode;

/**
 * Allocates a QNode pointer and sets the data and next fields to NULL.
 * @param void
 * @return QNode pointer
 */
QNode * qnode_alloc(void);

/**
 * Frees a qnode_t pointer. This function does not check if the data type has not been freed, then
 *  this function returns an error warning that the data type must be freed. It will automatically
 *  set the next pointer to NULL.
 *  @param QNode pointer
 *  @return 0 on success or error numbe on failure.
 *      ERROR_TYPENULL if the queue node is NULL
 *      ERROR_STRUCTCODE is the node is not a qnode
 *      ERROR_DATA if the data is not null and needs to be freed.
 */
int qnode_free(QNode * node);

/**
 * Sets the data type of the node. Data can be a structure of any size or a primitive type.
 *  Data and queue cannot be NULL. If data is already associated with the node then the
 *  function throws an error.
 *  @param node QNode pointer
 *  @param data void pointer
 *  @return 0 on success or error number on failure
 *      ERROR_TYPENULL if the queue node is NULL
 *      ERROR_REPDATA if data is already allocated for this node
 */
int qnode_setData(QNode * node, void * data);

/**
 * Returns the data for the node as a void pointer. The user will have to remember what type
 *  of data is associated with the node before returning it, else they can pass it through a check
 *  function.
 *  @param node QNode pointer
 *  @return void pointer or NULL on failure
 */
void * qnode_getData(QNode * node);

/**
 * Connects two nodes. The current node's next pointer is assigned to the next node. If either node
 *  is NULL, then the function returns with a failure number. If the next node is already set, then
 *  an error number is also returned.
 *  @param curr QNode pointer
 *  @param next QNode pointer
 *  @return 0 on success or an error number on failure.
 *      ERROR_TYPENULL if the queue node is NULL
 *      ERROR_REPDATA if data is already allocated for the next node
 */
int qnode_connect(QNode * curr, QNode * next);

/* Updates */
// 1)

#endif /* _ULID_QNODE_H_ */
