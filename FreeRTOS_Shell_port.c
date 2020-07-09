#include "FreeRTOS_Shell_port.h"
#include "FreeRTOS_Shell.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "semphr.h"

extern UART_HandleTypeDef huart2;
void FreeRTOS_ShellOutput(const char * buffer, int length) {
    // Please Replace below code to your board
    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, length, length);
}

void USART2_IRQHandler(void)
{
  if(huart2.Instance->SR & USART_SR_RXNE){
    // 保证读取出数据，防止溢出，产生ORE错误。
    uint8_t recvData = READ_REG(huart2.Instance->DR);
    FreeRTOS_ShellIRQHandle(recvData);
  }
} 

void FreeRTOS_Shell_init(void){
	    __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
}