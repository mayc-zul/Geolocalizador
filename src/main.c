#include "events.h"

// --------------------------------------------------------------------------------------
// ---------------- 2. Deifinicion e inicializacion de variables ------------------------
// --------------------------------------------------------------------------------------


// --------------------- Banderas --------------------------- 
bool Flagshow = true;
bool Flagpress = false;
uint16_t Addr = 0x0000;

// ---------------------------------------------------------
// ---------------------- 3. Main --------------------------
// ---------------------------------------------------------

int main(void) {
    int cont = 0;
    uint8_t Data = 0x00;

    EventAllInit();
    
    while (1){

        process_Events();
        
        // __asm volatile("wfi");
    }

        
    return 0;
}