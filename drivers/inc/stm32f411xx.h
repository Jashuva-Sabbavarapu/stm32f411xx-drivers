#ifndef STM32F411XX_H
#define STM32F411XX_H

#include <stdint.h>

/*-------------------------ARM Cortex-M4 Nested vectored interrupt registers-------------------------------*/
// NVIC ISERx registers 
#define NVIC_ISER0                              *((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1                              *((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2                              *((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3                              *((volatile uint32_t*)0xE000E10C)

// NVIC ICERx registers

#define NVIC_ICER0                              *((volatile uint32_t*)0xE000E180)
#define NVIC_ICER1                              *((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2                              *((volatile uint32_t*)0xE000E188)
#define NVIC_ICER3                              *((volatile uint32_t*)0xE000E18C)

// NVIC Periority base address
#define NVIC_PR_BASE_ADDR                       ((volatile uint32_t*)0xE000E400)

/*
 *   Interrupt vector of ARM Cortex-M4 processor for EXTI
 */
#define IRQ_NO_EXTI0                            6
#define IRQ_NO_EXTI1                            7
#define IRQ_NO_EXTI2                            8
#define IRQ_NO_EXTI3                            9
#define IRQ_NO_EXTI4                            10
#define IRQ_NO_EXTI9_5                          23
#define IRQ_NO_EXTI15_10                        40  

/*
* NVIC Pending register no of bits implemented
*/                                
#define PR_NO_BITS_IMP                          4


/*
 *   Embedded memory base addresses
 */

#define FLASH_BASE_ADDR                         0x08000000U
#define SRAM_BASE_ADDR                          0x20000000U
#define SYSTEM_MEMORY_BASE_ADDR                 0x1FFF0000U
#define OTP_BASSE_ADDR                          0x1FFF7800U
#define OPTION_BYTES_BASE_ADDR                  0x1FFF7800U

/*
 *   APBx and AHBx base addresses
 */

#define APB1_BASE_ADDR                          0x40000000U
#define APB2_BASE_ADDR                          0x40010000U
#define AHB1_BASE_ADDR                          0x40020000U
#define AHB2_BASE_ADDR                          0x50000000U

/*
 *   CRC peripheral register base addresses
 */
#define CRC_BASE_ADDR                           (AHB1_BASE_ADDR + 0x3000)

/*
 *   POWER CONTROL REGISTER peripheral base addresses
 */
#define PWR_BASE_ADDR                           (APB1_BASE_ADDR + 0x7000)

/*
 *   RCC peripheral register base addresses
 */
#define RCC_BASE_ADDR                           (AHB1_BASE_ADDR + 0x3800)

/*
 *   System configuration register base addresses
 */
#define SYSCFG_BASE_ADDR                        (APB2_BASE_ADDR + 0x3800)

/*
 *   GPIOx peripheral registers base addresses
 */
#define GPIOA_BASE_ADDR                         (AHB1_BASE_ADDR + 0x0000)
#define GPIOB_BASE_ADDR                         (AHB1_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR                         (AHB1_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR                         (AHB1_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR                         (AHB1_BASE_ADDR + 0x1000)
#define GPIOH_BASE_ADDR                         (AHB1_BASE_ADDR + 0x1C00)

/*
 *   DMAx peripheral registers base addresses
 */
#define DMA1_BASE_ADDR                          (AHB1_BASE_ADDR + 0x6000)
#define DMA2_BASE_ADDR                          (AHB1_BASE_ADDR + 0x6400)

/*
 *   EXTI peripheral register base addresses
 */
#define EXTI_BASE_ADDR                          (APB2_BASE_ADDR + 0x3C00)

/*
 *   ADC1 peripheral base addresses
 */
#define ADC1_BASE_ADDR                          (APB2_BASE_ADDR + 0x2000)

/*
 *   TIMERx peripheral registers base addresses
 */
#define TIM1_BASE_ADDR                          (APB2_BASE_ADDR + 0x0000)
#define TIM2_BASE_ADDR                          (APB1_BASE_ADDR + 0x0000)
#define TIM3_BASE_ADDR                          (APB1_BASE_ADDR + 0x0400)
#define TIM4_BASE_ADDR                          (APB1_BASE_ADDR + 0x0800)
#define TIM5_BASE_ADDR                          (APB1_BASE_ADDR + 0x0C00)
#define TIM9_BASE_ADDR                          (APB2_BASE_ADDR + 0x4000)
#define TIM10_BASE_ADDR                         (APB2_BASE_ADDR + 0x4400)
#define TIM11_BASE_ADDR                         (APB2_BASE_ADDR + 0x4800)

