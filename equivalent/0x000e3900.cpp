// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// MapThing::vfunc_11 @ 0x000e3900
struct Vec3 { float x, y, z; };

struct Entity {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPosition(Vec3* out);
};
struct Registry { Entity* FUN_001fd780(int id); };
struct Region { char data[4]; bool FUN_0022d2b0(const Vec3* pos, unsigned tag); };
struct RegionNode { char pad[4]; Region region; };
struct RegionList {
    int FUN_000c8180();
    RegionNode* FUN_000c8190(int i);
};
struct RegionManager { RegionList* FUN_000cae70(); };
struct Holder3c { char pad[8]; RegionManager* mgr; };
struct World {
    char pad0[0x28];
    Registry* registry;
    char pad2c[0x10];
    Holder3c* holder;
};
extern World* DAT_004dd700;

class MapThing {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int region);
    virtual void vfunc_11(int id);
};

// Finds the region that contains the entity's position and selects it.
void MapThing::vfunc_11(int id)
{
    Entity* e = DAT_004dd700->registry->FUN_001fd780(id);
    if (e == 0)
        return;
    Vec3 pos;
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
