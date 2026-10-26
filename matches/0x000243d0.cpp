#include "decls/data/game/global.h"
// data: zeroValue_243d0 = DAT_003f335c

struct Obj_243d0 {
    char pad[0x124];
    void* member;
    void* go();
};
void* __fastcall FUN_000243d0(Obj_243d0* self) {
    Obj_243d0* p = (Obj_243d0*)self->member;
    if (!p)
        return ((char*)&DAT_003f335c);
    return p->go();
}