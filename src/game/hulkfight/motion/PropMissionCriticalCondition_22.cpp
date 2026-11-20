// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00187340..0x00188ab0 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropAddToCollisionTrack); was game/hulkfight/motion/PropAddToCollisionTrack_3.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/engine/unknown.h"   // (gx3, D18) for the merged registrations
#include "decls/data/engine/fight.h"   // (gx3, D18) for the merged registrations
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f5c5d2a1 {
#define TREE_TU_END }
namespace fn_f5c5d2a1 {} using namespace fn_f5c5d2a1;
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f4259b06 { struct A_1803b0 { char SetAttachmentIndex_001803b0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct C_17f5e0 { char SetState_0017f5e0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct C_17fe80 { bool SetState_0017fe80(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f5a0 { bool SetAttachmentIndex_0017f5a0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f600 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f620 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f640 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f6b0 { char SetTimeBegin_0017f6b0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f6d0 { char SetAttachmentIndex_0017f6d0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f710 { unsigned char SetAtEnd_0017f710(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f8b0 { bool SetAttachmentIndex_0017f8b0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f8f0 { char SetDamageMax_0017f8f0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17fe60 { char SetAttachmentIndex_0017fe60(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_180340 { char Fn(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_1803d0 { bool SetMissiles_001803d0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_1803e0 { char SetTimeBegin_001803e0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_180420 { char SetDamage_00180420(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct T_180390 { char SetTimeBegin_00180390(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Target_17f6f0 { bool SetSimulate_0017f6f0(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Thing { bool SetTimeBegin_0017fe40(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_17f5c0 { char SetCompare_0017f5c0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_17f890 { char SetTimeBegin_0017f890(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_17f8d0 { char SetDamage_0017f8d0(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_180360 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_180380 { char Set(char); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_180400 { bool SetAttachmentIndex_00180400(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp

// ---- declarations shared by the functions below
namespace fight {
class TrackFactory_187340 {
  public:
    virtual void dummy();
};
}
namespace fight {
template <class T> class TrackFactoryTemplate_187340 : public TrackFactory_187340 {};
}
namespace fight {
class TrackFactoryCaster_187340 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class ShieldArcTrack_187340;
} }
namespace fn_f5c5d2a1 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be510;
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_1873a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropAddToCollisionTrack_1873a0;
} }
namespace fn_f5c5d2a1 {
extern "C" int __cdecl Check(void*, int, void*, void*, int);
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_187440 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropAddToMissileCountTrack_187440 {};
} }
namespace fn_f5c5d2a1 {
extern char DAT_004be5c8;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern char DAT_004be680;
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_1874c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropDamageTrack_1874c0 {};
} }
namespace fn_f5c5d2a1 {
extern char DAT_004be728;
} // namespace fn_f5c5d2a1
namespace fight {
class TrackFactoryCaster_187540 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class TrackFactoryCaster_1875e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropDestroyTrack_1875e0 {};
} }
namespace fn_f5c5d2a1 {
extern char DAT_004be7d0;
} // namespace fn_f5c5d2a1
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f5c5d2a1 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
} // namespace fn_f5c5d2a1
namespace hulkfight { namespace motion {
class PropMissionCriticalCondition_187650 {
public:
    char FUN_0017f2b0(int); /* (unb4) as defined; address taken only */
    char FUN_0017f2d0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f5c5d2a1 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f5c5d2a1
namespace fight {
template <class T>
class ParamBool_187650 : public ParamBoolBase {
public:
    ParamBool_187650(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187650 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187650(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f5c5d2a1 {
} // namespace fn_f5c5d2a1
namespace hulkfight { namespace motion {
class SmartPropGrabbableCondition_1876f0 {
public:
    char FUN_0017f2f0(char); /* (unb4) as defined; address taken only */
    char FUN_0017f310(int); /* (unb4) as defined; address taken only */
    char FUN_0017f330(char); /* (unb4) as defined; address taken only */
    char FUN_0017f350(char); /* (unb4) as defined; address taken only */
    char FUN_0017f370(char); /* (unb4) as defined; address taken only */
    bool FUN_0017f390(int); /* (unb4) as defined; address taken only */
    char FUN_0017f3b0(char); /* (unb4) as defined; address taken only */
    bool FUN_0017f3d0(int); /* (unb4) as defined; address taken only */
    char FUN_0017f3f0(char); /* (unb4) as defined; address taken only */
    bool FUN_0017f410(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_1876f0 : public ParamBoolBase {
public:
    ParamBool_1876f0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_1876f0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1876f0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace hulkfight { namespace motion {
class PropGrabbableIsThrownCondition_187960 {
public:
    char FUN_0017f470(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_187960 : public ParamBoolBase {
public:
    ParamBool_187960(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropAtRestCondition_1879c0 {
public:
    char FUN_0017f500(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_1879c0 : public ParamBoolBase {
public:
    ParamBool_1879c0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropIsAttachedCondition_187a20 {
public:
    bool FUN_0017f520(int); /* (unb4) as defined; address taken only */
    char FUN_0017f530(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_187a20 : public ParamBoolBase {
public:
    ParamBool_187a20(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187a20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187a20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropCollidedWithWorldCondition_187ca0 {
public:
    bool FUN_0017f660(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f670(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_187ca0 : public ParamBoolBase {
public:
    ParamBool_187ca0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187ca0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187ca0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CSMPropIsCharacterCondition_187da0 {
public:
    bool FUN_0017f6a0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_187da0 : public ParamBoolBase {
public:
    ParamBool_187da0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropActorThinkingTrack_187f00 {
public:
    char FUN_0017f760(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f780(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f5c5d2a1 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f5c5d2a1
namespace fight {
template <class T>
class ParamBool_187f00 : public ParamBoolBase {
public:
    ParamBool_187f00(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_187f00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_187f00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropDropTrack_187fa0 {
public:
    char FUN_0017f790(int); /* (unb4) as defined; address taken only */
    char FUN_0017f7b0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_187fa0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_187fa0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_187fa0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187fa0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class BallAndChainSpinTrack_188220 {
public:
    char FUN_001801c0(int); /* (unb4) as defined; address taken only */
    char FUN_001801d0(int); /* (unb4) as defined; address taken only */
    char FUN_001801f0(int); /* (unb4) as defined; address taken only */
    char FUN_00180210(int); /* (unb4) as defined; address taken only */
    bool FUN_00180230(int); /* (unb4) as defined; address taken only */
    char FUN_00180250(float); /* (unb4) as defined; address taken only */
    bool FUN_00180280(float); /* (unb4) as defined; address taken only */
    char FUN_001802c0(void*); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f5c5d2a1 {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
} // namespace fn_f5c5d2a1
namespace hulkfight { namespace motion {
class ShieldArcTrack_1883f0 {
public:
    bool FUN_00180300(int); /* (unb4) as defined; address taken only */
    bool FUN_00180320(float); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_1883f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1883f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class PropDestroyTrack_188730 {
public:
    char FUN_00180580(int); /* (unb4) as defined; address taken only */
    bool FUN_001805a0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_188730 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_188730(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_188730 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_188730(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f5c5d2a1 {
struct RefCounted_188820 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419608[];
class PropActorToPropAction_188820 {
  public:
    PropActorToPropAction_188820* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188820* m_20;
};
struct RefCounted_1888c0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419624[];
class PropActorThinkingAction_1888c0 {
  public:
    PropActorThinkingAction_1888c0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1888c0* m_20;
};
extern int FUN_00344e74(int, int, const void*, const void*, int);
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
class AllocObj_188910 {
  public:
    int init_00183aa0(hulkfight::motion::PropAnimationTrack*, hulk_intptr);
};
class Ref_188960 {
  public:
    virtual void f0();
    virtual void f1();
};
class Action {
  public:
    virtual void f0();
    virtual void f1();
    virtual int f2(char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void baseCleanup_002326a0();
};
class PropAnimationAction : public Action {
  public:
    char pad[0x18];
    int m1c;
    Ref_188960* m20;
    Ref_188960* m24;
    Ref_188960* m28;
    virtual int f2(char);
};
extern char hulk_at_00419640[];
extern void thunk_0008d330(PropAnimationAction*);
struct RefCounted_188a10 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041965c[];
class PropAddToMissileCountAction_188a10 {
  public:
    PropAddToMissileCountAction_188a10* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_188a10* m_20;
};

} // namespace fn_f5c5d2a1

// 0x001866b0 fight::ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0 (30 B): matches/0x001866b0.cpp
// sym: ??_G?$ParamIntConstRange@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMissionCriticalCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x001866d0 fight::ParamBool<hulkfight::motion::PropMissionCriticalCondition>::vfunc_0 (30 B): matches/0x001866d0.cpp
// sym: ??_G?$ParamBool@VPropMissionCriticalCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMissionCriticalCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186730 fight::ParamBool<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_0 (30 B): matches/0x00186730.cpp
// sym: ??_G?$ParamBool@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SmartPropGrabbableCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186750 fight::ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>::vfunc_0 (30 B): matches/0x00186750.cpp
// sym: ??_G?$ParamEnumConstList@VSmartPropGrabbableCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SmartPropGrabbableCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186830 fight::ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>::vfunc_0 (30 B): matches/0x00186830.cpp
// sym: ??_G?$ParamBool@VPropGrabbableIsThrownCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMassCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186930 fight::ParamBool<hulkfight::motion::PropAtRestCondition>::vfunc_0 (30 B): matches/0x00186930.cpp
// sym: ??_G?$ParamBool@VPropAtRestCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropIsAttachedCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186990 fight::ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>::vfunc_0 (30 B): matches/0x00186990.cpp
// sym: ??_G?$ParamIntConstRange@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropIsAttachedCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x001869b0 fight::ParamBool<hulkfight::motion::PropIsAttachedCondition>::vfunc_0 (30 B): matches/0x001869b0.cpp
// sym: ??_G?$ParamBool@VPropIsAttachedCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropIsAttachedCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186a90 fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::vfunc_0 (30 B): matches/0x00186a90.cpp
// sym: ??_G?$ParamIntConstRange@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropStateByIndexCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186ab0 fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_0 (30 B): matches/0x00186ab0.cpp
// sym: ??_G?$ParamEnumConstList@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropStateByIndexCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186b10 fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::vfunc_0 (30 B): matches/0x00186b10.cpp
// sym: ??_G?$ParamIntConstRange@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMissileCountCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186b30 fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_0 (30 B): matches/0x00186b30.cpp
// sym: ??_G?$ParamEnumConstList@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMissileCountCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186b90 fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0 (30 B): matches/0x00186b90.cpp
// sym: ??_G?$ParamIntConstRange@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropCollidedWithWorldCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186bb0 fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_0 (30 B): matches/0x00186bb0.cpp
// sym: ??_G?$ParamBool@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropCollidedWithWorldCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186c10 fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_0 (30 B): matches/0x00186c10.cpp
// sym: ??_G?$ParamIntConstRange@VSmartPropIsCargoCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorToPropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186c70 fight::ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_0 (30 B): matches/0x00186c70.cpp
// sym: ??_G?$ParamBool@VCSMPropIsCharacterCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorToPropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186cd0 fight::ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (30 B): matches/0x00186cd0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorToPropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186cf0 fight::ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (30 B): matches/0x00186cf0.cpp
// sym: ??_G?$ParamIntConstRange@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorToPropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186d10 fight::ParamBool<hulkfight::motion::PropActorToPropTrack>::vfunc_0 (30 B): matches/0x00186d10.cpp
// sym: ??_G?$ParamBool@VPropActorToPropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorToPropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186df0 fight::ParamFloatConstRange<hulkfight::motion::PropActorThinkingTrack>::vfunc_0 (30 B): matches/0x00186df0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorThinkingTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186e10 fight::ParamBool<hulkfight::motion::PropActorThinkingTrack>::vfunc_0 (30 B): matches/0x00186e10.cpp
// sym: ??_G?$ParamBool@VPropActorThinkingTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropActorThinkingTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186e70 fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::vfunc_0 (30 B): matches/0x00186e70.cpp
// sym: ??_G?$ParamFloatConstRange@VPropDropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropDropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186e90 fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::vfunc_0 (30 B): matches/0x00186e90.cpp
// sym: ??_G?$ParamIntConstRange@VPropDropTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropDropTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186f90 fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0 (30 B): matches/0x00186f90.cpp
// sym: ??_G?$ParamFloatConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from GrapplePropDamageTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00186fb0 fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_0 (30 B): matches/0x00186fb0.cpp
// sym: ??_G?$ParamIntConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from GrapplePropDamageTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00187190 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0 (30 B): matches/0x00187190.cpp
// sym: ??_G?$ParamFloatConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropSetStateByIndexTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x001871b0 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_0 (30 B): matches/0x001871b0.cpp
// sym: ??_G?$ParamIntConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropSetStateByIndexTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x001872d0 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (30 B): matches/0x001872d0.cpp
// sym: ??_G?$ParamFloatConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainSpinTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x001872f0 fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (30 B): matches/0x001872f0.cpp
// sym: ??_G?$ParamIntConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainSpinTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00187310 fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (30 B): matches/0x00187310.cpp
// sym: ??_G?$ParamVector@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainSpinTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00187650 / FUN_001876f0 / FUN_00187960 / FUN_001879c0 / FUN_00187a20 / FUN_00187ac0 / FUN_00187bb0 / FUN_00187ca0 / FUN_00187d40 / FUN_00187da0 / FUN_00187e00 / FUN_00187f00 / FUN_00187fa0 / FUN_00188040 / FUN_00188140 / FUN_00188220 / FUN_001883f0 / FUN_00188490 / FUN_00188570 / FUN_00188650 / FUN_00188730)



// 0x00187340 fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0 (36 B): matches/0x00187340.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VShieldArcTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
// the original asks whether a factory is the ShieldArcTrack one: dynamic_cast from fight::TrackFactory (RTTI 0x0049850c)
// to fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack> (0x004be460)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return dynamic_cast<fight::TrackFactoryTemplate_187340<hulkfight::motion::ShieldArcTrack_187340>*>((fight::TrackFactory_187340*)p) != 0;
}


// 0x00187370 fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::vfunc_0 (30 B): matches/0x00187370.cpp
// sym: ??_G?$ParamFloatConstRange@VShieldArcTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001873a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (36 B): matches/0x001873a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be510, 0) != 0;
}


// 0x001873d0 fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (30 B): matches/0x001873d0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001873f0 fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (30 B): matches/0x001873f0.cpp
// sym: ??_G?$ParamIntConstRange@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00187410 fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::vfunc_0 (30 B): matches/0x00187410.cpp
// sym: ??_G?$ParamBool@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00187440 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0 (36 B): matches/0x00187440.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004be5c8, 0) != 0;
}


// 0x00187470 fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0 (30 B): matches/0x00187470.cpp
// sym: ??_G?$ParamFloatConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00187490 fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0 (30 B): matches/0x00187490.cpp
// sym: ??_G?$ParamIntConstRange@VPropAddToMissileCountTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001874c0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_0 (36 B): matches/0x001874c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropDamageTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be680, 0) != 0;
}


// 0x001874f0 fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::vfunc_0 (30 B): matches/0x001874f0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00187510 fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::vfunc_0 (30 B): matches/0x00187510.cpp
// sym: ??_G?$ParamIntConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00187540 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_0 (36 B): matches/0x00187540.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be728, 0) != 0;
}


// 0x001875e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_0 (36 B): matches/0x001875e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropDestroyTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be7d0, 0) != 0;
}


// 0x00187610 fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_0 (30 B): matches/0x00187610.cpp
// sym: ??_G?$ParamFloatConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00187630 fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_0 (30 B): matches/0x00187630.cpp
// sym: ??_G?$ParamIntConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_f5c5d2a1 {

} // namespace fn_f5c5d2a1

namespace fn_f5c5d2a1 {

} // namespace fn_f5c5d2a1

namespace fn_f5c5d2a1 {

} // namespace fn_f5c5d2a1

// 0x00187650 FUN_00187650 (158 B): matches/0x00187650.cpp
// sym: _FUN_00187650
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropMissionCriticalCondition>, ParamIntConstRange<hulkfight::motion::PropMissionCriticalCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187650()
{
    if (DAT_004e1404 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropMissionCriticalCondition>("attachmentIndex", &owners::Obj_17f2b0::FUN_0017f2b0);
        params[1] = new ::fight::ParamBool< ::hulkfight::motion::PropMissionCriticalCondition>("missionCritical", &owners::O_17f2d0::FUN_0017f2d0);
        FUN_002347b0(&DAT_004e1400, params, 2);
    }
    DAT_004e1404++;
}



// 0x001876f0 FUN_001876f0 (618 B): matches/0x001876f0.cpp
// sym: _FUN_001876f0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::SmartPropGrabbableCondition>, ParamEnumConstList<hulkfight::motion::SmartPropGrabbableCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001876f0()
{
    if (DAT_004e140c == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::SmartPropGrabbableCondition>("matchObjectClass", &owners::Obj_17f2f0::FUN_0017f2f0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::SmartPropGrabbableCondition>("objectClass", (void*)&DAT_004c5fd0, 23, &owners::Obj_17f310::FUN_0017f310);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::SmartPropGrabbableCondition>("matchCargo", &owners::Obj_17f330::FUN_0017f330);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::SmartPropGrabbableCondition>("isCargo", &owners::X_17f350::FUN_0017f350);
        params[4] = new ::fight::ParamBool< ::hulkfight::motion::SmartPropGrabbableCondition>("matchWeaponType", &owners::X_17f370::FUN_0017f370);
        params[5] = new ::fight::ParamEnumConstList< ::hulkfight::motion::SmartPropGrabbableCondition>("weaponType", (void*)&DAT_004c5fd0[22], 7, &owners::Obj_17f390::FUN_0017f390);
        params[6] = new ::fight::ParamBool< ::hulkfight::motion::SmartPropGrabbableCondition>("matchWeaponizableType", &owners::Obj_17f3b0::FUN_0017f3b0);
        params[7] = new ::fight::ParamEnumConstList< ::hulkfight::motion::SmartPropGrabbableCondition>("weaponizableType", (void*)&DAT_004c5fd0[22], 7, &owners::Obj_17f3d0::FUN_0017f3d0);
        params[8] = new ::fight::ParamBool< ::hulkfight::motion::SmartPropGrabbableCondition>("matchHasEvent", &owners::Obj_17f3f0::FUN_0017f3f0);
        params[9] = new ::fight::ParamEnumConstList< ::hulkfight::motion::SmartPropGrabbableCondition>("event", (void*)&DAT_00496168, 16, &owners::Obj_17f410::FUN_0017f410);
        FUN_002347b0(&DAT_004e1408, params, 10);
    }
    DAT_004e140c++;
}



// 0x00187960 FUN_00187960 (95 B): matches/0x00187960.cpp
// sym: _FUN_00187960
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropGrabbableIsThrownCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187960()
{
    if (DAT_004e141c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::PropGrabbableIsThrownCondition>("isThrown", &owners::X_17f470::FUN_0017f470);
        FUN_002347b0(&DAT_004e1418, params, 1);
    }
    DAT_004e141c++;
}



// 0x001879c0 FUN_001879c0 (95 B): matches/0x001879c0.cpp
// sym: _FUN_001879c0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropAtRestCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001879c0()
{
    if (DAT_004e142c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::PropAtRestCondition>("atRest", &owners::A_17f500::FUN_0017f500);
        FUN_002347b0(&DAT_004e1428, params, 1);
    }
    DAT_004e142c++;
}



// 0x00187a20 FUN_00187a20 (158 B): matches/0x00187a20.cpp
// sym: _FUN_00187a20
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropIsAttachedCondition>, ParamIntConstRange<hulkfight::motion::PropIsAttachedCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187a20()
{
    if (DAT_004e1434 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropIsAttachedCondition>("attachmentIndex", &owners::Obj_17f520::FUN_0017f520);
        params[1] = new ::fight::ParamBool< ::hulkfight::motion::PropIsAttachedCondition>("isAttached", &owners::Obj_17f530::FUN_0017f530);
        FUN_002347b0(&DAT_004e1430, params, 2);
    }
    DAT_004e1434++;
}



// 0x00187ac0 FUN_00187ac0 (231 B): matches/0x00187ac0.cpp
// sym: _FUN_00187ac0
// (gx2, D18) from PropAddToCollisionTrack_3.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>, ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187ac0()
{
    if (DAT_004e1444 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropStateByIndexCondition>("attachmentIndex", &fn_f4259b06::Obj_17f5a0::SetAttachmentIndex_0017f5a0);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::PropStateByIndexCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f4259b06::X_17f5c0::SetCompare_0017f5c0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropStateByIndexCondition>("state", &fn_f4259b06::C_17f5e0::SetState_0017f5e0);
        FUN_002347b0(&DAT_004e1440, params, 3);
    }
    DAT_004e1444++;
}



// 0x00187bb0 FUN_00187bb0 (231 B): matches/0x00187bb0.cpp
// sym: ?FUN_00187bb0@@YAXXZ
// (gx2, D18) from PropAddToCollisionTrack_3.iso_00187bb0.cpp; constructs the real ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>, ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00187bb0()
{
    if (DAT_004e144c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropMissileCountCondition>("attachmentIndex", &fn_f4259b06::Obj_17f600::Set);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::PropMissileCountCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f4259b06::Obj_17f620::Set);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropMissileCountCondition>("missiles", &fn_f4259b06::Obj_17f640::Set);
        FUN_002347b0(&DAT_004e1448, params, 3);
    }
    DAT_004e144c++;
}



// 0x00187ca0 FUN_00187ca0 (158 B): matches/0x00187ca0.cpp
// sym: _FUN_00187ca0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>, ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187ca0()
{
    if (DAT_004e1454 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropCollidedWithWorldCondition>("attachmentIndex", &owners::Obj_17f660::FUN_0017f660);
        params[1] = new ::fight::ParamBool< ::hulkfight::motion::PropCollidedWithWorldCondition>("collided", &owners::Obj_17f670::FUN_0017f670);
        FUN_002347b0(&DAT_004e1450, params, 2);
    }
    DAT_004e1454++;
}



// 0x00187d40 FUN_00187d40 (95 B): matches/0x00187d40.cpp
// sym: _FUN_00187d40
// (gx2, D18) rewritten; constructs the real ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187d40()
{
    if (DAT_004e145c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::SmartPropIsCargoCondition>("attachmentIndex", &owners::Target_17f690::FUN_0017f690);
        FUN_002347b0(&DAT_004e1458, params, 1);
    }
    DAT_004e145c++;
}



// 0x00187da0 FUN_00187da0 (95 B): matches/0x00187da0.cpp
// sym: _FUN_00187da0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::CSMPropIsCharacterCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187da0()
{
    if (DAT_004e1464 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::motion::CSMPropIsCharacterCondition>("isCharacter", &owners::C_17f6a0::FUN_0017f6a0);
        FUN_002347b0(&DAT_004e1460, params, 1);
    }
    DAT_004e1464++;
}



// 0x00187e00 FUN_00187e00 (256 B): matches/0x00187e00.cpp
// sym: ?FUN_00187e00@@YAXXZ
// (gx2, D18) from PropAddToCollisionTrack_3.iso_00187e00.cpp; constructs the real ParamBool<hulkfight::motion::PropActorToPropTrack>, ParamFloatConstRange<hulkfight::motion::PropActorToPropTrack>, ParamIntConstRange<hulkfight::motion::PropActorToPropTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00187e00()
{
    if (DAT_004e146c == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropActorToPropTrack>("timeBegin", &fn_f4259b06::Obj_17f6b0::SetTimeBegin_0017f6b0);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropActorToPropTrack>("attachmentIndex", &fn_f4259b06::Obj_17f6d0::SetAttachmentIndex_0017f6d0);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::PropActorToPropTrack>("simulate", &fn_f4259b06::Target_17f6f0::SetSimulate_0017f6f0);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::PropActorToPropTrack>("atEnd", &fn_f4259b06::Obj_17f710::SetAtEnd_0017f710);
        FUN_002347b0(&DAT_004e1468, params, 4);
    }
    DAT_004e146c++;
}



// 0x00187f00 FUN_00187f00 (158 B): matches/0x00187f00.cpp
// sym: _FUN_00187f00
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropActorThinkingTrack>, ParamFloatConstRange<hulkfight::motion::PropActorThinkingTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187f00()
{
    if (DAT_004e147c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropActorThinkingTrack>("timeBegin", &owners::Obj_17f760::FUN_0017f760);
        params[1] = new ::fight::ParamBool< ::hulkfight::motion::PropActorThinkingTrack>("thinking", &owners::X_17f780::FUN_0017f780);
        FUN_002347b0(&DAT_004e1478, params, 2);
    }
    DAT_004e147c++;
}



// 0x00187fa0 FUN_00187fa0 (158 B): matches/0x00187fa0.cpp
// sym: _FUN_00187fa0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::PropDropTrack>, ParamIntConstRange<hulkfight::motion::PropDropTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00187fa0()
{
    if (DAT_004e1484 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropDropTrack>("timeBegin", &owners::Obj_17f790::FUN_0017f790);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropDropTrack>("attachmentIndex", &owners::Obj_17f7b0::FUN_0017f7b0);
        FUN_002347b0(&DAT_004e1480, params, 2);
    }
    DAT_004e1484++;
}



// 0x00188040 FUN_00188040 (256 B): matches/0x00188040.cpp
// sym: _FUN_00188040
// (gx2, D18) from PropAddToCollisionTrack_3.iso_00188040.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>, ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00188040()
{
    if (DAT_004e1494 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrapplePropDamageTrack>("timeBegin", &fn_f4259b06::X_17f890::SetTimeBegin_0017f890);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::GrapplePropDamageTrack>("attachmentIndex", &fn_f4259b06::Obj_17f8b0::SetAttachmentIndex_0017f8b0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrapplePropDamageTrack>("damage", &fn_f4259b06::X_17f8d0::SetDamage_0017f8d0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrapplePropDamageTrack>("damageMax", &fn_f4259b06::Obj_17f8f0::SetDamageMax_0017f8f0);
        FUN_002347b0(&DAT_004e1490, params, 4);
    }
    DAT_004e1494++;
}



// 0x00188140 FUN_00188140 (213 B): matches/0x00188140.cpp
// sym: _FUN_00188140
// (gx2, D18) from PropAddToCollisionTrack_3.iso_00188140.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>, ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00188140()
{
    if (DAT_004e14ac == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropSetStateByIndexTrack>("timeBegin", &fn_f4259b06::Thing::SetTimeBegin_0017fe40);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropSetStateByIndexTrack>("attachmentIndex", &fn_f4259b06::Obj_17fe60::SetAttachmentIndex_0017fe60);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropSetStateByIndexTrack>("state", &fn_f4259b06::C_17fe80::SetState_0017fe80);
        FUN_002347b0(&DAT_004e14a8, params, 3);
    }
    DAT_004e14ac++;
}



// 0x00188220 FUN_00188220 (460 B): matches/0x00188220.cpp
// sym: _FUN_00188220
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>, ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>, ParamVector<hulkfight::motion::BallAndChainSpinTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00188220()
{
    if (DAT_004e14bc == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("timeBegin", &owners::O_1801c0::FUN_001801c0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("timeEnd", &owners::Obj_1801d0::FUN_001801d0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("attachmentIndex", &owners::X_1801f0::FUN_001801f0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("radius", &owners::Obj_180210::FUN_00180210);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("height", &owners::X_180230::FUN_00180230);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("startAngle", &owners::Obj_180250::FUN_00180250);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainSpinTrack>("spinVelocity", &owners::Obj_180280::FUN_00180280);
        params[7] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainSpinTrack>("orient", &owners::Angles_1802c0::FUN_001802c0);
        FUN_002347b0(&DAT_004e14b8, params, 8);
    }
    DAT_004e14bc++;
}



// 0x001883f0 FUN_001883f0 (158 B): matches/0x001883f0.cpp
// sym: _FUN_001883f0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001883f0()
{
    if (DAT_004e14c4 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ShieldArcTrack>("timeBegin", &owners::X_180300::FUN_00180300);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::ShieldArcTrack>("arc", &owners::Thing_180320::FUN_00180320);
        FUN_002347b0(&DAT_004e14c0, params, 2);
    }
    DAT_004e14c4++;
}



// 0x00188490 FUN_00188490 (213 B): matches/0x00188490.cpp
// sym: _FUN_00188490
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropAddToCollisionTrack>, ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>, ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00188490()
{
    if (DAT_004e14cc == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAddToCollisionTrack>("timeBegin", &fn_f4259b06::Obj_180340::Fn);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropAddToCollisionTrack>("attachmentIndex", &fn_f4259b06::X_180360::Set);
        params[2] = new ::fight::ParamBool< ::hulkfight::motion::PropAddToCollisionTrack>("addMissile", &fn_f4259b06::X_180380::Set);
        FUN_002347b0(&DAT_004e14c8, params, 3);
    }
    DAT_004e14cc++;
}



// 0x00188570 FUN_00188570 (213 B): matches/0x00188570.cpp
// sym: _FUN_00188570
// (gx2, D18) from PropAddToCollisionTrack_3.iso_00188570.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>, ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00188570()
{
    if (DAT_004e14d4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAddToMissileCountTrack>("timeBegin", &fn_f4259b06::T_180390::SetTimeBegin_00180390);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropAddToMissileCountTrack>("attachmentIndex", &fn_f4259b06::A_1803b0::SetAttachmentIndex_001803b0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropAddToMissileCountTrack>("missiles", &fn_f4259b06::Obj_1803d0::SetMissiles_001803d0);
        FUN_002347b0(&DAT_004e14d0, params, 3);
    }
    DAT_004e14d4++;
}



// 0x00188650 FUN_00188650 (213 B): matches/0x00188650.cpp
// sym: ?FUN_00188650@@YAXXZ
// (gx2, D18) from PropAddToCollisionTrack_3.iso_00188650.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::PropDamageTrack>, ParamIntConstRange<hulkfight::motion::PropDamageTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00188650()
{
    if (DAT_004e14dc == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropDamageTrack>("timeBegin", &fn_f4259b06::Obj_1803e0::SetTimeBegin_001803e0);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropDamageTrack>("attachmentIndex", &fn_f4259b06::X_180400::SetAttachmentIndex_00180400);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropDamageTrack>("damage", &fn_f4259b06::Obj_180420::SetDamage_00180420);
        FUN_002347b0(&DAT_004e14d8, params, 3);
    }
    DAT_004e14dc++;
}



// 0x00188730 FUN_00188730 (158 B): matches/0x00188730.cpp
// sym: _FUN_00188730
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>, ParamIntConstRange<hulkfight::motion::PropDestroyTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00188730()
{
    if (DAT_004e14ec == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropDestroyTrack>("timeBegin", &owners::X_180580::FUN_00180580);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropDestroyTrack>("attachmentIndex", &owners::Obj_1805a0::FUN_001805a0);
        FUN_002347b0(&DAT_004e14e8, params, 2);
    }
    DAT_004e14ec++;
}

namespace fn_f5c5d2a1 {


// 0x00188820 hulkfight::motion::PropActorToPropAction::vfunc_2 (71 B): matches/0x00188820.cpp
// sym: ?vfunc_2@PropActorToPropAction_188820@fn_f5c5d2a1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropActorToPropAction_188820* PropActorToPropAction_188820::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419608;
    RefCounted_188820* q = *(RefCounted_188820* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        ::operator delete(this);
    }
    return this;
}


// 0x001888c0 hulkfight::motion::PropActorThinkingAction::vfunc_2 (71 B): matches/0x001888c0.cpp
// sym: ?vfunc_2@PropActorThinkingAction_1888c0@fn_f5c5d2a1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropActorThinkingAction_1888c0* PropActorThinkingAction_1888c0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419624;
    RefCounted_1888c0* q = *(RefCounted_1888c0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        ::operator delete(this);
    }
    return this;
}

} // namespace fn_f5c5d2a1

// 0x00188910 hulkfight::motion::PropAnimationTrack::vfunc_10 (70 B): matches/0x00188910.cpp
// sym: ?vfunc_10@PropAnimationTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001134e0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_188910* p = (AllocObj_188910*)FUN_0008d690((unsigned int)sizeof(::hulkfight::motion::PropAnimationAction));
        if (p)
            return p->init_00183aa0(this, c);
    }
    return 0;
}

namespace fn_f5c5d2a1 {

// 0x00188960 hulkfight::motion::PropAnimationAction::vfunc_2 (95 B): matches/0x00188960.cpp
// sym: ?f2@PropAnimationAction@fn_f5c5d2a1@@UAEHD@Z
int PropAnimationAction::f2(char param) {
    *(void**)this = (void*)hulk_at_00419640;
    _ReadWriteBarrier();
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    this->Action::baseCleanup_002326a0();
    if (param & 1)
        thunk_0008d330(this);
    return (hulk_intptr)this;
}


// 0x00188a10 hulkfight::motion::PropAddToMissileCountAction::vfunc_2 (71 B): matches/0x00188a10.cpp
// sym: ?vfunc_2@PropAddToMissileCountAction_188a10@fn_f5c5d2a1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PropAddToMissileCountAction_188a10* PropAddToMissileCountAction_188a10::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041965c;
    RefCounted_188a10* q = *(RefCounted_188a10* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        ::operator delete(this);
    }
    return this;
}

} // namespace fn_f5c5d2a1
