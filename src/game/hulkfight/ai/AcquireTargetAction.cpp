// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00124090..0x00124e60 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f712cb17 {
#define TREE_TU_END }
namespace fn_f712cb17 {} using namespace fn_f712cb17;
namespace fn_f712cb17 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
namespace fn_f712cb17 { extern "C" char DAT_0040fd34[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f712cb17 {
extern int* hulk_at_004e0dcc;
class CCondition_124090 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0dd4;
class CCondition_124100 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0ddc;
class CCondition_124170 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0de4;
class CCondition_1241e0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0dec;
class CCondition_124240 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0df4;
class CCondition_1242a0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0dfc;
class CCondition_124300 {
  public:
    virtual int vfunc_0(int);
};
class Track_124310 {
  public:
    Track_124310();
    virtual hulk_intptr FnA_00124300(int);
    char pad[4];
    int m8;
};
class TargetClearTrack : public Track_124310 {
  public:
    TargetClearTrack();
    int m_c;
    char m_10;
};
extern int* hulk_at_004e0e04;
class CCondition_124390 {
  public:
    virtual int vfunc_0(int);
};
struct Param_1243f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1243f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0e0c;
class CCondition_124430 {
  public:
    virtual int vfunc_0(int);
};
class Track_124440 {
  public:
    Track_124440();
    virtual hulk_intptr Fnf_00124430(int);
    char pad[4];
};
class ClearProjectileDistanceTrack : public Track_124440 {
  public:
    ClearProjectileDistanceTrack();
    int a;
    int b;
    float d;
    char flag;
};
struct Param_124480 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_124480 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Params_124540 {
    virtual void f();
};
struct Ent_124540 {
    char p[0x328];
    int target;
};
struct Holder_124540 {};
struct Condition_124540 {
    virtual void a();
};
struct Base2 {
    virtual void b();
};
struct T1 {
    virtual void f();
};
struct T2 {
    virtual void f();
};
extern T1 hulk_at_00494b44;
extern T2 hulk_at_00494b60;
Holder_124540* __fastcall G1_000592a0(Params_124540*);
Ent_124540* __fastcall G2_00059a30(Holder_124540*);
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
struct Vec3_1245b0 {
    float x, y, z;
};
struct Unit_1245b0 {
    char pad0[0x1b0];
    int id;                  // 0x1b0
};
struct Weapon_1245b0 {
    char pad0[0x1b0c];
    float charge;            // 0x1b0c
};
struct Target_1245b0 {
    char pad0[8];
    Weapon_1245b0 *weapon;          // 0x08
    int kind;                // 0x0c
};
struct Actor_1245b0;
struct Player_1245b0 {
    char pad0[0x11c];
    Unit_1245b0 *unit;              // 0x11c
    char pad120[0x12c - 0x120];
    Actor_1245b0 *other;            // 0x12c
};
struct Actor_1245b0 {
    char pad0[0x11c];
    Unit_1245b0 *unit;              // 0x11c
    char pad120[0x328 - 0x120];
    Target_1245b0 *target;          // 0x328
    char pad32c[0x1b48 - 0x32c];
    char active;             // 0x1b48
    char pad1b49[0x20a8 - 0x1b49];
    int state;               // 0x20a8
    void FUN_0003ffa0(void *a, void *b);
    void FUN_00035dc0(Vec3_1245b0 *out);
    char FUN_000350c0(Vec3_1245b0 *out);
    void FUN_000400e0(Vec3_1245b0 *a, Vec3_1245b0 *b, int c, int d, unsigned int flags);
    void FUN_0003a520(Vec3_1245b0 *a, Vec3_1245b0 *b, int c, int d);
};
struct Chain_1245b0 {
    Actor_1245b0 *FUN_00059a30();
};
struct Owner_1245b0 {
};
struct Globals_1245b0 {
    char pad0[0x20];
    Actor_1245b0 *player;           // 0x20 (struct with +0x124 pointer actually)
};
struct Holder_1245b0 {
    char pad0[0x124];
    Actor_1245b0 *actor;            // 0x124
};
} // namespace fn_f712cb17
struct World {
    char pad0[0x20];
    Holder_1245b0 *holder;          // 0x20
};
namespace fn_f712cb17 {
class AcquireTargetCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_1245b0 *owner, int unused3);
    char pad4[8];
    int argA;                // 0x0c
    int argB;                // 0x10
    char flag;               // 0x14
};
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
struct Kind_124750 {
    char pad0[0xc];
    int kind;               // 0x0c
};
struct Mixer_124750 {
    char pad0[0x328];
    Kind_124750* target;           // 0x328
};
struct Context_124750 {
    Mixer_124750* FUN_00059a30();
};
struct Entity_124750 {
};
struct Invincible {
    char FUN_00036170();
};
struct Body_1249b0 {
    char pad0[8];
    Invincible *invincible;
    int state;
};
struct Res_1249b0 {
    char pad00[0x328];
    Body_1249b0 *body;
};
struct Resolver_1249b0 {
    Res_1249b0 *FUN_00059a30();
};
struct Target_1249b0 {
};
class Condition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
class Param {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class TargetFirstShotCondition : public Condition, public Param {
  public:
    virtual void vfunc_0();
    virtual void vfunc_5();
    virtual unsigned char vfunc_6(void*, void*, void*);
};
extern int RTTI_Params_124a30;
extern int RTTI_CFightParams_124a30;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Actor_124a30 {
    char pad[0x1b74];
    unsigned char flag;
};
struct Obj_124a30 {
};
struct ActorRef {
    int FUN_00059a30();
};
struct B_124cb0 {
    int h();
    void Fnj_0003ee50();
};
struct A_124cb0 {
    B_124cb0* Fng_00059a30();
};
class Helper_124ce0 {
  public:
    Helper_124ce0* Next_00059a30();
    int Check();
    void Act_0003ee50();
};
class Obj_124d20;
class Actor_124d20 {
  public:
    char pad[0x10];
    char flag;
};
class Obj_124d20 {
  public:
    Obj_124d20* Check_00059a30();
    void Apply_0003ffa0(int a, int b);
    char pad[0x32c];
    char flag;
};
extern void* hulk_at_0040fd14[];
class Condition_124dd0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetDirectionYCondition_124dd0 : public Condition_124dd0 {
  public:
    TargetDirectionYCondition_124dd0* vfunc_5(signed char flags);
};
struct Sub_124e00 {
    void* v;
    void Fin_0027af50();
};
class Condition_124e00 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class TargetArcCondition_124e00 : public Condition_124e00 {
  public:
    char pad[0x18 - 4];
    Sub_124e00 sub;
    TargetArcCondition_124e00* f5(unsigned char flags);
};
extern void* hulk_at_0040fd54[];
class Condition_124e30 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class TargetTypeCondition_124e30 : public Condition_124e30 {
  public:
    TargetTypeCondition_124e30* vfunc_5(signed char flags);
};

} // namespace fn_f712cb17

// 0x00124090 hulkfight::ai::AcquireTargetCondition::vfunc_0 (16 B): matches/0x00124090.cpp
// sym: ?vfunc_0@AcquireTargetCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::AcquireTargetCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0dcc;
    return p[index];
}

