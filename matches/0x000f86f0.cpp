#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* FUN_0008d6d0(hulk_uintptr n);


void owners::Obj_f86f0::FUN_000f86f0(int a, hulk_intptr b) {
    m4 = ((int)b) * 2;
    m0 = (char*)FUN_0008d6d0((unsigned)(m4 >> 1) * 2);
    m10 = a;
    mC = (int*)FUN_0008d6d0(a * 4);
    unsigned v = m10;
    unsigned n = (v + 0x1f) >> 5;
    unsigned* p = (unsigned*)FUN_0008d6d0(n * 4 + 4);
    *p = v;
    if (n > 0) {
        unsigned* q = p + 1;
        for (unsigned i = n; i != 0; i--)
            *q++ = 0;
    }
    m11c = p;
    unsigned k = (*p + 0x1f) >> 5;
    if (k > 0) {
        unsigned* q = p + 1;
        for (; k != 0; k--)
            *q++ = 0;
    }
    m1c = a;
    m18 = FUN_0008d6d0(a * 8);
    m110 = 1;
}
