#include "compat/ptr.h"
extern "C" char DAT_00433568[];
extern "C" char DAT_0043359c[];
typedef unsigned int u32_327930;
extern u32_327930 g_327930;
extern void __fastcall finish(void*);
void __fastcall target(u32_327930* self) {
    *self = ((hulk_intptr)DAT_0043359c);
    if (g_327930 == (hulk_uintptr)self)
        g_327930 = 0;
    *self = ((hulk_intptr)DAT_00433568);
    finish((void*)(self));
}
