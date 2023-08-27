#ifndef RTE_STATE_MACHINE_H_
#define RTE_STATE_MACHINE_H_


#include "Rte.h"




#define    Rte_Write_P_Next_Next_State(data)     (Rte_Write_State_Machine_P_Next_Next_State(data))
#define    Rte_IRead_State_Machine_Runnable_Switch0_R_Switch0_Switch0_State (&data)     (Rte_IRead_Switch0_State_State_Machine_R_Switch0_State_Machine_Runnable_Switch0 (&data))
#define    Rte_IRead_State_Machine_Runnable_Switch1_R_Switch1_Switch1_State (&data)     (Rte_IRead_Switch1_State_State_Machine_R_Switch1_State_Machine_Runnable_Switch1 (&data))

typedef enum{
  OFF,RED,BLUE,GREEN
}state_p;



void State_Machine_Runnable_Switch0(void);
void State_Machine_Runnable_Switch1(void);
void State_Machine_Runnable_Next(void);

#endif


