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
    Returns 1 if number is 0.
static int SOPAS_NumberToString(char * str, int number) {
    
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
*/

static char * SOPAS_EncodeSubjectString(Lidar * lidar, Subject subject) {
    
    char * outStr = NULL;
    int msgSize = 0;
    
    switch (subject) {
        case SetAccessMode:
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
        case LMPscancfg: // combine with similar methods
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LCMstate:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMDscandatacfg:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMPoutputRange:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMDscandata: // Reads a single can telegram
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LSPsetdatetime:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case STlms:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mEEwriteall:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case Run: // combine with similar methods universal method
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LFPparticle:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LFPmeanfilter:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LFPnto1filter:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case FREchoFilter:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case MSsuppmode:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICsrc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICencset:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICencres:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICFixVel:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICSpTh:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICencsp:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LIDoutputstate:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mDOSetOutput:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case DO6Fnc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case DO3And4Fnc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LIDrstoutpcnt:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case DeviceIdent:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case SCdevicestate:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LocationName:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case ODoprh:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case ODpwrc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case EIIpAddr:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mSCloadfacdef:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case mSCreboot:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LCMcfg:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case SYPhase:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMLfpFcn:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMCstandby:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMCstartmeas:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case LMCstopmeas:
            // Check compatability ...
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        default:
            // Log error -->
            printf("ERROR: subject doesn't exists --> %s  at  %d\n",__FUNCTION__,__LINE__);
            break;
    }
    return outStr;
}

/*  SOPAS_EncodeMessage
    Must free memory after recieved. Wise to allocate specific local string and free this right away. */
char * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject) {
    
    char * tmp_msg = SOPAS_EncodeSubjectString(lidar,subject);
    
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


static int SOPAS_DecodeSubjectString(Lidar * lidar, Subject subject, Message * message) {
    
    //printf("Entered %s function \n", __FUNCTION__);
    
    switch (subject) {
        case SetAccessMode:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mLMPsetscancfg:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMPscancfg:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LCMstate:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMDscandatacfg:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMPoutputRange:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMDscandata:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LSPsetdatetime:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case STlms:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mEEwriteall:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case Run:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LFPparticle:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LFPmeanfilter:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LFPnto1filter:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case FREchoFilter:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case MSsuppmode:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICsrc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICencset:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICencres:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICFixVel:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICSpTh:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LICencsp:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LIDoutputstate:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mDOSetOutput:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case DO6Fnc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case DO3And4Fnc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LIDrstoutpcnt:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case DeviceIdent:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case SCdevicestate:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LocationName:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case ODoprh:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case ODpwrc:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case EIIpAddr:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mSCloadfacdef:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mSCreboot:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LCMcfg:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case SYPhase:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMLfpFcn:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMCstandby:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMCstartmeas:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case LMCstopmeas:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        default:
            // Log error -->
            printf("ERROR: subject doesn't exists --> %s  at  %d\n",__FUNCTION__,__LINE__);
            break;
    }
    return 0;
}

/*  */
int SOPAS_DecodeMessage(Lidar * lidar, Message * message) {
    
    int index;
    
    char **ap, *argv[2], *inputstring;
    
    // Copy retMsg to tmp location --> not sure if we need this
    inputstring = strdup(message->retMsg);
    
    for (ap = argv; (*ap = strsep(&inputstring, " \2\3")) != NULL;)
        if (**ap != '\0')
            if (++ap >= &argv[2])
                break;
    
    // gets subject argument index
    for(index = 0; index < 41; index++) {
        if(!strcmp(argv[1],SubjectArr[index])){
            printf("argv[1]: %s\n", argv[1]);
            break;
        }
    }
    
    //
    if(!strcmp(argv[0],RetCommandArr[RET_READ])) {
        printf("Entered: implement %s statement\n",RetCommandArr[RET_READ]);
        SOPAS_DecodeSubjectString(lidar, index, message);
        
    }else if(!strcmp(argv[0],RetCommandArr[RET_WRITE])) {
        printf("Entered: implement %s statement\n",RetCommandArr[RET_READ]);
        SOPAS_DecodeSubjectString(lidar, index, message);
        
    } else if(!strcmp(argv[0],RetCommandArr[RET_METHOD])) {
        printf("Entered: implement %s statement\n",RetCommandArr[RET_READ]);
        SOPAS_DecodeSubjectString(lidar, index, message);
        
    } else if(!strcmp(argv[0],RetCommandArr[RET_EVENT])) {
        printf("Entered: implement %s statement\n",RetCommandArr[RET_READ]);
        SOPAS_DecodeSubjectString(lidar, index, message);
        
    } else if(!strcmp(argv[0],RetCommandArr[RET_CHANGE])) {
        printf("Entered: implement %s statement\n",RetCommandArr[RET_READ]);
        SOPAS_DecodeSubjectString(lidar, index, message);
        
    } else if(!strcmp(argv[0],RetCommandArr[RET_ERROR])) {
        printf("Entered: implement %s statement\n",RetCommandArr[RET_READ]);
        SOPAS_DecodeSubjectString(lidar, index, message);
        
    } else {
        printf("ERROR: unrecognized sopas return message --> %s  at  %d\n",__FUNCTION__,__LINE__);
        return -1;
    }
    
    free(inputstring);
    
    return 0;
}

