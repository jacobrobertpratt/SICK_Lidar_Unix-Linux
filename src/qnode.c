#include "../include/qnode.h"

QNode * qnode_alloc() {
    
    struct qnode_t * node = malloc(sizeof(QNode));
    if(!node){
        uliderror(errno);
        return NULL;
    }
    
    node->data = NULL;
    
    node->next = NULL;
    
    return node;
}

int qnode_free(QNode ** node) {
    
    // Node cannot be null
    if(!(*node))
        return ERROR_TYPENULL;
    
    /* Catch for possibly already allocated next pointer
        and data pointer. */
    if((*node)->data || (*node)->next)
        return ERROR_MEMREF;
    
    free(*node);
    *node = NULL;
    
    return 0;
}

int qnode_setData(QNode * node, void * data) {
    
    // Check if either is null
    if(!data || !node)
        return ERROR_TYPENULL;
    
    // Check if data is already set
    if(node->data)
        return ERROR_REPDATA;
    
    node->data = data;
    
    return 0;
}

int qnode_connect(QNode * curr, QNode * next) {
    
    if(!curr || !next)
        return ERROR_TYPENULL;
    
    // Check if next node already set
    if(curr->next)
        return ERROR_REPDATA;
    
    curr->next = next;
    
    return 0;
}
