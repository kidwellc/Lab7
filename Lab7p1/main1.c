/**************************************************************************************
* Author: Christina Kidwell
* Course: EGR 226 - 905
* Date: 02/25/2021
* Project: Lab 7 Part 1
* File: main.c
* Description:
*
**************************************************************************************/
#include "msp.h"
#include <stdio.h>
#include <string.h>
#include "MySetup.h"
#include "MyLCD.h"
#include "MyTimer.h"

void shiftInLeft(char *myString);

/**
 * main.c
 */
 void main(void) {

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    setupIO();
    SysTickInit();
    LCD_init();

    while(1);
}

