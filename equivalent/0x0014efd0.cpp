// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_0014efd0 @ 0x0014efd0
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/owners.h"

struct Vec3_14efd0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};


void __cdecl FUN_00224d70(float angle, Vec3_14efd0 *axis);

struct Marker;

struct Timing_14efd0 {
    hulk_freg FUN_000354c0();
};
struct Clock_14efd0 {
    Timing_14efd0 *FUN_00059a30();
};

class Owner_14efd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Marker *GetMarker();
};

struct Config_14efd0 {
    char pad0[0x10];
    int f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    int f24;
    char f28;
    char pad29[3];
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    char f44;
};

struct State_14efd0 {
    float f0;
    float f4;
    char pad8[0x10];
    Vec3_14efd0 axis;
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
    void FUN_00059370(Marker *m);
    // equiv-conv: FUN_000595f0 ecx stack stack stack stack
    void FUN_000595f0(Vec3_14efd0 *v, float a, float b, float c);
};

struct Frame_14efd0 {
    float t;
    Vec3_14efd0 tmp;
};

// equiv-conv: FUN_0014efd0 ebx esi edi
extern "C" void FUN_0014efd0(void *owner, void *cfg, void * st_)
{
    State_14efd0 * st = (State_14efd0 *)st_;
    Frame_14efd0 f;
    f.t = ((Clock_14efd0 *)((owners::Object_592a0 *)(((Owner_14efd0 *)owner)))->FUN_000592a0())->FUN_00059a30()->FUN_000354c0();
    Marker *m = ((Owner_14efd0 *)owner)->GetMarker();
    if (m != 0 && ((Config_14efd0 *)cfg)->f44 == 0) {
        st->FUN_00059370(m);
        f.tmp.x = st->f28;
        f.tmp.y = 0;
        f.tmp.z = st->f30;
        f.tmp.FUN_0022d110();
    } else {
        st->f74 = ((Config_14efd0 *)cfg)->f10;
        st->axis = (*(Vec3_14efd0*)&DAT_004afa08);
        FUN_00224d70(f.t + ((Config_14efd0 *)cfg)->f14, &st->axis);
        float t2 = f.t + ((Config_14efd0 *)cfg)->f30;
        f.tmp = (*(Vec3_14efd0*)&DAT_004afa08);
        FUN_00224d70(t2, &f.tmp);
    }
    st->f0 = ((Config_14efd0 *)cfg)->f18;
    st->f4 = ((Config_14efd0 *)cfg)->f1c;
    st->f54 += ((Config_14efd0 *)cfg)->f24;
    st->f24 = ((Config_14efd0 *)cfg)->f28;
    st->f58 = ((Config_14efd0 *)cfg)->f2c;
    st->f68 = ((Config_14efd0 *)cfg)->f40;
    if (((Config_14efd0 *)cfg)->f20 >= (*(float*)&DAT_003f32e0))
        st->f78 = ((Config_14efd0 *)cfg)->f20;
    float u = ((Config_14efd0 *)cfg)->f38;
    if (u <= (*(float*)&DAT_003f32e0))
        u = ((Config_14efd0 *)cfg)->f2c;
    st->FUN_000595f0(&f.tmp, ((Config_14efd0 *)cfg)->f34, u, ((Config_14efd0 *)cfg)->f3c);
}
