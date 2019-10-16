
/**
 * Write intro here
 */

#ifndef ULID_MESSAGE_H
#define ULID_MESSAGE_H

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
    
    /*  Pointer to the information in the message */
    uint8_t * data;
    
    /* The time stamp of the message */
    uint32_t time_stamp;
    
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



#endif
