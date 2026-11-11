// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00193bc0..0x00195100 (kind game, layer game, confidence high), dominant class hulkfight::motion::AccuracyLatencyAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc8c1e47 {
#define TREE_TU_END }
namespace fn_fc8c1e47 {} using namespace fn_fc8c1e47;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc8c1e47 {
extern int* hulk_at_004e1548;
class CCondition_193bc0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1550;
class CCondition_193c20 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1558;
class CCondition_193c80 {
  public:
    virtual int vfunc_0(int);
};
struct Param_193d90 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_193d90 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_0041b288[];
class Ref_193da0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_193da0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
void Free(void*) throw();
struct Sub_193da0 {
    char c;
};
void __fastcall SubFini_0027af50(Sub_193da0*) throw();
void __fastcall SubFini2_00234150(Sub_193da0*) throw();
class FireProjectileTrack_193da0 : public Track_193da0 {
  public:
    char p[0x14];
    Sub_193da0 s18;
    char p1[0x1f];
    Sub_193da0 s38;
    char p2[0x4f];
    Sub_193da0 s88;
    char p3[0x13];
    Sub_193da0 s9c;
    char p4[0xb];
    Sub_193da0 sa8;
    ~FireProjectileTrack_193da0() throw();
};
extern int* hulk_at_004e1560;
class CCondition_193e10 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1568;
class CCondition_193ee0 {
  public:
    virtual int vfunc_0(int);
};
class Track_193ef0 {
  public:
    Track_193ef0();
    virtual void dummy();
    char pad[4];
};
class Part {
  public:
    Part();
};
class MissilePunchTrack : public Track_193ef0 {
  public:
    MissilePunchTrack();
    char pad2[4];
    int a;
    float b;
    float c;
    Part part;
};
struct Param_193f40 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_193f40 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Tail_193f50 {
    void Init_00234150();
};
struct MissilePunchTrack_193f50 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_0041b2e8;
extern int* hulk_at_004e1570;
class CCondition_193f90 {
  public:
    virtual int vfunc_0(int);
};
class Track_193fa0 {
  public:
    Track_193fa0();
    virtual void f();
};
class AccuracyLatencyTrack : public Track_193fa0 {
  public:
    AccuracyLatencyTrack();
    char pad[4];
    int a;
    int b;
    float c;
    int d;
    float e;
};
struct Param_193fe0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_193fe0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e1578;
class CCondition_194020 {
  public:
    virtual int vfunc_0(int);
};
struct Param_194200 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_194200 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" char DAT_0041b348[];
struct S18 {
    char z[0x18];
    void Clear_0027af50();
};
struct S30 {
    char z[0x40];
    void Clear_0027af50();
};
struct S70 {
    char z[0x14];
    void Clear_0027af50();
};
struct S84 {
    char z[0x2c];
    void Clear_00234150();
};
struct SB0 {
    char z[0x10];
    void Clear_00234150();
};
struct SC0 {
    char z[0x10];
    void Clear_0027af50();
};
struct FireBeamTrack {
    hulk_uintptr vptr;
    char pad[0x14];
    S18 a;
    S30 b;
    S70 c;
    S84 d;
    SB0 e;
    SC0 f;
    void Finish_00236d60();
    void Reset();
};
extern int* hulk_at_004e1580;
class CCondition_194280 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041b378[];
} // namespace fn_fc8c1e47
void operator delete[](void*);
namespace fn_fc8c1e47 {
struct T1 {
    void Fini_0027af50();
};
struct T2 {
    void Fini_00234150();
};
class Track_194490 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class FireMissileTrack_194490 : public Track_194490 {
  public:
    char pad10[0xc];
    T1 m10;
    char pad18[0x7];
    T1 m18;
    char pad20[0x7];
    T1 m20;
    char pad38[0x17];
    T1 m38;
    char padbc[0x83];
    T2 mbc;
    char padc8[0xb];
    T2 mc8;
    char paddc[0x13];
    void* mdc;
    char pade8[0x8];
    T1 me8;
    char pad100[0x17];
    T2 m100;
    char pad128[0x27];
    T1 m128;
    ~FireMissileTrack_194490() throw();
};
void* __cdecl FUN_0008d340(void* p);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
extern int* hulk_at_004e1588;
class CCondition_1945a0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_0041b3a8[];
extern void __fastcall initA_0027af50(void*);
extern void __fastcall initB_00234150(void*);
extern void __fastcall finish_00236d60(void*);
struct FireGroundShockwaveTrack {
  public:
    void* vt;
    char _m_pad_4[0xa4];
    FireGroundShockwaveTrack* vfunc_5(unsigned char flag);
    void baseInit_00236d60();
};
struct Vec3_1947a0 {
    float x, y, z;
};
struct Wanderer {
    char pad0[0x1d1c];
    int steps;
    char pad1d20[0x1d2c - 0x1d20];
    int direction;
};
struct RandState_1947a0 {
    unsigned s0;
    unsigned s1;
    float FUN_000787e0(float lo, float hi);
};
extern "C" RandState_1947a0* FUN_000964d0();
struct Player_194cb0 {
    char pad0[0x1d54];
    int aimX;               // 0x1d54
    int aimY;               // 0x1d58
    int aimZ;               // 0x1d5c
    int aimW;               // 0x1d60
    int aimV;               // 0x1d64
};
struct PlayerRef_194cb0 {
    Player_194cb0 *FUN_00059a30();
};
struct Owner_194cb0 {
};
struct Vec {
    float x, y, z;
    Vec() : x(0.0f), y(0.0f), z(0.0f) {}
};
struct Obj {
    char pad[0x40];
    Vec v;
};
typedef unsigned int u32_194d90;
struct Obj_194d90 {
    char pad[0x20];
    Obj_194d90* HelperB_00059a30();
    void DoWork_0003b580(int, u32_194d90, u32_194d90);
};
struct ObjC_194dd0;
struct ObjB_194dd0 {
    ObjC_194dd0* Fng_00059a30();
};
struct ObjA_194dd0 {
};
struct ObjC_194dd0 {
    void Fnh_0003b580(int, int, int);
};
extern void* hulk_at_0041b248[];
class Condition_194ee0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class PropGrabbableIsMissileCondition_194ee0 : public Condition_194ee0 {
  public:
    PropGrabbableIsMissileCondition_194ee0* vfunc_5(signed char flags);
};
extern void* hulk_at_0041b268[];
class Condition_194f10 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class PropIsMissileCondition_194f10 : public Condition_194f10 {
  public:
    PropIsMissileCondition_194f10* vfunc_5(signed char flags);
};
class Track {
  public:
    virtual void v0();
    ~Track();
};
struct P18_194f40 {
    ~P18_194f40();
    char pad[0x20];
};
struct P38 {
    ~P38();
    char pad[0x50];
};
struct P88 {
    ~P88();
    char pad[0x14];
};
struct P9c {
    ~P9c();
    char pad[0xc];
};
struct Pa8 {
    ~Pa8();
    char pad[4];
};
extern int g_FireProjectileTrackVtable;
void FUN_0008d330(void*);
class FireProjectileTrack : public Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual FireProjectileTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();

