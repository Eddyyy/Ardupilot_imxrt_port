BOARDSRC = ./src/board/board.c \
		   ./src/board/clock_config.c \
		   ./src/board/pin_mux.c

BOARDINC = ./src/board

BOARDASM = 


ALLCSRC += $(BOARDSRC)
ALLINC += $(BOARDINC)
ALLXASMSRC += $(BOARDASM)
