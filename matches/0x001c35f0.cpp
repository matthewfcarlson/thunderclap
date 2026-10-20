#include "decls/data/engine/content.h"
#include "gen/Render.h"

extern int __cdecl FUN_00266da0(int);
extern void __cdecl FUN_0023f8c0(const char*);
extern void* __cdecl FUN_0008d690(unsigned int);
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
struct World_nv_1c35f0 {
    Render::World* FUN_001c9030();
};
struct Small_1c35f0 {
    Small_1c35f0* FUN_001c5f10();
};
struct ObjectManager_nv_1c35f0 {
    Render::ObjectManager* FUN_001c5840();
};
struct Owner_1c35f0;
struct LevelLoader_nv_1c35f0 {
    Render::LevelLoader* FUN_001c8f60(Render::World*, Owner_1c35f0*);
};
struct Item_1c35f0 {
    char pad[12];
    unsigned char active;
    Item_1c35f0* FUN_001c49c0();
};
struct Manager_1c35f0 {
    void FUN_00265210(Render::LevelLoader*, unsigned int);
};
struct Owner_1c35f0 {
    void* context;
    Render::World* engine;
    Small_1c35f0* small;
    Render::ObjectManager* medium;
    char pad10[4];
    Item_1c35f0* item14;
    Item_1c35f0* item18;
    char pad1c[0x52];
    unsigned char initialized;
    void FUN_001c35f0();
};
void Owner_1c35f0::FUN_001c35f0() {
    int previous = FUN_00266da0(15);
    if (initialized) {
        FUN_0023f8c0("Render engine already setup, setup aborted.\n");
        FUN_00266da0(previous);
        return;
    }
    FUN_0023f8c0("Starting render engine setup...\n");
    Render::World* e = (Render::World*)FUN_0008d690(0x768);
    engine = e ? ((World_nv_1c35f0*)(e))->FUN_001c9030() : 0;
    Small_1c35f0* s = (Small_1c35f0*)FUN_0008d690(0x10);
    small = s ? s->FUN_001c5f10() : 0;
    Render::ObjectManager* m = (Render::ObjectManager*)FUN_0008d690(0x250);
    medium = m ? ((ObjectManager_nv_1c35f0*)(m))->FUN_001c5840() : 0;
    Render::LevelLoader* r = (Render::LevelLoader*)thunk_FUN_0008d690(0x20);
    r = r ? ((LevelLoader_nv_1c35f0*)(r))->FUN_001c8f60(engine, (Owner_1c35f0*)context) : 0;
    (*(Manager_1c35f0**)&DAT_00527c58)->FUN_00265210(r, 0x60000700);
    FUN_0023f8c0("Render engine setup complete\n");
    Item_1c35f0* i = (Item_1c35f0*)FUN_0008d690(0x38);
    item18 = i ? i->FUN_001c49c0() : 0;
    i = (Item_1c35f0*)FUN_0008d690(0x38);
    item14 = i ? i->FUN_001c49c0() : 0;
    item14->active = 1;
    initialized = 1;
    FUN_00266da0(previous);
}
