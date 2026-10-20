#include "compat/ptr.h"
extern "C" void __cdecl FUN_00047d40();
extern "C" char DAT_003f7938[];
struct Param {
    void Initialize(const char*);
    char pad[24];
};
extern hulk_intptr __cdecl Alloc(unsigned int);
extern void __cdecl Register(void*, void*, int);
extern int gCount_534e0;
extern int gSlot_534e0;
void FUN_000534e0() {
    if (gCount_534e0 == 0) {
        Param* p = (Param*)Alloc(0x18);
        void* out;
        if (p) {
            p->Initialize("interrupt");
            *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7938);
            *(hulk_uintptr*)((char*)p + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_00047d40);
            out = p;
        } else
            out = 0;
        Register(&gSlot_534e0, &out, 1);
    }
    ++gCount_534e0;
}
