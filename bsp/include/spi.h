#ifndef _SPI_H_
#define _SPI_H_

//SPI1
//SPI1_MOSI
#define GPIO_LCD_MOSI_PIN        GPIO_PINS_7
#define GPIO_LCD_MOSI_PORT       GPIOA
//SPI1_CLK
#define GPIO_LCD_CLK_PIN         GPIO_PINS_5
#define GPIO_LCD_CLK_PORT        GPIOA

void Spi1_Init(void);

#endif