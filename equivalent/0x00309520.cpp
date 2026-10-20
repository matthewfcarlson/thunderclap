// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 16/16)
// FUN_00309520 @ 0x00309520
#include "compat/ptr.h"
void *__cdecl FUN_0008d6d0(hulk_uintptr size);

struct Vec3_309520 {
    float x, y, z;
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90();
    void FUN_002fd080();
    void FUN_002fcaf0(const SymMatrix *src);
};

struct Part_309520 {
    SymMatrix inertia;
    Vec3_309520 pos;
    float mass;
    float massBits;
    unsigned char active;
    char pad31[3];
};

struct Source_309520 {
    char pad0[0x34];
    float mass;
    char pad38[0x48 - 0x38];
    SymMatrix inertia;
    char pad64[0x80 - 0x64];
    Vec3_309520 pos;
};

struct Settings_309520 {
    char pad0[0xc];
    float massScale;
};

namespace physics {

class __declspec(novtable) PhysicsObject {
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
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    char pad04[0xc];
    int hook;
    char pad14[4];
    Settings_309520 *settings;
    char pad1c[8];
    int mode;
    char pad28[0x10];
    float totalMass;
    char pad3c[0x1f8 - 0x3c];
    void FUN_002f65f0(int a);
    PhysicsObject(int a) throw() { FUN_002f65f0(a); }
};

class HairclubPhysicsObject : public PhysicsObject {
public:
    Part_309520 *parts;
    int count;
    void FUN_00309410();
    HairclubPhysicsObject(int a, Source_309520 **sources, int n) throw();
};

HairclubPhysicsObject::HairclubPhysicsObject(int a, Source_309520 **sources, int n) throw() : PhysicsObject(a)
{
    parts = 0;
    count = n;
    mode = 2;
    Part_309520 *arr = 0;
    int *mem = (int *)FUN_0008d6d0(n * sizeof(Part_309520) + 4);
    if (mem) {
        *mem = n;
        arr = (Part_309520 *)(mem + 1);
        for (int i = 0; i < n; i++)
            arr[i].inertia.FUN_002fca90();
    }
    parts = arr;
    for (int i = 0; i < count; i++) {
        parts[i].inertia.FUN_002fd080();
        parts[i].inertia.FUN_002fcaf0(&sources[i]->inertia);
        parts[i].pos = sources[i]->pos;
        parts[i].mass = sources[i]->mass * settings->massScale;
        parts[i].massBits = sources[i]->mass;
        parts[i].active = 1;
    }
    for (int i = 0; i < count; i++)
        totalMass = parts[i].massBits + totalMass;
    if (hook != 0)
        FUN_00309410();
}

}
