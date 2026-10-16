// Same code shape as 0x001fbfb0 (propagated; names are from that function)
#include "gen/global.h"

typedef unsigned int uint;
extern "C" void __fastcall __security_check_cookie(uint);
extern "C" uint g_cookie_1fc460;

void CTriggerVolume::vfunc_7(int ) {
    volatile uint t = g_cookie_1fc460;
    __security_check_cookie(t);
}
