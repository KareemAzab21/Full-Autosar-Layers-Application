#include "Rte_CDD_IOA.h"
#include "Dio.h"
#include "Std_Types.h"


/*
*Runnable:CDD_IOA_Runnable_ReadChannel
*Event Type:operation invoked event
*DATA ACCESS:
*/
void CDD_IOA_Runnable_ReadChannel(Dio_Channel_Id CS_ReadChannel_Argument_1,Dio_Level *CS_ReadChannel_Argument_2){
  *CS_ReadChannel_Argument_2=Dio_ReadChannel(CS_ReadChannel_Argument_1);


}



/*
*Runnable:CDD_IOA_Runnable_ClearChannel
*Event Type:operation invoked event
*DATA ACCESS:
*/
void CDD_IOA_Runnable_ClearChannel(Dio_Channel_Id CS_ClearChannel_Argument_1){
  Dio_WriteChannel(CS_ClearChannel_Argument_1, STD_LOW);
  
}



/*
*Runnable:CDD_IOA_Runnable_SetChannel
*Event Type:operation invoked event
*DATA ACCESS:
*/
void CDD_IOA_Runnable_SetChannel(Dio_Channel_Id CS_SetChannel_Argument_1){
  
  Dio_WriteChannel(CS_SetChannel_Argument_1, STD_HIGH);


}