  private:
    char pad0[0x18 - 4];
    P18_194f40 m18;
    P38 m38;
    P88 m88;
    P9c m9c;
    Pa8 ma8;
};
extern void* hulk_at_0041b2b8[];
class Track_194fa0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class MissileThrowTrack_194fa0 : public Track_194fa0 {
  public:
    MissileThrowTrack_194fa0* vfunc_5(signed char flags);
};
extern void* hulk_at_0041b318[];
class Track_195000 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class AccuracyLatencyTrack_195000 : public Track_195000 {
  public:
    AccuracyLatencyTrack_195000* vfunc_5(signed char flags);
};
struct Part_1950b0 {
    void init_0027af50();
};
struct Part2_1950b0 {
    void init2_00234150();
};
void destroy_0008d330(void*);

} // namespace fn_fc8c1e47

// 0x00193bc0 hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_0 (16 B): matches/0x00193bc0.cpp
// sym: ?vfunc_0@PropGrabbableIsMissileCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1548;
    return p[index];
}

namespace fn_fc8c1e47 {

// 0x00193c00 FUN_00193c00 (19 B): matches/0x00193c00.cpp
// sym: ?FUN_00193c00@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00193c00() {
    FUN_00234810(((char*)&DAT_004e1550), ((char*)&DAT_004e1554));
}

} // namespace fn_fc8c1e47

// 0x00193c20 hulkfight::motion::PropIsMissileCondition::vfunc_0 (16 B): matches/0x00193c20.cpp
// sym: ?vfunc_0@PropIsMissileCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropIsMissileCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1550;
    return p[index];
}

namespace fn_fc8c1e47 {

// 0x00193c60 FUN_00193c60 (19 B): matches/0x00193c60.cpp
// sym: ?FUN_00193c60@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00193c60() {
    FUN_00234810(((char*)&DAT_004e1558), ((char*)&DAT_004e155c));
}

} // namespace fn_fc8c1e47

// 0x00193c80 hulkfight::motion::FireProjectileTrack::vfunc_0 (16 B): matches/0x00193c80.cpp
// sym: ?vfunc_0@FireProjectileTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FireProjectileTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1558;
    return p[index];
}


// 0x00193c90 FUN_00193c90 (228 B): equivalent/0x00193c90.cpp [wrapped: conflict: hulkfight::motion::FireProjectileTrack]
// sym: ?FUN_00193c90@FireProjectileTrack@motion@hulkfight@fn_00193c90@@QAEPAV1234@XZ @9b72c201c4c4 @w08a93b1aa6cc
inline void *operator new(size_t, void *p) { return p; }
namespace fn_00193c90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00193c90 @ 0x00193c90


struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_193c90 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

namespace hulkfight {
namespace motion {
class FireProjectileTrack {
public:
    virtual void vfunc_0();
    char pad4[4];
    int f8;
    int fc;
    float f10;
    char pad14[4];
    Name8_193c90 n18;
    int f20;
    int f24;
    float f28;
    float f2c;
    int f30;
    char pad34[4];
    Name8_193c90 n38;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    float f54;
    int f58;
    float f5c;
    float f60;
    int f64;
    float f68;
    float f6c;
    int f70;
    char b74;
    char b75;
    char b76;
    char pad77[1];
    float f78;
    int f7c;
    int f80;
    char pad84[4];
    Name8_193c90 n88;
    int f90;
    int f94;
    float f98;
    Name12 n9c;
    Name12 na8;
    int fb4;
    int fb8;
    int fbc;

    FireProjectileTrack() {}
    FireProjectileTrack *FUN_00193c90();
};
}
}

hulkfight::motion::FireProjectileTrack *hulkfight::motion::FireProjectileTrack::FUN_00193c90()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) FireProjectileTrack;
    fc = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f2c = 1e+01f;
    f30 = -1;
    n38.FUN_0027af00();
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f54 = -1.0f;
    f58 = 0;
    f5c = 2e+01f;
    f60 = 2e+01f;
    f64 = 0;
    f68 = 1.5707964f;
    f6c = 1e+02f;
    f70 = 0;
    b74 = 0;
    b75 = 0;
    b76 = 1;
    f78 = 6e+01f;
    f7c = 0;
    f80 = 0;
    n88.FUN_0027af00();
    f90 = 0;
    f94 = 0;
    f98 = -1.0f;
    n9c.FUN_00233dd0();
    na8.FUN_00233dd0();
    fb4 = 0;
    fb8 = 0;
    fbc = 0;
    f8 = 1;
    return this;
}
} // namespace fn_00193c90


// 0x00193d80 hulkfight::motion::FireProjectileTrack::vfunc_6 (4 B): matches/0x00193d80.cpp
// sym: ?vfunc_6@FireProjectileTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FireProjectileTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00193d90 hulkfight::motion::FireProjectileTrack::vfunc_7 (7 B): matches/0x00193d90.cpp
// sym: ?vfunc_7@FireProjectileTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FireProjectileTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fc8c1e47 {

