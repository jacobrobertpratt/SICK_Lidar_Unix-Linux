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

typedef enum ret_command_t {
    RET_READ,
    RET_WRITE,
    RET_METHOD,
    RET_EVENT,
    RET_CHANGE,
    RET_ERROR
} RetCommand;

/*  */
typedef enum subject_t {
    LOGIN,
    mLMPsetscancfg,
    CONFIG,
    LCMstate,
    SCAN_CONFIG,
    LMPoutputRange,
    SCAN_DATA,
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

/*  */
char * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject);

/*  */
int SOPAS_DecodeMessage(char * message);

#endif
