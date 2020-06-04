# Porting The Hardware Abstraction Layer of ChibiOS

Porting the HAL requires implementing the Low Level Drivers (LLD) that are specific to the MCU used.
This means if the HAL is to be pported to both the imxrt1020 and imxrt1060, the port would be
different for each MCU. The saving grace is that the LLD will be quite similar due to similarities
between each MCU.

This is also outlined in the following forum post (which also describes what would be required for
an RT port).
http://www.chibios.com/forum/viewtopic.php?t=4299

This forum post also suggests that there are LLD templates to follow and to follow existing ports
for guidance. The conclusion was to then follow the STM32H7 port for its similar size and features
and to also refer to the LPCxx line of ports for the fact the it was produced by NXP and also has
similar features and internal structure.

![ChibiOS Structure](http://www.chibios.org/dokuwiki/lib/exe/fetch.php?cache=&media=chibios:documentation:books:rt:architecture:architecture.png)

In the linked image, we will be implementing the HAL Port Layer first then the HAL Board Layer.