// 0x00193da0 FUN_00193da0 (66 B): matches/0x00193da0.cpp
// sym: ??1FireProjectileTrack_193da0@fn_fc8c1e47@@QAE@XZ
FireProjectileTrack_193da0::~FireProjectileTrack_193da0() throw() {
    vptr = hulk_at_0041b288;
    SubFini2_00234150(&sa8);
    SubFini2_00234150(&s9c);
    SubFini_0027af50(&s88);
    SubFini_0027af50(&s38);
    SubFini_0027af50(&s18);
    Fin_00236d60();
}


// 0x00193df0 FUN_00193df0 (19 B): matches/0x00193df0.cpp
// sym: ?FUN_00193df0@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00193df0() {
    FUN_00234810(((char*)&DAT_004e1560), ((char*)&DAT_004e1564));
}

} // namespace fn_fc8c1e47

// 0x00193e10 hulkfight::motion::MissileThrowTrack::vfunc_0 (16 B): matches/0x00193e10.cpp
// sym: ?vfunc_0@MissileThrowTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MissileThrowTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1560;
    return p[index];
}


// 0x00193e20 FUN_00193e20 (102 B): equivalent/0x00193e20.cpp [wrapped: conflict: hulkfight::motion::MissileThrowTrack]
// sym: ?FUN_00193e20@MissileThrowTrack@motion@hulkfight@fn_00193e20@@QAEPAV1234@XZ @8a252dad3de3 @w9f463766bea0
namespace fn_00193e20 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00193e20 @ 0x00193e20


struct Base12 {
    char data[12];
    void FUN_00236d40();
};

namespace hulkfight {
namespace motion {
class MissileThrowTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    float f1c;
    float f20, f24, f28, f2c;
    float f30, f34, f38;
    int f3c, f40;
    float f44;

    MissileThrowTrack() {}
    MissileThrowTrack *FUN_00193e20();
};
}
}

hulkfight::motion::MissileThrowTrack *hulkfight::motion::MissileThrowTrack::FUN_00193e20()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) MissileThrowTrack;
    f0c = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = -1.0f;
    f3c = 0;
    f40 = 0;
    f20 = 10.0f;
    f24 = 100.0f;
    f28 = 10.0f;
    f2c = 100.0f;
    f30 = 0.17453294f;
    f34 = 1.7453293f;
    f38 = 1.5707964f;
    f44 = 0.8f;
    f08 = 1;
    return this;
}
} // namespace fn_00193e20


// 0x00193e90 hulkfight::motion::MissileThrowTrack::vfunc_6 (4 B): matches/0x00193e90.cpp
// sym: ?vfunc_6@MissileThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::MissileThrowTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00193ea0 hulkfight::motion::MissileThrowTrack::vfunc_7 (7 B): matches/0x00193ea0.cpp
// sym: ?vfunc_7@MissileThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::MissileThrowTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fc8c1e47 {

// 0x00193ec0 FUN_00193ec0 (19 B): matches/0x00193ec0.cpp
// sym: ?FUN_00193ec0@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00193ec0() {
    FUN_00234810(((char*)&DAT_004e1568), ((char*)&DAT_004e156c));
}

} // namespace fn_fc8c1e47

// 0x00193ee0 hulkfight::motion::MissilePunchTrack::vfunc_0 (16 B): matches/0x00193ee0.cpp
// sym: ?vfunc_0@MissilePunchTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MissilePunchTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1568;
    return p[index];
}

namespace fn_fc8c1e47 {

// 0x00193ef0 FUN_00193ef0 (54 B): matches/0x00193ef0.cpp
// sym: ??0MissilePunchTrack@fn_fc8c1e47@@QAE@XZ
MissilePunchTrack::MissilePunchTrack() : Track_193ef0(), a(0), b(-1.0f), c(6.2831855f), part() {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_fc8c1e47

// 0x00193f30 hulkfight::motion::MissilePunchTrack::vfunc_6 (4 B): matches/0x00193f30.cpp
// sym: ?vfunc_6@MissilePunchTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::MissilePunchTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00193f40 hulkfight::motion::MissilePunchTrack::vfunc_7 (7 B): matches/0x00193f40.cpp
// sym: ?vfunc_7@MissilePunchTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::MissilePunchTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

namespace fn_fc8c1e47 {

// 0x00193f50 FUN_00193f50 (25 B): matches/0x00193f50.cpp
// sym: ?Run@MissilePunchTrack_193f50@fn_fc8c1e47@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void MissilePunchTrack_193f50::Run() {
    vptr = &hulk_at_0041b2e8;
    ((Tail_193f50*)((char*)this + 0x18))->Init_00234150();
    Finish_00236d60();
}


// 0x00193f70 FUN_00193f70 (19 B): matches/0x00193f70.cpp
// sym: ?FUN_00193f70@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00193f70() {
    FUN_00234810(((char*)&DAT_004e1570), ((char*)&DAT_004e1574));
}

} // namespace fn_fc8c1e47

// 0x00193f90 hulkfight::motion::AccuracyLatencyTrack::vfunc_0 (16 B): matches/0x00193f90.cpp
// sym: ?vfunc_0@AccuracyLatencyTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AccuracyLatencyTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1570;
    return p[index];
}

namespace fn_fc8c1e47 {

// 0x00193fa0 FUN_00193fa0 (47 B): matches/0x00193fa0.cpp
// sym: ??0AccuracyLatencyTrack@fn_fc8c1e47@@QAE@XZ
AccuracyLatencyTrack::AccuracyLatencyTrack() : b(0), c(-1.0f), d(0), e(1.0f) {
    a = 1;
}

} // namespace fn_fc8c1e47

// 0x00193fd0 hulkfight::motion::AccuracyLatencyTrack::vfunc_6 (4 B): matches/0x00193fd0.cpp
// sym: ?vfunc_6@AccuracyLatencyTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AccuracyLatencyTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00193fe0 hulkfight::motion::AccuracyLatencyTrack::vfunc_7 (7 B): matches/0x00193fe0.cpp
// sym: ?vfunc_7@AccuracyLatencyTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AccuracyLatencyTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

namespace fn_fc8c1e47 {

// 0x00194000 FUN_00194000 (19 B): matches/0x00194000.cpp
// sym: ?FUN_00194000@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00194000() {
    FUN_00234810(((char*)&DAT_004e1578), ((char*)&DAT_004e157c));
}

} // namespace fn_fc8c1e47

