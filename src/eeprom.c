#include "eeprom.h"
#include <string.h>


void i2cInit(void){
    i2c_init(I2C_ID, 100 * 1000);          // Parameter 1 Either i2c0 or i2c1, Parameter 2 Baudrate
    gpio_set_function(PICO_I2C_SDA_PIN, GPIO_FUNC_I2C);             // Se escoge como funcionalidad del gpio el i2c con le pin para SDA
    gpio_set_function(PICO_I2C_SCL_PIN, GPIO_FUNC_I2C);             // Se escoge como funcionalidad del gpio el i2c con le pin para SCL
    gpio_pull_up(PICO_I2C_SDA_PIN);
    gpio_pull_up(PICO_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    //bi_decl(bi_2pins_with_func(PICO_I2C_SDA_PIN, PICO_I2C_SCL_PIN, GPIO_FUNC_I2C)); 
}

/* description: This function is used to write the data at specified EEPROM_address..*/
void EEPROM_WriteByte(uint8_t *var_eepromData, int TamData){

    if(i2c_write_blocking(I2C_ID, COMMAN_CTR, var_eepromData, TamData, false) == PICO_ERROR_GENERIC){
        printf("Error de escritura\n");
    }else{
        sleep_ms(50);
    }
    
}

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

/* description: This function is used to read the data from specified EEPROM_address.        */
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

// void EEPROM_ReadNBytes(uint16_t StartPonter, uint8_t *array){
//     uint8_t buffer[3] = {0, 0, 0};
//     int8_t Data = 0x00;
//     uint8_t HightByte = StartPonter >> 8;
//     uint8_t LowByte = StartPonter & 0x00FF;

//     for (int i = 0; i < strlen(array); i++){
//         HightByte = StartPonter >> 8;
//         LowByte = StartPonter & 0x00FF;
//         buffer[0] = HightByte;
//         buffer[1] = LowByte;
//         Data = EEPROM_ReadByte(buffer);
//         printf("%c", Data);
//         StartPonter ++;
//     }
//     printf("\n");
// }