/*
 *   IWDG peripheral registers base addresses
 */
#define IWDG_BASE_ADDR                          (APB1_BASE_ADDR + 0x3000)

/*
 *   WWDG peripheral registers base addresses
 */
#define WWDG_BASE_ADDR                          (APB1_BASE_ADDR + 0x2C00)

/*
 *   RTC peripheral base addresses
 */
#define RTC_BASE_ADDR                           (APB1_BASE_ADDR + 0x2800)

/*
 *   I2Cx peripheral base addresses
 */
#define I2C1_BASE_ADDR                          (APB1_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR                          (APB1_BASE_ADDR + 0x5800)
#define I2C3_BASE_ADDR                          (APB1_BASE_ADDR + 0x5C00)

/*
 *   USARTx peripheral base addresses
 */
#define USART1_BASE_ADDR                        (APB2_BASE_ADDR + 0x1000)
#define USART2_BASE_ADDR                        (APB1_BASE_ADDR + 0x4400)
#define USART6_BASE_ADDR                        (APB2_BASE_ADDR + 0x1400)

/*
 *   SPIx and I2Sx peripheral base addresses
 */
#define SPI1_I2S1_BASE_ADDR                     (APB2_BASE_ADDR + 0x3000)
#define SPI2_I2S2_BASE_ADDR                     (APB1_BASE_ADDR + 0x3800)
#define SPI3_I2S3_BASE_ADDR                     (APB1_BASE_ADDR + 0x3C00)
#define SPI4_I2S4_BASE_ADDR                     (APB2_BASE_ADDR + 0x3400)
#define SPI5_I2S5_BASE_ADDR                     (APB2_BASE_ADDR + 0x5000)

/*
 *   SDIO peripheral base addresses
 */
#define SDIO_BASE_ADDR                          (APB2_BASE_ADDR + 0x2C00)

/*-------------------------Peripheral registers structure definition------------------------------*/

/*
 *   CRC Peripheral structure definition
 */
typedef struct
{
    volatile uint32_t DR;
    volatile uint32_t IDR;
    volatile uint32_t CR;
} CRC_t;

/*
 *   PWR peripheral structure definition
 */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CSR;
} PWR_t;

/*
 *   RCC peripheral structure definition
 */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t RESERVED0[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t RESERVED2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    uint32_t RESERVED4[2];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    uint32_t RESERVED7;
    volatile uint32_t DCKCFGR;
} RCC_t;

/*
 *   SYSCFG peripheral structure definition
 */
typedef struct
{
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4];
    volatile uint32_t CMPCR;
} SYSCFG_t;

/*
 *   GPIOx peripheral structure definition
 */
typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDER;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
} GPIOx_t;

/*
 *   DMAx peripheral structure definition
 */
typedef struct
{
    volatile uint32_t LISR;
    volatile uint32_t HISR;
    volatile uint32_t LIFCR;
    volatile uint32_t HIFCR;
    volatile uint32_t S0CR;
    volatile uint32_t S0NDIR;
    volatile uint32_t S0PAR;
    volatile uint32_t S0M0AR;
    volatile uint32_t S0M1AR;
    volatile uint32_t S0FCR;
    volatile uint32_t S1CR;
    volatile uint32_t S1NDTR;
    volatile uint32_t S1PAR;
    volatile uint32_t S1M0AR;
    volatile uint32_t S1M1AR;
    volatile uint32_t S1FCR;
    volatile uint32_t S2CR;
    volatile uint32_t S2NDTR;
    volatile uint32_t S2PAR;
    volatile uint32_t S2M0AR;
    volatile uint32_t S2M1AR;
    volatile uint32_t S2FCR;
    volatile uint32_t S3CR;
    volatile uint32_t S3NDTR;
    volatile uint32_t S3PAR;
    volatile uint32_t S3M0AR;
    volatile uint32_t S3M1AR;
    volatile uint32_t S3FCR;
    volatile uint32_t S4CR;
    volatile uint32_t S4NDTR;
    volatile uint32_t S4PAR;
    volatile uint32_t S4M0AR;
    volatile uint32_t S4M1AR;
    volatile uint32_t S4FCR;
    volatile uint32_t S5CR;
    volatile uint32_t S5NDTR;
    volatile uint32_t S5PAR;
    volatile uint32_t S5M0AR;
    volatile uint32_t S5M1AR;
    volatile uint32_t S5FCR;
    volatile uint32_t S6CR;
    volatile uint32_t S6NDTR;
    volatile uint32_t S6PAR;
    volatile uint32_t S6M0AR;
    volatile uint32_t S6M1AR;
    volatile uint32_t S6FCR;
    volatile uint32_t S7CR;
    volatile uint32_t S7NDTR;
    volatile uint32_t S7PAR;
    volatile uint32_t S7M0AR;
    volatile uint32_t S7M1AR;
    volatile uint32_t S7FCR;
} DMAx_T;