namespace fn_f712cb17 {

// 0x001240e0 FUN_001240e0 (19 B): matches/0x001240e0.cpp
// sym: ?FUN_001240e0@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001240e0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dd4), ((char*)&DAT_004e0dd8));
}

} // namespace fn_f712cb17

// 0x00124100 hulkfight::ai::TargetVelocityXZCondition::vfunc_0 (16 B): matches/0x00124100.cpp
// sym: ?vfunc_0@TargetVelocityXZCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetVelocityXZCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0dd4;
    return p[index];
}

namespace fn_f712cb17 {

// 0x00124150 FUN_00124150 (19 B): matches/0x00124150.cpp
// sym: ?FUN_00124150@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124150(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0ddc), ((char*)&DAT_004e0de0));
}

} // namespace fn_f712cb17

// 0x00124170 hulkfight::ai::TargetDirectionXZCondition::vfunc_0 (16 B): matches/0x00124170.cpp
// sym: ?vfunc_0@TargetDirectionXZCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetDirectionXZCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0ddc;
    return p[index];
}

namespace fn_f712cb17 {

// 0x001241c0 FUN_001241c0 (19 B): matches/0x001241c0.cpp
// sym: ?FUN_001241c0@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001241c0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0de4), ((char*)&DAT_004e0de8));
}

} // namespace fn_f712cb17

