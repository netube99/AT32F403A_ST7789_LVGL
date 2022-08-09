#include "main.h"

int main(void)
{
    System_Init();
    lv_demo_benchmark();
    while(1)
    {
        lv_task_handler();
        
    }
}

void System_Init(void)
{
    //system init
    system_clock_config();
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
    //bsp init
    Gpio_Init();
    Spi1_Init();
	System_Timer_Init();
    //hardware init
    LCD_Init();
    //application init
    lv_init();
    lv_port_disp_init();
}
