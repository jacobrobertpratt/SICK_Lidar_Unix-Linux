#ifndef ULID_SOPAS_COM
#define ULID_SOPAS_COM

#include "common.h"
#include "error.h"
#include "socket.h"

/** CLASS DEFINITION:
 * This class represents a SOPAS style telegram lidar device, which is a product of the SICK corporation. It consists of a sopas_t structure, allocations, deallocations, and calls to the many different capabilities that SOPAS devices offer. For each lidar device a telegram is sent to the device and then returned with information. Please refer to the SOPAS Telegram Listing documentation for more information.
 *
 * @Author Jacob Robert Pratt
 * @Date Jan 7th, 2020
 */

#define SOPAS_STRUCT_CODE 0x0006

typedef enum command_t {
    READ,
    WRITE,
    METHOD,
    EVENT,
    RETREAD,
    RETWRITE,
    RETMETHOD,
    RETEVENT,
    RETCHANGE,
    ERROR
} Command;

typedef enum subject_t {
    SCAN = 6
} Subject;

typedef struct sopas_t {
    
    // Call sign of this structure for deallocations purposes.
    int struct_code;
    
    // User level
    uint8_t level;
    
    // Sopas password
    char password[9];
    
    // Socket connection
    Socket * sock;
    
} Sopas;


//
Sopas * sopas_alloc();


//
int sopas_free(Sopas * sopas);


//
int sopas_scanOnce(Sopas * sopas);

#endif
