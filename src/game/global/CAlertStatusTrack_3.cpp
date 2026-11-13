// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00072590..0x00075ce0 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"
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

// ---- declarations shared by the functions below
namespace fn_f4b6f30b {
class TrackFactoryCasterTemplate_72c40 {
  public:
    virtual int cast_0006d690(void*);
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
void __cdecl FUN_002347b0(int*, ParamBase_75b50**, int);
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

// 0x00072740 FUN_00072740 (213 B): equivalent/0x00072740.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: _FUN_00072740 @ffbc7270478e @w2313c9cd17c4
namespace fn_00072740 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00072740 @ 0x00072740


extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern bool SetTimeBegin_00068b90(void*, int); /* (unb5) as defined; address taken only */
extern bool SetTimeEnd_00068ba0(void*, int); /* (unb5) as defined; address taken only */
extern bool SetHeight_00068bb0(void*, int); /* (unb5) as defined; address taken only */
class CMotionHitGroundHeightTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<CMotionHitGroundHeightTrack> Param;
extern void __cdecl FUN_002347b0(int*, Param**, int);
extern "C" void FUN_00072740() {
 if (!DAT_004dd01c) {
 Param* params[3];
 Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
 if (p) { p->FUN_00234960("timeBegin"); new(p) Param; p->callback=(void (*)())SetTimeBegin_00068b90; } params[0]=p;
 p = (Param*)FUN_0008d690((int)sizeof(Param));
 if (p) { p->FUN_00234960("timeEnd"); new(p) Param; p->callback=(void (*)())SetTimeEnd_00068ba0; } params[1]=p;
 p = (Param*)FUN_0008d690((int)sizeof(Param));
 if (p) { p->FUN_00234960("height"); new(p) Param; p->callback=(void (*)())SetHeight_00068bb0; } params[2]=p;
 FUN_002347b0(&DAT_004dd018, params, 3);
 }
 ++DAT_004dd01c;
}
} // namespace fn_00072740

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
template <> fight::ParamNameConstList<CJointTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CJointTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x73640)
#endif


// 0x00073660 fight::ParamName<CScrubberTrack>::vfunc_0 (30 B): matches/0x00073660.cpp
// sym: ??_G?$ParamName@VCScrubberTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CScrubberTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CScrubberTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x73660)
#endif


// 0x00073680 fight::ParamName<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x00073680.cpp
// sym: ??_G?$ParamName@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CKeyPoseTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CKeyPoseTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x73680)
#endif


// 0x000736a0 fight::ParamName<CCameraDramaticTrack>::vfunc_0 (30 B): matches/0x000736a0.cpp
// sym: ??_G?$ParamName@VCCameraDramaticTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CCameraDramaticTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CCameraDramaticTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x736a0)
#endif


// 0x000736c0 fight::ParamNameConstList<CHeadTrackerTrack>::vfunc_0 (30 B): matches/0x000736c0.cpp
// sym: ??_G?$ParamNameConstList@VCHeadTrackerTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<CHeadTrackerTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<CHeadTrackerTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x736c0)
#endif


// 0x000736e0 fight::ParamName<CAIHintTrack>::vfunc_0 (30 B): matches/0x000736e0.cpp
// sym: ??_G?$ParamName@VCAIHintTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<CAIHintTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<CAIHintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x736e0)
#endif


