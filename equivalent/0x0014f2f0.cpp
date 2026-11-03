// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0014f2f0 @ 0x0014f2f0
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/owners.h"

struct Vec3_14f2f0 {
    float x, y, z;
    float FUN_0022d110();
};


void __cdecl FUN_00224d70(float angle, Vec3_14f2f0 *axis);

struct Marker_14f2f0 {
    char pad0[0x7c];
    float f7c;
};

struct Timing_14f2f0 {
    float FUN_000354c0();
};
struct Clock_14f2f0 {
    Timing_14f2f0 *FUN_00059a30();
};

class Owner_14f2f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Marker_14f2f0 *GetMarker();
};

struct Config_14f2f0 {
    char pad0[0x10];
    int f10;
    float f14;
    float f18;
    float f1c;
    int f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;
    float f4c;
    char f50;
};

struct State_14f2f0 {
    float f0;
    float f4;
    char pad8[0x10];
    Vec3_14f2f0 axis;
    char f24;
    char pad25[3];
    float f28;
    char pad2c[4];
    float f30;
    char pad34[0x20];
    int f54;
    float f58;
    char pad5c[0xc];
    float f68;
    char pad6c[8];
    int f74;
    float f78;
    void FUN_00059370(Marker_14f2f0 *m);
    // equiv-conv: FUN_000595f0 ecx stack stack stack stack
    void FUN_000595f0(Vec3_14f2f0 *v, float a, float b, float c);
};

struct Frame_14f2f0 {
    float t;
    float v;
    Vec3_14f2f0 tmp;
};

// equiv-conv: FUN_0014f2f0 eax esi edi
extern "C" void FUN_0014f2f0(void *owner, void *cfg, void * st_)
{
    State_14f2f0 * st = (State_14f2f0 *)st_;
    Frame_14f2f0 f;
    f.t = ((Clock_14f2f0 *)((owners::Object_592a0 *)(((Owner_14f2f0 *)owner)))->FUN_000592a0())->FUN_00059a30()->FUN_000354c0();
    Marker_14f2f0 *m = ((Owner_14f2f0 *)owner)->GetMarker();
    f.v = 0.0f;
    if (m != 0 && ((Config_14f2f0 *)cfg)->f50 == 0) {
        st->FUN_00059370(m);
        f.tmp.x = st->f28;
        f.tmp.y = 0;
        f.tmp.z = st->f30;
        f.tmp.FUN_0022d110();
        f.v = m->f7c;
    } else {
        st->f74 = ((Config_14f2f0 *)cfg)->f10;
        st->axis = (*(Vec3_14f2f0*)&DAT_004afa08);
        FUN_00224d70(f.t + ((Config_14f2f0 *)cfg)->f14, &st->axis);
        float t2 = f.t + ((Config_14f2f0 *)cfg)->f24;
        f.tmp = (*(Vec3_14f2f0*)&DAT_004afa08);
        FUN_00224d70(t2, &f.tmp);
    }
    st->f0 = ((Config_14f2f0 *)cfg)->f18;
    st->f4 = ((Config_14f2f0 *)cfg)->f1c;
    st->f54 += ((Config_14f2f0 *)cfg)->f20;
    st->f24 = 1;
    st->f68 = ((Config_14f2f0 *)cfg)->f48 + (((Config_14f2f0 *)cfg)->f4c - ((Config_14f2f0 *)cfg)->f48) * f.v;
    if (((Config_14f2f0 *)cfg)->f28 >= (*(float*)&DAT_003f32e0))
        st->f78 = ((Config_14f2f0 *)cfg)->f28 + (((Config_14f2f0 *)cfg)->f2c - ((Config_14f2f0 *)cfg)->f28) * f.v;
    float r1 = ((Config_14f2f0 *)cfg)->f38 + (((Config_14f2f0 *)cfg)->f3c - ((Config_14f2f0 *)cfg)->f38) * f.v;
    st->f58 = r1;
    float r2 = ((Config_14f2f0 *)cfg)->f40 + (((Config_14f2f0 *)cfg)->f44 - ((Config_14f2f0 *)cfg)->f40) * f.v;
    float r3 = ((Config_14f2f0 *)cfg)->f30 + (((Config_14f2f0 *)cfg)->f34 - ((Config_14f2f0 *)cfg)->f30) * f.v;
    st->FUN_000595f0(&f.tmp, r3, r1, r2);
}
