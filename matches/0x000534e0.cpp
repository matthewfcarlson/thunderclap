#include "decls/data/game/unknown.h"
// data: gCount_534e0 = DAT_004dc474, gSlot_534e0 = DAT_004dc470

#include "compat/ptr.h"
#include "gen/fight.h"
extern "C" void __cdecl FUN_00047d40();
extern "C" char DAT_003f7938[];
struct Param {
    char pad[24];
};
extern hulk_intptr __cdecl Alloc(unsigned int);
extern void __cdecl Register(void*, void*, int);
extern "C" void FUN_000534e0() {
    if ((*(int*)&DAT_004dc474) == 0) {
        Param* p = (Param*)Alloc(0x18);
        void* out;
        if (p) {
            ((fight::ParamValueBool *)p)->FUN_00234860("interrupt");
            *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7938);
            *(hulk_uintptr*)((char*)p + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_00047d40);
            out = p;
        } else
            out = 0;
        Register(((int*)&DAT_004dc470), &out, 1);
    }
    ++(*(int*)&DAT_004dc474);
}
