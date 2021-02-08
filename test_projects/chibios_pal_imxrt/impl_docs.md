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
    chSysLock
    PORT_SETUP_CONTEXT
    _thread_init
    chSchWakeupS
    chSysUnlock

halInit

palReadLine
palToggleLine

PORTAB_LINE_BUTTON
PORTAB_BUTTON_PRESSED
PORTAB_LINE_LED1
PORTAB_LINE_LED2

PAL_USE_WAIT
PAL_USE_CALLBACKS
