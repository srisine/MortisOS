#pragma once

#include <ISR.h>
#include <ports.h>
#include <graphics.h>
#include <stdio.h>
#include <GUI.h>
#include <pit.h>

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

void beep(int freq, int ms);
void play_error_sound(); 
