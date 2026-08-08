#include "usb_phob_bridge.hpp"
#include "usb_configurations/gcc_to_usb_adapter.hpp"

static PhobUsbReportGetter phobReportGetter = nullptr;

static void updateUsbAdapterReport() {
    PhobUsbReport p{};
    phobReportGetter(&p);

    GCReport g = defaultGcReport;

    g.a = p.a;
    g.b = p.b;
    g.x = p.x;
    g.y = p.y;
    g.start = p.start;

    g.dLeft = p.dLeft;
    g.dRight = p.dRight;
    g.dDown = p.dDown;
    g.dUp = p.dUp;

    g.z = p.z;
    g.r = p.r;
    g.l = p.l;

    g.xStick = p.xStick;
    g.yStick = p.yStick;
    g.cxStick = p.cxStick;
    g.cyStick = p.cyStick;

    g.analogL = p.analogL;
    g.analogR = p.analogR;

    USBConfigurations::GccToUsbAdapter::actuateReportFromGCState(g);
}

void enterPhobUsbMode(PhobUsbReportGetter getter) {
    phobReportGetter = getter;
    USBConfigurations::GccToUsbAdapter::enterMode(updateUsbAdapterReport);
}