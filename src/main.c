#include "events.h"

// --------------------------------------------------------------------------------------
// ---------------- 2. Deifinicion e inicializacion de variables ------------------------
// --------------------------------------------------------------------------------------


// --------------------- Banderas --------------------------- 
bool Flagshow = true;
bool Flagpress = false;
uint16_t Addr = 0x0000;
//uint8_t array[] = "A diferencia de los arrays de tipos de datos numéricos (arrays de enteros, de números con punto decimal, etc.), en donde cada elemento del array se debe considerar como una variable independiente de los demás,";

//uint8_t hola[10] = {0x00, 0x00, '&', '3', 'g', 'z',56, 65, 94, 29};

// ---------------------------------------------------------
// ---------------------- 3. Main --------------------------
// ---------------------------------------------------------

int main(void) {
    int cont = 0;
    uint8_t Data = 0x00;


    EventAllInit();
    // sleep_ms(5000);
    // printf("Escribiendo en la EEPROM\n");
    // EEPROM_WriteNBytes(Addr, array);
    // Addr = 0x0000;
    // EEPROM_ReadNBytes(Addr, array);
    
    while (1){
        // // Se detecta la tecla oprimida
        // key = keyMatrixRead();
        process_Events();
        // // -----------------------------------------------------------------------------------
        // // ------------- Seccion que se ejecuta al detectar interrupcion del timer -----------
        // // -----------------------------------------------------------------------------------
        // if (timer_req){
        //     timer_req = false;                                  // Se desactiva la bandera de la interrupción del Timer
        //     if (ProcesarTecla == true){                         // Se identifica si una tecla fue presionada
        //         cnt_ProcessKey++;                               // Activa el debounce
        //     }
        // }
        
        // if(key != '.'){
        //     printf("char: %c\n",key);
        //     keyMatrixInit();
        // }
        
        // __asm volatile("wfi");
    }

        
    return 0;
}