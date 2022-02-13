#Versión mínima requerida de Cmake
cmake_minimum_required(VERSION 3.12)

#Incluir funciones de SDK de PICO
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

#Nombre del proyecto y estándares del lenguaje aceptados
project(myblinkkey C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#Inicialización de varios elementos del proyecto
pico_sdk_init()

#Indicarle a Cmake los archivos de nuestro programa
add_executable(${PROJECT_NAME}
    src/main.c
    src/KeyMatrix.c
    src/timer.c
    src/lcd.c
    src/eeprom.c
    src/gps.c
    src/events.c
)

#Crear archivos de salida
pico_add_extra_outputs(${PROJECT_NAME})

include_directories(include)

#Enlazar a las librerías requeridas
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_adc
    hardware_irq
    hardware_gpio
    hardware_i2c
    hardware_uart
)

#Habilitar comunicación por USB
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)