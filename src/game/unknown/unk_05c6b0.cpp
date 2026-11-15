// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005c6b0..0x0005d190 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f35d11f7 {
#define TREE_TU_END }
namespace fn_f35d11f7 {} using namespace fn_f35d11f7;
#include "game/unknown.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f8b0a0f7 { struct S_5a240; } 
namespace fn_f8b0a0f7 { struct S_5a390; } 
namespace fn_f8b0a0f7 { struct V; } 
namespace fn_f8b0a0f7 { struct Vec3; } 
namespace fn_f8b0a0f7 { struct Vec3_5a1b0; } 
namespace fn_ff0a839e { class C_12af0; } 
namespace fn_ff0a839e { class Obj_12990; } 
namespace fn_ff0a839e { struct S_12be0; } namespace fn_ff0a839e { struct S_12be0; } 
namespace fn_ff0a839e { struct T; } 
namespace fn_ff0a839e { void * __fastcall FUN_00012970(void *); }   // (gx3, D18) a setter, as defined in unk_011000.cpp
namespace fn_ff0a839e { void * __fastcall FUN_00012990(class fn_ff0a839e::Obj_12990 *); }   // (gx3, D18) a setter, as defined in unk_011000.cpp
namespace fn_ff0a839e { int * __fastcall FUN_00012af0(class fn_ff0a839e::C_12af0 *); }   // (gx3, D18) a setter, as defined in unk_011000.cpp
namespace fn_ff0a839e { struct fn_ff0a839e::S_12be0 * __fastcall FUN_00012be0(struct fn_ff0a839e::S_12be0 *); }   // (gx3, D18) a setter, as defined in unk_011000.cpp
namespace fn_f8b0a0f7 { struct C_5a240 { bool Set(struct fn_f8b0a0f7::S_5a240 const *); }; }   // (gx3, D18) setters, as defined in CFightParamsCollision.cpp
namespace fn_f8b0a0f7 { struct O_5a140 { char Set(struct fn_f8b0a0f7::V *); }; }   // (gx3, D18) setters, as defined in CFightParamsCollision.cpp
namespace fn_f8b0a0f7 { struct O_5a390 { bool Set(struct fn_f8b0a0f7::S_5a390 *); }; }   // (gx3, D18) setters, as defined in CFightParamsCollision.cpp
namespace fn_f8b0a0f7 { struct Obj { unsigned char FUN_0005a180(struct fn_f8b0a0f7::Vec3 const *); }; }   // (gx3, D18) setters, as defined in CFightParamsCollision.cpp
namespace fn_f8b0a0f7 { struct Obj_5a1b0 { bool Set(struct fn_f8b0a0f7::Vec3_5a1b0 const *); }; }   // (gx3, D18) setters, as defined in CFightParamsCollision.cpp
namespace fn_ff0a839e { struct O_12980 { struct fn_ff0a839e::T * Get(); }; }   // (gx3, D18) setters, as defined in unk_011000.cpp
namespace fn_ff0a839e { struct Obj_12960 { void * Get(); }; }   // (gx3, D18) setters, as defined in unk_011000.cpp

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f35d11f7 {
extern "C" void* FUN_0008d690(unsigned int size);
class CGrappleLocoStrafe4Track_5c6b0 {
public:
    void FUN_0005a0d0();
    void FUN_0005a0e0();
    void FUN_00012900();
    void FUN_00012910();
    void FUN_00012920();
    void FUN_00012930();
    void FUN_00012940();
    void FUN_00012950();
    void FUN_00012960();
    void FUN_00012970();
    void FUN_00012980();
    void FUN_00012990();
    void FUN_000129a0();
    void FUN_0005a0f0();
    void FUN_0005a100();
    void FUN_0005a110();
};
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
} // namespace fn_f35d11f7
namespace fight {
template <class T>
class ParamFloatConstRange_5c6b0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5c6b0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5c6b0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5c6b0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_5c6b0 : public ParamNameBase {
public:
    ParamName_5c6b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f35d11f7 {
extern ParamRegistry hulk_at_004dc590;
extern int hulk_at_004dc594;
class CGrappleAttachTrack_5ca20 {
public:
    bool FUN_0005a120(int); /* (unb4) as defined; address taken only */
    void FUN_000129e0();
    void FUN_000129f0();
    char FUN_0005a130(char); /* (unb4) as defined; address taken only */
    char FUN_0005a140(void*); /* (unb4) as defined; address taken only */
    char FUN_0005a160(float); /* (unb4) as defined; address taken only */
    char FUN_0005a180(void*); /* (unb4) as defined; address taken only */
    void FUN_00012a60();
    bool FUN_0005a1b0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0005a1d0(int); /* (unb4) as defined; address taken only */
    char FUN_0005a1e0(int); /* (unb4) as defined; address taken only */
    char FUN_0005a1f0(char); /* (unb4) as defined; address taken only */
    bool FUN_0005a200(int); /* (unb4) as defined; address taken only */
    char FUN_0005a210(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f35d11f7
namespace fight {
template <class T>
class ParamBool_5ca20 : public ParamBoolBase {
public:
    ParamBool_5ca20(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_5ca20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5ca20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5ca20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5ca20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f35d11f7 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f35d11f7
namespace fight {
template <class T>
class ParamNameConstList_5ca20 : public ParamNameConstListBase {
public:
    ParamNameConstList_5ca20(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_5ca20 : public ParamVectorBase {
public:
    ParamVector_5ca20(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f35d11f7 {
class CGrappleSwapTrack_5cd20 {
public:
    char FUN_0005a220(int); /* (unb4) as defined; address taken only */
    void FUN_00012ae0();
    void FUN_00012af0();
    char FUN_0005a230(char); /* (unb4) as defined; address taken only */
    bool FUN_0005a240(void*); /* (unb4) as defined; address taken only */
    char FUN_0005a260(float); /* (unb4) as defined; address taken only */
    bool FUN_0005a280(int); /* (unb4) as defined; address taken only */
    bool FUN_0005a290(int); /* (unb4) as defined; address taken only */
    bool FUN_0005a2a0(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CGrabTrack_5cf20 {
public:
    char FUN_0005a360(int); /* (unb4) as defined; address taken only */
    char FUN_0005a370(int); /* (unb4) as defined; address taken only */
    void FUN_0005a380();
    bool FUN_0005a390(void*); /* (unb4) as defined; address taken only */
    char FUN_0005a3b0(int); /* (unb4) as defined; address taken only */
    char FUN_0005a3c0(int); /* (unb4) as defined; address taken only */
    char FUN_0005a3d0(int); /* (unb4) as defined; address taken only */
    void FUN_00012bd0();
    void FUN_00012be0();
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
struct T_5d130 {
    char pad[0x10];
    int value;
    char FUN_0005d130(int a) {
        value = a;
        return 1;
    }
};
struct M_5d150 {
    int val;
};
class X_5d150 {
  public:
    char Set(int v);
    char pad[0x18];
    M_5d150 m;
};


} // namespace fn_f35d11f7

// 0x0005bfa0 fight::ParamFloatConstRange<CGrappleLocoStrafe4Track>::vfunc_0 (30 B): matches/0x0005bfa0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005bfc0 fight::ParamIntConstRange<CGrappleLocoStrafe4Track>::vfunc_0 (30 B): matches/0x0005bfc0.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005bfe0 fight::ParamFloatConstRange<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005bfe0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c000 fight::ParamBool<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c000.cpp
// sym: ??_G?$ParamBool@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c020 fight::ParamVector<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c020.cpp
// sym: ??_G?$ParamVector@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c040 fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c040.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c060 fight::ParamFloatConstRange<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c060.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c080 fight::ParamBool<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c080.cpp
// sym: ??_G?$ParamBool@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c0a0 fight::ParamVector<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c0a0.cpp
// sym: ??_G?$ParamVector@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c0c0 fight::ParamIntConstRange<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c0c0.cpp
// sym: ??_G?$ParamIntConstRange@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c1e0 fight::ParamFloatConstRange<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c1e0.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrabTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c200 fight::ParamVector<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c200.cpp
// sym: ??_G?$ParamVector@VCGrabTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c220 fight::ParamIntConstRange<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c220.cpp
// sym: ??_G?$ParamIntConstRange@VCGrabTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c240 fight::ParamBool<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c240.cpp
// sym: ??_G?$ParamBool@VCGrabTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c260 fight::ParamBranch<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c260.cpp
// sym: ??_G?$ParamBranch@VCGrabTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c630 fight::ParamName<CGrappleLocoStrafe4Track>::vfunc_0 (30 B): matches/0x0005c630.cpp
// sym: ??_G?$ParamName@VCGrappleLocoStrafe4Track@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c650 fight::ParamNameConstList<CGrappleAttachTrack>::vfunc_0 (30 B): matches/0x0005c650.cpp
// sym: ??_G?$ParamNameConstList@VCGrappleAttachTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c670 fight::ParamNameConstList<CGrappleSwapTrack>::vfunc_0 (30 B): matches/0x0005c670.cpp
// sym: ??_G?$ParamNameConstList@VCGrappleSwapTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c690 fight::ParamNameConstList<CGrabTrack>::vfunc_0 (30 B): matches/0x0005c690.cpp
// sym: ??_G?$ParamNameConstList@VCGrabTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CGrappleOpportunityTrack.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_0005c6b0 / FUN_0005ca20 / FUN_0005cd20 / FUN_0005cf20)



// 0x0005c6b0 FUN_0005c6b0 (868 B): matches/0x0005c6b0.cpp
// sym: _FUN_0005c6b0
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CGrappleLocoStrafe4Track>, ParamIntConstRange<CGrappleLocoStrafe4Track>, ParamName<CGrappleLocoStrafe4Track>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005c6b0()
{
    if ((*(int*)&DAT_004dc594) == 0) {
        ::fight::ParamValue* params[16];
        params[0] = new ::fight::ParamFloatConstRange< ::CGrappleLocoStrafe4Track>("timeBegin", &owners::O_5a0d0::FUN_0005a0d0);
        params[1] = new ::fight::ParamFloatConstRange< ::CGrappleLocoStrafe4Track>("timeEnd", &owners::Obj_5a0e0::FUN_0005a0e0);
        params[2] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("locomotion", &owners::Obj_12900::FUN_00012900);
        params[3] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animIdle", &owners::Obj_12910::FUN_00012910);
        params[4] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animWalkNorth", &owners::X_12920::FUN_00012920);
        params[5] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animWalkEast", &owners::X_12930::FUN_00012930);
        params[6] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animWalkSouth", &owners::Obj_12940::FUN_00012940);
        params[7] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animWalkWest", &owners::C_12950::FUN_00012950);
        params[8] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animRunNorth", &fn_ff0a839e::Obj_12960::Get);
        params[9] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animRunEast", &fn_ff0a839e::FUN_00012970);
        params[10] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animRunSouth", &fn_ff0a839e::O_12980::Get);
        params[11] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("animRunWest", &fn_ff0a839e::FUN_00012990);
        params[12] = new ::fight::ParamName< ::CGrappleLocoStrafe4Track>("partition", &owners::Obj_129a0::FUN_000129a0);
        params[13] = new ::fight::ParamIntConstRange< ::CGrappleLocoStrafe4Track>("priority", &owners::Obj_5a0f0::FUN_0005a0f0);
        params[14] = new ::fight::ParamFloatConstRange< ::CGrappleLocoStrafe4Track>("blendInTime", &owners::Obj_5a100::FUN_0005a100);
        params[15] = new ::fight::ParamFloatConstRange< ::CGrappleLocoStrafe4Track>("blendOutTime", &owners::Obj_5a110::FUN_0005a110);
        FUN_002347b0(&DAT_004dc590, params, 16);
    }
    (*(int*)&DAT_004dc594)++;
}



// 0x0005ca20 FUN_0005ca20 (766 B): matches/0x0005ca20.cpp
// sym: _FUN_0005ca20
// (gx2, D18) rewritten; constructs the real ParamBool<CGrappleAttachTrack>, ParamFloatConstRange<CGrappleAttachTrack>, ParamIntConstRange<CGrappleAttachTrack>, ParamNameConstList<CGrappleAttachTrack>, ParamVector<CGrappleAttachTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005ca20()
{
    if (DAT_004dc59c == 0) {
        ::fight::ParamValue* params[14];
        params[0] = new ::fight::ParamFloatConstRange< ::CGrappleAttachTrack>("timeBegin", &owners::C_5a120::FUN_0005a120);
        params[1] = new ::fight::ParamNameConstList< ::CGrappleAttachTrack>("joint", &owners::A_129e0::FUN_000129e0);
        params[2] = new ::fight::ParamNameConstList< ::CGrappleAttachTrack>("channel", &owners::Obj_129f0::FUN_000129f0);
        params[3] = new ::fight::ParamBool< ::CGrappleAttachTrack>("useOffset", &owners::Obj_5a130::FUN_0005a130);
        params[4] = new ::fight::ParamVector< ::CGrappleAttachTrack>("offsetPosition", &fn_f8b0a0f7::O_5a140::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::CGrappleAttachTrack>("offsetOrientation", &owners::Obj_5a160::FUN_0005a160);
        params[6] = new ::fight::ParamVector< ::CGrappleAttachTrack>("offsetAngle", &fn_f8b0a0f7::Obj::FUN_0005a180);
        params[7] = new ::fight::ParamNameConstList< ::CGrappleAttachTrack>("orientJoint", &owners::Obj_12a60::FUN_00012a60);
        params[8] = new ::fight::ParamVector< ::CGrappleAttachTrack>("orientJointOffset", &fn_f8b0a0f7::Obj_5a1b0::Set);
        params[9] = new ::fight::ParamFloatConstRange< ::CGrappleAttachTrack>("orientJointMinDistance", &owners::Obj_5a1d0::FUN_0005a1d0);
        params[10] = new ::fight::ParamFloatConstRange< ::CGrappleAttachTrack>("orientJointMaxDistance", &owners::Obj_5a1e0::FUN_0005a1e0);
        params[11] = new ::fight::ParamBool< ::CGrappleAttachTrack>("attachToGrapplee", &owners::Obj_5a1f0::FUN_0005a1f0);
        params[12] = new ::fight::ParamIntConstRange< ::CGrappleAttachTrack>("rootPriority", &owners::Obj_5a200::FUN_0005a200);
        params[13] = new ::fight::ParamFloatConstRange< ::CGrappleAttachTrack>("rootBlendInTime", &owners::Obj_5a210::FUN_0005a210);
        FUN_002347b0(&DAT_004dc598, params, 14);
    }
    DAT_004dc59c++;
}



// 0x0005cd20 FUN_0005cd20 (511 B): matches/0x0005cd20.cpp
// sym: _FUN_0005cd20
// (gx2, D18) rewritten; constructs the real ParamBool<CGrappleSwapTrack>, ParamFloatConstRange<CGrappleSwapTrack>, ParamIntConstRange<CGrappleSwapTrack>, ParamNameConstList<CGrappleSwapTrack>, ParamVector<CGrappleSwapTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005cd20()
{
    if (DAT_004dc5a4 == 0) {
        ::fight::ParamValue* params[9];
        params[0] = new ::fight::ParamFloatConstRange< ::CGrappleSwapTrack>("timeBegin", &owners::C_5a220::FUN_0005a220);
        params[1] = new ::fight::ParamNameConstList< ::CGrappleSwapTrack>("joint", &owners::Obj_12ae0::FUN_00012ae0);
        params[2] = new ::fight::ParamNameConstList< ::CGrappleSwapTrack>("channel", &fn_ff0a839e::FUN_00012af0);
        params[3] = new ::fight::ParamBool< ::CGrappleSwapTrack>("useOffset", &owners::O_5a230::FUN_0005a230);
        params[4] = new ::fight::ParamVector< ::CGrappleSwapTrack>("offsetPosition", &fn_f8b0a0f7::C_5a240::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::CGrappleSwapTrack>("offsetOrientation", &owners::Thing_5a260::FUN_0005a260);
        params[6] = new ::fight::ParamIntConstRange< ::CGrappleSwapTrack>("rootPriority", &owners::Obj_5a280::FUN_0005a280);
        params[7] = new ::fight::ParamFloatConstRange< ::CGrappleSwapTrack>("rootBlendInTime", &owners::Obj_5a290::FUN_0005a290);
        params[8] = new ::fight::ParamFloatConstRange< ::CGrappleSwapTrack>("rootBlendOutTime", &owners::Obj_5a2a0::FUN_0005a2a0);
        FUN_002347b0(&DAT_004dc5a0, params, 9);
    }
    DAT_004dc5a4++;
}



// 0x0005cf20 FUN_0005cf20 (511 B): matches/0x0005cf20.cpp
// sym: _FUN_0005cf20
// (gx2, D18) rewritten; constructs the real ParamBool<CGrabTrack>, ParamBranch<CGrabTrack>, ParamFloatConstRange<CGrabTrack>, ParamIntConstRange<CGrabTrack>, ParamNameConstList<CGrabTrack>, ParamVector<CGrabTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_0005cf20()
{
    if (DAT_004dc5c4 == 0) {
        ::fight::ParamValue* params[9];
        params[0] = new ::fight::ParamFloatConstRange< ::CGrabTrack>("timeBegin", &owners::Obj_5a360::FUN_0005a360);
        params[1] = new ::fight::ParamFloatConstRange< ::CGrabTrack>("timeEnd", &owners::Obj_5a370::FUN_0005a370);
        params[2] = new ::fight::ParamNameConstList< ::CGrabTrack>("joint", &owners::Obj_5a380::FUN_0005a380);
        params[3] = new ::fight::ParamVector< ::CGrabTrack>("offset", &fn_f8b0a0f7::O_5a390::Set);
        params[4] = new ::fight::ParamFloatConstRange< ::CGrabTrack>("radius", &owners::O_5a3b0::FUN_0005a3b0);
        params[5] = new ::fight::ParamIntConstRange< ::CGrabTrack>("interruptPriority", &owners::Obj_5a3c0::FUN_0005a3c0);
        params[6] = new ::fight::ParamBool< ::CGrabTrack>("missileCatch", &owners::Obj_5a3d0::FUN_0005a3d0);
        params[7] = new ::fight::ParamBranch< ::CGrabTrack>("receiver", &owners::O_12bd0::FUN_00012bd0);
        params[8] = new ::fight::ParamBranch< ::CGrabTrack>("giver", &fn_ff0a839e::FUN_00012be0);
        FUN_002347b0(&DAT_004dc5c0, params, 9);
    }
    DAT_004dc5c4++;
}



// 0x0005d120 FUN_0005d120 (12 B): matches/0x0005d120.cpp
// sym: ?FUN_0005d120@Obj_5d120@owners@@QAE_NH@Z
bool owners::Obj_5d120::FUN_0005d120(int x) {
    mVal = x;
    return true;
}

namespace fn_f35d11f7 {

// 0x0005d130 FUN_0005d130 (12 B): matches/0x0005d130.cpp
// sym: ?FUN_0005d130@T_5d130@fn_f35d11f7@@QAEDH@Z
int main() {
    T_5d130 t;
    return t.FUN_0005d130(0);
}

} // namespace fn_f35d11f7

// 0x0005d140 FUN_0005d140 (12 B): matches/0x0005d140.cpp
// sym: ?FUN_0005d140@Obj_5d140@owners@@QAEDH@Z
char owners::Obj_5d140::FUN_0005d140(int value) {
    m14 = value;
    return 1;
}

namespace fn_f35d11f7 {

// 0x0005d150 FUN_0005d150 (12 B): matches/0x0005d150.cpp
// sym: ?Set@X_5d150@fn_f35d11f7@@QAEDH@Z
char X_5d150::Set(int v) {
    m.val = v;
    return 1;
}

} // namespace fn_f35d11f7

// 0x0005d160 FUN_0005d160 (12 B): matches/0x0005d160.cpp
// sym: ?FUN_0005d160@Obj_5d160@owners@@QAEEE@Z
unsigned char owners::Obj_5d160::FUN_0005d160(unsigned char v) {
    b = v;
    return 1;
}

namespace fn_f35d11f7 {

// 0x0005d170 FUN_0005d170 (19 B): matches/0x0005d170.cpp
// sym: ?FUN_0005d170@fn_f35d11f7@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0005d170(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc5c8), ((char*)&DAT_004dc5cc));
}

} // namespace fn_f35d11f7
