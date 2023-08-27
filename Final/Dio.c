#include "Dio.h"
#include "Dio_Regs.h"
#include "Dio_Types.h"



/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;

	/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(DioChannel[ChannelId].DioPortType)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		/* Read the required channel */
		if(BIT_IS_SET(*Port_Ptr,DioChannel[ChannelId].DioChannelId))
		{
			output = STD_HIGH;
		}
		else
		{
			output = STD_LOW;
		}
        return output;
}




/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile uint32 * Port_Ptr = NULL_PTR;


		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(DioChannel[ChannelId].DioPortType)
		{
                    case 0:    Port_Ptr = &GPIO_PORTA_DATA_REG;
		               break;
		    case 1:    Port_Ptr = &GPIO_PORTB_DATA_REG;
		               break;
		    case 2:    Port_Ptr = &GPIO_PORTC_DATA_REG;
		               break;
		    case 3:    Port_Ptr = &GPIO_PORTD_DATA_REG;
		               break;
                    case 4:    Port_Ptr = &GPIO_PORTE_DATA_REG;
		               break;
                    case 5:    Port_Ptr = &GPIO_PORTF_DATA_REG;
		               break;
		}
		if(Level == STD_HIGH)
		{
			/* Write Logic High */
			SET_BIT(*Port_Ptr,DioChannel[ChannelId].DioChannelId);
		}
		else if(Level == STD_LOW)
		{
			/* Write Logic Low */
			CLEAR_BIT(*Port_Ptr,DioChannel[ChannelId].DioChannelId);
		}

}
