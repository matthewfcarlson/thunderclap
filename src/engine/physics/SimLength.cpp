// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ecd50..0x002ed240 (kind game, layer engine, confidence high), dominant class physics::SimLength
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/engine/physics.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fae3921a {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fae3921a {} using namespace fn_fae3921a;
namespace fn_fae3921a { extern "C" char DAT_0043117c[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace physics {
extern const float hulk_at_004d287c;
}
namespace physics {
class SimCGSValue_2ecd70 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(float);
    virtual void vfunc_2();
    virtual void vfunc_3();
    float a;
    float b;
};
}
namespace physics {
class SimUnits_2ecd70 {};
}
namespace fn_fae3921a {
class SimUnits_2ecda0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual float vfunc_3();
};
extern void* hulk_at_00431184[];
class Entity_2ece00 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class Environment_2ece00 : public Entity_2ece00 {
  public:
    Environment_2ece00* vfunc_5(signed char flags);
};
struct Listener_2ece90 {
    void FUN_002f7a60();
};
struct SystemA {
    char pad00[0x68];
    Listener_2ece90 listener;
};
struct SystemB {
    char pad00[HULK_PW_SOLVER];  // (x64t4) decls/physics_world.h
    Listener_2ece90 listener;
};
extern void* hulk_at_004311b0;
struct SimLength {
    void* vptr;
    float value;
    float raw;
    SimLength(float);
};
struct SimTime {
    virtual void FUN_002ecf60();
    float current;
    float previous;
    SimTime(float time);
};
struct Environment_nv_2ed020 {
    physics::Environment* Init_002ecf60();
};
extern "C" void* __cdecl FUN_00263ea0(unsigned);  // (x64t4) the allocator's jmp thunk 0x00263ea0 (was `Alloc`, unbound)

} // namespace fn_fae3921a

// 0x002ecd50 physics::SimLength::vfunc_1 (23 B): matches/0x002ecd50.cpp
// sym: ?vfunc_1@SimLength@physics@@UAEXM@Z
 // namespace physics
void physics::SimLength::vfunc_1(float value) {
    *(float*)((char*)&this->f_08) = value;
    *(float*)((char*)&this->f_04) = hulk_at_004d287c * value;
}


// 0x002ecd70 physics::SimTime::vfunc_1 (15 B): matches/0x002ecd70.cpp
// sym: ?vfunc_1@SimTime@physics@@UAEXM@Z
 // namespace physics
void physics::SimTime::vfunc_1(float x) {
    this->f_08 = x;
    this->f_04 = x;
}


// 0x002ecd90 physics::SimCGSValue::vfunc_2 (4 B): matches/0x002ecd90.cpp
// sym: ?vfunc_2@SimCGSValue@physics@@UAEMXZ
 // namespace physics
hulk_freg physics::SimCGSValue::vfunc_2() {
    return *(float*)((char*)&this->f_08);
}


// 0x002ecda0 physics::SimCGSValue::vfunc_3 (4 B): matches/0x002ecda0.cpp
// sym: ?vfunc_3@SimCGSValue@physics@@UAEMXZ
hulk_freg physics::SimCGSValue::vfunc_3() {
    return this->f_04;
}


// 0x002ecdc0 physics::SimCGSValue::vfunc_0 (31 B): matches/0x002ecdc0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002ecdc0@@UAEPAV123@E@Z
namespace fn_002ecdc0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimUnits_2ecdc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0043117c[];
namespace pure3d {
class NonCopyable : public SimUnits_2ecdc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0043117c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002ecdc0


// 0x002ecde0 physics::SimUnits::vfunc_0 (31 B): matches/0x002ecde0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002ecde0@@UAEPAV123@E@Z
namespace fn_002ecde0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0043117c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002ecde0

namespace fn_fae3921a {

// 0x002ece00 physics::Environment::vfunc_2 (36 B): matches/0x002ece00.cpp
// sym: ?vfunc_5@Environment_2ece00@fn_fae3921a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Environment_2ece00* Environment_2ece00::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00431184;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fae3921a

// 0x002ece90 FUN_002ece90 (132 B): equivalent/0x002ece90.cpp
// sym: ?FUN_002ece90@ScaledVec_2ece90@owners@@QAEXMMM@Z @bdc6e933d553 @w4554b06516f2
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_002ece90 @ 0x002ece90
void owners::ScaledVec_2ece90::FUN_002ece90(float vx, float vy, float vz)
{
    x = vx;
    y = vy;
    z = vz;
    sx = DAT_004d287c * x;
    sy = DAT_004d287c * y;
    sz = DAT_004d287c * z;
    // sx..sz are read back from memory (rounded to float), as the original does
    const float *p = &sx;
    length = (float)sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
    if ((*(SystemA**)&DAT_0055547c)) {
        (*(SystemA**)&DAT_0055547c)->listener.FUN_002f7a60();
    } else if ((*(SystemB**)&DAT_00554c14)) {
        (*(SystemB**)&DAT_00554c14)->listener.FUN_002f7a60();
    }
}

namespace fn_fae3921a {

// 0x002ecf20 FUN_002ecf20 (31 B): matches/0x002ecf20.cpp
// sym: ??0SimLength@fn_fae3921a@@QAE@M@Z
// data: gScale_2ecf20 = DAT_004d287c
SimLength::SimLength(float x) {
    vptr = &hulk_at_004311b0;
    raw = x;
    value = (*(const float*)&DAT_004d287c) * x;
}


// 0x002ecf40 FUN_002ecf40 (23 B): matches/0x002ecf40.cpp
// sym: ??0SimTime@fn_fae3921a@@QAE@M@Z
SimTime::SimTime(float time) {
    previous = time;
    current = time;
}

} // namespace fn_fae3921a

// 0x002ecf60 FUN_002ecf60 (124 B): equivalent/0x002ecf60.cpp [wrapped: conflict: physics::Environment]
// sym: ??0Environment@physics@fn_002ecf60@@QAE@XZ @d30eae54df63 @wfd3d60ae415e
namespace fn_002ecf60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002ecf60 @ 0x002ecf60


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double x);
#endif



// (x64t4) pure3d::Entity's words and Environment's vftable stored by address (DAT_00431184): the local classes' own
// vftables were the 64-bit link's stubs (`Entity::v0`, unbound)
extern "C" char DAT_00431184[];  // physics::Environment
class Entity {
public:
    void* vftable;
    char pad04[0xc];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};

namespace physics {
class Environment : public Entity {
public:
    Environment();

    float gravityX;     // +0x10
    float gravityY;     // +0x14
    float gravityZ;     // +0x18
    float scaledX;      // +0x1c
    float scaledY;      // +0x20
    float scaledZ;      // +0x24
    float length;       // +0x28
    float damping;      // +0x2c
    float scaledDamping; // +0x30
};

Environment::Environment() {
    vftable = DAT_00431184;
    damping = 2.0f;
    scaledDamping = 2.0f;
    gravityY = -980.0f;
    gravityX = 0.0f;
    gravityZ = 0.0f;
    scaledX = DAT_004d287c * gravityX;
    scaledY = DAT_004d287c * gravityY;
    scaledZ = DAT_004d287c * gravityZ;
    length = (float)sqrt(scaledX * scaledX + scaledY * scaledY + scaledZ * scaledZ);
    scaledDamping = DAT_004d287c * damping;
}
}
} // namespace fn_002ecf60


// 0x002ecfe0 physics::SimLength::vfunc_0 (31 B): matches/0x002ecfe0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002ecfe0@@UAEPAV123@E@Z
namespace fn_002ecfe0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimCGSValue_2ecfe0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimCGSValue_2ecfe0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0043117c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002ecfe0


// 0x002ed000 physics::SimTime::vfunc_0 (31 B): matches/0x002ed000.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002ed000@@UAEPAV123@E@Z
namespace fn_002ed000 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimCGSValue_2ed000 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimCGSValue_2ed000 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0043117c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002ed000

namespace fn_fae3921a {

// 0x002ed020 FUN_002ed020 (46 B): matches/0x002ed020.cpp
// sym: _FUN_002ed020
extern "C" void __cdecl FUN_002ed020() {
    physics::Environment* p = (*(physics::Environment**)&DAT_00554c10);
    if (p == 0) {
        // (x64t5) the environment as its constructor 0x002ecf60 writes it (0x34 bytes on 32-bit: Entity's words, nine
        // floats), plus the block's last word (the XBE allocates 0x38): the 0x38-byte block was 8 short natively
        p = (physics::Environment*)FUN_00263ea0((unsigned int)sizeof(fn_002ecf60::physics::Environment) + 4);
        if (p != 0)
            p = ((Environment_nv_2ed020*)(((physics::Environment*)(p))))->Init_002ecf60();
        else
            p = 0;
        (*(physics::Environment**)&DAT_00554c10) = p;
        p->vfunc_0();
    }
}

} // namespace fn_fae3921a
