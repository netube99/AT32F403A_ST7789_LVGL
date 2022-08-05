#ifndef _GPIO_H_
#define _GPIO_H_

//lcd屏幕
//lcd_res
#define GPIO_LCD_RES_PIN        GPIO_PINS_1
#define GPIO_LCD_RES_PORT       GPIOB
#define _GPIO_LCD_RES_H()       gpio_bits_write(GPIO_LCD_RES_PORT, GPIO_LCD_RES_PIN, TRUE)
#define _GPIO_LCD_RES_L()       gpio_bits_write(GPIO_LCD_RES_PORT, GPIO_LCD_RES_PIN, FALSE)
//lcd_dc
#define GPIO_LCD_DC_PIN         GPIO_PINS_8
#define GPIO_LCD_DC_PORT        GPIOB
#define _GPIO_LCD_DC_H()        gpio_bits_write(GPIO_LCD_DC_PORT, GPIO_LCD_DC_PIN, TRUE)
#define _GPIO_LCD_DC_L()        gpio_bits_write(GPIO_LCD_DC_PORT, GPIO_LCD_DC_PIN, FALSE)
//lcd_cs
#define GPIO_LCD_CS_PIN         GPIO_PINS_9
#define GPIO_LCD_CS_PORT        GPIOB
#define _GPIO_LCD_CS_H()       gpio_bits_write(GPIO_LCD_CS_PORT, GPIO_LCD_CS_PIN, TRUE)
#define _GPIO_LCD_CS_L()       gpio_bits_write(GPIO_LCD_CS_PORT, GPIO_LCD_CS_PIN, FALSE)

void Gpio_Init(void);

#endif