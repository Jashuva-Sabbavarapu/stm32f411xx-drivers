#ifndef STM32F411XX_SPI_H
#define STM32F411XX_SPI_H

#include <stdint.h>
#include "stm32f411xx.h"

typedef struct
{
	uint8_t DeviceMode;
	uint8_t BusConfig;
	uint8_t SclkSpeed;
	uint8_t DFF;
	uint8_t CPOL;
	uint8_t CPHA;
	uint8_t SSM;
}SPI_Config_t;

typedef struct
{
	SPIx_I2Sx_t *SPIx;
	SPI_Config_t SPI_Config;
	uint8_t *TxBuffer;
	uint8_t *RxBuffer;
	uint32_t TxLen;
	uint32_t RxLen;
	uint8_t TxState;
	uint8_t RxState;
}SPI_Handle_t;

/*
*	@DeviceMode
*/
#define SPI_MODE_SLAVE					0
#define SPI_MODE_MASTER					1

/*
*	@BusConfig
*/
#define SPI_BUS_FD					  	0
#define SPI_BUS_HD					  	1
#define SPI_BUS_SMP_RX					2

/*
*	@SclkSpeed
*/
#define SPI_SPEED_DIV2					0
#define SPI_SPEED_DIV4					1
#define SPI_SPEED_DIV8					2
#define SPI_SPEED_DIV16					3
#define SPI_SPEED_DIV32					4
#define SPI_SPEED_DIV64					5
#define SPI_SPEED_DIV128				6
#define SPI_SPEED_DIV256				7

/*
*	@DFF
*/
#define SPI_DFF_8BIT				  	0
#define SPI_DFF_16BIT				  	1

/*
*	@CPOL
*/
#define SPI_CPOL_LOW				  	0
#define SPI_CPOL_HIGH				  	1

/*
*	@CPHA
*/
#define SPI_CPHA_LOW				  	0
#define SPI_CPHA_HIGH				  	1

/*
*	@SSM
*/
#define SPI_SSM_DI					  	0
#define SPI_SSM_EN					  	1

/*
*	BIT POSITION FOR CR1 REGISTER
*/
#define SPI_CR1_CPHA				  	0
#define SPI_CR1_CPOL				  	1
#define SPI_CR1_MSTR				  	2
#define SPI_CR1_BR					  	3
#define SPI_CR1_SPE					  	6
#define SPI_CR1_LSBFIRST				7
#define SPI_CR1_SSI 				  	8
#define SPI_CR1_SSM					  	9
#define SPI_CR1_RXONLY					10
#define SPI_CR1_DFF					  	11
#define SPI_CR1_CRCNEXT					12
#define SPI_CR1_CRCEN 					13
#define SPI_CR1_BIDIOE					14
#define SPI_CR1_BIDIMODE				15

/*
*	BIT POSITION FOR CR2 REGISTER
*/
#define SPI_CR2_RXDMAEN					0
#define SPI_CR2_TXDMAEN					1
#define SPI_CR2_SSOE				  	2
#define SPI_CR2_FRF					  	3
#define SPI_CR2_ERRIE				  	5
#define SPI_CR2_RXNEIE					6
#define SPI_CR2_TXEIE				  	7 

/*
*	BIT POSITION FOR SR REGISTER
*/
#define SPI_SR_RXNE					   	0
#define SPI_SR_TXE					   	1
#define SPI_SR_CHSIDE				   	2
#define SPI_SR_UDR					   	3
#define SPI_SR_CRCERR				   	4
#define SPI_SR_MODF					   	5
#define SPI_SR_OVR					   	6
#define SPI_SR_BSY					   	7
#define SPI_SR_FRE					   	8

/*
*	SPI Flags
*/
#define SPI_FLAG_RXNE				  	(1 << SPI_SR_RXNE)
#define SPI_FLAG_TXE				  	(1 << SPI_SR_TXE)
#define SPI_FLAG_CHSIDE					(1 << SPI_SR_CHSIDE)
#define SPI_FLAG_UDR				  	(1 << SPI_SR_UDR)
#define SPI_FLAG_CRCERR					(1 << SPI_SR_CRCERR)
#define SPI_FLAG_MODF				  	(1 << SPI_SR_MODF)
#define SPI_FLAG_OVR				  	(1 << SPI_SR_OVR)
#define SPI_FLAG_BSY				  	(1 << SPI_SR_BSY)
#define SPI_FLAG_FRE				  	(1 << SPI_SR_FRE)

#define FLAG_SET					    1
#define FLAG_RESET					  	0

/*
*	SPI state macros
*/
#define SPI_READY					  	0
#define SPI_BUSY_IN_RX					1
#define SPI_BUSY_IN_TX					2

/*
*	Possible SPI events
*/
#define SPI_EVENT_TX_CMPLT				0
#define SPI_EVENT_RX_CMPLT				1
#define SPI_EVENT_OVR_ERR				2

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
void SPI_PclkConfig(SPIx_I2Sx_t *SPIx, uint8_t EnorDi);

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
void SPI_Init(SPI_Handle_t *SPI_Handle);

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
void SPI_Dinit(SPIx_I2Sx_t *SPIx);

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
void SPI_SendData(SPIx_I2Sx_t *SPIx, uint8_t *buffer);

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
void SPI_ReadData(SPIx_I2Sx_t *SPIx, uint8_t *buffer);

/*
 *	@fn 		:		SPI_SendDataIT
 *
 *	@brief		:		Function for sending the data interrupt mode
 *
 *	@param[in]	:		Pointer for selecting handling structure
 *	@param[in]	:		String pointer for holding the buffer
 *
 *	@return		:		uint8_t
 *
 *	@note 		:		none
 */
uint8_t SPI_SendDataIT(SPI_Handle_t *SPI_Handle, uint8_t *buffer);

/*
 *	@fn 		:		SPI_ReadDataIT
 *
 *	@brief		:		Function for receiving the data interrupt mode
 *
 *	@param[in]	:		Pointer for selecting handling structure
 *	@param[in]	:		String pointer for holding the buffer
 *
 *	@return		:		uint8_t
 *
 *	@note 		:		none
 */
uint8_t SPI_ReadDataIT(SPI_Handle_t *SPI_Handle, uint8_t *buffer);

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
uint8_t SPI_FlagStatus(SPIx_I2Sx_t *SPIx, uint32_t Flag);

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
void SPI_IRQHandling(SPI_Handle_t *SPI_Handle);

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
void SPI_Transmission(SPIx_I2Sx_t *SPIx, uint8_t EnorDi);

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
void SPI_SSIConfig(SPIx_I2Sx_t *SPIx, uint8_t EnorDi);

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
void SPI_SSOEConfig(SPIx_I2Sx_t *SPIx, uint8_t EnorDi);

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
void SPI_ClearOVRFlag(SPIx_I2Sx_t *SPIx);

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
void SPI_StopTX(SPI_Handle_t *SPI_Handle);

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
void SPI_StopRX(SPI_Handle_t *SPI_Handle);

void SPI_CallBack(SPI_Handle_t *SPI_Handle, uint8_t EVENT);

#endif // STM32F411XX_SPI_H
