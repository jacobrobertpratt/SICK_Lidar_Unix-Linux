
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

