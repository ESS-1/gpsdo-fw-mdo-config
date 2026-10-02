#include <stdint.h>

typedef struct __attribute__((packed)) {
    // Bootloader version string
    const char bootloader_version[8];

    // Boot logo
    const struct __attribute__((packed)) {
        const uint8_t* image;
        uint32_t image_length;
        uint32_t format;
        uint16_t width;
        uint16_t height;
    } boot_logo;

    // LCD initialization commands
    const struct __attribute__((packed)) {
        const uint8_t* commands;
        uint32_t commands_length;
    } display_init_commands;
} boot_data_t;
