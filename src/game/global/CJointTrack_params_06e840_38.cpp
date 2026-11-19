// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006e840..0x00075ce0 (kind game, layer game, confidence high), merged by D32: global/CJointTrack_params_06e840.cpp
// piece 0x00072590..0x00075ce0 (kind game, layer game, confidence high, dominant class CAlertStatusTrack); was game/global/CAlertStatusTrack_3.cpp until D46
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/unknown.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4b6f30b {
#define TREE_TU_END }
namespace fn_f4b6f30b {} using namespace fn_f4b6f30b;
namespace fn_f4b6f30b {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/global.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
extern "C" bool __stdcall FUN_00068eb0(hulk_intptr x);   // (gx4, D18) a setter, as defined in CScrubberTrack.cpp
namespace fn_f51b6026 { struct Vec; } 
namespace fn_fa3ff49b { struct Entry_67f60; } 
namespace fn_fa3ff49b { struct In; } 
namespace fn_fa3ff49b { struct S_68a30; } 
namespace fn_fa3ff49b { struct Src_68650; } 
namespace fn_fa3ff49b { struct Sub_68b60; } 
namespace fn_fa3ff49b { struct Vec3_689f0; } 
namespace fn_f88b40b1 { int __cdecl FUN_00068e70(void *); }   // (gx3, D18) a setter, as defined in CScrubberTrack.cpp
namespace fn_fa3ff49b { bool __fastcall FUN_00068a30(struct fn_fa3ff49b::S_68a30 *, void *, float); }   // (gx3, D18) a setter, as defined in CWeaponCollisionTrack.cpp
namespace fn_f51b6026 { struct Obj { unsigned char Set(struct fn_f51b6026::Vec const *); }; }   // (gx3, D18) setters, as defined in CJointTrack.cpp
namespace fn_fa3ff49b { struct C_68b90 { bool SetTimeBegin_00068b90(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_67f60 { bool Set(struct fn_fa3ff49b::Entry_67f60 *); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_67f90 { bool Set(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68650 { char Set(struct fn_fa3ff49b::Src_68650 *); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_689f0 { bool Set(struct fn_fa3ff49b::Vec3_689f0 const *); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68a10 { bool Set(struct fn_fa3ff49b::In *); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68b40 { bool SetTimeBegin_00068b40(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68b50 { bool SetTimeEnd_00068b50(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68b60 { struct fn_fa3ff49b::Sub_68b60 * GetHint_00068b60(); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68ba0 { bool SetTimeEnd_00068ba0(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp
namespace fn_fa3ff49b { struct Obj_68bb0 { bool SetHeight_00068bb0(int); }; }   // (gx3, D18) setters, as defined in CWeaponCollisionTrack.cpp

// ---- declarations shared by the functions below
namespace fn_f4b6f30b {
extern "C" char DAT_003fcbf4[];   // (fix2) the game's caster vftable
class TrackFactoryCasterTemplate_72c40 {   // (fix2) was polymorphic (virtual int cast_0006d690(void*);): clang's vftable natively
  public:
    void *vftable;
    TrackFactoryCasterTemplate_72c40() { vftable = DAT_003fcbf4; }
};
} // namespace fn_f4b6f30b
struct CDamageTrack;
namespace fn_f4b6f30b {
extern void __cdecl Find_00236ac0(CDamageTrack*, TrackFactoryCasterTemplate_72c40*);
extern "C" char DAT_003fcd5c[];
typedef unsigned int u32_73000;
} // namespace fn_f4b6f30b
struct CHitAnimationTrack {};
namespace fn_f4b6f30b {
struct TrackFactoryCasterTemplate {
    void* vftable;
};
extern void FUN_00236ac0(u32_73000, void**);
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_f4b6f30b
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f4b6f30b {
bool SetTimeBegin_00068b40(void*, int); /* (unb5) as defined; address taken only */
bool SetTimeEnd_00068b50(void*, int); /* (unb5) as defined; address taken only */
void* GetHint_00068b60(void*); /* (unb5) as defined; address taken only */
struct ParamBase_75b50 {
 virtual void slot0();
 char reserved[12];
 void (__cdecl *callback)();
 int tail;
};
class CAIHintTrack_75b50;
} // namespace fn_f4b6f30b
namespace fight {
template<class T> struct ParamFloatConstRange_75b50 : ParamBase_75b50 { virtual void slot0(); };
}
namespace fight {
template<class T> struct ParamName_75b50 : ParamBase_75b50 { virtual void slot0(); };
}
namespace fn_f4b6f30b {
} // namespace fn_f4b6f30b
void* __cdecl operator new(size_t size);
namespace fn_f4b6f30b {
class TrackFactoryTemplate_75c30 {
  public:
    TrackFactoryTemplate_75c30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00072590();
extern "C" char DAT_003fc10c[];
struct Obj_75c70 {
    int pad0[5];
    void Init_00236d40();
};
extern int hulk_at_003fe540;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006ad60();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f4b6f30b

namespace fn_f4b6f30b {

} // namespace fn_f4b6f30b

// 0x0006e840 fight::ParamFloatConstRange<CJointTrack>::vfunc_0 (30 B): matches/0x0006e840.cpp
// sym: ??_G?$ParamFloatConstRange@VCJointTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJointTrack_params_06e840.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006e860 fight::ParamBool<CJointTrack>::vfunc_0 (30 B): matches/0x0006e860.cpp
// sym: ??_G?$ParamBool@VCJointTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJointTrack_params_06e840.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006e880 fight::ParamVector<CJointTrack>::vfunc_0 (30 B): matches/0x0006e880.cpp
// sym: ??_G?$ParamVector@VCJointTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJointTrack_params_06e840.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006e8a0 fight::ParamIntConstRange<CJointTrack>::vfunc_0 (30 B): matches/0x0006e8a0.cpp
// sym: ??_G?$ParamIntConstRange@VCJointTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJointTrack_params_06e840.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006e8c0 fight::ParamFloat<CScrubberTrack>::vfunc_0 (30 B): matches/0x0006e8c0.cpp
// sym: ??_G?$ParamFloat@VCScrubberTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CJumpTrack_params_06e8c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006e9c0 fight::ParamFloatConstRange<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x0006e9c0.cpp
// sym: ??_G?$ParamFloatConstRange@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CKeyPoseTrack_params_06e9c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006e9e0 fight::ParamBool<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x0006e9e0.cpp
// sym: ??_G?$ParamBool@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CKeyPoseTrack_params_06e9c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ea00 fight::ParamIntConstRange<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x0006ea00.cpp
// sym: ??_G?$ParamIntConstRange@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CKeyPoseTrack_params_06e9c0.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ece0 fight::ParamFloatConstRange<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ece0.cpp
// sym: ??_G?$ParamFloatConstRange@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ed00 fight::ParamVector<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ed00.cpp
// sym: ??_G?$ParamVector@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ed20 fight::ParamBool<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ed20.cpp
// sym: ??_G?$ParamBool@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ed40 fight::ParamEnumConstList<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x0006ed40.cpp
// sym: ??_G?$ParamEnumConstList@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CCameraDramaticTrack_params_06ec00.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ef40 fight::ParamFloatConstRange<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x0006ef40.cpp
// sym: ??_G?$ParamFloatConstRange@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ef60 fight::ParamVector<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x0006ef60.cpp
// sym: ??_G?$ParamVector@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006ef80 fight::ParamIntConstRange<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x0006ef80.cpp
// sym: ??_G?$ParamIntConstRange@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CHeadTrackerTrack_params_06ee60.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006efa0 fight::ParamFloatConstRange<CAlertStatusTrack>::vfunc_0 (30 B): matches/0x0006efa0.cpp
// sym: ??_G?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006efc0 fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_0 (30 B): matches/0x0006efc0.cpp
// sym: ??_G?$ParamEnumConstList@VCAlertStatusTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006efe0 fight::ParamFloatConstRange<CDeathTrack>::vfunc_0 (30 B): matches/0x0006efe0.cpp
// sym: ??_G?$ParamFloatConstRange@VCDeathTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006f000 fight::ParamFloatConstRange<CAIHintTrack>::vfunc_0 (30 B): matches/0x0006f000.cpp
// sym: ??_G?$ParamFloatConstRange@VCAIHintTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006f020 fight::ParamFloatConstRange<CClearCollisionStun>::vfunc_0 (30 B): matches/0x0006f020.cpp
// sym: ??_G?$ParamFloatConstRange@VCClearCollisionStun@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006f040 fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::vfunc_0 (30 B): matches/0x0006f040.cpp
// sym: ??_G?$ParamFloatConstRange@VCMotionHitGroundHeightTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006f060 fight::ParamFloatConstRange<CWallSlideTrack>::vfunc_0 (30 B): matches/0x0006f060.cpp
// sym: ??_G?$ParamFloatConstRange@VCWallSlideTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006f080 fight::ParamIntConstRange<CWallSlideTrack>::vfunc_0 (30 B): matches/0x0006f080.cpp
// sym: ??_G?$ParamIntConstRange@VCWallSlideTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x0006f0a0 fight::ParamFloatConstRange<CTargetTrack>::vfunc_0 (30 B): matches/0x0006f0a0.cpp
// sym: ??_G?$ParamFloatConstRange@VCTargetTrack@@@fight@@UAEPAXI@Z
// (gx3, D32/D18) moved from CAlertStatusTrack_params.cpp: the implicit destructor of the class; its scalar deleting destructor is
// emitted beside the vftable by the registration that constructs it (FUN_00072590 / FUN_00072640 / FUN_000726a0 / FUN_00072740 / FUN_00072820 / FUN_00072a20 / FUN_00074ab0 / FUN_00074cf0 / FUN_00074d90 / FUN_00075230 / FUN_00075810 / FUN_00075b50)



// 0x00072590 FUN_00072590 (170 B): matches/0x00072590.cpp
// sym: _FUN_00072590
// (gx2, D18) from CAlertStatusTrack_3.iso_00072590.cpp; constructs the real ParamEnumConstList<CAlertStatusTrack>, ParamFloatConstRange<CAlertStatusTrack>,
// whose vftable and scalar deleting destructor it emits
namespace fn_f4b6f30b {
extern "C" void FUN_00072590()
{
    if (DAT_004dcffc == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CAlertStatusTrack>("timeBegin", &owners::Obj_68b10::FUN_00068b10);
        params[1] = new ::fight::ParamEnumConstList< ::CAlertStatusTrack>("status", (void*)&DAT_004a1ab4, DAT_0040d0e4, &owners::Obj_68b20::FUN_00068b20);
        FUN_002347b0(&DAT_004dcff8, params, 2);
    }
    DAT_004dcffc++;
}
} // namespace fn_f4b6f30b



// 0x00072640 FUN_00072640 (95 B): matches/0x00072640.cpp
// sym: _FUN_00072640
// (gx2, D18) from CAlertStatusTrack_3.iso_00072640.cpp; constructs the real ParamFloatConstRange<CDeathTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072640()
{
    if (DAT_004dd004 == 0) {
        ::fight::ParamValue* params[1];
        params[0] = new ::fight::ParamFloatConstRange< ::CDeathTrack>("timeBegin", &owners::Obj_68b30::FUN_00068b30);
        FUN_002347b0(&DAT_004dd000, params, 1);
    }
    DAT_004dd004++;
}



// 0x000726a0 FUN_000726a0 (158 B): matches/0x000726a0.cpp
// sym: _FUN_000726a0
// (gx2, D18) from CAlertStatusTrack_3.iso_000726a0.cpp; constructs the real ParamFloatConstRange<CClearCollisionStun>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_000726a0()
{
    if (DAT_004dd014 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CClearCollisionStun>("timeBegin", &owners::Obj_68b70::FUN_00068b70);
        params[1] = new ::fight::ParamFloatConstRange< ::CClearCollisionStun>("timeEnd", &owners::Obj_68b80::FUN_00068b80);
        FUN_002347b0(&DAT_004dd010, params, 2);
    }
    DAT_004dd014++;
}



// 0x00072740 FUN_00072740 (213 B): matches/0x00072740.cpp
// sym: _FUN_00072740
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CMotionHitGroundHeightTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072740()
{
    if (DAT_004dd01c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CMotionHitGroundHeightTrack>("timeBegin", &fn_fa3ff49b::C_68b90::SetTimeBegin_00068b90);
        params[1] = new ::fight::ParamFloatConstRange< ::CMotionHitGroundHeightTrack>("timeEnd", &fn_fa3ff49b::Obj_68ba0::SetTimeEnd_00068ba0);
        params[2] = new ::fight::ParamFloatConstRange< ::CMotionHitGroundHeightTrack>("height", &fn_fa3ff49b::Obj_68bb0::SetHeight_00068bb0);
        FUN_002347b0(&DAT_004dd018, params, 3);
    }
    DAT_004dd01c++;
}



// 0x00072820 FUN_00072820 (511 B): matches/0x00072820.cpp
// sym: _FUN_00072820
// (gx2, D18) from CAlertStatusTrack_3.new_throw.cpp; constructs the real ParamFloatConstRange<CWallSlideTrack>, ParamIntConstRange<CWallSlideTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072820()
{
    if (DAT_004dd024 == 0) {
        ::fight::ParamValue* params[9];
        params[0] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("timeBegin", &owners::X_68bc0::FUN_00068bc0);
        params[1] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("maxTimeEnd", &owners::A_68bd0::FUN_00068bd0);
        params[2] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("friction", &owners::C_68be0::FUN_00068be0);
        params[3] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("gravity", &owners::Obj_68bf0::FUN_00068bf0);
        params[4] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("deceleration", &owners::Obj_68c00::FUN_00068c00);
        params[5] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("minVelocity", &owners::Obj_68c10::FUN_00068c10);
        params[6] = new ::fight::ParamIntConstRange< ::CWallSlideTrack>("priority", &owners::Obj_68c20::FUN_00068c20);
        params[7] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("blendInTime", &owners::X_68c30::FUN_00068c30);
        params[8] = new ::fight::ParamFloatConstRange< ::CWallSlideTrack>("blendOutTime", &owners::Obj_68c40::FUN_00068c40);
        FUN_002347b0(&DAT_004dd020, params, 9);
    }
    DAT_004dd024++;
}



// 0x00072a20 FUN_00072a20 (158 B): matches/0x00072a20.cpp
// sym: _FUN_00072a20
// (gx2, D18) from CAlertStatusTrack_3.iso_00072a20.cpp; constructs the real ParamFloatConstRange<CTargetTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00072a20()
{
    if (DAT_004dd02c == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamFloatConstRange< ::CTargetTrack>("timeBegin", &owners::Obj_68c50::FUN_00068c50);
        params[1] = new ::fight::ParamFloatConstRange< ::CTargetTrack>("timeEnd", &owners::Obj_68c60::FUN_00068c60);
        FUN_002347b0(&DAT_004dd028, params, 2);
    }
    DAT_004dd02c++;
}

namespace fn_f4b6f30b {


// 0x00072c40 FUN_00072c40 (27 B): matches/0x00072c40.cpp
// sym: ?Target@fn_f4b6f30b@@YAXPAVCDamageTrack@@@Z
void __cdecl Target(CDamageTrack* track) {
    TrackFactoryCasterTemplate_72c40 c;
    Find_00236ac0(track, &c);
}


// 0x00073000 FUN_00073000 (27 B): matches/0x00073000.cpp
// sym: ?FUN_00073000@fn_f4b6f30b@@YAXI@Z
void FUN_00073000(u32_73000 key) {
    void* caster;
    caster = (void*)((hulk_intptr)DAT_003fcd5c);
    FUN_00236ac0(key, &caster);
}


// 0x00073540 fight::ParamNameConstList<CJointTrack>::vfunc_7 (12 B): matches/0x00073540.cpp
// sym: ?vfunc_6@ParamBranch@fn_f4b6f30b@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f4b6f30b

// 0x00073570 fight::ParamName<CScrubberTrack>::vfunc_7 (12 B): matches/0x00073570.cpp [wrapped: same definition as 0x00073540 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00073570@@UAEXPAX@Z
namespace fn_00073570 {
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00073570


// 0x000735a0 fight::ParamName<CKeyPoseTrack>::vfunc_7 (12 B): matches/0x000735a0.cpp [wrapped: same definition as 0x00073540 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000735a0@@UAEXPAX@Z
namespace fn_000735a0 {
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_000735a0


// 0x000735d0 fight::ParamName<CCameraDramaticTrack>::vfunc_7 (12 B): matches/0x000735d0.cpp [wrapped: same definition as 0x00073540 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_000735d0@@UAEXPAX@Z
namespace fn_000735d0 {
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_000735d0


// 0x00073600 fight::ParamNameConstList<CHeadTrackerTrack>::vfunc_7 (12 B): matches/0x00073600.cpp [wrapped: same definition as 0x00073540 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00073600@@UAEXPAX@Z
namespace fn_00073600 {
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00073600


// 0x00073630 fight::ParamName<CAIHintTrack>::vfunc_7 (12 B): matches/0x00073630.cpp [wrapped: same definition as 0x00073540 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00073630@@UAEXPAX@Z
namespace fn_00073630 {
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
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00073630


// 0x00073640 fight::ParamNameConstList<CJointTrack>::vfunc_0 (30 B): matches/0x00073640.cpp
// sym: ??_G?$ParamNameConstList@VCJointTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00073660 fight::ParamName<CScrubberTrack>::vfunc_0 (30 B): matches/0x00073660.cpp
// sym: ??_G?$ParamName@VCScrubberTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00073680 fight::ParamName<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x00073680.cpp
// sym: ??_G?$ParamName@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x000736a0 fight::ParamName<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x000736a0.cpp
// sym: ??_G?$ParamName@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x000736c0 fight::ParamNameConstList<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x000736c0.cpp
// sym: ??_G?$ParamNameConstList@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x000736e0 fight::ParamName<CAIHintTrack>::vfunc_0 (30 B): matches/0x000736e0.cpp
// sym: ??_G?$ParamName@VCAIHintTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00073700 FUN_00073700 (4234 B): matches/0x00073700.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_00073700
namespace fn_00073700 {
// FUN_00073700 @ 0x00073700
// FUN_00073700 @ 0x00073700  (generated by tools/equiv_gen/call_table.py)
class CAIHintTrack; class CAlertStatusTrack; class CAutoTargetTrack; class CCameraDramaticTrack; class CCameraHintTrack; class CCameraShakeTrack; class CClearHitRecordsTrack; class CClearCollisionStun; class CClimbingTrack; class CCollisionTrack; class CComboMessageTrack; class CComboTimerTrack; class CDamageTrack; class CDeathTrack; class CDrainHealthTrack; class CDriftTrack; class CDropTrack; class CEffectTrack; class CEffectStopTrack; class CExplosionTrack; class CGrabTrack; class CGrappleAttachTrack; class CGrappleAutoTargetTrack; class CGrappleDamageTrack; class CGrappleDetachTrack; class CGrappleDrainHealthTrack; class CGrappleEffectTrack; class CGrappleEffectStopTrack; class CGrappleIntangibleTrack; class CGrappleInvincibleTrack; class CGrappleInvulnerableTrack; class CGrappleKeyPoseTrack; class CGrappleLocoStrafe4Track; class CGrappleMotionTrailTrack; class CGrappleOpportunityTrack; class CGrappleSequenceTrack; class CGrappleSoundTrack; class CGrappleSmartPropDropTrack; class CGrappleSwapTrack; class CGrappleUninterruptibleTrack; class CHeadTrackerTrack; class CHeliDeathSpiralTrack; class CHitAnimationTrack; class CIntangibleTrack; class CIntangibleToActorsTrack; class CInvincibleTrack; class CInvulnerableTrack; class CJointTrack; class CJumpTrack; class CJumpAttackTrack; class CKeyPoseTrack; class CMotionHitGroundHeightTrack; class CMotionTrailTrack; class CMoveTrack; class CMoveAddTrack; class CMoveAddYTrack; class COpportunityBallTrack; class COrientTrack; class COrientTargetTrack; class CPropActorSetStateTrack; class CPushBackAnimationTrack; class CRageModeTrack; class CHapticTrack; class CScrubberTrack; class CSmartPropAttachTrack; class CSmartPropDetachTrack; class CSmartPropDropTrack; class CSmartPropEventTrack; class CSmartPropRemoveInstanceTrack; class CSmartPropSetStateTrack; class CSmartPropSpawnTrack; class CSmartPropThrowTrack; class CSmartPropThrowingTrack; class CSmartPropUpdateAttachmentTrack; class CSnapToWallTrack; class CSoundTrack; class CStageTrack; class CStunAnimationTrack; class CSweepTrack; class CTargetTrack; class CUninterruptibleTrack; class CWallSlideTrack; class CWeaponCollisionTrack;
namespace fight { extern "C" char DAT_003fcb64[], DAT_003fcb70[], DAT_003fcb7c[], DAT_003fcb88[], DAT_003fcb94[], DAT_003fcba0[], DAT_003fcbac[], DAT_003fcbb8[], DAT_003fcbc4[], DAT_003fcbd0[], DAT_003fcbdc[], DAT_003fcbe8[], DAT_003fcbf4[], DAT_003fcc00[], DAT_003fcc0c[], DAT_003fcc18[], DAT_003fcc24[], DAT_003fcc30[], DAT_003fcc3c[], DAT_003fcc48[], DAT_003fcc54[], DAT_003fcc60[], DAT_003fcc6c[], DAT_003fcc78[], DAT_003fcc84[], DAT_003fcc90[], DAT_003fcc9c[], DAT_003fcca8[], DAT_003fccb4[], DAT_003fccc0[], DAT_003fcccc[], DAT_003fccd8[], DAT_003fcce4[], DAT_003fccf0[], DAT_003fccfc[], DAT_003fcd08[], DAT_003fcd14[], DAT_003fcd20[], DAT_003fcd2c[], DAT_003fcd38[], DAT_003fcd44[], DAT_003fcd50[], DAT_003fcd5c[], DAT_003fcd68[], DAT_003fcd74[], DAT_003fcd80[], DAT_003fcd8c[], DAT_003fcd98[], DAT_003fcda4[], DAT_003fcdb0[], DAT_003fcdbc[], DAT_003fcdc8[], DAT_003fcdd4[], DAT_003fcde0[], DAT_003fcdec[], DAT_003fcdf8[], DAT_003fce04[], DAT_003fce10[], DAT_003fce1c[], DAT_003fce28[], DAT_003fce34[], DAT_003fce40[], DAT_003fce4c[], DAT_003fce58[], DAT_003fce64[], DAT_003fce70[], DAT_003fce7c[], DAT_003fce88[], DAT_003fce94[], DAT_003fcea0[], DAT_003fceac[], DAT_003fceb8[], DAT_003fcec4[], DAT_003fced0[], DAT_003fcedc[], DAT_003fcee8[], DAT_003fcef4[], DAT_003fcf00[], DAT_003fcf0c[], DAT_003fcf18[], DAT_003fcf24[], DAT_003fcf30[], DAT_003fcf3c[];   // (fix2) the game's caster vftables
template <class T> struct TrackFactoryCasterTemplate {   // (fix2) was polymorphic (virtual void create();): clang's own vftable natively,
  public:                          // the game's by address now, stored by each instantiation's constructor
    void *vftable;
    TrackFactoryCasterTemplate();
};
template <> inline TrackFactoryCasterTemplate<CAIHintTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcb64; }
template <> inline TrackFactoryCasterTemplate<CAlertStatusTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcb70; }
template <> inline TrackFactoryCasterTemplate<CAutoTargetTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcb7c; }
template <> inline TrackFactoryCasterTemplate<CCameraDramaticTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcb88; }
template <> inline TrackFactoryCasterTemplate<CCameraHintTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcb94; }
template <> inline TrackFactoryCasterTemplate<CCameraShakeTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcba0; }
template <> inline TrackFactoryCasterTemplate<CClearHitRecordsTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbac; }
template <> inline TrackFactoryCasterTemplate<CClearCollisionStun>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbb8; }
template <> inline TrackFactoryCasterTemplate<CClimbingTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbc4; }
template <> inline TrackFactoryCasterTemplate<CCollisionTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbd0; }
template <> inline TrackFactoryCasterTemplate<CComboMessageTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbdc; }
template <> inline TrackFactoryCasterTemplate<CComboTimerTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbe8; }
template <> inline TrackFactoryCasterTemplate<CDamageTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcbf4; }
template <> inline TrackFactoryCasterTemplate<CDeathTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc00; }
template <> inline TrackFactoryCasterTemplate<CDrainHealthTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc0c; }
template <> inline TrackFactoryCasterTemplate<CDriftTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc18; }
template <> inline TrackFactoryCasterTemplate<CDropTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc24; }
template <> inline TrackFactoryCasterTemplate<CEffectTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc30; }
template <> inline TrackFactoryCasterTemplate<CEffectStopTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc3c; }
template <> inline TrackFactoryCasterTemplate<CExplosionTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc48; }
template <> inline TrackFactoryCasterTemplate<CGrabTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc54; }
template <> inline TrackFactoryCasterTemplate<CGrappleAttachTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc60; }
template <> inline TrackFactoryCasterTemplate<CGrappleAutoTargetTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc6c; }
template <> inline TrackFactoryCasterTemplate<CGrappleDamageTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc78; }
template <> inline TrackFactoryCasterTemplate<CGrappleDetachTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc84; }
template <> inline TrackFactoryCasterTemplate<CGrappleDrainHealthTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc90; }
template <> inline TrackFactoryCasterTemplate<CGrappleEffectTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc9c; }
template <> inline TrackFactoryCasterTemplate<CGrappleEffectStopTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcca8; }
template <> inline TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fccb4; }
template <> inline TrackFactoryCasterTemplate<CGrappleInvincibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fccc0; }
template <> inline TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcccc; }
template <> inline TrackFactoryCasterTemplate<CGrappleKeyPoseTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fccd8; }
template <> inline TrackFactoryCasterTemplate<CGrappleLocoStrafe4Track>::TrackFactoryCasterTemplate() { vftable = DAT_003fcce4; }
template <> inline TrackFactoryCasterTemplate<CGrappleMotionTrailTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fccf0; }
template <> inline TrackFactoryCasterTemplate<CGrappleOpportunityTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fccfc; }
template <> inline TrackFactoryCasterTemplate<CGrappleSequenceTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd08; }
template <> inline TrackFactoryCasterTemplate<CGrappleSoundTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd14; }
template <> inline TrackFactoryCasterTemplate<CGrappleSmartPropDropTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd20; }
template <> inline TrackFactoryCasterTemplate<CGrappleSwapTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd2c; }
template <> inline TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd38; }
template <> inline TrackFactoryCasterTemplate<CHeadTrackerTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd44; }
template <> inline TrackFactoryCasterTemplate<CHeliDeathSpiralTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd50; }
template <> inline TrackFactoryCasterTemplate<CHitAnimationTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd5c; }
template <> inline TrackFactoryCasterTemplate<CIntangibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd68; }
template <> inline TrackFactoryCasterTemplate<CIntangibleToActorsTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd74; }
template <> inline TrackFactoryCasterTemplate<CInvincibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd80; }
template <> inline TrackFactoryCasterTemplate<CInvulnerableTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd8c; }
template <> inline TrackFactoryCasterTemplate<CJointTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd98; }
template <> inline TrackFactoryCasterTemplate<CJumpTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcda4; }
template <> inline TrackFactoryCasterTemplate<CJumpAttackTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcdb0; }
template <> inline TrackFactoryCasterTemplate<CKeyPoseTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcdbc; }
template <> inline TrackFactoryCasterTemplate<CMotionHitGroundHeightTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcdc8; }
template <> inline TrackFactoryCasterTemplate<CMotionTrailTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcdd4; }
template <> inline TrackFactoryCasterTemplate<CMoveTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcde0; }
template <> inline TrackFactoryCasterTemplate<CMoveAddTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcdec; }
template <> inline TrackFactoryCasterTemplate<CMoveAddYTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcdf8; }
template <> inline TrackFactoryCasterTemplate<COpportunityBallTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce04; }
template <> inline TrackFactoryCasterTemplate<COrientTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce10; }
template <> inline TrackFactoryCasterTemplate<COrientTargetTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce1c; }
template <> inline TrackFactoryCasterTemplate<CPropActorSetStateTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce28; }
template <> inline TrackFactoryCasterTemplate<CPushBackAnimationTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce34; }
template <> inline TrackFactoryCasterTemplate<CRageModeTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce40; }
template <> inline TrackFactoryCasterTemplate<CHapticTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce4c; }
template <> inline TrackFactoryCasterTemplate<CScrubberTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce58; }
template <> inline TrackFactoryCasterTemplate<CSmartPropAttachTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce64; }
template <> inline TrackFactoryCasterTemplate<CSmartPropDetachTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce70; }
template <> inline TrackFactoryCasterTemplate<CSmartPropDropTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce7c; }
template <> inline TrackFactoryCasterTemplate<CSmartPropEventTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce88; }
template <> inline TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce94; }
template <> inline TrackFactoryCasterTemplate<CSmartPropSetStateTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcea0; }
template <> inline TrackFactoryCasterTemplate<CSmartPropSpawnTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fceac; }
template <> inline TrackFactoryCasterTemplate<CSmartPropThrowTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fceb8; }
template <> inline TrackFactoryCasterTemplate<CSmartPropThrowingTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcec4; }
template <> inline TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fced0; }
template <> inline TrackFactoryCasterTemplate<CSnapToWallTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcedc; }
template <> inline TrackFactoryCasterTemplate<CSoundTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcee8; }
template <> inline TrackFactoryCasterTemplate<CStageTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcef4; }
template <> inline TrackFactoryCasterTemplate<CStunAnimationTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf00; }
template <> inline TrackFactoryCasterTemplate<CSweepTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf0c; }
template <> inline TrackFactoryCasterTemplate<CTargetTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf18; }
template <> inline TrackFactoryCasterTemplate<CUninterruptibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf24; }
template <> inline TrackFactoryCasterTemplate<CWallSlideTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf30; }
template <> inline TrackFactoryCasterTemplate<CWeaponCollisionTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf3c; } }
struct Registry_73700 { void FUN_002367c0(void*); void FUN_00236400(); };
void* __cdecl FUN_00236ac0(const char*, void*);
extern "C" void __cdecl FUN_002369c0(void *);
void __cdecl FUN_0012de00(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00132560(Registry_73700*, const char*);
void __cdecl FUN_00132530(Registry_73700*, const char*);
void __cdecl FUN_00132500(Registry_73700*, const char*);
void __cdecl FUN_001325c0(Registry_73700*, const char*);
void __cdecl FUN_001324d0(Registry_73700*, const char*);
void __cdecl FUN_00132590(Registry_73700*, const char*);
void __cdecl FUN_001325f0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0013c620(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0013d780(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0013cdd0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0013d040(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0013c930(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0013cb60(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019d130(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019c050(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019c720(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019c6f0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019c690(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019de20(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0019c6c0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017c620(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d1b0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00161d20(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d5e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d8a0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017cc00(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dd00(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017ca30(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d180(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dc70(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d610(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dd90(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017cbd0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158260(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158a40(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158a10(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158b90(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001586a0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001586d0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001582c0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158b00(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158bf0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158bc0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158aa0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158b60(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158290(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158a70(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158b30(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00158ad0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d1e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b960(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b510(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b5a0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b4e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b540(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b570(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b4b0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0014b990(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00162280(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001633c0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00163020(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00163760(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00161d50(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00162820(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00189f30(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018a070(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018a0d0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b0b0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b080(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018ab70(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00189f60(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b110(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018a0a0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b0e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018a2e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b2e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018a310(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b050(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018b020(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018aba0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0018a840(Registry_73700*, const char*);
void __cdecl FUN_0018e8d0(Registry_73700*);
extern "C" void __cdecl FUN_00191b10(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00191ae0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00191910(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017ca00(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dd60(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d670(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017ddc0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d580(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d5b0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dca0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dc40(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d640(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dc10(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00139330(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00139270(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00139360(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001393c0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00139240(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001392a0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00139390(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001392d0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00139300(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017d870(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dd30(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017cea0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0017dcd0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001424e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001428e0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_001428b0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00146400(Registry_73700*);
extern "C" void __cdecl FUN_00113cf0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00113bd0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00113d20(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00129f80(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00129fb0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_0012d110(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00113ba0(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00113c30(Registry_73700*, const char*);
extern "C" void __cdecl FUN_00129f50(Registry_73700*, const char*);
void __cdecl FUN_001a1d20(Registry_73700*, const char*);
extern "C" bool __cdecl FUN_00073700(Registry_73700* r) {
    FUN_002369c0((Registry_73700 *)r);
    FUN_0012de00(r, "postEvent_string");
    FUN_00132560(r, "debugPrint");
    FUN_00132530(r, "dialogue");
    FUN_00132500(r, "nisSound");
    FUN_001325c0(r, "stat");
    FUN_001324d0(r, "statBeginTrial");
    FUN_00132590(r, "statEndTrial");
    FUN_001325f0(r, "xp");
    FUN_0013c620(r, "animation");
    FUN_0013d780(r, "grappleAnimation");
    FUN_0013cdd0(r, "animationPhaseMatched");
    FUN_0013d040(r, "animationVelocityScaled");
    FUN_0013c930(r, "animationCharge");
    FUN_0013cb60(r, "animationLinked");
    FUN_0019d130(r, "fireMissile");
    FUN_0019c050(r, "fireProjectile");
    FUN_0019c720(r, "fireBeam");
    FUN_0019c6f0(r, "accuracyLatency");
    FUN_0019c690(r, "missileThrow");
    FUN_0019de20(r, "fireGroundShockwave");
    FUN_0019c6c0(r, "missilePunch");
    FUN_0017c620(r, "jointTracker");
    FUN_0017d1b0(r, "locomotionState");
    FUN_00161d20(r, "locomoting");
    FUN_0017d5e0(r, "motionState");
    FUN_0017d8a0(r, "jointPivotTracker");
    FUN_0017cc00(r, "jointRelative");
    FUN_0017dd00(r, "intentionClear");
    FUN_0017ca30(r, "restPose");
    FUN_0017d180(r, "suck");
    FUN_0017dc70(r, "criticalMassDrain");
    FUN_0017d610(r, "momentumXZAdd");
    FUN_0017dd90(r, "visibility");
    FUN_0017cbd0(r, "snapToGround");
    FUN_00158260(r, "interruptAccumulatorSet");
    FUN_00158a40(r, "interruptPriority");
    FUN_00158a10(r, "hitWait");
    FUN_00158b90(r, "groundSlide");
    FUN_001586a0(r, "hitPause");
    FUN_001586d0(r, "hitReaction");
    FUN_001582c0(r, "hitReactionFloat");
    FUN_00158b00(r, "hitPushbackAdd");
    FUN_00158bf0(r, "noHitPushback");
    FUN_00158bc0(r, "hitPushback");
    FUN_00158aa0(r, "hitFloat");
    FUN_00158b60(r, "hitDamage");
    FUN_00158290(r, "hitThrow");
    FUN_00158a70(r, "hitOrientToPushback");
    FUN_00158b30(r, "health");
    FUN_00158ad0(r, "clearFightParamsHitRecord");
    FUN_0017d1e0(r, "moveJoint");
    FUN_0014b960(r, "grappleExecute");
    FUN_0014b510(r, "grappleStruggle");
    FUN_0014b5a0(r, "grappleHitReaction");
    FUN_0014b4e0(r, "grappleThrow");
    FUN_0014b540(r, "civilianThrow");
    FUN_0014b570(r, "civilianAttach");
    FUN_0014b4b0(r, "civilianDetach");
    FUN_0014b990(r, "civilianAnimation");
    FUN_00162280(r, "locoStrafe4");
    FUN_001633c0(r, "locoSprint");
    FUN_00163020(r, "locoSteer");
    FUN_00163760(r, "grappleLocoSteer");
    FUN_00161d50(r, "climbLocomotion4");
    FUN_00162820(r, "heliLocomotion");
    FUN_00189f30(r, "propActorToProp");
    FUN_0018a070(r, "propActorThinking");
    FUN_0018a0d0(r, "propAnimation");
    FUN_0018b0b0(r, "propAddToMissileCount");
    FUN_0018b080(r, "propAddToCollision");
    FUN_0018ab70(r, "propSetStateByIndex");
    FUN_00189f60(r, "propSetStateByName");
    FUN_0018b110(r, "propSpawn");
    FUN_0018a0a0(r, "propDrop");
    FUN_0018b0e0(r, "propDamage");
    FUN_0018a2e0(r, "grapplePropDamage");
    FUN_0018b2e0(r, "propDestroy");
    FUN_0018a310(r, "propThrow");
    FUN_0018b050(r, "shieldArc");
    FUN_0018b020(r, "ballAndChainSpin");
    FUN_0018aba0(r, "ballAndChainShoot");
    FUN_0018a840(r, "ballAndChainReturn");
    FUN_0018e8d0(r);
    FUN_00191b10(r, "tankLocomotion");
    FUN_00191ae0(r, "simulation");
    FUN_00191910(r, "impulseVelocity");
    FUN_0017ca00(r, "charge");
    FUN_0017dd60(r, "chargeClear");
    FUN_0017d670(r, "pushOut");
    FUN_0017ddc0(r, "footPivot");
    FUN_0017d580(r, "driftToPosition");
    FUN_0017d5b0(r, "driftToHulk");
    FUN_0017dca0(r, "suckInProps");
    FUN_0017dc40(r, "targetIconDistance");
    FUN_0017d640(r, "targetBreak");
    FUN_0017dc10(r, "surf");
    FUN_00139330(r, "hover");
    FUN_00139270(r, "grappleHover");
    FUN_00139360(r, "fall");
    FUN_001393c0(r, "flyingAttack");
    FUN_00139240(r, "flyingDash");
    FUN_001392a0(r, "flyingBrake");
    FUN_00139390(r, "flyingAutoTarget");
    FUN_001392d0(r, "bounce");
    FUN_00139300(r, "airToGroundTarget");
    FUN_0017d870(r, "teleport");
    FUN_0017dd30(r, "teleportToLocator");
    FUN_0017cea0(r, "syncToLocator");
    FUN_0017dcd0(r, "teleportRelative");
    FUN_001424e0(r, "wallRun");
    FUN_001428e0(r, "wallExit");
    FUN_001428b0(r, "wallJump");
    FUN_00146400(r);
    FUN_00113cf0(r, "token");
    FUN_00113bd0(r, "tokenSupress");
    FUN_00113d20(r, "semaphoreWait");
    FUN_00129f80(r, "acquireTarget");
    FUN_00129fb0(r, "clearProjectileDistance");
    FUN_0012d110(r, "threatBall");
    FUN_00113ba0(r, "semaphoreClear");
    FUN_00113c30(r, "hulk_action");
    FUN_00129f50(r, "targetClear");
    FUN_001a1d20(r, "lua");
    {
        fight::TrackFactoryCasterTemplate<CAIHintTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("aiHint", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CAlertStatusTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("alertStatus", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CAutoTargetTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("autoTarget", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CCameraDramaticTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("cameraDramatic", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CCameraHintTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("cameraHint", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CCameraShakeTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("cameraShake", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("clearHitRecords", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CClearCollisionStun> caster;
        r->FUN_002367c0(FUN_00236ac0("clearStunTime", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CClimbingTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("climbing", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CCollisionTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("collision", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CComboMessageTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("comboMessage", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CComboTimerTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("comboTimer", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CDamageTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("damage", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CDeathTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("death", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CDrainHealthTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("drainHealth", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CDriftTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("drift", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CDropTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("drop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CEffectTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("effect", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CEffectStopTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("effectStop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CExplosionTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("explosion", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrabTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grab", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleAttachTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleAttach", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleAutoTargetTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleAutoTarget", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleDamageTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleDamage", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleDetachTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleDetach", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleDrainHealthTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleDrainHealth", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleEffectTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleEffect", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleEffectStopTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleEffectStop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleIntangible", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleInvincibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleInvincible", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleInvulnerable", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleKeyPoseTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleKeyPose", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleLocoStrafe4Track> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleLocoStrafe4", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleMotionTrailTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleMotionTrail", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleOpportunityTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleOpportunity", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleSequence", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleSoundTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleSound", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleSmartPropDropTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleSmartPropDrop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleSwapTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleSwap", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("grappleUninterruptible", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CHeadTrackerTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("headTracker", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CHeliDeathSpiralTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("heliDeathSpiral", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CHitAnimationTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("hitAnimation", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CIntangibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("intangible", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CIntangibleToActorsTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("intangibleToActors", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CInvincibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("invincible", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CInvulnerableTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("invulnerable", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CJointTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("joint", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CJumpTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("jump", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CJumpAttackTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("jumpAttack", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CKeyPoseTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("keyPose", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CMotionHitGroundHeightTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("motionHitGroundHeight", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CMotionTrailTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("motionTrail", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CMoveTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("move", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CMoveAddTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("moveAdd", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CMoveAddYTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("moveYAdd", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<COpportunityBallTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("opportunityBall", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<COrientTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("orient", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<COrientTargetTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("orientTarget", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CPropActorSetStateTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("propActorSetState", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CPushBackAnimationTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("pushBackAnimation", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CRageModeTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("rageMode", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CHapticTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("rumble", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CScrubberTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("scrubber", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropAttachTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropAttach", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropDetachTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropDetach", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropDropTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropDrop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropEventTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropEvent", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropRemoveInstance", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropSetStateTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropSetState", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropSpawnTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropSpawn", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropThrowTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropThrow", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropThrowingTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropThrowing", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("smartPropUpdateAttachment", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSnapToWallTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("snapToWall", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSoundTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("sound", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CStageTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("stage", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CStunAnimationTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("stunAnimation", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CSweepTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("sweep", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CTargetTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("target", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CUninterruptibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("uninterruptible", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CWallSlideTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("wallSlide", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CWeaponCollisionTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("weaponCollision", &caster));
    }
    r->FUN_00236400();
    return true;
}
} // namespace fn_00073700


// 0x00074790 FUN_00074790 (587 B): matches/0x00074790.cpp [wrapped: macros]
// sym: _FUN_00074790
namespace fn_00074790 {
struct Registry {
    void FUN_002367c0(void*);
    void FUN_00236400();
};
class CAlertStatusTrack;
class CEffectTrack;
class CEffectStopTrack;
class CIntangibleTrack;
class CUninterruptibleTrack;
namespace fight {
extern "C" char DAT_003fcd68[], DAT_003fcb70[], DAT_003fcc30[], DAT_003fcc3c[], DAT_003fcf24[];   // (fix2) the game's caster vftables
template <class T> struct TrackFactoryCasterTemplate {   // (fix2) was polymorphic (virtual void cast();): clang's own vftable natively,
  public:                          // the game's by address now, stored by each instantiation's constructor
    void *vftable;
    TrackFactoryCasterTemplate();
};
template <> inline TrackFactoryCasterTemplate<CIntangibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcd68; }
template <> inline TrackFactoryCasterTemplate<CAlertStatusTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcb70; }
template <> inline TrackFactoryCasterTemplate<CEffectTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc30; }
template <> inline TrackFactoryCasterTemplate<CEffectStopTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcc3c; }
template <> inline TrackFactoryCasterTemplate<CUninterruptibleTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fcf24; }
} // namespace fight
void* __cdecl FUN_00236ac0(const char*, void*);
extern "C" void __cdecl FUN_002369c0(void *);
#define DECL(a) void __cdecl FUN_##a(Registry*, const char*);
DECL(0012de00)
DECL(00132530) DECL(00132500) DECL(00132560) DECL(001325c0) DECL(001324d0) DECL(00132590) DECL(001325f0)
    DECL(00129f80) DECL(00129fb0) DECL(00113c90) DECL(00122c00) DECL(00122c90) DECL(00122c60) DECL(00122c30)
        DECL(00122cc0) DECL(00122ba0) DECL(00122bd0) DECL(0012d2e0) DECL(00113cc0) DECL(00113c30)
            DECL(00113d20) DECL(00113ba0) DECL(00113c60) DECL(00113cf0) DECL(00113bd0) DECL(0017dd30)
                DECL(0017dcd0) DECL(0017d580) DECL(0018a0a0) DECL(0017d1b0) DECL(00158b30)
                    DECL(001a1d20) void __cdecl FUN_0011ae60(Registry*);
extern "C" void __cdecl FUN_0010bf20(Registry*);
void __cdecl FUN_0018e8d0(Registry*);
extern "C" bool __cdecl FUN_00074790(Registry* r) {
    FUN_002369c0((Registry *)r);
    FUN_0012de00(r, "postEvent_string");
    FUN_00132530(r, "dialogue");
    FUN_00132500(r, "nisSound");
    FUN_00132560(r, "debugPrint");
    FUN_001325c0(r, "stat");
    FUN_001324d0(r, "statBeginTrial");
    FUN_00132590(r, "statEndTrial");
    FUN_001325f0(r, "xp");
    FUN_00129f80(r, "acquireTarget");
    FUN_00129fb0(r, "clearProjectileDistance");
    FUN_00113c90(r, "button");
    FUN_00122c00(r, "strafeRun");
    FUN_00122c90(r, "strafeCircle");
    FUN_00122c60(r, "strafeCircleHB");
    FUN_00122c30(r, "strafeLateralHB");
    FUN_00122cc0(r, "path");
    FUN_00122ba0(r, "rout");
    FUN_00122bd0(r, "pathFormation");
    FUN_0012d2e0(r, "threatDodge");
    FUN_0011ae60(r);
    FUN_0010bf20(r);
    FUN_00113cc0(r, "ai_history_set");
    FUN_00113c30(r, "hulk_action");
    FUN_00113d20(r, "semaphoreWait");
    FUN_00113ba0(r, "semaphoreClear");
    FUN_00113c60(r, "keywordWait");
    FUN_00113cf0(r, "token");
    FUN_00113bd0(r, "tokenSupress");
    FUN_0018e8d0(r);
    FUN_0017dd30(r, "teleportToLocator");
    FUN_0017dcd0(r, "teleportRelative");
    FUN_0017d580(r, "driftToPosition");
    FUN_0018a0a0(r, "propDrop");
    FUN_0017d1b0(r, "locomotionState");
    FUN_00158b30(r, "health");
    {
        fight::TrackFactoryCasterTemplate<CIntangibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("intangible", &caster));
    }
    FUN_001a1d20(r, "lua");
    {
        fight::TrackFactoryCasterTemplate<CAlertStatusTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("alertStatus", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CEffectTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("effect", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CEffectStopTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("effectStop", &caster));
    }
    {
        fight::TrackFactoryCasterTemplate<CUninterruptibleTrack> caster;
        r->FUN_002367c0(FUN_00236ac0("uninterruptible", &caster));
    }
    r->FUN_00236400();
    return true;
}
} // namespace fn_00074790
#undef DECL


// 0x000749e0 FUN_000749e0 (193 B): matches/0x000749e0.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_000749e0
namespace fn_000749e0 {
namespace fight {
extern "C" char DAT_003fce4c[];   // (fix2) the game's caster vftables
template <class T> struct TrackFactoryCasterTemplate {   // (fix2) was polymorphic (virtual void cast();): clang's own vftable natively,
  public:                          // the game's by address now, stored by each instantiation's constructor
    void *vftable;
    TrackFactoryCasterTemplate();
};
} // namespace fight
class CHapticTrack;
template <> inline fight::TrackFactoryCasterTemplate<CHapticTrack>::TrackFactoryCasterTemplate() { vftable = DAT_003fce4c; }
struct Registry_749e0 {
    void FUN_002367c0(void*);
    void FUN_00236400();
};
extern "C" void __cdecl FUN_002369c0(void *);
extern void __cdecl FUN_0012de00(Registry_749e0*, const char*);
extern void __cdecl FUN_00132530(Registry_749e0*, const char*);
extern void __cdecl FUN_00132500(Registry_749e0*, const char*);
extern void __cdecl FUN_001325c0(Registry_749e0*, const char*);
extern void __cdecl FUN_001324d0(Registry_749e0*, const char*);
extern void __cdecl FUN_00132590(Registry_749e0*, const char*);
extern void __cdecl FUN_001325f0(Registry_749e0*, const char*);
extern void __cdecl FUN_001a1d20(Registry_749e0*, const char*);
extern "C" void __cdecl FUN_001a9a90(Registry_749e0*, const char*);
extern "C" void __cdecl FUN_001a97d0(Registry_749e0*, const char*);
extern "C" void __cdecl FUN_00146130(Registry_749e0*, const char*);
extern "C" void __cdecl FUN_001463a0(Registry_749e0*, const char*);
extern void* __cdecl FUN_00236ac0(const char*, fight::TrackFactoryCasterTemplate<CHapticTrack>*);
extern "C" bool __cdecl FUN_000749e0(Registry_749e0* registry) {
    FUN_002369c0((Registry_749e0 *)registry);
    FUN_0012de00(registry, "postEvent_string");
    FUN_00132530(registry, "dialogue");
    FUN_00132500(registry, "nisSound");
    FUN_001325c0(registry, "stat");
    FUN_001324d0(registry, "statBeginTrial");
    FUN_00132590(registry, "statEndTrial");
    FUN_001325f0(registry, "xp");
    FUN_001a1d20(registry, "lua");
    FUN_001a9a90(registry, "nisAnimation");
    FUN_001a97d0(registry, "effect");
    FUN_00146130(registry, "effectSlowMotion");
    FUN_001463a0(registry, "effectMotionBlur");
    fight::TrackFactoryCasterTemplate<CHapticTrack> caster;
    registry->FUN_002367c0(FUN_00236ac0("rumble", &caster));
    registry->FUN_00236400();
    return true;
}
} // namespace fn_000749e0

namespace fn_f4b6f30b {

} // namespace fn_f4b6f30b

// 0x00074ab0 FUN_00074ab0 (562 B): matches/0x00074ab0.cpp
// sym: _FUN_00074ab0
// (gx2, D18) from CAlertStatusTrack_3.new_throw.cpp; constructs the real ParamBool<CJointTrack>, ParamFloatConstRange<CJointTrack>, ParamIntConstRange<CJointTrack>, ParamNameConstList<CJointTrack>, ParamVector<CJointTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00074ab0()
{
    if (DAT_004dcf0c == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamFloatConstRange< ::CJointTrack>("timeBegin", &owners::Obj_67f30::FUN_00067f30);
        params[1] = new ::fight::ParamFloatConstRange< ::CJointTrack>("timeEnd", &owners::Obj_67f40::FUN_00067f40);
        params[2] = new ::fight::ParamNameConstList< ::CJointTrack>("joint", &owners::A_11ce0::FUN_00011ce0);
        params[3] = new ::fight::ParamBool< ::CJointTrack>("hasTranslation", &owners::X_67f50::FUN_00067f50);
        params[4] = new ::fight::ParamVector< ::CJointTrack>("translation", &fn_fa3ff49b::Obj_67f60::Set);
        params[5] = new ::fight::ParamBool< ::CJointTrack>("hasRotation", &owners::Obj_67f80::FUN_00067f80);
        params[6] = new ::fight::ParamVector< ::CJointTrack>("rotation", &fn_f51b6026::Obj::Set);
        params[7] = new ::fight::ParamIntConstRange< ::CJointTrack>("priority", &fn_fa3ff49b::Obj_67f90::Set);
        params[8] = new ::fight::ParamFloatConstRange< ::CJointTrack>("blendInTime", &owners::Obj_67fa0::FUN_00067fa0);
        params[9] = new ::fight::ParamFloatConstRange< ::CJointTrack>("blendOutTime", &owners::Obj_67fb0::FUN_00067fb0);
        FUN_002347b0(&DAT_004dcf08, params, 10);
    }
    DAT_004dcf0c++;
}



// 0x00074cf0 FUN_00074cf0 (158 B): matches/0x00074cf0.cpp
// sym: _FUN_00074cf0
// (gx2, D18) from CAlertStatusTrack_3.iso_00074cf0.cpp; constructs the real ParamFloat<CScrubberTrack>, ParamName<CScrubberTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00074cf0()
{
    if (DAT_004dcf14 == 0) {
        ::fight::ParamValue* params[2];
        params[0] = new ::fight::ParamName< ::CScrubberTrack>("animation", &fn_f88b40b1::FUN_00068e70);
        params[1] = new ::fight::ParamFloat< ::CScrubberTrack>("frame", &FUN_00068eb0);
        FUN_002347b0(&DAT_004dcf10, params, 2);
    }
    DAT_004dcf14++;
}



// 0x00074d90 FUN_00074d90 (1174 B): matches/0x00074d90.cpp
// sym: _FUN_00074d90
// (gx2, D18) from CAlertStatusTrack_3.iso_00074d90.cpp; constructs the real ParamBool<CKeyPoseTrack>, ParamFloatConstRange<CKeyPoseTrack>, ParamIntConstRange<CKeyPoseTrack>, ParamName<CKeyPoseTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00074d90()
{
    if (DAT_004dcf34 == 0) {
        ::fight::ParamValue* params[22];
        params[0] = new ::fight::ParamName< ::CKeyPoseTrack>("animation", &owners::Obj_11e20::FUN_00011e20);
        params[1] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key0", &owners::Obj_6b310::FUN_0006b310);
        params[2] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map0", &owners::X_6b320::FUN_0006b320);
        params[3] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key1", &owners::X_6b330::FUN_0006b330);
        params[4] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map1", &owners::Obj_6b340::FUN_0006b340);
        params[5] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key2", &owners::Obj_6b350::FUN_0006b350);
        params[6] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map2", &owners::Obj_6b360::FUN_0006b360);
        params[7] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key3", &owners::Obj_6b370::FUN_0006b370);
        params[8] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map3", &owners::Obj_6b380::FUN_0006b380);
        params[9] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key4", &owners::C_6b390::FUN_0006b390);
        params[10] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map4", &owners::Obj_6b3a0::FUN_0006b3a0);
        params[11] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key5", &owners::Obj_6b3b0::FUN_0006b3b0);
        params[12] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map5", &owners::Obj_6b3c0::FUN_0006b3c0);
        params[13] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key6", &owners::Obj_6b3d0::FUN_0006b3d0);
        params[14] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map6", &owners::Obj_6b3e0::FUN_0006b3e0);
        params[15] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("key7", &owners::A_6b3f0::FUN_0006b3f0);
        params[16] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("map7", &owners::X_6b400::FUN_0006b400);
        params[17] = new ::fight::ParamBool< ::CKeyPoseTrack>("rootMotion", &owners::O_68210::FUN_00068210);
        params[18] = new ::fight::ParamName< ::CKeyPoseTrack>("partition", &owners::Obj_11e40::FUN_00011e40);
        params[19] = new ::fight::ParamIntConstRange< ::CKeyPoseTrack>("priority", &owners::Obj_68220::FUN_00068220);
        params[20] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("blendInTime", &owners::Obj_68230::FUN_00068230);
        params[21] = new ::fight::ParamFloatConstRange< ::CKeyPoseTrack>("blendOutTime", &owners::Obj_68240::FUN_00068240);
        FUN_002347b0(&DAT_004dcf30, params, 22);
    }
    DAT_004dcf34++;
}



// 0x00075230 FUN_00075230 (1502 B): matches/0x00075230.cpp
// sym: _FUN_00075230
// (gx2, D18) from CAlertStatusTrack_3.iso_00075230.cpp; constructs the real ParamBool<CCameraDramaticTrack>, ParamEnumConstList<CCameraDramaticTrack>, ParamFloatConstRange<CCameraDramaticTrack>, ParamName<CCameraDramaticTrack>, ParamVector<CCameraDramaticTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00075230()
{
    if (DAT_004dcfac == 0) {
        ::fight::ParamValue* params[27];
        params[0] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("timeBegin", &owners::Obj_68630::FUN_00068630);
        params[1] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("timeEnd", &owners::Obj_68640::FUN_00068640);
        params[2] = new ::fight::ParamVector< ::CCameraDramaticTrack>("targetOffset", &fn_fa3ff49b::Obj_68650::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("noCamWeight", &owners::A_686f0::FUN_000686f0);
        params[4] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation0", &owners::O_12080::FUN_00012080);
        params[5] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight0", &owners::Obj_68670::FUN_00068670);
        params[6] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation1", &owners::Obj_120a0::FUN_000120a0);
        params[7] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight1", &owners::C_68680::FUN_00068680);
        params[8] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation2", &owners::Obj_120c0::FUN_000120c0);
        params[9] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight2", &owners::Obj_68690::FUN_00068690);
        params[10] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation3", &owners::Obj_120e0::FUN_000120e0);
        params[11] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight3", &owners::Obj_686a0::FUN_000686a0);
        params[12] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation4", &owners::C_12100::FUN_00012100);
        params[13] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight4", &owners::Obj_686b0::FUN_000686b0);
        params[14] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation5", &owners::Obj_12120::FUN_00012120);
        params[15] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight5", &owners::Obj_686c0::FUN_000686c0);
        params[16] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation6", &owners::Obj_12140::FUN_00012140);
        params[17] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight6", &owners::Obj_686d0::FUN_000686d0);
        params[18] = new ::fight::ParamName< ::CCameraDramaticTrack>("animation7", &owners::T_12160::FUN_00012160);
        params[19] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("weight7", &owners::Obj_686e0::FUN_000686e0);
        params[20] = new ::fight::ParamBool< ::CCameraDramaticTrack>("abortWhenInterrupted", &owners::O_68700::FUN_00068700);
        params[21] = new ::fight::ParamEnumConstList< ::CCameraDramaticTrack>("blendInTransition", (void*)&DAT_00496f9c, 2, &owners::Target_68710::FUN_00068710);
        params[22] = new ::fight::ParamEnumConstList< ::CCameraDramaticTrack>("blendInBlend", (void*)&DAT_00496fa4, 4, &owners::Obj_68720::FUN_00068720);
        params[23] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("blendInDuration", &owners::Obj_68730::FUN_00068730);
        params[24] = new ::fight::ParamEnumConstList< ::CCameraDramaticTrack>("blendOutTransition", (void*)&DAT_00496f9c, 2, &owners::Obj_68740::FUN_00068740);
        params[25] = new ::fight::ParamEnumConstList< ::CCameraDramaticTrack>("blendOutBlend", (void*)&DAT_00496fa4, 4, &owners::Obj_68750::FUN_00068750);
        params[26] = new ::fight::ParamFloatConstRange< ::CCameraDramaticTrack>("blendOutDuration", &owners::Target_68760::FUN_00068760);
        FUN_002347b0(&DAT_004dcfa8, params, 27);
    }
    DAT_004dcfac++;
}



// 0x00075810 FUN_00075810 (817 B): matches/0x00075810.cpp
// sym: _FUN_00075810
// (gx2, D18) from CAlertStatusTrack_3.iso_00075810.cpp; constructs the real ParamFloatConstRange<CHeadTrackerTrack>, ParamIntConstRange<CHeadTrackerTrack>, ParamNameConstList<CHeadTrackerTrack>, ParamVector<CHeadTrackerTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00075810()
{
    if (DAT_004dcff4 == 0) {
        ::fight::ParamValue* params[15];
        params[0] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("timeBegin", &owners::Obj_689d0::FUN_000689d0);
        params[1] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("timeEnd", &owners::Obj_689e0::FUN_000689e0);
        params[2] = new ::fight::ParamNameConstList< ::CHeadTrackerTrack>("joint", &owners::T_12310::FUN_00012310);
        params[3] = new ::fight::ParamVector< ::CHeadTrackerTrack>("north", &fn_fa3ff49b::Obj_689f0::Set);
        params[4] = new ::fight::ParamVector< ::CHeadTrackerTrack>("east", &fn_fa3ff49b::Obj_68a10::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("turnRate", &fn_fa3ff49b::FUN_00068a30);
        params[6] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("verticalMinAngle", &owners::Obj_68a50::FUN_00068a50);
        params[7] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("verticalMaxAngle", &owners::C_68a70::FUN_00068a70);
        params[8] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("horizontalMinAngle", &owners::Obj_68a90::FUN_00068a90);
        params[9] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("horizontalMaxAngle", &owners::T_68ab0::FUN_00068ab0);
        params[10] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("arc", &owners::Thing_6ad10::FUN_0006ad10);
        params[11] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("distance", &owners::O_68ad0::FUN_00068ad0);
        params[12] = new ::fight::ParamIntConstRange< ::CHeadTrackerTrack>("priority", &owners::Obj_68ae0::FUN_00068ae0);
        params[13] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("blendInTime", &owners::Obj_68af0::FUN_00068af0);
        params[14] = new ::fight::ParamFloatConstRange< ::CHeadTrackerTrack>("blendOutTime", &owners::Obj_68b00::FUN_00068b00);
        FUN_002347b0(&DAT_004dcff0, params, 15);
    }
    DAT_004dcff4++;
}



// 0x00075b50 FUN_00075b50 (213 B): matches/0x00075b50.cpp
// sym: _FUN_00075b50
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<CAIHintTrack>, ParamName<CAIHintTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00075b50()
{
    if (DAT_004dd00c == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::CAIHintTrack>("timeBegin", &fn_fa3ff49b::Obj_68b40::SetTimeBegin_00068b40);
        params[1] = new ::fight::ParamFloatConstRange< ::CAIHintTrack>("timeEnd", &fn_fa3ff49b::Obj_68b50::SetTimeEnd_00068b50);
        params[2] = new ::fight::ParamName< ::CAIHintTrack>("hint", &fn_fa3ff49b::Obj_68b60::GetHint_00068b60);
        FUN_002347b0(&DAT_004dd008, params, 3);
    }
    DAT_004dd00c++;
}



// 0x00075c30 fight::TrackFactoryCasterTemplate<CAlertStatusTrack>::vfunc_1 (60 B): matches/0x00075c30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCAlertStatusTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CAlertStatusTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_75c30));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_75c30* t = new (mem) TrackFactoryTemplate_75c30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00072590();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00075c70 fight::TrackFactoryTemplate<CAlertStatusTrack>::vfunc_5 (59 B): matches/0x00075c70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCAlertStatusTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CAlertStatusTrack>::vfunc_5() {
    Obj_75c70* p = (Obj_75c70*)FUN_0008d690((int)sizeof(Obj_75c70));
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003fc10c);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f4b6f30b {

// 0x00075cb0 fight::TrackFactoryTemplate<CAlertStatusTrack>::vfunc_2 (43 B): matches/0x00075cb0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f4b6f30b@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe540;
    base1_dtor_0006ad60();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f4b6f30b
