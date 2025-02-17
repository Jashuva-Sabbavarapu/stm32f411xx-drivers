#include "stm32f411xx_spi.h"

static uint8_t my_strlen(uint8_t *buffer);
static void SPI_TXE_IT_HANDLE(SPI_Handle_t *SPI_Handle);
static void SPI_RXNE_IT_HANDLE(SPI_Handle_t *SPI_Handle);
static void SPI_OVR_IT_HANDLE(SPI_Handle_t *SPI_Handle);

/*
 *	SPI peripheral clock config function
 */

/*
 *	@fn 		:		SPI_PclkConfig
 *
 *	@brief		:		Function for enabling and disabling the SPI peripheral clock
 *
 *	@param[in]	:		Pointer for selectiong the SPI
 *	@param[in]	:		ENABLE and DISABLE macros
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_PclkConfig(SPIx_I2Sx_t *SPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(SPIx == SPI1_I2S1)
		{
			SPI1_I2S1_PCLK_EN();
		}
		else if(SPIx == SPI2_I2S2)
		{
			SPI2_I2S2_PCLK_EN();
		}
		else if(SPIx == SPI3_I2S3)
		{
			SPI3_I2S3_PCLK_EN();
		}
		else if(SPIx == SPI4_I2S4)
		{
			SPI4_I2S4_PCLK_EN();
		}
		else if(SPIx == SPI5_I2S5)
		{
			SPI5_I2S5_PCLK_EN();
		}
	}
	else
	{
		if(SPIx == SPI1_I2S1)
		{
			SPI1_I2S1_PCLK_DI();
		}
		else if(SPIx == SPI2_I2S2)
		{
			SPI2_I2S2_PCLK_DI();
		}
		else if(SPIx == SPI3_I2S3)
		{
			SPI3_I2S3_PCLK_DI();
		}
		else if(SPIx == SPI4_I2S4)
		{
			SPI4_I2S4_PCLK_DI();
		}
		else if(SPIx == SPI5_I2S5)
		{
			SPI5_I2S5_PCLK_DI();
		}
	}
}

/*
 *	SPI init and Deinit functions
 */

/*
 *	@fn 		:		SPI_Init
 *
 *	@brief		:		Function for initilizing SPI
 *
 *	@param[in]	:		Pointer for SPI handling structure
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_Init(SPI_Handle_t *SPI_Handle)
{
	uint32_t tempReg = 0;

	// Configure the device mode
	tempReg |= (SPI_Handle->SPI_Config.DeviceMode << SPI_CR1_MSTR);

	// Configure the bus mode
	if(SPI_Handle->SPI_Config.BusConfig == SPI_BUS_FD)
	{
		//BIDI mode is disabled
		tempReg &= ~(1 << SPI_CR1_BIDIMODE);
	}
	else if(SPI_Handle->SPI_Config.BusConfig == SPI_BUS_HD)
	{
		//BIDI mode is enabled
		tempReg |= (1 << SPI_CR1_BIDIMODE);
	}
	else if(SPI_Handle->SPI_Config.BusConfig == SPI_BUS_SMP_RX)
	{
		//BIDI mode is disabled
		tempReg &= ~(1 << SPI_CR1_BIDIMODE);
		// RXONLY bit must be set
		tempReg |= (1 << SPI_CR1_RXONLY);
	}

	// SCLK speed 
	tempReg |= (SPI_Handle->SPI_Config.SclkSpeed << SPI_CR1_BR);

	// Configure the DFF
	tempReg |= (SPI_Handle->SPI_Config.DFF << SPI_CR1_DFF);

	// Configure the CPOL
	tempReg |= (SPI_Handle->SPI_Config.CPOL << SPI_CR1_CPOL);

	// Confgure the CPHA
	tempReg |= (SPI_Handle->SPI_Config.CPHA << SPI_CR1_CPHA);

	// Configure the SSM
	tempReg |= (SPI_Handle->SPI_Config.SSM << SPI_CR1_SSM);

	SPI_Handle->SPIx->CR1 = tempReg;
}

/*
 *	@fn 		:		SPI_Dinit
 *
 *	@brief		:		Function for deinitilizing SPI
 *
 *	@param[in]	:		Pointer for selecting SPI
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_Dinit(SPIx_I2Sx_t *SPIx)
{
	if(SPIx == SPI1_I2S1)
	{
		SPI1_I2S1_PERI_RST();
	}
	else if(SPIx == SPI2_I2S2)
	{
		SPI2_I2S2_PERI_RST();
	}
	else if(SPIx == SPI3_I2S3)
	{
		SPI3_I2S3_PERI_RST();
	}
	else if(SPIx == SPI4_I2S4)
	{
		SPI4_I2S4_PERI_RST();
	}
	else if(SPIx == SPI5_I2S5)
	{
		SPI5_I2S5_PERI_RST();
	}
}

/*
*	SPI send and receive data fucntions
*/

