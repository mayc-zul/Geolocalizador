# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

# compile ASM with C:/RPPicoSDK/armcc/10 2021.10/bin/arm-none-eabi-gcc.exe
# compile C with C:/RPPicoSDK/armcc/10 2021.10/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/RPPicoSDK/armcc/10 2021.10/bin/arm-none-eabi-g++.exe
ASM_DEFINES = -DCFG_TUSB_DEBUG=0 -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CORE=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_TARGET_NAME=\"myblinkkey\" -DPICO_USE_BLOCKED_RAM=0

ASM_INCLUDES = -IC:\Users\Maycol\DOCUME~1\UdeA\ONCEAV~1\EMBEBI~1\LABORA~1\GEOLOC~1\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_base\include -IC:\Users\Maycol\DOCUME~1\UdeA\ONCEAV~1\EMBEBI~1\LABORA~1\GEOLOC~1\build\GENERA~1\PICO_B~1 -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\boards\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_usb\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\src -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\src\common -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\hw -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_fix\rp2040_usb_device_enumeration\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_flash\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_usb_reset_interface\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_adc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_i2c\include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections

C_DEFINES = -DCFG_TUSB_DEBUG=0 -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CORE=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_TARGET_NAME=\"myblinkkey\" -DPICO_USE_BLOCKED_RAM=0

C_INCLUDES = -IC:\Users\Maycol\DOCUME~1\UdeA\ONCEAV~1\EMBEBI~1\LABORA~1\GEOLOC~1\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_base\include -IC:\Users\Maycol\DOCUME~1\UdeA\ONCEAV~1\EMBEBI~1\LABORA~1\GEOLOC~1\build\GENERA~1\PICO_B~1 -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\boards\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_usb\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\src -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\src\common -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\hw -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_fix\rp2040_usb_device_enumeration\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_flash\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_usb_reset_interface\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_adc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_i2c\include

C_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections -std=gnu11

CXX_DEFINES = -DCFG_TUSB_DEBUG=0 -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CORE=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_TARGET_NAME=\"myblinkkey\" -DPICO_USE_BLOCKED_RAM=0

CXX_INCLUDES = -IC:\Users\Maycol\DOCUME~1\UdeA\ONCEAV~1\EMBEBI~1\LABORA~1\GEOLOC~1\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_base\include -IC:\Users\Maycol\DOCUME~1\UdeA\ONCEAV~1\EMBEBI~1\LABORA~1\GEOLOC~1\build\GENERA~1\PICO_B~1 -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\boards\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_usb\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\src -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\src\common -IC:\RPPicoSDK\sdk\pico\pico-sdk\lib\tinyusb\hw -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_fix\rp2040_usb_device_enumeration\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\pico_unique_id\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_flash\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\common\pico_usb_reset_interface\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_adc\include -IC:\RPPicoSDK\sdk\pico\pico-sdk\src\rp2_common\hardware_i2c\include

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit -std=gnu++17

