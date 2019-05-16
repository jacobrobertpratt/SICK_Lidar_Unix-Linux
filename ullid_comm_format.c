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

int TelegramLengthArr[2] = {
  31,52
};

const char * UserLevelArr[3] = {
    "02","03","04"
};

const char * PasswordArr[3] = {
    "B21ACE26", "F4724744", "81BE23AA"
};

const char * IntegerEnumArr[8] = {
    "+1",
    "+2500",
    "+3500",
    "+5000",
    "+7500",
    "+10000",
    "+2250000",
    "-450000"
};

// 1. Log in:                             sMN SetAccessMode                      (done)
// 2. Set Frequency and Resolution:       sMN mLMPsetscancfg                     (done)
// 3. Configure scan data content:        sWN LMDscandatacfg                     (working)
// 4. Configure scan data output:         sWN LMPoutputRange
// 5. Store Parameters:                   sMN mEEwriteall
// 6. Log out:                            sMN Run
// 7. Request Scan:                       sRN LMDscandata / sEN LMDscandata

char * stringBuilder(char * buildStr, const char * str) {
    SPC(buildStr)
    return buildStr;
}

char * integerBuilder(char * buildStr, int checkInt) {
    int strLen = 0;
    SPC(buildStr)
    
    // TODO ... 
    
    return buildStr;
}

char * frequencyBuilder(char * buildStr, int checkInt) {
    int strLen = 0;
    SPC(buildStr)
    if(checkInt == 1){
        ADDSTR(buildStr,IntegerEnumArr[PLUS_1],strLen)
    } else if (checkInt == 25) {
        ADDSTR(buildStr,IntegerEnumArr[PLUS_2500],strLen)
    } else if (checkInt == 35) {
        ADDSTR(buildStr,IntegerEnumArr[PLUS_3500],strLen)
    } else if (checkInt == 50) {
        ADDSTR(buildStr,IntegerEnumArr[PLUS_5000],strLen)
    } else if (checkInt == 75) {
        ADDSTR(buildStr,IntegerEnumArr[PLUS_7500],strLen)
    } else if (checkInt == 100) {
        ADDSTR(buildStr,IntegerEnumArr[PLUS_10000],strLen)
    } else {
        LogError("frequency value is not correctly defined");
        buildStr = NULL;
    }
    return buildStr;
}

char * passwordBuilder(char * buildStr, const char * checkStr) {
    int strLen = 0;
    SPC(buildStr)
    if(!strcmp(checkStr,"B21ACE26")) {
        ADDSTR(buildStr,PasswordArr[Maintenance],strLen)
    } else if (!strcmp(checkStr,"F4724744")) {
        ADDSTR(buildStr,PasswordArr[Client],strLen)
    } else if (!strcmp(checkStr,"81BE23AA")) {
        ADDSTR(buildStr,PasswordArr[Service],strLen)
    } else {
        LogError("inccorect password entered.");
        buildStr = NULL;
    }
    return buildStr;
}

char * userlevelBuilder(char * buildStr, const char * checkStr) {
    
    int strLen = 0;
    SPC(buildStr)
    if(!strcmp(checkStr,"maintenance")) {
        ADDSTR(buildStr,UserLevelArr[Maintenance],strLen)
    } else if(!strcmp(checkStr,"client")) {
        ADDSTR(buildStr,UserLevelArr[Client],strLen)
    } else if(!strcmp(checkStr,"service")) {
        ADDSTR(buildStr,UserLevelArr[Service],strLen)
    } else {
        LogError("incorrect user level entered.");
        buildStr = NULL;
    }
    return buildStr;
}

char * argumentBuilder(char * buildStr, const char * fmt, va_list args){
    
    char * str;
    int num;
    
    while (*fmt) {
        switch(*fmt++) {
            case 'u':                       /* user level */
                str = va_arg(args,char*);
                buildStr = userlevelBuilder(buildStr,str);
                if(buildStr == NULL)
                    LogError("userLevel was not correct");
                break;
            case 'p':                       /* password */
                str = va_arg(args,char*);
                buildStr = passwordBuilder(buildStr,str);
                if(buildStr == NULL)
                    LogError("password in argument builder failed.");
                break;
            case 'f':                       /* frequency */
                num = va_arg(args,int);
                buildStr = frequencyBuilder(buildStr,num);
                if(buildStr == NULL)
                    LogError("frequenc argument is not defined");
                break;
            case 'a':                       /* angular resolution */
                num = va_arg(args,int);
                buildStr = integerBuilder(buildStr, num);
                if(buildStr == NULL)
                    LogError("frequenc argument is not defined");
                break;
            default:
                LogError("incorrectly formated character");
                break;
        }
    }
    END(buildStr)
    
    return buildStr;
}

