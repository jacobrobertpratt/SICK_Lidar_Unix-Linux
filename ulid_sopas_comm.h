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
    CONFIG,
    LCMstate,
    LMDscandatacfg,
    LMPoutputRange,
    LMDscandata,
    LSPsetdatetime,
    STlms,
    HARD_SAVE,
    RUN,
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
    HARD_RESET,
    REBOOT,
    LCMcfg,
    SYPhase,
    LMLfpFcn,
    LMCstandby,
    LMC_START,
    LMC_STOP
} Subject;

int SOPAS_NumberToString(char * str, int number);

char * SOPAS_BuildSubjectString(Lidar * lidar, Subject subject);

char * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject);


#endif
