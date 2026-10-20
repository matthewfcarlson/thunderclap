#include "compat/ptr.h"
extern "C" char DAT_0041d5f4[];
extern void __cdecl Init(void*, void*);
void __cdecl target(void* a) {
    hulk_intptr v = ((hulk_intptr)DAT_0041d5f4);
    Init(a, &v);
}