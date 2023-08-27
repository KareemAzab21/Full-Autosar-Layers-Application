#include "Port.h"
#include "SysTick.h"
#include "types.h"
#include "Dio.h"
#include "Rte.h"
#include "Rte_CDD_IOA.h"
#include "Rte_State_Machine.h"
#include "Rte_State_Manager.h"
#include "Std_Types.h"

uint8 tick=0;
uint8 flag=0;
uint8 switch3_st=1;
int main()
{
  Port_Init();
  SysTick_Disable();
  SysTickPeriodSet(1);
  SysTick_Enable();
  switch3_st=Dio_ReadChannel(4);
   if(switch3_st==0)
  {
    CDD_IOA_Runnable_SetChannel(1);
  }

  while(1){
    if(tick%10==0 && flag==1){
      State_Manager_Runnable_ReadChannel();
      State_Manager_Runnable_Switch0();
      State_Manager_Runnable_Switch1();
      State_Machine_Runnable_Switch0();
      State_Machine_Runnable_Switch1();
      State_Machine_Runnable_Next();
      State_Manager_Runnable_Next();
      State_Manager_Runnable_ClearChannel();
      State_Manager_Runnable_SetChannel();
      flag=0;
      
    }
  }
}

void SysTick_Handler(){
  tick++;
  if(tick%10==0)
  {
    flag=1;
  }
}
