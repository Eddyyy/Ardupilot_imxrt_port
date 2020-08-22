##############################################################################
# Build global options
# NOTE: Can be overridden externally.
#

# Compiler options here.
ifeq ($(USE_OPT),)
  USE_OPT = \
    -g \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -std=gnu99
endif

# C specific options here (added to USE_OPT).
ifeq ($(USE_COPT),)
  USE_COPT = 
endif

# C++ specific options here (added to USE_OPT).
ifeq ($(USE_CPPOPT),)
  USE_CPPOPT =
endif

# Enable this if you want the linker to remove unused code and data
ifeq ($(USE_LINK_GC),)
  USE_LINK_GC = yes
endif

# Linker extra options here.
ifeq ($(USE_LDOPT),)
  USE_LDOPT = \
    --specs=nano.specs \
    --specs=nosys.specs \
    -Wl, -static \
    -Wl, -z,muldefs \
	-Wl, --start-group \
	-lm \
	-lc \
	-lgcc \
	-lnosys \
	-Wl,--end-group
endif


# Enable this if you want link time optimizations (LTO)
# no = -O0
ifeq ($(USE_LTO),)
  USE_LTO = no
endif

# If enabled, this option allows to compile the application in THUMB mode.
# -mthumb
ifeq ($(USE_THUMB),)
  USE_THUMB = yes
endif

# Enable this if you want to see the full log while compiling.
ifeq ($(USE_VERBOSE_COMPILE),)
  USE_VERBOSE_COMPILE = yes
endif

#
# Build global options
##############################################################################

##############################################################################
# Architecture or project specific options
#

# Stack size to be allocated to the Cortex-M process stack. This stack is
# the stack used by the main() thread.
ifeq ($(USE_PROCESS_STACKSIZE),)
  USE_PROCESS_STACKSIZE = 0x400
endif

# Stack size to the allocated to the Cortex-M main/exceptions stack. This
# stack is used for processing interrupts and exceptions.
ifeq ($(USE_EXCEPTIONS_STACKSIZE),)
  USE_EXCEPTIONS_STACKSIZE = 0x400
endif

# Enables the use of FPU (no, softfp, hard).
ifeq ($(USE_FPU),)
  USE_FPU = hard
endif

# FPU-related options.
ifeq ($(USE_FPU_OPT),)
  USE_FPU_OPT = -mfloat-abi=$(USE_FPU) -mfpu=fpv5-d16
endif

#
# Architecture or project specific options
##############################################################################

##############################################################################
# Project, sources and paths
#

# Define project name here
PROJECT = test_blinky

# Imported source files and paths
CONFDIR  := ./src/board
BUILDDIR := ./build
DEPDIR   := ./dep

# Startup files.
STARTUPLD = ./startup
include $(STARTUPLD)/startup_MIMXRT1021.mk
# Library files
include ./library/xip/xip.mk
include ./library/drivers/drivers.mk
include ./library/debug/debug.mk
# MCU Files
include ./src/board/board.mk
include ./src/device/device.mk
# CMSIS h files
ALLINC += ./include/CMSIS

# Initializsing assembly file
ALLASMSRC += ./startup/*.S

# Define linker script file here
LDSCRIPT= $(STARTUPLD)/*.ld

# C sources that can be compiled in ARM or THUMB mode depending on the global
# setting.
CSRC = $(ALLCSRC) \
       $(TESTSRC) \
       $(CONFDIR)/* \
       ./src/gpio_led_output.c

# C++ sources that can be compiled in ARM or THUMB mode depending on the global
# setting.
CPPSRC = $(ALLCPPSRC)

# List ASM source files here
ASMSRC = $(ALLASMSRC)
ASMXSRC = $(ALLXASMSRC)

INCDIR = $(ALLINC) $(TESTINC) $(CONFDIR)

#
# Project, sources and paths
##############################################################################

##############################################################################
# Compiler settings
#

# -mcpu=
MCU  = cortex-m7

#TRGT = arm-elf-
TRGT = arm-none-eabi-
CC   = $(TRGT)gcc
CPPC = $(TRGT)g++
# Enable loading with g++ only if you need C++ runtime support.
# NOTE: You can use C++ even without C++ support if you are careful. C++
#       runtime support makes code size explode.
LD   = $(TRGT)gcc
#LD   = $(TRGT)g++
CP   = $(TRGT)objcopy
AS   = $(TRGT)gcc -x assembler-with-cpp
AR   = $(TRGT)ar
OD   = $(TRGT)objdump
SZ   = $(TRGT)size
HEX  = $(CP) -O ihex
BIN  = $(CP) -O binary

# ARM-specific options here
AOPT =

# THUMB-specific options here
TOPT = -DTHUMB

# Define C warning options here
CWARN = -Wall -Wextra -Wundef -Wstrict-prototypes

# Define C++ warning options here
CPPWARN = -Wall -Wextra -Wundef

#
# Compiler settings
##############################################################################

##############################################################################
# Start of user section
#

# List all user C define here, like -D_DEBUG=1
UDEFS = \
    -DXIP_EXTERNAL_FLASH=1 \
    -DXIP_BOOT_HEADER_ENABLE=1 \
    -DDEBUG \
    -DCPU_MIMXRT1021DAG5A \
    -DSERIAL_PORT_TYPE_UART=1


# Define ASM defines here
UADEFS = \
    -D__STARTUP_CLEAR_BSS \
    -DDEBUG \
    -D__STARTUP_INITIALIZE_NONCACHEDATA


# List all user directories here
UINCDIR =

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS =

#
# End of user defines
##############################################################################

RULESPATH = $(BUILDDIR)
include $(RULESPATH)/rules.mk