// 0x00194020 hulkfight::motion::FireBeamTrack::vfunc_0 (16 B): matches/0x00194020.cpp
// sym: ?vfunc_0@FireBeamTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FireBeamTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1578;
    return p[index];
}


// 0x00194030 FUN_00194030 (433 B): equivalent/0x00194030.cpp [wrapped: conflict: hulkfight::motion::FireBeamTrack]
// sym: ?FUN_00194030@FireBeamTrack@motion@hulkfight@fn_00194030@@QAEPAV1234@XZ @b7d9b91c10c0 @w9c0682921966
namespace fn_00194030 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00194030 @ 0x00194030


struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_194030 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

namespace hulkfight {
namespace motion {
class FireBeamTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    char pad14[4];
    Name8_194030 n18;
    int f20, f24;
    float f28;
    int f2c;
    Name8_194030 n30;
    int f38, f3c, f40, f44, f48;
    float f4c, f50, f54, f58;
    int f5c;
    char b60;
    char pad61[3];
    float f64;
    int f68;
    char pad6c[4];
    Name8_194030 n70;
    int f78, f7c;
    float f80;
    Name12 n84;
    int f90;
    float f94, f98;
    char b9c;
    char pad9d[3];
    int fa0, fa4, fa8;
    char bac;
    char padad[3];
    Name12 nb0;
    char padbc[4];
    Name8_194030 nc0;
    int fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8;
    float fec;
    char bf0;
    char padf1[3];
    float ff4, ff8;
    char bfc, bfd, bfe;
    char padff;
    int f100, f104, f108, f10c, f110, f114;
    float f118;
    int f11c, f120, f124;
    float f128;
    char b12c;
    char pad12d[3];
    float f130, f134;

    FireBeamTrack() {}
    FireBeamTrack *FUN_00194030();
};
}
}

hulkfight::motion::FireBeamTrack *hulkfight::motion::FireBeamTrack::FUN_00194030()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) FireBeamTrack;
    f0c = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f2c = -1;
    n30.FUN_0027af00();
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = -1.0f;
    f50 = 20.0f;
    f54 = 1.5707964f;
    f58 = 100.0f;
    f5c = 0;
    b60 = 0;
    f64 = 3.0f;
    f68 = 0;
    n70.FUN_0027af00();
    f78 = 0;
    f7c = 0;
    f80 = -1.0f;
    n84.FUN_00233dd0();
    f90 = 0;
    f94 = 50.0f;
    f98 = 0.1f;
    b9c = 1;
    fa0 = 0;
    fa4 = 0;
    fa8 = 0;
    bac = 1;
    nb0.FUN_00233dd0();
    nc0.FUN_0027af00();
    fc8 = 0;
    fcc = 0;
    fd0 = 0;
    fd4 = 0;
    fd8 = 0;
    fdc = 0;
    fe0 = 0;
    fe4 = 0;
    fe8 = 0;
    bf0 = 0;
    ff4 = 1.5707964f;
    bfc = 0;
    bfd = 0;
    bfe = 0;
    fec = 1.0f;
    ff8 = 1.0f;
    f100 = 0;
    f104 = 0;
    f108 = 0;
    f10c = 0;
    f110 = 0;
    f114 = 0;
    f118 = 1.0f;
    f11c = 0;
    f120 = 0;
    f124 = 0;
    f128 = 1.0f;
    b12c = 0;
    f130 = 1.2f;
    f134 = 1.0f;
    f08 = 1;
    return this;
}
} // namespace fn_00194030


// 0x001941f0 hulkfight::motion::FireBeamTrack::vfunc_6 (4 B): matches/0x001941f0.cpp
// sym: ?vfunc_6@FireBeamTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FireBeamTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00194200 hulkfight::motion::FireBeamTrack::vfunc_7 (7 B): matches/0x00194200.cpp
// sym: ?vfunc_7@FireBeamTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FireBeamTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fc8c1e47 {

// 0x00194210 FUN_00194210 (74 B): matches/0x00194210.cpp
// sym: ?Reset@FireBeamTrack@fn_fc8c1e47@@QAEXXZ
void FireBeamTrack::Reset() {
    vptr = ((hulk_intptr)DAT_0041b348);
    f.Clear_0027af50();
    e.Clear_00234150();
    d.Clear_00234150();
    c.Clear_0027af50();
    b.Clear_0027af50();
    a.Clear_0027af50();
    Finish_00236d60();
}


// 0x00194260 FUN_00194260 (19 B): matches/0x00194260.cpp
// sym: ?FUN_00194260@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00194260() {
    FUN_00234810(((char*)&DAT_004e1580), ((char*)&DAT_004e1584));
}

} // namespace fn_fc8c1e47

// 0x00194280 hulkfight::motion::FireMissileTrack::vfunc_0 (16 B): matches/0x00194280.cpp
// sym: ?vfunc_0@FireMissileTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FireMissileTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1580;
    return p[index];
}


// 0x00194290 FUN_00194290 (480 B): equivalent/0x00194290.cpp [wrapped: conflict: hulkfight::motion::FireMissileTrack]
// sym: ??0FireMissileTrack@motion@hulkfight@fn_00194290@@QAE@XZ @88e24418ddf7 @w71f2714a0192
namespace fn_00194290 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00194290 @ 0x00194290
struct Sub8_194290 {
    unsigned int a, b;
    void FUN_0027af00();
};
struct Sub0C_194290 {
    unsigned int a, b, c;
    void FUN_00233dd0();
};

