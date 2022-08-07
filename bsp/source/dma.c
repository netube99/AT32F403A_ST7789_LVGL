#include "dma.h"
#include "at32f403a_407.h"

dma_init_type dma_init_struct ;

uint8_t dma1_ch3_busy = 0 ;

void Dma1_Ch3_Config(uint32_t memory_base_addr, uint32_t peripheral_base_addr, uint16_t data_size)
{
    crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

    dma_reset(DMA1_CHANNEL3);
    dma_init_struct.buffer_size = data_size;                                    //传输量
    dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;                   //内存到外设
    dma_init_struct.memory_base_addr = memory_base_addr;                        //内存基地址
    dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;             //数据宽度
    dma_init_struct.memory_inc_enable = TRUE;                                   //内存地址自增
    dma_init_struct.peripheral_base_addr = peripheral_base_addr;                //外设基地址
    dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;     //外设数据宽度
    dma_init_struct.peripheral_inc_enable = FALSE;                              //外设地址非自增
    dma_init_struct.priority = DMA_PRIORITY_MEDIUM;                             //中等优先级
    dma_init_struct.loop_mode_enable = FALSE;                                   //非循环模式
    dma_init(DMA1_CHANNEL3, &dma_init_struct);                                  //初始化dma
    dma_interrupt_enable(DMA1_CHANNEL3, DMA_FDT_INT, TRUE);                     //使能传输完成中断
    nvic_irq_enable(DMA1_Channel3_IRQn, 1, 0);//开启中断
    dma1_ch3_busy = 1 ;
    _DMA1CH3_ENABLE();
}

void DMA1_Channel3_IRQHandler(void)
{
    //DMA1通道3传输完成
    if(dma_flag_get(DMA1_FDT3_FLAG))
    {
        dma_flag_clear(DMA1_FDT3_FLAG);
        dma1_ch3_busy = 0 ;
    }
}

uint8_t Dma1_Ch3_IsBusy()
{
    return dma1_ch3_busy ;
}