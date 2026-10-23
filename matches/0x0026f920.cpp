#include "compat/ptr.h"
typedef unsigned int U_26f920;
U_26f920 __stdcall FUN_002101d4(U_26f920, U_26f920, U_26f920, U_26f920);
U_26f920 __stdcall FUN_0020ff8d(U_26f920, U_26f920, U_26f920, hulk_uintptr, U_26f920);
U_26f920 __stdcall GetLastError();
class XboxDrive {
    char pad[0xb4];

  public:
    U_26f920 mError;
    U_26f920 ConvertError(U_26f920);
    U_26f920 Run(U_26f920, U_26f920, U_26f920, U_26f920, U_26f920, U_26f920, U_26f920*, U_26f920);
};
U_26f920 XboxDrive::Run(U_26f920 p2, U_26f920 p3, U_26f920 p4, U_26f920 p5, U_26f920 p6, U_26f920 p7, U_26f920* p8, U_26f920 unused) {
    U_26f920 r = FUN_002101d4(p2, p5, 0, 0);
    if (r == p5)
        if (FUN_0020ff8d(p2, p6, p7, (hulk_uintptr)p8, 0)) {
            *p8 = p7;
            mError = 0;
            return 1;
        }
    mError = ConvertError(GetLastError());
    return 0;
}