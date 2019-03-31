/*
 */

/**/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**/
#include "ullid_comm_format.h"
#include "ullid_error.h"

const char * type_str[12] = {
    "<STX>",
    "<ETX>",
    "sRA",
    "sRN",
    "sWN",
    "sWA",
    "sAN",
    "sMN",
    "sEN",
    "sEA",
    "sSN",
    "{SPC}"
};

const char * comm_str[41] = {
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



/*

// This function takes a general telegram and gets the
// hex code for it.
char * telegramBuilder(const char * format, ... ) {
    
    char * telegram;
    char * telegram_ret;
    int mem_size = sizeof(char) * strlen(format) + 2;
    int int_count = 0;
    
    const char * tmp_format = format;
    
    // Getting the integer counts
    while(*format != '\0'){
        if(*format == '%') {
            format++;
            if(*format == 'd') {    // gets the number of integers
                int_count++;
            }
        }
        format++;
    }
    
    // Counts the size of memory needed
    mem_size = mem_size + 10 * int_count;
    telegram_ret = telegram = (char *) malloc(mem_size); // allocates memory
    memset(telegram, '0', mem_size); // zeros the allocation.
    
    *telegram = 0x02; // <STX> --> START Telegram
    telegram++;
    
    va_list args;
    va_start(args,format);
    
    format = tmp_format;
    
    while(*format != '\0'){
        if(*format == '%') {            // TelegramComm --> String
            format++;
            if(*format == 'd') {
                
            }
        }
        *telegram = *format;
        telegram++;
        format++;
    }
    
    va_end(args);
    
    *telegram = 0x03; // <ETX> --> END Telegram
    
    return telegram_ret;
}
*/
