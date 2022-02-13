#ifndef _EEPROM_H
#define _EEPROM_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"



//Value should be set referring the respective controller data sheet
#define C_MaxEepromSize_U16 256

/*PreCompile configuration to enable or disable the API's.
 1.Required interfaces can be enabled/disabled by configuring its respective macros to 1/0.
 2. By default all the API's are disabled. */

#define    COMMAN_CTR                0xA0 >> 1
#define PICO_I2C_SDA_PIN                14
#define PICO_I2C_SCL_PIN                15
#define I2C_ID                          i2c1



void i2cInit(void);
void EEPROM_WriteByte(uint8_t *var_eepromData, int TamData);
uint8_t EEPROM_ReadByte(uint16_t var_eepromData);
uint8_t *EEPROM_ReadNByte(uint8_t var_eepromData, int TamData);
void EEPROM_WriteNBytes(uint16_t StartPonter, uint8_t *array);

#endif