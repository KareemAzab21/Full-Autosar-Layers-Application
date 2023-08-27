#ifndef RTE_H_
#define RTE_H_


#include "Rte_Type.h"




#ifdef RTE_CDD_IOA_H_

#endif


#ifdef RTE_STATE_MACHINE_H_
Std_ReturnType Rte_Write_State_Machine_P_Next_Next_State(State data);
Std_ReturnType Rte_IRead_Switch0_State_State_Machine_R_Switch0_State_Machine_Runnable_Switch0 (Dio_Level* data);
Std_ReturnType Rte_IRead_Switch1_State_State_Machine_R_Switch1_State_Machine_Runnable_Switch1 (Dio_Level* data);

#endif


#ifdef RTE_STATE_MANAGER_H_
Std_ReturnType Rte_Write_State_Manager_P_Switch0_Switch0_State(Dio_Level data);
Std_ReturnType Rte_Write_State_Manager_P_Switch1_Switch1_State(Dio_Level data);
Std_ReturnType Rte_IRead_Next_State_State_Manager_R_Next_State_Manager_Runnable_Next (State* data);

#endif

Std_ReturnType Rte_Write_State_Machine_P_Next_Next_State(State data);
Std_ReturnType Rte_Read_State_Machine_R_Switch0_Switch0_State(Dio_Level* data);
Std_ReturnType Rte_Read_State_Machine_R_Switch1_Switch1_State(Dio_Level* data);
Std_ReturnType Rte_Write_State_Manager_P_Switch0_Switch0_State(Dio_Level data);
Std_ReturnType Rte_Write_State_Manager_P_Switch1_Switch1_State(Dio_Level data);
Std_ReturnType Rte_Read_State_Manager_R_Next_Next_State(State* data);



#endif