class __declspec(novtable) Track_194290 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_194290() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class FireMissileTrack : public Track_194290 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5_00194470();
    virtual void vfunc_6_00194480();
    virtual void vfunc_7();

    int f0c;
    Sub8_194290 s10;
    Sub8_194290 s18;
    Sub8_194290 s20;
    int f28, f2c;
    float f30;
    int f34;
    Sub8_194290 s38;
    int f40, f44, f48, f4c, f50;
    float f54;
    char f58;
    char pad59[3];
    float f5c, f60;
    int f64;
    float f68, f6c;
    int f70;
    char f74, f75, f76, f77;
    int f78;
    float f7c, f80;
    int f84;
    float f88, f8c;
    int f90;
    char f94, f95, f96;
    char pad97;
    int f98;
    float f9c, fa0, fa4, fa8, fac, fb0;
    int fb4, fb8;
    Sub0C_194290 sbc;
    Sub0C_194290 sc8;
    int fd4, fd8, fdc, fe0;
    int fe4_pad;
    Sub8_194290 se8;
    int ff0, ff4, ff8, ffc;
    Sub0C_194290 s100;
    int f10c, f110, f114, f118, f11c, f120, f124;
    Sub8_194290 s128;
    int f130, f134, f138, f13c, f140, f144;

    FireMissileTrack();
};
}
}

hulkfight::motion::FireMissileTrack::FireMissileTrack() {
    f0c = 0;
    s10.FUN_0027af00();
    s18.FUN_0027af00();
    s20.FUN_0027af00();
    f28 = 0;
    f2c = 0;
    f30 = -1.0f;
    f34 = -1;
    s38.FUN_0027af00();
    f40 = 0; f44 = 0; f48 = 0; f4c = 0; f50 = 0;
    f54 = -1.0f;
    f5c = 20.0f;
    f60 = 20.0f;
    f7c = 60.0f;
    fb0 = 60.0f;
    f58 = 0;
    f64 = 0;
    f68 = 1.5707964f;
    f6c = 100.0f;
    f70 = 0;
    f74 = 0; f75 = 0; f76 = 1; f77 = 0;
    f78 = 0;
    f80 = 0.7853982f;
    f84 = 0;
    f88 = 1.0f;
    f8c = 1.0f;
    f90 = 0;
    f94 = 0; f95 = 0; f96 = 0;
    f98 = 0;
    f9c = 3.1415927f;
    fa0 = 5.0f;
    fa4 = 6.981317f;
    fa8 = 10.0f;
    fac = 6.2831855f;
    fb4 = 5;
    fb8 = 0;
    sbc.FUN_00233dd0();
    sc8.FUN_00233dd0();
    fd4 = 0; fd8 = 0; fdc = 0; fe0 = 0;
    se8.FUN_0027af00();
    ff0 = 0; ff4 = 0; ff8 = 0; ffc = 0;
    s100.FUN_00233dd0();
    f10c = 0; f110 = 0; f114 = 0; f118 = 0; f11c = 0; f120 = 0; f124 = 0;
    s128.FUN_0027af00();
    f130 = 0; f134 = 0; f138 = 0; f13c = 0; f140 = 0; f144 = 0;
    pad08 = 1;
}
} // namespace fn_00194290


// 0x00194470 hulkfight::motion::FireMissileTrack::vfunc_6 (4 B): matches/0x00194470.cpp
// sym: ?vfunc_6@FireMissileTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FireMissileTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00194480 hulkfight::motion::FireMissileTrack::vfunc_7 (7 B): matches/0x00194480.cpp
// sym: ?vfunc_7@FireMissileTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::FireMissileTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fc8c1e47 {

// 0x00194490 FUN_00194490 (119 B): matches/0x00194490.cpp
// sym: ??1FireMissileTrack_194490@fn_fc8c1e47@@QAE@XZ
FireMissileTrack_194490::~FireMissileTrack_194490() throw() {
    vptr = hulk_at_0041b378;
    operator delete[](mdc);
    m128.Fini_0027af50();
    m100.Fini_00234150();
    me8.Fini_0027af50();
    mc8.Fini_00234150();
    mbc.Fini_00234150();
    m38.Fini_0027af50();
    m20.Fini_0027af50();
    m18.Fini_0027af50();
    m10.Fini_0027af50();
    Fin_00236d60();
}

} // namespace fn_fc8c1e47

// 0x00194510 FUN_00194510 (97 B): equivalent/0x00194510.cpp
// sym: ?FUN_00194510@Object_194510@owners@@QAEEPBD@Z @b0ce0be62dac @wb2dca91d21d9
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00194510 @ 0x00194510
unsigned char owners::Object_194510::FUN_00194510(const char* value) {
    FUN_0008d340(text);
    if (!value) { text = 0; return 1; }
    unsigned int length = 0;
    while (value[length]) ++length;
    text = (char*)FUN_0008d6d0(length + 1);
    char* dest = text;
    do { *dest++ = *value; } while (*value++);
    return 1;
}

namespace fn_fc8c1e47 {

// 0x00194580 FUN_00194580 (19 B): matches/0x00194580.cpp
// sym: ?FUN_00194580@fn_fc8c1e47@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00194580() {
    FUN_00234810(((char*)&DAT_004e1588), ((char*)&DAT_004e158c));
}

} // namespace fn_fc8c1e47

// 0x001945a0 hulkfight::motion::FireGroundShockwaveTrack::vfunc_0 (16 B): matches/0x001945a0.cpp
// sym: ?vfunc_0@FireGroundShockwaveTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FireGroundShockwaveTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1588;
    return p[index];
}


// 0x001945b0 FUN_001945b0 (220 B): equivalent/0x001945b0.cpp [wrapped: conflict: hulkfight::motion::FireGroundShockwaveTrack]
// sym: ??0FireGroundShockwaveTrack@motion@hulkfight@fn_001945b0@@QAE@XZ @5eb66809a769 @w463216ddaac1
namespace fn_001945b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001945b0 @ 0x001945b0
struct Name_1945b0 {
    unsigned int a, b;
    void FUN_0027af00();
};

struct Handle_1945b0 {
    char pad[16];
    void FUN_00233dd0();
};

class __declspec(novtable) Track_1945b0 {
public:
    virtual void b0();
    int pad04;
    int mode;
    void FUN_00236d40();
    Track_1945b0() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class FireGroundShockwaveTrack : public Track_1945b0 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10, f14, f18;
    int f1c, f20;
    float f24, f28, f2c;
    int f30;
    float f34, f38, f3c;
    Name_1945b0 name40;                    // 0x40
    int f48, f4c;
    float f50;
    int f54;
    float f58, f5c;
    int f60;
    float f64, f68;
    int f6c;
    float f70;
    int f74, f78, f7c, f80, f84, f88, f8c, f90, f94;
    Handle_1945b0 handle98;                // 0x98
    Name_1945b0 nameA8;                    // 0xa8

