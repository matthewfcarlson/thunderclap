// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001899a0..0x0018b4e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/engine/unknown.h"   // (gx3, D18) for the merged registrations
#include "decls/data/engine/fight.h"   // (gx3, D18) for the merged registrations
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "decls/data/game/global.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6684e61 {
#define TREE_TU_END }
namespace fn_f6684e61 {} using namespace fn_f6684e61;
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f4259b06 { struct Data_17fe20; } 
namespace fn_f4259b06 { struct Field; } 
namespace fn_f4259b06 { struct S_17fd80; } 
namespace fn_f4259b06 { struct S_180520; } 
namespace fn_f4259b06 { struct Src_17fef0; } 
namespace fn_f4259b06 { struct Src_17ff30; } 
namespace fn_f4259b06 { struct Sub_17f800; } 
namespace fn_f4259b06 { struct T_17fd40; } 
namespace fn_f4259b06 { struct T_180560; } 
namespace fn_f4259b06 { struct Vec3_17f980; } 
namespace fn_f4259b06 { struct Vec3_17fdd0; } 
namespace fn_f4259b06 { struct Vec3_1800f0; } 
namespace fn_f4259b06 { struct Vec3_180480; } 
namespace fn_f4259b06 { struct Vec; } 
namespace fn_fa661594 { struct Vec3_17ff70; } 
namespace fn_f4259b06 { struct C_17f430 { bool SetAttachmentIndex_0017f430(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct C_17f4e0 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct C_17f570 { char SetCompare_0017f570(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct C_17fd80 { char Set(struct fn_f4259b06::S_17fd80 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct O_180520 { bool Set(struct fn_f4259b06::S_180520 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct O_180560 { bool Set(struct fn_f4259b06::T_180560 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj { char Set(struct fn_f4259b06::Field *); char Set(struct fn_f4259b06::Vec const *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f450 { bool SetCompare_0017f450(void *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f460 { char * GetState_0017f460(); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f490 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f4b0 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f4c0 { int * Get(); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f550 { bool SetAttachmentIndex_0017f550(void *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f720 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f740 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f750 { char ** Get(); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f800 { struct fn_f4259b06::Sub_17f800 * GetField(); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17f980 { bool Set(struct fn_f4259b06::Vec3_17f980 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17fd40 { bool FUN_0017fd40(struct fn_f4259b06::T_17fd40 const *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17fe20 { bool Set(struct fn_f4259b06::Data_17fe20 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17fef0 { bool Set(struct fn_f4259b06::Src_17fef0 const *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_17ff30 { bool Copy(struct fn_f4259b06::Src_17ff30 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_1800f0 { bool Set(struct fn_f4259b06::Vec3_1800f0 const *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Obj_180480 { bool Set(struct fn_f4259b06::Vec3_180480 const *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct T_17f580 { char * GetState_0017f580(); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct Thing_17fc00 { void * Get(); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_f4259b06 { struct X_17fdd0 { bool Set(struct fn_f4259b06::Vec3_17fdd0 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.cpp
namespace fn_fa661594 { struct Obj_17ff70 { bool Set(struct fn_fa661594::Vec3_17ff70 *); }; }   // (gx3, D18) setters, as defined in unk_17f2b0.O1.cpp

// ---- declarations shared by the functions below
namespace fn_f6684e61 {
class TrackFactoryCasterTemplate_189f30 {
  public:
    virtual bool Cast_00186ca0(void*);
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_189f30*);
class TrackFactoryCasterTemplate_18a0d0 {
  public:
    virtual bool cast_00186ec0(void*);
};
class Track {
  public:
    void apply_002367c0(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_18a0d0*);
} // namespace fn_f6684e61
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f6684e61 {
void* FUN_0008d690(unsigned int size);
class PropAnimationTrack {
public:
    bool FUN_0017f7c0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f7d0(int); /* (unb4) as defined; address taken only */
    char FUN_0017f7f0(int); /* (unb4) as defined; address taken only */
    void FUN_0017f800();
    bool FUN_0017f820(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f840(int); /* (unb4) as defined; address taken only */
    char FUN_0017f860(int); /* (unb4) as defined; address taken only */
    char FUN_0017f880(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class TrackFactoryCasterTemplate_18a310 {
  public:
    virtual bool Cast_00186fe0(void*);
};
class Owner {
  public:
    void Set_002367c0(void*);
    void Add_002367c0(Track*);
};
void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18a310*);
} // namespace fn_f6684e61
namespace hulkfight { namespace motion {
class PropThrowTrack_18a340 {
public:
    char FUN_0017f900(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f910(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f930(int); /* (unb4) as defined; address taken only */
    char FUN_0017f950(char); /* (unb4) as defined; address taken only */
    bool FUN_0017f980(void*); /* (unb4) as defined; address taken only */
    bool FUN_0017f9b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f9d0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017f9f0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fa10(int); /* (unb4) as defined; address taken only */
    char FUN_0017fa30(float); /* (unb4) as defined; address taken only */
    char FUN_0017fa60(float); /* (unb4) as defined; address taken only */
    bool FUN_0017fa90(float); /* (unb4) as defined; address taken only */
    char FUN_0017fac0(float); /* (unb4) as defined; address taken only */
    bool FUN_0017faf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fb10(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fb30(float); /* (unb4) as defined; address taken only */
    bool FUN_0017fb60(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fb80(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fba0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fbc0(int); /* (unb4) as defined; address taken only */
    char FUN_0017fbe0(int); /* (unb4) as defined; address taken only */
    void FUN_0017fbf0();
    void FUN_0017fc00();
    char FUN_0017fc20(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f6684e61 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
} // namespace fn_f6684e61
namespace fight {
template <class T>
class ParamBool_18a340 : public ParamBoolBase {
public:
    ParamBool_18a340(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamBranch_18a340 : public ParamBranchBase {
public:
    ParamBranch_18a340(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_18a340 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18a340(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18a340 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18a340(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_18a340 : public ParamNameBase {
public:
    ParamName_18a340(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_18a340 : public ParamVectorBase {
public:
    ParamVector_18a340(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class BallAndChainReturnTrack_18a870 {
public:
    bool FUN_0017fc30(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fc40(int); /* (unb4) as defined; address taken only */
    char FUN_0017fc60(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fc80(void*); /* (unb4) as defined; address taken only */
    char FUN_0017fca0(int); /* (unb4) as defined; address taken only */
    char FUN_0017fcc0(float); /* (unb4) as defined; address taken only */
    bool FUN_0017fcf0(int); /* (unb4) as defined; address taken only */
    char FUN_0017fd10(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fd40(void*); /* (unb4) as defined; address taken only */
    char FUN_0017fd80(void*); /* (unb4) as defined; address taken only */
    void FUN_0017fda0();
    bool FUN_0017fdd0(void*); /* (unb4) as defined; address taken only */
    void FUN_0017fdf0();
    bool FUN_0017fe20(void*); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_18a870 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18a870(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18a870 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18a870(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_18a870 : public ParamNameBase {
public:
    ParamName_18a870(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f6684e61 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f6684e61
namespace fight {
template <class T>
class ParamNameConstList_18a870 : public ParamNameConstListBase {
public:
    ParamNameConstList_18a870(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_18a870 : public ParamVectorBase {
public:
    ParamVector_18a870(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f6684e61 {
class TrackFactoryCasterTemplate_18ab70 {
  public:
    virtual bool Cast_00187160(void*);
};
class Host {
  public:
    void Set_002367c0(void*);
};
extern "C" void* __cdecl Lookup(void*, TrackFactoryCasterTemplate_18ab70*);
} // namespace fn_f6684e61
namespace hulkfight { namespace motion {
class BallAndChainShootTrack_18abd0 {
public:
    bool FUN_0017fe90(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fea0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fec0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017fef0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0017ff30(void*); /* (unb4) as defined; address taken only */
    bool FUN_0017ff70(void*); /* (unb4) as defined; address taken only */
    bool FUN_0017ffa0(int); /* (unb4) as defined; address taken only */
    bool FUN_0017ffc0(int); /* (unb4) as defined; address taken only */
    char FUN_0017ffe0(int); /* (unb4) as defined; address taken only */
    bool FUN_00180000(int); /* (unb4) as defined; address taken only */
    char FUN_00180020(float); /* (unb4) as defined; address taken only */
    bool FUN_00180050(float); /* (unb4) as defined; address taken only */
    char FUN_00180080(float); /* (unb4) as defined; address taken only */
    bool FUN_001800b0(int); /* (unb4) as defined; address taken only */
    void FUN_001800c0();
    bool FUN_001800f0(void*); /* (unb4) as defined; address taken only */
    void FUN_00180110();
    char FUN_00180150(void*); /* (unb4) as defined; address taken only */
    bool FUN_00180190(int); /* (unb4) as defined; address taken only */
    bool FUN_001801b0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_18abd0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_18abd0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_18abd0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18abd0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18abd0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18abd0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_18abd0 : public ParamNameBase {
public:
    ParamName_18abd0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamNameConstList_18abd0 : public ParamNameConstListBase {
public:
    ParamNameConstList_18abd0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_18abd0 : public ParamVectorBase {
public:
    ParamVector_18abd0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f6684e61 {
class TrackFactoryCasterTemplate_18b050 {
  public:
    virtual bool Cast_00187340(void*);
};
void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b050*);
class TrackFactoryCasterTemplate_18b080 {
  public:
    virtual bool cast_001873a0(void*);
};
extern void* findTrack_00236ac0(int, TrackFactoryCasterTemplate_18b080*);
class Holder {
  public:
    void put_002367c0(void*);
};
class TrackFactoryCasterTemplate_18b0e0 {
  public:
    virtual bool Cast_001874c0(void*);
    TrackFactoryCasterTemplate_18b0e0() {}
};
Track* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18b0e0*);
class TrackFactoryCasterTemplate_18b110 {
  public:
    virtual bool Cast_00187540(void*);
};
class Target {
  public:
    void* Do_002367c0(void*);
    void* Set_002367c0(void*);
};
extern "C" void* FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b110*);
class PropSpawnTrack {
public:
    bool FUN_00180430(int); /* (unb4) as defined; address taken only */
    char FUN_00181670(void*); /* (unb4) as defined; address taken only */
    void FUN_00180450();
    bool FUN_00180480(void*); /* (unb4) as defined; address taken only */
    char FUN_001804c0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00180520(void*); /* (unb4) as defined; address taken only */
    bool FUN_00180560(void*); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class TrackFactoryCasterTemplate_18b2e0 {
  public:
    virtual bool Cast_001875e0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b2e0*);

} // namespace fn_f6684e61

// 0x001867b0 fight::ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0 (30 B): matches/0x001867b0.cpp
// sym: ??_G?$ParamIntConstRange@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from GrapplePropStateByNameCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001867d0 fight::ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0 (30 B): matches/0x001867d0.cpp
// sym: ??_G?$ParamEnumConstList@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from GrapplePropStateByNameCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186890 fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x00186890.cpp
// sym: ??_G?$ParamIntConstRange@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMassCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001868b0 fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x001868b0.cpp
// sym: ??_G?$ParamEnumConstList@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMassCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001868d0 fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x001868d0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropMassCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186a10 fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x00186a10.cpp
// sym: ??_G?$ParamIntConstRange@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropStateByNameCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186a30 fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x00186a30.cpp
// sym: ??_G?$ParamEnumConstList@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropStateByNameCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186d70 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x00186d70.cpp
// sym: ??_G?$ParamFloatConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropSetStateByNameTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186d90 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x00186d90.cpp
// sym: ??_G?$ParamIntConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropSetStateByNameTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186ef0 fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x00186ef0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropAnimationTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186f10 fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x00186f10.cpp
// sym: ??_G?$ParamIntConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropAnimationTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00186f30 fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x00186f30.cpp
// sym: ??_G?$ParamEnumConstList@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropAnimationTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187010 fight::ParamFloatConstRange<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187010.cpp
// sym: ??_G?$ParamFloatConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropThrowTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187030 fight::ParamIntConstRange<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187030.cpp
// sym: ??_G?$ParamIntConstRange@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropThrowTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187050 fight::ParamBool<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187050.cpp
// sym: ??_G?$ParamBool@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropThrowTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187070 fight::ParamVector<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187070.cpp
// sym: ??_G?$ParamVector@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropThrowTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187090 fight::ParamBranch<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00187090.cpp
// sym: ??_G?$ParamBranch@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropThrowTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001870f0 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x001870f0.cpp
// sym: ??_G?$ParamFloatConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainReturnTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187110 fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00187110.cpp
// sym: ??_G?$ParamIntConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainReturnTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187130 fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00187130.cpp
// sym: ??_G?$ParamVector@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainReturnTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187210 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187210.cpp
// sym: ??_G?$ParamFloatConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187230 fight::ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187230.cpp
// sym: ??_G?$ParamIntConstRange@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187250 fight::ParamVector<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187250.cpp
// sym: ??_G?$ParamVector@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187270 fight::ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00187270.cpp
// sym: ??_G?$ParamEnumConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187570 fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x00187570.cpp
// sym: ??_G?$ParamFloatConstRange@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropAddToCollisionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00187590 fight::ParamString<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x00187590.cpp
// sym: ??_G?$ParamString@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropAddToCollisionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001875b0 fight::ParamVector<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x001875b0.cpp
// sym: ??_G?$ParamVector@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropAddToCollisionTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189860 fight::ParamName<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0 (30 B): matches/0x00189860.cpp
// sym: ??_G?$ParamName@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189880 fight::ParamNameConstList<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x00189880.cpp
// sym: ??_G?$ParamNameConstList@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001898a0 fight::ParamName<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x001898a0.cpp
// sym: ??_G?$ParamName@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001898c0 fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x001898c0.cpp
// sym: ??_G?$ParamName@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001898e0 fight::ParamName<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x001898e0.cpp
// sym: ??_G?$ParamName@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189900 fight::ParamName<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00189900.cpp
// sym: ??_G?$ParamName@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189920 fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00189920.cpp
// sym: ??_G?$ParamName@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189940 fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00189940.cpp
// sym: ??_G?$ParamNameConstList@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189960 fight::ParamName<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00189960.cpp
// sym: ??_G?$ParamName@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x00189980 fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00189980.cpp
// sym: ??_G?$ParamNameConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from BallAndChainShootTrack_4.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00189a50 / FUN_00189ba0 / FUN_00189d50 / FUN_00189f90 / FUN_0018a100 / FUN_0018a340 / FUN_0018a870 / FUN_0018abd0 / FUN_0018b140)



// 0x001899a0 fight::ParamNameConstList<hulkfight::motion::PropSpawnTrack>::vfunc_0 (30 B): matches/0x001899a0.cpp
// sym: ??_G?$ParamNameConstList@VPropSpawnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_f6684e61 {

} // namespace fn_f6684e61

// 0x00189a50 FUN_00189a50 (231 B): matches/0x00189a50.cpp
// sym: _FUN_00189a50
// (gx2, D18) from PropSpawnTrack_reg.new_plain.cpp; constructs the real ParamEnumConstList<hulkfight::motion::GrapplePropStateByNameCondition>, ParamIntConstRange<hulkfight::motion::GrapplePropStateByNameCondition>, ParamName<hulkfight::motion::GrapplePropStateByNameCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00189a50()
{
    if (DAT_004e1414 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::GrapplePropStateByNameCondition>("attachmentIndex", &fn_f4259b06::C_17f430::SetAttachmentIndex_0017f430);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::GrapplePropStateByNameCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f4259b06::Obj_17f450::SetCompare_0017f450);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::GrapplePropStateByNameCondition>("state", &fn_f4259b06::Obj_17f460::GetState_0017f460);
        FUN_002347b0(&DAT_004e1410, params, 3);
    }
    DAT_004e1414++;
}



// 0x00189ba0 FUN_00189ba0 (274 B): matches/0x00189ba0.cpp
// sym: ?FUN_00189ba0@@YAXXZ
// (gx2, D18) from PropSpawnTrack_reg.iso_00189ba0.cpp; constructs the real ParamEnumConstList<hulkfight::motion::PropMassCondition>, ParamFloatConstRange<hulkfight::motion::PropMassCondition>, ParamIntConstRange<hulkfight::motion::PropMassCondition>, ParamNameConstList<hulkfight::motion::PropMassCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00189ba0()
{
    if (DAT_004e1424 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropMassCondition>("attachmentIndex", &fn_f4259b06::Obj_17f490::Set);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::PropMassCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f4259b06::Obj_17f4b0::Set);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::PropMassCondition>("massClass", &fn_f4259b06::Obj_17f4c0::Get);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropMassCondition>("massMultiplier", &fn_f4259b06::C_17f4e0::Set);
        FUN_002347b0(&DAT_004e1420, params, 4);
    }
    DAT_004e1424++;
}



// 0x00189d50 FUN_00189d50 (231 B): matches/0x00189d50.cpp
// sym: _FUN_00189d50
// (gx2, D18) from PropSpawnTrack_reg.iso_00189d50.cpp; constructs the real ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>, ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>, ParamName<hulkfight::motion::PropStateByNameCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00189d50()
{
    if ((*(int*)&DAT_004e143c) == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropStateByNameCondition>("attachmentIndex", &fn_f4259b06::Obj_17f550::SetAttachmentIndex_0017f550);
        params[1] = new ::fight::ParamEnumConstList< ::hulkfight::motion::PropStateByNameCondition>("compare", (void*)&DAT_00427758, DAT_00427760, &fn_f4259b06::C_17f570::SetCompare_0017f570);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::PropStateByNameCondition>("state", &fn_f4259b06::T_17f580::GetState_0017f580);
        FUN_002347b0(&DAT_004e1438, params, 3);
    }
    (*(int*)&DAT_004e143c)++;
}

namespace fn_f6684e61 {


// 0x00189f30 FUN_00189f30 (38 B): matches/0x00189f30.cpp
// sym: _FUN_00189f30
extern "C" void FUN_00189f30(Obj* o, void* p) {
    TrackFactoryCasterTemplate_189f30 c;
    o->Apply_002367c0(Find(p, &c));
}

} // namespace fn_f6684e61

// 0x00189f60 FUN_00189f60 (38 B): matches/0x00189f60.cpp [wrapped: conflict: Find]
// sym: _FUN_00189f60
namespace fn_00189f60 {
class TrackFactoryCasterTemplate_189f60 {
  public:
    virtual bool cast_00186d40(void*);
};
class Obj {
  public:
    int Do_002367c0(void*);
};
extern void* Find_00236ac0(int, TrackFactoryCasterTemplate_189f60*);
extern "C" int FUN_00189f60(Obj* obj, int name) {
    TrackFactoryCasterTemplate_189f60 c;
    return obj->Do_002367c0(Find_00236ac0(name, &c));
}
} // namespace fn_00189f60


// 0x00189f90 FUN_00189f90 (213 B): matches/0x00189f90.cpp
// sym: ?FUN_00189f90@@YAXXZ
// (gx2, D18) from PropSpawnTrack_reg.iso_00189f90.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>, ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>, ParamName<hulkfight::motion::PropSetStateByNameTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00189f90()
{
    if (DAT_004e1474 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropSetStateByNameTrack>("timeBegin", &fn_f4259b06::Obj_17f720::Set);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropSetStateByNameTrack>("attachmentIndex", &fn_f4259b06::Obj_17f740::Set);
        params[2] = new ::fight::ParamName< ::hulkfight::motion::PropSetStateByNameTrack>("state", &fn_f4259b06::Obj_17f750::Get);
        FUN_002347b0(&DAT_004e1470, params, 3);
    }
    DAT_004e1474++;
}



// 0x0018a070 FUN_0018a070 (38 B): matches/0x0018a070.cpp [wrapped: conflict: Find]
// sym: _FUN_0018a070
namespace fn_0018a070 {
class TrackFactoryCasterTemplate_18a070 {
  public:
    virtual bool Cast_00186dc0(void*);
};
class Owner {
  public:
    void Attach_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_18a070*);
extern "C" void FUN_0018a070(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a070 c;
    owner->Attach_002367c0(Find_00236ac0(name, &c));
}
} // namespace fn_0018a070


// 0x0018a0a0 FUN_0018a0a0 (38 B): matches/0x0018a0a0.cpp [wrapped: conflict: Owner]
// sym: _FUN_0018a0a0
namespace fn_0018a0a0 {
class TrackFactoryCasterTemplate_18a0a0 {
  public:
    virtual bool Cast_00186e40(void*);
};
class Owner {
  public:
    void* Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18a0a0*);
extern "C" void* __cdecl FUN_0018a0a0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a0a0 c;
    return owner->Add_002367c0(FUN_00236ac0(name, &c));
}
} // namespace fn_0018a0a0

namespace fn_f6684e61 {

// 0x0018a0d0 FUN_0018a0d0 (38 B): matches/0x0018a0d0.cpp
// sym: _FUN_0018a0d0
extern "C" void FUN_0018a0d0(Track* track, void* name) {
    TrackFactoryCasterTemplate_18a0d0 caster;
    track->apply_002367c0(find(name, &caster));
}


} // namespace fn_f6684e61

// 0x0018a100 FUN_0018a100 (476 B): matches/0x0018a100.cpp
// sym: _FUN_0018a100
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::PropAnimationTrack>, ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>, ParamIntConstRange<hulkfight::motion::PropAnimationTrack>, ParamName<hulkfight::motion::PropAnimationTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0018a100()
{
    if (DAT_004e148c == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAnimationTrack>("timeBegin", &owners::X_17f7c0::FUN_0017f7c0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAnimationTrack>("timeEnd", &owners::C_17f7d0::FUN_0017f7d0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropAnimationTrack>("attachmentIndex", &owners::Obj_17f7f0::FUN_0017f7f0);
        params[3] = new ::fight::ParamName< ::hulkfight::motion::PropAnimationTrack>("animation", &fn_f4259b06::Obj_17f800::GetField);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAnimationTrack>("speed", &owners::Obj_17f820::FUN_0017f820);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAnimationTrack>("startFrame", &owners::Obj_17f840::FUN_0017f840);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropAnimationTrack>("endFrame", &owners::Obj_17f860::FUN_0017f860);
        params[7] = new ::fight::ParamEnumConstList< ::hulkfight::motion::PropAnimationTrack>("cyclic", (void*)&DAT_004abf70, DAT_004123d4, &owners::Obj_17f880::FUN_0017f880);
        FUN_002347b0(&DAT_004e1488, params, 8);
    }
    DAT_004e148c++;
}



// 0x0018a2e0 FUN_0018a2e0 (38 B): matches/0x0018a2e0.cpp [wrapped: conflict: Find]
// sym: _FUN_0018a2e0
namespace fn_0018a2e0 {
class TrackFactoryCasterTemplate_18a2e0 {
  public:
    virtual bool Cast_00186f60(void*);
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern void* Find_00236ac0(void*, TrackFactoryCasterTemplate_18a2e0*);
extern "C" void FUN_0018a2e0(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_18a2e0 c;
    obj->Apply_002367c0(Find_00236ac0(p, &c));
}
} // namespace fn_0018a2e0

namespace fn_f6684e61 {

// 0x0018a310 FUN_0018a310 (38 B): matches/0x0018a310.cpp
// sym: _FUN_0018a310
extern "C" void FUN_0018a310(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a310 c;
    void* p = FUN_00236ac0(name, &c);
    owner->Set_002367c0(p);
}


} // namespace fn_f6684e61

// 0x0018a340 FUN_0018a340 (1276 B): matches/0x0018a340.cpp
// sym: _FUN_0018a340
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::motion::PropThrowTrack>, ParamBranch<hulkfight::motion::PropThrowTrack>, ParamFloatConstRange<hulkfight::motion::PropThrowTrack>, ParamIntConstRange<hulkfight::motion::PropThrowTrack>, ParamName<hulkfight::motion::PropThrowTrack>, ParamVector<hulkfight::motion::PropThrowTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0018a340()
{
    if (DAT_004e149c == 0) {
        ::fight::ParamValue* params[24];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("timeBegin", &owners::X_17f900::FUN_0017f900);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("timeEnd", &owners::Obj_17f910::FUN_0017f910);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropThrowTrack>("attachmentIndex", &owners::Obj_17f930::FUN_0017f930);
        params[3] = new ::fight::ParamBool< ::hulkfight::motion::PropThrowTrack>("useCameraDirection", &owners::Obj_17f950::FUN_0017f950);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::PropThrowTrack>("direction", &fn_f4259b06::Obj_17f980::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("distanceMin", &owners::Obj_17f9b0::FUN_0017f9b0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("distanceMax", &owners::C_17f9d0::FUN_0017f9d0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("velocityMin", &owners::Obj_17f9f0::FUN_0017f9f0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("velocityMax", &owners::X_17fa10::FUN_0017fa10);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("spinMin", &owners::Obj_17fa30::FUN_0017fa30);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("spinMax", &owners::X_17fa60::FUN_0017fa60);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("trackingMin", &owners::Obj_17fa90::FUN_0017fa90);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("trackingMax", &owners::Thing_17fac0::FUN_0017fac0);
        params[13] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropThrowTrack>("bounceMin", &owners::Obj_17faf0::FUN_0017faf0);
        params[14] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropThrowTrack>("bounceMax", &owners::Target_17fb10::FUN_0017fb10);
        params[15] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("yFixupAngle", &owners::Thing_17fb30::FUN_0017fb30);
        params[16] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("forceMin", &owners::Obj_17fb60::FUN_0017fb60);
        params[17] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("forceMax", &owners::C_17fb80::FUN_0017fb80);
        params[18] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("damageMin", &owners::Obj_17fba0::FUN_0017fba0);
        params[19] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropThrowTrack>("damageMax", &owners::Obj_17fbc0::FUN_0017fbc0);
        params[20] = new ::fight::ParamIntConstRange< ::hulkfight::motion::PropThrowTrack>("interruptPriority", &owners::Target_17fbe0::FUN_0017fbe0);
        params[21] = new ::fight::ParamBranch< ::hulkfight::motion::PropThrowTrack>("hitBranch", &owners::Base_17fbf0::FUN_0017fbf0);
        params[22] = new ::fight::ParamName< ::hulkfight::motion::PropThrowTrack>("hitEffect", &fn_f4259b06::Thing_17fc00::Get);
        params[23] = new ::fight::ParamBool< ::hulkfight::motion::PropThrowTrack>("clearCharge", &owners::Obj_17fc20::FUN_0017fc20);
        FUN_002347b0(&DAT_004e1498, params, 24);
    }
    DAT_004e149c++;
}



// 0x0018a840 FUN_0018a840 (38 B): matches/0x0018a840.cpp [wrapped: conflict: Find]
// sym: _FUN_0018a840
namespace fn_0018a840 {
class TrackFactoryCasterTemplate_18a840 {
  public:
    virtual bool Cast_001870c0(void*);
};
class Obj {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_18a840*);
extern "C" void __cdecl FUN_0018a840(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_18a840 caster;
    void* p = Find_00236ac0(name, &caster);
    obj->Set_002367c0(p);
}
} // namespace fn_0018a840

namespace fn_f6684e61 {

} // namespace fn_f6684e61

// 0x0018a870 FUN_0018a870 (766 B): matches/0x0018a870.cpp
// sym: _FUN_0018a870
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>, ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>, ParamName<hulkfight::motion::BallAndChainReturnTrack>, ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>, ParamVector<hulkfight::motion::BallAndChainReturnTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0018a870()
{
    if (DAT_004e14a4 == 0) {
        ::fight::ParamValue* params[14];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("timeBegin", &owners::Obj_17fc30::FUN_0017fc30);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("timeEnd", &owners::T_17fc40::FUN_0017fc40);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("attachmentIndex", &owners::Obj_17fc60::FUN_0017fc60);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("initVelocity", &owners::Obj_17fc80::FUN_0017fc80);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("acceleration", &owners::Obj_17fca0::FUN_0017fca0);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("tracking", &owners::Obj_17fcc0::FUN_0017fcc0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("targetYOffset", &owners::Obj_17fcf0::FUN_0017fcf0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainReturnTrack>("minDistance", &owners::Obj_17fd10::FUN_0017fd10);
        params[8] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainReturnTrack>("offset", &fn_f4259b06::Obj_17fd40::FUN_0017fd40);
        params[9] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainReturnTrack>("propAxis", &fn_f4259b06::C_17fd80::Set);
        params[10] = new ::fight::ParamName< ::hulkfight::motion::BallAndChainReturnTrack>("beamEffect", &owners::Obj_17fda0::FUN_0017fda0);
        params[11] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainReturnTrack>("beamOffset", &fn_f4259b06::X_17fdd0::Set);
        params[12] = new ::fight::ParamNameConstList< ::hulkfight::motion::BallAndChainReturnTrack>("beamAttachJoint", &owners::T_17fdf0::FUN_0017fdf0);
        params[13] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainReturnTrack>("beamAttachJointOffset", &fn_f4259b06::Obj_17fe20::Set);
        FUN_002347b0(&DAT_004e14a0, params, 14);
    }
    DAT_004e14a4++;
}

namespace fn_f6684e61 {


// 0x0018ab70 FUN_0018ab70 (38 B): matches/0x0018ab70.cpp
// sym: _FUN_0018ab70
extern "C" void __cdecl FUN_0018ab70(Host* host, void* key) {
    TrackFactoryCasterTemplate_18ab70 caster;
    void* result = Lookup(key, &caster);
    host->Set_002367c0(result);
}

} // namespace fn_f6684e61

// 0x0018aba0 FUN_0018aba0 (38 B): matches/0x0018aba0.cpp [wrapped: conflict: Find]
// sym: _FUN_0018aba0
namespace fn_0018aba0 {
class TrackFactoryCasterTemplate_18aba0 {
  public:
    virtual bool cast_001871e0(void*);
};
class Owner {
  public:
    void Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_00236ac0(void*, TrackFactoryCasterTemplate_18aba0*);
extern "C" void __cdecl FUN_0018aba0(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_18aba0 caster;
    owner->Add_002367c0(Find_00236ac0(key, &caster));
}
} // namespace fn_0018aba0

namespace fn_f6684e61 {

} // namespace fn_f6684e61

// 0x0018abd0 FUN_0018abd0 (1090 B): matches/0x0018abd0.cpp
// sym: _FUN_0018abd0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::motion::BallAndChainShootTrack>, ParamFloatConstRange<hulkfight::motion::BallAndChainShootTrack>, ParamIntConstRange<hulkfight::motion::BallAndChainShootTrack>, ParamName<hulkfight::motion::BallAndChainShootTrack>, ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>, ParamVector<hulkfight::motion::BallAndChainShootTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0018abd0()
{
    if (DAT_004e14b4 == 0) {
        ::fight::ParamValue* params[20];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("timeBegin", &owners::Obj_17fe90::FUN_0017fe90);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("timeEnd", &owners::Obj_17fea0::FUN_0017fea0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::BallAndChainShootTrack>("attachmentIndex", &owners::Obj_17fec0::FUN_0017fec0);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainShootTrack>("initPosition", &fn_f4259b06::Obj_17fef0::Set);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainShootTrack>("direction", &fn_f4259b06::Obj_17ff30::Copy);
        params[5] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainShootTrack>("propAxis", &fn_fa661594::Obj_17ff70::Set);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("distanceMin", &owners::Obj_17ffa0::FUN_0017ffa0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("distanceMax", &owners::Obj_17ffc0::FUN_0017ffc0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("velocityMin", &owners::X_17ffe0::FUN_0017ffe0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("velocityMax", &owners::T_180000::FUN_00180000);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("trackingMin", &owners::X_180020::FUN_00180020);
        params[11] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("trackingMax", &owners::Obj_180050::FUN_00180050);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("yFixupAngle", &owners::Obj_180080::FUN_00180080);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("targetYOffset", &owners::Obj_1800b0::FUN_001800b0);
        params[14] = new ::fight::ParamName< ::hulkfight::motion::BallAndChainShootTrack>("beamEffect", &owners::Obj_1800c0::FUN_001800c0);
        params[15] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainShootTrack>("beamOffset", &fn_f4259b06::Obj_1800f0::Set);
        params[16] = new ::fight::ParamNameConstList< ::hulkfight::motion::BallAndChainShootTrack>("beamAttachJoint", &owners::Obj_180110::FUN_00180110);
        params[17] = new ::fight::ParamVector< ::hulkfight::motion::BallAndChainShootTrack>("beamAttachJointOffset", static_cast<char (fn_f4259b06::Obj::*)(struct fn_f4259b06::Field *)>(&fn_f4259b06::Obj::Set));
        params[18] = new ::fight::ParamEnumConstList< ::hulkfight::motion::BallAndChainShootTrack>("damageType", (void*)&DAT_004ad788, DAT_00412ed4, &owners::Obj_180190::FUN_00180190);
        params[19] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BallAndChainShootTrack>("damageScale", &owners::C_1801b0::FUN_001801b0);
        FUN_002347b0(&DAT_004e14b0, params, 20);
    }
    DAT_004e14b4++;
}



// 0x0018b020 FUN_0018b020 (38 B): matches/0x0018b020.cpp [wrapped: conflict: Find]
// sym: _FUN_0018b020
namespace fn_0018b020 {
class TrackFactoryCasterTemplate_18b020 {
  public:
    virtual bool Cast_001872a0(void*);
};
class Receiver {
  public:
    void Fn_002367c0(void*);
};
void* Find_00236ac0(void*, TrackFactoryCasterTemplate_18b020*);
extern "C" void FUN_0018b020(Receiver* receiver, void* name) {
    TrackFactoryCasterTemplate_18b020 caster;
    receiver->Fn_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_0018b020

namespace fn_f6684e61 {

// 0x0018b050 FUN_0018b050 (38 B): matches/0x0018b050.cpp
// sym: _FUN_0018b050
extern "C" void __cdecl FUN_0018b050(Owner* owner, void* item) {
    TrackFactoryCasterTemplate_18b050 caster;
    void* p = FUN_00236ac0(item, &caster);
    owner->Set_002367c0(p);
}


// 0x0018b080 FUN_0018b080 (38 B): matches/0x0018b080.cpp
// sym: _FUN_0018b080
extern "C" void FUN_0018b080(Holder* h, int n) {
    TrackFactoryCasterTemplate_18b080 c;
    void* p = findTrack_00236ac0(n, &c);
    h->put_002367c0(p);
}

} // namespace fn_f6684e61

// 0x0018b0b0 FUN_0018b0b0 (38 B): matches/0x0018b0b0.cpp [wrapped: conflict: Lookup]
// sym: _FUN_0018b0b0
namespace fn_0018b0b0 {
class TrackFactoryCasterTemplate_18b0b0 {
  public:
    virtual bool Cast_00187440(void*);
};
class Owner {
  public:
    void Add_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* Lookup_00236ac0(void*, TrackFactoryCasterTemplate_18b0b0*);
extern "C" void FUN_0018b0b0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_18b0b0 caster;
    void* result = Lookup_00236ac0(name, &caster);
    owner->Add_002367c0(result);
}
} // namespace fn_0018b0b0

namespace fn_f6684e61 {

// 0x0018b0e0 FUN_0018b0e0 (38 B): matches/0x0018b0e0.cpp
// sym: _FUN_0018b0e0
extern "C" void FUN_0018b0e0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18b0e0 caster;
    owner->Add_002367c0(FUN_00236ac0(name, &caster));
}


// 0x0018b110 FUN_0018b110 (38 B): matches/0x0018b110.cpp
// sym: _FUN_0018b110
extern "C" void* FUN_0018b110(Target* t, void* name) {
    TrackFactoryCasterTemplate_18b110 c;
    void* p = FUN_00236ac0(name, &c);
    return t->Do_002367c0(p);
}


} // namespace fn_f6684e61

// 0x0018b140 FUN_0018b140 (409 B): matches/0x0018b140.cpp
// sym: _FUN_0018b140
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>, ParamNameConstList<hulkfight::motion::PropSpawnTrack>, ParamString<hulkfight::motion::PropSpawnTrack>, ParamVector<hulkfight::motion::PropSpawnTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0018b140()
{
    if (DAT_004e14e4 == 0) {
        ::fight::ParamValue* params[7];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::PropSpawnTrack>("timeBegin", &owners::C_180430::FUN_00180430);
        params[1] = new ::fight::ParamString< ::hulkfight::motion::PropSpawnTrack>("propName", &owners::X_181670::FUN_00181670);
        params[2] = new ::fight::ParamNameConstList< ::hulkfight::motion::PropSpawnTrack>("joint", &owners::A_180450::FUN_00180450);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::PropSpawnTrack>("offset", &fn_f4259b06::Obj_180480::Set);
        params[4] = new ::fight::ParamVector< ::hulkfight::motion::PropSpawnTrack>("orient", static_cast<char (fn_f4259b06::Obj::*)(struct fn_f4259b06::Vec const *)>(&fn_f4259b06::Obj::Set));
        params[5] = new ::fight::ParamVector< ::hulkfight::motion::PropSpawnTrack>("impulse", &fn_f4259b06::O_180520::Set);
        params[6] = new ::fight::ParamVector< ::hulkfight::motion::PropSpawnTrack>("impulseOffset", &fn_f4259b06::O_180560::Set);
        FUN_002347b0(&DAT_004e14e0, params, 7);
    }
    DAT_004e14e4++;
}

namespace fn_f6684e61 {


// 0x0018b2e0 FUN_0018b2e0 (38 B): matches/0x0018b2e0.cpp
// sym: _FUN_0018b2e0
extern "C" void* __cdecl FUN_0018b2e0(Target* target, void* arg) {
    TrackFactoryCasterTemplate_18b2e0 caster;
    void* p = FUN_00236ac0(arg, &caster);
    return target->Set_002367c0(p);
}

} // namespace fn_f6684e61

// 0x0018b310 FUN_0018b310 (451 B): matches/0x0018b310.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: _FUN_0018b310
namespace fn_0018b310 {
namespace hulkfight {
namespace motion {
class PropMissionCriticalCondition;
class SmartPropGrabbableCondition;
class GrapplePropStateByNameCondition;
class PropGrabbableIsThrownCondition;
class PropMassCondition;
class PropAtRestCondition;
class PropIsAttachedCondition;
class PropStateByNameCondition;
class PropStateByIndexCondition;
class PropMissileCountCondition;
class PropCollidedWithWorldCondition;
class SmartPropIsCargoCondition;
class CSMPropIsCharacterCondition;
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> struct ConditionFactoryCasterTemplate {
    virtual void create();
    virtual void cast();
    virtual void other();
};
} // namespace fight
extern "C" void* __cdecl FUN_002343e0(const char*, void*);
struct Registry_18b310 {
    void* FUN_00236760(void*);
};
extern "C" void* __cdecl FUN_0018b310(Registry_18b310* registry) {
    using namespace hulkfight::motion;
    {
        fight::ConditionFactoryCasterTemplate<PropAtRestCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propAtRest", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropStateByIndexCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propStateByIndex", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropStateByNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propStateByName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<GrapplePropStateByNameCondition> caster;
        registry->FUN_00236760(FUN_002343e0("grapplePropStateByName", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropIsAttachedCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propIsAttached", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<CSMPropIsCharacterCondition> caster;
        registry->FUN_00236760(FUN_002343e0("csmPropIsCharacter", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<SmartPropIsCargoCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropIsCargo", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<SmartPropGrabbableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("smartPropGrabbable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropCollidedWithWorldCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propCollidedWithWorld", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMissileCountCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propMissileCount", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropGrabbableIsThrownCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propGrabbableIsThrown", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMissionCriticalCondition> caster;
        registry->FUN_00236760(FUN_002343e0("propMissionCritical", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<PropMassCondition> caster;
        return registry->FUN_00236760(FUN_002343e0("propMass", &caster));
    }
}
} // namespace fn_0018b310

