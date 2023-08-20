# Build Options
#   change yes to no to disable.
#
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = embedded_flash

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# custom matrix setup
CUSTOM_MATRIX = lite


#VPATH += keyboards/keychron/common
#SRC += matrix.c

TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
