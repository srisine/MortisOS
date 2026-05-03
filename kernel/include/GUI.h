#ifndef GUI_H
#define GUI_H

#include<stdio.h>
#include<graphics.h>
#include<shell.h>

extern char command[256];
extern int index;

extern int cursor_x; 
extern int cursor_y;

void renderTxt();
void backspace();

#endif
