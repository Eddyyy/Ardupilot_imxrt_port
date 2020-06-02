# Initial Research

The initial research sought to define a structure to the resulting project and to outline the links
between systems required to be implemented. The end goal of this project was to have Ardupilot
running on the MCU. Ardupilot is built on a Hardware Abstraction Layer (HAL) and while it can be
run in a few situations the most common use-case is on an MCU over an RTOS. ChibiOS is the RTOS that
Ardupilot currently uses as it's HAL and further functionality (Note that Ardupilot does have other
HAL's but they are used more for simulation or ease of integration and have a reduced performance.
E.g. SITL and Linux HAL).


![ChibiOS Structure](http://www.chibios.org/dokuwiki/lib/exe/fetch.php?cache=&media=chibios:documentation:books:rt:architecture:architecture.png)
For the Imxrt10xx MCUs', the HAL Board Layer is the portion to be implemented for this project.
The RT Port Layer is specific to MCU core (ARM Cortex M7) and is already implement for that core.
[ChibiOS Structure Description](http://www.chibios.org/dokuwiki/doku.php?id=chibios:documentation:books:rt:architecture)
[ChibiOS Book Documentation](http://www.chibios.org/dokuwiki/doku.php?id=chibios:documentation:books:rt:start)

[Ardupilot on ChibiOS](https://www.youtube.com/watch?v=y2KCB0a3xMg)


