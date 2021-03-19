/**************************************************************************************
* Author: Christina Kidwell
* Course: EGR 226 - 905
* Date: 02/25/2021
* Project: Lab 7 Extra Credit
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
    float x = 6.6;
    float y = 23;
    float c;
    char buff[50];


    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    setupIO();
    SysTickInit();
    LCD_init();

    c = x/y;
    commandWrite((0x80 | 0x00) + 4);    // position cursor to row 1 column 4
    sprintf(buff, "X=%.3f",x);          // load x display message into buffer
    writeLCD(buff);                     // display buffer
    commandWrite((0x80 | 0x40) + 4);    // position cursor to row 2 column 4
    sprintf(buff, "Y=%.3f",y);          // load y display message into buffer
    writeLCD(buff);                     // display buffer
    commandWrite((0x80 | 0x10) + 1);    // position cursor to row 3 column 1
    writeLCD("Division   x/y");         // display text message
    commandWrite((0x80 | 0x50) + 5);    // position cursor to row 4 column 5
    sprintf(buff, "%.3f", c);         // load result display message into buffer
    writeLCD(buff);

    while(1);
 }
