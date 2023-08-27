#ifndef PORT_TYPES_H
#define PORT_TYPES_H

#include "types.h"


typedef enum{
  PORT_PIN_IN,
  PORT_PIN_OUT
}Port_PinDirection;



typedef enum{
  PORT_PIN_LEVEL_LOW,
  PORT_PIN_LEVEL_HIGH
}Port_PinLevelValue;

typedef enum
{
    PORT_PIN_IN_NO_PULL,
    PORT_PIN_IN_PULL_UP,
    PORT_PIN_IN_PULL_DOWN
}Port_InternalResistor;


typedef enum
{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI,
}Port_PinMode;




typedef struct{
  uint8   PortContainer_startingIndex;
  uint8  PortContainer_numberOfInstances;

}PortConfigSet_s;


typedef struct{
  	uint8 PortNumberOfPortPins;
	uint8 PortPin_startingIndex;
	uint8 PortPin_numberOfInstances;
}PortContainer_s;



typedef struct{
        uint8 Port_ID;	
  	Port_PinDirection PortPinDirection;
	uint8 PortPinDirectionChangeable;
	uint8 PortPinId;
	Port_PinMode PortPinInitialMode; 
	Port_PinLevelValue PortPinLevelValue;
	Port_PinMode PortPinMode;
	uint8 PortPinModeChangeable ;
	Port_InternalResistor PortPinInputPullResistor ;
}PortPin_s;





#endif