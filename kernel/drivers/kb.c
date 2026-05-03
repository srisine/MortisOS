#include <kb.h>

#define PIC1_COMMAND 0x20
#define PIC_EOI     0x20

void append_to_shell(char c) {
    if (index < 255) { 
        command[index++] = c;
        command[index] = '\0';

        renderTxt();
    }
}

void print_letter(uint8_t scancode) {
    switch (scancode) {
        case 0x02: append_to_shell('1'); break;
        case 0x03: append_to_shell('2'); break;
        case 0x04: append_to_shell('3'); break;
        case 0x05: append_to_shell('4'); break;
        case 0x06: append_to_shell('5'); break;
        case 0x07: append_to_shell('6'); break;
        case 0x08: append_to_shell('7'); break;
        case 0x09: append_to_shell('8'); break;
        case 0x0A: append_to_shell('9'); break;
        case 0x0B: append_to_shell('0'); break;
        case 0x0E: backspace(); break;
        
        case 0x10: append_to_shell('Q'); break;
        case 0x11: append_to_shell('W'); break;
        case 0x12: append_to_shell('E'); break;
        case 0x13: append_to_shell('R'); break;
        case 0x14: append_to_shell('T'); break;
        case 0x15: append_to_shell('Y'); break;
        case 0x16: append_to_shell('U'); break;
        case 0x17: append_to_shell('I'); break;
        case 0x18: append_to_shell('O'); break;
        case 0x19: append_to_shell('P'); break;

        case 0x1E: append_to_shell('A'); break;
        case 0x1F: append_to_shell('S'); break;
        case 0x20: append_to_shell('D'); break;
        case 0x21: append_to_shell('F'); break;
        case 0x22: append_to_shell('G'); break;
        case 0x23: append_to_shell('H'); break;
        case 0x24: append_to_shell('J'); break;
        case 0x25: append_to_shell('K'); break;
        case 0x26: append_to_shell('L'); break;

        case 0x2C: append_to_shell('Z'); break;
        case 0x2D: append_to_shell('X'); break;
        case 0x2E: append_to_shell('C'); break;
        case 0x2F: append_to_shell('V'); break;
        case 0x30: append_to_shell('B'); break;
        case 0x31: append_to_shell('N'); break;
        case 0x32: append_to_shell('M'); break;

        case 0x39: append_to_shell(' '); break; 
        
        case 0x1C:
            drawRect(cursor_x-8, 16*lineNo, 5, 10, 0x000000); //Sheesh took too long but no more cursor visible when pressed enter! ;)
            execCmd();
            index = 0;      
            cursor_x = 20; 
            addLine();
            renderTxt(); 
            printf("$", 10, 16*lineNo);
            break;

        default: break; 
    }
}
static void keyboard_callback(registers_t *r) {
    uint8_t scancode = port_byte_in(0x60);
    if (scancode & 0x80) {
        port_byte_out(0x20, 0x20);
        return;
    }
    print_letter(scancode);
    port_byte_out(0x20, 0x20);
}

void init_keyboard() {
    register_interrupt_handler(33, keyboard_callback);
    pic_unmask_irq(1);
}

