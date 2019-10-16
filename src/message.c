
#include "../include/message.h"

Message * message_alloc(){
    // allocate memory for the Message struct.
    Message * message = (Message *) malloc(sizeof(Message));
    if(message == NULL) {
        uliderror(errno);
        return NULL;
    }
    
    message->data = NULL;
    message->size = 0;
    message->time_stamp = 0;
    
    return message;
}

int message_free(Message * message) {
    
    if(!message)
        return ERROR_MSGNULL;
    
    if(message->data)
        free(message->data);
    
    free(message);
    
    return 0;
}

/*  Possible Updates:
 *  1) Check the upper limit of the size_t
 *  2) Check to see what type of errors could happen with (void *)
 */
int message_set(Message * msg, size_t size, void * data) {
    
    // Check if size is a valid number
    if(!size) {
        return ERROR_MSGSIZE;
    }
    
    // if data pointer is null then return error message
    if(!data) {
        return ERROR_MSGDATA;
    }
    
    /* Check if sizeof data type if larger than size of data
     * This would imply we can't even copy the structure type.*/
    printf("sizeof size: %lu\n", size);
    if(sizeof(data) > size) {
        return ERROR_MSGSIZE;
    }
    
    // Free data if already allocated
    if(msg->data) {
        free(msg->data);
        msg->data = NULL;
    }
    
    // allocate memory
    msg->data = (uint8_t*) malloc(size);
    
    
    // copy data
    
    
    // Returns zero on success
    return 0;
    
}
