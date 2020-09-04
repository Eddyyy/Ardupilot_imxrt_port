# Makefile Integration
This documentation outlines the process to port the NXP SDK to ChibiOS' Makefile build system.
The information could also be used for any other build system based on the gcc compiler.

## Build Global Options
### USE_OPT
* "`-g`" Used to inform the compiler to place debugging symbols in the compiled binary. 
Documentation can be found at: [debugging options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)
* "`-O0`" Used to set the amount of optimization done (0 sets no optimization). The following
describes further: [Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options)

### USE_LINK_GC = yes

### USE_LDOPT

### USE_LTO

### USE_THUMB

### USE_VERBOSE_COMPILE

## Architecture Specific Options
### Process and Exception Stacksize
0x400

### USE_FPU and USE_FPU_OPT

## Projects, Sources and Paths
### Project name and temp folders

### Included Makefiles

### Source definitions and linker script

## Compiler Settings
### MCU definition

### Toolchain definition

### Compiler options

## User Defines
### C defines

### Assembly Defines

## Final Notes
### changes to rules.mk
Had to remove the `-nostartfiles` option as the NXP SDK does not implement a crt0.s or crt1.c as the
ChibiOS system does. This will something that will need to be fixed later to fully integrate with 
the ChibiOS system. Potiential fixes would require some way to cancel the `-nostartfiles` option
or substitue a different rules.mk file or implment/modify the ChibiOS startup files.
