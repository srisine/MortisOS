#include<pit.h>

uint64_t system_ticks = 0;

void pit_callback(registers_t *regs) {
    system_ticks++;

    if(system_ticks % 1000 == 0) {
        drawRect(cursor_x-8, 16*lineNo, 5, 10, 0xFFFFFF);
    } else if (system_ticks % 1000 == 500) { 
        drawRect(cursor_x-8, 16*lineNo, 5, 10, 0x000000);
    }

    port_byte_out(0x20, 0x20);
}

void init_pit(uint32_t frequency) {
    register_interrupt_handler(32, pit_callback);
    port_byte_out(0x43, 0x36);
    int32_t divisor = 1193182 / frequency;
    port_byte_out(0x40, (uint8_t)(divisor & 0xFF));
    port_byte_out(0x40, (uint8_t)((divisor >> 8) & 0xFF));
    pic_unmask_irq(0);
}

uint64_t get_ticks() {
    uint64_t ticks;
    asm volatile("cli"); 
    ticks = system_ticks;
    asm volatile("sti"); 
    return ticks;
}

void sleep(uint32_t ms) {
    uint64_t start_ticks = get_ticks();
    while ((get_ticks() - start_ticks) < ms) {
        asm volatile("hlt");
    }
}
