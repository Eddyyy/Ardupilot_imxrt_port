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

### Update:
Some further research was and through testing it was found that the aformentioned guide does not work
with the firmware loaded onto the on-board debugger. The NXP ide, MCUxpresso, worked perfectly is
a decent debugger for the given sdk. Unfortunately while the ide works great when using the given 
sdk it takes a large setup for anything external. This lead to the tool
[pyOCD](https://github.com/mbedmicro/pyOCD) which provides the GDB remote server replacing the
JLink server in the NXP guide.
### Further pyOCD resources
* [Debugging with pyOCD](https://os.mbed.com/users/maclobdell/notebook/debugging-with-pyocd/)

The resulting toolchain uses the ARM gcc toolchain to compile the code and a combination of the gdb
program in ARM gcc and jlink gdb server. (installed with `sudo apt install jlink`)
Running the following should compile and load onto a imxrt1020 eval board.
```
cd /path/to/sdk/hello_world/armgcc
sudo chmod 744 build_flexspi_nor_debug.sh
ARMGCC_DIR=/path/to/gcc-arm-none-eabi-9-2019-q4-major/ ./build_flexspi_nor_debug.sh
```

Connect the board and in another terminal type:
```
pyocd gdbserver
```

In the original terminal type:
```
cd flexspi_nor_debug
/path/to/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gdb
(gdb) target remote localhost: 3333
(gdb) file hello_world.elf
(gdb) break main
(gdb) continue
```


# Potiential Other Resources
https://www.playembedded.org/blog/tag/openocd/

## CMake Fixes
It was also found that the `arm.gcc` cmake file being used gave depreciated warnings. It was using
CMAKE_FORCE_C_COMPILER functions rather than directing cmake to find the compiler with
SET CMAKE_C_COMPILER commands. This was changed but due to resons outlined in this
[stack overflow post](https://stackoverflow.com/questions/53633705/cmake-the-c-compiler-is-not-able-to-compile-a-simple-test-program),
the line `set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")` was also added.
In short cmake trys to check the compiler but since we use a custom linking script for imxrt chips,
it fails when running on a generic environment.
