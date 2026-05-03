#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <fb.h>
#include <font8.h>

void printChar(char c, int px, int py);
void printf(const char* str, int px, int py);
void clrScr(uint8_t r, uint8_t g, uint8_t b);
void drawRect(int x, int y, int w, int h, uint32_t color);

#endif