// 0x001241e0 hulkfight::ai::TargetFirstShotCondition::vfunc_0 (16 B): matches/0x001241e0.cpp
// sym: ?vfunc_0@TargetFirstShotCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetFirstShotCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0de4;
    return p[index];
}

namespace fn_f712cb17 {

// 0x00124220 FUN_00124220 (19 B): matches/0x00124220.cpp
// sym: ?FUN_00124220@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124220(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dec), ((char*)&DAT_004e0df0));
}

} // namespace fn_f712cb17

// 0x00124240 hulkfight::ai::TargetInvincibleCondition::vfunc_0 (16 B): matches/0x00124240.cpp
// sym: ?vfunc_0@TargetInvincibleCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetInvincibleCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0dec;
    return p[index];
}

namespace fn_f712cb17 {

// 0x00124280 FUN_00124280 (19 B): matches/0x00124280.cpp
// sym: ?FUN_00124280@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124280(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0df4), ((char*)&DAT_004e0df8));
}

} // namespace fn_f712cb17

// 0x001242a0 hulkfight::ai::CanSeeTargetCondition::vfunc_0 (16 B): matches/0x001242a0.cpp
// sym: ?vfunc_0@CanSeeTargetCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::CanSeeTargetCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0df4;
    return p[index];
}

namespace fn_f712cb17 {

// 0x001242e0 FUN_001242e0 (19 B): matches/0x001242e0.cpp
// sym: ?FUN_001242e0@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001242e0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dfc), ((char*)&DAT_004e0e00));
}

} // namespace fn_f712cb17

// 0x00124300 hulkfight::ai::TargetClearTrack::vfunc_0 (16 B): matches/0x00124300.cpp
// sym: ?vfunc_0@TargetClearTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetClearTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0dfc;
    return p[index];
}

namespace fn_f712cb17 {

// 0x00124310 FUN_00124310 (33 B): matches/0x00124310.cpp
// sym: ??0TargetClearTrack@fn_f712cb17@@QAE@XZ
TargetClearTrack::TargetClearTrack() {
    *(volatile int*)((char*)&this->m_c) = 0;
    *(volatile char*)((char*)&this->m_10) = 0;
    *(volatile int*)((char*)&this->m8) = 1;
}

} // namespace fn_f712cb17

// 0x00124340 hulkfight::ai::TargetClearTrack::vfunc_6 (4 B): matches/0x00124340.cpp
// sym: ?vfunc_6@TargetClearTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::TargetClearTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00124350 hulkfight::ai::TargetClearTrack::vfunc_7 (7 B): matches/0x00124350.cpp
// sym: ?vfunc_7@TargetClearTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::ai::TargetClearTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f712cb17 {

// 0x00124370 FUN_00124370 (19 B): matches/0x00124370.cpp
// sym: ?FUN_00124370@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124370(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0e04), ((char*)&DAT_004e0e08));
}

} // namespace fn_f712cb17

// 0x00124390 hulkfight::ai::AcquireTargetTrack::vfunc_0 (16 B): matches/0x00124390.cpp
// sym: ?vfunc_0@AcquireTargetTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::AcquireTargetTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e04;
    return p[index];
}


