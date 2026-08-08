#pragma once
#include <stdint.h>

struct PhobUsbReport {
    uint8_t a, b, x, y, start;
    uint8_t dLeft, dRight, dDown, dUp;
    uint8_t z, r, l;
    uint8_t xStick, yStick;
    uint8_t cxStick, cyStick;
    uint8_t analogL, analogR;
};

using PhobUsbReportGetter = void (*)(PhobUsbReport*);

void enterPhobUsbMode(PhobUsbReportGetter getter);