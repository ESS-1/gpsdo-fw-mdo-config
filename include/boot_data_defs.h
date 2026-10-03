#pragma once

#include <stdint.h>

// Boot logo
typedef struct __attribute__((packed)) {
    const uint8_t* image;
    uint32_t image_length;
    uint32_t format;
    uint16_t width;
    uint16_t height;
} boot_logo_t;

// LCD initialization commands
typedef struct __attribute__((packed)) {
    const uint8_t* commands;
    uint32_t commands_length;
} display_init_commands_t;

// Boot data
typedef struct __attribute__((packed)) {
    char bootloader_version[8];
    boot_logo_t boot_logo;
    display_init_commands_t display_init_commands;
} boot_data_t;

const boot_data_t* const g_boot_data = (boot_data_t* const)(FLASH_BASE + (BOOTLOADER_SIZE - BOOTLOADER_DATA_SIZE));
