
#include "../include/sopas.h"

static const char * comArr[10] = {
    "sRN",
    "sWN",
    "sMN",
    "sEN",
    "sRA",
    "sWA",
    "sAN",
    "sEA",
    "sSN",
    "sFA"
};

static const char * subArr[41] = {
    "SetAccessMode",    // used for login
    "mLMPsetscancfg",
    "LMPscancfg",
    "LCMstate",
    "LMDscandatacfg",
    "LMPoutputRange",
    "LMDscandata",      // Get raw scan information (ang & dist)
    "LSPsetdatetime",
    "STlms",
    "mEEwriteall",
    "Run",              // used for logout or start the machine
    "LFPparticle",
    "LFPmeanfilter",
    "LFPnto1filter",
    "FREchoFilter",
    "MSsuppmode",
    "LICsrc",
    "LICencset",
    "LICencres",
    "LICFixVel",
    "LICSpTh",
    "LICencsp",
    "LIDoutputstate",
    "mDOSetOutput",
    "DO6Fnc",
    "DO3And4Fnc",
    "LIDrstoutpcnt",
    "DeviceIdent",
    "SCdevicestate",
    "LocationName",
    "ODoprh",
    "ODpwrc",
    "EIIpAddr",
    "mSCloadfacdef",
    "mSCreboot",
    "LCMcfg",
    "SYPhase",
    "LMLfpFcn",
    "LMCstandby",
    "LMCstartmeas",
    "LMCstopmeas"
};

/*
static const char * levelArr[3] = {
    "02","03","04"
};

static char * pwArr[3] = {
    "B21ACE26",
    "F4724744",
    "81BE23AA"
};
*/

Sopas * sopas_alloc() {
    
    Sopas * sopas = (Sopas *) malloc(sizeof(Sopas));
    if(!sopas) {
        uliderror(errno);
        return NULL;
    }
    
    // Set the struct code
    sopas->struct_code = SOPAS_STRUCT_CODE;
    
    // User level --> init to zero
    sopas->level = 0;
    
    // Zero out password buffer
    memset(sopas->password, 0, 9);
    
    // Allocate Socket structure
    sopas->sock = socket_alloc();
        
    return sopas;
}


int sopas_free(Sopas ** sopas) {
    
    if(!(*sopas)) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    if((*sopas)->struct_code != SOPAS_STRUCT_CODE) {
        uliderror(ERROR_STRUCTCODE);
        return ERROR_STRUCTCODE;
    }
    
    if((*sopas)->sock)
        socket_free((*sopas)->sock);
    
    free(*sopas);
    *sopas = NULL;
    
    return 0;
}

int sopas_scanOnce(Sopas * sopas, Telegram * tele) {
    
    int ret = 0, i, j; // function error messages and loop vars
    time_t time_stamp;
    
    // sopas cannot be NULL
    if(!sopas) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    // Send/recv message to lidar
    if(!sopas->sock->connected) {
        uliderror(ERROR_SOCKCONNECT);
        return ERROR_SOCKCONNECT;
    }
    
    // Build message to send to lidar
    char str[18];
    sprintf(str,"\2%s %s\3",comArr[READ],subArr[SCAN]);
    
    // Implement exchange method for socket
    char * retMsg = NULL;
    ret = socket_exchange(sopas->sock, str, &retMsg);
    if(ret) {
        uliderror(ERROR_SOCKMSG);
        if(retMsg)
            free(retMsg);
        return ERROR_SOCKMSG;
    }
    
    time(&time_stamp);
    tele->sys_timestamp = time_stamp;
    
    // Build char * arr[] for tokens
    int count = countTokens(retMsg,' ');
    char * arr[count];
    ret = stringToTokenArray(retMsg, arr, " \2\3", count);
    if(ret) {
        // TODO:
        return -1;
    }
    
    // Check if return message is correct
    if(strcmp(arr[0],comArr[RETREAD]) || strcmp(arr[1], subArr[SCAN])) {
        printf("return message: %s\n",retMsg);
        uliderror(ERROR_RETMSG);
        return ERROR_RETMSG;
    }
    
    // arr[2] --> version #
    // arr[4] --> serial number (SAVE)
    // arr[5] & arr[6] --> Device status 0 0 means okay
    // arr[7] --> telegram counter
    // arr[8] --> scan counter
    // arr[9] --> Time since start up in μs
    // arr[11] & arr[12] --> Status of digital inputs
    // arr[13] & arr[14] --> Status of digital outputs
    
    // arr[3] --> device # (SAVE)
    tele->device_number = strtol(arr[3], NULL, 16);

    // arr[10] --> Time of transmission in μs (SAVE)
    tele->device_timestamp = strtol(arr[10], NULL, 16);
    
    // arr[16] --> scan frequency (1/100 Hz)
    tele->scan_freq.num = strtol(arr[16], NULL, 16);
    
    tele->scan_freq.den = 100; // sopas specific
    
    // arr[17] --> measurment frequency (time between two shots)
    
    // arr[19] --> output channels
    tele->channel = strtol(arr[19], NULL, 16);
    
    // arr[20] --> DIST1 context of output channel
    
    // arr[21] --> scale factor (SAVE) 1x or 2x
    tele->scale_factor = strtol(arr[21], NULL, 16);
    
    // arr[22] --> scale factor offset ?????
    
    // arr[23] --> start angle (SAVE)
    tele->start_angle.num = strtol(arr[23], NULL, 16);
    tele->start_angle.den = 10000; // sopas secific
    
    // arr[24] --> Size of single angular step (Output format in degree: 1/10000°) (SAVE)
    tele->angular_step.num = strtol(arr[24], NULL, 16);
    tele->angular_step.den = 10000; // sopas specific
    
    // arr[25] --> amount of data (Defines the number of items on measured output) (SAVE)
    tele->data_count = strtol(arr[25], NULL, 16);
    
    // allocate data array
    tele->data = (uint32_t*) malloc(tele->data_count * sizeof(uint32_t));
    if(!(tele->data)) {
        uliderror(errno);
        return errno;
    }
    
    // load data into array
    for(j = 0, i = 26; j < tele->data_count; i++, j++) {
        //printf("[%d,%ld]\n", ang, strtol(arr[i], NULL, 16));
        tele->data[j] = strtol(arr[i], NULL, 16);
        if(tele->data[j] > tele->max_dist) tele->max_dist = tele->data[j];
    }
    
    if(retMsg)
        free(retMsg);
    
    return 0;
}
