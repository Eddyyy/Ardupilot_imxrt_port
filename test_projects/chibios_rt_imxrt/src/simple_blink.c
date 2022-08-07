/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
// #include "hal.h"
#include "portab.h"

#include "MIMXRT1021.h"

#if !defined(SYSTEM_CLOCK)
#define SYSTEM_CLOCK 8000000U
#endif

/*
 * @brief   System Timer handler.
 */
CH_IRQ_HANDLER(SysTick_Handler) {

  CH_IRQ_PROLOGUE();

  chSysLockFromISR();
  chSysTimerHandlerI();
  chSysUnlockFromISR();

  CH_IRQ_EPILOGUE();
}
static uint32_t seconds_counter;
//static uint32_t minutes_counter;

/*
 * Seconds counter thread.
 */
static THD_WORKING_AREA(counter_thd_wa, 128);
static THD_FUNCTION(counter_thd, arg) {

  (void)arg;

  chRegSetThreadName("counter");

  while (true) {
    chThdSleepMilliseconds(1000);
    seconds_counter++;
  }
}

/*
#define USER_LED_PAD GPIO1_IO05
#define USER_LED_PORT GPIO_AD_B0_05
*/

#define USER_LED_MASK 1<<5
iomuxc_sw_mux_ctl_pad_t user_led_config = kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05;

static THD_WORKING_AREA(blinker_thd_wa, 128);
static THD_FUNCTION(blinker_thd, arg) {
    (void)arg;
    chRegSetThreadName("blinker");

    while (true) {
        // palToggleLine(PORTAB_LINE_LED1);
        GPIO1->DR_TOGGLE = USER_LED_MASK;

        chThdSleepMilliseconds(500);
    }
}

int main(void) {

    //gpio1_clk_enable = 1;
    CCM->CCGR1 |= CCM_CCGR1_CG13(0b11);

    // GPIO1_IO5 pad config register
    // SW_MUX_CTL_PAD_GPIO_AD_B0_05
    // IOMUXC->SW_PAD_CTL_PAD[
    //     iomux_sw_pad_ctl_pad_t->kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_05
    // ] 

    // GPIO1_IO05 MUX config register
    //IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05 = 0b101; //ALT5
    IOMUXC->SW_MUX_CTL_PAD[user_led_config] = 0b101; // ALT5, select GPIO peripheral

    // Set GPIO1_IO05 to output
    GPIO1->GDIR |= USER_LED_MASK;

    /*
     * Hardware initialization, in this simple demo just the systick timer is
     * initialized.
     */
    SysTick->LOAD = SYSTEM_CLOCK / CH_CFG_ST_FREQUENCY - (systime_t)1;
    SysTick->VAL = (uint32_t)0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk |
                    SysTick_CTRL_TICKINT_Msk;

    /* IRQ enabled.*/
    NVIC_SetPriority(SysTick_IRQn, 8);

    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *   and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *   RTOS is active.
     */
    // halInit();
    chSysInit();

    chThdCreateStatic(blinker_thd_wa, sizeof(blinker_thd_wa), NORMALPRIO+1, blinker_thd, NULL);
    chThdCreateStatic(counter_thd_wa, sizeof(counter_thd_wa), NORMALPRIO+2, counter_thd, NULL);

    while (true) {
        // palToggleLine(PORTAB_LINE_LED1);
        // GPIO1->DR_TOGGLE = USER_LED_MASK;

        chThdSleepMilliseconds(60);
    }
}
