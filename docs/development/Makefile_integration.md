# Makefile Integration
This documentation outlines the process to port the NXP SDK to ChibiOS' Makefile build system.
The information could also be used for any other build system based on the gcc compiler.

## Build Global Options
### USE_OPT
* `-g` Used to inform the compiler to place debugging symbols in the compiled binary. 
Documentation can be found at: [Debugging Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)
* `-O0` Used to set the amount of optimization done (0 sets no optimization). The following
describes further: [Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options)
* `-ffreestanding` Used to allow for custom bootloaders and custom libraries to be used. Informs the
compiler to not use the standard libraries. Could probably be placed under C specific options. 
More info found at: [C Options](https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html#C-Dialect-Options)
* `-std=gnu99` Is also C specific option that defines the expected standed for C to be compiled with.
The C specific functions have been added here to begin with to closely imitate the NXP SDK compiling
behaviour. More info also found at: [C Options](https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html#C-Dialect-Options)
* `-mapcs-frame` Is a specific ARM option to specify the stack used for function calls. According to
gcc options documentation this option is deprecated but the NXP SDK still uses this functionality.
More info found at: [ARM Options](https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html)

### USE_LINK_GC = yes
This adds `-ffunction-sections -fdata-sections -fno-common` options to compiling c code and adds
`--gc-sections` option to linking code. This was selected to imitate the NXP SDK options.

`-ffunction-sections -fdata-sections` Control how the compiled code is laid out and improves linking
optimizations.

`-fno-common` TODO, Currently provided as part of rules.mk and is default gcc behaviour.

`--gc-sections` Will garbage collect unused portions of code and data, minimizing binary size.

#### Relavent Documentation
* [`-ffunction-sections` and ` -fdata-sections`](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options)
* [-fno-common](https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html)
* [--gc-sections](https://linux.die.net/man/1/arm-linux-gnu-ld)

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
