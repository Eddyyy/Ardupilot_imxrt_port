include ./libraries/debug/utilities/utilities.mk

DEBUGSRC = ./libraries/debug/src/generic_list.c \
		   ./libraries/debug/src/lpuart_adapter.c \
		   ./libraries/debug/src/serial_manager.c \
		   ./libraries/debug/src/serial_port_uart.c

DEBUGINC = ./libraries/debug/include

DEBUGASM =

ALLXASMSRC += $(DEBUGASM)
ALLCSRC    += $(DEBUGSRC)
ALLINC     += $(DEBUGINC)

