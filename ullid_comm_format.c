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

const char * UserLevelArr[3] = {
    "02","03","04"
};

const char * FrequencyArr[5] = {
    "+2500","+3500","+5000","+7500","+10000"
};

//1. Log in:                             sMN SetAccessMode                      (done)
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
            
            // Start
            STRT(buildStr)
            
            // Add Telegram Type (3 characters)
            ADDSTR(buildStr,TelegramTypeArr[typeEnum],strLen);
            
            //Adds a Space
            SPC(buildStr)
            
            // Add Telegram Communication Type(varies)
            ADDSTR(buildStr,TelegramCommArr[commEnum],strLen);
            
            // SPACE
            SPC(buildStr)
            
            
            // Adding the maintenance thing --> try and get this into a common method
            char * userLevel = strdup(va_arg(args,char*));
            
            if(!strcmp(userLevel,"maintenance")){
                PUT(buildStr,'0')
                PUT(buildStr,'2')
            } else if(!strcmp(userLevel,"client")){ // This class is tested
                PUT(buildStr,'0')
                PUT(buildStr,'3')
            } else if(!strcmp(userLevel,"service")){
                PUT(buildStr,'0')
                PUT(buildStr,'4')
            } else {
                LogError("user level access incorrect");
            }
            
            SPC(buildStr) // Adding Space character
            
            // Adding password to string
            char * password = strdup(va_arg(args,char*));
            ADDSTR(buildStr,password,strLen)
            
            // adds the end character
            END(buildStr)
            
            // Free allocated space
            free(password);
            free(userLevel);
            break;
        case mLMPsetscancfg:
            retStr = buildStr = (char*) malloc(52*sizeof(char));
            // Start
            STRT(buildStr)
            
            // Add Telegram Type (3 characters)
            ADDSTR(buildStr,TelegramTypeArr[typeEnum],strLen);
            
            //Adds a Space
            SPC(buildStr)
            
            // Add Telegram Communication Type(varies)
            ADDSTR(buildStr,TelegramCommArr[commEnum],strLen);
            
            // SPACE
            SPC(buildStr)
#ifdef _ULLID_SICK_LMS1XX_HEADER
            
            // Check if LMS1XX is declared
            if(!strcmp(mainLidar,"SICK_LMS1XX")){
                // Set the Frequency
                int freq = va_arg(args,int);
                if(freq == 25){
                    ADDSTR(buildStr,FrequencyArr[hz_25],strLen)
                } else if (freq == 35) {
                    ADDSTR(buildStr,FrequencyArr[hz_35],strLen)
                } else if (freq == 50) {
                    ADDSTR(buildStr,FrequencyArr[hz_50],strLen)
                } else if (freq == 75) {
                    ADDSTR(buildStr,FrequencyArr[hz_75],strLen)
                } else if (freq == 100) {
                    ADDSTR(buildStr,FrequencyArr[hz_100],strLen)
                } else {
                    LogError("failed to recognize freqenecy --> Default 50");
                    ADDSTR(buildStr,FrequencyArr[hz_50],strLen)
                }
            }
            
            
            
#endif
            
#ifdef _ULLID_SICK_LMS5XX_HEADER
#endif
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
            LogError("incorrect communicaton format type");
            break;
    }
    
    printf("%s\n",retStr);
    
    va_end(args);
    return retStr;
}
