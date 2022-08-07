#ifndef _MAIN_H_
#define _MAIN_H_

//system
#include "at32f403a_407.h"
#include "at32f403a_407_clock.h"

//bsp
#include "gpio.h"
#include "spi.h"
#include "dma.h"
#include "timer.h"

//hardware
#include "lcd.h"

//application
#include "lvgl.h"
#include "lv_port_disp.h"

void System_Init(void);

#endif