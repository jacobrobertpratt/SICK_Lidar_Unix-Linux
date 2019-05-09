/*  All communication related building / messages / structures
 */

#ifndef _ULLID_COMM_FORMAT_HEADER
#define _ULLID_COMM_FORMAT_HEADER

#include "ullid_lidar_type.h"
#include "ullid_error.h"
#include "LMS1XX.h"

/*  */
enum TelegramType {
    STX,
    ETX,
    sRA,
    sRN,
    sWN,
    sWA,
    sAN,
    sMN,
    sEN,
    sEA,
    sSN,
    SPC
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
char * teleCommBuilder(enum TelegramComm comEnum, ... );

/*  */
char * telegramBuilder(enum TelegramType tele_type, enum TelegramComm tele_comm, ... );

/*  */
enum PasswordType {
    Maintenance,
    Client,
    Service
};

#endif


