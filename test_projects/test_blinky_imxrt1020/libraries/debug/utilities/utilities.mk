UTILITIESSRC = ./libraries/debug/utilities/fsl_assert.c \
			   ./libraries/debug/utilities/fsl_debug_console.c \
			   ./libraries/debug/utilities/fsl_sbrk.c \
			   ./libraries/debug/utilities/fsl_str.c

UTILITIESINC = ./libraries/debug/utilities

UTILITIESASM =

ALLXASMSRC += $(UTILITIESASM)
ALLCSRC    += $(UTILITIESSRC)
ALLINC     += $(UTILITIESINC)
