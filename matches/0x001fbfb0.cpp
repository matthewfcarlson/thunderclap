#include "gen/global.h"

typedef unsigned int uint;
extern "C" void __fastcall __security_check_cookie(uint);
extern "C" uint g_cookie_1fbfb0;

void CLocator::vfunc_7(int ) {
    volatile uint t = g_cookie_1fbfb0;
    __security_check_cookie(t);
}
