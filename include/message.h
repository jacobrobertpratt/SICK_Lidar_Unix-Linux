
/**
 * Write intro here
 */

#ifndef ULID_MESSAGE_H
#define ULID_MESSAGE_H

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
    
    /*  size: is the initial size of the message in bytes */
    uint8_t size;
    
    /*  sendMsg: the information that is return from a lidar device. */
    char * data;
    
} Message;

/**
 * Allocate Message initializes the message and assigns all internal variables to zero or null.
 * All messages should be deallocated with deallocate_message(Message * message).
 * @param NONE
 * @Return Message pointer on success or global ULIDERROR upon failure.
 */
Message * allocate_message();

int deallocate_message(Message * message);

#endif
