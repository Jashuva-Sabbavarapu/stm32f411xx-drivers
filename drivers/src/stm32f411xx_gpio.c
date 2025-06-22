#include "stm32f411xx_gpio.h"

/*
 *	GPIO peripheral clock config function
 */

/*
*	@fn 		:		GPIO_PclkConfig
*
*	@brief		:		Function for enabling and disabling the GPIO peripheral clock
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*	@param[in]	:		ENABLE and DISABLE macros
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_PclkConfig(GPIOx_t *GPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (GPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (GPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (GPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (GPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (GPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if (GPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else if (EnorDi == DISABLE)
	{
		if (GPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if (GPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if (GPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if (GPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if (GPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if (GPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}

/*
 *	GPIO init and Deinit function
 */

/*
*	@fn 		:		GPIO_Init
*
*	@brief		:		Function for initilizing GPIO
*
*	@param[in]	:		Pointer for GPIO handling structure
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_Init(GPIO_Handle_t *GPIO_Handle)
{

	if (GPIO_Handle->PinConfig.pinMode <= GPIO_MODE_ANALOG)
	{
		// Non interrupt mode
		// Setting up the GPIO mode
		GPIO_Handle->GPIOx->MODER &= ~(0x3 << (2 * GPIO_Handle->PinConfig.pinNumber));
		GPIO_Handle->GPIOx->MODER |= (GPIO_Handle->PinConfig.pinMode << (2 * GPIO_Handle->PinConfig.pinNumber));

		// Setting up the GPIO output types 
		GPIO_Handle->GPIOx->OTYPER &= ~(0x1 << GPIO_Handle->PinConfig.pinNumber);
		GPIO_Handle->GPIOx->OTYPER |= (GPIO_Handle->PinConfig.pinOtype << GPIO_Handle->PinConfig.pinNumber);

		// Setting up the Alternate function mode
		uint8_t index = (GPIO_Handle->PinConfig.pinNumber / 8);
		GPIO_Handle->GPIOx->AFR[index] &= ~(0xF << (4 * (GPIO_Handle->PinConfig.pinNumber % 8)));
		GPIO_Handle->GPIOx->AFR[index] |= (GPIO_Handle->PinConfig.pinAlf << (4 * (GPIO_Handle->PinConfig.pinNumber % 8)));

	}
	else
	{
		// interrupt mode
		GPIO_Handle->GPIOx->MODER &= ~(0x3 << (2 * GPIO_Handle->PinConfig.pinNumber));
		GPIO_Handle->GPIOx->MODER |= GPIO_MODE_IN;


		if(GPIO_Handle->PinConfig.pinMode == GPIO_MODE_IT_RT)
		{
			EXTI->RTSR |= (1 << GPIO_Handle->PinConfig.pinNumber);
			EXTI->FTSR &= ~(1 << GPIO_Handle->PinConfig.pinNumber);
		}
		else if(GPIO_Handle->PinConfig.pinMode == GPIO_MODE_IT_FT)
		{
			EXTI->RTSR &= ~(1 << GPIO_Handle->PinConfig.pinNumber);
			EXTI->FTSR |= (1 << GPIO_Handle->PinConfig.pinNumber);
		}
		else if(GPIO_Handle->PinConfig.pinMode == GPIO_MODE_IT_RFT)
		{
			EXTI->RTSR |= (1 << GPIO_Handle->PinConfig.pinNumber);
			EXTI->FTSR |= (1 << GPIO_Handle->PinConfig.pinNumber);
		}

		SYSCFG_PCLK_EN();
		uint8_t index = (GPIO_Handle->PinConfig.pinNumber / 4);
		uint8_t temp = (GPIO_Handle->PinConfig.pinNumber % 4);
		uint8_t port_code = SYSCFG_PORT_CODE(GPIO_Handle->GPIOx);
		SYSCFG->EXTICR[index] &= ~(0xF << (4 * temp));
		SYSCFG->EXTICR[index] |= (port_code << (4 * temp));

		EXTI->IMR |= (1 << GPIO_Handle->PinConfig.pinNumber);

	}

	// Setting up the pull up and pull down
	GPIO_Handle->GPIOx->PUPDR &= ~(0x3 << (2 * GPIO_Handle->PinConfig.pinNumber));
	GPIO_Handle->GPIOx->PUPDR |= (GPIO_Handle->PinConfig.pinPupd << (2 * GPIO_Handle->PinConfig.pinNumber));

	// Setting up the output speed
	GPIO_Handle->GPIOx->OSPEEDER &= ~(0x3 << (2 * GPIO_Handle->PinConfig.pinNumber));
	GPIO_Handle->GPIOx->OSPEEDER |= (GPIO_Handle->PinConfig.pinSpeed << (2 * GPIO_Handle->PinConfig.pinNumber));

	// GPIO port config
	// Set the mode of the GPIO port
	// GPIO_Handle->GPIOx->MODER = GPIO_Handle->PortConfig.portMode;

	// // Set the output type of the GPIO port
	// GPIO_Handle->GPIOx->OTYPER = GPIO_Handle->PortConfig.portOtype;

	// // Set the speed of the GPIO port
	// GPIO_Handle->GPIOx->OSPEEDER = GPIO_Handle->PortConfig.portSpeed;

	// // Set the PUPDR of the GPIO port
	// GPIO_Handle->GPIOx->PUPDR = GPIO_Handle->PortConfig.portPupd;
}

/*
*	@fn 		:		GPIO_Dinit
*
*	@brief		:		Function for deinitilizing GPIO
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_Dinit(GPIOx_t *GPIOx)
{
	if (GPIOx == GPIOA)
	{
		GPIOA_PERI_RST();
	}
	else if (GPIOx == GPIOB)
	{
		GPIOB_PERI_RST();
	}
	else if (GPIOx == GPIOC)
	{
		GPIOC_PERI_RST();
	}
	else if (GPIOx == GPIOD)
	{
		GPIOD_PERI_RST();
	}
	else if (GPIOx == GPIOE)
	{
		GPIOE_PERI_RST();
	}
	else if (GPIOx == GPIOH)
	{
		GPIOH_PERI_RST();
	}
}

/*
 *	GPIO read and write function
 */

