#include "compat/ptr.h"
#include "decls/data/records.h"
typedef unsigned int U_26f920;
U_26f920 __stdcall FUN_002101d4(U_26f920, U_26f920, U_26f920, U_26f920);
U_26f920 __stdcall FUN_0020ff8d(U_26f920, void*, U_26f920, hulk_uintptr, U_26f920);
U_26f920 __stdcall GetLastError();
// core::XboxDrive::vfunc_12 (records.h CoreXboxDrive): seeks the handle (p2) to p5 and reads p7 bytes into the buffer
// p6 (a pointer on every target); 0x0026f3e0 converts the XAPI error into the drive's
class XboxDrive_26f920 : public CoreXboxDrive {
  public:
    U_26f920 FUN_0026f3e0(U_26f920);
    U_26f920 Run(U_26f920, U_26f920, U_26f920, U_26f920, void*, U_26f920, U_26f920*, U_26f920);
};
U_26f920 XboxDrive_26f920::Run(U_26f920 p2, U_26f920 p3, U_26f920 p4, U_26f920 p5, void* p6, U_26f920 p7, U_26f920* p8, U_26f920 unused) {
    U_26f920 r = FUN_002101d4(p2, p5, 0, 0);
    if (r == p5)
        if (FUN_0020ff8d(p2, p6, p7, (hulk_uintptr)p8, 0)) {
            *p8 = p7;
            drive.error = 0;
            return 1;
        }
    drive.error = FUN_0026f3e0(GetLastError());
    return 0;
}