// 0x00073700 FUN_00073700 (4234 B): matches/0x00073700.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_00073700
namespace fn_00073700 {
// FUN_00073700 @ 0x00073700
// FUN_00073700 @ 0x00073700  (generated by tools/equiv_gen/call_table.py)
class CAIHintTrack; class CAlertStatusTrack; class CAutoTargetTrack; class CCameraDramaticTrack; class CCameraHintTrack; class CCameraShakeTrack; class CClearHitRecordsTrack; class CClearCollisionStun; class CClimbingTrack; class CCollisionTrack; class CComboMessageTrack; class CComboTimerTrack; class CDamageTrack; class CDeathTrack; class CDrainHealthTrack; class CDriftTrack; class CDropTrack; class CEffectTrack; class CEffectStopTrack; class CExplosionTrack; class CGrabTrack; class CGrappleAttachTrack; class CGrappleAutoTargetTrack; class CGrappleDamageTrack; class CGrappleDetachTrack; class CGrappleDrainHealthTrack; class CGrappleEffectTrack; class CGrappleEffectStopTrack; class CGrappleIntangibleTrack; class CGrappleInvincibleTrack; class CGrappleInvulnerableTrack; class CGrappleKeyPoseTrack; class CGrappleLocoStrafe4Track; class CGrappleMotionTrailTrack; class CGrappleOpportunityTrack; class CGrappleSequenceTrack; class CGrappleSoundTrack; class CGrappleSmartPropDropTrack; class CGrappleSwapTrack; class CGrappleUninterruptibleTrack; class CHeadTrackerTrack; class CHeliDeathSpiralTrack; class CHitAnimationTrack; class CIntangibleTrack; class CIntangibleToActorsTrack; class CInvincibleTrack; class CInvulnerableTrack; class CJointTrack; class CJumpTrack; class CJumpAttackTrack; class CKeyPoseTrack; class CMotionHitGroundHeightTrack; class CMotionTrailTrack; class CMoveTrack; class CMoveAddTrack; class CMoveAddYTrack; class COpportunityBallTrack; class COrientTrack; class COrientTargetTrack; class CPropActorSetStateTrack; class CPushBackAnimationTrack; class CRageModeTrack; class CHapticTrack; class CScrubberTrack; class CSmartPropAttachTrack; class CSmartPropDetachTrack; class CSmartPropDropTrack; class CSmartPropEventTrack; class CSmartPropRemoveInstanceTrack; class CSmartPropSetStateTrack; class CSmartPropSpawnTrack; class CSmartPropThrowTrack; class CSmartPropThrowingTrack; class CSmartPropUpdateAttachmentTrack; class CSnapToWallTrack; class CSoundTrack; class CStageTrack; class CStunAnimationTrack; class CSweepTrack; class CTargetTrack; class CUninterruptibleTrack; class CWallSlideTrack; class CWeaponCollisionTrack;
namespace fight { template<class T> struct TrackFactoryCasterTemplate { virtual void create(); }; }
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
template <class T> struct TrackFactoryCasterTemplate {
    virtual void cast();
};
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
template <class T> struct TrackFactoryCasterTemplate {
    virtual void cast();
};
} // namespace fight
class CHapticTrack;
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

// 0x00075b50 FUN_00075b50 (213 B): equivalent/0x00075b50.cpp
// sym: _FUN_00075b50 @4864e2dc4984 @w7c46dc9191df
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00075b50 @ 0x00075b50
extern "C" void __cdecl FUN_00075b50() {
 if (DAT_004dd00c == 0) {
  ParamBase_75b50* params[3];
  ParamBase_75b50* p = (ParamBase_75b50*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_75b50<CAIHintTrack_75b50>));
  if(p) {
   ((fight::ParamValueFloat *)(ParamBase_75b50 *)p)->FUN_00234960("timeBegin");
   new(p) fight::ParamFloatConstRange_75b50<CAIHintTrack_75b50>;
   p->callback = (void (*)())SetTimeBegin_00068b40;
  }
  params[0]=p;
  p=(ParamBase_75b50*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_75b50<CAIHintTrack_75b50>));
  if(p) {
   ((fight::ParamValueFloat *)(ParamBase_75b50 *)p)->FUN_00234960("timeEnd");
   new(p) fight::ParamFloatConstRange_75b50<CAIHintTrack_75b50>;
   p->callback=(void (*)())SetTimeEnd_00068b50;
  }
  params[1]=p;
  p=(ParamBase_75b50*)FUN_0008d690((int)sizeof(fight::ParamName_75b50<CAIHintTrack_75b50>));
  if(p) {
   ((fight::ParamValueName *)(ParamBase_75b50 *)p)->FUN_00234a90("hint");
   new(p) fight::ParamName_75b50<CAIHintTrack_75b50>;
   p->callback=(void (*)())GetHint_00068b60;
  }
  params[2]=p;
  FUN_002347b0(&DAT_004dd008,params,3);
 }
 ++DAT_004dd00c;
}

} // namespace fn_f4b6f30b

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
