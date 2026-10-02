#include <stdint.h>

typedef struct __attribute__((packed)) {
    // Bootloader version string
    const char bootloader_version[8];

    // Boot logo
    const struct __attribute__((packed)) {
        const uint8_t * const image;
        const uint32_t image_length;
        const uint32_t format;
        const uint16_t width;
        const uint16_t height;
    } boot_logo;

    // LCD initialization commands
    const struct __attribute__((packed)) {
        const uint8_t * const commands;
        const uint32_t commands_length;
    } display_init_commands;
} boot_data_t;
