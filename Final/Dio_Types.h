#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

#include "types.h"





typedef uint8 Dio_LevelType;
typedef uint8 Dio_ChannelType;


typedef struct{
  	uint8 DioPortId;
	uint8 DioChannel_startingIndex;
	uint8 DioChannel_numberOfInstances;
	uint8 DioChannelGroup_startingIndex;
	uint8 DioChannelGroup_numberOfInstances;
}DioPort_s;



typedef struct{
  uint8 DioPort_startingIndex;
  uint8 DioPort_numberOfInstances;
}DioConfig_s;

typedef struct{
    uint8 DioPortMask;
    uint8 DioPortOffset;
    uint8 DioPortId;
}DioChannelGroup_s;

typedef struct{
  uint8 DioPortType;
  Dio_ChannelType DioChannelId;
 
}DioChannel_s;



#endif