    FireGroundShockwaveTrack();
};
} }

hulkfight::motion::FireGroundShockwaveTrack::FireGroundShockwaveTrack()
{
    f0c = 0;
    f10 = 0.0f;
    f14 = 1.0f;
    f18 = -1.0f;
    f1c = 0;
    f20 = 0;
    f24 = -1.0f;
    f28 = 10.0f;
    f2c = 1.0f;
    f30 = 10;
    f34 = 5.0f;
    f38 = 5.0f;
    f3c = 1.0f;
    name40.FUN_0027af00();
    f48 = 0;
    f4c = 0;
    f50 = -1.0f;
    f54 = 0;
    f58 = 1.0f;
    f5c = 1.0f;
    f60 = 0;
    f64 = 5.0f;
    f68 = 3.1415927410125732f;
    f6c = 3;
    f70 = 1.0f;
    f74 = 0; f78 = 0; f7c = 0; f80 = 0; f84 = 0; f88 = 0; f8c = 0; f90 = 0; f94 = 0;
    handle98.FUN_00233dd0();
    nameA8.FUN_0027af00();
    mode = 1;
}
} // namespace fn_001945b0


// 0x00194690 hulkfight::motion::FireGroundShockwaveTrack::vfunc_6 (4 B): matches/0x00194690.cpp
// sym: ?vfunc_6@FireGroundShockwaveTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FireGroundShockwaveTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001946a0 hulkfight::motion::FireGroundShockwaveTrack::vfunc_7 (7 B): matches/0x001946a0.cpp
// sym: ?vfunc_7@FireGroundShockwaveTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::FireGroundShockwaveTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_fc8c1e47 {

// 0x001946b0 FUN_001946b0 (47 B): matches/0x001946b0.cpp
// sym: ?FUN_001946b0@fn_fc8c1e47@@YIXPAUFireGroundShockwaveTrack@1@PAX@Z
void __fastcall FUN_001946b0(FireGroundShockwaveTrack* p, void*) {
    *(void**)p = (void*)((hulk_intptr)DAT_0041b3a8);
    initA_0027af50((char*)p + 0xa8);
    initB_00234150((char*)p + 0x98);
    initA_0027af50((char*)p + 0x40);
    finish_00236d60(p);
}

} // namespace fn_fc8c1e47

// 0x00194720 FUN_00194720 (33 B): matches/0x00194720.cpp
// sym: ?FUN_00194720@C_194720@owners@@QAEXPAH@Z
void owners::C_194720::FUN_00194720(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}

namespace fn_fc8c1e47 {

// 0x001947a0 FUN_001947a0 (505 B): equivalent/0x001947a0.cpp
// sym: _FUN_001947a0 @ac654a4fa39f @wa374d29a513f
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 16/16)
// FUN_001947a0 @ 0x001947a0
// Random walk step: the position arrives in esi, the walker and the step size on the stack.
// equiv-conv: FUN_001947a0 esi stack stack
extern "C" void FUN_001947a0(Vec3_1947a0* pos, Wanderer* w, float step)
{
    RandState_1947a0* rng = FUN_000964d0();
    int dir = w->direction;
    if (dir == 1 || dir == 0) {
        rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
        rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
        dir = (int)(((rng->s0 << 16) + (rng->s1 & 0xffff)) % 10) + 2;
    }
    w->steps--;
    float r;
    switch (dir) {
    case 2:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        break;
    case 3:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        break;
    case 4:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        break;
    case 5:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        break;
    case 6:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        break;
    case 7:
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        break;
    case 8:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z + r;
        break;
    case 9:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        r = rng->FUN_000787e0(step, step);
        pos->z = pos->z - r;
        break;
    case 10:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x + r;
        break;
    case 11:
        r = rng->FUN_000787e0(step, step);
        pos->x = pos->x - r;
        break;
    default:
        break;
    }
    w->direction = dir;
}

} // namespace fn_fc8c1e47

