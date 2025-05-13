#include "app.h"
#include "usart.h"
#include "gpio.h"
#include "tim.h"
#include "stm32f4xx_it.h"
#include <stdio.h>

uint32_t press_count = 0;
bool is_led_on = false;

void app()
{
    
    while (1)
    {
        
        
        static uint32_t i = 0;
        printf("%ld, Button count: %ld. \r\n", i++, press_count);
        if ((GPIOC->IDR & GPIO_IDR_ID13) == 0) {
            press_count++;
            if(is_led_on == false)
            {
                //GPIOA->BSRR = GPIO_BSRR_BS5;
                is_led_on = true;
            }
            else
            {
                //GPIOA->BSRR = GPIO_BSRR_BR5;
                is_led_on = false;
            }
            HAL_Delay(100);
            

        }
        
    }
}

int _write(int file, char *ptr, int len)
{
    (void)file; // hack for fix warning - unused int file.
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, 1000);
    return len;
}
