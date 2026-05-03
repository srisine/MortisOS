#include "GUI.h"

char command[256];
int index = 0;

int cursor_x = 20; 

void renderTxt() {
    int start_x = 20;

    drawRect(start_x, 16*lineNo, 256 * 8, 16, 0x000000);
    printf("$", 10, 16*lineNo);
    int temp_x = start_x;

    for(int i = 0; i < index; ++i) {
        char str[2] = {command[i], '\0'};
        printf(str, temp_x, 16*lineNo);
        temp_x += 8; 
    }

    cursor_x = temp_x;
}

void backspace() {
    if (index > 0) {
        index--;

        cursor_x -= 8;

        renderTxt();

        command[index] = '\0';
    }
}
