#ifndef RTE_CDD_IOA_H_
#define RTE_CDD_IOA_H_


#include "Std_Types.h"
#include "Rte.h"

#define SWITCH_0       0
#define SWITCH_1       4


void CDD_IOA_Runnable_ClearChannel(Dio_Channel_Id CS_ClearChannel_Argument_1);

void CDD_IOA_Runnable_ReadChannel(Dio_Channel_Id CS_ReadChannel_Argument_1,Dio_Level *CS_ReadChannel_Argument_2);

void CDD_IOA_Runnable_SetChannel(Dio_Channel_Id CS_SetChannel_Argument_1);


#endif
