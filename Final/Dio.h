#ifndef DIO_H
#define DIO_H

#include "Dio_LCfg.h"
#include "Dio_Regs.h"
#include "Dio_Types.h"
#include "Common_Macros.h"



/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);




#endif