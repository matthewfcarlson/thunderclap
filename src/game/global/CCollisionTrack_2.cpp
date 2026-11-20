// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005d850..0x000604d0 (kind game, layer game, confidence high), merged by D32: global/CCollisionTrack.cpp
// piece 0x0005fa10..0x000604d0 (kind game, layer game, confidence low); was game/unknown/unk_05fa10.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe2e62b7 {
#define TREE_TU_END }
namespace fn_fe2e62b7 {} using namespace fn_fe2e62b7;
#include "game/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f133b0a3 { struct Src_5d6c0; } 
namespace fn_f133b0a3 { struct Owner_5d6c0 { bool Set(struct fn_f133b0a3::Src_5d6c0 *); }; }   // (gx3, D18) setters, as defined in unk_05d370.cpp
namespace fn_ff0a839e { struct O_130f0 { int * Get(); }; }   // (gx3, D18) setters, as defined in unk_011000.cpp

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fe2e62b7 {
extern "C" void* FUN_0008d690(unsigned int size);
class COpportunityBallTrack_5fa10 {
public:
    bool FUN_0005d690(int); /* (unb4) as defined; address taken only */
    char FUN_0005d6a0(int); /* (unb4) as defined; address taken only */
    void FUN_0005d6b0();
    bool FUN_0005d6c0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0005d6e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d6f0(int); /* (unb4) as defined; address taken only */
    void FUN_00013050();
    void FUN_00013060();
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CProceduralDurationAnimationTrack_5fbe0 {
public:
    bool FUN_0005d700(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d710(int); /* (unb4) as defined; address taken only */
    char FUN_0005d720(int); /* (unb4) as defined; address taken only */
    void FUN_00013090();
    bool FUN_0005d730(int); /* (unb4) as defined; address taken only */
    char FUN_0005d740(int); /* (unb4) as defined; address taken only */
    char FUN_0005d750(int); /* (unb4) as defined; address taken only */
    char FUN_0005d760(int); /* (unb4) as defined; address taken only */
    char FUN_0005d770(int); /* (unb4) as defined; address taken only */
    void FUN_000130f0();
    char FUN_0005d780(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d790(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d7a0(int); /* (unb4) as defined; address taken only */
    char FUN_0005d7b0(char); /* (unb4) as defined; address taken only */
};
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
} // namespace fn_fe2e62b7
namespace fight {
template <class T>
class ParamBool_5fbe0 : public ParamBoolBase {
public:
    ParamBool_5fbe0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_5fbe0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_5fbe0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_5fbe0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5fbe0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5fbe0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5fbe0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_5fbe0 : public ParamNameBase {
public:
    ParamName_5fbe0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fe2e62b7 {
class CStunAnimationTrack_5fef0 {
public:
    bool FUN_0005d7c0(int); /* (unb4) as defined; address taken only */
    void FUN_00013140();
    char FUN_0005d7d0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d7e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d7f0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d800(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d810(int); /* (unb4) as defined; address taken only */
    void FUN_000131a0();
    bool FUN_0005d820(int); /* (unb4) as defined; address taken only */
    char FUN_0005d830(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d840(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_fe2e62b7
namespace fight {
template <class T>
class ParamFloatConstRange_5fef0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5fef0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_5fef0 : public ParamNameBase {
public:
    ParamName_5fef0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5fef0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5fef0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_5fef0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_5fef0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
namespace fn_fe2e62b7 {
struct Sub_60170 {
    char data[8];
};
struct Object {
    char head[0x10c];
    int f10c, f110, f114, f118, f11c, f120, f124, f128, f12c, f130, f134, f138, f13c;
    Sub_60170 sub;
    char flag;
    void FUN_00060170();
};
class Sub_601f0 {
  public:
    void Call_0027af00();
};
struct Data_602a0 {
    int x;
};
class Obj_602a0 {
  public:
    char pad[0x58];
    Data_602a0* Get();
};
struct V {
    int a;
    int b;
    int c;
};
class T_602d0 {
  public:
    char Pad[0x6c];
    int m6c;
    int m70;
    int m74;
    char Set(V* v);
};
class Thing {
  public:
    char pad[0x9c];
    Src s;
    bool Set(const Src* p);
};
struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x84];
    int a;
    int b;
    int c;
    char _m_pad_90[0x20];
    int m_b0;
    int m_b4;
    int m_b8;
    bool FUN_00060310(const V3* v);
    bool FUN_000603a0(const Vec3* v);
};
struct Vec3_60450 {
    int x, y, z;
};
class Obj_60450 {
  public:
    char pad[0x38];
    int a;
    int b;
    int c;
    bool Set(const Vec3_60450* v);
};


} // namespace fn_fe2e62b7

// 0x0005eb90 fight::ParamFloatConstRange<COpportunityBallTrack>::vfunc_0 (30 B): matches/0x0005eb90.cpp
// sym: ??_G?$ParamFloatConstRange@VCOpportunityBallTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ebb0 fight::ParamVector<COpportunityBallTrack>::vfunc_0 (30 B): matches/0x0005ebb0.cpp
// sym: ??_G?$ParamVector@VCOpportunityBallTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ebd0 fight::ParamIntConstRange<COpportunityBallTrack>::vfunc_0 (30 B): matches/0x0005ebd0.cpp
// sym: ??_G?$ParamIntConstRange@VCOpportunityBallTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ebf0 fight::ParamBranch<COpportunityBallTrack>::vfunc_0 (30 B): matches/0x0005ebf0.cpp
// sym: ??_G?$ParamBranch@VCOpportunityBallTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ec10 fight::ParamFloatConstRange<CProceduralDurationAnimationTrack>::vfunc_0 (30 B): matches/0x0005ec10.cpp
// sym: ??_G?$ParamFloatConstRange@VCProceduralDurationAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ec30 fight::ParamEnumConstList<CProceduralDurationAnimationTrack>::vfunc_0 (30 B): matches/0x0005ec30.cpp
// sym: ??_G?$ParamEnumConstList@VCProceduralDurationAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ec50 fight::ParamIntConstRange<CProceduralDurationAnimationTrack>::vfunc_0 (30 B): matches/0x0005ec50.cpp
// sym: ??_G?$ParamIntConstRange@VCProceduralDurationAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ec70 fight::ParamBool<CProceduralDurationAnimationTrack>::vfunc_0 (30 B): matches/0x0005ec70.cpp
// sym: ??_G?$ParamBool@VCProceduralDurationAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ec90 fight::ParamFloatConstRange<CStunAnimationTrack>::vfunc_0 (30 B): matches/0x0005ec90.cpp
// sym: ??_G?$ParamFloatConstRange@VCStunAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ecb0 fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_0 (30 B): matches/0x0005ecb0.cpp
// sym: ??_G?$ParamEnumConstList@VCStunAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005ecd0 fight::ParamIntConstRange<CStunAnimationTrack>::vfunc_0 (30 B): matches/0x0005ecd0.cpp
// sym: ??_G?$ParamIntConstRange@VCStunAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005f0f0 fight::ParamNameConstList<COpportunityBallTrack>::vfunc_0 (30 B): matches/0x0005f0f0.cpp
// sym: ??_G?$ParamNameConstList@VCOpportunityBallTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005f110 fight::ParamName<CProceduralDurationAnimationTrack>::vfunc_0 (30 B): matches/0x0005f110.cpp
// sym: ??_G?$ParamName@VCProceduralDurationAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005f130 fight::ParamName<CStunAnimationTrack>::vfunc_0 (30 B): matches/0x0005f130.cpp
// sym: ??_G?$ParamName@VCStunAnimationTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCollisionTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005fa10 / FUN_0005fbe0 / FUN_0005fef0)



// 0x0005fa10 FUN_0005fa10 (460 B): matches/0x0005fa10.cpp
// sym: _FUN_0005fa10
// (gx2, D18) rewritten; constructs the real ParamBranch<COpportunityBallTrack>, ParamFloatConstRange<COpportunityBallTrack>, ParamIntConstRange<COpportunityBallTrack>, ParamNameConstList<COpportunityBallTrack>, ParamVector<COpportunityBallTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005fa10()
{
    if (DAT_004dc5dc == 0) {
        ::fight::ParamValue* params[8];
        params[0] = new ::fight::ParamFloatConstRange< ::COpportunityBallTrack>("timeBegin", &owners::Obj_5d690::FUN_0005d690);
        params[1] = new ::fight::ParamFloatConstRange< ::COpportunityBallTrack>("timeEnd", &owners::A_5d6a0::FUN_0005d6a0);
        params[2] = new ::fight::ParamNameConstList< ::COpportunityBallTrack>("joint", &owners::Obj_5d6b0::FUN_0005d6b0);
        params[3] = new ::fight::ParamVector< ::COpportunityBallTrack>("offset", &fn_f133b0a3::Owner_5d6c0::Set);
        params[4] = new ::fight::ParamFloatConstRange< ::COpportunityBallTrack>("radius", &owners::C_5d6e0::FUN_0005d6e0);
        params[5] = new ::fight::ParamIntConstRange< ::COpportunityBallTrack>("maxHitCount", &owners::A_5d6f0::FUN_0005d6f0);
        params[6] = new ::fight::ParamBranch< ::COpportunityBallTrack>("receiver", &owners::A_13050::FUN_00013050);
        params[7] = new ::fight::ParamBranch< ::COpportunityBallTrack>("giver", &owners::Obj_13060::FUN_00013060);
        FUN_002347b0(&DAT_004dc5d8, params, 8);
    }
    DAT_004dc5dc++;
}



// 0x0005fbe0 FUN_0005fbe0 (784 B): matches/0x0005fbe0.cpp
// sym: _FUN_0005fbe0
// (gx2, D18) rewritten; constructs the real ParamBool<CProceduralDurationAnimationTrack>, ParamEnumConstList<CProceduralDurationAnimationTrack>, ParamFloatConstRange<CProceduralDurationAnimationTrack>, ParamIntConstRange<CProceduralDurationAnimationTrack>, ParamName<CProceduralDurationAnimationTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005fbe0()
{
    if (DAT_004dc5e4 == 0) {
        ::fight::ParamValue* params[14];
        params[0] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("timeBegin", &owners::Obj_5d700::FUN_0005d700);
        params[1] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("timeScale", &owners::Obj_5d710::FUN_0005d710);
        params[2] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("timeEndMin", &owners::Obj_5d720::FUN_0005d720);
        params[3] = new ::fight::ParamName< ::CProceduralDurationAnimationTrack>("animation", &owners::Obj_13090::FUN_00013090);
        params[4] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("speed", &owners::Obj_5d730::FUN_0005d730);
        params[5] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("initFrame", &owners::Obj_5d740::FUN_0005d740);
        params[6] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("startFrame", &owners::A_5d750::FUN_0005d750);
        params[7] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("endFrame", &owners::Obj_5d760::FUN_0005d760);
        params[8] = new ::fight::ParamEnumConstList< ::CProceduralDurationAnimationTrack>("cyclic", (void*)&DAT_004abf70, DAT_004123d4, &owners::T_5d770::FUN_0005d770);
        params[9] = new ::fight::ParamName< ::CProceduralDurationAnimationTrack>("partition", &fn_ff0a839e::O_130f0::Get);
        params[10] = new ::fight::ParamIntConstRange< ::CProceduralDurationAnimationTrack>("priority", &owners::Obj_5d780::FUN_0005d780);
        params[11] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("blendInTime", &owners::Obj_5d790::FUN_0005d790);
        params[12] = new ::fight::ParamFloatConstRange< ::CProceduralDurationAnimationTrack>("blendOutTime", &owners::Obj_5d7a0::FUN_0005d7a0);
        params[13] = new ::fight::ParamBool< ::CProceduralDurationAnimationTrack>("useRootMotion", &owners::Thing_5d7b0::FUN_0005d7b0);
        FUN_002347b0(&DAT_004dc5e0, params, 14);
    }
    DAT_004dc5e4++;
}



// 0x0005fef0 FUN_0005fef0 (631 B): matches/0x0005fef0.cpp
// sym: _FUN_0005fef0
// (gx2, D18) rewritten; constructs the real ParamEnumConstList<CStunAnimationTrack>, ParamFloatConstRange<CStunAnimationTrack>, ParamIntConstRange<CStunAnimationTrack>, ParamName<CStunAnimationTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005fef0()
{
    if (DAT_004dc5ec == 0) {
        ::fight::ParamValue* params[11];
        params[0] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("timeBegin", &owners::X_5d7c0::FUN_0005d7c0);
        params[1] = new ::fight::ParamName< ::CStunAnimationTrack>("animation", &owners::X_13140::FUN_00013140);
        params[2] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("speed", &owners::Obj_5d7d0::FUN_0005d7d0);
        params[3] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("initFrame", &owners::Obj_5d7e0::FUN_0005d7e0);
        params[4] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("startFrame", &owners::C_5d7f0::FUN_0005d7f0);
        params[5] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("endFrame", &owners::Obj_5d800::FUN_0005d800);
        params[6] = new ::fight::ParamEnumConstList< ::CStunAnimationTrack>("cyclic", (void*)&DAT_004abf70, DAT_004123d4, &owners::Obj_5d810::FUN_0005d810);
        params[7] = new ::fight::ParamName< ::CStunAnimationTrack>("partition", &owners::Obj_131a0::FUN_000131a0);
        params[8] = new ::fight::ParamIntConstRange< ::CStunAnimationTrack>("priority", &owners::Obj_5d820::FUN_0005d820);
        params[9] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("blendInTime", &owners::C_5d830::FUN_0005d830);
        params[10] = new ::fight::ParamFloatConstRange< ::CStunAnimationTrack>("blendOutTime", &owners::Obj_5d840::FUN_0005d840);
        FUN_002347b0(&DAT_004dc5e8, params, 11);
    }
    DAT_004dc5ec++;
}

namespace fn_fe2e62b7 {


// 0x00060170 FUN_00060170 (118 B): equivalent/0x00060170.cpp
// sym: ?FUN_00060170@Object@fn_fe2e62b7@@QAEXXZ @b45888004883 @w90958a31a05c @v4c41c7841ece
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060170 @ 0x00060170
void Object::FUN_00060170() {
    memset(this, 0, 0x10c);
    f114 = 0;
    f110 = 0;
    f10c = 0;
    f118 = 0;
    f124 = 0;
    f120 = 0;
    f11c = 0;
    f130 = 0;
    f12c = 0;
    f128 = 0;
    ((owners::Target_27b040 *)&sub)->FUN_0027b040((hulk_uintptr)0);
    flag = 0;
    f13c = 0;
    f138 = 0;
    f134 = 0;
}

} // namespace fn_fe2e62b7

// 0x000601f0 FUN_000601f0 (25 B): matches/0x000601f0.cpp
// sym: ?FUN_000601f0@Obj_601f0@owners@@QAEPAU12@XZ
owners::Obj_601f0* owners::Obj_601f0::FUN_000601f0() {
    ((Sub_601f0*)((char*)this + 0x140))->Call_0027af00();
    G();
    return this;
}


// 0x00060210 FUN_00060210 (12 B): matches/0x00060210.cpp
// sym: ?FUN_00060210@A_60210@owners@@QAEDH@Z
char owners::A_60210::FUN_00060210(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x00060220 FUN_00060220 (12 B): matches/0x00060220.cpp
// sym: ?FUN_00060220@Obj_60220@owners@@QAEDH@Z
char owners::Obj_60220::FUN_00060220(int x) {
    m10 = x;
    return 1;
}


// 0x00060230 FUN_00060230 (12 B): matches/0x00060230.cpp
// sym: ?FUN_00060230@Obj_60230@owners@@QAEDH@Z
char owners::Obj_60230::FUN_00060230(int x) {
    m = x;
    return 1;
}


// 0x00060240 FUN_00060240 (12 B): matches/0x00060240.cpp
// sym: ?FUN_00060240@Obj_60240@owners@@QAEDH@Z
char owners::Obj_60240::FUN_00060240(int v) {
    mVal = v;
    return 1;
}


// 0x00060250 FUN_00060250 (4 B): matches/0x00060250.cpp
// sym: ?FUN_00060250@Obj_60250@owners@@QAEPAXXZ
void* owners::Obj_60250::FUN_00060250() {
    return (char*)this + 0x30;
}


// 0x00060260 FUN_00060260 (4 B): matches/0x00060260.cpp
// sym: ?FUN_00060260@Obj_60260@owners@@QAEPADXZ
char* owners::Obj_60260::FUN_00060260() {
    return (char*)this + 0x38;
}


// 0x00060270 FUN_00060270 (4 B): matches/0x00060270.cpp
// sym: ?FUN_00060270@Obj_60270@owners@@QAEPADXZ
char* owners::Obj_60270::FUN_00060270() {
    return pad + 0x40;
}


// 0x00060280 FUN_00060280 (4 B): matches/0x00060280.cpp
// sym: ?FUN_00060280@T_60280@owners@@QAEPAXXZ
void* owners::T_60280::FUN_00060280() {
    return (char*)this + 0x48;
}


// 0x00060290 FUN_00060290 (4 B): matches/0x00060290.cpp
// sym: ?FUN_00060290@Obj_60290@owners@@QAEPAHXZ
int* owners::Obj_60290::FUN_00060290() {
    return &value;
}

namespace fn_fe2e62b7 {

// 0x000602a0 FUN_000602a0 (4 B): matches/0x000602a0.cpp
// sym: ?Get@Obj_602a0@fn_fe2e62b7@@QAEPAUData_602a0@2@XZ
Data_602a0* Obj_602a0::Get() {
    return (Data_602a0*)((char*)this + 0x58);
}

} // namespace fn_fe2e62b7

// 0x000602b0 FUN_000602b0 (26 B): matches/0x000602b0.cpp
// sym: ?FUN_000602b0@Obj_602b0@owners@@QAE_NPBX@Z
bool owners::Obj_602b0::FUN_000602b0(const void* src) {
    a = *(const int*)src;
    b = *(const int*)((const char*)src + 4);
    c = *(const int*)((const char*)src + 8);
    return true;
}

namespace fn_fe2e62b7 {

// 0x000602d0 FUN_000602d0 (26 B): matches/0x000602d0.cpp
// sym: ?Set@T_602d0@fn_fe2e62b7@@QAEDPAUV@2@@Z
char T_602d0::Set(V* v) {
    m6c = v->a;
    m70 = v->b;
    m74 = v->c;
    return 1;
}

} // namespace fn_fe2e62b7

// 0x000602f0 FUN_000602f0 (29 B): matches/0x000602f0.cpp
// sym: ?FUN_000602f0@Obj_602f0@owners@@QAE_NPAH@Z
bool owners::Obj_602f0::FUN_000602f0(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}

namespace fn_fe2e62b7 {

// 0x00060310 FUN_00060310 (35 B): matches/0x00060310.cpp
// sym: ?FUN_00060310@Obj@fn_fe2e62b7@@QAE_NPBUV3@2@@Z
bool Obj::FUN_00060310(const V3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_fe2e62b7

// 0x00060340 FUN_00060340 (35 B): matches/0x00060340.cpp
// sym: ?FUN_00060340@Obj_60340@owners@@QAEDPAX@Z
char owners::Obj_60340::FUN_00060340(void* p) {
    int* q = (int*)p;
    a = q[0];
    b = q[1];
    c = q[2];
    return 1;
}

namespace fn_fe2e62b7 {

// 0x00060370 FUN_00060370 (35 B): matches/0x00060370.cpp
// sym: ?Set@Thing@fn_fe2e62b7@@QAE_NPBUSrc@2@@Z
bool Thing::Set(const Src* p) {
    s.a = p->a;
    s.b = p->b;
    s.c = p->c;
    return true;
}


// 0x000603a0 FUN_000603a0 (35 B): matches/0x000603a0.cpp
// sym: ?FUN_000603a0@Obj@fn_fe2e62b7@@QAE_NPBUVec3@2@@Z
bool Obj::FUN_000603a0(const Vec3* v) {
    m_b0 = v->x;
    m_b4 = v->y;
    m_b8 = v->z;
    return true;
}

} // namespace fn_fe2e62b7

// 0x000603d0 FUN_000603d0 (15 B): matches/0x000603d0.cpp
// sym: ?FUN_000603d0@X_603d0@owners@@QAE_NH@Z
bool owners::X_603d0::FUN_000603d0(int v) {
    m = v;
    return true;
}


// 0x000603e0 FUN_000603e0 (15 B): matches/0x000603e0.cpp
// sym: ?FUN_000603e0@X_603e0@owners@@QAEDH@Z
char owners::X_603e0::FUN_000603e0(int v) {
    mVal = v;
    return 1;
}


// 0x000603f0 FUN_000603f0 (15 B): matches/0x000603f0.cpp
// sym: ?FUN_000603f0@T_603f0@owners@@QAE_NH@Z
bool owners::T_603f0::FUN_000603f0(int x) {
    m = x;
    return true;
}


// 0x00060400 FUN_00060400 (15 B): matches/0x00060400.cpp
// sym: ?FUN_00060400@Obj_60400@owners@@QAE_ND@Z
bool owners::Obj_60400::FUN_00060400(char c) {
    pad[0xc8] = c;
    return true;
}


// 0x00060410 FUN_00060410 (15 B): matches/0x00060410.cpp
// sym: ?FUN_00060410@Obj_60410@owners@@QAE_NE@Z
bool owners::Obj_60410::FUN_00060410(unsigned char v) {
    value = v;
    return true;
}


// 0x00060420 FUN_00060420 (15 B): matches/0x00060420.cpp
// sym: ?FUN_00060420@Obj_60420@owners@@QAE_NH@Z
bool owners::Obj_60420::FUN_00060420(int v) {
    mValue = v;
    return true;
}


// 0x00060430 FUN_00060430 (12 B): matches/0x00060430.cpp
// sym: ?FUN_00060430@Obj_60430@owners@@QAE_NH@Z
bool owners::Obj_60430::FUN_00060430(int v) {
    m = v;
    return true;
}


// 0x00060440 FUN_00060440 (12 B): matches/0x00060440.cpp
// sym: ?FUN_00060440@Obj_60440@owners@@QAE_NH@Z
bool owners::Obj_60440::FUN_00060440(int x) {
    value = x;
    return true;
}

namespace fn_fe2e62b7 {

// 0x00060450 FUN_00060450 (26 B): matches/0x00060450.cpp
// sym: ?Set@Obj_60450@fn_fe2e62b7@@QAE_NPBUVec3_60450@2@@Z
bool Obj_60450::Set(const Vec3_60450* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_fe2e62b7

// 0x00060470 FUN_00060470 (12 B): matches/0x00060470.cpp
// sym: ?FUN_00060470@Obj_60470@owners@@QAE_NH@Z
bool owners::Obj_60470::FUN_00060470(int v) {
    m20 = v;
    return true;
}


// 0x00060480 FUN_00060480 (12 B): matches/0x00060480.cpp
// sym: ?FUN_00060480@Obj_60480@owners@@QAE_NH@Z
bool owners::Obj_60480::FUN_00060480(int x) {
    field = x;
    return true;
}


// 0x00060490 FUN_00060490 (12 B): matches/0x00060490.cpp
// sym: ?FUN_00060490@Obj_60490@owners@@QAEDD@Z
char owners::Obj_60490::FUN_00060490(char c) {
    m50 = c;
    return 1;
}


// 0x000604a0 FUN_000604a0 (12 B): matches/0x000604a0.cpp
// sym: ?FUN_000604a0@Obj_604a0@owners@@QAEEE@Z
unsigned char owners::Obj_604a0::FUN_000604a0(unsigned char x) {
    Value = x;
    return 1;
}


// 0x000604b0 FUN_000604b0 (12 B): matches/0x000604b0.cpp
// sym: ?FUN_000604b0@T_604b0@owners@@QAE_NH@Z
bool owners::T_604b0::FUN_000604b0(int v) {
    m54 = v;
    return true;
}


// 0x000604c0 FUN_000604c0 (12 B): matches/0x000604c0.cpp
// sym: ?FUN_000604c0@Obj_604c0@owners@@QAE_NH@Z
bool owners::Obj_604c0::FUN_000604c0(int v) {
    m58 = v;
    return true;
}

