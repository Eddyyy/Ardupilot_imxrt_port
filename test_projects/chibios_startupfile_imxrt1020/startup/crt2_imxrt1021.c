
void __core_init(void) {

#if CORTEX_MODEL == 7
    SCB_EnableICache();
    SCB_EnableDCache();
#endif

    // Need to add 
}


