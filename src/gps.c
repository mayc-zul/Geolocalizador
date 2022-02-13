#include "gps.h"


uint8_t state = 0;
char Long[15];
char Lat[15];
char Date[6];
myfloat LongIEEE;
myfloat LatIEEE;
uint8_t ptr = 0;
char caracter;
bool uart_req = false;
bool FlagReadyRed = false;
bool FlagPoint = true;
bool FlagMode1 = false;
bool FlagShow = true;
uint16_t AddrWrite = 0x0004;
uint8_t CntSample = 0;
int CntShow = 0;
uint8_t ArrayCnt[3] = {0x00, 0x00, 0};



void uartInit(){
    // Initialise UART 0
    uart_init(UART_ID, BOUD_RATE);
    gpio_set_function(PICO_UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(PICO_UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_fifo_enabled(UART_ID, false);

    // Select correct interrupt for the UART we are using
    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);
    uart_set_irq_enables(UART_ID, true, false);     // Configure interrupt only rx

}

void on_uart_rx(){

    while (uart_is_readable(UART_ID)){
        char ch = uart_getc(UART_ID);
        //printf("%c", ch);
        caracter = ch;
        uart_req = true;
        //LatLonGet(ch);
    }
    
}

void LatLonGet(char ch){
    
    switch (state){
    case 0:
        if(ch == '$'){
            state = 1;
            strcpy(Long, "");
            strcpy(Lat, "");
        }else{
            state = 0;
        }
        break;
    case 1:
        if(ch == 'G'){
            state = 2;
        }else{
            state = 0;
        }
        break;
    case 2:
        if(ch == 'P'){
            state = 3;
        }else{
            state = 0;
        }
        break;
    case 3:
        if(ch == 'R'){
            state = 4;
        }else{
            state = 0;
        }
        break;
    case 4:
        if(ch == 'M'){
            state = 5;
        }else{
            state = 0;
        }
        break;
    case 5:
        if(ch == 'C'){
            state = 6;
        }else{
            state = 0;
        }
        break;
    case 6:
        if(ch == 'V'){
            state = 0;
            ptr = 0;
        }else if(ch == 'A'){
            state = 7;
            ptr = 0;
            FlagPoint = true;
        }else if(ch != ',' && FlagPoint){
            if(ch == '.'){
                FlagPoint = false;
            }else{
                Date[ptr] = ch;
                ptr++;
            }
            state = 6;
        }
        break;
    case 7:
        if(ch == 'N' || ch == 'S'){
            state = 8;
            ptr = 0; 
            LongIEEE = Float2IEEE(atof(Long));
            if(ch == 'N'){
                LongIEEE.raw.sign = 0;
            }else{
                LongIEEE.raw.sign = 1;
            }
        }else if(ch != ','){
            Long[ptr] = ch;
            ptr++;
            state = 7;
        }else{
            state = 7;
        }
        break;
    case 8:
        if(ch == 'W' || ch == 'E'){
            state = 0;
            ptr = 0;
            LatIEEE = Float2IEEE(atof(Lat));
            if(ch == 'E'){
                LatIEEE.raw.sign = 0;
            }else{
                LatIEEE.raw.sign = 1;
            }
            EEPROM_WriteByte(GenericVector(LongIEEE), 6);
            AddrWrite = AddrWrite + 4;
            EEPROM_WriteByte(GenericVector(LatIEEE), 6);
            AddrWrite = AddrWrite + 4;
            FlagReadyRed = false;
            CntSample++;
            printf("%d\n", CntSample);
            ArrayCnt[2] = CntSample;
            EEPROM_WriteByte(ArrayCnt, 3);
            //printf("Time: %s - Longitud: %f - %x   Latitud: %f - %x\n", ProcessDate(Date),LongIEEE.f, LongIEEE.raw, LatIEEE.f, LatIEEE.raw);
            if(FlagMode1){
                //if (FlagShow){
                    setCursor(1,1);
                    WriteMessage("Long:");
                    setCursor(6,1);
                    WriteMessage(Long);
                    setCursor(1,2);
                    WriteMessage("Lat:");
                    setCursor(5,2);
                    WriteMessage(Lat);
                // }else{
                //     Clear();
                //     returnHome();
                //     setCursor(1,1);
                //     WriteMessage("Time:");
                //     setCursor(6,1);
                //     WriteMessage(ProcessDate(Date));
                // }
            }
        }else if(ch != ','){
            Lat[ptr] = ch;
            ptr++;
            state = 8;
        }else{
            state = 8;
        }
        break;
    default:
        state = 0;
        break;
    }
}

myfloat Float2IEEE(float var){
    myfloat num;
    num.f = var;
    return num;
}

myfloat IEEE2Float(uint32_t rep){
    myfloat num;
    num.raw.mantissa = rep & 0x007FFFFF;
    num.raw.exponent = ((rep & 0x7F800000) >> 23);
    num.raw.sign = ((rep & 0x80000000) >> 31);
    return num;
}

uint8_t * GenericVector(myfloat rep){
    uint32_t sign = rep.raw.sign;
    uint32_t exponent = rep.raw.exponent;
    uint32_t mantissa = rep.raw.mantissa;
    uint32_t IEEE = (sign << 31) + (exponent << 23) + mantissa;
    static uint8_t buffer[6];
    buffer[0] = ((AddrWrite & 0xFF00) >> 8);
    buffer[1] = (AddrWrite & 0x00FF);
    buffer[2] = ((IEEE & 0xFF000000) >> 24);
    buffer[3] = ((IEEE & 0x00FF0000) >> 16);
    buffer[4] = ((IEEE & 0x0000FF00) >> 8);
    buffer[5] = (IEEE & 0x000000FF);
    return buffer;
}

char *ProcessDate(char *ArrayDate){
    char hour[2];
    static char BufferDate[9];
    uint8_t IntHour;
    hour[0] = ArrayDate[0];
    hour[1] = ArrayDate[1];
    IntHour = atoi(hour)-5;
    if(IntHour == 0){
        BufferDate[0] = '2';
        BufferDate[1] = '4';
    }else if(IntHour == -1){
        BufferDate[0] = '2';
        BufferDate[1] = '3';
    }else if(IntHour == -2){
        BufferDate[0] = '2';
        BufferDate[1] = '2';
    }else if(IntHour == -3){
        BufferDate[0] = '2';
        BufferDate[1] = '1';
    }else if(IntHour == -4){
        BufferDate[0] = '2';
        BufferDate[1] = '0';
    }
    else{
        BufferDate[0] = (IntHour / 10) + 48;
        BufferDate[1] = (IntHour % 10) + 48;
    }
    BufferDate[2] = ':';
    BufferDate[3] = ArrayDate[2];
    BufferDate[4] = ArrayDate[3];
    BufferDate[5] = ':';
    BufferDate[6] = ArrayDate[4];
    BufferDate[7] = ArrayDate[5];
    BufferDate[8] = '\0';
    return BufferDate;
}