// 0x001243a0 FUN_001243a0 (64 B): equivalent/0x001243a0.cpp [wrapped: conflict: hulkfight::ai::AcquireTargetTrack]
// sym: ??0AcquireTargetTrack@ai@hulkfight@fn_001243a0@@QAE@XZ @d2ee33c05c8e @wcf529dfdabab
namespace fn_001243a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001243a0 @ 0x001243a0
struct FUN_00236d40 {
    virtual hulk_intptr slot0_00124390(int);
    char data[8];
    FUN_00236d40();
};
namespace hulkfight { namespace ai {
struct AcquireTargetTrack : FUN_00236d40 {
    int state;
    float minimum;
    float angle;
    float distance;
    bool enabled;
    char pad[3];
    int value20;
    int value24;
    float value28;
    AcquireTargetTrack();
};
} }
hulkfight::ai::AcquireTargetTrack::AcquireTargetTrack() : FUN_00236d40() {
    state = 0;
    enabled = false;
    minimum = -1.0f;
    angle = 6.2831855f;
    distance = 100.0f;
    value20 = 0;
    value24 = 0;
    value28 = -1.0f;
    *(int*)(data + 4) = 1;
}
} // namespace fn_001243a0


// 0x001243e0 hulkfight::ai::AcquireTargetTrack::vfunc_6 (4 B): matches/0x001243e0.cpp
// sym: ?vfunc_6@AcquireTargetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::AcquireTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001243f0 hulkfight::ai::AcquireTargetTrack::vfunc_7 (7 B): matches/0x001243f0.cpp
// sym: ?vfunc_7@AcquireTargetTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::AcquireTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f712cb17 {

// 0x00124410 FUN_00124410 (19 B): matches/0x00124410.cpp
// sym: ?FUN_00124410@fn_f712cb17@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124410(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0e0c), ((char*)&DAT_004e0e10));
}

} // namespace fn_f712cb17

// 0x00124430 hulkfight::ai::ClearProjectileDistanceTrack::vfunc_0 (16 B): matches/0x00124430.cpp
// sym: ?vfunc_0@ClearProjectileDistanceTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ClearProjectileDistanceTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e0c;
    return p[index];
}

namespace fn_f712cb17 {

// 0x00124440 FUN_00124440 (40 B): matches/0x00124440.cpp
// sym: ??0ClearProjectileDistanceTrack@fn_f712cb17@@QAE@XZ
ClearProjectileDistanceTrack::ClearProjectileDistanceTrack() {
    b = 0;
    flag = 0;
    d = -1.0f;
    a = 1;
}

} // namespace fn_f712cb17

// 0x00124470 hulkfight::ai::ClearProjectileDistanceTrack::vfunc_6 (4 B): matches/0x00124470.cpp
// sym: ?vfunc_6@ClearProjectileDistanceTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::ClearProjectileDistanceTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00124480 hulkfight::ai::ClearProjectileDistanceTrack::vfunc_7 (7 B): matches/0x00124480.cpp
// sym: ?vfunc_7@ClearProjectileDistanceTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::ClearProjectileDistanceTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x00124500 FUN_00124500 (33 B): matches/0x00124500.cpp
// sym: ?FUN_00124500@X_124500@owners@@QAEXPAH@Z
void owners::X_124500::FUN_00124500(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}


// 0x00124540 hulkfight::ai::HasTargetCondition::vfunc_6 (97 B): matches/0x00124540.cpp
// sym: ?vfunc_6@HasTargetCondition@ai@hulkfight@@UAE_NPAX00@Z
bool hulkfight::ai::HasTargetCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; Params_124540 * p = (Params_124540 *)__p1; int b = (int)__p2;

    if (!DynCast(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0))
        return false;
    int t = G2_00059a30(G1_000592a0(p))->target;
    if (this->f_0c)
        return t != 0;
    return t == 0;
}

