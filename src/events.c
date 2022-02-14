#include "events.h"


// ------- Varible para leer la tecla presionada -------------
char key = '.';

int cnt = 0;
bool FlagGet = true;
uint32_t Hex;


void EventAllInit(){
    // Inicializar las funciones de entrada/salida estándar
    stdio_init_all();
    // Inicialización del modulo rtc, KeyMatrix y LCD
    keyMatrixInit();
    LCDInit();
    i2cInit();
    uartInit();
    // Inicialización del Timer
    TimerInit(CNT_SPLITREAD);
    setCursor(1,1);
    WriteMessage("1.Seguimiento");
    setCursor(1,2);
    WriteMessage("2.Consulta");
    
}

void process_Events(){
    // Se detecta la tecla oprimida
    key = keyMatrixRead();
    

    if(timer_req){
        timer_req = false;
        if (ProcesarTecla == true){                         // Se identifica si una tecla fue presionada
            cnt_ProcessKey++;                              // Activa el debounce
        }
        if(cnt == CNT_SAMPLE){
            FlagReadyRed = true;
            FlagShow = !FlagShow;
            cnt = 0;
            
        }
        cnt++;
    }

    if(uart_req){
        uart_req = false;
        if(FlagReadyRed &&  CntSample <= N_SAMPLE){
            LatLonGet(caracter);
        }
    }

    if(key != '.'){
        printf("char: %c\n",key);
        keyMatrixInit();
    }


    switch (key){
    case 'A':
        Clear();
        setCursor(1,1);
        WriteMessage("1.Seguimiento");
        setCursor(1,2);
        WriteMessage("2.Consulta");
        FlagMode1 = false;
        break;
    case '1':
        FlagMode1 = true;
        break;
    case '2':
        FormatPoint();
        break;
    case '3':
        CntSample = 0;
    default:
        break;
    }
    // if(CntSample == N_SAMPLE && FlagGet){

    //     for (int i = 0; i < N_SAMPLE*2; i++){
    //         DataRead = EEPROM_ReadByte(AddrRead, 4);
    //         Hex = (DataRead[0] << 24) + (DataRead[1] << 16) + (DataRead[2] << 8) + DataRead[3];
    //         NumData = IEEE2Float(Hex);
    //         printf("float: %f  hex: %x\n",NumData.f, NumData.raw);

    //         AddrRead = AddrRead + 4;
    //     }
    //     FlagGet = false;
        
    // }

    
}

void FormatPoint(){

    uint8_t NS = EEPROM_ReadByte(0x0000);
    uint16_t AddrRead = 0x0004;
    myfloat longitud;
    myfloat latitud;
    printf("%s", "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    printf("%s", "<kml xmlns=\"http://www.opengis.net/kml/2.2\">");
    printf("%s", "<Document>");
    for (int i = 0; i < NS; i++){
        longitud = ReadEEPROM(AddrRead);
        AddrRead = AddrRead + 4;
        latitud = ReadEEPROM(AddrRead);
        AddrRead = AddrRead + 4;
        printf("%s", "<Placemark>");
        printf("%s", "<Point>");
        printf("%s%f,%f,0%s", "<coordinates>", latitud.f/100.0, longitud.f/100.0,"</coordinates>");
        printf("%s", "</Point>");
        printf("%s", "</Placemark>");
    }
    printf("%s", "</Document>");
    printf("%s", "</kml>");
    
}

myfloat ReadEEPROM (uint32_t Addr){
    uint8_t *DataRead;
    myfloat NumData;
    DataRead = EEPROM_ReadNByte(Addr, 4);
    Hex = (DataRead[0] << 24) + (DataRead[1] << 16) + (DataRead[2] << 8) + DataRead[3];
    NumData = IEEE2Float(Hex);
    return NumData;
}