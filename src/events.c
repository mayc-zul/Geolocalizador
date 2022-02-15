#include "events.h"


// ------- Varible para leer la tecla presionada -------------
char key = '.';

int cnt = 0;
bool FlagGet = true;
uint32_t Hex;


// Inicialización de los módulos (Timer, LCD, I2C, UART), GPIO's de entrada/salida usados y menú del aplicativo
void EventAllInit(){
    stdio_init_all();
    keyMatrixInit();
    LCDInit();
    i2cInit();
    uartInit();
    TimerInit(CNT_SPLITREAD);
    setCursor(1,1);
    WriteMessage("1.Seguimiento");
    setCursor(1,2);
    WriteMessage("2.Consulta");
    
}

//Procesamiento de eventos/interrupciones producidas por módulos y procesamiento de la interfaz de usuario LCD.
void process_Events(){
    key = keyMatrixRead();
    
    if(timer_req){
        timer_req = false;
        if (ProcesarTecla == true){                         
            cnt_ProcessKey++;                              
        }
        if(cnt == CNT_SAMPLE){
            FlagReadyRed = true;
            FlagShow = !FlagShow;
            cnt = 0;
        }
        cnt++;
    }

    //Polling asociado a la interupción por dato recibido donde se inactiva la bandera de interrupción y se procesa el caracter que captura, .
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

    //Impresión del menú en el LCD y decisión en caso de oprimirse alguna opción del menú.
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
    
}

//Metodo usado para exportar formato XML por la interfaz serial con las posiciones almacendas en la memoria EEPROM
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

//Metodo usado para leer de la memoria EEPROM una posiucion de memora especifica y retornar flotante almacenado.
myfloat ReadEEPROM (uint32_t Addr){
    uint8_t *DataRead;
    myfloat NumData;
    DataRead = EEPROM_ReadNByte(Addr, 4);
    Hex = (DataRead[0] << 24) + (DataRead[1] << 16) + (DataRead[2] << 8) + DataRead[3];
    NumData = IEEE2Float(Hex);
    return NumData;
}