// This function takes a general telegram and gets the hex code for it.
char * telegramBuilder(enum TelegramType typeEnum, enum TelegramComm commEnum, ... ) {
    
    char * retStr = NULL;
    char * buildStr = NULL;
    int strLen = 0;
    int angRes = 0;
    char * fmt = NULL;
    
    int freq;
    
    va_list args;
    va_start(args,commEnum);
    
    // Always sets the start of the telegram message to the specified enum values
    retStr = buildStr = (char*) malloc(TelegramLengthArr[commEnum] * sizeof(char));
    STRT(buildStr)
    ADDSTR(buildStr,TelegramTypeArr[typeEnum],strLen)
    SPC(buildStr)
    ADDSTR(buildStr,TelegramCommArr[commEnum],strLen)
    
    switch (commEnum) {
        case SetAccessMode:
            
            // defines the order in which arguments must be entered
            fmt = strdup("up");
            
            // Build all arguments that are added in va_list
            buildStr = argumentBuilder(buildStr,fmt,args);

            break;
            
        case mLMPsetscancfg:
            
            fmt = strdup("");
            
#ifdef _ULLID_SICK_LMS1XX_HEADER
            
            // TODO --> Need to add the if() statement when adding a LMS1XX type lidar.
            
            fmt = strdup("");
            
            // Set Scan Frequency
            freq = va_arg(args,int);
            if(freq == 25){
                ADDSTR(buildStr,IntegerEnumArr[PLUS_2500],strLen)
            } else if (freq == 50) {
                ADDSTR(buildStr,IntegerEnumArr[PLUS_5000],strLen)
            } else {
                LogError("failed to recognize freqenecy --> Default 50");
                ADDSTR(buildStr,IntegerEnumArr[PLUS_2500],strLen)
            }
            
            SPC(buildStr)
            
            // Set active sector
            ADDSTR(buildStr,IntegerEnumArr[PLUS_1],strLen)
            SPC(buildStr)
            
            // Set angular resoluiton
            angRes = va_arg(args,int);
            if(angRes == 25){
                ADDSTR(buildStr,IntegerEnumArr[PLUS_2500], strLen)
                SPC(buildStr)
            } else if (angRes == 50){
                ADDSTR(buildStr,IntegerEnumArr[PLUS_5000], strLen)
                SPC(buildStr)
            } else {
                ADDSTR(buildStr,IntegerEnumArr[PLUS_2500], strLen)
                SPC(buildStr)
                LogError("no angular resolution set for LMS1XX --> default 0.25 deg");
            }
            
            // Set start angle
            ADDSTR(buildStr,IntegerEnumArr[MIN_450000],strLen)
            SPC(buildStr)
            
            // Set stop angle
            ADDSTR(buildStr,IntegerEnumArr[PLUS_2250000],strLen)
            
#endif
            
#ifdef _ULLID_SICK_LMS5XX_HEADER
            
            // TODO --> Need to add the if() statement when adding a LMS5XX type lidar.
            /*
            freq = va_arg(args,int);
            if(freq == 25){
                ADDSTR(buildStr,FrequencyArr[hz_25],strLen)
            } else if (freq == 35) {
                ADDSTR(buildStr,FrequencyArr[HZ_35],strLen)
            } else if (freq == 50) {
                ADDSTR(buildStr,FrequencyArr[HZ_50],strLen)
            } else if (freq == 75) {
                ADDSTR(buildStr,FrequencyArr[HZ_75],strLen)
            } else if (freq == 100) {
                ADDSTR(buildStr,FrequencyArr[HZ_100],strLen)
            } else {
                LogError("failed to recognize freqenecy --> Default 50");
                ADDSTR(buildStr,FrequencyArr[HZ_50],strLen)
            }
             */
            
#endif
            END(buildStr)
            break;
        case LMPscancfg:
            retStr = buildStr = (char*) malloc(16*sizeof(char));
            STRT(buildStr)
            ADDSTR(buildStr,TelegramTypeArr[typeEnum],strLen);
            SPC(buildStr)
            ADDSTR(buildStr,TelegramCommArr[commEnum],strLen);
            END(buildStr)
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
    
    free(fmt);
    return retStr;
}
