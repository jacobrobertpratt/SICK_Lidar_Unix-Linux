#ifndef _ULID_FIFO_H_
#define _ULID_FIFO_H_

#include "common.h"
#include "error.h"
#include "qnode.h"

/** CLASS DEFINITION:
 * The fifo class is a structure that represents a first-in first-out queue. This a geneic queue
 *  which can take in any reference and store that reference in order. This queue doesn't
 *  copy any memory from the structure. All structure information passed to the queue are
 *  stored in qnodes. QNodes are allocated and destroyed in the structure calls.
 *  @author Jacob R. Pratt
 *  @Date Jan 5th, 2020
 */

#define INITIAL_FIFO_SIZE   50
#define FIFO_STRUCT_CODE    1


/** FIFO STRUCT DEFINITION:
 * The fifo_t structure contains head, tail, size, max size, and type fields. The structure has a
 *  structure reference such that only Fifo structures can be passed to the Fifo free function
 *  call.
 */
typedef struct fifo_t {
    int size, max;
    QNode * head;
    QNode * tail;
    char type[10];
    
    /* Call sign of this structure for deallocations purposes. */
    int struct_code;
    
} Fifo;

/**
 * Function allocates memoy for a FIFO queue structure, setting all internal fields to NULL, and
 *  zeroing out the type field. If memory cannot be allocated NULL is retreturned and the error
 *  is reported with uliderror(...).
 *  @param VOID
 *  @return Fifo pointer
 */
Fifo * fifo_alloc();

/**
 * Will deallocate the entirety of the queue. Upon success 0 is returned, else the appropriate
 *  error message is returned associated with the given error. If the queue was allocated with
 *  a structure, then the structures free method can be passed as a second parameter to this function.
 *  If the function is not given the free() function associated with the structure passed to the queue, and the queue is full of data, then the method will return with an error message. If there is no data
 *  then the function will return 0 and will have successfully deallocated the queue.
 *  @param Fifo queue pointer
 *  @param callback to structure free function, in the form {int <struct name>_free(<struct> * )}
 *  @return 0 upon success or the following error messages on failure
 *          ERROR_TYPENULL if the queue that is passed is NULL
 *          FIFO_STRUCT_CODE if the queue passed is not a FIFO queue
 *          ERROR_TYPENULL if the call back is NULL, but data is in the queue
 *          ERROR_STRUCTCODE if the callback fails to deallocate the data
 *          ERROR_SIZE if all nodes were not removed from the queue
 *          ERROR_MEMREF if the head and tail nodes were not NULL after all data deallocation
 */
int fifo_free(Fifo * queue, int (*dealloc_cb)(void *));

/**
 * Pushes a data or structure type onto the queue. Will allocate a (qnode_t *) and load the data
 *  paramters into the node. The queue and data must not be NULL.
 *  @param Fifo queue pointer
 *  @param data (void *) to struct or data type passed to the queue
 *  @return 0 upon success or the following errors on failure
 *          ERROR_TYPENULL if the queue that is passed is NULL or can't allocate a qnode
 *          ERROR_REPDATA if the qnode already cointains data
 */
int fifo_push(Fifo * queue, void * data);

/**
 * Provides the data or structure that was passed to the queue. This is a first-in, first-out queue so
 *  the order that it was added matters. If the function fails a uliderror is set.
 *  @param Fifo queue pointer
 *  @return Data type that was passed in order it was passed or NULL on failure
 */
void * fifo_pop(Fifo * queue);

/**
 * Provides the size of the queue at the given time of calling this function.
 *  @param Fifo queue pointer
 *  @return integer of queue size
 */
int fifo_getSize(Fifo * queue);

/**
 * Allows update of the maximum size of this queue.
 *  @param Fifo queue pointer
 *  @param size queue pointer
 *  @return 0 on success or appropriate error number on failure
 *          ERROR_TYPENULL if the queue that is passed is NULL or can't allocate a qnode
 *          ERROR_SIZE if the size passed as a parameter is negative
 */
int fifo_setMaxSize(Fifo * queue, int size);

/**
 * Sets a string value that is associate with the type of queue. This allows the user to enter a label for this
 *  queue. Hence, if there are multiple queues in the same program, allows the user to make a call to
 *  fifo_getType(Fifo * queue) to reference what type of queue it was.
 *  @param Fifo queue pointer
 *  @param type constant char pointer.
 *  @return 0 on success or error number on failure.
 *          ERROR_TYPENULL if the queue that is passed is NULL or can't allocate a qnode
 */
int fifo_setType(Fifo * queue, const char * type);

/* Updates: */
// 1) Add a fifo_getType() function that returns the type of fifo queue
// 2) change the setType label to setLabel ... better explination
// 3) See how to enforce encapsulation of the functions

#endif /* _ULID_FIFO_H_ */
