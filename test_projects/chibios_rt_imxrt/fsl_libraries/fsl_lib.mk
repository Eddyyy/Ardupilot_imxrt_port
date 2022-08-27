FSLSRC = ./fsl_libraries/clock_config.c \
		   ./fsl_libraries/fsl_clock.c \
		   ./fsl_libraries/fsl_common_arm.c

FSLINC = ./fsl_libraries

FSLASM = 


ALLCSRC += $(FSLSRC)
ALLINC += $(FSLINC)
ALLXASMSRC += $(FSLASM)
