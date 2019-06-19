#include "ulid_sopas_comm.h"

const char * UserLevelArr[3] = {
    "02","03","04"
};

char * PasswordArr[3] = {
    "B21ACE26", "F4724744", "81BE23AA"
};

/************************ SHARED SOPAS FUNCTIONS ************************/

/*  SOPAS_LogIn */
int SOPAS_LogIn(int sock_id, UserLevel level) {
    
    int check;
    char outMsg[31];
    char retMsg[21];
    bzero(outMsg,sizeof(outMsg));
    bzero(retMsg,sizeof(retMsg));
    
    // Build string
    snprintf(outMsg,31,"\2sMN SetAccessMode %s %s\3",UserLevelArr[level],PasswordArr[level]);
    //printf("outMsg: %s\n", outMsg);
    
    // Send Message
    if(send(sock_id, outMsg, sizeof(outMsg), 0) < 0){
        perror("ERROR: ");
    }
    
    // Recv Message
    check = recv(sock_id, retMsg, sizeof(retMsg), 0);
    if(check < 0){
        perror("ERROR :");
    }
    
    // Check Message --> TODO
    printf("ret: %s\n",retMsg);
    
    return 0;
}




/*  SOPAS Read Scan Configuraiton */
int SOPAS_ReadScanConfig(int sock_id) {
    
    int check;
    char outMsg[1024];
    char retMsg[1024];
    bzero(outMsg,sizeof(outMsg));
    bzero(retMsg,sizeof(retMsg));
    
    strcpy(outMsg,"\2sRN LMPscancfg\3");
    
    send(sock_id,outMsg,sizeof(outMsg),0);
    check = recv(sock_id,retMsg,sizeof(retMsg),0);
    if(check < 0){
        perror("ERROR :");
    }
    
    // Check Message --> TODO
    printf("ret: %s\n",retMsg);
    return 0;
}



/*  */

