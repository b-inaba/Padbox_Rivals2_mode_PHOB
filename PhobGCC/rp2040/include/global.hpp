#ifndef __GLOBAL_HPP
#define __GLOBAL_HPP

#include <stdint.h>

const int us = 125;

// These aren't used by our Phob integration,
// but pico-rectangle's USB code expects them.
#define LED_PIN 25
#define USB_POWER_PIN 24
const uint8_t gcDataPin = 28;

// IMPORTANT:
// pico-rectangle normally uses GPIO 11 for rumble,
// but GPIO 11 is Y on the Padbox.
// Use unused GPIO 25 as a harmless dummy instead.
const uint8_t rumblePin = 25;

#define USE_UART0 0

#endif