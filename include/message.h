
/**
 * Write intro here ...
 */

#ifndef ULID_MESSAGE_H
#define ULID_MESSAGE_H

/* Global headers*/


/* Local header files */
#include "error.h"

/**
 *  A message class that defines what a message is and functions that are associated
 *  with updating the message class.
 */

/**
 * The messge_t struct defines labels, data, and general information about a message
 * being sent or recieved. The general communication form from a lidar device is by sending a
 * message to the lidar device and in-turn the lidar device sends a message back.
 */
typedef struct message_t {
    
    /* The is the initial size of the message in bytes */
    uint32_t size;
    
    /* Pointer to the information in the message */
    void * data;
    
    /* Set by user in Message_set(). So that we can later
     * tell what type of data has been set in the message. */
    char * data_type;
    
    /* The time stamp of the message */
    uint64_t time_stamp;
    
} Message;

/**
 * Allocate Message initializes the message and assigns all internal variables to zero or null.
 * All messages should be deallocated with deallocate_message(Message * message).
 * @param NONE
 * @Return Message pointer on success or global ULIDERROR upon failure. The global error
 * message will be set to the specific error.
 */
Message * message_alloc();

/**
 * Deallocates a message which has been allocated by allocate_message(). If the input message is
 * NULL, will return appropriate error message.
 * @param message * Message structure.
 * @return error message number.
 */
int message_free(Message * message);

/**
 * Function will take an already allocated Message structure and set the whatever is passed
 * through the data parameter and set it to the data value in Message struct. Size must be the
 * size of the structure or primative type being passed to data. The data can be any structure or primateive. If the Message data type is already allocated, the function will free that data before copying. If the data_type parameter is set to NULL, then the Message data_type will be NULL,
 * else the Message data_type will be allocated and set to the data_type parameter.
 * The data type can later be used to reference what type of data the Message struct holds.
 *
 * Example:

 typedef struct temp_t {
     int a;
     char * b;
 } Tmp;


 int main(int argc, char * argv[]) {
     Tmp tmp;
     tmp.a = 5;
     tmp.b = strdup("this is a test.");
     Message * msg = message_alloc();
     message_set_data(msg, &tmp, sizeof(Tmp),"tmp");
     Tmp * ret;
     if(!strcmp(msg->data_type,"tmp"))
         ret = (Tmp *) msg->data;
     else
         ret = NULL;
     printf("%d , %s\n", ret->a, ret->b);
     message_free(msg);
     return 0;
 }

 * This function will return an error message from the standard errno.h or the local error type
 * message on failure.
 * @param msg the allocated Message structure
 * @param data (void *) source data
 * @param size size of (void*) data (i.e. the size of the type or struct you pass)
 * @param data_type is a string set by user or NULL.
 * @return integer value of error number, (see uliderror(number) to print)
 */
int message_set_data(Message * msg, void * data, size_t size, const char * data_type);

/**
 */


#endif
