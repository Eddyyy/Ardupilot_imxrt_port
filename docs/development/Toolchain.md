# Toolchain Research

For Teensy 4.0 the steps to load a program onto it using the NXP SDK are outlined in this
[link](https://www.stupid-projects.com/using-nxp-sdk-with-teensy-4-0/).
Note that on Debian the package teensy_loader_cli is not updated to allow for Teensy 4.0 support.
I ended up cloning the repo and compiling it from source. This was very simple as once dependencies
are installed, typing `make` in the repo folder is all that is needed.

https://github.com/PaulStoffregen/teensy_loader_cli


For the eval board, evk_rt1020, the steps are quite similar to those outlined in the above blog post.
The major difference is that teensy_loader_cli is not available for the IMXRT Boards. To replace
this we use something derived from the NXP Page
[Get Started with the MIMXRT1020-EVK](https://www.nxp.com/document/guide/get-started-with-the-mimxrt1020-evk:GS-MIMXRT1020-EVK).

The resulting toolchain uses the ARM gcc toolchain to compile the code and a combination of the gdb
program in ARM gcc and jlink gdb server. (installed with `sudo apt install jlink`)
Running the following should compile and load onto a imxrt1020 eval board.
```
cd /path/to/sdk/hello_world/armgcc
sudo chmod 744 build_flexspi_nor_debug.sh
ARMGCC_DIR=/path/to/gcc-arm-none-eabi-9-2019-q4-major/ ./build_flexspi_nor_debug.sh
```
After some small testing it was also found that `/path/to/gcc-arm-none-eabi-9-2019-q4-major/` needed
to be absolute rather than relative.

Connect the board and in another terminal type:
```
cd /path/to/sdk/hello_world
JLinkGDBServer evkmimxrt1020_sdram_init.jlinkscript
```

In the original terminal type:
```
cd flexspi_nor_debug
/path/to/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gdb hello_world.elf
```


