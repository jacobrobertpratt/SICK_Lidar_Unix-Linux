#include "../include/queue.h"

static struct  qnode_t * qnode_alloc(void * data, void (*dealloc_cb)()) {
    
    struct qnode_t * node = NULL;
    
    // Possibly check data type to assign to validate callback, else
    
    return node;
}

static void qnode_free(struct qnode_t * node){
    // test node
    
    // test callback
    
}

Queue * queue_alloc() {
    Queue * queue = NULL;
    return queue;
}

int queue_free(Queue * queue) {
    
    // test if queue is not null
    
    /* loop through each element and remove nodes only leaving
        the head and tail nodes. */
    
    return 0;
}

void * queue_pop(Queue * queue) {
    
    return NULL;
}

int queue_push(Queue * queue, void * element) {
    return 0;
}

int queue_getSize(Queue * queue) {
    return 0;
}
