#include "ulid_sopas_comm.h"


static const char * CommandArr[10] = {
  "sRN","sWN","sMN","sEN","sRA","sWA","sAN","sEA","sSN","sFA"
};

static const char * SubjectArr[41] = {
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


char * PasswordArr[3] = {
    "B21ACE26",
    "F4724744",
    "81BE23AA"
};

/*  SOPAS_EncodeSubjectString(Lidar * lidar, Subject subject)
 *  */
static char * SOPAS_EncodeSubjectString(Lidar * lidar, Subject subject) {
    
    char * outStr = NULL;
    int msgSize = 0;
    
    switch (subject) {
        case SetAccessMode:
            printf("Need to implement subject %s at %d\n",SubjectArr[subject],__LINE__);
            lidar->callbacks.destroyLidar(lidar);
            break;
        case mLMPsetscancfg:
            // Check lidar device for compatability
            // Calculate size
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
        case LMDscandata: // Reads a single scan telegram
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
            msgSize = strlen(SubjectArr[subject]) + 1;
            outStr = (char*) malloc(msgSize * sizeof(char));
            sprintf(outStr,"%s",SubjectArr[subject]);
            break;
        case Run:
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


Message * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject) {
    
    // What to check?
    
    char * tmp_msg = SOPAS_EncodeSubjectString(lidar,subject);
    
    int msgLen = strlen(tmp_msg) + 5;
    
    // Allocate memory
    char * outMsg = (char*) malloc(msgLen * sizeof(char));
    if(!outMsg){
        printf("ERROR: outMsg failed to allocate memory --> %s   @   %d\n", __FUNCTION__, __LINE__);
        return NULL;
    }
    
    // build the strings
    sprintf(outMsg,"\2%s %s\3",CommandArr[command],tmp_msg);
    
    // Free memory after string is set
    free(tmp_msg);
    
    // Create a Message struct and set the 
    Message * retMsg = CreateMessagePacket();
    retMsg->data = outMsg;
    
    retMsg->size = strlen(outMsg);
    
    
    return retMsg;
     
}




