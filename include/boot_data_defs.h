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

// Barcode
typedef struct {
    const uint8_t* data;
    uint32_t       data_length;
    uint16_t       width;
    uint16_t       height;
    uint16_t       bar_color;
    uint16_t       bg_color;
} barcode_t;

// LCD initialization commands
typedef struct {
    const uint8_t* init_commands;
    uint32_t       init_commands_length;

    uint16_t       vcom_min;
    uint16_t       vcom_max;
    uint16_t       vcom_adjust_step;
    uint16_t       vcom_default;
    int16_t        vcom_offset_mv;
    int16_t        vcom_step_mv;
} display_config_t;

// Boot data
typedef struct {
    char             bootloader_version[12]; // Null-terminated
    display_config_t display_config;
    boot_logo_t      boot_logo;
    barcode_t        app_update_url;
} boot_data_t;

_Static_assert(sizeof(boot_data_t) == 68, "boot_data_t size mismatch");

#define G_BOOT_DATA ((const volatile boot_data_t*)(FLASH_BASE + BOOTLOADER_SIZE - BOOTLOADER_DATA_SIZE))
