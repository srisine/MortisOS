#pragma once
#include <stdint.h>
#include <graphics.h>
#include <ports.h>

#define NUM_INTERRUPTS 256


typedef struct registers {
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    uint64_t r11;
    uint64_t r10;
    uint64_t r9;
    uint64_t r8;
    uint64_t rbp;
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rdx;
    uint64_t rcx;
    uint64_t rbx;
    uint64_t rax;

    uint64_t int_no;    // interrupt number
    uint64_t err_code;  // error code if present

    uint64_t rip;
    uint64_t cs;
    uint64_t rflags;
    uint64_t rsp;
    uint64_t ss;
} registers_t;


typedef void (*isr_t)(registers_t *r);


void isr_install();


void isr_handler(registers_t *r);


void register_interrupt_handler(uint8_t n, isr_t handler);

void pic_remap();

void pic_mask_all(void);

void pic_unmask_irq(uint8_t irq);
