/**************************************************************************************
* Author: Christina Kidwell
* Course: EGR 226 - 905
* Date: 02/25/2021
* Project: Lab 7 Part 3
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

    commandWrite(1); // clear screen
    msDelay(100);
    while(1) {
        commandWrite(2); // clear screen
        msDelay(100);
        writeLCD("LABORATORY OVER                         ");
        commandWrite(0x80 + 16); // position cursor
        shiftInLeft("                LABORATORY OVER ");
    }
}

/****| shiftInLeft | ***********************************************
* Brief: This function will shift in a string of characters
* coming in from the right edge of the display and scrolling
* the display across to the left.
* Characters that scroll off the left edge of line one and appear
* at the right edge of row three are erased.
* Param:
* Data to send to the display
* return:
* N/A
*************************************************************/
void shiftInLeft(char *myString) {
    int i = 0;
    int j = 0;

    while(1) {
        msDelay(1000);              // one second delay
        commandWrite(0x80 + i);     // position cursor to corrected row 1 col 1
        dataWrite(' ');             // clear row 1 col 1
        commandWrite(0x18);         // shift left
        j = i + 16;                 // calculate ram position of row 1 col 17
        if(i>23) j=j-40;            // correct for memory wrap around
        commandWrite(0x80 + j);     // position cursor
        msDelay(1);                 // delay a bit
        dataWrite(myString[i++]);   // output next character just off screen
        msDelay(1);                 // delay a bit

        if(myString[i]==0) break;   // if we've reached the end of the string, exit
    }
}

