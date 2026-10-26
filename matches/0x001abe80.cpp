#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/data/game/hulkfight/scenario.h"
// data: gCount_1abe80 = DAT_004e178c, gSlot_1abe80 = DAT_004e1788, name_1abe80 = DAT_003f8778

extern "C" void __cdecl FUN_001aacf0();
extern "C" char DAT_0041d4ac[];
extern void* Alloc(hulk_uintptr);
struct Obj_1abe80 {
    hulk_intptr v;
    char pad4[12];
    hulk_intptr a;
    int b;
    hulk_intptr c;
    void Init(const char*);
};
extern void Register(int*, Obj_1abe80**, int);
void FUN_001abe80() {
    if ((*(int*)&DAT_004e178c) == 0) {
        Obj_1abe80* p;
        Obj_1abe80* q = (Obj_1abe80*)Alloc(0x20);
        if (q != 0) {
            q->Init(DAT_003f8778);
            q->v = ((hulk_intptr)DAT_0041d4ac);
            q->a = ((hulk_intptr)((char*)&DAT_004c2a28));
            q->b = 0x1f;
            q->c = ((hulk_intptr)(void (__cdecl*)())&FUN_001aacf0);
            p = q;
        } else {
            p = 0;
        }
        Register(((int*)&DAT_004e1788), &p, 1);
    }
    ++(*(int*)&DAT_004e178c);
}
