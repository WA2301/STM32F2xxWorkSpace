/**
  ******************************************************************************
  * @file    Project/STM32F2xx_StdPeriph_Template/stm32f2xx_conf.h  
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    13-April-2012
  * @brief   Library configuration file.
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F2xx_CONF_H
#define __STM32F2xx_CONF_H

/* Includes ------------------------------------------------------------------*/
/* Uncomment the line below to enable peripheral header file inclusion */
#include "stm32f2xx_adc.h"
#include "stm32f2xx_can.h"
#include "stm32f2xx_crc.h"
#include "stm32f2xx_cryp.h"
#include "stm32f2xx_dac.h"
#include "stm32f2xx_dbgmcu.h"
#include "stm32f2xx_dcmi.h"
#include "stm32f2xx_dma.h"
#include "stm32f2xx_exti.h"
#include "stm32f2xx_flash.h"
#include "stm32f2xx_fsmc.h"
#include "stm32f2xx_hash.h"
#include "stm32f2xx_gpio.h"
#include "stm32f2xx_i2c.h"
#include "stm32f2xx_iwdg.h"
#include "stm32f2xx_pwr.h"
#include "stm32f2xx_rcc.h"
#include "stm32f2xx_rng.h"
#include "stm32f2xx_rtc.h"
#include "stm32f2xx_sdio.h"
#include "stm32f2xx_spi.h"
#include "stm32f2xx_syscfg.h"
#include "stm32f2xx_tim.h"
#include "stm32f2xx_usart.h"
#include "stm32f2xx_wwdg.h"
#include "misc.h" /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */

/* Exported macro ------------------------------------------------------------*/
/**
  ******************************************************************************
  * @macro   Periph BitBand
  * @Example Set     GPIO: (*GPO_BAND(GPIOE_BASE,15) =1)
	*          Reset   GPIO: (*GPO_BAND(GPIOE_BASE,15) =0)
	*          Reverse GPIO: (*GPO_BAND(GPIOE_BASE,15)^=1)
	*          Read    GPIO:= *GPI_BAND(GPIOE_BASE,15)
  ******************************************************************************
  */ 
#define GPI_BAND(Addr,N)  (vu32*)(0x42200100+((Addr&0xFFFF)<<5)+(N<<2))/**IDR**/
#define GPO_BAND(Addr,N)  (vu32*)(0x42200180+((Addr&0xFFFF)<<5)+(N<<2))/**ODR**/

/**
  ******************************************************************************
  * @macro   RAM BitBand
  * @Example Set     Bit: (*BIT0_BAND(&val) =1)
	*          Reset   Bit: (*BIT0_BAND(&val) =0)
	*          Reverse Bit: (*BIT0_BAND(&val)^=0)
	*          Read    Bit:= *BIT0_BAND(&val)
  ******************************************************************************
  */ 
#define BIT0_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x00+((Addr&0xFFFF)<<5))
#define BIT1_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x04+((Addr&0xFFFF)<<5))
#define BIT2_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x08+((Addr&0xFFFF)<<5))
#define BIT3_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x0C+((Addr&0xFFFF)<<5))
#define BIT4_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x10+((Addr&0xFFFF)<<5))
#define BIT5_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x14+((Addr&0xFFFF)<<5))
#define BIT6_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x18+((Addr&0xFFFF)<<5))
#define BIT7_BAND(Addr)  	(vu32*)(SRAM_BB_BASE+0x1C+((Addr&0xFFFF)<<5))



/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/





/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    1 */
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */



#endif /* __STM32F2xx_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
