#ifndef _GPS_H
#define _GPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "eeprom.h"
#include "lcd.h"


#define PICO_UART_TX_PIN  12
#define PICO_UART_RX_PIN  13
#define BOUD_RATE         9600
#define UART_ID           uart0
#define DATA_BITS         0
#define STOP_BITS         1
#define PARITY            UART_PARITY_NONE

extern char caracter;
extern bool uart_req;
extern bool FlagReadyRed;
extern uint8_t CntSample;
extern bool FlagMode1;
extern bool FlagShow;

typedef union {
    float f;
    struct
    {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
 
    } raw;
} myfloat;

void uartInit(void);
void on_uart_rx(void);
void LatLonGet(char ch);
myfloat Float2IEEE(float var);
myfloat IEEE2Float(uint32_t rep);
uint8_t * GenericVector(myfloat rep);
char *ProcessDate(char *ArrayDate);
char* Signo(myfloat num, char *numstring);
//char * UTMtoString(myfloat num);


#endif