namespace fn_f712cb17 {

// 0x001245b0 hulkfight::ai::AcquireTargetCondition::vfunc_6 (410 B): equivalent/0x001245b0.cpp
// sym: ?vfunc_6@AcquireTargetCondition@fn_f712cb17@@UAEDHPAUOwner_1245b0@2@H@Z @7b165c989211 @w08624b289e7b
// STATUS: equivalent (tools/equiv.py level 3: 12028 inputs, branch coverage 34/34; run with --inputs 12000)
// hulkfight::ai::AcquireTargetCondition::vfunc_6 @ 0x001245b0
char AcquireTargetCondition::vfunc_6(int unused1, Owner_1245b0 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor_1245b0 *self = ((Chain_1245b0 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    Target_1245b0 *target = self->target;
    Actor_1245b0 *other = DAT_004dd700->holder->actor;

    if (!target && self->state < 0 && self->unit && other) {
        Actor_1245b0 *otherTarget = *(Actor_1245b0 **)((char *)other + 0x12c);
        Unit_1245b0 *otherUnit = other->unit;
        if (otherTarget && otherUnit && self->unit->id != otherUnit->id) {
            self->FUN_0003ffa0(otherTarget, 0);
            return 1;
        }
    }

    Vec3_1245b0 v1;
    v1.x = 0; v1.y = 0; v1.z = 0;
    self->FUN_00035dc0(&v1);
    Vec3_1245b0 v2;
    v2.x = 0; v2.y = 0; v2.z = 0;
    if (!self->FUN_000350c0(&v2))
        return 0;

    if (!target) {
        self->FUN_000400e0(&v2, &v1, argA, argB, 0x80000000);
    } else {
        if (self->active && self != other && target->weapon && target->kind == 1
            && target->weapon->charge <= 0.0f) {
            self->active = 0;
            self->FUN_0003ffa0(0, 0);
            return 0;
        }
        if (flag)
            self->FUN_0003a520(&v2, &v1, argA, argB);
    }
    return self->target != 0;
}

} // namespace fn_f712cb17

// 0x00124750 hulkfight::ai::TargetTypeCondition::vfunc_6 (127 B): equivalent/0x00124750.cpp
// sym: ?vfunc_6@TargetTypeCondition@ai@hulkfight@@UAE_NPAX00@Z @28faa266b339 @wd4eb2e1b0a46
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 16/16)
// hulkfight::ai::TargetTypeCondition::vfunc_6 @ 0x00124750
bool hulkfight::ai::TargetTypeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; Entity_124750 * entity = (Entity_124750 *)__p1; int unused2 = (int)__p2;

    if (!FUN_00344e74(entity, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Kind_124750* target = ((Context_124750 *)((owners::Object_592a0 *)entity)->FUN_000592a0())->FUN_00059a30()->target;
    if (!target)
        return false;
    int want;
    switch (this->type) {
    case 0:
        want = 1;
        break;
    case 1:
        want = 5;
        break;
    default:
        return false;
    }
    int kind = target->kind;
    switch (this->compare) {
    case 0:
        return kind == want;
    case 1:
        return kind != want;
    }
    return false;
}


// 0x001247d0 hulkfight::ai::CanSeeTargetCondition::vfunc_6 (476 B): equivalent/0x001247d0.cpp [wrapped: conflict: World]
// sym: ?vfunc_6@CanSeeTargetCondition@fn_001247d0@@UAEDHPAVParams_1247d0@fight@2@H@Z @92eb42df0ca6 @wa31f71f34156
namespace fn_001247d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3294 inputs, branch coverage 27/28, incomplete; Wine build 689 inputs, 27/28)
// hulkfight::ai::CanSeeTargetCondition::vfunc_6 @ 0x001247d0
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

struct V3_1247d0 { float x, y, z; };

namespace fight {
class Params_1247d0 {
public:
    virtual void vfunc_0();
};
}

class CFightParams_1247d0 : public fight::Params_1247d0 {
public:
    virtual void vfunc_0();
};

struct Part_1247d0 {
    char FUN_000fc800();
};

struct Unit_1247d0 {
    char pad[0x58];
    Part_1247d0 part;
};

struct Locator {
    char FUN_00036ac0(V3_1247d0* out);
};

struct Body_1247d0 {
    char pad0[8];
    Locator* loc;
    int mode;
    char pad1[0x40 - 0x10];
    V3_1247d0 pos;
};

struct Owner_1247d0 {
    char pad0[0x328];
    Body_1247d0* body;
    char pad1[0x1b8c - 0x32c];
    float lastTime;
    char lastResult;
    char pad2[0x1ca0 - 0x1b91];
    Unit_1247d0* unit;
    char FUN_00036ac0(V3_1247d0* out);
};

struct Clock_1247d0 {
};

struct Ctl_1247d0 {
    void FUN_001dcf60(int a);
};
struct World {
    char pad[0xc];
    Ctl_1247d0* ctl;
};

class Context { public: char pad[4]; };

Context* __fastcall FUN_000592a0(void* obj);
Owner_1247d0* __fastcall FUN_00059a30(Context* ctx);
Clock_1247d0* FUN_000678d0();
extern "C" bool __cdecl FUN_00203190(V3_1247d0* a1, V3_1247d0* a2, int a3, Body_1247d0* a4, int a5, Owner_1247d0* a6);

class CanSeeTargetCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight::Params_1247d0* params, int c);
    char pad04[8];
    char expected;
    char flag;
};

