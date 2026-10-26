#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
// data: gGuard = DAT_004dc4f4, gTable_53d80 = DAT_004dc4f0

extern "C" void __cdecl FUN_00047f80();
extern "C" void __cdecl FUN_00047f90();
extern "C" char DAT_003f7d48[];
extern "C" char DAT_003f7d70[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct ParamEnumConstList {
    int pad[5];
    int field14;
    hulk_intptr field18;
    void Init(const char*);
};
struct ParamIntConstRange {
    int pad[4];
    hulk_intptr field10;
    void Init(const char*);
};
extern void __cdecl Register(void*, void**, int);
void FUN_00053d80() {
    if ((*(int*)&DAT_004dc4f4)) {
        ++(*(int*)&DAT_004dc4f4);
        return;
    }
    void* slots[2];
    ParamEnumConstList* a = (ParamEnumConstList*)Alloc(0x20);
    if (a) {
        int k = (*(int*)&DAT_00427754);
        a->Init("compare");
        a->field14 = k;
        a->pad[0] = ((hulk_intptr)DAT_003f7d48);
        a->pad[4] = ((hulk_intptr)((char*)&DAT_0042773c));
        a->field18 = ((hulk_intptr)(void (__cdecl*)())&FUN_00047f80);
        slots[0] = a;
    } else
        slots[0] = 0;
    ParamIntConstRange* b = (ParamIntConstRange*)Alloc(0x18);
    if (b) {
        b->Init("state");
        b->pad[0] = ((hulk_intptr)DAT_003f7d70);
        b->field10 = ((hulk_intptr)(void (__cdecl*)())&FUN_00047f90);
        slots[1] = b;
    } else
        slots[1] = 0;
    Register(((int*)&DAT_004dc4f0), slots, 2);
    ++(*(int*)&DAT_004dc4f4);
}