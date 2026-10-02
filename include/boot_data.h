#include <stdint.h>

typedef struct __attribute__((packed)) {
    // Bootloader version string
    char bootloader_version[8];

    // Boot logo
    struct __attribute__((packed)) {
        uint8_t* data;
        uint32_t data_length;
        uint16_t width;
        uint16_t height;
    } boot_logo;

    // LCD initialization commands
    struct __attribute__((packed)) {
        uint8_t* lcd_init_commands;
        uint32_t lcd_init_commands_length;
    } lcd_init_commands;
} boot_data_t;
