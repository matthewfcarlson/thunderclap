#include "compat/ptr.h"
#include "gen/core.h"

typedef unsigned int uint;
extern int __cdecl FUN_0026fd50(hulk_intptr, int);

int core::XboxSaveDrive::vfunc_5(int __p0, int param3) { int * param2 = (int *)__p0;

    hulk_intptr base = param3;
    uint q = (uint)(base + 0x1fef) / 0x1fec;
    int* p = (int*)((char*)base + q * 20 + 4);
    int r = FUN_0026fd50((hulk_intptr)p, 0x4000);
    r += 0x8000;
    if (*param2)
        r += 0x4000;
    return r;
}
