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
    const uint8_t* commands;
    uint32_t       commands_length;
} display_init_commands_t;

// Boot data
typedef struct {
    char                    bootloader_version[12];
    boot_logo_t             boot_logo;
    display_init_commands_t display_init_commands;
} boot_data_t;

_Static_assert(sizeof(boot_data_t) == 36, "boot_data_t size mismatch");

#define G_BOOT_DATA ((const volatile boot_data_t*)(FLASH_BASE + BOOTLOADER_SIZE - BOOTLOADER_DATA_SIZE))
