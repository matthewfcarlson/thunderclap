// STATUS: equivalent (tools/equiv.py level 3: 19978 inputs, branch coverage 29/30, incomplete)
// FUN_002fddf0 @ 0x002fddf0
#include "compat/ptr.h"
#include "gen/physics.h"
struct Pose_2fddf0 {
    int words[21];
};

struct InnerCtl {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad04[0x15];
    unsigned char flag19;
};

struct Binding_2fddf0 {
    char pad0[0x18];
    int handle;
};

struct Item_2fddf0 {
    char pad0[0x20];
    InnerCtl *ctl;
    char pad24[0x50 - 0x24];
    unsigned char locked;
    char pad51[0x68 - 0x51];
    unsigned char dirtyA;
    unsigned char dirtyB;
    void FUN_00304740(int handle);
};

struct Flagged_2fddf0 {
    char pad0[0x94];
    unsigned char flag;
};

class Sink_2fddf0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(Binding_2fddf0 *b);
    virtual void vfunc_14(Item_2fddf0 *item);
    char pad04[0x90];
    unsigned char flag94;
};

class Source_2fddf0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual Item_2fddf0 *vfunc_5(Sink_2fddf0 *sink);
    char pad04[0x14];
    Flagged_2fddf0 *flagged;
};

class Provider_2fddf0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual Binding_2fddf0 *vfunc_28(Sink_2fddf0 *sink);
    char pad04[0xc];
    Flagged_2fddf0 *flagged;
    char pad14[0x24 - 0x14];
    int kind;
    char pad28[0x220 - 0x28];
    int extra;

    void FUN_00310e90(void *handler);
};

struct PoseItem {
    Pose_2fddf0 *FUN_0030ef30();
    void FUN_0030ee40(Pose_2fddf0 *pose);
};

struct Chain_2fddf0 {
    char pad0[8];
    void *owner;
    void FUN_0030f4c0();
    PoseItem *FUN_0030f490(int index);
};

struct SkeletonInfo_nv_2fddf0 {
    physics::SkeletonInfo *FUN_00312440(void *owner);
};

void *__cdecl FUN_0008d690(hulk_uintptr size);
void *__cdecl FUN_00263ea0(unsigned int size);

struct SimStateArticulated_nv_2fddf0 {
    Sink_2fddf0 *FUN_002fdc90(Chain_2fddf0 *chain, int arg);
};

Sink_2fddf0 *__cdecl FUN_002fddf0(Chain_2fddf0 *chain, Source_2fddf0 *source, Provider_2fddf0 *provider)
{
    chain->FUN_0030f4c0();
    Pose_2fddf0 *pose = chain->FUN_0030f490(0)->FUN_0030ef30();
    chain->FUN_0030f490(0)->FUN_0030ee40(pose);

    physics::SimStateArticulated *mem = (physics::SimStateArticulated *)FUN_0008d690(0x98);
    if (mem == 0)
        return 0;
    Sink_2fddf0 *sink = ((SimStateArticulated_nv_2fddf0*)(mem))->FUN_002fdc90(chain, 0);
    if (sink == 0)
        return 0;

    Binding_2fddf0 *binding = 0;
    if (provider != 0) {
        if (provider->kind == 1 && provider->extra == 0) {
            physics::SkeletonInfo *h = (physics::SkeletonInfo *)FUN_00263ea0(0x18);
            if (h != 0)
                h = ((SkeletonInfo_nv_2fddf0*)(h))->FUN_00312440(chain->owner);
            provider->FUN_00310e90(h);
        }
        if (provider->flagged != 0) {
            if (provider->flagged->flag != 0)
                sink->flag94 = 1;
            binding = provider->vfunc_28(sink);
        } else {
            binding = provider->vfunc_28(sink);
        }
        sink->vfunc_13(binding);
    }

    if (source != 0) {
        Item_2fddf0 *item;
        if (source->flagged != 0) {
            if (source->flagged->flag != 0)
                sink->flag94 = 1;
            item = source->vfunc_5(sink);
        } else {
            item = source->vfunc_5(sink);
        }
        sink->vfunc_14(item);
        if (item->dirtyA != 0 || item->dirtyB != 0)
            item->ctl->vfunc_10();
        item->ctl->vfunc_8();
        if (item->locked == 0) {
            item->ctl->flag19 = 0;
            item->dirtyA = 1;
            item->dirtyB = 1;
        }
        if (binding != 0)
            item->FUN_00304740(binding->handle);
    }
    return sink;
}
