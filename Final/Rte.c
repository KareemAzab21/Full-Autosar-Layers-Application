#include "Rte_Type.h"
#include "Rte_CDD_IOA.h"


Dio_Level State_Manager_P_Switch0_Switch0_State = 0;
State State_Machine_P_Next_Next_State = 0;
Dio_Level State_Manager_P_Switch1_Switch1_State = 0;


Std_ReturnType Rte_Write_State_Machine_P_Next_Next_State(State data)
{
     State_Machine_P_Next_Next_State = data;
   return E_OK;
}

Std_ReturnType Rte_Read_State_Machine_R_Switch0_Switch0_State(Dio_Level* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      
     CDD_IOA_Runnable_ReadChannel(SWITCH_0,&State_Manager_P_Switch0_Switch0_State);
      *data = State_Manager_P_Switch0_Switch0_State;
      return_value = E_OK;
   }
   return return_value;
}

Std_ReturnType Rte_Read_State_Machine_R_Switch1_Switch1_State(Dio_Level* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      CDD_IOA_Runnable_ReadChannel(SWITCH_1,&State_Manager_P_Switch1_Switch1_State);
      *data = State_Manager_P_Switch1_Switch1_State;
      return_value = E_OK;
   }
   return return_value;
}

Std_ReturnType Rte_Write_State_Manager_P_Switch0_Switch0_State(Dio_Level data)
{
  if(data==STD_LOW ){
    CDD_IOA_Runnable_ClearChannel(SWITCH_0);
  }
  else{
    CDD_IOA_Runnable_SetChannel(SWITCH_0);
  }
     State_Manager_P_Switch0_Switch0_State = data;
   return E_OK;
}

Std_ReturnType Rte_Write_State_Manager_P_Switch1_Switch1_State(Dio_Level data)
{
   if(data==STD_LOW ){
    CDD_IOA_Runnable_ClearChannel(SWITCH_1);
  }
  else{
    CDD_IOA_Runnable_SetChannel(SWITCH_1);
  }
     State_Manager_P_Switch1_Switch1_State = data;
   return E_OK;
}

Std_ReturnType Rte_Read_State_Manager_R_Next_Next_State(State* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      *data = State_Machine_P_Next_Next_State;
      return_value = E_OK;
   }
   return return_value;
}



