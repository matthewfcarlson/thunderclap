// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 26/26)
// CSmartPropAttachAction::vfunc_6 @ 0x0001ead0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Vec3_1ead0 { int x, y, z; };

struct Sub_1ead0 {
    void FUN_001d82d0();
    void FUN_001d7590();
};

class Entity {
public:
    virtual void v0();
    virtual void v1();
    int f04;
    Sub_1ead0* sub;
    int kind;
};

class Holder_1ead0 {
public:
    char pad00[0x1ec];
    char flag;
    char pad1ed[3];
    Vec3_1ead0 pos;
    Entity* FUN_001d72e0();
};

struct Table_1ead0 {
    Holder_1ead0* FUN_001dee40(int a, int b);
};

struct World {
    char pad0[0xc];
    Table_1ead0* table;
};

struct Slot_1ead0 {
    char pad00[0x128];
    Holder_1ead0* holder;
};

struct Fighter_1ead0 { char pad[4]; };
struct Stats_1ead0 {
    char pad0[0x334];
    Slot_1ead0* slotA;
    Slot_1ead0* slotB;
    char pad33c[0x3a4 - 0x33c];
    Entity* defaultEntity;
    Holder_1ead0* FUN_00035ef0(int index);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
};
Fighter_1ead0* __fastcall FUN_000592a0(void* owner);
Stats_1ead0* __fastcall FUN_00059a30(Fighter_1ead0* f);

struct Singleton_1ead0 {
    bool FUN_000665e0(int* key, Stats_1ead0* stats);
    void FUN_00065ee0(int* key);
};
Singleton_1ead0* FUN_000678d0();

struct Owner_1ead0 {
    char pad00[0x10];
    Entity* entity;
};

struct Config_1ead0 {
    char pad00[0x14];
    int index;
    char pad18[0x48 - 0x18];
    char useWorld;
    char pad49[3];
    Vec3_1ead0 pos;
};

class CSmartPropAttachAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused);
    char pad04[0x1c - 4];
    Owner_1ead0* owner;
    Config_1ead0* config;
    Entity* current;
};

bool CSmartPropAttachAction::vfunc_6(int unused)
{
    Stats_1ead0* stats = FUN_00059a30(FUN_000592a0(owner));
    Entity* e;
    int index = config->index;
    if (config->useWorld) {
        if (!FUN_000678d0()->FUN_000665e0(DAT_004dc010, stats)) {
            stats->FUN_0003acf0(index, 0, -1, 0, 0, 0);
            return false;
        }
        Holder_1ead0* h = DAT_004dd700->table->FUN_001dee40(DAT_004dc010[0], DAT_004dc010[1]);
        if (!h) {
            stats->FUN_0003acf0(index, 0, -1, 0, 0, 0);
            return false;
        }
        h->flag = 1;
        Vec3_1ead0 p = config->pos;
        h->pos = p;
        e = h->FUN_001d72e0();
        FUN_000678d0()->FUN_00065ee0(DAT_004dc010);
    } else {
        e = 0;
        if (stats->FUN_00035ef0(index)) {
            e = stats->FUN_00035ef0(index)->FUN_001d72e0();
        }
        if (!e) {
            Slot_1ead0* s = stats->slotA;
            if (!s)
                s = stats->slotB;
            if (s && s->holder) {
                e = s->holder->FUN_001d72e0();
            }
            if (!e) {
                e = owner->entity;
                if (!e)
                    e = stats->defaultEntity;
            }
        }
    }
    if (!e) {
        stats->FUN_0003acf0(index, 0, -1, 0, 0, 0);
        return false;
    }
    if (e->kind == 5) {
        Sub_1ead0* sub = e->sub;
        sub->FUN_001d82d0();
        sub->FUN_001d7590();
    }
    e->v0();
    if (current)
        current->v1();
    current = e;
    return true;
}
