#include "main.h"

uint16_t buffer[240][100];

int main(void)
{
    system_clock_config();
    System_Init();
    while(1)
    {
        
    }
}

void System_Init(void)
{
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
    Gpio_Init();
    Spi1_Init();
    LCD_Init();
}
