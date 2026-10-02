#include <stdint.h>

typedef struct __attribute__((packed)) {
    // Bootloader version string
    char bootloader_version[8];

    // Boot logo
    struct __attribute__((packed)) {
        uint8_t* image;
        uint32_t image_length;
        uint32_t compression;
        uint16_t width;
        uint16_t height;
    } boot_logo;

    // LCD initialization commands
    struct __attribute__((packed)) {
        uint8_t* commands;
        uint32_t commands_length;
    } display_init_commands;
} boot_data_t;
