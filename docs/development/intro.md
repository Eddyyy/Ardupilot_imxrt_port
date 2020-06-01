#Introduction
These are my initial thoughts starting the project. I had a very basic idea of what I wanted to do
but didn't have any specific intentions behind it other than to learn. As we will see later that
changed.

##Requirements (sort of)

###Need to have
1. Chip to run the control algorithms
2. IO to actuators and propulsion
3. IMU or IMU port
4. Telemetry IO
5. Sensor IO

###Extra
1. Potential power supply
2. CC or Accelerator connection (PCIE or usb or serial or something)
3. IO Processor or FPGA

##Context
First researching was done based on the type of processors that are being used in flight controllers
 and the new ones being developed today. One of the big things I was looking for was a chip that
may be able to provide something not currently available in Ardupilot based drones built now. I had
also been working on a brushed DC motor speed controller which had lead me through the stm32
ecosystem.  One thing I had felt it was missing was a high speed processing MCU. I hadn't looked
into the STM32H7 family now being developed into the Cube Orange flight controller and the MatekH7
flight controller.

[Cube Orange H7 Product page](http://www.proficnc.com/all-products/188-the-cube.html)

Something that had recently come into my mind was the Teensy 4.0 which had a clock speed of
600 MHz which was far faster than any of the F4s and F7s of the STM32 family. I had also spoken to 
friends who were amazed and very impressed by this new MCU. I was also surprised at the tiny size
the Teensy from work with the 3.2 version in earlier projects. Finally I recently found further
support and praise for a similar processor in a forum that I follow. All this lead me to look into
the
[IMXRT](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/i-mx-rt-crossover-mcus:IMX-RT-SERIES)
line of processors by NXP.


