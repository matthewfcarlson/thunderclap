// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// MapThing::vfunc_11 @ 0x000e3900
#include "gen/global.h"
#include "decls/address.h"

struct Vec3_e3900 { float x, y, z; };

struct Entity_e3900 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPosition(Vec3_e3900* out);
};
struct Registry_e3900 { Entity_e3900* FUN_001fd780(int id); };
struct Region_e3900 { char data[4]; bool FUN_0022d2b0(const Vec3_e3900* pos, unsigned tag); };
struct RegionNode { char pad[4]; Region_e3900 region; };
struct RegionList {
    int FUN_000c8180();
    RegionNode* FUN_000c8190(int i);
};
struct RegionManager { RegionList* FUN_000cae70(); };
struct Holder3c { char pad[8]; RegionManager* mgr; };
struct World {
    char pad0[0x28];
    Registry_e3900* registry;
    char pad2c[0x10];
    Holder3c* holder;
};

// Finds the region that contains the entity's position and selects it.

void MapThing::vfunc_11(int id) {
    Entity_e3900* e = DAT_004dd700->registry->FUN_001fd780(id);
    if (e == 0)
        return;
    Vec3_e3900 pos;
    e->GetPosition(&pos);
    RegionList* list = DAT_004dd700->holder->mgr->FUN_000cae70();
    for (int i = 0; i < list->FUN_000c8180(); i++) {
        RegionNode* n = list->FUN_000c8190(i);
        if (n && n->region.FUN_0022d2b0(&pos, 0x3727c5ac)) {
            vfunc_10(i);
            break;
        }
    }
}
