#include "Rte_State_Machine.h"
#include "types.h"
#include "Rte.h"

uint8 switch0_state=0;
uint8 switch1_state=0;
state_p next_state=OFF;

/*
*Runnable:State_Machine_Runnable_Switch0
*Event Type:periodic
*DATA ACCESS:
* DATA READ ACCESS:   Switch0_State    Rte_Read_R_Switch0_Switch0_State()
*/
void State_Machine_Runnable_Switch0(void){
  (void)Rte_Read_State_Machine_R_Switch0_Switch0_State(&switch0_state);


}



/*
*Runnable:State_Machine_Runnable_Switch1
*Event Type:periodic
*DATA ACCESS:
* DATA READ ACCESS:   Switch1_State    Rte_Read_R_Switch1_Switch1_State()
*/
void State_Machine_Runnable_Switch1(void){
  (void)Rte_Read_State_Machine_R_Switch0_Switch0_State(&switch1_state);


}



/*
*Runnable:State_Machine_Runnable_Next
*Event Type:periodic
*DATA ACCESS:
* DATA SEND POINT:  Rte_Write_P_Next_Next_State(State Next_State)
*/
void State_Machine_Runnable_Next(void){
  if((switch0_state==1 && switch1_state==1) || (switch0_state==0 && switch1_state==0) )
  {
    //do nothing
  }
  else if(switch0_state==1 && switch1_state==0){
    if(next_state==GREEN)
    {
      //do nothing
    }
    else{
      next_state +=1;
    }
  }
   else if(switch0_state==1 && switch1_state==0){
    if(next_state==RED)
    {
      //do nothing
    }
    else{
      next_state -=1;
    }
  }
  (void)Rte_Write_State_Machine_P_Next_Next_State(next_state);

}