char CanSeeTargetCondition::vfunc_6(int a, fight::Params_1247d0* params, int c)
{
    if (dynamic_cast<CFightParams_1247d0*>(params) == 0)
        return 0;
    Owner_1247d0* owner = FUN_00059a30(FUN_000592a0(params));
    V3_1247d0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    owner->FUN_00036ac0(&pos);
    pos.y = pos.y + 1.0f;
    float now = ((owners::Obj_66280 *)(FUN_000678d0()))->FUN_00066280();
    Body_1247d0* body = owner->body;
    float last = owner->lastTime;
    if (body == 0)
        return 0;
    V3_1247d0 bpos = body->pos;
    char f = flag;
    if (f != 0 && body->mode == 1) {
        Unit_1247d0* u = owner->unit;
        if (u != 0) {
            Part_1247d0* p = &u->part;
            if (p != 0)
                return expected == p->FUN_000fc800();
        } else if (body->loc != 0) {
            body->loc->FUN_00036ac0(&bpos);
        }
    }
    if (last != 0.0f && last - 0.2f > now) {
        owner->lastTime = 0.0f;
        last = 0.0f;
    }
    if (last + 0.2f <= now) {
        bpos.y = bpos.y + 0.5f;
        DAT_004dd700->ctl->FUN_001dcf60(0);
        char r = FUN_00203190(&pos, &bpos, 0, body, f == 0, owner);
        DAT_004dd700->ctl->FUN_001dcf60(1);
        owner->lastResult = r;
        owner->lastTime = now;
        return expected == r;
    }
    return expected == owner->lastResult;
}
} // namespace fn_001247d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001249b0 hulkfight::ai::TargetInvincibleCondition::vfunc_6 (123 B): equivalent/0x001249b0.cpp
// sym: ?vfunc_6@TargetInvincibleCondition@ai@hulkfight@@UAE_NPAX00@Z @b8977fbd1f75 @w352c6492cd10
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 14/14)
// hulkfight::ai::TargetInvincibleCondition::vfunc_6 @ 0x001249b0
bool hulkfight::ai::TargetInvincibleCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; void * obj = (void *)__p1; int c = (int)__p2;

    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0)) {
        return false;
    }
    Body_1249b0 *body = ((Resolver_1249b0 *)((owners::Object_592a0 *)(((Target_1249b0 *)obj)))->FUN_000592a0())->FUN_00059a30()->body;
    if (body == 0) {
        return false;
    }
    if (body->state == 1) {
        if (body->invincible == 0) {
            return false;
        }
        return body->invincible->FUN_00036170() == this->f_0c;
    }
    if (body->state == 5) {
        return this->f_0c == 0;
    }
    return false;
}

