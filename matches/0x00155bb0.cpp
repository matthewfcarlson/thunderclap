#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
// data: gCount_155bb0 = DAT_004e10c4, gSlot_155bb0 = DAT_004e10c0, gValue_155bb0 = DAT_00427754

extern "C" void __cdecl FUN_0014c730();
extern "C" char DAT_00414ad0[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Param {
  public:
    void Init(const char*);
    char pad[0x20];
};
extern "C" void __cdecl Register(void*, void**, int);
void FUN_00155bb0() {
    if ((*(int*)&DAT_004e10c4)) {
        ++(*(int*)&DAT_004e10c4);
        return;
    }
    void* tmp;
    Param* p = (Param*)Alloc(0x20);
    if (p) {
        int v = (*(int*)&DAT_00427754);
        p->Init("compare");
        *(int*)((char*)p + 0x14) = v;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414ad0);
        *(hulk_intptr*)((char*)p + 0x10) = ((hulk_intptr)((char*)&DAT_0042773c));
        *(hulk_intptr*)((char*)p + 0x18) = ((hulk_intptr)(void (__cdecl*)())&FUN_0014c730);
        tmp = p;
    } else
        tmp = 0;
    Register(((void**)&DAT_004e10c0), &tmp, 1);
    ++(*(int*)&DAT_004e10c4);
}