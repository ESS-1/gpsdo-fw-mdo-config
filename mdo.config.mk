# Total Flash memory: 128*1024 = 131072
TOTAL_FLASH_SIZE     := 131072

# Total bootloader size (including the bootloader data section): 14*1024 = 14336
BOOTLOADER_SIZE      := 14336
# Size of the bootloader data section at the end of the bootloader
BOOTLOADER_DATA_SIZE := 1024

# Reserved space for EEPROM emulation
EEPROM_SIZE          := 1024

# Reserved space for metadata (HW ID, CRC)
APP_METADATA_SIZE    := 24


# MDO-1A UF2 family ID
UF2_FAMILY           := 0xCA8A701A
# Hardware ID for firmware compatibility check
BOARD_HWID           := MDO-1A*001
# Device firmware download link
FIRMWARE_URL         := https://github.com/ESS-1/gpsdo-fw-mdo-1a
