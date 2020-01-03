
#include "../include/fifo.h"

Fifo * fifo_alloc() {
    
    // Allocate Queue
    Fifo * queue = malloc(sizeof(Fifo));
    if(!queue) {
        uliderror(errno);
        return NULL;
    }
    
    // Allocate head and tail nodes
    queue->head = NULL;
    queue->tail = NULL;
    
    // Set to standard queue size
    queue->max = INITIAL_FIFO_SIZE;
    queue->size = 0;
    
    // Set queue type
    memset(queue->type, 0, 5);
    
    queue->dealloc_cb = NULL;
    
    return queue;
}

int fifo_free(Fifo * queue) {
    
    if(!queue) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    free(queue);
    
    return 0;
}

int fifo_reset(Fifo * queue) {
    
    if(!queue) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    return 0;
}

int fifo_push(Fifo * queue, void * data) {
    
    QNode * node;
    
    if(!queue || !data) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    
    // Create new node
    node = qnode_alloc();
    if(!node){
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    // Set nodes data
    
    // add node to queue
    
    queue->size++;
    
    return 0;
}

void * fifo_pop(Fifo * queue) {
    
    if(!queue) {
        uliderror(ERROR_TYPENULL);
        return NULL;
    }
    
    return NULL;
}

void * fifo_peek(Fifo * queue) {
    
    if(!queue) {
        uliderror(ERROR_TYPENULL);
        return NULL;
    }
    
    return NULL;
}

int fifo_getSize(Fifo * queue) {
    
    int ret = 0;
    
    if(!queue) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    ret = queue->size;
    
    return ret;
}

int fifo_setMaxSize(Fifo * queue, int size) {
    
    if(!queue) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    if(size <= 0)
        return ERROR_SIZE;
    
    queue->max = size;
    
    return 0;
}

int fifo_setDealloc_Callback(Fifo * queue, void (*dealloc_cb)()) {
    
    if(!queue || !dealloc_cb){
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    return 0;
}

int fifo_setType(Fifo * queue, const char * type) {
    
    if(!queue || !type) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    return 0;
}
