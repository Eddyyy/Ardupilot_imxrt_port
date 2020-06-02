# Toolchain Research

For Teensy 4.0 the steps to load a program onto it using the NXP SDK are outlined in this
[link](https://www.stupid-projects.com/using-nxp-sdk-with-teensy-4-0/).
Note that on Debian the package teensy_loader_cli is not updated to allow for Teensy 4.0 support.
I ended up cloning the repo and compiling it from source. This was very simple as once dependencies
are installed, typing `make` in the repo folder is all that is needed.

https://github.com/PaulStoffregen/teensy_loader_cli


For the eval board, evk_rt1020, the steps are quite similar to those outlined in the above link.
The major difference is that teensy_loader_cli is not availble for 
