DRIVERSSRC = ./libraries/drivers/src/fsl_clock.c \
			 ./libraries/drivers/src/fsl_common.c \
			 ./libraries/drivers/src/fsl_gpio.c \
			 ./libraries/drivers/src/fsl_lpuart.c

DRIVERSINC = ./libraries/drivers/include

DRIVERSASM =

ALLXASMSRC += $(DRIVERSASM)
ALLCSRC    += $(DRIVERSSRC)
ALLINC     += $(DRIVERSINC)
