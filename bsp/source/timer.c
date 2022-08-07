#include "timer.h"
#include <at32f403a_407.h>

uint8_t system_timer_flag = 0;

void System_Timer_Init(void)
{
    crm_clocks_freq_type crm_clocks_freq_struct = {0};
    crm_clocks_freq_get(&crm_clocks_freq_struct);
    crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);
    tmr_base_init(TMR1, 50 - 1, 24000 - 1);
    tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
    tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);
    nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
    tmr_counter_enable(TMR1, TRUE);
}

//周期5ms
void TMR1_OVF_TMR10_IRQHandler(void)
{
    if(tmr_flag_get(TMR1, TMR_OVF_FLAG) != RESET)
    {
        tmr_flag_clear(TMR1, TMR_OVF_FLAG);
        System_Timer_Flag_Set(1);
    }
}

void System_Timer_Flag_Set(uint8_t flag)
{
    system_timer_flag = flag ;
}

uint8_t System_Timer_Flag_Get()
{
    return system_timer_flag ;
}