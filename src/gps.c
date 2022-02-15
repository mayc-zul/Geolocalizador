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
uint8_t ArrayCnt[3] = {0x00, 0x00, 0};


//Inicialización UART0 (Buadios(bits/seg), Puertos GPIO como TX/RX, FIFO desactivada, Interrupción RX unicamente)
void uartInit(){
    uart_init(UART_ID, BOUD_RATE);
    gpio_set_function(PICO_UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(PICO_UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_fifo_enabled(UART_ID, false);

    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);
    uart_set_irq_enables(UART_ID, true, false);
}

//Subrutina ante interrupción por dato recibido(Se toma el caracter, se almacena y luego se activa la bandera de interrupción).
void on_uart_rx(){
    while (uart_is_readable(UART_ID)){
        char ch = uart_getc(UART_ID);
        caracter = ch;
        uart_req = true;
    }
}

//Máquina de estados cuya funcionalidad es exportar Latitud y Longitud de la trama de caracteres que retorna el satélite.
void LatLonGet(char ch){
    char NSampleCaracter[3];
    switch (state){
        //Estado #0 : Detección secuencia $ y reinicio de variables auxiliares Lat y Long
        case 0:
            if(ch == '$'){
                state = 1;
                strcpy(Long, "");
                strcpy(Lat, "");
            }else{
                state = 0;
            }
            break;
        //Estado #1 : Detección secuencia $G    
        case 1:
            if(ch == 'G'){
                state = 2;
            }else{
                state = 0;
            }
            break;
        //Estado #2 : Detección secuencia $GP
        case 2:
            if(ch == 'P'){
                state = 3;
            }else{
                state = 0;
            }
            break;
        //Estado #3 : Detección secuencia $GPR    
        case 3:
            if(ch == 'R'){
                state = 4;
            }else{
                state = 0;
            }
            break;
        //Estado #4 : Detección secuencia $GPRM 
        case 4:
            if(ch == 'M'){
                state = 5;
            }else{
                state = 0;
            }
            break;
        //Estado #5 : Detección secuencia $GPRMC    
        case 5:
            if(ch == 'C'){
                state = 6;
            }else{
                state = 0;
            }
            break;
        //Estado #6 : Obtención de la hora actual en formato UTC, en caso de obtener un posicionamiento
        //válido ($GPRMC,(HH:MM:SS),A) se continua obteniendo datos y en caso que no ($GPRMC,(HH:MM:SS),V)
        //se retorna al estado 0, para obtener una nueva trama.
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
        // Estado #7: Obtención de la longitud con su respectivo signo, luego de obtenerse dicha longitud
        // es almacenada en la estructura IEEE.
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
        // Estado #8: Obtención de la latitud con su respectivo signo, luego de obtenerse dicha latitud
        // es almacenada en la estructura IEEE, luego de tenerse la longitu y latitud, se proceden a escribir
        // en la memoria EEEPROM mediante el uso del protoclo I2C.    
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
                ArrayCnt[2] = CntSample;
                EEPROM_WriteByte(ArrayCnt, 3);

                //En caso de Seguimiento, se visualiza Latitud, Longitu y Hora en el LCD.
                if(FlagMode1){
                    //Depsliegue de latitud y Longitu
                    if (FlagShow){
                        Clear();
                        setCursor(1,1);
                        WriteMessage("Long:");
                        setCursor(6,1);
                        WriteMessage(Signo(LongIEEE,Long));
                        setCursor(1,2);
                        WriteMessage("Lat:");
                        setCursor(5,2);
                        WriteMessage(Signo(LatIEEE,Lat));
                    }else{
                        //Depsliegue de Hora y numero de muestra
                        Clear();
                        setCursor(1,1);
                        WriteMessage("Time:");
                        setCursor(6,1);
                        WriteMessage(ProcessDate(Date));
                        setCursor(1,2);
                        WriteMessage("Sample:");
                        NSampleCaracter[0] = (CntSample / 10) + 48;
                        NSampleCaracter[1] = (CntSample % 10) + 48;
                        NSampleCaracter[2] = '\0';
                        setCursor(8,2);
                        WriteMessage(NSampleCaracter);
                    }
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

//Metodo usado para asignar flotante a la estructura IEEE
myfloat Float2IEEE(float var){
    myfloat num;
    num.f = var;
    return num;
}

//Método usado para asignar 32 bits a la estructura IEE implementada
myfloat IEEE2Float(uint32_t rep){
    myfloat num;
    num.raw.mantissa = rep & 0x007FFFFF;
    num.raw.exponent = ((rep & 0x7F800000) >> 23);
    num.raw.sign = ((rep & 0x80000000) >> 31);
    return num;
}

//Método usado para retornar Vector de enteros de 6 bytes para la transmision a la memoria EEPROM usando el protocolo I2C
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

//Método usado para retornar arreglo de caracteres con la hora colombiana en formato HH:MM:SS
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

//Método usado para mostrar el signo para latitudes y longitudes en el LCD
char* Signo(myfloat num, char *numstring){
    static char BufferString[15];
    if(num.raw.sign == 1){
        BufferString[0] = '-';
    }else{
        BufferString[0] = ' ';
    }
    for (int i = 0; i < strlen(numstring); i++){
        BufferString[i+1] = numstring[i];
    }
    return BufferString;

    
}

// char * UTMtoString(myfloat num){
//     static char BufferString[9];
//     int Resultado;
//     int Residuo;
    
//     Resultado = (int)b;
//     BufferString[0] = (Resultado / 10) + 48;
//     BufferString[1] = (Resultado % 10) + 48;
//     BufferString[2] = ',';
//     Residuo = Resultado % 1;
//     Resultado = (Residuo * 60);
//     BufferString[3] = (Resultado / 10) + 48;
//     BufferString[4] = (Resultado % 10) + 48;
//     BufferString[5] = '.';
//     Residuo = Resultado % 1;
//     Resultado = (Residuo * 60);
//     BufferString[6] = (Resultado / 10) + 48;
//     BufferString[7] = (Resultado % 10) + 48;
//     BufferString[8] = '\'';
    
//     return BufferString;
    
// }