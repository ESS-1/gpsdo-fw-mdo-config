#pragma once

#include <stdint.h>

typedef struct __attribute__((packed)) {
    char hardware_id[10] __attribute__((nonstring));
    char app_version[10] __attribute__((nonstring));
} app_metadata_t;

#define HARDWARE_ID_SIZE (sizeof(((app_metadata_t*)0)->hardware_id))
#define APP_VERSION_SIZE (sizeof(((app_metadata_t*)0)->app_version))

const app_metadata_t* const g_app_metadata = (app_metadata_t* const)(FLASH_BASE + (TOTAL_FLASH_SIZE - EEPROM_SIZE - APP_METADATA_SIZE));
const uint32_t*       const g_app_crc      = (uint32_t* const)      (FLASH_BASE + (TOTAL_FLASH_SIZE - EEPROM_SIZE - sizeof(uint32_t)) );
