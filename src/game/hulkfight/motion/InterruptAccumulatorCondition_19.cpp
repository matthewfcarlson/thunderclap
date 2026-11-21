// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x00157800..0x00158f00 (kind game, layer game, confidence low); was game/hulkfight/motion/CollisionThrownObjectCondition_reg.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "decls/data/game/global.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4e72ed8 {
#define TREE_TU_END }
namespace fn_f4e72ed8 {} using namespace fn_f4e72ed8;
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up

// ---- declarations shared by the functions below
namespace fn_f4e72ed8 {
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
extern "C" char DAT_004150cc[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_157b10 {   // (fix2) was polymorphic (virtual bool cast_00154e00(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_157b10() { vftable = DAT_004150cc; }
};
extern "C" void __cdecl Use_00236ac0(void*, TrackFactoryCasterTemplate_157b10*);
} // namespace fn_f4e72ed8
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f4e72ed8 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class CollisionThrownObjectCondition_157ee0 {
public:
    char FUN_0014c5e0(char); /* (unb4) as defined; address taken only */
    void FUN_0014c5f0();
};
} }
namespace fn_f4e72ed8 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f4e72ed8
namespace fight {
template <class T>
class ParamBool_157ee0 : public ParamBoolBase {
public:
    ParamBool_157ee0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_157ee0 : public ParamNameBase {
public:
    ParamName_157ee0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class CollisionTargetNameCondition_158040 {
public:
    char FUN_0014c690(int); /* (unb4) as defined; address taken only */
    void FUN_0014c6a0();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_158040 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_158040(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamName_158040 : public ParamNameBase {
public:
    ParamName_158040(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
extern "C" char DAT_00415024[];
class B_1580f0 {
  public:
    bool FUN_00236760(void*);
};
extern "C" void* FUN_002343e0(void*, void*);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class CollisionSourceNameCondition_1581b0 {
public:
    bool FUN_0014c740(int); /* (unb4) as defined; address taken only */
    void FUN_0014c750();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_1581b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1581b0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamName_1581b0 : public ParamNameBase {
public:
    ParamName_1581b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
extern "C" char DAT_00415054[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158260 {   // (fix2) was polymorphic (virtual bool Cast_001548a0(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158260() { vftable = DAT_00415054; }
};
Track* FindTrack_00236ac0(const char*, TrackFactoryCasterTemplate_158260*);
extern "C" char DAT_00415060[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158290 {   // (fix2) was polymorphic (virtual void f() {}): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158290() { vftable = DAT_00415060; }
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern void* __cdecl find_00236ac0(void*, TrackFactoryCasterTemplate_158290*);
extern "C" char DAT_0041506c[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_1582c0 {   // (fix2) was polymorphic (virtual bool cast_001549a0(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_1582c0() { vftable = DAT_0041506c; }
};
class Track {
  public:
    bool FUN_002367c0(void*);
};
class Owner {
  public:
    bool FUN_002367c0(void*);
};
extern "C" void* FUN_00236ac0(void*, TrackFactoryCasterTemplate_1582c0*);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class HitReactionFloatTrack_1582f0 {
public:
    bool FUN_0014c880(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c8a0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c8c0(float); /* (unb4) as defined; address taken only */
    void FUN_0014c8e0();
    bool FUN_0014c900(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c920(float); /* (unb4) as defined; address taken only */
    bool FUN_0014c950(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c970(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c990(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c9b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014c9d0(int); /* (unb4) as defined; address taken only */
    char FUN_0014c9f0(int); /* (unb4) as defined; address taken only */
    char FUN_0014ca10(int); /* (unb4) as defined; address taken only */
    bool FUN_0014ca30(int); /* (unb4) as defined; address taken only */
    bool FUN_0014ca50(int); /* (unb4) as defined; address taken only */
    bool FUN_0014ca70(int); /* (unb4) as defined; address taken only */
    char FUN_0014ca90(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f4e72ed8 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f4e72ed8
namespace fight {
template <class T>
class ParamBool_1582f0 : public ParamBoolBase {
public:
    ParamBool_1582f0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_1582f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1582f0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_1582f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1582f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1582f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1582f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1582f0 : public ParamNameBase {
public:
    ParamName_1582f0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
extern "C" char DAT_00415078[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_1586a0 {   // (fix2) was polymorphic (virtual bool Cast_00154a60(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_1586a0() { vftable = DAT_00415078; }
};
class Receiver {
  public:
    bool FUN_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_1586a0*);
extern "C" char DAT_00415084[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_1586d0 {   // (fix2) was polymorphic (virtual bool cast_00154ac0(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_1586d0() { vftable = DAT_00415084; }
};
void* lookup_00236ac0(void*, TrackFactoryCasterTemplate_1586d0*);
} // namespace fn_f4e72ed8
namespace hulkfight { namespace motion {
class HitReactionTrack_158700 {
public:
    char FUN_0014caf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cb10(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cb30(float); /* (unb4) as defined; address taken only */
    void FUN_0014cb50();
    char FUN_0014cb70(int); /* (unb4) as defined; address taken only */
    bool FUN_0014cb90(int); /* (unb4) as defined; address taken only */
    char FUN_0014cbb0(char); /* (unb4) as defined; address taken only */
    bool FUN_0014cbd0(int); /* (unb4) as defined; address taken only */
    char FUN_0014cbf0(float); /* (unb4) as defined; address taken only */
    char FUN_0014cc20(void*); /* (unb4) as defined; address taken only */
    bool FUN_0014cc40(int); /* (unb4) as defined; address taken only */
    char FUN_0014cc60(int); /* (unb4) as defined; address taken only */
    char FUN_0014cc80(int); /* (unb4) as defined; address taken only */
    char FUN_0014cca0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_158700 : public ParamBoolBase {
public:
    ParamBool_158700(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_158700 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_158700(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_158700 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_158700(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_158700 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_158700(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_158700 : public ParamNameBase {
public:
    ParamName_158700(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f4e72ed8 {
extern "C" char DAT_00415090[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158a10 {   // (fix2) was polymorphic (virtual bool Cast_00154b80(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158a10() { vftable = DAT_00415090; }
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_158a10*);
extern "C" char DAT_0041509c[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158a40 {   // (fix2) was polymorphic (virtual bool Fnf_00154c00(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158a40() { vftable = DAT_0041509c; }
};
void* __cdecl find_00236ac0(const char*, TrackFactoryCasterTemplate_158a40*);
extern "C" char DAT_004150b4[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158aa0 {   // (fix2) was polymorphic (virtual bool Dummy_00154d00(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158aa0() { vftable = DAT_004150b4; }
};
Track* Find_00236ac0(const char*, TrackFactoryCasterTemplate_158aa0*);
extern "C" char DAT_004150c0[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158ad0 {   // (fix2) was polymorphic (virtual bool cast_00154da0(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158ad0() { vftable = DAT_004150c0; }
};
Track* __cdecl lookup_00236ac0(void*, TrackFactoryCasterTemplate_158ad0*);
extern "C" char DAT_004150cc[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158b00 {   // (fix2) was polymorphic (virtual bool Cast_00154e00(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158b00() { vftable = DAT_004150cc; }
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_158b00*);
extern "C" char DAT_004150d8[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158b30 {   // (fix2) was polymorphic (virtual bool cast_00154e60(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158b30() { vftable = DAT_004150d8; }
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_158b30*);
extern "C" char DAT_004150e4[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158b60 {   // (fix2) was polymorphic (virtual bool Cast_00154ee0(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158b60() { vftable = DAT_004150e4; }
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_158b60*);
extern "C" char DAT_004150f0[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158b90 {   // (fix2) was polymorphic (virtual bool Cast_00154f40(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158b90() { vftable = DAT_004150f0; }
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_158b90*);
extern "C" char DAT_004150fc[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158bc0 {   // (fix2) was polymorphic (virtual bool Cast_00154fc0(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158bc0() { vftable = DAT_004150fc; }
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_158bc0*);
class Factory {
  public:
    bool FUN_002367c0(void*);
};


} // namespace fn_f4e72ed8

// 0x001544b0 fight::ParamBool<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_0 (30 B): matches/0x001544b0.cpp
// sym: ??_G?$ParamBool@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionSourceNodeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)

namespace fn_f4e72ed8 {


} // namespace fn_f4e72ed8

// 0x001546b0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0 (30 B): matches/0x001546b0.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionDamageHealthCompareCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x00154870 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0 (30 B): matches/0x00154870.cpp
// sym: ??_G?$ParamEnumConstList@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CollisionTargetTypeCondition_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x001549d0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x001549d0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionFloatTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x001549f0 fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x001549f0.cpp
// sym: ??_G?$ParamEnumConstList@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionFloatTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x00154a10 fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x00154a10.cpp
// sym: ??_G?$ParamIntConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionFloatTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x00154a30 fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x00154a30.cpp
// sym: ??_G?$ParamBool@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionFloatTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)

namespace fn_f4e72ed8 {


} // namespace fn_f4e72ed8

// 0x00154af0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154af0.cpp
// sym: ??_G?$ParamFloatConstRange@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x00154b10 fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154b10.cpp
// sym: ??_G?$ParamEnumConstList@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x00154b30 fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154b30.cpp
// sym: ??_G?$ParamIntConstRange@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)



// 0x00154b50 fight::ParamBool<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00154b50.cpp
// sym: ??_G?$ParamBool@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HitReactionTrack_params_factory.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00157ee0 / FUN_00158040 / FUN_001581b0 / FUN_001582f0 / FUN_00158700)

namespace fn_f4e72ed8 {


// 0x00157800 fight::ParamName<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_7 (12 B): matches/0x00157800.cpp
// sym: ?vfunc_6@ParamBranch@fn_f4e72ed8@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}

} // namespace fn_f4e72ed8

// 0x001578b0 fight::ParamName<hulkfight::motion::CollisionTargetNameCondition>::vfunc_7 (12 B): matches/0x001578b0.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001578b0@@UAEXPAX@Z
namespace fn_001578b0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_001578b0


// 0x00157960 fight::ParamName<hulkfight::motion::CollisionSourceNameCondition>::vfunc_7 (12 B): matches/0x00157960.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00157960@@UAEXPAX@Z
namespace fn_00157960 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_00157960


// 0x001579f0 fight::ParamName<hulkfight::motion::HitReactionFloatTrack>::vfunc_7 (12 B): matches/0x001579f0.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001579f0@@UAEXPAX@Z
namespace fn_001579f0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_001579f0


// 0x00157a60 fight::ParamName<hulkfight::motion::HitReactionTrack>::vfunc_7 (12 B): matches/0x00157a60.cpp [wrapped: same definition as 0x00157800 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00157a60@@UAEXPAX@Z
namespace fn_00157a60 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    hulk_eaxptr(__fastcall* fn)(void*);
    virtual hulk_eaxptr vfunc_6(void*);
};
hulk_eaxptr ParamBranch::vfunc_6(void* p) {
    return fn(p);
}
} // namespace fn_00157a60

namespace fn_f4e72ed8 {

// 0x00157b10 FUN_00157b10 (27 B): matches/0x00157b10.cpp
// sym: ?target@fn_f4e72ed8@@YAXPAX@Z
void __cdecl target(void* p) {
    TrackFactoryCasterTemplate_157b10 c;
    Use_00236ac0(p, &c);
}

} // namespace fn_f4e72ed8

// 0x00157bd0 fight::ParamName<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_0 (30 B): matches/0x00157bd0.cpp
// sym: ??_G?$ParamName@VCollisionThrownObjectCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00157bf0 fight::ParamName<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0 (30 B): matches/0x00157bf0.cpp
// sym: ??_G?$ParamName@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00157c10 fight::ParamName<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0 (30 B): matches/0x00157c10.cpp
// sym: ??_G?$ParamName@VCollisionSourceNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00157c30 fight::ParamName<hulkfight::motion::HitReactionFloatTrack>::vfunc_0 (30 B): matches/0x00157c30.cpp
// sym: ??_G?$ParamName@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00157c50 fight::ParamName<hulkfight::motion::HitReactionTrack>::vfunc_0 (30 B): matches/0x00157c50.cpp
// sym: ??_G?$ParamName@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_f4e72ed8 {

} // namespace fn_f4e72ed8

// 0x00157ee0 FUN_00157ee0 (158 B): matches/0x00157ee0.cpp
// sym: _FUN_00157ee0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CollisionThrownObjectCondition>, ParamName<hulkfight::motion::CollisionThrownObjectCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00157ee0()
{
    if (DAT_004e108c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CollisionThrownObjectCondition>("thrownObject", &owners::Obj_14c5e0::FUN_0014c5e0);
        params[1] = new ::fight::ParamName< ::hulkfight::motion::CollisionThrownObjectCondition>("name", &owners::X_14c5f0::FUN_0014c5f0);
        FUN_002347b0(&DAT_004e1088, params, 2);
    }
    DAT_004e108c++;
}



// 0x00158040 FUN_00158040 (176 B): matches/0x00158040.cpp
// sym: _FUN_00158040
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>, ParamName<hulkfight::motion::CollisionTargetNameCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00158040()
{
    if (DAT_004e10ac == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionTargetNameCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::Obj_14c690::FUN_0014c690);
        params[1] = new ::fight::ParamName< ::hulkfight::motion::CollisionTargetNameCondition>("name", &owners::Obj_14c6a0::FUN_0014c6a0);
        FUN_002347b0(&DAT_004e10a8, params, 2);
    }
    DAT_004e10ac++;
}

namespace fn_f4e72ed8 {


// 0x001580f0 FUN_001580f0 (38 B): matches/0x001580f0.cpp
// sym: ?FUN_001580f0@fn_f4e72ed8@@YAXPAVB_1580f0@1@PAX1@Z
void FUN_001580f0(B_1580f0* b, void* a, void* x) {
    void* local;
    *(void**)&local = (void*)((hulk_intptr)DAT_00415024);
    void* p = FUN_002343e0(a, &local);
    b->FUN_00236760(p);
}


} // namespace fn_f4e72ed8

// 0x001581b0 FUN_001581b0 (176 B): matches/0x001581b0.cpp
// sym: _FUN_001581b0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::CollisionSourceNameCondition>, ParamName<hulkfight::motion::CollisionSourceNameCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001581b0()
{
    if (DAT_004e10cc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::motion::CollisionSourceNameCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &owners::Obj_14c740::FUN_0014c740);
        params[1] = new ::fight::ParamName< ::hulkfight::motion::CollisionSourceNameCondition>("name", &owners::Obj_14c750::FUN_0014c750);
        FUN_002347b0(&DAT_004e10c8, params, 2);
    }
    DAT_004e10cc++;
}

namespace fn_f4e72ed8 {


// 0x00158260 FUN_00158260 (38 B): matches/0x00158260.cpp
// sym: _FUN_00158260
extern "C" void FUN_00158260(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_158260 caster;
    Track* track = FindTrack_00236ac0(name, &caster);
    owner->FUN_002367c0(track);
}


// 0x00158290 FUN_00158290 (38 B): matches/0x00158290.cpp
// sym: _FUN_00158290
extern "C" void FUN_00158290(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158290 caster;
    obj->FUN_002367c0(find_00236ac0(name, &caster));
}


// 0x001582c0 FUN_001582c0 (38 B): matches/0x001582c0.cpp
// sym: _FUN_001582c0
extern "C" void FUN_001582c0(Track* t, void* name) {
    TrackFactoryCasterTemplate_1582c0 caster;
    t->FUN_002367c0(FUN_00236ac0(name, &caster));
}


} // namespace fn_f4e72ed8

// 0x001582f0 FUN_001582f0 (937 B): matches/0x001582f0.cpp
// sym: _FUN_001582f0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::HitReactionFloatTrack>, ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>, ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>, ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>, ParamName<hulkfight::motion::HitReactionFloatTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001582f0()
{
    if (DAT_004e10e4 == 0) {
        ::fight::ParamValue* params[17];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("timeBegin", &owners::Obj_14c880::FUN_0014c880);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HitReactionFloatTrack>("hitLocation", (void*)&DAT_0048f6cc, DAT_003f5ed0, &owners::Obj_14c8a0::FUN_0014c8a0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("direction", &owners::C_14c8c0::FUN_0014c8c0);
        params[3] = new ::fight::ParamName< ::hulkfight::motion::HitReactionFloatTrack>("flag", &owners::Obj_14c8e0::FUN_0014c8e0);
        params[4] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HitReactionFloatTrack>("interruptPriority", &owners::Obj_14c900::FUN_0014c900);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("pushbackDirection", &owners::C_14c920::FUN_0014c920);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("damageMin", &owners::X_14c950::FUN_0014c950);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("damageMax", &owners::Obj_14c970::FUN_0014c970);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("pushbackDistanceMin", &owners::O_14c990::FUN_0014c990);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("pushbackDistanceMax", &owners::Obj_14c9b0::FUN_0014c9b0);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("pushbackTimeMin", &owners::Obj_14c9d0::FUN_0014c9d0);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("pushbackTimeMax", &owners::Obj_14c9f0::FUN_0014c9f0);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("heightMin", &owners::Obj_14ca10::FUN_0014ca10);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("heightMax", &owners::Obj_14ca30::FUN_0014ca30);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("stunTimeMin", &owners::Obj_14ca50::FUN_0014ca50);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionFloatTrack>("stunTimeMax", &owners::Obj_14ca70::FUN_0014ca70);
        params[16] = new ::fight::ParamBool< ::hulkfight::motion::HitReactionFloatTrack>("ignoreHitRecord", &owners::Obj_14ca90::FUN_0014ca90);
        FUN_002347b0(&DAT_004e10e0, params, 17);
    }
    DAT_004e10e4++;
}

namespace fn_f4e72ed8 {


// 0x001586a0 FUN_001586a0 (38 B): matches/0x001586a0.cpp
// sym: _FUN_001586a0
extern "C" void FUN_001586a0(Receiver* receiver, void* value) {
    TrackFactoryCasterTemplate_1586a0 caster;
    receiver->FUN_002367c0(Find_00236ac0(value, &caster));
}


// 0x001586d0 FUN_001586d0 (38 B): matches/0x001586d0.cpp
// sym: _FUN_001586d0
extern "C" void FUN_001586d0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1586d0 caster;
    void* x = lookup_00236ac0(name, &caster);
    owner->FUN_002367c0(x);
}


} // namespace fn_f4e72ed8

// 0x00158700 FUN_00158700 (784 B): matches/0x00158700.cpp
// sym: _FUN_00158700
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::HitReactionTrack>, ParamEnumConstList<hulkfight::motion::HitReactionTrack>, ParamFloatConstRange<hulkfight::motion::HitReactionTrack>, ParamIntConstRange<hulkfight::motion::HitReactionTrack>, ParamName<hulkfight::motion::HitReactionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00158700()
{
    if (DAT_004e10f4 == 0) {
        ::fight::ParamValue* params[14];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("timeBegin", &owners::O_14caf0::FUN_0014caf0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::HitReactionTrack>("hitLocation", (void*)&DAT_0048f6cc, DAT_003f5ed0, &owners::X_14cb10::FUN_0014cb10);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("direction", &owners::C_14cb30::FUN_0014cb30);
        params[3] = new ::fight::ParamName< ::hulkfight::motion::HitReactionTrack>("flag", &owners::Obj_14cb50::FUN_0014cb50);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("damage", &owners::X_14cb70::FUN_0014cb70);
        params[5] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HitReactionTrack>("interruptPriority", &owners::T_14cb90::FUN_0014cb90);
        params[6] = new ::fight::ParamBool< ::hulkfight::motion::HitReactionTrack>("interrupt", &owners::Obj_14cbb0::FUN_0014cbb0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("hitReactionTime", &owners::Obj_14cbd0::FUN_0014cbd0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("pushbackDirection", &owners::Obj_14cbf0::FUN_0014cbf0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("pushbackDistance", &owners::Obj_14cc20::FUN_0014cc20);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("pushbackTime", &owners::Obj_14cc40::FUN_0014cc40);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("height", &owners::X_14cc60::FUN_0014cc60);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HitReactionTrack>("stunTime", &owners::C_14cc80::FUN_0014cc80);
        params[13] = new ::fight::ParamBool< ::hulkfight::motion::HitReactionTrack>("ignoreHitRecord", &owners::X_14cca0::FUN_0014cca0);
        FUN_002347b0(&DAT_004e10f0, params, 14);
    }
    DAT_004e10f4++;
}

namespace fn_f4e72ed8 {


// 0x00158a10 FUN_00158a10 (38 B): matches/0x00158a10.cpp
// sym: _FUN_00158a10
extern "C" void __cdecl FUN_00158a10(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_158a10 caster;
    void* p = FUN_00236ac0(key, &caster);
    obj->FUN_002367c0(p);
}


// 0x00158a40 FUN_00158a40 (38 B): matches/0x00158a40.cpp
// sym: _FUN_00158a40
extern "C" void __cdecl FUN_00158a40(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158a40 c;
    obj->FUN_002367c0(find_00236ac0(name, &c));
}

} // namespace fn_f4e72ed8

// 0x00158a70 FUN_00158a70 (38 B): matches/0x00158a70.cpp [wrapped: conflict: find]
// sym: _FUN_00158a70
namespace fn_00158a70 {
extern "C" char DAT_004150a8[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158a70 {   // (fix2) was polymorphic (virtual bool cast_00154c80(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158a70() { vftable = DAT_004150a8; }
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, TrackFactoryCasterTemplate_158a70*);
class Object {
  public:
    bool FUN_002367c0(void*);
};
extern "C" void __cdecl FUN_00158a70(Object* obj, void* name) {
    TrackFactoryCasterTemplate_158a70 caster;
    obj->FUN_002367c0(find_00236ac0(name, &caster));
}
} // namespace fn_00158a70

namespace fn_f4e72ed8 {

// 0x00158aa0 FUN_00158aa0 (38 B): matches/0x00158aa0.cpp
// sym: _FUN_00158aa0
extern "C" void FUN_00158aa0(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158aa0 caster;
    Track* track = Find_00236ac0(name, &caster);
    obj->FUN_002367c0(track);
}


// 0x00158ad0 FUN_00158ad0 (38 B): matches/0x00158ad0.cpp
// sym: _FUN_00158ad0
extern "C" void __cdecl FUN_00158ad0(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_158ad0 caster;
    owner->FUN_002367c0(lookup_00236ac0(key, &caster));
}


// 0x00158b00 FUN_00158b00 (38 B): matches/0x00158b00.cpp
// sym: _FUN_00158b00
extern "C" void __cdecl FUN_00158b00(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158b00 caster;
    void* result = Find_00236ac0(name, &caster);
    obj->FUN_002367c0(result);
}


// 0x00158b30 FUN_00158b30 (38 B): matches/0x00158b30.cpp
// sym: _FUN_00158b30
extern "C" void FUN_00158b30(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b30 c;
    obj->FUN_002367c0(FUN_00236ac0(name, &c));
}


// 0x00158b60 FUN_00158b60 (38 B): matches/0x00158b60.cpp
// sym: _FUN_00158b60
extern "C" void FUN_00158b60(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b60 caster;
    void* p = FUN_00236ac0(name, &caster);
    obj->FUN_002367c0(p);
}


// 0x00158b90 FUN_00158b90 (38 B): matches/0x00158b90.cpp
// sym: _FUN_00158b90
extern "C" bool FUN_00158b90(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_158b90 caster;
    return owner->FUN_002367c0(Find_00236ac0(name, &caster));
}


// 0x00158bc0 FUN_00158bc0 (38 B): matches/0x00158bc0.cpp
// sym: _FUN_00158bc0
extern "C" void FUN_00158bc0(Factory* f, void* name) {
    TrackFactoryCasterTemplate_158bc0 caster;
    void* obj = Find_00236ac0(name, &caster);
    f->FUN_002367c0(obj);
}

} // namespace fn_f4e72ed8

// 0x00158bf0 FUN_00158bf0 (38 B): matches/0x00158bf0.cpp [wrapped: conflict: Find]
// sym: _FUN_00158bf0
namespace fn_00158bf0 {
extern "C" char DAT_00415108[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_158bf0 {   // (fix2) was polymorphic (virtual bool Cast_00155060(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_158bf0() { vftable = DAT_00415108; }
};
class Obj {
  public:
    bool FUN_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_158bf0*);
extern "C" void FUN_00158bf0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_158bf0 caster;
    void* p = Find_00236ac0(name, &caster);
    obj->FUN_002367c0(p);
}
} // namespace fn_00158bf0


// 0x00158c20 FUN_00158c20 (723 B): matches/0x00158c20.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00158c20
namespace fn_00158c20 {
// FUN_00158c20 @ 0x00158c20
namespace hulkfight { namespace motion {
class InterruptAccumulatorCondition;
class CollisionInterruptPriorityCondition;
class CollisionSourceTypeCondition;
class CollisionSourceNameCondition;
class CollisionTargetNameCondition;
class CollisionSourceIsMissileCondition;
class CollisionSourceNodeCondition;
class CollisionSourceForceMagnitudeCondition;
class CollisionTargetPriorityCondition;
class CollisionTargetIsTargetCondition;
class CollisionTargetTypeCondition;
class CollisionSourceSizeCondition;
class CollisionTargetSizeCondition;
class HitPushbackCondition;
class HitPushbackVelocityCondition;
class CollisionChargeCondition;
class CollisionDamageHealthCompareCondition;
class CollisionThrowCondition;
class CollisionThrownObjectCondition;
class CollisionExplosionCondition;
class CollisionDevastatorCondition;
} }
namespace fight {
extern "C" char DAT_00414f58[], DAT_0041503c[], DAT_00414f88[], DAT_00415048[], DAT_00415018[], DAT_00414fd0[], DAT_00415000[], DAT_00414f64[], DAT_00414f94[], DAT_00414fb8[], DAT_00415030[], DAT_00414f7c[], DAT_00414fc4[], DAT_00414fac[], DAT_00414fdc[], DAT_0041500c[], DAT_00415024[], DAT_00414f70[], DAT_00414fe8[], DAT_00414ff4[], DAT_00414fa0[];   // (fix2) the game's caster vftables
template <class T> struct ConditionFactoryCasterTemplate {   // (fix2) was polymorphic (virtual void Create();): clang's own vftable natively,
  public:                          // the game's by address now, stored by each instantiation's constructor
    void *vftable;
    ConditionFactoryCasterTemplate();
};
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414f58; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_0041503c; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414f88; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00415048; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00415018; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fd0; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00415000; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414f64; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414f94; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fb8; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00415030; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414f7c; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fc4; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fac; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fdc; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_0041500c; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00415024; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414f70; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fe8; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414ff4; }
template <> inline ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition>::ConditionFactoryCasterTemplate() { vftable = DAT_00414fa0; }
}
struct Registry_158c20 {
    bool FUN_00236760(void*);
};
extern void* __cdecl FUN_002343e0(const char*, void*);
extern "C" void __cdecl FUN_00158c20(Registry_158c20* registry) {
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition> caster;
        registry->FUN_00236760(FUN_002343e0("interruptAccumulator", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionInterruptPriority", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceIsMissileCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceIsMissile", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceNode", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceForceMagnitude", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetPriority", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetIsTargetCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetIsTarget", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetTypeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetType", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionSourceSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionTargetSize", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition> caster;
        registry->FUN_00236760(FUN_002343e0("hitPushback", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackVelocityCondition> caster;
        registry->FUN_00236760(FUN_002343e0("hitPushbackVelocity", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionCharge", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionDamageHealthCompare", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrowCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionThrow", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionThrownObjectCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionThrownObject", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionExplosion", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionDevastatorCondition> caster;
        registry->FUN_00236760(FUN_002343e0("collisionDevastator", &caster));
    }
}
} // namespace fn_00158c20

