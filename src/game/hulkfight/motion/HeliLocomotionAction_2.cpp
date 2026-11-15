// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015cd10..0x00163a90 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/HeliLocomotionAction.cpp
// piece 0x00161c10..0x00163a90 (kind game, layer game, confidence low); was game/unknown/unk_161c10.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f95ed483 {
#define TREE_TU_END }
namespace fn_f95ed483 {} using namespace fn_f95ed483;
#include "game/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f68d580d { class Obj_15a9f0; } 
namespace fn_f68d580d { class Obj_15b5e0; } namespace fn_f68d580d { class Obj_15b5e0; } 
namespace fn_f68d580d { class Obj_15b6e0; } 
namespace fn_f68d580d { struct Inner_15aa00; } 
namespace fn_f68d580d { struct O_15acf0; } 
namespace fn_f68d580d { struct Obj_15aa20; } namespace fn_f68d580d { struct Obj_15aa20; } 
namespace fn_f68d580d { struct Obj_15ac70; } namespace fn_f68d580d { struct Obj_15ac70; } 
namespace fn_f68d580d { struct Obj_15ac90; } 
namespace fn_f68d580d { struct Obj_15b1f0; } namespace fn_f68d580d { struct Obj_15b1f0; } 
namespace fn_f68d580d { struct S_15b0f0; } 
namespace fn_f68d580d { struct S_15b6d0; } 
namespace fn_f68d580d { struct Src; } 
namespace fn_f68d580d { struct Sub_15aa50; } 
namespace fn_f68d580d { struct V3; } 
namespace fn_f68d580d { struct Vec3_15af70; } 
namespace fn_f68d580d { struct Vec3_15b0b0; } 
namespace fn_f68d580d { int * __fastcall FUN_0015a9f0(class fn_f68d580d::Obj_15a9f0 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct fn_f68d580d::Obj_15aa20 * __fastcall FUN_0015aa20(struct fn_f68d580d::Obj_15aa20 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct fn_f68d580d::Obj_15ac70 * __fastcall FUN_0015ac70(struct fn_f68d580d::Obj_15ac70 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { int * __fastcall FUN_0015ac90(struct fn_f68d580d::Obj_15ac90 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { int * __fastcall FUN_0015acf0(struct fn_f68d580d::O_15acf0 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct fn_f68d580d::Obj_15b1f0 * __fastcall FUN_0015b1f0(struct fn_f68d580d::Obj_15b1f0 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { class fn_f68d580d::Obj_15b5e0 * __fastcall FUN_0015b5e0(class fn_f68d580d::Obj_15b5e0 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { char * __fastcall FUN_0015b6d0(struct fn_f68d580d::S_15b6d0 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_f68d580d { void * __fastcall FUN_0015b6e0(class fn_f68d580d::Obj_15b6e0 *); }   // (gx3, D18) a setter, as defined in unk_15a820.cpp
namespace fn_0015af20 { struct Obj_15af20 { bool operator=(int); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct A_15b600 { void * Get(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct O_15a830 { int * member(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj { bool Set(struct fn_f68d580d::V3 const *); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15a840 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15a850 { char Set(char); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15aa50 { struct fn_f68d580d::Sub_15aa50 * FUN_0015aa50(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15af70 { bool Set(struct fn_f68d580d::Vec3_15af70 const *); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15b0b0 { char Set(struct fn_f68d580d::Vec3_15b0b0 const *); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15b0f0 { bool Set(struct fn_f68d580d::S_15b0f0 *); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15b410 { int * GetValue(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15b440 { char * Get(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Obj_15b5f0 { char * Get(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct Tgt { char Set(struct fn_f68d580d::Src *); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp
namespace fn_f68d580d { struct X_15aa00 { struct fn_f68d580d::Inner_15aa00 * Fn(); }; }   // (gx3, D18) setters, as defined in unk_15a820.cpp

// ---- declarations shared by the functions below
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_161d20 {
  public:
    virtual bool Cast_00160ed0(void*);
};
class Owner {
  public:
    void Apply_002367c0(void*);
    void add_002367c0(void*);
};
void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_161d20*);
struct TrackFactoryCasterTemplate_161d50 {
    virtual bool cast_00160f30(void*);
};
extern "C" void* __cdecl findTrack_00236ac0(void*, TrackFactoryCasterTemplate_161d50*);
} // namespace fn_f95ed483
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f95ed483 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class ClimbLocomotion4Track_161d80 {
public:
    bool FUN_0015a8c0(int); /* (unb4) as defined; address taken only */
    char FUN_0015a8d0(int); /* (unb4) as defined; address taken only */
    char FUN_0015a8f0(int); /* (unb4) as defined; address taken only */
    char FUN_0015a910(int); /* (unb4) as defined; address taken only */
    char FUN_0015a930(int); /* (unb4) as defined; address taken only */
    char FUN_0015a950(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a970(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a990(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a9b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015a9d0(int); /* (unb4) as defined; address taken only */
    void FUN_0015a9e0();
    void FUN_0015a9f0();
    void FUN_0015aa00();
    void FUN_0015aa10();
    void FUN_0015aa20();
    void FUN_0015aa30();
    void FUN_0015aa40();
    void FUN_0015aa50();
    void FUN_0015aa60();
    void FUN_0015aa70();
    void FUN_0015aa80();
    char FUN_0015aaa0(int); /* (unb4) as defined; address taken only */
    char FUN_0015aac0(int); /* (unb4) as defined; address taken only */
    char FUN_0015aae0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f95ed483 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f95ed483
namespace fight {
template <class T>
class ParamFloatConstRange_161d80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_161d80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_161d80 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_161d80(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_161d80 : public ParamNameBase {
public:
    ParamName_161d80(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_162280 {
  public:
    virtual bool Fnf_00160fb0(void*);
};
class Obj {
  public:
    void run_002367c0(void*);
    void use_002367c0(void*);
    void Do_002367c0(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_162280*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class LocomotionStrafe4Track_1622b0 {
public:
    bool FUN_0015aaf0(int); /* (unb4) as defined; address taken only */
    char FUN_0015ab00(int); /* (unb4) as defined; address taken only */
    char FUN_0015ab20(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ab40(float); /* (unb4) as defined; address taken only */
    char FUN_0015ab70(char); /* (unb4) as defined; address taken only */
    char FUN_0015ab90(int); /* (unb4) as defined; address taken only */
    bool FUN_0015abb0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015abd0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015abf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ac10(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ac30(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ac50(int); /* (unb4) as defined; address taken only */
    void FUN_0015ac60();
    void FUN_0015ac70();
    void FUN_0015ac80();
    void FUN_0015ac90();
    void FUN_0015aca0();
    void FUN_0015acb0();
    void FUN_0015acc0();
    void FUN_0015acd0();
    void FUN_0015ace0();
    void FUN_0015acf0();
    void FUN_0015ad00();
    char FUN_0015ad20(int); /* (unb4) as defined; address taken only */
    bool FUN_0015ad40(int); /* (unb4) as defined; address taken only */
    char FUN_0015ad60(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f95ed483 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f95ed483
namespace fight {
template <class T>
class ParamBool_1622b0 : public ParamBoolBase {
public:
    ParamBool_1622b0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_1622b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1622b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1622b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1622b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1622b0 : public ParamNameBase {
public:
    ParamName_1622b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_162820 {
  public:
    virtual bool Fnf_00161050(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_162820*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class HeliLocomotionTrack_162850 {
public:
    bool FUN_0015ad70(int); /* (unb4) as defined; address taken only */
    char FUN_0015ad80(int); /* (unb4) as defined; address taken only */
    char FUN_0015ada0(int); /* (unb4) as defined; address taken only */
    char FUN_0015adc0(int); /* (unb4) as defined; address taken only */
    char FUN_0015ade0(float); /* (unb4) as defined; address taken only */
    char FUN_0015ae10(float); /* (unb4) as defined; address taken only */
    char FUN_0015ae40(float); /* (unb4) as defined; address taken only */
    bool FUN_0015ae70(float); /* (unb4) as defined; address taken only */
    bool FUN_0015aea0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015aed0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015af00(int); /* (unb4) as defined; address taken only */
    bool FUN_0015af20(int); /* (unb4) as defined; address taken only */
    bool FUN_0015af40(int); /* (unb4) as defined; address taken only */
    bool FUN_0015af70(void*); /* (unb4) as defined; address taken only */
    bool FUN_0015afa0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015afd0(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b000(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b030(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b060(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b080(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b0a0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b0b0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0015b0f0(void*); /* (unb4) as defined; address taken only */
    char FUN_0015b140(void*); /* (unb4) as defined; address taken only */
    bool FUN_0015b180(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b1a0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b1c0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b1e0(int); /* (unb4) as defined; address taken only */
    void FUN_0015b1f0();
    bool FUN_0015b210(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b220(void*); /* (unb4) as defined; address taken only */
    char FUN_0015b250(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b270(int); /* (unb4) as defined; address taken only */
    char FUN_0015b290(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b2b0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b2d0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b310(void*); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_162850 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_162850(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_162850 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_162850(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_162850 : public ParamNameBase {
public:
    ParamName_162850(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_162850 : public ParamVectorBase {
public:
    ParamVector_162850(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class LocomotionSteerTrack_163050 {
public:
    char FUN_0015b340(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b350(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b370(int); /* (unb4) as defined; address taken only */
    char FUN_0015b390(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b3c0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b3e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b400(int); /* (unb4) as defined; address taken only */
    void FUN_0015b410();
    void FUN_0015b420();
    void FUN_0015b430();
    void FUN_0015b440();
    char FUN_0015b460(char); /* (unb4) as defined; address taken only */
    void FUN_0015b470();
    char FUN_0015b490(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b4b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b4d0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_163050 : public ParamBoolBase {
public:
    ParamBool_163050(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_163050 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_163050(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_163050 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_163050(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_163050 : public ParamNameBase {
public:
    ParamName_163050(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_1633c0 {
  public:
    virtual int Cast_00161190(void*);
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_1633c0*);
} // namespace fn_f95ed483
namespace hulkfight { namespace motion {
class LocomotionSprintTrack_1633f0 {
public:
    char FUN_0015b4e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b4f0(int); /* (unb4) as defined; address taken only */
    char FUN_0015b510(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b530(float); /* (unb4) as defined; address taken only */
    char FUN_0015b560(float); /* (unb4) as defined; address taken only */
    bool FUN_0015b590(int); /* (unb4) as defined; address taken only */
    char FUN_0015b5b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b5d0(void*); /* (unb4) as defined; address taken only */
    void FUN_0015b5e0();
    void FUN_0015b5f0();
    void FUN_0015b600();
    void FUN_0015b610();
    void FUN_0015b620();
    bool FUN_0015b640(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b660(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b680(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_1633f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1633f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_1633f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1633f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1633f0 : public ParamNameBase {
public:
    ParamName_1633f0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f95ed483 {
class TrackFactoryCasterTemplate_163760 {
  public:
    virtual bool Cast_00161210(void*);
};
class Receiver {
  public:
    void Use_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_163760*);
class GrappleLocomotionSteerTrack {
public:
    char FUN_0015b690(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b6a0(int); /* (unb4) as defined; address taken only */
    void FUN_0015b6b0();
    void FUN_0015b6c0();
    void FUN_0015b6d0();
    void FUN_0015b6e0();
    void FUN_0015b6f0();
    bool FUN_0015b710(int); /* (unb4) as defined; address taken only */
    bool FUN_0015b730(int); /* (unb4) as defined; address taken only */
    char FUN_0015b750(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_f95ed483
namespace fight {
template <class T>
class ParamFloatConstRange_163790 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_163790(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_163790 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_163790(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_163790 : public ParamNameBase {
public:
    ParamName_163790(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_f95ed483 {

} // namespace fn_f95ed483

// 0x00160e20 fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>::vfunc_0 (30 B): matches/0x00160e20.cpp
// sym: ??_G?$ParamFloatConstRange@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00160e40 fight::ParamBool<hulkfight::motion::JointPlantedCondition>::vfunc_0 (30 B): matches/0x00160e40.cpp
// sym: ??_G?$ParamBool@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00160f60 fight::ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (30 B): matches/0x00160f60.cpp
// sym: ??_G?$ParamFloatConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00160f80 fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (30 B): matches/0x00160f80.cpp
// sym: ??_G?$ParamIntConstRange@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00160fe0 fight::ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00160fe0.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161000 fight::ParamBool<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00161000.cpp
// sym: ??_G?$ParamBool@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161020 fight::ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00161020.cpp
// sym: ??_G?$ParamIntConstRange@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161080 fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x00161080.cpp
// sym: ??_G?$ParamFloatConstRange@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x001610a0 fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x001610a0.cpp
// sym: ??_G?$ParamVector@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x001610c0 fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x001610c0.cpp
// sym: ??_G?$ParamIntConstRange@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161120 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161120.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161140 fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161140.cpp
// sym: ??_G?$ParamBool@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161160 fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161160.cpp
// sym: ??_G?$ParamIntConstRange@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x001611c0 fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (30 B): matches/0x001611c0.cpp
// sym: ??_G?$ParamFloatConstRange@VLocomotionSprintTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x001611e0 fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (30 B): matches/0x001611e0.cpp
// sym: ??_G?$ParamIntConstRange@VLocomotionSprintTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161240 fight::ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161240.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161260 fight::ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161260.cpp
// sym: ??_G?$ParamIntConstRange@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161ad0 fight::ParamNameConstList<hulkfight::motion::JointPlantedCondition>::vfunc_0 (30 B): matches/0x00161ad0.cpp
// sym: ??_G?$ParamNameConstList@VJointPlantedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161af0 fight::ParamName<hulkfight::motion::ClimbLocomotion4Track>::vfunc_0 (30 B): matches/0x00161af0.cpp
// sym: ??_G?$ParamName@VClimbLocomotion4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161b10 fight::ParamName<hulkfight::motion::LocomotionStrafe4Track>::vfunc_0 (30 B): matches/0x00161b10.cpp
// sym: ??_G?$ParamName@VLocomotionStrafe4Track@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161b30 fight::ParamName<hulkfight::motion::HeliLocomotionTrack>::vfunc_0 (30 B): matches/0x00161b30.cpp
// sym: ??_G?$ParamName@VHeliLocomotionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161b50 fight::ParamName<hulkfight::motion::LocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161b50.cpp
// sym: ??_G?$ParamName@VLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161b70 fight::ParamName<hulkfight::motion::LocomotionSprintTrack>::vfunc_0 (30 B): matches/0x00161b70.cpp
// sym: ??_G?$ParamName@VLocomotionSprintTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161b90 fight::ParamName<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0 (30 B): matches/0x00161b90.cpp
// sym: ??_G?$ParamName@VGrappleLocomotionSteerTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HeliLocomotionAction.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00161c10 / FUN_00161d80 / FUN_001622b0 / FUN_00162850 / FUN_00163050 / FUN_001633f0 / FUN_00163790)



// 0x00161c10 FUN_00161c10 (213 B): matches/0x00161c10.cpp
// sym: ?FUN_00161c10@@YAXXZ
// (gx2, D18) from unk_161c10.new_plain.cpp; constructs the real ParamBool<hulkfight::motion::JointPlantedCondition>, ParamFloatConstRange<hulkfight::motion::JointPlantedCondition>, ParamNameConstList<hulkfight::motion::JointPlantedCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00161c10()
{
    if (DAT_004e1164 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamNameConstList< ::hulkfight::motion::JointPlantedCondition>("joint", &fn_f68d580d::O_15a830::member);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::JointPlantedCondition>("thresholdDistance", &fn_f68d580d::Obj_15a840::Set);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::JointPlantedCondition>("planted", &fn_f68d580d::Obj_15a850::Set);
        FUN_002347b0(&DAT_004e1160, params, 3);
    }
    DAT_004e1164++;
}

namespace fn_f95ed483 {


// 0x00161d20 FUN_00161d20 (38 B): matches/0x00161d20.cpp
// sym: _FUN_00161d20
extern "C" void __cdecl FUN_00161d20(Owner* owner, void* source) {
    TrackFactoryCasterTemplate_161d20 caster;
    owner->Apply_002367c0(Find_00236ac0(source, &caster));
}


// 0x00161d50 FUN_00161d50 (38 B): matches/0x00161d50.cpp
// sym: _FUN_00161d50
extern "C" void FUN_00161d50(Owner* owner, void* value) {
    TrackFactoryCasterTemplate_161d50 caster;
    owner->add_002367c0(findTrack_00236ac0(value, &caster));
}


} // namespace fn_f95ed483

// 0x00161d80 FUN_00161d80 (1276 B): matches/0x00161d80.cpp
// sym: _FUN_00161d80
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::ClimbLocomotion4Track>, ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>, ParamName<hulkfight::motion::ClimbLocomotion4Track>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00161d80()
{
    if (DAT_004e117c == 0) {
        ::fight::ParamValue* params[24];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("timeBegin", &owners::Obj_15a8c0::FUN_0015a8c0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("timeEnd", &owners::A_15a8d0::FUN_0015a8d0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("acceleration", &owners::Obj_15a8f0::FUN_0015a8f0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("velocityLowNorth", &owners::C_15a910::FUN_0015a910);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("velocityLowStrafe", &owners::T_15a930::FUN_0015a930);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("velocityLowSouth", &owners::Obj_15a950::FUN_0015a950);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("velocityHighNorth", &owners::Obj_15a970::FUN_0015a970);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("velocityHighStrafe", &owners::Obj_15a990::FUN_0015a990);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("velocityHighSouth", &owners::Obj_15a9b0::FUN_0015a9b0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("phase", &owners::X_15a9d0::FUN_0015a9d0);
        params[10] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("locomotion", &owners::T_15a9e0::FUN_0015a9e0);
        params[11] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animIdle", &fn_f68d580d::FUN_0015a9f0);
        params[12] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animLowNorth", &fn_f68d580d::X_15aa00::Fn);
        params[13] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animLowEast", &owners::Obj_15aa10::FUN_0015aa10);
        params[14] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animLowSouth", &fn_f68d580d::FUN_0015aa20);
        params[15] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animLowWest", &owners::Obj_15aa30::FUN_0015aa30);
        params[16] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animHighNorth", &owners::Obj_15aa40::FUN_0015aa40);
        params[17] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animHighEast", &fn_f68d580d::Obj_15aa50::FUN_0015aa50);
        params[18] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animHighSouth", &owners::X_15aa60::FUN_0015aa60);
        params[19] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("animHighWest", &owners::Obj_15aa70::FUN_0015aa70);
        params[20] = new ::fight::ParamName< ::hulkfight::motion::ClimbLocomotion4Track>("partition", &owners::Obj_15aa80::FUN_0015aa80);
        params[21] = new ::fight::ParamIntConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("priority", &owners::Target_15aaa0::FUN_0015aaa0);
        params[22] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("blendInTime", &owners::Obj_15aac0::FUN_0015aac0);
        params[23] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ClimbLocomotion4Track>("blendOutTime", &owners::Obj_15aae0::FUN_0015aae0);
        FUN_002347b0(&DAT_004e1178, params, 24);
    }
    DAT_004e117c++;
}

namespace fn_f95ed483 {


// 0x00162280 FUN_00162280 (38 B): matches/0x00162280.cpp
// sym: _FUN_00162280
extern "C" void FUN_00162280(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_162280 c;
    void* v = find(p, &c);
    obj->run_002367c0(v);
}


} // namespace fn_f95ed483

// 0x001622b0 FUN_001622b0 (1378 B): matches/0x001622b0.cpp
// sym: _FUN_001622b0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::LocomotionStrafe4Track>, ParamFloatConstRange<hulkfight::motion::LocomotionStrafe4Track>, ParamIntConstRange<hulkfight::motion::LocomotionStrafe4Track>, ParamName<hulkfight::motion::LocomotionStrafe4Track>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001622b0()
{
    if (DAT_004e1184 == 0) {
        ::fight::ParamValue* params[26];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("timeBegin", &owners::Obj_15aaf0::FUN_0015aaf0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("timeEnd", &owners::Target_15ab00::FUN_0015ab00);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("acceleration", &owners::O_15ab20::FUN_0015ab20);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("turningVelocity", &owners::C_15ab40::FUN_0015ab40);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::LocomotionStrafe4Track>("steering", &owners::Obj_15ab70::FUN_0015ab70);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("velocityWalkNorth", &owners::O_15ab90::FUN_0015ab90);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("velocityWalkStrafe", &owners::Obj_15abb0::FUN_0015abb0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("velocityWalkSouth", &owners::Obj_15abd0::FUN_0015abd0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("velocityRunNorth", &owners::Obj_15abf0::FUN_0015abf0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("velocityRunStrafe", &owners::C_15ac10::FUN_0015ac10);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("velocityRunSouth", &owners::X_15ac30::FUN_0015ac30);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("phase", &owners::O_15ac50::FUN_0015ac50);
        params[12] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("locomotion", &owners::Obj_15ac60::FUN_0015ac60);
        params[13] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animIdle", &fn_f68d580d::FUN_0015ac70);
        params[14] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animWalkNorth", &owners::Obj_15ac80::FUN_0015ac80);
        params[15] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animWalkEast", &fn_f68d580d::FUN_0015ac90);
        params[16] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animWalkSouth", &owners::X_15aca0::FUN_0015aca0);
        params[17] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animWalkWest", &owners::A_15acb0::FUN_0015acb0);
        params[18] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animRunNorth", &owners::C_15acc0::FUN_0015acc0);
        params[19] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animRunEast", &owners::Obj_15acd0::FUN_0015acd0);
        params[20] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animRunSouth", &owners::A_15ace0::FUN_0015ace0);
        params[21] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("animRunWest", &fn_f68d580d::FUN_0015acf0);
        params[22] = new ::fight::ParamName< ::hulkfight::motion::LocomotionStrafe4Track>("partition", &owners::Obj_15ad00::FUN_0015ad00);
        params[23] = new ::fight::ParamIntConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("priority", &owners::C_15ad20::FUN_0015ad20);
        params[24] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("blendInTime", &owners::Obj_15ad40::FUN_0015ad40);
        params[25] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionStrafe4Track>("blendOutTime", &owners::O_15ad60::FUN_0015ad60);
        FUN_002347b0(&DAT_004e1180, params, 26);
    }
    DAT_004e1184++;
}

namespace fn_f95ed483 {


// 0x00162820 FUN_00162820 (38 B): matches/0x00162820.cpp
// sym: _FUN_00162820
extern "C" void FUN_00162820(Obj* o, void* p) {
    TrackFactoryCasterTemplate_162820 c;
    o->use_002367c0(Find_00236ac0(p, &c));
}


} // namespace fn_f95ed483

// 0x00162850 FUN_00162850 (1987 B): matches/0x00162850.cpp
// sym: _FUN_00162850
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>, ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>, ParamName<hulkfight::motion::HeliLocomotionTrack>, ParamVector<hulkfight::motion::HeliLocomotionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00162850()
{
    if (DAT_004e118c == 0) {
        ::fight::ParamValue* params[37];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("timeBegin", &owners::O_15ad70::FUN_0015ad70);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("timeEnd", &owners::Obj_15ad80::FUN_0015ad80);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("acceleration", &owners::C_15ada0::FUN_0015ada0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("velocity", &owners::Obj_15adc0::FUN_0015adc0);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("turnAcceleration", &owners::C_15ade0::FUN_0015ade0);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("turnVelocity", &owners::C_15ae10::FUN_0015ae10);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXDesiredAtRest", &owners::C_15ae40::FUN_0015ae40);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXDesiredAtMaxSpeed", &owners::Foo_15ae70::FUN_0015ae70);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXMin", &owners::C_15aea0::FUN_0015aea0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXMax", &owners::C_15aed0::FUN_0015aed0);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXMomentOfInertia", &owners::Obj_15af00::FUN_0015af00);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXSpringConstant", static_cast<bool (fn_0015af20::Obj_15af20::*)(int)>(&fn_0015af20::Obj_15af20::operator=));
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltXDampingConstant", &owners::C_15af40::FUN_0015af40);
        params[13] = new ::fight::ParamVector< ::hulkfight::motion::HeliLocomotionTrack>("tiltXInertiaPoint", &fn_f68d580d::Obj_15af70::Set);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZDesiredAtRest", &owners::C_15afa0::FUN_0015afa0);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZDesiredAtMaxSpeed", &owners::Foo_15afd0::FUN_0015afd0);
        params[16] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZMin", &owners::C_15b000::FUN_0015b000);
        params[17] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZMax", &owners::C_15b030::FUN_0015b030);
        params[18] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZMomentOfInertia", &owners::C_15b060::FUN_0015b060);
        params[19] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZSpringConstant", &owners::Obj_15b080::FUN_0015b080);
        params[20] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("tiltZDampingConstant", &owners::Obj_15b0a0::FUN_0015b0a0);
        params[21] = new ::fight::ParamVector< ::hulkfight::motion::HeliLocomotionTrack>("tiltZInertiaPoint", &fn_f68d580d::Obj_15b0b0::Set);
        params[22] = new ::fight::ParamVector< ::hulkfight::motion::HeliLocomotionTrack>("minimum", &fn_f68d580d::Obj_15b0f0::Set);
        params[23] = new ::fight::ParamVector< ::hulkfight::motion::HeliLocomotionTrack>("maximum", &fn_f68d580d::Tgt::Set);
        params[24] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HeliLocomotionTrack>("priority", &owners::Obj_15b180::FUN_0015b180);
        params[25] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("blendInTime", &owners::Obj_15b1a0::FUN_0015b1a0);
        params[26] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("blendOutTime", &owners::Obj_15b1c0::FUN_0015b1c0);
        params[27] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpSmoothingConstant", &owners::Obj_15b1e0::FUN_0015b1e0);
        params[28] = new ::fight::ParamName< ::hulkfight::motion::HeliLocomotionTrack>("riseUpJoint", &fn_f68d580d::FUN_0015b1f0);
        params[29] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpRayLength", &owners::Obj_15b210::FUN_0015b210);
        params[30] = new ::fight::ParamVector< ::hulkfight::motion::HeliLocomotionTrack>("riseUpOffset", &owners::Obj_15b220::FUN_0015b220);
        params[31] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpVelocity", &owners::Obj_15b250::FUN_0015b250);
        params[32] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpBoostAcceleration", &owners::Obj_15b270::FUN_0015b270);
        params[33] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpBoostXMax", &owners::Obj_15b290::FUN_0015b290);
        params[34] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpDecay", &owners::Obj_15b2b0::FUN_0015b2b0);
        params[35] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HeliLocomotionTrack>("riseUpDecayCutOff", &owners::Obj_15b2d0::FUN_0015b2d0);
        params[36] = new ::fight::ParamVector< ::hulkfight::motion::HeliLocomotionTrack>("riseUpDifference", &fn_f68d580d::Obj::Set);
        FUN_002347b0(&DAT_004e1188, params, 37);
    }
    DAT_004e118c++;
}



// 0x00163020 FUN_00163020 (38 B): matches/0x00163020.cpp [wrapped: conflict: Find]
// sym: _FUN_00163020
namespace fn_00163020 {
class TrackFactoryCasterTemplate_163020 {
  public:
    virtual bool cast_001610f0(void*);
};
class Track {
  public:
    void Set_002367c0(void*);
};
extern "C++" void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_163020*);
extern "C" void __cdecl FUN_00163020(Track* t, const char* name) {
    TrackFactoryCasterTemplate_163020 caster;
    t->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_00163020

namespace fn_f95ed483 {

} // namespace fn_f95ed483

// 0x00163050 FUN_00163050 (868 B): matches/0x00163050.cpp
// sym: _FUN_00163050
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::LocomotionSteerTrack>, ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>, ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>, ParamName<hulkfight::motion::LocomotionSteerTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00163050()
{
    if ((*(int*)&DAT_004e1194) == 0) {
        ::fight::ParamValue* params[16];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("timeBegin", &owners::Obj_15b340::FUN_0015b340);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("timeEnd", &owners::C_15b350::FUN_0015b350);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("acceleration", &owners::X_15b370::FUN_0015b370);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("turningVelocity", &owners::Thing_15b390::FUN_0015b390);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("velocityWalk", &owners::Obj_15b3c0::FUN_0015b3c0);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("velocityRun", &owners::O_15b3e0::FUN_0015b3e0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("phase", &owners::Obj_15b400::FUN_0015b400);
        params[7] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSteerTrack>("locomotion", &fn_f68d580d::Obj_15b410::GetValue);
        params[8] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSteerTrack>("animIdle", &owners::Obj_15b420::FUN_0015b420);
        params[9] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSteerTrack>("animWalk", &owners::O_15b430::FUN_0015b430);
        params[10] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSteerTrack>("animRun", &fn_f68d580d::Obj_15b440::Get);
        params[11] = new ::fight::ParamBool< ::hulkfight::motion::LocomotionSteerTrack>("locomoting", &owners::Obj_15b460::FUN_0015b460);
        params[12] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSteerTrack>("partition", &owners::Obj_15b470::FUN_0015b470);
        params[13] = new ::fight::ParamIntConstRange< ::hulkfight::motion::LocomotionSteerTrack>("priority", &owners::X_15b490::FUN_0015b490);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("blendInTime", &owners::Obj_15b4b0::FUN_0015b4b0);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSteerTrack>("blendOutTime", &owners::Obj_15b4d0::FUN_0015b4d0);
        FUN_002347b0(&DAT_004e1190, params, 16);
    }
    (*(int*)&DAT_004e1194)++;
}

namespace fn_f95ed483 {


// 0x001633c0 FUN_001633c0 (38 B): matches/0x001633c0.cpp
// sym: _FUN_001633c0
extern "C" void FUN_001633c0(Obj* obj, void* value) {
    TrackFactoryCasterTemplate_1633c0 c;
    void* p = Find_00236ac0(value, &c);
    obj->Do_002367c0(p);
}


} // namespace fn_f95ed483

// 0x001633f0 FUN_001633f0 (868 B): matches/0x001633f0.cpp
// sym: _FUN_001633f0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>, ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>, ParamName<hulkfight::motion::LocomotionSprintTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001633f0()
{
    if ((*(int*)&DAT_004e119c) == 0) {
        ::fight::ParamValue* params[16];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("timeBegin", &owners::Obj_15b4e0::FUN_0015b4e0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("timeEnd", &owners::Obj_15b4f0::FUN_0015b4f0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("velocity", &owners::X_15b510::FUN_0015b510);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("turnVelocity", &owners::Angle_15b530::FUN_0015b530);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("turnAcceleration", &owners::Angle_15b560::FUN_0015b560);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("leanThreshold", &owners::X_15b590::FUN_0015b590);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("leanRate", &owners::Obj_15b5b0::FUN_0015b5b0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("phase", &owners::A_15b5d0::FUN_0015b5d0);
        params[8] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSprintTrack>("locomotion", &fn_f68d580d::FUN_0015b5e0);
        params[9] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSprintTrack>("animRun", &fn_f68d580d::Obj_15b5f0::Get);
        params[10] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSprintTrack>("animLeanEast", &fn_f68d580d::A_15b600::Get);
        params[11] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSprintTrack>("animLeanWest", &owners::Obj_15b610::FUN_0015b610);
        params[12] = new ::fight::ParamName< ::hulkfight::motion::LocomotionSprintTrack>("partition", &owners::Obj_15b620::FUN_0015b620);
        params[13] = new ::fight::ParamIntConstRange< ::hulkfight::motion::LocomotionSprintTrack>("priority", &owners::Obj_15b640::FUN_0015b640);
        params[14] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("blendInTime", &owners::X_15b660::FUN_0015b660);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::LocomotionSprintTrack>("blendOutTime", &owners::Obj_15b680::FUN_0015b680);
        FUN_002347b0(&DAT_004e1198, params, 16);
    }
    (*(int*)&DAT_004e119c)++;
}

namespace fn_f95ed483 {


// 0x00163760 FUN_00163760 (38 B): matches/0x00163760.cpp
// sym: _FUN_00163760
extern "C" void FUN_00163760(Receiver* receiver, void* value) {
    TrackFactoryCasterTemplate_163760 caster;
    void* result = Find_00236ac0(value, &caster);
    receiver->Use_002367c0(result);
}


} // namespace fn_f95ed483

// 0x00163790 FUN_00163790 (562 B): matches/0x00163790.cpp
// sym: _FUN_00163790
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>, ParamIntConstRange<hulkfight::motion::GrappleLocomotionSteerTrack>, ParamName<hulkfight::motion::GrappleLocomotionSteerTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00163790()
{
    if (DAT_004e11a4 == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleLocomotionSteerTrack>("timeBegin", &owners::Obj_15b690::FUN_0015b690);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleLocomotionSteerTrack>("timeEnd", &owners::Obj_15b6a0::FUN_0015b6a0);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::GrappleLocomotionSteerTrack>("locomotion", &owners::Obj_15b6b0::FUN_0015b6b0);
        params[3] = new ::fight::ParamName< ::hulkfight::motion::GrappleLocomotionSteerTrack>("animIdle", &owners::Obj_15b6c0::FUN_0015b6c0);
        params[4] = new ::fight::ParamName< ::hulkfight::motion::GrappleLocomotionSteerTrack>("animWalk", &fn_f68d580d::FUN_0015b6d0);
        params[5] = new ::fight::ParamName< ::hulkfight::motion::GrappleLocomotionSteerTrack>("animRun", &fn_f68d580d::FUN_0015b6e0);
        params[6] = new ::fight::ParamName< ::hulkfight::motion::GrappleLocomotionSteerTrack>("partition", &owners::Obj_15b6f0::FUN_0015b6f0);
        params[7] = new ::fight::ParamIntConstRange< ::hulkfight::motion::GrappleLocomotionSteerTrack>("priority", &owners::Obj_15b710::FUN_0015b710);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleLocomotionSteerTrack>("blendInTime", &owners::Obj_15b730::FUN_0015b730);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleLocomotionSteerTrack>("blendOutTime", &owners::Obj_15b750::FUN_0015b750);
        FUN_002347b0(&DAT_004e11a0, params, 10);
    }
    DAT_004e11a4++;
}



// 0x00163a20 FUN_00163a20 (111 B): matches/0x00163a20.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_00163a20
namespace fn_00163a20 {
// FUN_00163a20 @ 0x00163a20
namespace hulkfight { namespace motion { class PhaseCondition; class JointPlantedCondition; class LocomotingCondition; } }
namespace fight { template<class T> struct ConditionFactoryCasterTemplate { virtual void create(); }; }
struct Registry_163a20 { void FUN_00236760(void *factory); };
extern "C" void *__cdecl FUN_002343e0(const char *name, void *caster);

extern "C" void __cdecl FUN_00163a20(Registry_163a20 *r)
{
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::PhaseCondition> caster;
        r->FUN_00236760(FUN_002343e0("phase", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::JointPlantedCondition> caster;
        r->FUN_00236760(FUN_002343e0("jointPlanted", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition> caster;
        r->FUN_00236760(FUN_002343e0("locomoting", &caster));
    }
}
} // namespace fn_00163a20