namespace fn_f712cb17 {

// 0x00124a30 hulkfight::ai::TargetFirstShotCondition::vfunc_6 (75 B): matches/0x00124a30.cpp
// sym: ?vfunc_6@TargetFirstShotCondition@fn_f712cb17@@UAEEPAX00@Z
unsigned char TargetFirstShotCondition::vfunc_6(void* a, void* b, void* c) {
    if (FUN_00344e74(b, 0, &RTTI_Params_124a30, &RTTI_CFightParams_124a30, 0)) {
        Actor_124a30* p = ((Actor_124a30 *)((owners::Object_592a0 *)(((Obj_124a30*)b)))->FUN_000592a0());
        hulk_intptr x = ((ActorRef*)p)->FUN_00059a30();
        if (x) {
            unsigned char old = *(unsigned char*)(x + 0x1b74);
            *(unsigned char*)(x + 0x1b74) = 1;
            return old;
        }
    }
    return 0;
}

} // namespace fn_f712cb17

// 0x00124cb0 hulkfight::ai::ClearProjectileDistanceAction::vfunc_4 (39 B): matches/0x00124cb0.cpp
// sym: ?vfunc_4@ClearProjectileDistanceAction@ai@hulkfight@@UAEXXZ
void hulkfight::ai::ClearProjectileDistanceAction::vfunc_4() {
    B_124cb0* x = ((A_124cb0 *)((owners::Object_592a0 *)((*(A_124cb0 * *)&this->f_20)))->FUN_000592a0())->Fng_00059a30();
    if (x->h())
        x->Fnj_0003ee50();
}


// 0x00124ce0 hulkfight::ai::ClearProjectileDistanceAction::vfunc_5 (64 B): matches/0x00124ce0.cpp
// sym: ?vfunc_5@ClearProjectileDistanceAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::ClearProjectileDistanceAction::vfunc_5(hulk_intptr a, int b) {
    if (a != 0)
        return true;
    Helper_124ce0* x = ((Helper_124ce0 *)((owners::Object_592a0 *)((*(Helper_124ce0 * *)&this->f_20)))->FUN_000592a0());
    x = x->Next_00059a30();
    if ((*(char * *)&this->f_1c)[0x14] && x->Check())
        x->Act_0003ee50();
    return true;
}


// 0x00124d20 hulkfight::ai::TargetClearAction::vfunc_3 (73 B): matches/0x00124d20.cpp
// sym: ?vfunc_3@TargetClearAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::TargetClearAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!(*(Obj_124d20 * *)&this->f_20))
        return false;
    Obj_124d20* r = ((Obj_124d20 *)((owners::Object_592a0 *)((*(Obj_124d20 * *)&this->f_20)))->FUN_000592a0());
    if (!r)
        return false;
    Obj_124d20* r2 = r->Check_00059a30();
    if (!r2)
        return false;
    if ((*(Actor_124d20 * *)&this->f_1c)->flag != 0 || r2->flag == 0)
        r2->Apply_0003ffa0(0, 0);
    return true;
}

namespace fn_f712cb17 {

// 0x00124dd0 hulkfight::ai::TargetDirectionYCondition::vfunc_5 (36 B): matches/0x00124dd0.cpp
// sym: ?vfunc_5@TargetDirectionYCondition_124dd0@fn_f712cb17@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetDirectionYCondition_124dd0* TargetDirectionYCondition_124dd0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fd14;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}


// 0x00124e00 hulkfight::ai::TargetArcCondition::vfunc_5 (46 B): matches/0x00124e00.cpp
// sym: ?f5@TargetArcCondition_124e00@fn_f712cb17@@QAEPAV12@E@Z
TargetArcCondition_124e00* TargetArcCondition_124e00::f5(unsigned char flags) {
    vptr = (void**)DAT_0040fd34;
    sub.Fin_0027af50();
    Fin_002345b0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00124e30 hulkfight::ai::TargetTypeCondition::vfunc_5 (36 B): matches/0x00124e30.cpp
// sym: ?vfunc_5@TargetTypeCondition_124e30@fn_f712cb17@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
TargetTypeCondition_124e30* TargetTypeCondition_124e30::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040fd54;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f712cb17
