#ifndef __ULID_SOPAS_COM__
#define __ULID_SOPAS_COM__

#include "ulid_common.h"

/*  */
typedef enum command_t {
    READ,
    WRITE,
    METHOD,
    EVENT
} Command;

/*  */
typedef enum subject_t {
    LOGIN,
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
} Subject;

char * SOPAS_BuildSubjectString(Lidar * lidar, Subject subject);

char * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject);


#endif
