#include "ulid_sopas_comm.h"

const char * CommandArr[4] = {
  "sRN","sWN","sMN","sEN"
};

const char * RetCommandArr[6] = {
    "sRA","sWA","sAN","sEA","sSN","sFA"
};

const char * SubjectArr[41] = {
    "SetAccessMode",
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

/*  Number to String
    Returns 1 if number is 0.*/
int SOPAS_NumberToString(char * str, int number) {
    
    if(number == 0){
        // Error --> TODO
        return 1;
    } else if (number > 0){
        sprintf(str,"+%d",number);
    } else {
        sprintf(str,"%d",number);
    }
    return 0;
}

char * SOPAS_BuildSubjectString(Lidar * lidar, Subject subject) {
    
    char * outStr = NULL;
    int msgSize = 0;
    
    switch (subject) {
        case LOGIN:
            // Check for compatibility
            // Calculate size
            msgSize = strlen(SubjectArr[subject]) + strlen(UserLevelArr[lidar->userLevel]) + strlen(PasswordArr[lidar->userLevel]) + 1;
            // allocate memory
            outStr = (char*) malloc(msgSize * sizeof(char));
            // set string
            sprintf(outStr,"%s %s %s",SubjectArr[subject],UserLevelArr[lidar->userLevel],PasswordArr[lidar->userLevel]);
            break;
        case mLMPsetscancfg:
            // Check lidar device for compatability
            
            // Calculate size
            msgSize = strlen(SubjectArr[subject]) + 1;
            // Allocate memory
            
            // Set string
            break;
        case CONFIG: // combine with similar methods
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LCMstate:
            
            break;
        case SCAN_CONFIG:
            
            break;
        case LMPoutputRange:
            
            break;
        case SCAN_DATA: // Reads a single can telegram
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LSPsetdatetime:
            
            break;
        case STlms:
            
            break;
        case HARD_SAVE:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case RUN: // combine with similar methods universal method
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
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
        case HARD_RESET:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case REBOOT:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LCMcfg:
            break;
        case SYPhase:
            break;
        case LMLfpFcn:
            break;
        case LMCstandby:
            break;
        case LMC_START:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LMC_STOP:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
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


/*  */
int SOPAS_DecodeMessage(char * message) {
    
    char *token, *string, *tofree;
    
    tofree = string = strdup(message);
    
    if((token = strsep(&string, " \2\3")) == NULL)
        return 1;
    
    printf("token: %s\n",token);
    
    if(!strcmp(token,RetCommandArr[RET_READ])) {
        printf("Entered: %s statement\n",RetCommandArr[RET_READ]);
    }
    
    if(!strcmp(token,RetCommandArr[RET_WRITE])) {
        printf("Entered: %s statement\n",RetCommandArr[RET_WRITE]);
    }
    
    if(!strcmp(token,RetCommandArr[RET_METHOD])) {
        printf("Entered: %s statement\n",RetCommandArr[RET_METHOD]);
    }
    
    if(!strcmp(token,RetCommandArr[RET_EVENT])) {
        printf("Entered: %s statement\n",RetCommandArr[RET_EVENT]);
    }
    
    if(!strcmp(token,RetCommandArr[RET_CHANGE])) {
        printf("Entered: %s statement\n",RetCommandArr[RET_CHANGE]);
    }
    
    if(!strcmp(token,RetCommandArr[RET_ERROR])) {
        printf("Entered: %s statement\n",RetCommandArr[RET_ERROR]);
    }
    
    free(tofree);
    return 0;
}

