// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077f30..0x000788e0 (kind game, layer game, confidence high), merged by D32: global/CExplosionTrack_2.cpp
// piece 0x000783a0..0x000788e0 (kind game, layer game, confidence medium, dominant class DataHandler::ObjectCreator); was game/DataHandler/ObjectCreator.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/unknown.h"   // (gx3, D18) for the merged registrations
#include "gen/fight.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3f3201f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3f3201f {} using namespace fn_f3f3201f;
namespace fn_f3f3201f { extern "C" char DAT_003feefc[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/DataHandler.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f42fdcee { struct Vec3; } 
namespace fn_f42fdcee { struct O_77ee0 { char SetExplosion_00077ee0(int); }; }   // (gx3, D18) setters, as defined in unk_077df0.cpp
namespace fn_f42fdcee { struct Obj { bool SetOffset_00077ef0(struct fn_f42fdcee::Vec3 const *); }; }   // (gx3, D18) setters, as defined in unk_077df0.cpp
namespace fn_f42fdcee { struct Obj_77ed0 { bool SetTimeBegin_00077ed0(int); }; }   // (gx3, D18) setters, as defined in unk_077df0.cpp

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f3f3201f {
bool SetTimeBegin_00077ed0(void*, int); /* (unb5) as defined; address taken only */
char SetExplosion_00077ee0(void*, int); /* (unb5) as defined; address taken only */
bool SetOffset_00077ef0(void*, void*); /* (unb5) as defined; address taken only */
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


} // namespace fn_f3f3201f

// 0x00078300 fight::ParamFloatConstRange<CHeliDeathSpiralTrack>::vfunc_0 (30 B): matches/0x00078300.cpp
// sym: ??_G?$ParamFloatConstRange@VCHeliDeathSpiralTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CExplosionTrack_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_000783a0 / FUN_00078610)



// 0x00078320 fight::ParamIntConstRange<CHeliDeathSpiralTrack>::vfunc_0 (30 B): matches/0x00078320.cpp
// sym: ??_G?$ParamIntConstRange@VCHeliDeathSpiralTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CExplosionTrack_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_000783a0 / FUN_00078610)



// 0x00078340 fight::ParamFloatConstRange<CExplosionTrack>::vfunc_0 (30 B): matches/0x00078340.cpp
// sym: ??_G?$ParamFloatConstRange@VCExplosionTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CExplosionTrack_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_000783a0 / FUN_00078610)



// 0x00078360 fight::ParamEnumConstList<CExplosionTrack>::vfunc_0 (30 B): matches/0x00078360.cpp
// sym: ??_G?$ParamEnumConstList@VCExplosionTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CExplosionTrack_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_000783a0 / FUN_00078610)



// 0x00078380 fight::ParamVector<CExplosionTrack>::vfunc_0 (30 B): matches/0x00078380.cpp
// sym: ??_G?$ParamVector@VCExplosionTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CExplosionTrack_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_000783a0 / FUN_00078610)



// 0x000783a0 FUN_000783a0 (613 B): matches/0x000783a0.cpp
// sym: _FUN_000783a0
// (gx2, D18) from ObjectCreator.new_throw.cpp; constructs the real ParamFloatConstRange<CHeliDeathSpiralTrack>, ParamIntConstRange<CHeliDeathSpiralTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000783a0()
{
    if (DAT_004dd034 == 0) {
        ::fight::ParamValue* params[11];
        params[0] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("timeBegin", &owners::Obj_77df0::FUN_00077df0);
        params[1] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("timeEnd", &owners::C_77e00::FUN_00077e00);
        params[2] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("weightRatio", &owners::X_77e10::FUN_00077e10);
        params[3] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("minTurningVelocity", &owners::X_77e20::FUN_00077e20);
        params[4] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("maxTurningVelocity", &owners::Obj_77e40::FUN_00077e40);
        params[5] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("acceleration", &owners::X_77e60::FUN_00077e60);
        params[6] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("gravity", &owners::A_77e70::FUN_00077e70);
        params[7] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("tilt", &owners::Target_77e80::FUN_00077e80);
        params[8] = new ::fight::ParamIntConstRange< ::CHeliDeathSpiralTrack>("priority", &owners::Obj_77ea0::FUN_00077ea0);
        params[9] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("blendInTime", &owners::X_77eb0::FUN_00077eb0);
        params[10] = new ::fight::ParamFloatConstRange< ::CHeliDeathSpiralTrack>("blendOutTime", &owners::Obj_77ec0::FUN_00077ec0);
        FUN_002347b0(&DAT_004dd030, params, 11);
    }
    DAT_004dd034++;
}



// 0x00078610 FUN_00078610 (227 B): matches/0x00078610.cpp
// sym: _FUN_00078610
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CExplosionTrack>, ParamFloatConstRange<CExplosionTrack>, ParamVector<CExplosionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00078610()
{
    if (DAT_004dd03c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CExplosionTrack>("timeBegin", &fn_f42fdcee::Obj_77ed0::SetTimeBegin_00077ed0);
        params[1] = new ::fight::ParamEnumConstList< ::CExplosionTrack>("explosion", (void*)&DAT_0049b6b4, 13, &fn_f42fdcee::O_77ee0::SetExplosion_00077ee0);
        params[2] = new ::fight::ParamVector< ::CExplosionTrack>("offset", &fn_f42fdcee::Obj::SetOffset_00077ef0);
        FUN_002347b0(&DAT_004dd038, params, 3);
    }
    DAT_004dd03c++;
}

namespace fn_f3f3201f {


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
    *(void**)this = (void**)DAT_003feefc;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f3f3201f