/*
 *   EXTI peripheral structure definition
 */
typedef struct
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
} EXTI_t;

/*
 *   ADC1 peripheral structure definition
 */
typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t CR[2];
    volatile uint32_t SMPR[2];
    volatile uint32_t JOFR[4];
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR[3];
    volatile uint32_t JSQR;
    volatile uint32_t JDR[4];
    volatile uint32_t DR;
    volatile uint32_t CCR;
} ADC1_t;

/*
 *   TIMx peripheral structure definition
 */
typedef struct
{
    volatile uint32_t CR[2];
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR[2];
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR[4];
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
    volatile uint32_t OR;
} TIMx_t;

/*
 *   IWDG peripheral structure definition
 */
typedef struct
{
    volatile uint32_t KR;
    volatile uint32_t PR;
    volatile uint32_t RLR;
    volatile uint32_t SR;
} IWDG_t;

/*
 *   WWDG peripheral structure definition
 */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CFR;
    volatile uint32_t SR;
} WWDG_t;

/*
 *   RTC peripheral structure definition
 */
typedef struct
{
    volatile uint32_t TR;
    volatile uint32_t DR;
    volatile uint32_t CR;
    volatile uint32_t ISR;
    volatile uint32_t PRER;
    volatile uint32_t WUTR;
    volatile uint32_t CALIBAR;
    volatile uint32_t ALRMAR;
    volatile uint32_t ALRMBR;
    volatile uint32_t WPR;
    volatile uint32_t SSR;
    volatile uint32_t TSTR;
    volatile uint32_t TSSSR;
    volatile uint32_t CALR;
    volatile uint32_t TAFCR;
    volatile uint32_t ALRMASSR;
    volatile uint32_t ALRMBSSR;
    volatile uint32_t BKP0R;
    volatile uint32_t BKP19R;
} RTC_t;

/*
 *   I2Cx peripheral structure definition
 */
typedef struct
{
    volatile uint32_t CR[2];
    volatile uint32_t OAR[2];
    volatile uint32_t DR;
    volatile uint32_t SR[2];
    volatile uint32_t CCR;
    volatile uint32_t TRISE;
    volatile uint32_t FLTR;
} I2Cx_t;

/*
 *   USARTx peripheral structure definition
 */
typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR[3];
    volatile uint32_t GTPR;
} USARTx_t;

/*
 *   SPIx and I2Sx peripheral structure definition
 */
typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2CPR;
} SPIx_I2Sx_t;

/*
 *   SIDO peripheral structure definition
 */
typedef struct
{
    volatile uint32_t POWER;
    volatile uint32_t CLKCR;
    volatile uint32_t ARG;
    volatile uint32_t CMD;
    volatile uint32_t RESPCMD;
    volatile uint32_t RESP[4];
    volatile uint32_t DTIMER;
    volatile uint32_t DLEN;
    volatile uint32_t DCTRL;
    volatile uint32_t DCOUNT;
    volatile uint32_t STA;
    volatile uint32_t ICR;
    volatile uint32_t MASK;
    volatile uint32_t FIFOCNT;
    volatile uint32_t FIFO;
} SIDO_t;

/*-----Peripheral definitions (Peripheral base addresses typecasted to structure definions)--------*/

/*
 *   CRC peripheral definitions
 */
#define CRC                                     ((CRC_t *)CRC_BASE_ADDR)

