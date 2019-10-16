
#include "../include/message.h"

Message * message_alloc(){
    // allocate memory for the Message struct.
    Message * message = (Message *) malloc(sizeof(Message));
    if(message == NULL) {
        uliderror(errno);
        return NULL;
    }
    
    message->data = NULL; // void * of data
    message->data_type = NULL; // type of data as string
    message->size = 0; // 32-bit integer
    message->time_stamp = -1; // 64-bit integer
    
    return message;
}

int message_free(Message * msg) {
    
    if(!msg)
        return ERROR_MSGNULL;
    
    // free data (void *)
    if(msg->data){
        free(msg->data);
        msg->data = NULL;
    }
    
    // free data_type (char *)
    if(msg->data_type) {
        free(msg->data_type);
        msg->data_type = NULL;
    }
    
    free(msg);
    
    return 0;
}

/*  Possible Updates:
 *  1) Check the upper limit of the size_t
 *  2) Check to see what type of errors could happen with (void *)
 *  3) Need to check and stop copy overflow. ... how?
 */
int message_set_data(Message * msg, void * data, size_t size, const char * data_type) {
    
    // Check if size is a valid number
    if(!size) {
        return ERROR_MSGSIZE;
    }
    
    // If data pointer is null then return error message
    if(!data) {
        return ERROR_MSGDATA;
    }
    
    // Free destination data if allocated
    if(msg->data) {
        free(msg->data);
        msg->data = NULL;
    }
    
    // allocate memory with size of size_t size
    msg->data = (uint8_t*) malloc(size);
    if(!msg->data) {
        return errno; // returns the error number associated with no mem.
    }
    
    // copy data to destination buffer with size specified.
    memcpy(msg->data, data, size);
    
    /* Sets the data type as a string so that it can be later used
     * to understand what kind of data was set in the message. */
    if(data_type)
        msg->data_type = strdup(data_type);
    
    // Returns zero on success
    return 0;
}
