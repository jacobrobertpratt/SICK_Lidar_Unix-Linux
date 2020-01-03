#include "../include/message.h"

Message * message_alloc(){
    // allocate memory for the Message struct.
    Message * msg = (Message *) malloc(sizeof(Message));
    if(!msg) {
        uliderror(errno);
        return NULL;
    }
    
    msg->data = NULL;       // void * of data
    msg->data_type = NULL;  // type of data as string
    msg->size = 0;          // 32-bit integer
    msg->time_stamp = -1;   // 64-bit integer
    
    return msg;
}

int message_reset(Message * msg){
    
    if(!msg)
        return ERROR_TYPENULL;
    
    msg->time_stamp = -1;
    msg->size = 0;
    
    if(msg->data_type)
        free(msg->data_type);
        
    // Possible improvement to add a callback to destroy data field.
    
    return 0;
}

int message_free(Message * msg) {
    
    if(!msg)
        return ERROR_TYPENULL;
    
    if(msg->data){
        free(msg->data);
    }
    
    free(msg);
    
    return 0;
}

/*  Possible Updates:
 *  1) Check the upper limit of the size_t
 *  2) Check to see what type of errors could happen with (void *)
 *  3) Need to check and stop copy overflow. ... how?
 */
int message_set_data(Message * msg, char * data, int size) {
    
    // Check message is not NULL
    if(!msg)
        return ERROR_TYPENULL;
    
    // Check data is not NULL
    if(!data)
        return ERROR_TYPEDATA;
    
    // Check size is not 0
    if(!size)
        return ERROR_SIZE;
    
    // Free destination data
    if(msg->data) {
        free(msg->data);
        msg->data = NULL;
    }
    
    // allocate memory with size of size_t size
    msg->data = (char*) malloc(size);
    if(!msg->data)
        return errno;
    
    // copy data to destination buffer with size specified.
    memcpy(msg->data, data, size);
    
    // Returns zero on success
    return 0;
}

int message_set_timestamp(Message * msg, uint64_t timestamp){
    
    // Check if the message struct is NULL -> return error
    if(!msg){
        return ERROR_TYPENULL;
    }
    
    if(timestamp < 0)
        return ERROR_NEGVAL;
    
    msg->time_stamp = timestamp;
    
    return 0;
}
