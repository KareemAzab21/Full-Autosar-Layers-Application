#include "Rte_State_Manager.h"
#include "Std_Types.h"
#include "Rte_CDD_IOA.h"
#include "types.h"
#include "Rte.h"

uint8 switch0_st=1;
uint8 switch1_st=1;
State next_st=0;

/*
*Runnable:State_Manager_Runnable_Switch0
*Event Type:periodic
*DATA ACCESS:
* DATA SEND POINT:  Rte_Write_P_Switch0_Switch0_State(Dio_Level Switch0_State)
*/
void State_Manager_Runnable_Switch0(void){

 (void)Rte_Write_State_Manager_P_Switch0_Switch0_State(switch0_st);

}



/*
*Runnable:State_Manager_Runnable_Switch1
*Event Type:periodic
*DATA ACCESS:
* DATA SEND POINT:  Rte_Write_P_Switch1_Switch1_State(Dio_Level Switch1_State)
*/
void State_Manager_Runnable_Switch1(void){
   (void)Rte_Write_State_Manager_P_Switch1_Switch1_State(switch1_st);


}



/*
*Runnable:State_Manager_Runnable_Next
*Event Type:periodic
*DATA ACCESS:
* DATA READ ACCESS:   Next_State    Rte_Read_R_Next_Next_State()
*/
void State_Manager_Runnable_Next(void){
  (void)Rte_Read_State_Manager_R_Next_Next_State(&next_st);


}



/*
*Runnable:State_Manager_Runnable_ReadChannel
*Event Type:periodic
*DATA ACCESS:
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_R_Read_CS_ReadChannel(Dio_Channel_Id CS_ReadChannel_Argument_1,Dio_Level CS_ReadChannel_Argument_2)
*/
void State_Manager_Runnable_ReadChannel(void){
// (void) Rte_Read_State_Machine_R_Switch0_Switch0_State(&switch0_st);
//  (void)Rte_Read_State_Machine_R_Switch1_Switch1_State(&switch1_st);
   CDD_IOA_Runnable_ReadChannel(SWITCH_0,&switch0_st);
   CDD_IOA_Runnable_ReadChannel(SWITCH_1,&switch1_st);



}



/*
*Runnable:State_Manager_Runnable_ClearChannel
*Event Type:periodic
*DATA ACCESS:
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_R_Clear_CS_ClearChannel(Dio_Channel_Id CS_ClearChannel_Argument_1)
*/
void State_Manager_Runnable_ClearChannel(void){
    CDD_IOA_Runnable_ClearChannel(1);
    CDD_IOA_Runnable_ClearChannel(2);
    CDD_IOA_Runnable_ClearChannel(3);

}



/*
*Runnable:State_Manager_Runnable_SetChannel
*Event Type:periodic
*DATA ACCESS:
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_R_Set_CS_SetChannel(Dio_Channel_Id CS_SetChannel_Argument_1)
*/
void State_Manager_Runnable_SetChannel(void){
  switch(next_st)
  {  
  case 1:     CDD_IOA_Runnable_SetChannel(1);
                break;
  case 2:    CDD_IOA_Runnable_SetChannel(2);
                break;
  case 3:   CDD_IOA_Runnable_SetChannel(3);
                break;
  default:      break;
    
  }


}


