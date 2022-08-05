#ifndef _DMA_H_
#define _DMA_H_

#include "stdint.h"

#define _DMA1CH3_ENABLE()   dma_channel_enable(DMA1_CHANNEL3, TRUE)//DMA1通道2 开始传输

void Dma1_Ch3_Config(uint32_t memory_base_addr, uint32_t peripheral_base_addr, uint16_t data_size);

#endif