// 0x001949d0 hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_6 (235 B): equivalent/0x001949d0.cpp [wrapped: conflict: hulkfight::motion::PropGrabbableIsMissileCondition]
// sym: ?vfunc_6@PropGrabbableIsMissileCondition@motion@hulkfight@fn_001949d0@@UAE_NPAXPAUActor_1949d0@4@0@Z @57a1735bd23a @we6e1448a13e2
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001949d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 24/24)
// hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_6 @ 0x001949d0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern char DAT_00494b44, DAT_00494b60, DAT_004bfe10, DAT_004bfe2c;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Held { char pad[8]; void* object; int kind; };
struct State_1949d0 { char pad[0x3a4]; Held* held; };
struct Intermediate_1949d0 { State_1949d0* FUN_00059a30(); };
struct Actor_1949d0 { Intermediate_1949d0* FUN_000592a0(); };
struct Entry_1949d0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void* slot5(); };
struct Manager_1949d0 { Entry_1949d0* FUN_001b68e0(int); };
struct World { char pad[0x14]; Manager_1949d0* manager; };
namespace hulkfight { namespace motion {
struct PropGrabbableIsMissileCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Actor_1949d0*,void*);
char pad[8]; unsigned char expected;
};
bool PropGrabbableIsMissileCondition::vfunc_6(void*, Actor_1949d0* actor, void*) {
if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Held* held = actor->FUN_000592a0()->FUN_00059a30()->held;
if (!held || held->kind != 5) return expected == 0;
void* object=held->object;
if (!object) return expected == 0;
Manager_1949d0* manager=DAT_004dd700->manager;
for (int i=0;i<32;++i) {
Entry_1949d0* entry=manager->FUN_001b68e0(i);
if (entry && entry->slot5()==object) {
void* casted=FUN_00344e74(entry,0,&DAT_004bfe10,&DAT_004bfe2c,0);
return expected == (casted != 0);
}
}
return expected == 0;
}
}}
} // namespace fn_001949d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00194ac0 hulkfight::motion::PropIsMissileCondition::vfunc_6 (209 B): matches/0x00194ac0.cpp [wrapped: conflict: World; hulkfight::motion::PropIsMissileCondition]
// sym: ?vfunc_6@PropIsMissileCondition@motion@hulkfight@fn_00194ac0@@UAE_NPAXPAUActor_194ac0@4@0@Z
namespace fn_00194ac0 {
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

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
} // namespace fn_00194ac0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00194ba0 hulkfight::motion::ProjectileMissile::vfunc_5 (21 B): equivalent/0x00194ba0.cpp [wrapped: conflict: World; hulkfight::motion::ProjectileMissile]
// sym: ?vfunc_5@ProjectileMissile@motion@hulkfight@fn_00194ba0@@QAEXXZ @b1b849f3e649 @w9272e9b79d5d
namespace fn_00194ba0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// hulkfight::motion::ProjectileMissile::vfunc_5 @ 0x00194ba0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct MissileManager { void FUN_001dc0d0(void *missile); };
struct World { char pad[12]; MissileManager *manager; };
namespace hulkfight { namespace motion {
struct ProjectileMissile {
    char pad[0x40];
    void *missile;
    void vfunc_5();
};
void ProjectileMissile::vfunc_5() {
    DAT_004dd700->manager->FUN_001dc0d0(missile);
}
}}
} // namespace fn_00194ba0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00194bd0 hulkfight::motion::AccuracyLatencyAction::vfunc_3 (217 B): equivalent/0x00194bd0.cpp [wrapped: conflict: World; hulkfight::motion::AccuracyLatencyAction]
// sym: ?vfunc_3@AccuracyLatencyAction@motion@hulkfight@fn_00194bd0@@UAE_NIM@Z @2b1a4ac7d0e0 @w852e8173baaf
namespace fn_00194bd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// hulkfight::motion::AccuracyLatencyAction::vfunc_3 @ 0x00194bd0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec_194bd0 { float x,y,z; };
struct Position_194bd0 { void FUN_00059a50(Vec_194bd0*); };
struct Entry_194bd0 { char pad[16]; Position_194bd0* position; };
struct Link_194bd0 { char pad[8]; Entry_194bd0* entry; int type; };
struct Actor_194bd0 { char pad[0x328]; Link_194bd0* link; char pad2[0x1d60-0x32c]; unsigned idLow,idHigh; void FUN_00194720(Vec_194bd0*); };
struct Object { Actor_194bd0* FUN_00059a30(); };
struct Source_194bd0 { Object* FUN_000592a0(); };
struct Manager_194bd0 { Entry_194bd0* FUN_00024280(unsigned,unsigned); };
struct World { char pad[0x20]; Manager_194bd0* manager; };
namespace hulkfight { namespace motion {
struct AccuracyLatencyAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned, float); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c]; Source_194bd0* source; float time; float lastTime; float latency;
};
bool AccuracyLatencyAction::vfunc_3(unsigned unused, float t) {
 if (!source) return false;
 Object* obj=source->FUN_000592a0();
 Actor_194bd0* actor=obj->FUN_00059a30();
 if (!obj || !actor) return false;
 lastTime=t;
 time=t+latency;
 Entry_194bd0* entry;
 if (actor->link && actor->link->type==1) {
  entry=actor->link->entry;
  if (!entry) return true;
 } else {
  unsigned lo=actor->idLow, hi=actor->idHigh;
  if (!(lo|hi)) return true;
  entry=DAT_004dd700->manager->FUN_00024280(lo,hi);
  if (!entry) return true;
 }
 Vec_194bd0 v;
 entry->position->FUN_00059a50(&v);
 actor->FUN_00194720(&v);
 return true;
}
}}
} // namespace fn_00194bd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00194cb0 hulkfight::motion::AccuracyLatencyAction::vfunc_4 (129 B): equivalent/0x00194cb0.cpp
// sym: ?vfunc_4@AccuracyLatencyAction@motion@hulkfight@@UAEXXZ @8b456efe7435 @w97720cfd2788
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// hulkfight::motion::AccuracyLatencyAction::vfunc_4 @ 0x00194cb0
void hulkfight::motion::AccuracyLatencyAction::vfunc_4() {
    PlayerRef_194cb0 *ref = ((PlayerRef_194cb0 *)((owners::Object_592a0 *)((*(Owner_194cb0 * *)&this->f_20)))->FUN_000592a0());
    Player_194cb0 *player = ref->FUN_00059a30();

    // function-local static zero vector
    if (!(DAT_004e15bc & 1)) {
        DAT_004e15bc |= 1;
        DAT_004e15b0 = 0;
        DAT_004e15b4 = 0;
        DAT_004e15b8 = 0;
    }

    if (ref != 0 && player != 0) {
        player->aimX = DAT_004e15b0;
        player->aimY = DAT_004e15b4;
        player->aimZ = DAT_004e15b8;
        player->aimW = 0;
        player->aimV = 0;
    }
}


// 0x00194d40 hulkfight::motion::ProjectileGroundShockwave::vfunc_3 (68 B): matches/0x00194d40.cpp
// sym: ?vfunc_3@ProjectileGroundShockwave@motion@hulkfight@@UAEPAXXZ
void* hulkfight::motion::ProjectileGroundShockwave::vfunc_3() {
    if (!(*(Obj * *)&this->f_24)) {
        static Vec zero;
        return (void*)(&zero);
    }
    return (void*)(&(*(Obj * *)&this->f_24)->v);
}


// 0x00194d90 hulkfight::motion::MissilePunchAction::vfunc_3 (54 B): matches/0x00194d90.cpp
// sym: ?vfunc_3@MissilePunchAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::MissilePunchAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!(*(Obj_194d90 * *)&this->f_20))
        return (bool)(0);
    Obj_194d90* x = ((Obj_194d90 *)((owners::Object_592a0 *)((*(Obj_194d90 * *)&this->f_20)))->FUN_000592a0());
    x = x->HelperB_00059a30();
    Obj_194d90* y = (*(Obj_194d90 * *)&this->f_1c);
    x->DoWork_0003b580(1, *(u32_194d90*)((char*)y + 0x14), *(u32_194d90*)((char*)y + 0x18));
    return (bool)(1);
}


