#pragma once

#include <stdint.h>

// Boot logo
typedef struct {
    const uint8_t* image;
    uint32_t       image_length;
    uint32_t       format;
    uint16_t       width;
    uint16_t       height;
} boot_logo_t;

// LCD initialization commands
typedef struct {
    const uint8_t* init_commands;
    uint32_t       init_commands_length;

    uint16_t       vcom_min;
    uint16_t       vcom_max;
    uint16_t       vcom_default;
    int16_t        vcom_base_mv;
    int16_t        vcom_step_mv;

    uint16_t       reserved_1;
} display_config_t;

// Boot data
typedef struct {
    char             bootloader_version[12];
    boot_logo_t      boot_logo;
    display_config_t display_config;
} boot_data_t;

_Static_assert(sizeof(boot_data_t) == 48, "boot_data_t size mismatch");

#define G_BOOT_DATA ((const volatile boot_data_t*)(FLASH_BASE + BOOTLOADER_SIZE - BOOTLOADER_DATA_SIZE))