/*
 *	@fn 		:		SPI_SendData
 *
 *	@brief		:		Function for sending the data
 *
 *	@param[in]	:		Pointer for selecting SPI
 *	@param[in]	:		String pointer for holding the buffer
 *
 *	@return		:		none
 *
 *	@note 		:		Blocking function
 */
void SPI_SendData(SPIx_I2Sx_t *SPIx, uint8_t *buffer)
{
	uint8_t len = my_strlen(buffer);

	while(len != 0)
	{
		// Check the TXE flag
		while(SPI_FlagStatus(SPIx, SPI_FLAG_TXE) == FLAG_RESET);

		// check if the DFF is 16bit
		if(SPIx->CR1 & (1 << SPI_CR1_DFF))
		{
			// Send 16bit data
			SPIx->DR = *((uint16_t*)buffer);
			len -= 2;
			(uint16_t*)buffer++;
		}
		else
		{
			// Send 8bit data
			SPIx->DR = *buffer;
			len--;
			buffer++;
		}
	}
}

/*
 *	@fn 		:		SPI_ReadData
 *
 *	@brief		:		Function for receiving the data
 *
 *	@param[in]	:		Pointer for selecting SPI
 *	@param[in]	:		String pointer for holding the buffer
 *
 *	@return		:		none
 *
 *	@note 		:		Blocking function
 */
void SPI_ReadData(SPIx_I2Sx_t *SPIx, uint8_t *buffer)
{
	uint8_t len = my_strlen(buffer);

	while(len != 0)
	{
		// Check the RXNE flag
		while(SPI_FlagStatus(SPIx, SPI_FLAG_RXNE));

		// Check if the DFF is 16bit
		if(SPIx->SR & (1 << SPI_CR1_DFF))
		{
			// Read 16bit data
			*((uint16_t*)buffer) = SPIx->DR;
			len -= 2;
			(uint16_t*)buffer++;
		}
		else
		{
			// Read 8bit data
			*buffer = SPIx->DR;
			len--;
			buffer++;
		}
	}
}

/*
 *	@fn 		:		SPI_SendDataIT
 *
 *	@brief		:		Function for sending the data interrupt mode
 *
 *	@param[in]	:		Pointer for selecting handle structure
 *	@param[in]	:		String pointer for holding the buffer
 *
 *	@return		:		uint8_t
 *
 *	@note 		:		none
 */
uint8_t SPI_SendDataIT(SPI_Handle_t *SPI_Handle, uint8_t *buffer)
{
	uint8_t state = SPI_Handle->TxState;

	if(state != SPI_BUSY_IN_TX)
	{
		// Save the TX buffer address and len information in some global variables
		SPI_Handle->TxBuffer = buffer;
		SPI_Handle->TxLen = my_strlen(buffer);
	
		// Mark the SPI state as busy in transimission
		SPI_Handle->TxState = SPI_BUSY_IN_TX;
	
		// Enable the TXEIE bit to get an interrupt whenever the TXE flag is set
		SPI_Handle->SPIx->CR2 |= (1 << SPI_CR2_TXEIE);
	
		// Data transimission will be handled by the ISR code
	}

	return state;
}

/*
 *	@fn 		:		SPI_ReadDataIT
 *
 *	@brief		:		Function for receiving the data interrupt mode
 *
 *	@param[in]	:		Pointer for selecting handle structure
 *	@param[in]	:		String pointer for holding the buffer
 *
 *	@return		:		uint8_t
 *
 *	@note 		:		none
 */