/*
 *   PWR peripheral definitions
 */
#define PWR                                     ((PWR_t *)PWR_BASE_ADDR)

/*
 *   RCC peripheral definitions
 */
#define RCC                                     ((RCC_t *)RCC_BASE_ADDR)

/*
 *   SYSCFG peripheral definitions
 */
#define SYSCFG                                  ((SYSCFG_t *)SYSCFG_BASE_ADDR)

/*
 *   GPIOx peripheral definitions
 */
#define GPIOA                                   ((GPIOx_t *)GPIOA_BASE_ADDR)
#define GPIOB                                   ((GPIOx_t *)GPIOB_BASE_ADDR)
#define GPIOC                                   ((GPIOx_t *)GPIOC_BASE_ADDR)
#define GPIOD                                   ((GPIOx_t *)GPIOD_BASE_ADDR)
#define GPIOE                                   ((GPIOx_t *)GPIOE_BASE_ADDR)
#define GPIOH                                   ((GPIOx_t *)GPIOH_BASE_ADDR)

/*
 *   DMA peripheral definitions
 */
#define DMA1                                    ((DMAx_T *)DMA1_BASE_ADDR)
#define DMA2                                    ((DMAx_T *)DMA2_BASE_ADDR)

/*
 *   EXTI peripheral definitions
 */
#define EXTI                                    ((EXTI_t *)EXTI_BASE_ADDR)

/*
 *   ADC peripheral definitions
 */
#define ADC1                                    ((ADC1_t *)ADC1_BASE_ADDR)

/*
 *   TIMx peripheral definitions
 */
#define TIM1                                    ((TIMx_t *)TIM1_BASE_ADDR)
#define TIM2                                    ((TIMx_t *)TIM2_BASE_ADDR)
#define TIM3                                    ((TIMx_t *)TIM3_BASE_ADDR)
#define TIM4                                    ((TIMx_t *)TIM4_BASE_ADDR)
#define TIM5                                    ((TIMx_t *)TIM5_BASE_ADDR)
#define TIM9                                    ((TIMx_t *)TIM9_BASE_ADDR)
#define TIM10                                   ((TIMx_t *)TIM10_BASE_ADDR)
#define TIM11                                   ((TIMx_t *)TIM11_BASE_ADDR)

/*
 *   IWDG peripheral definitions
 */
#define IWDG                                    ((IWDG_t *)IWDG_BASE_ADDR)

/*
 *   WWDG peripheral definitions
 */
#define WWDG                                    ((WWDG_t *)WWDG_BASE_ADDR)

/*
 *   RTC peripheral definitions
 */
#define RTC                                     ((RCC_t *)RTC_BASE_ADDR)

/*
 *   I2C peripheral definitions
 */
#define I2C1                                    ((I2Cx_t *)I2C1_BASE_ADDR)
#define I2C2                                    ((I2Cx_t *)I2C2_BASE_ADDR)
#define I2C3                                    ((I2Cx_t *)I2C3_BASE_ADDR)

/*
 *   USARTx peripheral definitions
 */
#define USART1                                  ((USARTx_t *)USART1_BASE_ADDR)
#define USART2                                  ((USARTx_t *)USART2_BASE_ADDR)
#define USART6                                  ((USARTx_t *)USART1_BASE_ADDR)

/*
 *   SPIx and I2Sx peripheral definitons
 */
#define SPI1_I2S1                               ((SPIx_I2Sx_t *)SPI1_I2S1_BASE_ADDR)
#define SPI2_I2S2                               ((SPIx_I2Sx_t *)SPI2_I2S2_BASE_ADDR)
#define SPI3_I2S3                               ((SPIx_I2Sx_t *)SPI3_I2S3_BASE_ADDR)
#define SPI4_I2S4                               ((SPIx_I2Sx_t *)SPI4_I2S4_BASE_ADDR)
#define SPI5_I2S5                               ((SPIx_I2Sx_t *)SPI5_I2S5_BASE_ADDR)

/*
 *   SDIO peripheral definitions
 */
#define SDIO                                    ((SIDO_t *)SDIO_BASE_ADDR)

/*
 *   Peripheral clock enable macros
 */

/*
*   CRC peripheral clock enable macros
*/
#define CRC_PCLK_EN()                           RCC->AHB1ENR |= (1 << 12)

