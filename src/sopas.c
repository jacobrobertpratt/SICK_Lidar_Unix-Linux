
#include "../include/sopas.h"

static const char * comArr[10] = {
  "sRN","sWN","sMN","sEN","sRA","sWA","sAN","sEA","sSN","sFA"
};

static const char * subArr[41] = {
    "SetAccessMode",        // used for login
    "mLMPsetscancfg",
    "LMPscancfg",
    "LCMstate",
    "LMDscandatacfg",
    "LMPoutputRange",
    "LMDscandata",
    "LSPsetdatetime",
    "STlms",
    "mEEwriteall",
    "Run",
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

static const char * levelArr[3] = {
    "02","03","04"
};

static char * pwArr[3] = {
    "B21ACE26",
    "F4724744",
    "81BE23AA"
};

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

int sopas_login(Sopas * sopas) {
    
    // Create String for login
    char str[32];
    sprintf(str,"\2%s %s %s %s\3",comArr[METHOD],subArr[LOGIN],levelArr[sopas->level],pwArr[sopas->level]);
    printf("str: %s\n",str);
    
    // Send/recv message to lidar
    
    
    // Check return message
    
    
    // Update lidar
    
    
    return 0;
}
