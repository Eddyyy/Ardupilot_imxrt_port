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

## HAL Port Layer
There are a set number of peripheral devices that are to be ported to the HAL. The devices are
external to the ARM core but still implement in silicon on the MCU.
### Resources For implementing drivers
* https://www.playembedded.org/blog/chibioshal-design-an-object-oriented-approach/
* [ChibiOS HAL Documentation](http://chibios.sourceforge.net/docs3/hal/group___h_a_l___n_o_r_m_a_l___d_r_i_v_e_r_s.html)
* Need to create some examples under the testhal folder.
    * Read through existing examples
    * `ChibiOS/testhal`
* Overall template found in `os/hal/templates`
* `/os/hal/board/readme.txt`
* ChibiStudio IDE can help generate board.\* files

### HAL config files describing MCU
* Templates for config files
    * [ ] os/rt/templates/chconf.h
    * [ ] os/hal/templates/halconf.h
    * [ ] os/hal/templates/mcuconf.h
* LLD Files
    * [ ] os/hal/templates/hal_lld.\*
    * [ ] os/hal/templates/platform.mk
* Startup files
    * [ ] /os/common/startup/ARMCMx/compilers/


### Devices to be ported
* Port Abstraction Layer (PAL)
    * [ ] hal_pal_lld.\*
* TIMER Layer
* EXTI Layer (External interrupts)
* USART Layer
* USB Layer
* ADC Layer
* DAC Layer
* CAN Layer
* I2C Layer
* SPI Layer
* DMA Layer
* SDMMC Layer
* OTG Layer?
* MAC Layer?
* CRYPto Layer (maybe not needed atm)
* WatchDog Timer Layer?

## HAL Board Layer
Small guide on porting to a new board:
http://www.chibios.com/forum/viewtopic.php?t=2655

* Board specific files
    * [ ] os/hal/templates/board.*
