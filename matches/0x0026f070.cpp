#include "decls/data/platform/xbox/core.h"
// data: gPlatform = DAT_005283b4, gPlatformRef = DAT_005283c8, gReady = DAT_005283bc

typedef unsigned int uint;
struct Platform {
    virtual ~Platform();
};
extern Platform platformObject;
extern "C" int* FUN_002705f0();
// XAPILIB's XInitDevices through its thunk 0x003eba7c (the XDK table's row 0x003eac33)
extern "C" void __stdcall thunk_FUN_003eac33(int, void*);
extern "C" void FUN_0026f070() {
    (*(Platform**)&DAT_005283b4) = &platformObject;
    (*(Platform***)&DAT_005283c8) = ((Platform**)&DAT_005283b4);
    FUN_002705f0();
    thunk_FUN_003eac33(0, 0);
    (*(unsigned char*)&DAT_005283bc) = 1;
}
