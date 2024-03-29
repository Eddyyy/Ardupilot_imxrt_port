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

#include "MIMXRT1021.h"
/*
#define USER_LED_PAD GPIO1_IO05
#define USER_LED_PORT GPIO_AD_B0_05
*/

#define USER_LED_MASK 1<<5
iomuxc_sw_mux_ctl_pad_t user_led_config = kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05;

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

    GPIO1->GDIR |= USER_LED_MASK;

    int i = 0;
    int j = 0;
    while (1) {
        // palToggleLine(PORTAB_LINE_LED1);
        GPIO1->DR_TOGGLE = USER_LED_MASK;

        // chThdSleepMilliseconds(500);
        i = 0;
        while (i < 500) {
            // Delay 1 ms
            j = 0;
            while (j < 50000) {
                j++;
            }
            i++;
        }
        i++;
    }
}
