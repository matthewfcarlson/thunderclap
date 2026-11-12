// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030ea00..0x0030eba0 (kind game, layer engine, confidence high), dominant class physics::PoseDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fe58ce06 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fe58ce06 {} using namespace fn_fe58ce06;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fe58ce06 {
struct Vec3_30ea10 {
    unsigned int x, y, z;
};
struct Shape_30ea10 {
    Vec3_30ea10 v[5];
    unsigned int extra;
    void FUN_0030ea10(const Vec3_30ea10 *a, const Vec3_30ea10 *b, const Vec3_30ea10 *c, const Vec3_30ea10 *d, const Vec3_30ea10 *e, unsigned int f);
};
struct V3 {
    int x, y, z;
    V3() : x(0), y(0), z(0) { _ReadWriteBarrier(); }
};
struct H3 {
    float x, y, z;
    H3() : x(0.5f), y(0.5f), z(0.5f) {}
};
class ColorState {
  public:
    ColorState();
    V3 a;
    H3 d;
    float g;
    int h, i, j;
    float k;
    int l, m, n;
    float o;
    int p;
};
extern "C" char DAT_0043209c[];
struct PoseDriver_nv_30eb10 {
    void InitBase_0027b070();
};
void __fastcall FUN_0027afd0(CEffectStopTrack*);
extern void* hulk_at_0043209c[];
class Entity_30eb60 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class PoseDriver_30eb60 : public Entity_30eb60 {
  public:
    PoseDriver_30eb60* vfunc_5(signed char flags);
};


// 0x0030ea00 FUN_0030ea00 (1 B): matches/0x0030ea00.cpp
// sym: ?FUN_0030ea00@fn_fe58ce06@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0030ea00() {}


// 0x0030ea10 FUN_0030ea10 (114 B): equivalent/0x0030ea10.cpp
// sym: ?FUN_0030ea10@Shape_30ea10@fn_fe58ce06@@QAEXPBUVec3_30ea10@2@0000I@Z @828474353fbf @w2d5b78024651
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030ea10 @ 0x0030ea10
void Shape_30ea10::FUN_0030ea10(const Vec3_30ea10 *a, const Vec3_30ea10 *b, const Vec3_30ea10 *c, const Vec3_30ea10 *d, const Vec3_30ea10 *e, unsigned int f)
{
    v[0] = *a;
    v[1] = *b;
    v[2] = *c;
    v[3] = *d;
    v[4] = *e;
    extra = f;
}


// 0x0030eaa0 FUN_0030eaa0 (62 B): matches/0x0030eaa0.cpp
// sym: ??0ColorState@fn_fe58ce06@@QAE@XZ
ColorState::ColorState() {
    h = 0;
    i = 0;
    _ReadWriteBarrier();
    g = 1.0f;
    j = 0;
    k = 1.0f;
    l = 0;
    m = 0;
    n = 0;
    o = 1.0f;
    p = 0;
}


// 0x0030eb10 FUN_0030eb10 (22 B): matches/0x0030eb10.cpp
// sym: ?FUN_0030eb10@fn_fe58ce06@@YIPAVPoseDriver@physics@@PAV23@@Z
physics::PoseDriver* __fastcall FUN_0030eb10(physics::PoseDriver* self) {
    ((PoseDriver_nv_30eb10*)(((physics::PoseDriver*)(self))))->InitBase_0027b070();
    *(void**)self = (void*)((hulk_intptr)DAT_0043209c);
    (*(char *)&self->f_10) = 1;
    return self;
}


// 0x0030eb30 physics::PoseDriver::vfunc_5 (3 B): matches/0x0030eb30.cpp
// sym: ?GetZero@fn_fe58ce06@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_fe58ce06

// 0x0030eb40 physics::PoseDriver::vfunc_6 (3 B): matches/0x0030eb40.cpp [wrapped: same definition as 0x0030eb30 in this TU]
// sym: ?GetZero@fn_0030eb40@@YAIXZ
namespace fn_0030eb40 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0030eb40

namespace fn_fe58ce06 {

// 0x0030eb50 FUN_0030eb50 (11 B): matches/0x0030eb50.cpp
// sym: ?FUN_0030eb50@fn_fe58ce06@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_0030eb50(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_0043209c);
    FUN_0027afd0(self);
}


// 0x0030eb60 physics::PoseDriver::vfunc_2 (36 B): matches/0x0030eb60.cpp
// sym: ?vfunc_5@PoseDriver_30eb60@fn_fe58ce06@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PoseDriver_30eb60* PoseDriver_30eb60::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0043209c;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fe58ce06
