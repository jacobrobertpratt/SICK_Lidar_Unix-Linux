/*  All communication related building / messages / structures
 */
#ifndef _ULLID_COMM_FORMAT_HEADER
#define _ULLID_COMM_FORMAT_HEADER

#include "ullid_error.h"
#include "ullid_sick_LMS1xx.h"

// Macros that are used to simplify the code
#define STRT(a)         *a=0x02;a++;
#define SPC(b)          *b=0x20;b++;
#define END(c)          *c=0x03;
#define ADDSTR(a,b,n)   n=strlen(b);strncpy(a,b,n);a+=n;
#define PUT(a,b)        *a=b;a++;

/*  */
enum TelegramType {
    sRA,
    sRN,
    sWN,
    sWA,
    sAN,
    sMN,
    sEN,
    sEA,
    sSN
};

/*  */
enum TelegramComm {
    SetAccessMode,
    mLMPsetscancfg,
    LMPscancfg,
    LCMstate,
    LMDscandatacfg,
    LMPoutputRange,
    LMDscandata,
    LSPsetdatetime,
    STlms,
    mEEwriteall,
    Run,
    LFPparticle,
    LFPmeanfilter,
    LFPnto1filter,
    FREchoFilter,
    MSsuppmode,
    LICsrc,
    LICencset,
    LICencres,
    LICFixVel,
    LICSpTh,
    LICencsp,
    LIDoutputstate,
    mDOSetOutput,
    DO6Fnc,
    DO3And4Fnc,
    LIDrstoutpcnt,
    DeviceIdent,
    SCdevicestate,
    LocationName,
    ODoprh,
    ODpwrc,
    EIIpAddr,
    mSCloadfacdef,
    mSCreboot,
    LCMcfg,
    SYPhase,
    LMLfpFcn,
    LMCstandby,
    LMCstartmeas,
    LMCstopmeas
};

/*  */
enum UserLevel {
    Maintenance,
    Client,
    Service
};

enum IntegerEnum {
    PLUS_1,
    PLUS_1667,
    PLUS_2500,
    PLUS_3333,
    PLUS_3500,
    PLUS_5000,
    PLUS_6667,
    PLUS_7500,
    PLUS_10000,
    PLUS_2250000,
    MIN_450000
};
/*  */
char * teleCommBuilder(enum TelegramComm comEnum, va_list args );

/*  */
char * telegramBuilder(enum TelegramType tele_type, enum TelegramComm tele_comm, ... );

#endif


