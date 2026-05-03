#include <stdio.h>
#include <boot_reqs.h>
#include <graphics.h>
#include <VGA.h>
#include <GDT.h>
#include <IDT.h>
#include <ISR.h>
#include <kb.h>
#include <pit.h>
#include <rtc.h>
#include <memmap.h>
#include <speaker.h>
#include <GUI.h>

void kmain(void) {
    chkBtl();
    initVGA();
    clrScr(0,0,0);

    initiateGDT();

    pic_remap();
    pic_mask_all();

    isr_install();        
    set_idt(); 

    pmm_init();

    asm volatile("sti");

    init_keyboard(); 
    init_pit(1000);

    hcf();
}

