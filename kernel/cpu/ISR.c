#include <ISR.h>
#include <stdio.h>

static isr_t interrupt_handlers[NUM_INTERRUPTS];

char *exception_messages[] = {
        "Division By Zero",
        "Debug",
        "Non Maskable Interrupt",
        "Breakpoint",
        "Into Detected Overflow",
        "Out of Bounds",
        "Invalid Opcode",
        "No Coprocessor",

        "Double Fault",
        "Coprocessor Segment Overrun",
        "Bad TSS",
        "Segment Not Present",
        "Stack Fault",
        "General Protection Fault",
        "Page Fault",
        "Unknown Interrupt",

        "Coprocessor Fault",
        "Alignment Check",
        "Machine Check",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",

        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved"
};

void isr_handler(registers_t *r) {
    if (interrupt_handlers[r->int_no]) {
        interrupt_handlers[r->int_no](r);
    } else {
        printf(exception_messages[r->int_no], 100, 100);
        while (1)
            ; // Halt
    }
}

void register_interrupt_handler(uint8_t n, isr_t handler) {
    interrupt_handlers[n] = handler;
}

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr32();
extern void isr33();

void isr_install() {
    extern void set_idt_gate(int n, uint64_t handler, uint8_t flags);

    // Exceptions 0-31
    set_idt_gate(0,  (uint64_t)isr0,  0x8E);
    set_idt_gate(1,  (uint64_t)isr1,  0x8E);
    set_idt_gate(2,  (uint64_t)isr2,  0x8E);
    set_idt_gate(3,  (uint64_t)isr3,  0x8E);
    set_idt_gate(4,  (uint64_t)isr4,  0x8E);
    set_idt_gate(5,  (uint64_t)isr5,  0x8E);
    set_idt_gate(6,  (uint64_t)isr6,  0x8E);
    set_idt_gate(7,  (uint64_t)isr7,  0x8E);
    set_idt_gate(8,  (uint64_t)isr8,  0x8E);
    set_idt_gate(9,  (uint64_t)isr9,  0x8E);
    set_idt_gate(10, (uint64_t)isr10, 0x8E);
    set_idt_gate(11, (uint64_t)isr11, 0x8E);
    set_idt_gate(12, (uint64_t)isr12, 0x8E);
    set_idt_gate(13, (uint64_t)isr13, 0x8E);
    set_idt_gate(14, (uint64_t)isr14, 0x8E);
    set_idt_gate(15, (uint64_t)isr15, 0x8E);
    set_idt_gate(16, (uint64_t)isr16, 0x8E);
    set_idt_gate(17, (uint64_t)isr17, 0x8E);
    set_idt_gate(18, (uint64_t)isr18, 0x8E);
    set_idt_gate(19, (uint64_t)isr19, 0x8E);
    set_idt_gate(20, (uint64_t)isr20, 0x8E);
    set_idt_gate(21, (uint64_t)isr21, 0x8E);
    set_idt_gate(22, (uint64_t)isr22, 0x8E);
    set_idt_gate(23, (uint64_t)isr23, 0x8E);
    set_idt_gate(24, (uint64_t)isr24, 0x8E);
    set_idt_gate(25, (uint64_t)isr25, 0x8E);
    set_idt_gate(26, (uint64_t)isr26, 0x8E);
    set_idt_gate(27, (uint64_t)isr27, 0x8E);
    set_idt_gate(28, (uint64_t)isr28, 0x8E);
    set_idt_gate(29, (uint64_t)isr29, 0x8E);
    set_idt_gate(30, (uint64_t)isr30, 0x8E);
    set_idt_gate(31, (uint64_t)isr31, 0x8E);
    set_idt_gate(32, (uint64_t)isr32, 0x8E);
    set_idt_gate(33, (uint64_t)isr33, 0x8E);
}

void pic_remap(void) {
    uint8_t a1 = port_byte_in(0x21);
    uint8_t a2 = port_byte_in(0xA1);

    port_byte_out(0x20, 0x11);
    port_byte_out(0xA0, 0x11);

    port_byte_out(0x21, 0x20); // IRQs start at 32
    port_byte_out(0xA1, 0x28); // Slave at 40

    port_byte_out(0x21, 0x04);
    port_byte_out(0xA1, 0x02);

    port_byte_out(0x21, 0x01);
    port_byte_out(0xA1, 0x01);

    port_byte_out(0x21, a1);
    port_byte_out(0xA1, a2);
}

void pic_mask_all(void) {
    port_byte_out(0x21, 0xFF);
    port_byte_out(0xA1, 0xFF);
}

void pic_unmask_irq(uint8_t irq) {
    uint16_t port = (irq < 8) ? 0x21 : 0xA1;
    uint8_t mask = port_byte_in(port);
    port_byte_out(port, mask & ~(1 << (irq % 8)));
}

