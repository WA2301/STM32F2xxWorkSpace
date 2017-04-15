/**
  ******************************************************************************
  * @file    Project/STM32F2xx_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    13-April-2012
  * @brief   Main program body
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_app.h"
#include "minos.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void STM32_Init(void);

/****** Task00 Configuration **************************************************/
#define TASK00_PRIO        0													/* The priority of task */
#define TASK00_STK_SIZE   80			 /* The stack size of task, NO LESS than 40 */
OS_STK  Task00_Stk[
				TASK00_STK_SIZE];										 						 /* The stack of task */
void 		Task00(void *p_arg);

/****** Task01 Configuration **************************************************/
#define TASK01_PRIO        1													/* The priority of task */
#define TASK01_STK_SIZE   80			 /* The stack size of task, NO LESS than 40 */
OS_STK  Task01_Stk[
				TASK01_STK_SIZE];										 						 /* The stack of task */
void 		Task01(void *p_arg);

/****** Task02 Configuration **************************************************/
#define TASK02_PRIO        2													/* The priority of task */
#define TASK02_STK_SIZE   80			 /* The stack size of task, NO LESS than 40 */
OS_STK  Task02_Stk[
				TASK02_STK_SIZE];										 						 /* The stack of task */
void 		Task02(void *p_arg);


/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  RCC_ClocksTypeDef RCC_Clocks;

  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f2xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f2xx.c file
     */  

  /* SysTick end of count event each 1ms */
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);	

  /* Add your application code here
     */
	
	OSInit();

/************* Task00 Creation ************************************************/
	OSTaskCreate(Task00,(void *)0,
							&Task00_Stk[
							 TASK00_STK_SIZE-1],
							 TASK00_PRIO);

/************* Task01 Creation ************************************************/
	OSTaskCreate(Task01,(void *)0,
							&Task01_Stk[
							 TASK01_STK_SIZE-1],
							 TASK01_PRIO);

/************* Task02 Creation ************************************************/
	OSTaskCreate(Task02,(void *)0,
							&Task02_Stk[
							 TASK02_STK_SIZE-1],
							 TASK02_PRIO);
	
	
	OSStart();
    return 0;
	
	
}



/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
