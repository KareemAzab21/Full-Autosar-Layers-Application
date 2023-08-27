#include "Port.h"
#include "Port_Regs.h"
#include "Port_Types.h"

void Port_Init()
{
  for(uint8 pin=0;pin<=PORT_PIN_SIZE;pin++){
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
		volatile uint32 delay = 0;

		switch(PortPin[pin].Port_ID)
		{
			case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
			 break;
			case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
			 break;
			case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
			 break;
			case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
			 break;
			case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
			 break;
			case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
			 break;
		}

		/* Enable clock for PORT and allow time for clock to start*/
		SYSCTL_REGCGC2_REG |= (1<<PortPin[pin].Port_ID);
		delay = SYSCTL_REGCGC2_REG;

		if( ((PortPin[pin].Port_ID == 3) && (PortPin[pin].PortPinId == 7)) || ((PortPin[pin].Port_ID == 5) && (PortPin[pin].PortPinId == 0)) ) /* PD7 or PF0 */
		{
			/* Unlock the GPIOCR register */
			*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;

			/* Set the corresponding bit in GPIOCR register to allow changes on this pin */
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , PortPin[pin].PortPinId);
		}
		else if( (PortPin[pin].Port_ID == 2) && (PortPin[pin].PortPinId<= 3)) /* PC0 to PC3 */
		{
			/* JTAG PINS ONLY FOR DEBUGGING*/
			continue;
		}
		else
		{
			/* No need to unlock the commit register for this pin */
		}

		if (PortPin[pin].PortPinInitialMode == PORT_PIN_MODE_DIO)
		{
			/* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PortPin[pin].PortPinId);

			/* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PortPin[pin].PortPinId);

			/* Clear the PMCx bits for this pin */
			*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (PortPin[pin].PortPinId * 4));

			/* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PortPin[pin].PortPinId);
		}

		else 
		{
			/* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , PortPin[pin].PortPinId);

			/* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , PortPin[pin].PortPinId);

			/* Set the PMCx bits for this pin */
			*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (PortPin[pin].PortPinInitialMode & 0x0000000F << (PortPin[pin].PortPinId * 4));

			/* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , PortPin[pin].PortPinId );
		}
                
                
		if(PortPin[pin].PortPinDirection == PORT_PIN_OUT)
		{
				/* Set the corresponding bit in the GPIODIR register to configure it as output pin */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , PortPin[pin].PortPinId );

				if(PortPin[pin].PortPinLevelValue == STD_HIGH)
				{
						/* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , PortPin[pin].PortPinId);
				}
				else
				{
						/* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , PortPin[pin].PortPinId);
				}
		}
		else if(PortPin[pin].PortPinDirection == PORT_PIN_IN)
		{
				/* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , PortPin[pin].PortPinId);

				if(PortPin[pin].PortPinInputPullResistor == PORT_PIN_IN_PULL_UP)
				{
						/* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , PortPin[pin].PortPinId);
				}
				else if(PortPin[pin].PortPinInputPullResistor == PORT_PIN_IN_PULL_DOWN)
				{
						/* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
						SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PortPin[pin].PortPinId);
				}
				else
				{
						/* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , PortPin[pin].PortPinId);

						/* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , PortPin[pin].PortPinId);
				}
		}
		else
		{
				/* Do Nothing MISRA RULE */
		}
	}
    
   

}
