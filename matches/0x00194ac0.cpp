#include "decls/address.h"
extern char DAT_00494b44, DAT_00494b60, DAT_004bfe10, DAT_004bfe2c;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Prop_194ac0 {};
struct Lookup_194ac0 {
    Prop_194ac0* FUN_00035ef0(int);
};
struct Context {
    Lookup_194ac0* FUN_00059a30();
};
struct Actor_194ac0 {
    Context* FUN_000592a0();
};
struct Entry_194ac0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Prop_194ac0* slot5();
};
struct Registry_194ac0 {
    Entry_194ac0* FUN_001b68e0(int);
};
struct World {
    char pad[0x14];
    Registry_194ac0* registry;
};
namespace hulkfight {
namespace motion {
struct PropIsMissileCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void*, Actor_194ac0*, void*);
    char padding[8];
    int propId;
    unsigned char expected;
};
bool PropIsMissileCondition::vfunc_6(void*, Actor_194ac0* actor, void*) {
    if (!FUN_00344e74(actor, 0, &DAT_00494b44, &DAT_00494b60, 0))
        return false;
    Context* context = actor->FUN_000592a0();
    Lookup_194ac0* lookup = context->FUN_00059a30();
    Prop_194ac0* prop = lookup->FUN_00035ef0(propId);
    if (!prop)
        return expected == 0;
    Registry_194ac0* registry = DAT_004dd700->registry;
    for (int i = 0; i < 32; ++i) {
        Entry_194ac0* entry = registry->FUN_001b68e0(i);
        if (entry && entry->slot5() == prop) {
            bool missile = FUN_00344e74(entry, 0, &DAT_004bfe10, &DAT_004bfe2c, 0) != 0;
            return expected == (unsigned char)missile;
        }
    }
    return expected == 0;
}
} // namespace motion
} // namespace hulkfight