/*
*	@fn 		:		GPIO_ReadPort
*
*	@brief		:		Function for reading the GPIO port
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*
*	@return		:		uint16_t
*	
*	@note 		:		none
*/
uint16_t GPIO_ReadPort(GPIOx_t *GPIOx)
{
	return GPIOx->IDR;
}

/*
*	@fn 		:		GPIO_ReadPin
*
*	@brief		:		Function for reading the GPIO pin
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*	@param[in]	:		For selecting the pin number
*
*	@return		:		uint8_t
*	
*	@note 		:		none
*/
uint8_t GPIO_ReadPin(GPIOx_t *GPIOx, uint8_t pinNum)
{
	return (GPIOx->IDR & (1 << pinNum));
}

/*
*	@fn 		:		GPIO_WritePort
*
*	@brief		:		Function for writing the GPIO port
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*	@param[in]	:		Value to be write into the GPIO port
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_WritePort(GPIOx_t *GPIOx, uint16_t value)
{
	GPIOx->ODR = value;
}

/*
*	@fn 		:		GPIO_WritePin
*
*	@brief		:		Function for writing the GPIO pin
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*	@param[in]	:		For selecting the pin number
*	@param[in]	:		Value to be write into the GPIO pin
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_WritePin(GPIOx_t *GPIOx, uint8_t pinNum, uint8_t value)
{
	GPIOx->ODR |= (value << pinNum);
}

/*
*	@fn 		:		GPIO_TogglePort
*
*	@brief		:		Function for toggling the GPIO port
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_TogglePort(GPIOx_t *GPIOx)
{
	GPIOx->ODR ^= 0xFF;
}

/*
*	@fn 		:		GPIO_TogglePin
*
*	@brief		:		Function for toggling the GPIO pin
*
*	@param[in]	:		Pointer for selectiong the GPIO port
*	@param[in]	:		For selecting the pin number
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_TogglePin(GPIOx_t *GPIOx, uint8_t pinNum)
{
	GPIOx->ODR ^= (1 << pinNum);
}

/*
*	@fn 		:		GPIO_InterruptConfig
*
*	@brief		:		Function for Configuring the NVIC registers
*
*	@param[in]	:		IRQ number for configuring
*	@param[in]	:		ENABLE or DISABLE macros
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_InterruptConfig(uint8_t IRQNum, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNum <= 31)
		{
			NVIC_ISER0 |= (1 << IRQNum);
		}
		else if(IRQNum > 31 && IRQNum < 64)
		{
			NVIC_ISER1 |= (1 << (IRQNum % 32));
		}
		else if(IRQNum >= 64 && IRQNum < 96)
		{
			NVIC_ISER2 |= (1 << (IRQNum % 64));
		}
	}
	else
	{
		if(IRQNum <= 31)
		{
			NVIC_ICER0 |= (1 << IRQNum);
		}
		else if(IRQNum > 31 && IRQNum < 64)
		{
			NVIC_ICER1 |= (1 << (IRQNum % 32));
		}
		else if(IRQNum >= 64 && IRQNum < 96)
		{
			NVIC_ICER2 |= (1 << (IRQNum % 64));
		}
	}
}

/*
*	@fn 		:		GPIO_PriorityConfig
*
*	@brief		:		Function for Configuring the the priority
*
*	@param[in]	:		IRQ number for config
*	@param[in]	:		priority value
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_PriorityConfig(uint8_t IRQNum, uint8_t priority)
{
	uint8_t iprx = IRQNum / 4;
	uint8_t iprx_section = IRQNum % 4;
	uint8_t shift_amount = ((8 * iprx_section) * (8 - PR_NO_BITS_IMP));
	*(NVIC_PR_BASE_ADDR + iprx) |= (priority << shift_amount);
}

/*
*	@fn 		:		GPIO_IRQHandling
*
*	@brief		:		Function for Handling the IRQ
*
*	@param[in]	:		Pin number for handling the IRQ
*
*	@return		:		none
*	
*	@note 		:		none
*/
void GPIO_IRQHandling(uint8_t pinNum)
{
	if(EXTI->PR & (1 << pinNum))
	{
		EXTI->PR |= (1 << pinNum);
	}
}
