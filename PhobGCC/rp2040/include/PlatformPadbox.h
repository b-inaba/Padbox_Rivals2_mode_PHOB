#ifndef BOARD_H
#define BOARD_H

#ifndef CLEANADC
#define CLEANADC
#endif //CLEANADC

//This is for the Arkodd Platform Padbox GS

//defining which pin is what
//GPIO
const int _pinA  = 15; //TODO: not working
const int _pinB  = 6;  //K1, bottom row 1
const int _pinL  = 22; //L3, left (only) trigger
const int _pinR  = 10; //P1, top row 1
const int _pinX  = 7;  //K2, bottom row 2 TODO: NOT WORKING
const int _pinY  = 11; //P2, top row 2
const int _pinZ  = 8; //K3, bottom row 3 TODO: NOT WORKING
const int _pinS  = 17; //working
const int _pinRumble = -1;
const int _pinBrake  = -1;
const int _pinTX  = 23; //working
//20 is actually the third menu button
//9 is dpad left
//7 was dpad left, now it does nothing?

//Analog trigger values
#ifndef B0XXRIGHT
#define B0XXRIGHT
#endif //B0XXRIGHT
const int _pinLS = 12; //P3, top row 3 //TODO: NOT WORKING
const int _pinMS = 13; //P4, top row 4 //working
const int _pinUP = 9;  //K4, bottom row 4 (unused by default) //TODO: dunno, was 9 which is actually dpad left

//Permanent d-pad
#ifndef DPAD
#define DPAD
#endif //DPAD
const int _pinDr = 4;
const int _pinDu = 2;
const int _pinDl = 5;
const int _pinDd = 3;

//Digital C-button inputs
#ifndef CBUTTONS
#define CBUTTONS
#endif //CBUTTONS
const int _pinCr = 19;
const int _pinCu = 27;
const int _pinCl = 26;
const int _pinCd = 18;

#ifndef ASTICK_RP_ADC
#define ASTICK_RP_ADC
#endif //ASTICK_RP_ADC
const int _pinAx = 29;
const int _pinAxADC = 3;
const int _pinAy = 28;
const int _pinAyADC = 2;
const int _pinCx = -1;
const int _pinCxADC = -1;
const int _pinCy = -1;
const int _pinCyADC = -1;
const int _pinRX = -1;

#include "debug.h"
#include "readHardware.h"

#endif //BOARD_H
