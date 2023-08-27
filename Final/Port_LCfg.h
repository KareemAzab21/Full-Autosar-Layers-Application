#ifndef PORT_LCFG_H
#define PORT_LCFG_H



/******************************************************************************************
****************************************Port Module****************************************
*********************************Link-Time Configurations*********************************
******************************************************************************************/


/*
* Port_LCfg_H
* 	File's Includes
*/
#include "Port_Types.h"
#include "types.h"


/******************************************************************************************
***************************************Port Module's***************************************
****************************************Structures****************************************
******************************************************************************************/


/*
* PortConfigSet Container
*  Macro Configurations
*/
#define PORT_CONFIG_SET_SIZE                       (1U)

/* Container Instance 0*/
#define PORT_CONFIG_SET_ID_5                       (5U)
#define PORT_CONTAINER_0_STARTING_INDEX            (0U)
#define PORT_CONTAINER_0_NUMBER_INSTANCES          (1U)


/*
* PortContainer Container
*  Macro Configurations
*/
#define PORT_CONTAINER_SIZE                        (1U)

/* Container Instance 0*/
#define PORT_CONTAINER_ID_0                        (0U)
#define PORT_PIN_0_STARTING_INDEX                  (0U)
#define PORT_PIN_0_NUMBER_INSTANCES                (5U)


/*
* PortPin Container
*  Macro Configurations
*/
#define PORT_PIN_SIZE                              (5U)

/* Container Instance 0*/
#define PORT_PIN_ID_0                              (0U)
/* Container Instance 1*/
#define PORT_PIN_ID_1                              (1U)
/* Container Instance 2*/
#define PORT_PIN_ID_2                              (2U)
/* Container Instance 3*/
#define PORT_PIN_ID_3                              (3U)
/* Container Instance 4*/
#define PORT_PIN_ID_4                              (4U)




/******************************************************************************************
**********************************User Defined Map Array**********************************
**************************************Mapping Element**************************************
******************************************************************************************/

#ifndef USER_MAP_ARRAY_ELEMENT_TYPE
#define USER_MAP_ARRAY_ELEMENT_TYPE
/* Used only in case of user defined multiple mapping*/
typedef struct
{
	uint8*	baseAddress;	/*The base address which refers to the UserMapArrayIds*/
	uint8	offset;			/*The number of mapped elements*/

}UserMapArrayElement_s;
#endif

/******************************************************************************************
***************************************Port Module's***************************************
*************************************Structures Arrays*************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* PortConfigSet Container
* 	Extern Array Of Structures
*/
extern PortConfigSet_s PortConfigSet[PORT_CONFIG_SET_SIZE];

/*
* PortContainer Container
* 	Extern Array Of Structures
*/
extern PortContainer_s PortContainer[PORT_CONTAINER_SIZE];

/*
* PortPin Container
* 	Extern Array Of Structures
*/
extern PortPin_s PortPin[PORT_PIN_SIZE];




/******************************************************************************************
***************************************Port Module's***************************************
*************************************Structures Sizes*************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* PortConfigSet Container
* 	Extern Size Variable
*/
extern uint8 lcfg_PortConfigSet_size;

/*
* PortContainer Container
* 	Extern Size Variable
*/
extern uint8 lcfg_PortContainer_size;

/*
* PortPin Container
* 	Extern Size Variable
*/
extern uint8 lcfg_PortPin_size;




/******************************************************************************************
***************************************Port Module's***************************************
***************************************Enumerations***************************************
******************************************************************************************/
#if 0



/*
* Type Definition
* 	Enumeration: PortPinDirection
*/
typedef enum
{

	PORT_PIN_IN,
	PORT_PIN_OUT

}PortPinDirection_e;


/*
* Type Definition
* 	Enumeration: PortPinInitialMode
*/
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
	PORT_PIN_MODE_SPI

}PortPinInitialMode_e;


/*
* Type Definition
* 	Enumeration: PortPinLevelValue
*/
typedef enum
{

	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW

}PortPinLevelValue_e;


/*
* Type Definition
* 	Enumeration: PortPinMode
*/
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
	PORT_PIN_MODE_SPI

}PortPinMode_e;


/*
* Type Definition
* 	Enumeration: PortPinInputPullResistor
*/
typedef enum
{

	PORT_PIN_IN_NO_PULL,
	PORT_PIN_IN_PULL_DOWN,
	PORT_PIN_IN_PULL_UP

}PortPinInputPullResistor_e;


#endif


/******************************************************************************************
***************************************Port Module's***************************************
**************************************Default Values**************************************
******************************************************************************************/

#define DEFAULT_PARAMETER_8BIT_VALUE            (255U)
#define DEFAULT_PARAMETER_16BIT_VALUE           (65535U)
#define DEFAULT_PARAMETER_32BIT_VALUE           (4294967295U)
#define DEFAULT_PARAMETER_64BIT_VALUE           (18446744073709551615U)
#define DEFAULT_PARAMETER_BOOLEAN_VALUE         (0U)
#define DEFAULT_PARAMETER_ENUM_VALUE            (11U)
#define DEFAULT_PARAMETER_STRING_VALUE          ("\0")
#define DEFAULT_REFERENCE_TYPE                  (0U)
#define DEFAULT_REFERENCE_NUMBER_INSTANCES      (0U)
#define DEFAULT_REFERENCE_VALUE                 ((void *)0)
#define DEFAULT_PARAMETER_FUNCTION_NAME_VALUE   ((void *)0)
#define DEFAULT_CONTAINER_TYPE                  (0U)
#define DEFAULT_CONTAINER_STARTING_VALUE        (0U)
#define DEFAULT_CONTAINER_NUMBER_INSTANCES      (0U)
#define FALSE                                   (0U)
#define TRUE                                    (1U)




#endif