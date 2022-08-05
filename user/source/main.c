#include "main.h"

int main(void)
{
    system_clock_config();
    System_Init();
	_GPIO_LCD_CS_L();
    LCD_Address_Set(20,20,200-1,200-1);//设置显示范围
    while(1)
    {
        LCD_WR_DATA(0X01FF);
		LCD_Delay_Ms(1);
    }
}

void System_Init(void)
{
    Gpio_Init();
    Spi1_Init();
    LCD_Init();
}
