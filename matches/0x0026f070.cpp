#include "decls/data/platform/xbox/core.h"
// data: gPlatform = DAT_005283b4, gPlatformRef = DAT_005283c8, gReady = DAT_005283bc

typedef unsigned int uint;
struct Platform {
    virtual ~Platform();
};
extern Platform platformObject;
extern void InitPlatform();
namespace XAPILIB {
extern void __stdcall XInitDevices(int, int);
}
void Target() {
    (*(Platform**)&DAT_005283b4) = &platformObject;
    (*(Platform***)&DAT_005283c8) = ((Platform**)&DAT_005283b4);
    InitPlatform();
    XAPILIB::XInitDevices(0, 0);
    (*(unsigned char*)&DAT_005283bc) = 1;
}