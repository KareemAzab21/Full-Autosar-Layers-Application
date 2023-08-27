#ifndef RTE_STATE_MANAGER_H_
#define RTE_STATE_MANAGER_H_


#include "Rte.h"


extern void CDD_IOA_Runnable_SetChannel(Dio_Channel_Id CS_SetChannel_Argument_1);
extern void CDD_IOA_Runnable_ReadChannel(Dio_Channel_Id CS_ReadChannel_Argument_1,Dio_Level* CS_ReadChannel_Argument_2);
extern void CDD_IOA_Runnable_ClearChannel(Dio_Channel_Id CS_ClearChannel_Argument_1);


#define    Rte_Write_P_Switch0_Switch0_State(data)     (Rte_Write_State_Manager_P_Switch0_Switch0_State(data))
#define    Rte_Write_P_Switch1_Switch1_State(data)     (Rte_Write_State_Manager_P_Switch1_Switch1_State(data))
#define    Rte_Call_R_Read_CS_ReadChannel(CS_ReadChannel_Argument_1,CS_ReadChannel_Argument_2)     (CDD_IOA_Runnable_ReadChannel(CS_ReadChannel_Argument_1,CS_ReadChannel_Argument_2))
#define    Rte_Call_R_Read_CS_ClearChannel(CS_ClearChannel_Argument_1)     (CDD_IOA_Runnable_ClearChannel(CS_ClearChannel_Argument_1))
#define    Rte_Call_R_Read_CS_SetChannel(CS_SetChannel_Argument_1)     (CDD_IOA_Runnable_SetChannel(CS_SetChannel_Argument_1))
#define    Rte_Call_R_Clear_CS_ReadChannel(CS_ReadChannel_Argument_1,CS_ReadChannel_Argument_2)     (CDD_IOA_Runnable_ReadChannel(CS_ReadChannel_Argument_1,CS_ReadChannel_Argument_2))
#define    Rte_Call_R_Clear_CS_ClearChannel(CS_ClearChannel_Argument_1)     (CDD_IOA_Runnable_ClearChannel(CS_ClearChannel_Argument_1))
#define    Rte_Call_R_Clear_CS_SetChannel(CS_SetChannel_Argument_1)     (CDD_IOA_Runnable_SetChannel(CS_SetChannel_Argument_1))
#define    Rte_Call_R_Set_CS_ReadChannel(CS_ReadChannel_Argument_1,CS_ReadChannel_Argument_2)     (CDD_IOA_Runnable_ReadChannel(CS_ReadChannel_Argument_1,CS_ReadChannel_Argument_2))
#define    Rte_Call_R_Set_CS_ClearChannel(CS_ClearChannel_Argument_1)     (CDD_IOA_Runnable_ClearChannel(CS_ClearChannel_Argument_1))
#define    Rte_Call_R_Set_CS_SetChannel(CS_SetChannel_Argument_1)     (CDD_IOA_Runnable_SetChannel(CS_SetChannel_Argument_1))
#define    Rte_IRead_State_Manager_Runnable_Next_R_Next_Next_State (&data)     (Rte_IRead_Next_State_State_Manager_R_Next_State_Manager_Runnable_Next (&data))




void State_Manager_Runnable_Switch0(void);
void State_Manager_Runnable_Switch1(void);
void State_Manager_Runnable_Next(void);
void State_Manager_Runnable_ReadChannel(void);
void State_Manager_Runnable_ClearChannel(void);
void State_Manager_Runnable_SetChannel(void);

#endif