/*
*   PWR peripheral clock enable macros
*/
#define PWR_PCLK_EN()                           RCC->APB1ENR |= (1 << 28)

/*
*   SYSCFG peripheral clock enable macros
*/                          
#define SYSCFG_PCLK_EN()                        RCC->APB2ENR |= (1 << 14)

/*
*   GPIOx peripheral clock enable macros
*/
#define GPIOA_PCLK_EN()                         RCC->AHB1ENR |= (1 << 0)
#define GPIOB_PCLK_EN()                         RCC->AHB1ENR |= (1 << 1)
#define GPIOC_PCLK_EN()                         RCC->AHB1ENR |= (1 << 2)
#define GPIOD_PCLK_EN()                         RCC->AHB1ENR |= (1 << 3)
#define GPIOE_PCLK_EN()                         RCC->AHB1ENR |= (1 << 4)
#define GPIOH_PCLK_EN()                         RCC->AHB1ENR |= (1 << 7)

/*
*   DMAx peripheral clock enable macros
*/
#define DMA1_PCLK_EN()                          RCC->AHB1ENR |= (1 << 21)
#define DMA2_PCLK_EN()                          RCC->AHB1ENR |= (1 << 22)

/*
*   ADC1 peripheral clock enable macros
*/
#define ADC1_PCLK_EN()                          RCC->APB2ENR |= (1 << 8)

/*
*   TIMx peripheral clock enable macros
*/
#define TIM1_PCLK_EN()                          RCC->APB2ENR |= (1 << 0)
#define TIM2_PCLK_EN()                          RCC->APB2ENR |= (1 << 0)
#define TIM3_PCLK_EN()                          RCC->APB1ENR |= (1 << 1)
#define TIM4_PCLK_EN()                          RCC->APB1ENR |= (1 << 2)
#define TIM5_PCLK_EN()                          RCC->APB1ENR |= (1 << 3)
#define TIM9_PCLK_EN()                          RCC->APB2ENR |= (1 << 16)
#define TIM10_PCLK_EN()                         RCC->APB2ENR |= (1 << 17)
#define TIM11_PCLK_EN()                         RCC->APB2ENR |= (1 << 18)

/*
*   WWDG peripheral clock enable macros
*/
#define WWDG_PCLK_EN()                          RCC->APB1ENR |= (1 << 11)

/*
*   I2Cx periphral clock enable macros
*/
#define I2C1_PCLK_EN()                          RCC->APB1ENR |= (1 << 21)
#define I2C2_PCLK_EN()                          RCC->APB1ENR |= (1 << 22)
#define I2C3_PCLK_EN()                          RCC->APB1ENR |= (1 << 23)

/*
*   USARTx peripheral clock enable macros
*/
#define USART1_PCLK_EN()                        RCC->APB2ENR |= (1 << 4)
#define USART2_PCLK_EN()                        RCC->APB1ENR |= (1 << 17)
#define USART6_PCLK_EN()                        RCC->APB2ENR |= (1 << 5)

/*
*   SPIx peripheral clock enable macros
*/
#define SPI1_I2S1_PCLK_EN()                     RCC->APB2ENR |= (1 << 12)
#define SPI2_I2S2_PCLK_EN()                     RCC->APB1ENR |= (1 << 14)
#define SPI3_I2S3_PCLK_EN()                     RCC->APB1ENR |= (1 << 15)
#define SPI4_I2S4_PCLK_EN()                     RCC->APB2ENR |= (1 << 13)
#define SPI5_I2S5_PCLK_EN()                     RCC->APB2ENR |= (1 << 20)

/*
*   SDIO peripheral clock enable macros
*/
#define SDIO_PCLK_EN()                          RCC->APB2ENR |= (1 << 11)


/*
 *   Peripheral clock disable macros
 */

/*
*   CRC peripheral clock disable macros
*/
#define CRC_PCLK_DI()                           RCC->AHB1ENR &= ~(1 << 12)

/*
*   PWR peripheral clock disable macros
*/
#define PWR_PCLK_DI()                           RCC->APB1ENR &= ~(1 << 28)

/*
*   SYSCFG peripheral clock disable macros
*/                          
#define SYSCFG_PCLK_DI()                        RCC->APB2ENR &= ~(1 << 14)

