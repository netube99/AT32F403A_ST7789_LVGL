#include "lcd.h"
#include "at32f403a_407.h"

/*
函数说明：LCD串行数据写入函数
入口数据：dat  要写入的串行数据
返回值：  无
*/
void LCD_Writ_Bus(uint8_t dat) 
{
	LCD_CS_Clr();
	spi_i2s_data_transmit(LCD_SPIX, dat);
	while(spi_i2s_flag_get(LCD_SPIX, SPI_I2S_BF_FLAG)){};
  	LCD_CS_Set();
}


/*
函数说明：LCD写入数据
入口数据：dat 写入的数据
返回值：  无
*/
void LCD_WR_DATA8(uint8_t dat)
{
	LCD_Writ_Bus(dat);
}


/*
函数说明：LCD写入数据
入口数据：dat 写入的数据
返回值：  无
*/
void LCD_WR_DATA(uint16_t dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


/*
函数说明：LCD写入命令
入口数据：dat 写入的命令
返回值：  无
*/
void LCD_WR_REG(uint8_t dat)
{
	LCD_DC_Clr();//写命令
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//写数据
}

void LCD_Delay_Ms(uint16_t ms)
{
	for(uint16_t i = 0 ; i < ms ; i ++)
		for(uint16_t j = 0 ; j < 15000 ; j ++);
}


/*
函数说明：设置起始和结束地址
入口数据：x1,x2 设置列的起始和结束地址
		y1,y2 设置行的起始和结束地址
返回值：  无
*/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	LCD_WR_REG(0x2a);	//列地址设置
	LCD_WR_DATA(x1);
	LCD_WR_DATA(x2);
	LCD_WR_REG(0x2b);	//行地址设置
	LCD_WR_DATA(y1);
	LCD_WR_DATA(y2);
	LCD_WR_REG(0x2c);	//储存器写
}

/*
函数说明：在指定区域填充颜色
入口数据：xsta,ysta   起始坐标
		xend,yend   终止坐标
		color       要填充的颜色
返回值：  无
*/
void LCD_Fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color)
{
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);
	for(uint16_t i=ysta; i<yend; i++)
	{
		for(uint16_t j=xsta; j<xend; j++)
		{
			LCD_WR_DATA(color);
		}
	}
}

void LCD_Init(void)
{
	LCD_BLK_Clr();//关闭背光
	LCD_RES_Clr();//复位
	LCD_Delay_Ms(100);
	LCD_RES_Set();
	LCD_Delay_Ms(100);

	//Start Initial Sequence=======================================
	LCD_WR_REG(0x11);
	LCD_Delay_Ms(100);

	// Memory Access Control
	LCD_WR_REG(0X36);
	if(USE_HORIZONTAL==0)
		LCD_WR_DATA8(0x00);
	else if(USE_HORIZONTAL==1)
		LCD_WR_DATA8(0xC0);
	else if(USE_HORIZONTAL==2)
		LCD_WR_DATA8(0x70);
	else 
		LCD_WR_DATA8(0xA0);
	LCD_WR_REG(0X3A);
	LCD_WR_DATA8(0X05);

	//ST7789S Frame rate setting
	LCD_WR_REG(0xb2);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x33);
	LCD_WR_REG(0xb7);
	LCD_WR_DATA8(0x35);

	//ST7789S Power setting
	LCD_WR_REG(0xbb);
	LCD_WR_DATA8(0x35);
	LCD_WR_REG(0xc0);
	LCD_WR_DATA8(0x2c);
	LCD_WR_REG(0xc2);
	LCD_WR_DATA8(0x01);
	LCD_WR_REG(0xc3);
	LCD_WR_DATA8(0x13);
	LCD_WR_REG(0xc4);
	LCD_WR_DATA8(0x20);
	LCD_WR_REG(0xc6);
	LCD_WR_DATA8(0x0f);
	LCD_WR_REG(0xca);
	LCD_WR_DATA8(0x0f);
	LCD_WR_REG(0xc8);
	LCD_WR_DATA8(0x08);
	LCD_WR_REG(0x55);
	LCD_WR_DATA8(0x90);
	LCD_WR_REG(0xd0);
	LCD_WR_DATA8(0xa4);
	LCD_WR_DATA8(0xa1);
	
	//ST7789S gamma setting
	LCD_WR_REG(0xe0);
	LCD_WR_DATA8(0xd0);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x06);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x0b);
	LCD_WR_DATA8(0x2a);
	LCD_WR_DATA8(0x3c);
	LCD_WR_DATA8(0x55);
	LCD_WR_DATA8(0x4b);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x16);
	LCD_WR_DATA8(0x14);
	LCD_WR_DATA8(0x19);
	LCD_WR_DATA8(0x20);
	LCD_WR_REG(0xe1);
	LCD_WR_DATA8(0xd0);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x06);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x0b);
	LCD_WR_DATA8(0x29);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x4b);
	LCD_WR_DATA8(0x0d);
	LCD_WR_DATA8(0x16);
	LCD_WR_DATA8(0x14);
	LCD_WR_DATA8(0x21);
	LCD_WR_DATA8(0x20);
	LCD_WR_REG(0x29);

	LCD_Fill(0, 0, 240, 320, 0xF000);//清屏

	LCD_BLK_Set();//打开背光
}