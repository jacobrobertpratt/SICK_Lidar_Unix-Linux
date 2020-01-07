#ifndef ULID_SOPAS_COM
#define ULID_SOPAS_COM

#include "common.h"
#include "error.h"
#include "socket.h"

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
