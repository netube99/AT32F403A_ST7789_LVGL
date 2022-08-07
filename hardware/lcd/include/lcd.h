#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "stdint.h"
#include "spi.h"
#include "gpio.h"

#define USE_HORIZONTAL 2  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 320

#else
#define LCD_W 320
#define LCD_H 240
#endif

#define TCLK 		PGout(12)  	//PG12  SCLK
#define TDIN 		PDout(5)  	//PD5   MOSI
#define DOUT 		PEin(8)   	//PE8   MISO
#define TCS  		PEout(12)  	//PE12  CS2
#define PEN  		PEin(14)    //PE14  INT

//-----------------LCD端口定义---------------- 
// #define LCD_SCLK_Clr() GPIO_ResetBits(GPIOG,GPIO_Pin_12)//SCL=SCLK
// #define LCD_SCLK_Set() GPIO_SetBits(GPIOG,GPIO_Pin_12)
// #define LCD_MOSI_Clr() GPIO_ResetBits(GPIOD,GPIO_Pin_5)//SDA=MOSI
// #define LCD_MOSI_Set() GPIO_SetBits(GPIOD,GPIO_Pin_5)

#define LCD_RES_Clr()   _GPIO_LCD_RES_L()
#define LCD_RES_Set()   _GPIO_LCD_RES_H()
#define LCD_DC_Clr()    _GPIO_LCD_DC_L()
#define LCD_DC_Set()    _GPIO_LCD_DC_H()
#define LCD_CS_Clr()    _GPIO_LCD_CS_L()
#define LCD_CS_Set()    _GPIO_LCD_CS_H()
#define LCD_BLK_Clr()   _GPIO_LCD_BLK_L()
#define LCD_BLK_Set()   _GPIO_LCD_BLK_H()
#define LCD_SPIX        SPI1

void LCD_Writ_Bus(uint8_t dat); //总线发送数据
void LCD_WR_DATA8(uint8_t dat); //写入一个字节
void LCD_WR_DATA(uint16_t dat); //写入两个字节
void LCD_WR_REG(uint8_t dat);   //写入一个指令
void LCD_Delay_Ms(uint16_t ms); //简单延时
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//设置坐标函数
void LCD_Fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color);
void LCD_Init(void);//LCD初始化
#endif
