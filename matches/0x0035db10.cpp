#include "compat/ptr.h"
extern "C" char hulk_at_00400488[];
extern "C" unsigned __int64 Hash(const char*);
extern unsigned int gHashLow;
extern unsigned int gHashHigh;
void FUN_0035db10() {
    unsigned __int64 h = Hash((const char*)((hulk_intptr)hulk_at_00400488));
    gHashLow = (unsigned int)h;
    gHashHigh = (unsigned int)(h >> 32);
}
