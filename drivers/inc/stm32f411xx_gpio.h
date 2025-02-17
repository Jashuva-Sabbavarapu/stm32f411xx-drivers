#ifndef STM32F411XX_GPIO_H
#define STM32F411XX_GPIO_H

#include <stdint.h>
#include "stm32f411xx.h"

/*
*	GPIO pin configuration structure
*/
typedef struct
{
	uint8_t pinNumber;
	uint8_t pinMode;
	uint8_t pinOtype;
	uint8_t pinSpeed;
	uint8_t pinPupd;
	uint8_t pinAlf;
	
}GPIO_PinConfig_t;

typedef struct
{
	uint16_t portMode;
	uint16_t portOtype;
	uint16_t portSpeed;
	uint16_t portPupd;
}GPIO_PortConfig_t;

/*
*	GPIOx handling structure
*/
typedef struct
{
	GPIOx_t *GPIOx;
	GPIO_PinConfig_t PinConfig;
	GPIO_PortConfig_t PortConfig;
}GPIO_Handle_t;

/*
*	Possible GPIO pin mode macros
*/
#define GPIO_MODE_IN					      0
#define GPIO_MODE_OUT					      1
#define GPIO_MODE_ALF					      2
#define GPIO_MODE_ANALOG				    3
#define GPIO_MODE_IT_RT					    4
#define GPIO_MODE_IT_FT					    5
#define GPIO_MODE_IT_RFT				    6

/*
*	Possible GPIO port mode macros
*/
#define GPIO_POROT_MODE_IN				  0x00000000
#define GPIO_PORT_MODE_OUT				  0x55555555

/*
*	Possible GPIO pin output type macros
*/
#define GPIO_OUT_PP						      0
#define GPIO_OUT_OD						      1

/*
*	Possible GPIO port output type macros
*/
#define GPIO_PORT_MODE_PP				    0x00000000
#define GPIO_PORT_MODE_OD				    0x55555555

/*
*	Possible GPIO pin output speed macros
*/
#define GPIO_SPEED_LOW					    0
#define GPIO_SPEED_MEDIUM				    1
#define GPIO_SPEED_FAST					    2
#define GPIO_SPEED_HIGH					    3

/*
*	Possible GPIO port output speed macros
*/
#define GPIO_PORT_SPEED_LOW				  0x00000000
#define GPIO_PORT_SPEED_MEDIUM			0x55555555
#define GPIO_PORT_SPEED_FAST			  0xAAAAAAAA
#define GPIO_PORT_SPEED_HIGH			  0xFFFFFFFF

/*
*	Possible GPIO pin Pull up and pull down resister macros
*/
#define GPIO_NO_PUPD					      0
#define GPIO_PIN_PUR					      1
#define GPIO_PIN_PDR					      2

/*
*	Possible GPIO port Pull up and pull down resister macros
*/
#define GPIO_PORT_NO_PUPD				    0x00000000
#define GPIO_PORT_PUR					      0x55555555
#define GPIO_PORT_PDR					      0xAAAAAAAA

/*
*	Possible GPIO pin alternate function macros
*/
#define GPIO_AF0						        0
#define GPIO_AF1						        1
#define GPIO_AF2						        2
#define GPIO_AF3						        3
#define GPIO_AF4						        4
#define GPIO_AF5						        5
#define GPIO_AF6						        6
#define GPIO_AF7						        7
#define GPIO_AF8						        8
#define GPIO_AF9						        9
#define GPIO_AF10						        10
#define GPIO_AF11						        11
#define GPIO_AF12						        12
#define GPIO_AF13						        13
#define GPIO_AF14						        14
#define GPIO_AF15						        15

/*
*	GPIO Pin numbers macros 
*/
#define GPIO_PIN_0						      0
#define GPIO_PIN_1  					      1
#define GPIO_PIN_2 						      2
#define GPIO_PIN_3  					      3
#define GPIO_PIN_4  					      4
#define GPIO_PIN_5   					      5
#define GPIO_PIN_6  					      6
#define GPIO_PIN_7   					      7
#define GPIO_PIN_8   					      8
#define GPIO_PIN_9   					      9
#define GPIO_PIN_10   					    10
#define GPIO_PIN_11						      11
#define GPIO_PIN_12						      12
#define GPIO_PIN_13						      13
#define GPIO_PIN_14						      14
#define GPIO_PIN_15						      15


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
void GPIO_PclkConfig(GPIOx_t *GPIOx, uint8_t EnorDi);

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
void GPIO_Init(GPIO_Handle_t *GPIO_Handle);

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
void GPIO_Dinit(GPIOx_t *GPIOx);

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
uint16_t GPIO_ReadPort(GPIOx_t *GPIOx);

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
uint8_t GPIO_ReadPin(GPIOx_t *GPIOx, uint8_t pinNum);

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
void GPIO_WritePort(GPIOx_t *GPIOx, uint16_t value);

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
void GPIO_WritePin(GPIOx_t *GPIOx, uint8_t pinNum, uint8_t value);

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
void GPIO_TogglePort(GPIOx_t *GPIOx);

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
void GPIO_TogglePin(GPIOx_t *GPIOx, uint8_t pinNum);

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
void GPIO_InterruptConfig(uint8_t IRQNum, uint8_t EnorDi);

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
void GPIO_PriorityConfig(uint8_t IRQNum, uint8_t priority);

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
void GPIO_IRQHandling(uint8_t pinNum);

/*
*	@fn 		:		clearTheElements
*
*	@brief		:		Function for clearing all the elements from the structure
*
*	@param[in]	:		pointer for pointing to the structure
*
*	@return		:		none
*	
*	@note 		:		none
*/
void clearTheElements(GPIO_Handle_t *ptr);

/*
* SYSCFG port code macro
*/
#define SYSCFG_PORT_CODE(x)					   ((GPIOA) ? 0 :\
												(GPIOB) ? 1 :\
												(GPIOC) ? 2 :\
												(GPIOD) ? 3 :\
												(GPIOE) ? 4 :\
												(GPIOH) ? 7 :\
												0)



#endif // STM32F411XX_GPIO_H
