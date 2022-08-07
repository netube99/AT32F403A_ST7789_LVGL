#include "main.h"

int main(void)
{
    System_Init();
    while(1)
    {
        //每隔5ms调用一次 lv_task_handler();
        if(System_Timer_Flag_Get())
        {
            System_Timer_Flag_Set(0);
            lv_task_handler();
        }
    }
}

void System_Init(void)
{
    //clock init
    system_clock_config();
    SysTick_Config(240000);
    //bsp init
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
    Gpio_Init();
    Spi1_Init();
    System_Timer_Init();
    //hardware init
    LCD_Init();
    //application init
    lv_init();
    lv_port_disp_init();
}