// 0x00194dd0 hulkfight::motion::MissilePunchAction::vfunc_4 (33 B): matches/0x00194dd0.cpp
// sym: ?vfunc_4@MissilePunchAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::MissilePunchAction::vfunc_4() {
    if ((*(void * *)&this->f_20)) {
        ObjC_194dd0* c = ((ObjB_194dd0 *)((owners::Object_592a0 *)(((ObjA_194dd0*)(*(void * *)&this->f_20))))->FUN_000592a0())->Fng_00059a30();
        c->Fnh_0003b580(0, 0, 0);
    }
}

namespace fn_fc8c1e47 {

// 0x00194ee0 hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_5 (36 B): matches/0x00194ee0.cpp
// sym: ?vfunc_5@PropGrabbableIsMissileCondition_194ee0@fn_fc8c1e47@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PropGrabbableIsMissileCondition_194ee0* PropGrabbableIsMissileCondition_194ee0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041b248;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00194f10 hulkfight::motion::PropIsMissileCondition::vfunc_5 (36 B): matches/0x00194f10.cpp
// sym: ?vfunc_5@PropIsMissileCondition_194f10@fn_fc8c1e47@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PropIsMissileCondition_194f10* PropIsMissileCondition_194f10::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041b268;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00194f40 hulkfight::motion::FireProjectileTrack::vfunc_5 (87 B): matches/0x00194f40.cpp
// sym: ?vfunc_5@FireProjectileTrack@fn_fc8c1e47@@UAEPAV12@E@Z
FireProjectileTrack* FireProjectileTrack::vfunc_5(unsigned char flag) {
    *(hulk_intptr*)this = (hulk_intptr)&g_FireProjectileTrackVtable;
    ma8.~Pa8();
    m9c.~P9c();
    m88.~P88();
    m38.~P38();
    m18.~P18_194f40();
    this->Track::~Track();
    if ((flag & 1) != 0)
        FUN_0008d330(this);
    return this;
}


// 0x00194fa0 hulkfight::motion::MissileThrowTrack::vfunc_5 (36 B): matches/0x00194fa0.cpp
// sym: ?vfunc_5@MissileThrowTrack_194fa0@fn_fc8c1e47@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
MissileThrowTrack_194fa0* MissileThrowTrack_194fa0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041b2b8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc8c1e47

// 0x00194fd0 hulkfight::motion::MissilePunchTrack::vfunc_5 (46 B): matches/0x00194fd0.cpp [wrapped: conflict: MissilePunchTrack]
// sym: ?vfunc_5@MissilePunchTrack@fn_00194fd0@@UAEPAV12@H@Z
namespace fn_00194fd0 {
class Sub_194fd0 {
  public:
    void Init_00234150();
};
class MissilePunchTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual MissilePunchTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    Sub_194fd0 sub;
    void Setup_00236d60();
};
extern int missileVftable;
extern void Cleanup_0008d330(MissilePunchTrack*);
MissilePunchTrack* MissilePunchTrack::vfunc_5(int flag) {
    *(hulk_intptr*)this = (hulk_intptr)&missileVftable;
    sub.Init_00234150();
    Setup_00236d60();
    if (flag & 1)
        Cleanup_0008d330(this);
    return this;
}
} // namespace fn_00194fd0

namespace fn_fc8c1e47 {

// 0x00195000 hulkfight::motion::AccuracyLatencyTrack::vfunc_5 (36 B): matches/0x00195000.cpp
// sym: ?vfunc_5@AccuracyLatencyTrack_195000@fn_fc8c1e47@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
AccuracyLatencyTrack_195000* AccuracyLatencyTrack_195000::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041b318;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc8c1e47

// 0x00195030 hulkfight::motion::FireBeamTrack::vfunc_5 (95 B): matches/0x00195030.cpp [wrapped: conflict: FireBeamTrack]
// sym: ?vfunc_5@FireBeamTrack@fn_00195030@@QAEPAV12@E@Z
namespace fn_00195030 {
class Obj_195030 {
  public:
    void init27_0027af50();
    void init23_00234150();
};
class TrackPart {
  public:
    void init36_00236d60();
};
class FireBeamTrack {
  public:
    hulk_intptr vptr;
    char pad[0xbc];
    FireBeamTrack* vfunc_5(unsigned char);
};
void destroy_0008d330(FireBeamTrack*);
extern int hulk_at_0041b348;
FireBeamTrack* FireBeamTrack::vfunc_5(unsigned char flag) {
    vptr = (hulk_intptr)&hulk_at_0041b348;
    ((Obj_195030*)((char*)this + 0xc0))->init27_0027af50();
    ((Obj_195030*)((char*)this + 0xb0))->init23_00234150();
    ((Obj_195030*)((char*)this + 0x84))->init23_00234150();
    ((Obj_195030*)((char*)this + 0x70))->init27_0027af50();
    ((Obj_195030*)((char*)this + 0x30))->init27_0027af50();
    ((Obj_195030*)((char*)this + 0x18))->init27_0027af50();
    ((TrackPart*)this)->init36_00236d60();
    if (flag & 1)
        destroy_0008d330(this);
    return this;
}
} // namespace fn_00195030


// 0x00195090 hulkfight::motion::FireMissileTrack::vfunc_5 (30 B): matches/0x00195090.cpp
// sym: ??_GFireMissileTrack@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::FireMissileTrack::~FireMissileTrack() {}

namespace fn_fc8c1e47 {

// 0x001950b0 hulkfight::motion::FireGroundShockwaveTrack::vfunc_5 (68 B): matches/0x001950b0.cpp
// sym: ?vfunc_5@FireGroundShockwaveTrack@fn_fc8c1e47@@QAEPAU12@E@Z
FireGroundShockwaveTrack* FireGroundShockwaveTrack::vfunc_5(unsigned char flag) {
    vt = (void*)((hulk_intptr)DAT_0041b3a8);
    ((Part_1950b0*)((char*)this + 0xa8))->init_0027af50();
    ((Part2_1950b0*)((char*)this + 0x98))->init2_00234150();
    ((Part_1950b0*)((char*)this + 0x40))->init_0027af50();
    baseInit_00236d60();
    if (flag & 1)
        destroy_0008d330(this);
    return this;
}

} // namespace fn_fc8c1e47
