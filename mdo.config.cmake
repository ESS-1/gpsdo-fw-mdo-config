# Load and parse shared build constants from 'mdo.config.mk'
set(CONFIG_MK_FILE "${CMAKE_CURRENT_SOURCE_DIR}/mdo.config.mk")

# Check if configuration file exists
if(NOT EXISTS "${CONFIG_MK_FILE}")
    message(FATAL_ERROR "Configuration file not found: ${CONFIG_MK_FILE}")
endif()

file(STRINGS "${CONFIG_MK_FILE}" CONFIG_MK_LINES)

foreach(line IN LISTS CONFIG_MK_LINES)
    # Skip empty lines and full-line comments
    if(line MATCHES "^\\s*#" OR line MATCHES "^\\s*$")
        continue()
    endif()

    # Parse KEY = VALUE or KEY := VALUE
    if(NOT line MATCHES "^\\s*([A-Za-z_][A-Za-z0-9_]*)\\s*:?=\\s*(.*)$")
        message(FATAL_ERROR "Unsupported syntax in ${CONFIG_MK_FILE}: '${line}'")
    endif()

    set(key "${CMAKE_MATCH_1}")
    set(val "${CMAKE_MATCH_2}")

    # Strip inline comments, unless '#' is escaped as '\#'
    string(REGEX REPLACE "(^|[^\\\\])#.*" "\\1" val "${val}")

    # Unescape '\#' -> '#'
    string(REPLACE "\\#" "#" val "${val}")

    # Trim whitespace
    string(STRIP "${val}" val)

    set(${key} "${val}")
endforeach()

# Track file changes to re-trigger CMake configuration automatically
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${CONFIG_MK_FILE}")
