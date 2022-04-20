XIPSRC = ./libraries/xip/src/evkmimxrt1020_flexspi_nor_config.c \
		 ./libraries/xip/src/fsl_flexspi_nor_boot.c

XIPINC = ./libraries/xip/include

XIPASM =

ALLXASMSRC += $(XIPASM)
ALLCSRC    += $(XIPSRC)
ALLINC     += $(XIPINC)
