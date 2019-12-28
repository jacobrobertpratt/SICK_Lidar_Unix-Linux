
#include "../include/fifo.h"

Fifo * fifo_alloc() {
    return NULL;
}

int fifo_free(Fifo * queue) {
    return 0;
}

int fifo_reset(Fifo * queue) {
    return 0;
}

int fifo_push(Fifo * queue, QNode * node) {
    return 0;
}

void * fifo_pop(Fifo * queue) {
    return NULL;
}

void * fifo_peek(Fifo * queue) {
    return NULL;
}

int fifo_getSize() {
    return 0;
}

int fifo_setMaxSize(int size) {
    return 0;
}

int fifo_setDealloc_Callback(void (*dealloc_cb)()) {
    return 0;
}

int fifo_setType(const char * type) {
    return 0;
}
