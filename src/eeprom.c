#include "eeprom.h"
#include <string.h>


//Inicialización módulo I2C (Puertos SDA,SCL, ID I2C y baudios)
void i2cInit(void){
    i2c_init(I2C_ID, 100 * 1000);
    gpio_set_function(PICO_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_I2C_SDA_PIN);
    gpio_pull_up(PICO_I2C_SCL_PIN);
}

//Metodo usado para transmitir cierta cantidad de bytes usando el protocolo I2C, a la memoria EEPROM
void EEPROM_WriteByte(uint8_t *var_eepromData, int TamData){

    if(i2c_write_blocking(I2C_ID, COMMAN_CTR, var_eepromData, TamData, false) == PICO_ERROR_GENERIC){
        printf("Error de escritura\n");
    }else{
        sleep_ms(50);
    }
    
}

//Método usado para leer y retornar un dato de 1 byte de la memoria EEPROM
uint8_t EEPROM_ReadByte(uint16_t var_eepromData){
    uint8_t buffer[2] = {0, 0};
    uint8_t HightByte = var_eepromData >> 8;
    uint8_t LowByte = var_eepromData & 0x00FF;
    uint8_t ReadData;  

    buffer[0] = HightByte;
    buffer[1] = LowByte;  

    if(i2c_write_blocking(I2C_ID, COMMAN_CTR, buffer, 2, false) != PICO_ERROR_GENERIC){
        if (i2c_read_blocking(I2C_ID, COMMAN_CTR, &ReadData, 1, false) == PICO_ERROR_GENERIC){
            printf("Error de lectura\n");
        }
    }else{
        printf("Error de escritura\n");
    }
    return ReadData;
    
}

//Método usado para leer y retornar N datos de 1 byte de la memoria EEPROM
uint8_t *EEPROM_ReadNByte(uint8_t var_eepromData, int TamData){
    uint8_t buffer[2] = {0, 0};
    uint8_t HightByte = var_eepromData >> 8;
    uint8_t LowByte = var_eepromData & 0x00FF;
    static uint8_t ReadData[4];  

    buffer[0] = HightByte;
    buffer[1] = LowByte;  

    if(i2c_write_blocking(I2C_ID, COMMAN_CTR, buffer, 2, false) != PICO_ERROR_GENERIC){
        if (i2c_read_blocking(I2C_ID, COMMAN_CTR, ReadData, TamData, false) == PICO_ERROR_GENERIC){
            printf("Error de lectura\n");
        }
    }else{
        printf("Error de escritura\n");
    }
    return ReadData;
    
}


//Método usado para escribir N datos en la memoria EEPROM, usando un apuntador para dicha escritura.
void EEPROM_WriteNBytes(uint16_t StartPonter, uint8_t *array){
    
    uint8_t buffer[3] = {0, 0, 0};
    uint8_t HightByte = StartPonter >> 8;
    uint8_t LowByte = StartPonter & 0x00FF;

    for (int i = 0; i < strlen(array); i++){
        buffer[0] = HightByte;
        buffer[1] = LowByte;
        buffer[2] = array[i];
        EEPROM_WriteByte(buffer, 3);
        StartPonter++;
        HightByte = StartPonter >> 8;
        LowByte = StartPonter & 0x00FF;
    }
}


