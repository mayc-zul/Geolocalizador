#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "timer.h"
#include "KeyMatrix.h"


unsigned char cnt_ProcessKey = 0;                   // Definición variable para hacar el debounce
bool ProcesarTecla = false;                         // Bandera para verificar si se procesa una tecla

const int col[4] = {5,4,3,2};                       // Puertos del GPIO correspondintes a las columnas
const int row[4] = {9,8,7,6};                       // Puertos del GPIO correspondintes a las filas

unsigned char iRow = 0, iCol = 0;                   // Variables para capturar la tecla

char keys[4][4] = {
  { '1','2','3', 'A' },
  { '4','5','6', 'B' },
  { '7','8','9', 'C' },
  { '*','0','#', 'D' }
};

volatile bool gpio_req = false;                     // Bandera para indicar la activación del la interrupción del GPIO
volatile uint gpioRead;                             // Varibale para identificar el puerto GPIO correspondiente a la interrupción

// Defincion del callback para la interrupción del GPIO
void gpio_callback (uint gpio, uint32_t events){
    gpio_req = true;
    gpioRead = gpio;
    
}

// Inicialización de los puertos para el teclado matrizial
void keyMatrixInit(void) {
	
    // Definción del las columnas como entradas en pull-up
    for (int i = 0; i < 4; i++){
        //---- Col --------
        gpio_init(col[i]);                                                                      // Difinición de los puertos
        gpio_set_dir(col[i], GPIO_IN);                                                          // Configuración las columnas como entradas
        gpio_pull_up(col[i]);                                                                   // Configuración entradas en pull up (columnas)
        gpio_set_irq_enabled_with_callback(col[i], GPIO_IRQ_EDGE_FALL, true, gpio_callback);    // Habilitar interrupción con callback cuando ocurra una flanco de bajada
        
        //---- Row --------
        gpio_init(row[i]);                                                                      // Definición de los puertos
        gpio_set_dir(row[i], GPIO_OUT);                                                         // Configuración las filas como salidas
        gpio_put(row[i], 0);                                                                    // Se inicializan en 1
    }
}

void ChangePort(void){
    for (int i = 0; i < 4; i++){
        gpio_set_irq_enabled_with_callback(col[i], GPIO_IRQ_EDGE_FALL, false, gpio_callback);
        gpio_set_dir(row[i], GPIO_IN);
        gpio_pull_up(row[i]);        
        gpio_set_dir(col[i], GPIO_OUT);
        gpio_put(col[i], 0);
    }
}

// Lectura de la tecla presionada
char keyMatrixRead(void){
    if(gpio_req){
        gpio_req = false;
        ProcesarTecla = true;  
        for (int i = 0; i < 4; i++){
            if(gpioRead == col[i]){
                iCol = i;
            }            
        }
        ChangePort();
    }
    if(cnt_ProcessKey == CNT_DEBOUNCE){
        cnt_ProcessKey = 0;
        ProcesarTecla = false;
        for (int i = 0; i < 4; i++){
            if(gpio_get(row[i]) == 0){
                iRow = i;
            }
        } 
        return keys[iRow][iCol];
    }  
    return '.';
}