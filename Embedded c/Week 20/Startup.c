#include <stdint.h>

#define RAM_START 0x20000000u
#define RAM_SIZE  (128*1024)
#define RAM_END   (RAM_START + RAM_SIZE)

#define STACK_START RAM_END
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;

void Reset_Handler(void) {
    
    uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t* SRC  = (uint8_t*)&_etext;
    uint8_t* DEST = (uint8_t*)&_sdata;

    for (uint32_t i = 0; i < data_size; i++) {
        *DEST++ = *SRC++;
    }

    data_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    DEST = (uint8_t*)&_sbss;

    for (uint32_t i = 0; i < data_size; i++) {
        *DEST++ = 0U;
    }

    main();

    while (1);
}


void Default_Handler(void) {
    while (1);
}

void NMI_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));

uint32_t Vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)SVC_Handler,
    0,
    0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_IRQHandler,
    (uint32_t)TAMP_STAMP_IRQHandler,
    (uint32_t)RTC_WKUP_IRQHandler,
    (uint32_t)FLASH_IRQHandler,
    (uint32_t)RCC_IRQHandler,
    (uint32_t)EXTI0_IRQHandler,
    (uint32_t)EXTI1_IRQHandler,
    (uint32_t)EXTI2_IRQHandler,
    (uint32_t)EXTI3_IRQHandler,
    (uint32_t)EXTI4_IRQHandler,
    (uint32_t)DMA1_Stream0_IRQHandler,
    (uint32_t)DMA1_Stream1_IRQHandler,
    (uint32_t)DMA1_Stream2_IRQHandler,
    (uint32_t)DMA1_Stream3_IRQHandler,
    (uint32_t)DMA1_Stream4_IRQHandler,
    (uint32_t)DMA1_Stream5_IRQHandler,
    (uint32_t)DMA1_Stream6_IRQHandler,
    (uint32_t)ADC_IRQHandler,
    (uint32_t)CAN1_TX_IRQHandler,
    (uint32_t)CAN1_RX0_IRQHandler
};