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
} Subject;


/*  SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject)
 *
 *  Takes a Lidar structure, enum command, and enum subject and returns
 *  the a Message structt that can be used.
 *  The returned Message struct must be freed using free().
 *  @param Lidar * lidar, enum Command, enum Subject
 *  @return allocated (char *) upon success, NULL on failure. */
Message * SOPAS_EncodeMessage(Lidar * lidar, Command command, Subject subject);

/*  */
int SOPAS_ExchangeMessage(Lidar * lidar, Message * message);
    
    // Check to make sure lidar is not null and is initialized,
    
    // Check to make sure that the Message is initialized
    
    // Need to check what type of exchange is happening: TCP or UARD ... etc.
    
    // If TCP Connection -->
        
        // 
    
    




#endif
