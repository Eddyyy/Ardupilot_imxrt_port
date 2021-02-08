# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/MIMXRT1020_EVK/board/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/MIMXRT1020_EVK/board

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