/*
* GPIOx peripheral clock disable macros
*/
#define GPIOA_PCLK_DI()                         RCC->AHB1ENR &= ~(1 << 0)
#define GPIOB_PCLK_DI()                         RCC->AHB1ENR &= ~(1 << 1)
#define GPIOC_PCLK_DI()                         RCC->AHB1ENR &= ~(1 << 2)
#define GPIOD_PCLK_DI()                         RCC->AHB1ENR &= ~(1 << 3)
#define GPIOE_PCLK_DI()                         RCC->AHB1ENR &= ~(1 << 4)
#define GPIOH_PCLK_DI()                         RCC->AHB1ENR &= ~(1 << 7)

/*
*   DMAx peripheral clock disable macros
*/
#define DMA1_PCLK_DI()                          RCC->AHB1ENR &= ~(1 << 21)
#define DMA2_PCLK_DI()                          RCC->AHB1ENR &= ~(1 << 22)

/*
*   ADC1 peripheral clock disable macros
*/
#define ADC1_PCLK_DI()                          RCC->APB2ENR &= ~(1 << 8)

/*
*   TIMx peripheral clock disable macros
*/
#define TIM1_PCLK_DI()                          RCC->APB2ENR &= ~(1 << 0)
#define TIM2_PCLK_DI()                          RCC->APB2ENR &= ~(1 << 0)
#define TIM3_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 1)
#define TIM4_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 2)
#define TIM5_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 3)
#define TIM9_PCLK_DI()                          RCC->APB2ENR &= ~(1 << 16)
#define TIM10_PCLK_DI()                         RCC->APB2ENR &= ~(1 << 17)
#define TIM11_PCLK_DI()                         RCC->APB2ENR &= ~(1 << 18)

/*
*   WWDG peripheral clock disable macros
*/
#define WWDG_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 11)

/*
*   I2Cx periphral clock disable macros
*/
#define I2C1_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 21)
#define I2C2_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 22)
#define I2C3_PCLK_DI()                          RCC->APB1ENR &= ~(1 << 23)

/*
*   USARTx peripheral clock disable macros
*/
#define USART1_PCLK_DI()                        RCC->APB2ENR &= ~(1 << 4)
#define USART2_PCLK_DI()                        RCC->APB1ENR &= ~(1 << 17)
#define USART6_PCLK_DI()                        RCC->APB2ENR &= ~(1 << 5)

/*
*   SPIx peripheral clock disable macros
*/
#define SPI1_I2S1_PCLK_DI()                     RCC->APB2ENR &= ~(1 << 12)
#define SPI2_I2S2_PCLK_DI()                     RCC->APB1ENR &= ~(1 << 14)
#define SPI3_I2S3_PCLK_DI()                     RCC->APB1ENR &= ~(1 << 15)
#define SPI4_I2S4_PCLK_DI()                     RCC->APB2ENR &= ~(1 << 13)
#define SPI5_I2S5_PCLK_DI()                     RCC->APB2ENR &= ~(1 << 20)

/*
*   SDIO peripheral clock disable macros
*/
#define SDIO_PCLK_DI()                          RCC->APB2ENR &= ~(1 << 11)


/*
 *   Peripheral reset macros
 */

/*
*   CRC peripheral reset macros
*/
#define CRC_PERI_RST()                          do{ RCC->AHB1RSTR |= (1 << 12); RCC->AHB1RSTR &= ~(1 << 12); }while(0)

/*
*   PWR peripheral reset macros
*/
#define PWR_PERI_RST()                          do{ RCC->APB1RSTR |= (1 << 28); RCC->APB1RSTR &= ~(1 << 28); }while(0)

/*
*   SYSCFG peripheral reset macros
*/                          
#define SYSCFG_PERI_RST()                       do{ RCC->APB2RST |= (1 << 14); RCC->APB2RST &= ~(1 << 14); }while(0)
/*
*   GPIOx peripheral reset macros
*/
#define GPIOA_PERI_RST()                        do{ RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0); }while(0)
#define GPIOB_PERI_RST()                        do{ RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1); }while(0)
#define GPIOC_PERI_RST()                        do{ RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2); }while(0)
#define GPIOD_PERI_RST()                        do{ RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3); }while(0)
#define GPIOE_PERI_RST()                        do{ RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4); }while(0)
#define GPIOH_PERI_RST()                        do{ RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7); }while(0)

