#pragma once

#include <stdint.h>

#define HARDWARE_ID_SIZE 10
#define APP_VERSION_SIZE 10
#define APP_CRC_SIZE     (sizeof(uint32_t))

typedef struct __attribute__((packed)) {
    char hardware_id[HARDWARE_ID_SIZE] __attribute__((nonstring));
    char app_version[APP_VERSION_SIZE] __attribute__((nonstring));
} app_metadata_t;

#define G_APP_METADATA   ((const volatile app_metadata_t*)(FLASH_BASE + TOTAL_FLASH_SIZE - EEPROM_SIZE - APP_METADATA_SIZE))
#define G_APP_CRC        ((const volatile uint32_t*      )(FLASH_BASE + TOTAL_FLASH_SIZE - EEPROM_SIZE - APP_CRC_SIZE     ))
