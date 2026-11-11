// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000783a0..0x000788e0 (kind game, layer game, confidence medium), dominant class DataHandler::ObjectCreator
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/DataHandler.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3f3201f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3f3201f {} using namespace fn_f3f3201f;
#include "game/DataHandler.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f3f3201f {
void __cdecl SetTimeBegin_00077ed0();
void __cdecl SetExplosion_00077ee0();
void __cdecl SetOffset_00077ef0();
extern "C" void __cdecl FUN_002347b0(void*, void**, int);
class CExplosionTrack;
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
}
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; void* list; int count; void (__cdecl *callback)(); char tail[4]; void FUN_00234cc0(const char*); };
}
namespace fight {
template<class T> struct ParamVector { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234e50(const char*); };
}
struct V3_78710 {
    float x, y, z;
};
struct F_78710 {
    void Interpolate(V3_78710* a, V3_78710* b, float t);
};
struct RandomState { uint first; uint second; hulk_freg FUN_00078780(); };
class R_787e0 {
  public:
    unsigned a, b;
    hulk_freg Next(float lo, float hi);
};
inline unsigned Step(unsigned* s, unsigned m) {
    *s = (*s & 0xffff) * m + (*s >> 16);
    return *s;
}
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00078610 FUN_00078610 (227 B): equivalent/0x00078610.cpp
// sym: _FUN_00078610 @624d547724bc @w01088127ca48
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00078610 @ 0x00078610
extern "C" void FUN_00078610() {
 if (DAT_004dd03c == 0) {
 void* items[3];
 fight::ParamFloatConstRange<CExplosionTrack>* a = (fight::ParamFloatConstRange<CExplosionTrack>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CExplosionTrack>));
 if(a) { a->FUN_00234960("timeBegin"); new(a) fight::ParamFloatConstRange<CExplosionTrack>; a->callback=SetTimeBegin_00077ed0; }
 items[0]=a;
 fight::ParamEnumConstList<CExplosionTrack>* b=(fight::ParamEnumConstList<CExplosionTrack>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CExplosionTrack>));
 if(b) { b->FUN_00234cc0("explosion"); new(b) fight::ParamEnumConstList<CExplosionTrack>; b->list=((char*)&DAT_0049b6b4); b->count=13; b->callback=SetExplosion_00077ee0; }
 items[1]=b;
 fight::ParamVector<CExplosionTrack>* c=(fight::ParamVector<CExplosionTrack>*)FUN_0008d690((int)sizeof(fight::ParamVector<CExplosionTrack>));
 if(c) { c->FUN_00234e50("offset"); new(c) fight::ParamVector<CExplosionTrack>; c->callback=SetOffset_00077ef0; }
 items[2]=c;
 FUN_002347b0(((char*)&DAT_004dd038),items,3);
 }
 ++DAT_004dd03c;
}


// 0x00078710 FUN_00078710 (55 B): matches/0x00078710.cpp
// sym: ?Interpolate@F_78710@fn_f3f3201f@@QAEXPAUV3_78710@2@0M@Z
void F_78710::Interpolate(V3_78710* a, V3_78710* b, float t) {
    V3_78710* out = (V3_78710*)this;
    out->x = (b->x - a->x) * t + a->x;
    out->y = (b->y - a->y) * t + a->y;
    out->z = (b->z - a->z) * t + a->z;
}

} // namespace fn_f3f3201f

// 0x00078750 FUN_00078750 (35 B): matches/0x00078750.cpp
// sym: ?FUN_00078750@Vec3_78750@owners@@QAEPAU12@PAU12@0@Z
owners::Vec3_78750* owners::Vec3_78750::FUN_00078750(owners::Vec3_78750* out, owners::Vec3_78750* other) {
    float z = other->z + this->z;
    float y = other->y + this->y;
    float x = other->x + this->x;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}

namespace fn_f3f3201f {

// 0x00078780 FUN_00078780 (85 B): equivalent/0x00078780.cpp
// sym: ?FUN_00078780@RandomState@fn_f3f3201f@@QAEMXZ @22afe0c31dd3 @w5b2e526cfd9f
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00078780 @ 0x00078780
hulk_freg RandomState::FUN_00078780() {
    first = (first & 0xffff) * 0x9069 + (first >> 16);
    second = (second & 0xffff) * 0x4650 + (second >> 16);
    union { uint bits; float value; } result;
    result.bits = (((first << 16) + (second & 0xffff)) & 0x7fffff) | 0x3f800000;
    return result.value - 1.0f;
}


// 0x000787e0 FUN_000787e0 (101 B): matches/0x000787e0.cpp
// sym: ?Next@R_787e0@fn_f3f3201f@@QAEMMM@Z
hulk_freg R_787e0::Next(float lo, float hi) {
    Step(&a, 0x9069);
    unsigned t = Step(&b, 18000);
    unsigned u = (a << 16) + (t & 0xffff) & 0x7fffff | 0x3f800000;
    return (*(float*)&u - 1.0f) * (hi - lo) + lo;
}

} // namespace fn_f3f3201f

// 0x00078850 FUN_00078850 (3 B): matches/0x00078850.cpp
// sym: ?FUN_00078850@X_78850@owners@@QAEPAU12@XZ
owners::X_78850* owners::X_78850::FUN_00078850() {
    return this;
}

namespace fn_f3f3201f {

// 0x000788b0 DataHandler::ObjectCreator::vfunc_0 (31 B): matches/0x000788b0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f3f3201f@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f3f3201f
