#include "ulid_sopas_comm.h"

const char * CommandArr[4] = {
  "sRN","sWN","sMN","sEN"
};

const char * SubjectArr[41] = {
    "SetAccessMode",
    "mLMPsetscancfg",
    "LMPscancfg",
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

int outMsgSize[1] = {
    31
};

int retMsgSize[1] = {
    21
};

const char * UserLevelArr[3] = {
    "02","03","04"
};

// Possible to cause a problem since the password and user level are defined in the ulid_common.h
char * PasswordArr[3] = {
    "B21ACE26",
    "F4724744",
    "81BE23AA"
};

char * SOPAS_BuildSubjectString(Lidar * lidar, Subject subject) {
    
    char * outStr = NULL;
    int msgSize = 0;
    
    switch (subject) {
        case LOGIN:
            // Calculate size
            msgSize = strlen(SubjectArr[subject]) + strlen(UserLevelArr[lidar->userLevel])      \
            + strlen(PasswordArr[lidar->userLevel]) + 1;
            // allocate memory
            outStr = (char*) malloc(msgSize * sizeof(char));
            // set string
            sprintf(outStr,"%s %s %s",SubjectArr[subject],UserLevelArr[lidar->userLevel],PasswordArr[lidar->userLevel]);
            break;
        case mLMPsetscancfg:
            // Check lidar device for compatability
            // Calculate size
            // Allocate memory
            // Set string
            break;
        case LMPscancfg:
            
            break;
        case LCMstate:
            
            break;
        case LMDscandatacfg:
            
            break;
        case LMPoutputRange:
            
            break;
        case LMDscandata:
            
            break;
        case LSPsetdatetime:
            
            break;
        case STlms:
            
            break;
        case mEEwriteall:
            
            break;
        case Run:
            
            
            break;
        case LFPparticle:
            break;
        case LFPmeanfilter:
            break;
        case LFPnto1filter:
            break;
        case FREchoFilter:
            break;
        case MSsuppmode:
            break;
        case LICsrc:
            break;
        case LICencset:
            break;
        case LICencres:
            break;
        case LICFixVel:
            break;
        case LICSpTh:
            break;
        case LICencsp:
            break;
        case LIDoutputstate:
            break;
        case mDOSetOutput:
            break;
        case DO6Fnc:
            break;
        case DO3And4Fnc:
            break;
        case LIDrstoutpcnt:
            break;
        case DeviceIdent:
            break;
        case SCdevicestate:
            break;
        case LocationName:
            break;
        case ODoprh:
            break;
        case ODpwrc:
            break;
        case EIIpAddr:
            break;
        case mSCloadfacdef:
            break;
        case mSCreboot:
            break;
        case LCMcfg:
            break;
        case SYPhase:
            break;
        case LMLfpFcn:
            break;
        case LMCstandby:
            break;
        case LMCstartmeas:
            break;
        case LMCstopmeas:
            break;
        default:
            // Log error -->
            break;
    }
    return outStr;
}

// Make a method to generate string ... verbose? NO ... pulls information from Lidar Struct
    // Ex. foo1(lidar,METHOD,LOGIN); --> Logs into the lidar
    // Ex. foo2(lidar,METHOD,START_MEASURMENT);
    // ...

// 1) for - loop to get command string
// 2) for - loop to get

/*  SOPAS_EncodeMessage
    Must free memory after recieved. Wise to allocate specific local string and free this right away. */
char * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject) {
    
    char * tmp_msg = SOPAS_BuildSubjectString(lidar,subject);
    
    int msgLen = strlen(tmp_msg) + 5;
    
    // Allocate memory
    char * outMsg = (char*) malloc(msgLen * sizeof(char));
    if(!outMsg)
        printf("ERROR: outMsg failed to allocate memory --> %s   @   %d\n", __FUNCTION__, __LINE__);
    
    // build the strings
    sprintf(outMsg,"\2%s %s\3",CommandArr[command],tmp_msg);
    
    // Free memory after string is set
    free(tmp_msg);
    
    //printf("outMsg(%lu): %s\n",strlen(outMsg),outMsg);
    return outMsg;
}

