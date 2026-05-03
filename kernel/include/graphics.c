#include <graphics.h>

void printChar(char c, int px, int py){
    const uint8_t *bitmap = font[(uint8_t)c];
    for (int x=0; x < 8; x++) {
        for (int y=0; y < 8; y++) {
            if(bitmap[x]&(1<<(7-y))){
                drawPixel(px-y, py+x, 255, 255, 255);
            }
        }
    }
}

void printf(const char* str, int px, int py){
    while(*str){
        printChar(*str, px, py);
        px+=8;
        str++;
    }
}

void clrScr(uint8_t r, uint8_t g, uint8_t b) {
    uint32_t color = ((r & ((1 << fb.red_size)-1)) << fb.red_shift) |
                     ((g & ((1 << fb.green_size)-1)) << fb.green_shift) |
                     ((b & ((1 << fb.blue_size)-1)) << fb.blue_shift);

    size_t bpp_bytes = fb.bpp / 8;

    for (size_t y = 0; y < fb.height; y++) {
        uint8_t* row = fb.virt + y * fb.pitch;
        for (size_t x = 0; x < fb.width; x++) {
            if (bpp_bytes == 4) {
                ((uint32_t*)row)[x] = color;
            } else if (bpp_bytes == 3) {
                row[x*3 + 0] = (color >> 0) & 0xFF;
                row[x*3 + 1] = (color >> 8) & 0xFF;
                row[x*3 + 2] = (color >> 16) & 0xFF;
            }
        }
    }
}

void drawRect(int x, int y, int w, int h, uint32_t color) {
    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = color & 0xFF;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            drawPixel(x + i, y + j, r, g, b); 
        }
    }
}
