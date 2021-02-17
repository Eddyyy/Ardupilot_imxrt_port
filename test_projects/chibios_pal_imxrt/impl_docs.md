# IMX RT PAL implementation Documentation

# Call structure and todo list

THD_WORKING_AREA
    PORT_WORKING_AREA

THD_FUNCTION
    PORT_THD_FUNCTION

NORMALPRIO

chRegSetThreadName
chThdSleepMilliseconds
    chThdSleep
        chSchGoSleepTimeoutS
            and so on

chSysInit
    _scheduler_init
    _vt_init
    _trace_init
    _oslib_init
    _tm_init
    _stats_init
    _thread_init
    port_init
    chTMStartMeasurementX
    CH_CFG_SYSTEM_INIT_HOOK
    chSysEnable
    THD_WORKING_AREA_BASE
    THD_WORKING_AREA_END
    chThdCreate

chThdCreateStatic
    MEM_IS_ALIGNED
    PORT_WORKING_AREA_ALIGN
    THD_WORKING_AREA_SIZE
    PORT_STACK_ALIGN
    HIGHPRIO
    chRegFindThreadByWorkingArea
    chSysLock
    PORT_SETUP_CONTEXT
    _thread_init
    chSchWakeupS
    chSysUnlock

halInit
    osalInit
    hal_lld_init
    palInit
        pal_lld_init
    sdInit
    uartInit
    sduInit
    boardInit

palReadLine
    palReadPad(PAL_PORT(line), PAL_PAD(line))
or
    pal_lld_readline

palToggleLine
    palTogglePad(PAL_PORT(line), PAL_PAD(line))
or
    pal_lld_toggleline

PORTAB_LINE_BUTTON
    LINE_BUTTON_USER -> from portab.h

PORTAB_BUTTON_PRESSED
    PAL_HIGH -> from portab.h

PORTAB_LINE_LED1
    LINE_ARD_D13 -> from portab.h
        PAL_LINE(GPIOA, 12U) -> from board.h

PORTAB_LINE_LED2
    LINE_LED4

PAL_USE_WAIT -> TRUE
PAL_USE_CALLBACKS -> TRUE
