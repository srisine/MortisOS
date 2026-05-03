#pragma once

#include <ISR.h>
#include <ports.h>
#include <graphics.h>
#include <stdio.h>
#include <GUI.h>

extern uint64_t system_ticks;

void init_pit();
void sleep(uint32_t ms); 