/*
*   DMAx peripheral reset macros
*/
#define DMA1_PERI_RST()                         do{ RCC->AHB1RSTR |= (1 << 21); RCC->AHB1RSTR &= ~(1 << 21); }while(0)
#define DMA2_PERI_RST()                         do{ RCC->AHB1RSTR |= (1 << 22); RCC->AHB1RSTR &= ~(1 << 22); }while(0)

/*
*   ADC1 peripheral reset macros
*/
#define ADC1_PERI_RST()                         do{ RCC->APB2RSTR |= (1 << 8); RCC->APB2RSTR &= ~(1 << 8); }while(0)

/*
*   TIMx peripheral reset macros
*/
#define TIM1_PERI_RST()                         do{ RCC->APB2RSTR |= (1 << 0); RCC->APB2RSTR &= ~(1 << 0); }while(0)
#define TIM2_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 0); RCC->APB1RSTR &= ~(1 << 0); }while(0)
#define TIM3_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 1); RCC->APB1RSTR &= ~(1 << 1); }while(0)
#define TIM4_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 2); RCC->APB1RSTR &= ~(1 << 2); }while(0)
#define TIM5_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 3); RCC->APB1RSTR &= ~(1 << 3); }while(0)
#define TIM9_PERI_RST()                         do{ RCC->APB2RSTR |= (1 << 16); RCC->APB2RSTR &= ~(1 << 16); }while(0)
#define TIM10_PERI_RST()                        do{ RCC->APB2RSTR |= (1 << 17); RCC->APB2RSTR &= ~(1 << 17); }while(0)
#define TIM11_PERI_RST()                        do{ RCC->APB2RSTR |= (1 << 18); RCC->APB2RSTR &= ~(1 << 18); }while(0)

/*
*   WWDG peripheral reset macros
*/
#define WWDG_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 11); RCC->APB1RSTR &= ~(1 << 11); }while(0)
/*
*   I2Cx periphral reset macros
*/
#define I2C1_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 21); RCC->APB1RSTR &= ~(1 << 21); }while(0)
#define I2C2_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 22); RCC->APB1RSTR &= ~(1 << 22); }while(0)
#define I2C3_PERI_RST()                         do{ RCC->APB1RSTR |= (1 << 23); RCC->APB1RSTR &= ~(1 << 23); }while(0)

/*
*   USARTx peripheral reset macros
*/
#define USART1_PERI_RST()                       do{ RCC->APB2RSTR |= (1 << 4); RCC->APB2RSTR &= ~(1 << 4); }while(0)
#define USART2_PERI_RST()                       do{ RCC->APB1RSTR |= (1 << 17); RCC->APB1RSTR &= ~(1 << 17); }while(0)
#define USART6_PERI_RST()                       do{ RCC->APB2RSTR |= (1 << 5); RCC->APBRSTR &= ~(1 << 5); }while(0)

/*
*   SPIx peripheral reset macros
*/
#define SPI1_I2S1_PERI_RST()                    do{ RCC->APB2RSTR |= (1 << 12); RCC->APB2RSTR &= ~(1 << 12); }while(0)
#define SPI2_I2S2_PERI_RST()                    do{ RCC->APB1RSTR |= (1 << 14); RCC->APB1RSTR &= ~(1 << 14); }while(0)
#define SPI3_I2S3_PERI_RST()                    do{ RCC->APB1RSTR |= (1 << 15); RCC->APB1RSTR &= ~(1 << 15); }while(0)
#define SPI4_I2S4_PERI_RST()                    do{ RCC->APB2RSTR |= (1 << 13); RCC->APB2RSTR &= ~(1 << 13); }while(0)
#define SPI5_I2S5_PERI_RST()                    do{ RCC->APB2RSTR |= (1 << 20); RCC->APB2RSTR &= ~(1 << 20); }while(0)

/*
*   SDIO peripheral reset macros
*/
#define SDIO_PERI_RST()                         do{ RCC->APB2RSTR |= (1 << 11); RCC->APB2RSTR &= ~(1 << 11); }while(0)


/*
 *   Generic macros
 */
#define ENABLE                                  1
#define DISABLE                                 0
#define HIGH                                    ENABLE
#define LOW                                     DISABLEs

#endif // STM32F411XX_H
