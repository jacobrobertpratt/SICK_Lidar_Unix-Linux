#include "../include/qnode.h"

struct qnode_t * qnode_alloc(void * data) {
    
    if(!data) {
        uliderror(ERROR_TYPENULL);
        return NULL;
    }
    
    return NULL;
}

void qnode_free(struct qnode_t * node) {
    
    return;
}

int qnode_connect(struct qnode_t * curr, struct qnode_t * next) {
    
    return 0;
}
