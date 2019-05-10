/*
 */

/*  */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/*  */
#include "ullid_comm_format.h"

const char * TelegramTypeArr[9] = {
    "sRA",
    "sRN",
    "sWN",
    "sWA",
    "sAN",
    "sMN",
    "sEN",
    "sEA",
    "sSN",
};

const char * TelegramCommArr[41] = {
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

//1. Log in:                             sMN SetAccessMode


//2. Set Frequency and Resolution:       sMN mLMPsetscancfg


//3. Configure scan data content:        sWN LMDscandatacfg


//4. Configure scan data output:         sWN LMPoutputRange


//5. Store Parameters:                   sMN mEEwriteall


//6. Log out:                            sMN Run


//7. Request Scan:                       sRN LMDscandata / sEN LMDscandata



// This function takes a general telegram and gets the hex code for it.
char * telegramBuilder(enum TelegramType typeEnum, enum TelegramComm commEnum, ... ) {
    
    char * retStr = NULL;
    char * buildStr = NULL;
    int strLen = 0;
    
    va_list args;
    va_start(args,commEnum);
    
    switch (commEnum) {
        case SetAccessMode:
            
            retStr = buildStr = (char*) malloc(31*sizeof(char));
            *buildStr = 0x02;
            buildStr++;
            
            strncpy(buildStr,TelegramTypeArr[typeEnum],3);
            buildStr+=3;
            
            *buildStr=0x20;
            buildStr++;
            
            strLen = strlen(TelegramCommArr[commEnum]);
            printf("%d\n",strLen);
            strncpy(buildStr,TelegramCommArr[commEnum], strLen);
            buildStr+=strLen;
            
            *buildStr=0x20;
            buildStr++;
            
            char * userLevel = strdup(va_arg(args,char*));
            
            if(!strcmp(userLevel,"maintenance")){
                *buildStr = '0';
                buildStr++;
                *buildStr = '2';
                buildStr++;
            } else if(!strcmp(userLevel,"client")){
                *buildStr = '0';
                buildStr++;
                *buildStr = '3';
                buildStr++;
            } else if(!strcmp(userLevel,"service")){
                *buildStr = '0';
                buildStr++;
                *buildStr = '4';
                buildStr++;
            } else {
                LogError("user level access incorrect");
            }
            
            *buildStr = 0x20;
            buildStr++;
            
            char * password = strdup(va_arg(args,char*));
            strncpy(buildStr,password,8); // 4 is a required password length
            buildStr+=8;
            *buildStr=0x03;
            
            free(password);
            free(userLevel);
            
            printf("%s\n",retStr);
            
            break;
        case mLMPsetscancfg:
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
            // LogError
            break;
    }
    
    va_end(args);
    return retStr;
}

