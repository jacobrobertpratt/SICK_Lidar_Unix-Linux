
#include "../include/message.h"


Message * message_alloc(){
    // allocate memory for the Message struct.
    Message * msg = (Message *) malloc(sizeof(Message));
    if(!msg) {
        uliderror(errno);
        return NULL;
    }
    
    msg->data = NULL; // void * of data
    msg->data_type = NULL; // type of data as string
    msg->size = 0; // 32-bit integer
    msg->time_stamp = -1; // 64-bit integer
    
    return msg;
}

int message_reset(Message * msg){
    return 0;
}

int message_free(Message * msg) {
    
    if(!msg)
        return ERROR_TYPENULL;
    
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
    
    if(!msg || !data)
        return ERROR_TYPENULL;
    
    if(!size)
        return ERROR_SIZE;
    
    // Free destination data
    if(msg->data) {
        free(msg->data);
        msg->data = NULL;
    }
    
    // allocate memory with size of size_t size
    msg->data = (uint8_t*) malloc(size);
    if(!msg->data)
        return errno;
    
    // copy data to destination buffer with size specified.
    memcpy(msg->data, data, size);
    
    /* Sets the data type as a string so that it can be later used
     * to understand what kind of data was set in the message. */
    if(data_type){
        if(!msg->data_type)
            free(msg->data_type);
        msg->data_type = strdup(data_type);
    }
    
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