uint8_t SPI_ReadDataIT(SPI_Handle_t *SPI_Handle, uint8_t *buffer)
{
	uint8_t state = SPI_Handle->RxState;

	if(state != SPI_BUSY_IN_RX)
	{
		// Save the TX buffer address and len information in some global variables
		SPI_Handle->RxBuffer = buffer;
		SPI_Handle->RxLen = my_strlen(buffer);
	
		// Mark the SPI state as busy in transimission
		SPI_Handle->RxState = SPI_BUSY_IN_RX;
	
		// Enable the TXEIE bit to get an interrupt whenever the TXE flag is set
		SPI_Handle->SPIx->CR2 |= (1 << SPI_CR2_RXNEIE);
	
		// Data transimission will be handled by the ISR code
	}

	return state;
}

/*
 *	@fn 		:		SPI_FlagStatus
 *
 *	@brief		:		Function for checking the flag status
 *
 *	@param[in]	:		Pointer for selecting SPI 
 *	@param[in]	:		Flag name
 *
 *	@return		:		uint8_t
 *
 *	@note 		:		none
 */
uint8_t SPI_FlagStatus(SPIx_I2Sx_t *SPIx, uint32_t Flag)
{
	if(SPIx->SR & Flag)
	{
		return FLAG_SET;
	}
	else
	{
		return FLAG_RESET;
	}
}

/*
*	@fn 		:		SPI_InterruptConfig
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
void SPI_InterruptConfig(uint8_t IRQNum, uint8_t EnorDi);

/*
*	@fn 		:		SPI_PriorityConfig
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
void SPI_PriorityConfig(uint8_t IRQNum, uint8_t priority);

/*
*	@fn 		:		SPI_IRQHandling
*
*	@brief		:		Function for Handling the IRQ
*
*	@param[in]	:		Pointer for handling structure
*
*	@return		:		none
*	
*	@note 		:		none
*/
void SPI_IRQHandling(SPI_Handle_t *SPI_Handle)
{
	uint8_t temp1, temp2;
	// Check the TXE flag
	temp1 = (SPI_Handle->SPIx->SR & (1 << SPI_SR_TXE));
	temp2 = (SPI_Handle->SPIx->CR2 & (1 << SPI_CR2_TXEIE));

	if(temp1 && temp2)
	{
		// Handle TXE
		SPI_TXE_IT_HANDLE(SPI_Handle);
	}

	// Check for RXNE flag
	temp1 = (SPI_Handle->SPIx->SR & (1 << SPI_SR_RXNE));
	temp2 = (SPI_Handle->SPIx->CR2 & (1 << SPI_CR2_RXNEIE));

	if(temp1 && temp2)
	{
		// Handle RXNE
		SPI_RXNE_IT_HANDLE(SPI_Handle);
	}

	// Check for OVR flag
	temp1 = (SPI_Handle->SPIx->SR & (1 << SPI_SR_OVR));
	temp2 = (SPI_Handle->SPIx->CR2 & (1 << SPI_CR2_ERRIE));

	if(temp1 && temp2)
	{
		// Handle OVR
		SPI_OVR_IT_HANDLE(SPI_Handle);
	}
}

/*
 *	@fn 		:		SPI_Transmission
 *
 *	@brief		:		Function for enabling or disabling the SPI transmission
 *
 *	@param[in]	:		Pointer for selecting SPI
 *	@param[in]	:		ENABLE and DISABLE macros
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_Transmission(SPIx_I2Sx_t *SPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		SPIx->CR1 |= (1 << SPI_CR1_SPE);
	}
	else
	{
		SPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}

/*
 *	@fn 		:		SPI_SSIConfig
 *
 *	@brief		:		Function for enabling or disabling the SSI bit
 *
 *	@param[in]	:		Pointer for selecting SPI
 *	@param[in]	:		ENABLE and DISABLE macros
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_SSIConfig(SPIx_I2Sx_t *SPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		SPIx->CR1 |= (1 << SPI_CR1_SSI);
	}
	else
	{
		SPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}

/*
 *	@fn 		:		SPI_SSIConfig
 *
 *	@brief		:		Function for enabling or disabling the SSI bit
 *
 *	@param[in]	:		Pointer for selecting SPI
 *	@param[in]	:		ENABLE and DISABLE macros
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_SSOEConfig(SPIx_I2Sx_t *SPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		SPIx->CR2 |= (1 << SPI_CR2_SSOE);
	}
	else
	{
		SPIx->CR2 &= ~(1 << SPI_CR2_SSOE);
	}	
}

/*
 *	@fn 		:		SPI_ClearOVRFlag
 *
 *	@brief		:		Function for clearing the OVR flag
 *
 *	@param[in]	:		Pointer for selecting SPI
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_ClearOVRFlag(SPIx_I2Sx_t *SPIx)
{
	uint8_t temp = 0;
	// Clear the OVR flag	
	temp = SPIx->DR;
	temp = SPIx->SR;
	(void)temp;
}

/*
 *	@fn 		:		SPI_StopTX
 *
 *	@brief		:		Function for terminating the transmission
 *
 *	@param[in]	:		Pointer for selecting SPI
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_StopTX(SPI_Handle_t *SPI_Handle)
{
	SPI_Handle->SPIx->CR2 &= ~(1 << SPI_CR2_TXEIE);
	SPI_Handle->TxBuffer = ((void *)0);
	SPI_Handle->TxLen = 0;
}

/*
 *	@fn 		:		SPI_Stop
 *
 *	@brief		:		Function for terminating the reception
 *
 *	@param[in]	:		Pointer for selecting SPI
 *
 *	@return		:		none
 *
 *	@note 		:		none
 */
