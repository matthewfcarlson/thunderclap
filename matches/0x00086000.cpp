#include "decls/data/game/global.h"

extern "C" unsigned __int64 __cdecl FUN_00267f40();
struct Bits {
    unsigned lo;
    unsigned hi;
};
union U {
    unsigned __int64 n;
    Bits b;
};
extern "C" long double __cdecl FUN_00086000() {
    U x;
    x.n = FUN_00267f40();
    unsigned high = x.b.hi;
    x.b.hi = high & 0x7fffffff;
    long double a = (__int64)x.n;
    x.b.hi = high & 0x80000000;
    x.b.lo = 0;
    long double b = (__int64)x.n;
    b = -b;
    return (b + a) * DAT_003ffaa4;
}