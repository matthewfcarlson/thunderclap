// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000a9050..0x000a9e50 (kind game, layer game, confidence high), dominant class CGameCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f19d3f35 {
#define TREE_TU_END }
namespace fn_f19d3f35 {} using namespace fn_f19d3f35;
namespace fn_f19d3f35 {
void __cdecl SweepTrack_DeleteThis_00263f30(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_f19d3f35 { extern "C" char DAT_00405894[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f19d3f35 {
struct V {
    unsigned int a, b, c;
};
extern "C" void __cdecl FUN_0009f790(float, void*, float*, float*);
class Orbit {
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(float, float);
    char pad[0xd4 - 4];
    float angle;
    float outA;
    float outB;
    void* ref;
    void FUN_000a9090(float value);
};
struct Object { char padding[0xd0]; int flag; char rest[0x80]; int selected; char gap[8]; int alternate; };
struct Vec3_a91e0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Info_a91e0 {
    char pad0[0x20];
    Vec3_a91e0 dir;
    char pad1[4];
    Vec3_a91e0 pos;
};
class Owner_a91e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Info_a91e0* GetInfo();
    bool FUN_000a91e0(const Vec3_a91e0* target);
};
struct Vec3_a92c0 { float x, y, z; };
struct Target_a92c0 { bool FUN_000382c0(Vec3_a92c0 *out); };
struct Owner_a92c0 { char pad[0x124]; Target_a92c0 *target; };
struct Context { char pad[0x20]; Owner_a92c0 *owner; };
class Offset_a92c0 {
public:
    char pad[0xe4];
    float dx, dy, dz;
    Vec3_a92c0 FUN_000a92c0(Context *ctx, Target_a92c0 *t);
};
extern void* hulk_at_00405894[];
class Camera_a97b0 {
  public:
    void Destroy_002926c0(); // FUN_00236d60, __thiscall, this in ecx
};
class CGameCamera_a97b0 : public Camera_a97b0 {
  public:
    CGameCamera_a97b0* vfunc_5(signed char flags);
};


// 0x000a9050 FUN_000a9050 (23 B): matches/0x000a9050.cpp
// sym: ?FUN_000a9050@fn_f19d3f35@@YIPAUV@1@PAU21@@Z
V* __fastcall FUN_000a9050(V* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0x3f800000;
    return p;
}


// 0x000a9090 FUN_000a9090 (92 B): matches/0x000a9090.cpp
// sym: ?FUN_000a9090@Orbit@fn_f19d3f35@@QAEXM@Z
// FUN_000a9090 @ 0x000a9090
void Orbit::FUN_000a9090(float value) {
    if (value != angle) {
        angle = value;
        FUN_0009f790(value, ref, &outA, &outB);
        slot5(outA * 0.017453292f, 1.0f);
    }
}

} // namespace fn_f19d3f35

// 0x000a90f0 FUN_000a90f0 (21 B): matches/0x000a90f0.cpp
// sym: ?FUN_000a90f0@Thing_a90f0@owners@@QAEXHH@Z
void owners::Thing_a90f0::FUN_000a90f0(int index, int value) {
    values[index * 3] = value;
}


// 0x000a9110 FUN_000a9110 (18 B): matches/0x000a9110.cpp
// sym: ?FUN_000a9110@C_a9110@owners@@QAEXHM@Z
void owners::C_a9110::FUN_000a9110(int i, float v) {
    arr[i * 3 + 0x57] = v;
}


// 0x000a9130 FUN_000a9130 (21 B): matches/0x000a9130.cpp
// sym: ?FUN_000a9130@C_a9130@owners@@QAEXHH@Z
void owners::C_a9130::FUN_000a9130(int index, int value) {
    values[index * 3] = value;
}

namespace fn_f19d3f35 {

// 0x000a9170 FUN_000a9170 (45 B): equivalent/0x000a9170.cpp
// sym: _FUN_000a9170@8 @33f32bca1a76 @w922b0ae62f17
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a9170 @ 0x000a9170
extern "C" Object* __stdcall FUN_000a9170(Object* first, Object* second) {
    if (first->flag && !second->flag)
        return (Object*)&first->alternate;
    return (Object*)&second->selected;
}


// 0x000a91a0 CGameCamera::vfunc_28 (1 B): matches/0x000a91a0.cpp
// sym: ?FUN_000a91a0@fn_f19d3f35@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000a91a0() {}


// 0x000a91b0 CGameCamera::vfunc_29 (1 B): matches/0x000a91b0.cpp
// sym: ?FUN_000a91b0@fn_f19d3f35@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000a91b0(void* /*this, unused: callers pass it (unb4)*/) {}

} // namespace fn_f19d3f35

// 0x000a91c0 FUN_000a91c0 (3 B): matches/0x000a91c0.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_000a91c0@@UAEXH@Z
namespace fn_000a91c0 {
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

void CAgent::vfunc_7(int a) {
    (void)a;
}
} // namespace fn_000a91c0


// 0x000a91d0 FUN_000a91d0 (3 B): matches/0x000a91d0.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_000a91d0@@UAEXH@Z
namespace fn_000a91d0 {
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

void CAgent::vfunc_7(int a) {
    (void)a;
}
} // namespace fn_000a91d0

namespace fn_f19d3f35 {

// 0x000a91e0 FUN_000a91e0 (120 B): equivalent/0x000a91e0.cpp
// sym: ?FUN_000a91e0@Owner_a91e0@fn_f19d3f35@@QAE_NPBUVec3_a91e0@2@@Z @964923ef2cd4 @wdd46e71b9895
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000a91e0 @ 0x000a91e0
bool Owner_a91e0::FUN_000a91e0(const Vec3_a91e0* target) {
    Info_a91e0* info = GetInfo();
    Vec3_a91e0 d;
    d.z = target->z - info->pos.z;
    d.y = target->y - info->pos.y;
    d.x = target->x - info->pos.x;
    d.FUN_0022d110();
    Info_a91e0* info2 = GetInfo();
    return d.z * info2->dir.z + d.y * info2->dir.y + d.x * info2->dir.x < 0.3f;
}


// 0x000a92c0 FUN_000a92c0 (154 B): equivalent/0x000a92c0.cpp
// sym: ?FUN_000a92c0@Offset_a92c0@fn_f19d3f35@@QAE?AUVec3_a92c0@2@PAUContext@2@PAUTarget_a92c0@2@@Z @18370b4ef73f @w9e575b18b0b6
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000a92c0 @ 0x000a92c0
Vec3_a92c0 Offset_a92c0::FUN_000a92c0(Context *ctx, Target_a92c0 *t)
{
    Vec3_a92c0 v;
    if (t != 0 && t->FUN_000382c0(&v)) {
        if (ctx->owner->target == t) {
            v.x += dx;
            v.y += dy;
            v.z += dz;
        }
        return v;
    }
    v.x = 0;
    v.y = 0;
    v.z = 0;
    return v;
}

} // namespace fn_f19d3f35

// 0x000a9360 CGameCamera::vfunc_30 (17 B): matches/0x000a9360.cpp
// sym: ?vfunc_30@CGameCamera@@UAEXH@Z
void CGameCamera::vfunc_30(int ) {
    *((char*)this + 0xf0) = 1;
    *((char*)this + 0xf1) = 0;
}


// 0x000a9380 CGameCamera::vfunc_31 (3 B): matches/0x000a9380.cpp
// sym: ?vfunc_31@CGameCamera@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CGameCamera::vfunc_31(int a) {
    (void)a;
}


// 0x000a9390 CGameCamera::vfunc_37 (74 B): matches/0x000a9390.cpp [wrapped: conflict: CGameCamera]
// sym: ?vfunc_37@CGameCamera@fn_000a9390@@UAEXHHHM@Z
namespace fn_000a9390 {
// cl-flags: /O2 /GR /GX

class CGameCamera {
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
    virtual void vfunc_37(int index, int first, int second, float turns);

    char pad[0xf4 - 4]; // vptr at 0, slots at 0xf4

    struct Slot {
        int field0;
        int field1;
        int field2;
        float field3;
    };
    Slot slots[6];
};

void CGameCamera::vfunc_37(int index, int first, int second, float turns) {
    if (index >= 0 && index < 6) {
        static const float twoPi = 6.2831855f;
        float scaled = turns * twoPi;
        slots[index].field1 = first;
        slots[index].field2 = second;
        slots[index].field3 = scaled;
        slots[index].field0 = 0;
    }
}
} // namespace fn_000a9390


// 0x000a93e0 CGameCamera::vfunc_27 (17 B): matches/0x000a93e0.cpp
// sym: ?vfunc_27@CGameCamera@@UAEXPAX@Z
void CGameCamera::vfunc_27(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}


// 0x000a9400 FUN_000a9400 (177 B): equivalent/0x000a9400.cpp [wrapped: conflict: CGameCamera; pure3d::Camera]
// sym: ??0CGameCamera@fn_000a9400@@QAE@XZ @735048832553 @w64544bb976d8
namespace fn_000a9400 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000a9400 @ 0x000a9400

namespace pure3d {
struct Camera {
    Camera();
    virtual void slot0();
    virtual void slot1_000382a0();
    virtual void* slot2_000a97b0(char);
    virtual void slot3_0027afe0();
    virtual void slot4_0027aff0();
    virtual void slot5_002926d0(float, float);
    virtual void slot6_00292780(void*, void*);
    virtual void vfunc_7(float);
    virtual void slot8_002927c0();
    virtual void vfunc_9(float);
    char pad[0xcc];
};
}
struct Clock_a9400 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual float s16();
};
struct Vector { float x,y,z; };
struct CGameCamera : pure3d::Camera {
 int d0; int d4; int d8; int dc;
 float e0,e4,e8,ec;
 unsigned char f0,f1; char padf2[6];
 int f8; char pfc[12]; int f108; char p10c[12]; int f118; char p11c[12];
 int f128; char p12c[12]; int f138; char p13c[12]; int f148; char p14c[8];
 Vector v154,v160;
 CGameCamera();
 virtual void slot0();
 void FUN_000a9090(float);
};
CGameCamera::CGameCamera() {
 e4=0.0f; ec=0.0f; e8=1.0f; f0=0; f1=0;
 v154.x=0.0f; v154.y=0.0f; v154.z=1.0f;
 v160.x=0.0f; v160.y=0.0f; v160.z=1.0f;
 e0=(*(Clock_a9400**)&DAT_0052c2a4)->s16();
 d4=0;
 FUN_000a9090(75.0f);
 pure3d::Camera::vfunc_7(0.1f);
 pure3d::Camera::vfunc_9(3000.0f);
 f8=0; f108=0; f118=0; f128=0; f138=0; f148=0;
}
} // namespace fn_000a9400


