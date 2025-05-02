#include "app.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>

uint32_t press_count = 0;

void app()
{
    while (1)
    {
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        static uint32_t i = 0;
        printf("%ld, Button count: %ld. \r\n", i++, press_count);
        HAL_Delay(100);
    }
}

int _write(int file, char *ptr, int len)
{
    (void)file; // hack for fix warning - unused int file.
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, 1000);
    return len;
}
