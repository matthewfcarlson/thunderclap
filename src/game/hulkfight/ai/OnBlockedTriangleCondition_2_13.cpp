// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x00111720..0x001133f0 (kind game, layer game, confidence high, dominant class hulkfight::ai::SemaphoreWaitTrack); was game/hulkfight/ai/SemaphoreWaitTrack_3.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#include "decls/data/engine/fight.h"   // (gx3, D32) its owner object's data, merged
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fee140f0 {
#define TREE_TU_END }
namespace fn_fee140f0 {} using namespace fn_fee140f0;
#include "game/hulkfight/ai.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
extern "C" void* __fastcall GetText_0010c630(void*);   // (gx4, D18) a setter (the tree pins it as a fastcall getter)
namespace fn_f15aa14c { struct Inner_10c120; } 
namespace fn_f15aa14c { struct A_10c4d0 { char SetTimeBegin_0010c4d0(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct A_10c510 { bool SetValue_0010c510(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct C_10c2b0 { char SetValue_0010c2b0(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct C_10c2e0 { bool SetDistance_0010c2e0(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct C_10c520 { char SetTimeBegin_0010c520(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct O_10c280 { bool SetCompare_0010c280(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct O_10c620 { char SetOnlySetAtEnd_0010c620(char); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj { char SetText_0010cc40(char const *); char SetText_0010ce60(char const *); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c0d0 { char SetCompare_0010c0d0(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c0f0 { char SetTarget_0010c0f0(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c120 { struct fn_f15aa14c::Inner_10c120 & Get(); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c140 { bool SetCompare_0010c140(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c170 { unsigned char SetValue_0010c170(unsigned int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c2c0 { bool SetCompare_0010c2c0(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c4f0 { void * GetText_0010c4f0(); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c530 { bool SetTimeEnd_0010c530(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c540 { int * GetKeyword_0010c540(); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c550 { char SetRandomIntroWait_0010c550(char); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c600 { bool SetTimeBegin_0010c600(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c650 { bool SetTimeEnd_0010c650(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Obj_10c670 { unsigned char SetFloatDelayOnEnd_0010c670(unsigned char); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct Owner { hulk_intptr SetText_0010c8d0(char const *); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp (gx4: its hulk_intptr return, for the native name)
namespace fn_f15aa14c { struct T_10c300 { char SetNumberofAttachedProps_0010c300(char); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct T_10c4e0 { bool SetTimeEnd_0010c4e0(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct T_10c570 { char Set(unsigned int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct T_10c640 { char SetTimeBegin_0010c640(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct X_10c110 { bool SetSmartPropIndex_0010c110(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct X_10c200 { bool SetCompare_0010c200(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct X_10c230 { char SetValue_0010c230(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct X_10c320 { char SetNumber_0010c320(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct X_10c3d0 { void * Get(); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
namespace fn_f15aa14c { struct X_10c610 { char SetTimeEnd_0010c610(int); }; }   // (gx3, D18) setters, as defined in unk_10c0d0.cpp
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fee140f0 {
extern char DAT_004a4558;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_111720 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TokenSupressTrack_111720;
} }
namespace fn_fee140f0 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_0049850c;
extern char DAT_004a46a8;
int __cdecl FUN_00344e74(const char*, int, const char*, const char*, int);
class TrackFactoryCaster_111800 {
  public:
    virtual bool vfunc_0(const char* s);
    virtual void vfunc_1();
};
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_111880 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class KeywordWaitTrack_111880 {};
} }
namespace fn_fee140f0 {
extern char DAT_004a4750;
extern char DAT_004a47f0;
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_111920 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class ButtonTrack_111920 {};
} }
namespace fn_fee140f0 {
extern char DAT_004a4890;
} // namespace fn_fee140f0
namespace fight {
class TrackFactoryCaster_1119a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class AIHistorySetTrack_1119a0 {};
} }
namespace fight {
class TrackFactoryCaster_111a40 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class TokenTrack_111a40 {};
} }
namespace fn_fee140f0 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_004a4930;
extern char DAT_004a49d0;
class TrackFactoryCaster_111ac0 {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~TrackFactoryCaster_111ac0();
};
} // namespace fn_fee140f0
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fee140f0 {
void* FUN_0008d690(unsigned int size);
} // namespace fn_fee140f0
namespace hulkfight { namespace ai {
class AIFightNodeCondition_111c40 {
public:
    void FUN_0010c120();
};
} }
namespace fn_fee140f0 {
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
} // namespace fn_fee140f0
namespace fight {
template <class T>
class ParamBranch_111c40 : public ParamBranchBase {
public:
    ParamBranch_111c40(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fee140f0 {
} // namespace fn_fee140f0
namespace hulkfight { namespace ai {
class DefendingCondition_111ca0 {
public:
    bool FUN_0010c130(char); /* (unb4) as defined; address taken only */
};
} }
namespace fn_fee140f0 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fee140f0
namespace fight {
template <class T>
class ParamBool_111ca0 : public ParamBoolBase {
public:
    ParamBool_111ca0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class LeashedCondition_112000 {
public:
    char FUN_0010c1f0(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_112000 : public ParamBoolBase {
public:
    ParamBool_112000(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace ai {
class InActiveCondition_112200 {
public:
    char FUN_0010c250(int); /* (unb4) as defined; address taken only */
    char FUN_0010c270(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_112200 : public ParamBoolBase {
public:
    ParamBool_112200(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_112200 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_112200(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace hulkfight { namespace ai {
class TokenCondition_112570 {
public:
    char FUN_0010c370(char); /* (unb4) as defined; address taken only */
    char FUN_0010c390(char); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamBool_112570 : public ParamBoolBase {
public:
    ParamBool_112570(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fee140f0 {
class SemaphoreClearTrack {
public:
    char FUN_0010c3b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0010c3c0(int); /* (unb4) as defined; address taken only */
    void FUN_0010c3d0();
    char FUN_0010c3f0(char); /* (unb4) as defined; address taken only */
    char FUN_0010c410(char); /* (unb4) as defined; address taken only */
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
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class TokenSupressTrack {
public:
    char FUN_0010c420(int); /* (unb4) as defined; address taken only */
    char FUN_0010c430(int); /* (unb4) as defined; address taken only */
    char FUN_0010c450(char); /* (unb4) as defined; address taken only */
    bool FUN_0010c470(int); /* (unb4) as defined; address taken only */
    char FUN_0010c490(char); /* (unb4) as defined; address taken only */
    bool FUN_0010c4b0(char); /* (unb4) as defined; address taken only */
};
} // namespace fn_fee140f0
namespace hulkfight { namespace ai {
class AIHistoryCountTrack_112940 {
public:
    char FUN_0010c4c0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_112940 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_112940(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fee140f0 {
class ButtonTrack {
public:
    bool FUN_0010c560(int); /* (unb4) as defined; address taken only */
    char FUN_0010c570(int); /* (unb4) as defined; address taken only */
    bool FUN_0010c590(int); /* (unb4) as defined; address taken only */
    char FUN_0010c5b0(int); /* (unb4) as defined; address taken only */
    char FUN_0010c5d0(int); /* (unb4) as defined; address taken only */
    char FUN_0010c5f0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamEnumConstList : public ParamEnumBase {
public:
    ParamEnumConstList(const char* name, char** t, int n, void (T::*s)()) : ParamEnumBase(name) { table = t; count = n; setter = s; }
    virtual void v0();
    char** table;
    int count;
    void (T::*setter)();
    int unused1c;
};
class SemaphoreWaitTrack {
public:
    bool FUN_0010c680(int); /* (unb4) as defined; address taken only */
    char FUN_0010c690(int); /* (unb4) as defined; address taken only */
    void FUN_0010c6a0();
    bool FUN_0010c6c0(char); /* (unb4) as defined; address taken only */
    char FUN_0010c6e0(char); /* (unb4) as defined; address taken only */
    char FUN_0010c700(int); /* (unb4) as defined; address taken only */
};
class Params_113080 {
  public:
    int x;
};
extern Params_113080 hulk_at_00494b44;
extern Params_113080 hulk_at_00494b60;
class Object_113080 {
  public:
    int Init_0010ec00(hulkfight::ai::ButtonTrack*, hulk_intptr);
};
Object_113080* __cdecl Alloc_0008d690(int);
struct RefCounted_1130d0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd34[];
class ButtonAction_1130d0 {
  public:
    ButtonAction_1130d0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1130d0* m_20;
};
struct RefCounted_113170 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd50[];
class HulkAction_113170 {
  public:
    HulkAction_113170* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113170* m_20;
};
struct RefCounted_113210 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd6c[];
class TokenSupressAction_113210 {
  public:
    TokenSupressAction_113210* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113210* m_20;
};
struct RefCounted_1132b0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dd88[];
class TokenAction_1132b0 {
  public:
    TokenAction_1132b0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1132b0* m_20;
};
struct RefCounted_113350 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040dda4[];
class AIHistorySetAction_113350 {
  public:
    AIHistorySetAction_113350* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_113350* m_20;
};

} // namespace fn_fee140f0

// 0x00110e90 fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (30 B): matches/0x00110e90.cpp
// sym: ??_G?$ParamEnumConstList@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from OnBlockedTriangleCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00110eb0 fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (30 B): matches/0x00110eb0.cpp
// sym: ??_G?$ParamBool@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from OnBlockedTriangleCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00110ed0 fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_0 (30 B): matches/0x00110ed0.cpp
// sym: ??_G?$ParamIntConstRange@VOnBlockedTriangleCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from OnBlockedTriangleCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00110f30 fight::ParamBranch<hulkfight::ai::AIFightNodeCondition>::vfunc_0 (30 B): matches/0x00110f30.cpp
// sym: ??_G?$ParamBranch@VAIFightNodeCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AIHistoryNameCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00110f90 fight::ParamBool<hulkfight::ai::DefendingCondition>::vfunc_0 (30 B): matches/0x00110f90.cpp
// sym: ??_G?$ParamBool@VDefendingCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AIHistoryNameCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00110ff0 fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (30 B): matches/0x00110ff0.cpp
// sym: ??_G?$ParamEnumConstList@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AIHistoryNameCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111010 fight::ParamString<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (30 B): matches/0x00111010.cpp
// sym: ??_G?$ParamString@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AIHistoryNameCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111030 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>::vfunc_0 (30 B): matches/0x00111030.cpp
// sym: ??_G?$ParamFloatConstRange@VAIHistoryNameCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from AIHistoryNameCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111090 fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_0 (30 B): matches/0x00111090.cpp
// sym: ??_G?$ParamEnumConstList@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionLargestCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001110b0 fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::vfunc_0 (30 B): matches/0x001110b0.cpp
// sym: ??_G?$ParamString@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionLargestCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111110 fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_0 (30 B): matches/0x00111110.cpp
// sym: ??_G?$ParamEnumConstList@VPropsToChuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropsToChuckCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111130 fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::vfunc_0 (30 B): matches/0x00111130.cpp
// sym: ??_G?$ParamIntConstRange@VPropsToChuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropsToChuckCondition_2.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111190 fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_0 (30 B): matches/0x00111190.cpp
// sym: ??_G?$ParamEnumConstList@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionRecentCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001111b0 fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::vfunc_0 (30 B): matches/0x001111b0.cpp
// sym: ??_G?$ParamString@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionRecentCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111210 fight::ParamBool<hulkfight::ai::LeashedCondition>::vfunc_0 (30 B): matches/0x00111210.cpp
// sym: ??_G?$ParamBool@VLeashedCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from KeyWordWaitCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111270 fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111270.cpp
// sym: ??_G?$ParamEnumConstList@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from KeyWordWaitCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111290 fight::ParamString<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111290.cpp
// sym: ??_G?$ParamString@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from KeyWordWaitCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001112b0 fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>::vfunc_0 (30 B): matches/0x001112b0.cpp
// sym: ??_G?$ParamFloatConstRange@VKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from KeyWordWaitCondition.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111310 fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_0 (30 B): matches/0x00111310.cpp
// sym: ??_G?$ParamEnumConstList@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FormationReadyCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111330 fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_0 (30 B): matches/0x00111330.cpp
// sym: ??_G?$ParamString@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from FormationReadyCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111390 fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_0 (30 B): matches/0x00111390.cpp
// sym: ??_G?$ParamEnumConstList@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from InActiveCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001113b0 fight::ParamBool<hulkfight::ai::InActiveCondition>::vfunc_0 (30 B): matches/0x001113b0.cpp
// sym: ??_G?$ParamBool@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from InActiveCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111410 fight::ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>::vfunc_0 (30 B): matches/0x00111410.cpp
// sym: ??_G?$ParamEnumConstList@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionCountCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111430 fight::ParamString<hulkfight::ai::HulkActionCountCondition>::vfunc_0 (30 B): matches/0x00111430.cpp
// sym: ??_G?$ParamString@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionCountCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111450 fight::ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>::vfunc_0 (30 B): matches/0x00111450.cpp
// sym: ??_G?$ParamFloatConstRange@VHulkActionCountCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from HulkActionCountCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001114b0 fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x001114b0.cpp
// sym: ??_G?$ParamEnumConstList@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropsToSuckCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001114d0 fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x001114d0.cpp
// sym: ??_G?$ParamFloatConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropsToSuckCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001114f0 fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x001114f0.cpp
// sym: ??_G?$ParamBool@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropsToSuckCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111510 fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_0 (30 B): matches/0x00111510.cpp
// sym: ??_G?$ParamIntConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from PropsToSuckCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111570 fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111570.cpp
// sym: ??_G?$ParamEnumConstList@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RandomKeyWordWaitCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111590 fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0 (30 B): matches/0x00111590.cpp
// sym: ??_G?$ParamIntConstRange@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from RandomKeyWordWaitCondition_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001115f0 fight::ParamBool<hulkfight::ai::TokenCondition>::vfunc_0 (30 B): matches/0x001115f0.cpp
// sym: ??_G?$ParamBool@VTokenCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SemaphoreClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111650 fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_0 (30 B): matches/0x00111650.cpp
// sym: ??_G?$ParamEnumConstList@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SemaphoreClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001116b0 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (30 B): matches/0x001116b0.cpp
// sym: ??_G?$ParamFloatConstRange@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SemaphoreClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001116d0 fight::ParamName<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (30 B): matches/0x001116d0.cpp
// sym: ??_G?$ParamName@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SemaphoreClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x001116f0 fight::ParamBool<hulkfight::ai::SemaphoreClearTrack>::vfunc_0 (30 B): matches/0x001116f0.cpp
// sym: ??_G?$ParamBool@VSemaphoreClearTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from SemaphoreClearTrack_3.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00111b50 / FUN_00111c40 / FUN_00111ca0 / FUN_00111d00 / FUN_00111df0 / FUN_00111ea0 / FUN_00111f50 / FUN_00112000 / FUN_00112060 / FUN_00112150 / FUN_00112200 / FUN_001122b0 / FUN_001123a0 / FUN_001124c0 / FUN_00112570 / FUN_00112610 / FUN_00112690 / FUN_001127d0 / FUN_00112940 / FUN_001129a0 / FUN_00112aa0 / FUN_00112ba0 / FUN_00112d30 / FUN_00112e30 / FUN_00112f10)



// 0x00111720 fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_0 (36 B): matches/0x00111720.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTokenSupressTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenSupressTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4558, 0) != 0;
}


// 0x00111750 fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::vfunc_0 (30 B): matches/0x00111750.cpp
// sym: ??_G?$ParamFloatConstRange@VTokenSupressTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111770 fight::ParamBool<hulkfight::ai::TokenSupressTrack>::vfunc_0 (30 B): matches/0x00111770.cpp
// sym: ??_G?$ParamBool@VTokenSupressTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001117a0 fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_0 (36 B): matches/0x001117a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistoryCountTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x001117d0 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::vfunc_0 (30 B): matches/0x001117d0.cpp
// sym: ??_G?$ParamFloatConstRange@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111800 fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_0 (36 B): matches/0x00111800.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHulkActionTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::HulkActionTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    int r = FUN_00344e74(s, 0, (const char*)&DAT_0049850c, (const char*)&DAT_004a46a8, 0);
    return r != 0;
}


// 0x00111830 fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::vfunc_0 (30 B): matches/0x00111830.cpp
// sym: ??_G?$ParamFloatConstRange@VHulkActionTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111850 fight::ParamName<hulkfight::ai::HulkActionTrack>::vfunc_0 (30 B): matches/0x00111850.cpp
// sym: ??_G?$ParamName@VHulkActionTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111880 fight::TrackFactoryCasterTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (36 B): matches/0x00111880.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::KeywordWaitTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4750, 0) != 0;
}


// 0x001118b0 fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (30 B): matches/0x001118b0.cpp
// sym: ??_G?$ParamFloatConstRange@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001118d0 fight::ParamName<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (30 B): matches/0x001118d0.cpp
// sym: ??_G?$ParamName@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001118f0 fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::vfunc_0 (30 B): matches/0x001118f0.cpp
// sym: ??_G?$ParamBool@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111920 fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_0 (36 B): matches/0x00111920.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VButtonTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ButtonTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_0049850c), (void*)(hulk_uintptr)(&DAT_004a47f0), 0)) != 0;
}


// 0x00111950 fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::vfunc_0 (30 B): matches/0x00111950.cpp
// sym: ??_G?$ParamFloatConstRange@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111970 fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_0 (30 B): matches/0x00111970.cpp
// sym: ??_G?$ParamEnumConstList@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001119a0 fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (36 B): matches/0x001119a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AIHistorySetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a4890, 0) != 0;
}


// 0x001119d0 fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (30 B): matches/0x001119d0.cpp
// sym: ??_G?$ParamFloatConstRange@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001119f0 fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (30 B): matches/0x001119f0.cpp
// sym: ??_G?$ParamBool@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111a10 fight::ParamName<hulkfight::ai::AIHistorySetTrack>::vfunc_0 (30 B): matches/0x00111a10.cpp
// sym: ??_G?$ParamName@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111a40 fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_0 (36 B): matches/0x00111a40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VTokenTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004a4930, 0) != 0;
}


// 0x00111a70 fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::vfunc_0 (30 B): matches/0x00111a70.cpp
// sym: ??_G?$ParamFloatConstRange@VTokenTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111a90 fight::ParamBool<hulkfight::ai::TokenTrack>::vfunc_0 (30 B): matches/0x00111a90.cpp
// sym: ??_G?$ParamBool@VTokenTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111ab0 FUN_00111ab0 (9 B): matches/0x00111ab0.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: ??0?$TrackFactoryCasterTemplate@VSemaphoreWaitTrack@ai@hulkfight@fn_00111ab0@@@fight@fn_00111ab0@@QAE@XZ
namespace fn_00111ab0 {
namespace hulkfight {
namespace ai {
class SemaphoreWaitTrack;
}
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    TrackFactoryCasterTemplate();
    virtual void f();
};
template <> TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::TrackFactoryCasterTemplate() {}
} // namespace fight
} // namespace fn_00111ab0


// 0x00111ac0 fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (36 B): matches/0x00111ac0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    int x = ((int)(hulk_uintptr)__RTDynamicCast((void*)(arg), 0, (void*)&DAT_0049850c, (void*)&DAT_004a49d0, 0));
    return (x != 0) ? 1 : 0;
}


// 0x00111af0 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (30 B): matches/0x00111af0.cpp
// sym: ??_G?$ParamFloatConstRange@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111b10 fight::ParamName<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (30 B): matches/0x00111b10.cpp
// sym: ??_G?$ParamName@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00111b30 fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0 (30 B): matches/0x00111b30.cpp
// sym: ??_G?$ParamBool@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_fee140f0 {

} // namespace fn_fee140f0

namespace fn_fee140f0 {

} // namespace fn_fee140f0

namespace fn_fee140f0 {

} // namespace fn_fee140f0

namespace fn_fee140f0 {

} // namespace fn_fee140f0

namespace fn_fee140f0 {

} // namespace fn_fee140f0

// 0x00111b50 FUN_00111b50 (231 B): matches/0x00111b50.cpp
// sym: ?FUN_00111b50@@YAXXZ
// (gx2, D18) from SemaphoreWaitTrack_3.new_plain.cpp; constructs the real ParamBool<hulkfight::ai::OnBlockedTriangleCondition>, ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>, ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_00111b50()
{
    if (DAT_004e0ae4 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::OnBlockedTriangleCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f15aa14c::Obj_10c0d0::SetCompare_0010c0d0);
        params[1] = new ::fight::ParamBool< ::hulkfight::ai::OnBlockedTriangleCondition>("target", &fn_f15aa14c::Obj_10c0f0::SetTarget_0010c0f0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::ai::OnBlockedTriangleCondition>("smartPropIndex", &fn_f15aa14c::X_10c110::SetSmartPropIndex_0010c110);
        FUN_002347b0(&DAT_004e0ae0, params, 3);
    }
    DAT_004e0ae4++;
}



// 0x00111c40 FUN_00111c40 (95 B): matches/0x00111c40.cpp
// sym: _FUN_00111c40
// (gx2, D18) rewritten; constructs the real ParamBranch<hulkfight::ai::AIFightNodeCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00111c40()
{
    if (DAT_004e0aec == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBranch< ::hulkfight::ai::AIFightNodeCondition>("branch", &fn_f15aa14c::Obj_10c120::Get);
        FUN_002347b0(&DAT_004e0ae8, params, 1);
    }
    DAT_004e0aec++;
}



// 0x00111ca0 FUN_00111ca0 (95 B): matches/0x00111ca0.cpp
// sym: _FUN_00111ca0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::DefendingCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00111ca0()
{
    if (DAT_004e0af4 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::DefendingCondition>("defending", &owners::Obj_10c130::FUN_0010c130);
        FUN_002347b0(&DAT_004e0af0, params, 1);
    }
    DAT_004e0af4++;
}



// 0x00111d00 FUN_00111d00 (231 B): matches/0x00111d00.cpp
// sym: _FUN_00111d00
// (gx2, D18) from SemaphoreWaitTrack_3.iso_00111d00.cpp; constructs the real ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>, ParamFloatConstRange<hulkfight::ai::AIHistoryNameCondition>, ParamString<hulkfight::ai::AIHistoryNameCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00111d00()
{
    if (DAT_004e0afc == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::AIHistoryNameCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f15aa14c::Obj_10c140::SetCompare_0010c140);
        params[1] = new ::fight::ParamString< ::hulkfight::ai::AIHistoryNameCondition>("text", &fn_f15aa14c::Owner::SetText_0010c8d0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AIHistoryNameCondition>("value", &fn_f15aa14c::Obj_10c170::SetValue_0010c170);
        FUN_002347b0(&DAT_004e0af8, params, 3);
    }
    DAT_004e0afc++;
}



// 0x00111df0 FUN_00111df0 (176 B): matches/0x00111df0.cpp
// sym: _FUN_00111df0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>, ParamString<hulkfight::ai::HulkActionLargestCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00111df0()
{
    if (DAT_004e0b04 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::HulkActionLargestCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::A_10c180::FUN_0010c180);
        params[1] = new ::fight::ParamString< ::hulkfight::ai::HulkActionLargestCondition>("text", &owners::Obj_10c9b0::FUN_0010c9b0);
        FUN_002347b0(&DAT_004e0b00, params, 2);
    }
    DAT_004e0b04++;
}



// 0x00111ea0 FUN_00111ea0 (176 B): matches/0x00111ea0.cpp
// sym: _FUN_00111ea0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>, ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00111ea0()
{
    if (DAT_004e0b0c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::PropsToChuckCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_10c1a0::FUN_0010c1a0);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::ai::PropsToChuckCondition>("number", &owners::O_10c1c0::FUN_0010c1c0);
        FUN_002347b0(&DAT_004e0b08, params, 2);
    }
    DAT_004e0b0c++;
}



// 0x00111f50 FUN_00111f50 (176 B): matches/0x00111f50.cpp
// sym: _FUN_00111f50
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>, ParamString<hulkfight::ai::HulkActionRecentCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00111f50()
{
    if (DAT_004e0b14 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::HulkActionRecentCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::O_10c1d0::FUN_0010c1d0);
        params[1] = new ::fight::ParamString< ::hulkfight::ai::HulkActionRecentCondition>("text", &owners::Obj_10cb00::FUN_0010cb00);
        FUN_002347b0(&DAT_004e0b10, params, 2);
    }
    DAT_004e0b14++;
}



// 0x00112000 FUN_00112000 (95 B): matches/0x00112000.cpp
// sym: _FUN_00112000
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::LeashedCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112000()
{
    if (DAT_004e0b1c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::LeashedCondition>("leashed", &owners::Obj_10c1f0::FUN_0010c1f0);
        FUN_002347b0(&DAT_004e0b18, params, 1);
    }
    DAT_004e0b1c++;
}



// 0x00112060 FUN_00112060 (231 B): matches/0x00112060.cpp
// sym: _FUN_00112060
// (gx2, D18) from SemaphoreWaitTrack_3.iso_00112060.cpp; constructs the real ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>, ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition>, ParamString<hulkfight::ai::KeyWordWaitCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112060()
{
    if (DAT_004e0b24 == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::KeyWordWaitCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f15aa14c::X_10c200::SetCompare_0010c200);
        params[1] = new ::fight::ParamString< ::hulkfight::ai::KeyWordWaitCondition>("text", &fn_f15aa14c::Obj::SetText_0010cc40);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::KeyWordWaitCondition>("value", &fn_f15aa14c::X_10c230::SetValue_0010c230);
        FUN_002347b0(&DAT_004e0b20, params, 3);
    }
    DAT_004e0b24++;
}



// 0x00112150 FUN_00112150 (176 B): matches/0x00112150.cpp
// sym: _FUN_00112150
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::FormationReadyCondition>, ParamString<hulkfight::ai::FormationReadyCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112150()
{
    if (DAT_004e0b2c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::FormationReadyCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::O_10c240::FUN_0010c240);
        params[1] = new ::fight::ParamString< ::hulkfight::ai::FormationReadyCondition>("text", &owners::Obj_10cd20::FUN_0010cd20);
        FUN_002347b0(&DAT_004e0b28, params, 2);
    }
    DAT_004e0b2c++;
}



// 0x00112200 FUN_00112200 (176 B): matches/0x00112200.cpp
// sym: _FUN_00112200
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::InActiveCondition>, ParamEnumConstList<hulkfight::ai::InActiveCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112200()
{
    if (DAT_004e0b34 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::InActiveCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_10c250::FUN_0010c250);
        params[1] = new ::fight::ParamBool< ::hulkfight::ai::InActiveCondition>("active", &owners::X_10c270::FUN_0010c270);
        FUN_002347b0(&DAT_004e0b30, params, 2);
    }
    DAT_004e0b34++;
}



// 0x001122b0 FUN_001122b0 (231 B): matches/0x001122b0.cpp
// sym: _FUN_001122b0
// (gx2, D18) from SemaphoreWaitTrack_3.iso_001122b0.cpp; constructs the real ParamEnumConstList<hulkfight::ai::HulkActionCountCondition>, ParamFloatConstRange<hulkfight::ai::HulkActionCountCondition>, ParamString<hulkfight::ai::HulkActionCountCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001122b0()
{
    if (DAT_004e0b3c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::HulkActionCountCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f15aa14c::O_10c280::SetCompare_0010c280);
        params[1] = new ::fight::ParamString< ::hulkfight::ai::HulkActionCountCondition>("text", &fn_f15aa14c::Obj::SetText_0010ce60);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::HulkActionCountCondition>("value", &fn_f15aa14c::C_10c2b0::SetValue_0010c2b0);
        FUN_002347b0(&DAT_004e0b38, params, 3);
    }
    DAT_004e0b3c++;
}



// 0x001123a0 FUN_001123a0 (274 B): matches/0x001123a0.cpp
// sym: ?FUN_001123a0@@YAXXZ
// (gx2, D18) from SemaphoreWaitTrack_3.iso_001123a0.cpp; constructs the real ParamBool<hulkfight::ai::PropsToSuckCondition>, ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>, ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>, ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>,
// whose vftable and scalar deleting destructor it emits
void FUN_001123a0()
{
    if (DAT_004e0b44 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::PropsToSuckCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &fn_f15aa14c::Obj_10c2c0::SetCompare_0010c2c0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::PropsToSuckCondition>("distance", &fn_f15aa14c::C_10c2e0::SetDistance_0010c2e0);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::PropsToSuckCondition>("numberofAttachedProps", &fn_f15aa14c::T_10c300::SetNumberofAttachedProps_0010c300);
        params[3] = new ::fight::ParamIntConstRange< ::hulkfight::ai::PropsToSuckCondition>("number", &fn_f15aa14c::X_10c320::SetNumber_0010c320);
        FUN_002347b0(&DAT_004e0b40, params, 4);
    }
    DAT_004e0b44++;
}



// 0x001124c0 FUN_001124c0 (176 B): matches/0x001124c0.cpp
// sym: _FUN_001124c0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>, ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001124c0()
{
    if (DAT_004e0b4c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::RandomKeyWordWaitCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_10c330::FUN_0010c330);
        params[1] = new ::fight::ParamIntConstRange< ::hulkfight::ai::RandomKeyWordWaitCondition>("value", &owners::Obj_10c350::FUN_0010c350);
        FUN_002347b0(&DAT_004e0b48, params, 2);
    }
    DAT_004e0b4c++;
}



// 0x00112570 FUN_00112570 (158 B): matches/0x00112570.cpp
// sym: _FUN_00112570
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::TokenCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112570()
{
    if (DAT_004e0b54 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamBool< ::hulkfight::ai::TokenCondition>("oRNoOneHas", &owners::Obj_10c370::FUN_0010c370);
        params[1] = new ::fight::ParamBool< ::hulkfight::ai::TokenCondition>("have", &owners::Obj_10c390::FUN_0010c390);
        FUN_002347b0(&DAT_004e0b50, params, 2);
    }
    DAT_004e0b54++;
}



// 0x00112610 FUN_00112610 (113 B): matches/0x00112610.cpp
// sym: _FUN_00112610
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112610()
{
    if (DAT_004e0b5c == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamEnumConstList< ::hulkfight::ai::FightingOtherNPCCondition>("compare", (void*)&DAT_0042773c, DAT_00427754, &owners::Obj_10c3a0::FUN_0010c3a0);
        FUN_002347b0(&DAT_004e0b58, params, 1);
    }
    DAT_004e0b5c++;
}



// 0x00112690 FUN_00112690 (307 B): matches/0x00112690.cpp
// sym: _FUN_00112690
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::SemaphoreClearTrack>, ParamFloatConstRange<hulkfight::ai::SemaphoreClearTrack>, ParamName<hulkfight::ai::SemaphoreClearTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112690()
{
    if (DAT_004e0b64 == 0) {
        ::fight::ParamValue* params[5];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::SemaphoreClearTrack>("timeBegin", &owners::Obj_10c3b0::FUN_0010c3b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::SemaphoreClearTrack>("timeEnd", &owners::Obj_10c3c0::FUN_0010c3c0);
        params[2] = new ::fight::ParamName< ::hulkfight::ai::SemaphoreClearTrack>("semaphore", &fn_f15aa14c::X_10c3d0::Get);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::SemaphoreClearTrack>("clearEveryFrame", &owners::Obj_10c3f0::FUN_0010c3f0);
        params[4] = new ::fight::ParamBool< ::hulkfight::ai::SemaphoreClearTrack>("clearAll", &owners::Obj_10c410::FUN_0010c410);
        FUN_002347b0(&DAT_004e0b60, params, 5);
    }
    DAT_004e0b64++;
}



// 0x001127d0 FUN_001127d0 (358 B): matches/0x001127d0.cpp
// sym: _FUN_001127d0
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::TokenSupressTrack>, ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001127d0()
{
    if (DAT_004e0b6c == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TokenSupressTrack>("timeBegin", &owners::X_10c420::FUN_0010c420);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TokenSupressTrack>("timeEnd", &owners::O_10c430::FUN_0010c430);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::TokenSupressTrack>("supressEveryFrame", &owners::Obj_10c450::FUN_0010c450);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TokenSupressTrack>("floatDelayDuration", &owners::X_10c470::FUN_0010c470);
        params[4] = new ::fight::ParamBool< ::hulkfight::ai::TokenSupressTrack>("floatDelayDurationPermenant", &owners::Obj_10c490::FUN_0010c490);
        params[5] = new ::fight::ParamBool< ::hulkfight::ai::TokenSupressTrack>("floatDelayEndOnTrackFinish", &owners::Obj_10c4b0::FUN_0010c4b0);
        FUN_002347b0(&DAT_004e0b68, params, 6);
    }
    DAT_004e0b6c++;
}



// 0x00112940 FUN_00112940 (95 B): matches/0x00112940.cpp
// sym: _FUN_00112940
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112940()
{
    if (DAT_004e0b74 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AIHistoryCountTrack>("value", &owners::C_10c4c0::FUN_0010c4c0);
        FUN_002347b0(&DAT_004e0b70, params, 1);
    }
    DAT_004e0b74++;
}



// 0x001129a0 FUN_001129a0 (256 B): matches/0x001129a0.cpp
// sym: _FUN_001129a0
// (gx2, D18) from SemaphoreWaitTrack_3.iso_001129a0.cpp; constructs the real ParamFloatConstRange<hulkfight::ai::HulkActionTrack>, ParamName<hulkfight::ai::HulkActionTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_001129a0()
{
    if (DAT_004e0b7c == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::HulkActionTrack>("timeBegin", &fn_f15aa14c::A_10c4d0::SetTimeBegin_0010c4d0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::HulkActionTrack>("timeEnd", &fn_f15aa14c::T_10c4e0::SetTimeEnd_0010c4e0);
        params[2] = new ::fight::ParamName< ::hulkfight::ai::HulkActionTrack>("text", &fn_f15aa14c::Obj_10c4f0::GetText_0010c4f0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::HulkActionTrack>("value", &fn_f15aa14c::A_10c510::SetValue_0010c510);
        FUN_002347b0(&DAT_004e0b78, params, 4);
    }
    DAT_004e0b7c++;
}



// 0x00112aa0 FUN_00112aa0 (256 B): matches/0x00112aa0.cpp
// sym: _FUN_00112aa0
// (gx2, D18) from SemaphoreWaitTrack_3.iso_00112aa0.cpp; constructs the real ParamBool<hulkfight::ai::KeywordWaitTrack>, ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>, ParamName<hulkfight::ai::KeywordWaitTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112aa0()
{
    if (DAT_004e0b84 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::KeywordWaitTrack>("timeBegin", &fn_f15aa14c::C_10c520::SetTimeBegin_0010c520);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::KeywordWaitTrack>("timeEnd", &fn_f15aa14c::Obj_10c530::SetTimeEnd_0010c530);
        params[2] = new ::fight::ParamName< ::hulkfight::ai::KeywordWaitTrack>("keyword", &fn_f15aa14c::Obj_10c540::GetKeyword_0010c540);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::KeywordWaitTrack>("randomIntroWait", &fn_f15aa14c::Obj_10c550::SetRandomIntroWait_0010c550);
        FUN_002347b0(&DAT_004e0b80, params, 4);
    }
    DAT_004e0b84++;
}



// 0x00112ba0 FUN_00112ba0 (386 B): matches/0x00112ba0.cpp
// sym: _FUN_00112ba0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<hulkfight::ai::ButtonTrack>, ParamFloatConstRange<hulkfight::ai::ButtonTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112ba0()
{
    if (DAT_004e0b8c == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ButtonTrack>("timeBegin", &owners::O_10c560::FUN_0010c560);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ButtonTrack>("timeEnd", &fn_f15aa14c::T_10c570::Set);
        params[2] = new ::fight::ParamEnumConstList< ::hulkfight::ai::ButtonTrack>("button", (void*)&DAT_0049ee30, 13, &owners::Obj_10c590::FUN_0010c590);
        params[3] = new ::fight::ParamEnumConstList< ::hulkfight::ai::ButtonTrack>("state", (void*)&DAT_0049ee64, 4, &owners::Obj_10c5b0::FUN_0010c5b0);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ButtonTrack>("time", &owners::O_10c5d0::FUN_0010c5d0);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::ButtonTrack>("value", &owners::Obj_10c5f0::FUN_0010c5f0);
        FUN_002347b0(&DAT_004e0b88, params, 6);
    }
    DAT_004e0b8c++;
}



// 0x00112d30 FUN_00112d30 (256 B): matches/0x00112d30.cpp
// sym: ?FUN_00112d30@@YAXXZ
// (gx2, D18) from SemaphoreWaitTrack_3.iso_00112d30.cpp; constructs the real ParamBool<hulkfight::ai::AIHistorySetTrack>, ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>, ParamName<hulkfight::ai::AIHistorySetTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00112d30()
{
    if (DAT_004e0b94 == 0) {
        ::fight::ParamValue* params[4];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AIHistorySetTrack>("timeBegin", &fn_f15aa14c::Obj_10c600::SetTimeBegin_0010c600);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::AIHistorySetTrack>("timeEnd", &fn_f15aa14c::X_10c610::SetTimeEnd_0010c610);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::AIHistorySetTrack>("onlySetAtEnd", &fn_f15aa14c::O_10c620::SetOnlySetAtEnd_0010c620);
        params[3] = new ::fight::ParamName< ::hulkfight::ai::AIHistorySetTrack>("text", &GetText_0010c630);
        FUN_002347b0(&DAT_004e0b90, params, 4);
    }
    DAT_004e0b94++;
}



// 0x00112e30 FUN_00112e30 (213 B): matches/0x00112e30.cpp
// sym: _FUN_00112e30
// (gx2, D18) from SemaphoreWaitTrack_3.iso_00112e30.cpp; constructs the real ParamBool<hulkfight::ai::TokenTrack>, ParamFloatConstRange<hulkfight::ai::TokenTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112e30()
{
    if (DAT_004e0b9c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TokenTrack>("timeBegin", &fn_f15aa14c::T_10c640::SetTimeBegin_0010c640);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::TokenTrack>("timeEnd", &fn_f15aa14c::Obj_10c650::SetTimeEnd_0010c650);
        params[2] = new ::fight::ParamBool< ::hulkfight::ai::TokenTrack>("floatDelayOnEnd", &fn_f15aa14c::Obj_10c670::SetFloatDelayOnEnd_0010c670);
        FUN_002347b0(&DAT_004e0b98, params, 3);
    }
    DAT_004e0b9c++;
}



// 0x00112f10 FUN_00112f10 (358 B): matches/0x00112f10.cpp
// sym: _FUN_00112f10
// (gx2, D18) rewritten; constructs the real ParamBool<hulkfight::ai::SemaphoreWaitTrack>, ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>, ParamName<hulkfight::ai::SemaphoreWaitTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00112f10()
{
    if (DAT_004e0ba4 == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::SemaphoreWaitTrack>("timeBegin", &owners::T_10c680::FUN_0010c680);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::SemaphoreWaitTrack>("timeEnd", &owners::Obj_10c690::FUN_0010c690);
        params[2] = new ::fight::ParamName< ::hulkfight::ai::SemaphoreWaitTrack>("semaphore", &owners::Obj_10c6a0::FUN_0010c6a0);
        params[3] = new ::fight::ParamBool< ::hulkfight::ai::SemaphoreWaitTrack>("interuptable", &owners::Obj_10c6c0::FUN_0010c6c0);
        params[4] = new ::fight::ParamBool< ::hulkfight::ai::SemaphoreWaitTrack>("useCharacterTimeout", &owners::Obj_10c6e0::FUN_0010c6e0);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::ai::SemaphoreWaitTrack>("timeoutOverride", &owners::O_10c700::FUN_0010c700);
        FUN_002347b0(&DAT_004e0ba0, params, 6);
    }
    DAT_004e0ba4++;
}



// 0x00113080 hulkfight::ai::ButtonTrack::vfunc_10 (70 B): matches/0x00113080.cpp
// sym: ?vfunc_10@ButtonTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ButtonTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        Object_113080* p = Alloc_0008d690((int)sizeof(::hulkfight::ai::ButtonAction));   // (allocsize1) the size by gen's record
        if (p)
            return p->Init_0010ec00(this, c);
    }
    return 0;
}

namespace fn_fee140f0 {

// 0x001130d0 hulkfight::ai::ButtonAction::vfunc_2 (71 B): matches/0x001130d0.cpp
// sym: ?vfunc_2@ButtonAction_1130d0@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ButtonAction_1130d0* ButtonAction_1130d0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd34;
    RefCounted_1130d0* q = *(RefCounted_1130d0* volatile*)&m_20;
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


// 0x00113170 hulkfight::ai::HulkAction::vfunc_2 (71 B): matches/0x00113170.cpp
// sym: ?vfunc_2@HulkAction_113170@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
HulkAction_113170* HulkAction_113170::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd50;
    RefCounted_113170* q = *(RefCounted_113170* volatile*)&m_20;
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


// 0x00113210 hulkfight::ai::TokenSupressAction::vfunc_2 (71 B): matches/0x00113210.cpp
// sym: ?vfunc_2@TokenSupressAction_113210@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TokenSupressAction_113210* TokenSupressAction_113210::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd6c;
    RefCounted_113210* q = *(RefCounted_113210* volatile*)&m_20;
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


// 0x001132b0 hulkfight::ai::TokenAction::vfunc_2 (71 B): matches/0x001132b0.cpp
// sym: ?vfunc_2@TokenAction_1132b0@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TokenAction_1132b0* TokenAction_1132b0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dd88;
    RefCounted_1132b0* q = *(RefCounted_1132b0* volatile*)&m_20;
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


// 0x00113350 hulkfight::ai::AIHistorySetAction::vfunc_2 (71 B): matches/0x00113350.cpp
// sym: ?vfunc_2@AIHistorySetAction_113350@fn_fee140f0@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
AIHistorySetAction_113350* AIHistorySetAction_113350::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040dda4;
    RefCounted_113350* q = *(RefCounted_113350* volatile*)&m_20;
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

} // namespace fn_fee140f0
