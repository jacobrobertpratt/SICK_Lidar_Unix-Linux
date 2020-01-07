
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
    memset(sopas->password,0,9);
    
    // Allocate Socket structure
    sopas->sock = socket_alloc();
        
    return sopas;
}


int sopas_free(Sopas * sopas) {
    
    if(!sopas) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    if(sopas->struct_code != SOPAS_STRUCT_CODE) {
        uliderror(ERROR_STRUCTCODE);
        return ERROR_STRUCTCODE;
    }
    
    if(sopas->sock)
        socket_free(sopas->sock);
    
    free(sopas);
    
    return 0;
}


int sopas_scanOnce(Sopas * sopas) {
    
    int ret = 0, i, j; // function error messages and loop vars
    
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
        uliderror(ERROR_RETMSG);
        return ERROR_RETMSG;
    }
    
    // TODO: build a telegram struct or update the message class
    
    // arr[2] --> version #
    // arr[3] --> device # (SAVE)
    // arr[4] --> serial number (SAVE)
    // arr[5] & arr[6] --> Device status 0 0 means okay
    // arr[7] --> telegram counter
    // arr[8] --> scan counter
    // arr[9] --> Time since start up in μs
    // arr[10] --> Time of transmission in μs (SAVE)
    // arr[11] & arr[12] --> Status of digital inputs
    // arr[13] & arr[14] --> Status of digital outputs
    
    // arr[16] --> scan frequency
    // arr[17] --> measurment frequency
    // arr[19] --> output channels
    // arr[20] --> DIST1 context of output channel
    // arr[21] --> scale factor (SAVE) 1x or 2x
    // arr[22] --> scale factor offset
    // arr[23] --> start angle (SAVE)
    // arr[24] --> Size of single angular step (Output format in degree: 1/10000°) (SAVE)
    // arr[25] --> amount of data (Defines the number of items on measured output) (SAVE)
    // arr[26] --> start of data
    
    uint16_t datasize = strtol(arr[25],NULL,16);
    
    
    uint32_t startangle = strtol(arr[23],NULL,16);
    
    
    uint16_t angstep = strtol(arr[24],NULL,16);
    
    
    for(j = 0, i = 26; j < datasize; i++, j++) {
        uint32_t ang = (j * angstep) + startangle;
        printf("[%d,%ld]\n", ang, strtol(arr[i],NULL,16));
    }
    
    if(retMsg)
        free(retMsg);
    
    return 0;
}
