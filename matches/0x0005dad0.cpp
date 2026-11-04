#include "gen/owners.h"
extern "C" void __cdecl FUN_00267760(void* p, int n, const char* fmt, ...);


char owners::C_5dad0::FUN_0005dad0(int x) {
    char r = 1;
    void* q = (char*)this + 0x78;
    FUN_00267760(q, 0x40, "%s", x);
    return r;
}
