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
#include "LMS1XX.h"

const char * type_arr[12] = {
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

const char * comm_arr[41] = {
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

char * teleCommBuilder(enum TelegramComm comEnum, va_list args ) {
    
    char * retStr = NULL;
    char * buildStr = NULL;
    int strLen = 0;
    //char * va_string;
    
    switch (comEnum) {
        case SetAccessMode:
            
            strLen = strlen(comm_arr[comEnum]);
            
            buildStr = (char*) malloc(31*sizeof(char));
            
            retStr = buildStr;
            buildStr+=4;
            *buildStr=0x20;
            buildStr++;
            strncpy(buildStr,comm_arr[comEnum], strLen);
            buildStr+=strLen;
            *buildStr=0x20;
            buildStr++;
            
            char * testStr = strdup(va_arg(args,char*));
            
            if(!strcmp(testStr,"maintenance")){
                *buildStr = '0';
                buildStr++;
                *buildStr = '2';
                buildStr++;
            } else if(!strcmp(testStr,"client")){
                *buildStr = '0';
                buildStr++;
                *buildStr = '3';
                buildStr++;
            } else if(!strcmp(testStr,"service")){
                *buildStr = '0';
                buildStr++;
                *buildStr = '4';
                buildStr++;
            } else {
                // ERROR TODO --> need to set up error reporting.
                printf("Error: SetAccessMode failed.");
            }
            
            *buildStr = 0x20;
            buildStr++;
            
            char * password = strdup(va_arg(args,char*));
            strLen = strlen(password);
            
            strncpy(buildStr,password,strLen);
            buildStr+=strLen;
            *buildStr=0x03;
            
            free(password);
            free(testStr);
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
            logError("Uknown Comm type",__FILE__, __LINE__);
        break;
    }
    
    return retStr;
}


//1. Log in:                             sMN SetAccessMode


//2. Set Frequency and Resolution:       sMN mLMPsetscancfg


//3. Configure scan data content:        sWN LMDscandatacfg


//4. Configure scan data output:         sWN LMPoutputRange


//5. Store Parameters:                   sMN mEEwriteall


//6. Log out:                            sMN Run


//7. Request Scan:                       sRN LMDscandata / sEN LMDscandata



// This function takes a general telegram and gets the
// hex code for it.
char * telegramBuilder(enum TelegramType tele_type, enum TelegramComm comm_type, ... ) {
    
    char * retStr = NULL;
    char * builtStr = NULL;
    
    va_list args;
    va_start(args,comm_type);
    
    builtStr = retStr = teleCommBuilder(comm_type, args);
    *builtStr = 0x02;
    builtStr++;
    strncpy(builtStr,type_arr[tele_type],3);
    
    /*
    switch (tele_type) {
        case sRA:
            break;
        case sRN:
            break;
        case sWN:
            break;
        case sWA:
            break;
        case sAN:
            break;
        case sMN:
            builtStr = retStr = teleCommBuilder(comm_type, args);
            *builtStr = 0x02;
            builtStr++;
            strncpy(builtStr,type_arr[tele_type],3);
            break;
        case sEN:
            break;
        case sEA:
            break;
        case sSN:
            break;
        default:
            break;
     
    }
    */
    
    va_end(args);
    return retStr;
}

