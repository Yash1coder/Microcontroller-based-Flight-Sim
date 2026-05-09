/*
 * Switch.c
 *
 *  Created on: January 12, 2026
 *      Author:
 */
#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
// LaunchPad.h defines all the indices into the PINCM table
void Switch_Init(void){
    // PB17 - Left button
    IOMUX->SECCFG.PINCM[PB17INDEX] = 0x00040081; // GPIO input, no pull resistor (external pull-down)

    // PB12 - Right button
    IOMUX->SECCFG.PINCM[PB12INDEX] = 0x00040081; // GPIO input, no pull resistor (external pull-down)

    // Set PB17 and PB12 as inputs (clear output enable bits)
    GPIOB->DOE31_0 &= ~((1<<17)|(1<<12));
}

// Returns: bit 1 = PB17 (left), bit 0 = PB12 (right)
// 0x00 = none, 0x01 = right, 0x02 = left, 0x03 = both
uint32_t Switch_In(void){
    uint32_t pins = GPIOB->DIN31_0;
    uint32_t left  = (pins >> 17) & 1;  // bit 1
    uint32_t right = (pins >> 12) & 1;  // bit 0
    return (left << 1) | right;
}
