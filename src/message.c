
#include "message.h"

Message * allocate_message(){
    // allocate memory for the Message struct.
    Message * message = (Message *) malloc(sizeof(Message));
    if(message == NULL) {
        printf("ERROR: not enough memory to create message packet --> %s   at   %d\n",__FILE__, __LINE__);
        return NULL;
    }
    
    message->data = NULL;
    message->size = 0;
    return message;
}



int deallocate_message(Message * message) {
    
    if(message == NULL) {
        printf("ERROR: message packet could not be freed --> %s   at   %d\n",__FILE__, __LINE__);
        return 1;
    }
    
    if(message->data != NULL)
        free(message->data);
    
    free(message);
    
    return 0;
}
