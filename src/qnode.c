#include "../include/qnode.h"

QNode * qnode_alloc() {
    
    struct qnode_t * node = malloc(sizeof(QNode));
    if(!node){
        return NULL;
    }
    
    node->data = NULL;
    node->next = NULL;
    
    /* Sets the unique structure code for a QNode */
    node->struct_code = QNODE_STRUCT_CODE;
    
    return node;
}

int qnode_free(QNode * node) {
    
    // Node cannot be null
    if(!node)
        return ERROR_TYPENULL;
    
    if(node->struct_code != QNODE_STRUCT_CODE)
        return ERROR_STRUCTCODE;
    
    if(!(node)->next)
        node->next = NULL;
    
    free(node);
    
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

void * qnode_getData(QNode * node) {
    
    return NULL;
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
