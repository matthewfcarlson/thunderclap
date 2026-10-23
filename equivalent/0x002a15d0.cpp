// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 12/12)
// FUN_002a15d0 @ 0x002a15d0
#include "gen/pure3d.h"
struct LightGroup_nv_2a15d0 {
    pure3d::LightGroup* FUN_002a1140(unsigned int count);
};
void* __cdecl FUN_00263ea0(unsigned int bytes);
struct Holder {
    char pad0[0x2c];
    pure3d::LightGroup* item;
    char pad30[4];
    unsigned int count;
    void FUN_002a15d0(unsigned int newCount);
};
void Holder::FUN_002a15d0(unsigned int newCount) {
    if (newCount != count) {
        if (item) {
            item->vfunc_1();
            item = 0;
        }
        if (newCount != 0) {
            pure3d::LightGroup* created = 0;
            void* memory = FUN_00263ea0(0x28);
            if (memory) created = ((LightGroup_nv_2a15d0*)(((pure3d::LightGroup*)(((pure3d::LightGroup*)memory)))))->FUN_002a1140(newCount);
            if (created) created->vfunc_0();
            if (item) item->vfunc_1();
            item = created;
        }
        count = newCount;
    }
}