void SPI_StopRX(SPI_Handle_t *SPI_Handle)
{
	SPI_Handle->SPIx->CR2 &= ~(1 << SPI_CR2_RXNEIE);
	SPI_Handle->RxBuffer = ((void *)0);
	SPI_Handle->RxLen = 0;
}

/*
*	Helper private functions
*/

static uint8_t my_strlen(uint8_t *buffer)
{
	uint8_t len = 0;
	while(*buffer != '\0')
	{
		len++;
		buffer++;
	}

	return len;
}

static void SPI_TXE_IT_HANDLE(SPI_Handle_t *SPI_Handle)
{
	// check if the DFF is 16bit
	if(SPI_Handle->SPIx->CR1 & (1 << SPI_CR1_DFF))
	{
		// Send 16bit data
		SPI_Handle->SPIx->DR = *((uint16_t*)SPI_Handle->TxBuffer);
		SPI_Handle->TxLen -= 2;
		(uint16_t*)SPI_Handle->TxBuffer++;
	}
	else
	{
		// Send 8bit data
		SPI_Handle->SPIx->DR = *(SPI_Handle->TxBuffer);
		SPI_Handle->TxLen--;
		SPI_Handle->TxBuffer++;
	}

	if(!SPI_Handle->TxLen)
	{
		SPI_StopTX(SPI_Handle);
		SPI_Handle->TxState = SPI_READY;
		// Event call back
		SPI_CallBack(SPI_Handle, SPI_EVENT_TX_CMPLT);
	}
}
static void SPI_RXNE_IT_HANDLE(SPI_Handle_t *SPI_Handle)
{
	// check if the DFF is 16bit
	if(SPI_Handle->SPIx->CR1 & (1 << SPI_CR1_DFF))
	{
		// Send 16bit data
		*((uint16_t*)SPI_Handle->TxBuffer) = (uint16_t)SPI_Handle->SPIx->DR;
		SPI_Handle->TxLen -= 2;
		(uint16_t*)SPI_Handle->TxBuffer++;
	}
	else
	{
		// Send 8bit data
		*(SPI_Handle->TxBuffer) = (uint8_t)SPI_Handle->SPIx->DR;
		SPI_Handle->TxLen--;
		SPI_Handle->TxBuffer++;
	}

	if(!SPI_Handle->TxLen)
	{
		SPI_StopRX(SPI_Handle);
		SPI_Handle->RxState = SPI_READY;
		// Event call back
		SPI_CallBack(SPI_Handle, SPI_EVENT_RX_CMPLT);
	}
}
static void SPI_OVR_IT_HANDLE(SPI_Handle_t *SPI_Handle)
{
	uint8_t temp = 0;
	// Clear the OVR flag
	if(SPI_Handle->TxState != SPI_BUSY_IN_TX)
	{
		temp = SPI_Handle->SPIx->DR;
		temp = SPI_Handle->SPIx->SR;
	}
	(void)temp;
	// Event call back
	SPI_CallBack(SPI_Handle, SPI_EVENT_OVR_ERR);
}

__attribute__((weak)) void SPI_CallBack(SPI_Handle_t *SPI_Handle, uint8_t EVENT)
{
	//This is a weak implementation and the application need to override
}
