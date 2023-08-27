

/******************************************************************************************
****************************************Dio Module****************************************
*********************************Link-Time Configurations*********************************
******************************************************************************************/





#include "Dio_LCfg.h"



/******************************************************************************************
*************************************DioPort Container*************************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioPort_size = DIO_PORT_SIZE;

/* Array Of Structures Linking Configurations*/
DioPort_s DioPort[DIO_PORT_SIZE] =
{
	{	/*Instance_0*/
		.DioPortId = 5,
		.DioChannel_startingIndex = DIO_CHANNEL_0_STARTING_INDEX,
		.DioChannel_numberOfInstances = DIO_CHANNEL_0_NUMBER_INSTANCES,
		.DioChannelGroup_startingIndex = DIO_CHANNEL_GROUP_0_STARTING_INDEX,
		.DioChannelGroup_numberOfInstances = DIO_CHANNEL_GROUP_0_NUMBER_INSTANCES
	}
};
/******************************************************************************************
************************************DioConfig Container************************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioConfig_size = DIO_CONFIG_SIZE;

/* Array Of Structures Linking Configurations*/
DioConfig_s DioConfig[DIO_CONFIG_SIZE] =
{
	{	/*Instance_0*/
		.DioPort_startingIndex = DIO_PORT_0_STARTING_INDEX,
		.DioPort_numberOfInstances = DIO_PORT_0_NUMBER_INSTANCES
	}
};
/******************************************************************************************
***********************************DioChannel Container***********************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioChannel_size = DIO_CHANNEL_SIZE;

/* Array Of Structures Linking Configurations*/
DioChannel_s DioChannel[DIO_CHANNEL_SIZE] =
{
	{	/*Instance_0*/
                .DioPortType=DIO_PORT_ID_5,  
		.DioChannelId = 0
	},
	{	/*Instance_1*/
                .DioPortType=DIO_PORT_ID_5,
		.DioChannelId = 1
	},
	{	/*Instance_2*/
                .DioPortType=DIO_PORT_ID_5,
		.DioChannelId = 2
	},
	{	/*Instance_3*/
                .DioPortType=DIO_PORT_ID_5,
		.DioChannelId = 3
	},
	{	/*Instance_4*/
                .DioPortType=DIO_PORT_ID_5,
		.DioChannelId = 4
	}
};
/******************************************************************************************
*********************************DioChannelGroup Container*********************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioChannelGroup_size = DIO_CHANNEL_GROUP_SIZE;

/* Array Of Structures Linking Configurations*/
DioChannelGroup_s DioChannelGroup[DIO_CHANNEL_GROUP_SIZE] =
{
	{	/*Instance_0*/
		.DioPortMask = 31,
		.DioPortOffset = 4,
		.DioPortId = 5
	}
};