#include <stdint.h>

typedef void(*interrupt_service_routine_t)(void);

extern uint32_t _stack_addr;
extern uint32_t _stored_data;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;

void isr_reset(void);
void isr_nmi(void);
void isr_hard_fault(void);
void isr_mem_fault(void);
void isr_bus_fault(void);
void isr_usage_fault(void);
void isr_svcall(void);
void isr_dbg_monitor(void);
void isr_pend_sv(void);
void isr_sys_tick(void);

void main(void);

const interrupt_service_routine_t ivt[] __attribute__ ((section(".ivt"))) =
{
    (interrupt_service_routine_t)(&_stack_addr),    // Stack address
    isr_reset,                                      // Reset
    isr_nmi,                                        // NMI
    isr_hard_fault,                                 // Hard fault
    isr_mem_fault,                                  // Memory management fault
    isr_bus_fault,                                  // Bus fault
    isr_usage_fault,                                // Usage fault
    nullptr,                                        // Reserved
    nullptr,                                        // Reserved
    nullptr,                                        // Reserved
    nullptr,                                        // Reserved
    isr_svcall,                                     // System service call
    isr_dbg_monitor,                                // Debug monitor
    nullptr,                                        // Reserved
    isr_pend_sv,                                    // Pendable request for system service
    isr_sys_tick,                                   // System tick timer
};

void isr_reset(void)
{
    {
        // Copy data
        const uint32_t* src = &_stored_data;
        uint32_t*       dst = &_data_start;

        while (dst != &_data_end)
        {
            *dst++ = *src++;
        }
    }

    {
        // Zero BSS
        uint32_t* dst = &_bss_start;
        while (dst != &_bss_end)
        {
            *dst++ = 0;
        }
    }

    main();
}

void isr_nmi(void)
{}

[[noreturn]] void isr_hard_fault(void)
{
    while (1);
}

[[noreturn]] void isr_mem_fault(void)
{
    while (1);
}

[[noreturn]] void isr_bus_fault(void)
{
    while (1);
}

[[noreturn]] void isr_usage_fault(void)
{
    while (1);
}

void isr_svcall(void)
{}

void isr_dbg_monitor(void)
{}

void isr_pend_sv(void)
{}

void isr_sys_tick(void)
{}

uint32_t counter = 0;

[[noreturn]] void main(void)
{
    while (1)
    {
        ++counter;
        if (counter > 1'000'000'000)
        {
            counter = 0;
        }
    }
}
