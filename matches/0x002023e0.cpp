#include "decls/data/engine/unknown.h"
// data: global64 = DAT_004d293c

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_004259f8[];
struct Head_2023e0 {
    int x, y, z;
    char d, e;
    void C(int);
};
struct Obj_2023e0 {
    int v;
    void A();
};
class CWorldCollisionManager_2023e0 {
  public:
    void* vf;
    char pad4[4];
    Head_2023e0 head;
    int value;
    char pad1c[4];
    Obj_2023e0 part;
    char pad24[4];
    char flag;
};
CWorldCollisionManager_2023e0* __fastcall FUN_002023e0(CWorldCollisionManager_2023e0* s, void*) {
    Head_2023e0* h = &s->head;
    s->vf = (void*)((hulk_intptr)DAT_004259f8);
    h->x = 0;
    h->y = 0;
    h->z = 0;
    h->d = 0;
    h->e = 0;
    s->part.A();
    s->value = (int)0xc61c4000;
    ((owners::Target_27b040 *)&(s->part))->FUN_0027b040((hulk_uintptr)0);
    s->flag = 0;
    h->C(DAT_004d293c);
    return s;
}