// 0x000a94c0 FUN_000a94c0 (342 B): equivalent/0x000a94c0.cpp [wrapped: conflict: CGameCamera; pure3d::Camera]
// sym: ??0CGameCamera@fn_000a94c0@@QAE@ABU01@@Z @8b79d3579a2d @w3d5863359b33
namespace fn_000a94c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000a94c0 @ 0x000a94c0

namespace pure3d {
struct Camera {
 Camera();
 virtual void slot0_00038290(); virtual void slot1_000382a0(); virtual void* slot2_000a97b0(char); virtual void slot3_0027afe0(); virtual void slot4_0027aff0(); virtual void slot5_002926d0(float, float); virtual void slot6_00292780(void*, void*);
 virtual void vfunc_7(float);
 virtual float slot8_002927c0();
 virtual void vfunc_9(float);
 virtual float slot10_002927d0();
 virtual void slot11_002927e0(int, hulk_intptr); virtual void slot12_002928e0(void*, void*); virtual void slot13_00292910(); virtual unsigned slot14();
 virtual bool slot15_00292950(void*, void*); virtual char slot16_00292970(void*, float); virtual void slot17_00292a10(int); virtual void slot18_00292a50(void*, void*); virtual int slot19_00292a90(void*); virtual void slot20_00292b20(void*); virtual void vfunc_21(unsigned);
 char pad[0xd0]; unsigned d4; char padD8[8]; float e0; unsigned e4,e8,ec; unsigned char f0,f1; char padF2[6]; unsigned f8; char pfc[12]; unsigned f108; char p10c[12]; unsigned f118; char p11c[12]; unsigned f128; char p12c[12]; unsigned f138; char p13c[12]; unsigned f148; char p14c[8]; float x,y,z,u,v,w;
 void FUN_000a9090(unsigned);
};
}
struct Clock_a94c0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float s16(); };
struct CGameCamera: pure3d::Camera { CGameCamera(const CGameCamera& src); };
CGameCamera::CGameCamera(const CGameCamera& src) {
 e4=src.e4; e8=src.e8; ec=src.ec; f0=src.f0; f1=src.f1;
 x=0.0f; y=0.0f; z=1.0f; u=0.0f; v=0.0f; w=1.0f;
 e0=(*(Clock_a94c0**)&DAT_0052c2a4)->s16(); d4=0;
 FUN_000a9090(src.d4);
 pure3d::Camera::vfunc_7(const_cast<CGameCamera&>(src).slot8_002927c0());
 pure3d::Camera::vfunc_9(const_cast<CGameCamera&>(src).slot10_002927d0());
 pure3d::Camera::vfunc_21(const_cast<CGameCamera&>(src).slot14());
 x=src.x; y=src.y; z=src.z; u=src.u; v=src.v; w=src.w;
 f8=src.f8; f108=src.f108; f118=src.f118; f128=src.f128; f138=src.f138; f148=src.f148;
}
} // namespace fn_000a94c0


// 0x000a9620 FUN_000a9620 (11 B): matches/0x000a9620.cpp [wrapped: conflict: CEffectStopTrack]
// sym: @FUN_000a9620@4
namespace fn_000a9620 {
// Same code shape as 0x00060920 (propagated; names are from that function)
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_002926c0(CEffectStopTrack*);
extern "C" void __fastcall FUN_000a9620(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_00405894);
    FUN_002926c0(self);
}
} // namespace fn_000a9620

namespace fn_f19d3f35 {

// 0x000a97b0 CGameCamera::vfunc_2 (36 B): matches/0x000a97b0.cpp
// sym: ?vfunc_5@CGameCamera_a97b0@fn_f19d3f35@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGameCamera_a97b0* CGameCamera_a97b0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00405894;
    Destroy_002926c0();
    if (flags & 1) {
        SweepTrack_DeleteThis_00263f30(this);
    }
    return this;
}

} // namespace fn_f19d3f35
