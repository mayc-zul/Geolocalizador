#ifndef EVENTS_H_
#define EVENTS_H_

// ---------------------------------------------------------------------------
// ---------------------- 1. Importacion de librerias ------------------------
// ---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "KeyMatrix.h" 
#include "timer.h"
#include "lcd.h"
#include "eeprom.h"
#include "gps.h"

#define CNT_SAMPLE       4000
#define N_SAMPLE         10



void EventAllInit(void);
void process_Events(void);
void FormatPoint(void);
myfloat ReadEEPROM (uint32_t Addr);

#endif