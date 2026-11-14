// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006d590..0x0006e840 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa9e1582 {
#define TREE_TU_END }
namespace fn_fa9e1582 {} using namespace fn_fa9e1582;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fa9e1582 {
extern char DAT_00498994;
extern "C" int __cdecl FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);
class TrackFactoryCaster_6d590 {
  public:
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};
class CClimbingTrack_6d590;
extern "C++" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00498a1c;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d5d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CCollisionTrack_6d5d0 {};
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d610 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CComboMessageTrack_6d610;
}
namespace fn_fa9e1582 {
extern char DAT_00498aa8;
extern void* g_vftable_6d640[];
class TrackFactoryCasterTemplate {
  public:
    virtual void A();
};
class TrackFactoryCasterTemplate_6d640 : public TrackFactoryCasterTemplate {
  public:
    virtual void A();
    TrackFactoryCasterTemplate_6d640();
};
extern char DAT_00498b38;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d650 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CDeathTrack_6d6d0;
extern char DAT_00498c38;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d6d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
struct A {};
extern char DAT_00498cc0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d710 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CDropTrack_6d790;
extern char DAT_00498dbc;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d790 {
  public:
    virtual int vfunc_0(CDropTrack_6d790*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_00498e3c;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d7d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CEffectTrack_6d7d0;
}
namespace fn_fa9e1582 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_0049850c;
class CExplosionTrack_6d850;
extern char DAT_00498f44;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d850 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_00498fc4;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d890 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CGrabTrack_6d890;
}
namespace fn_fa9e1582 {
extern char DAT_00499048;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d8d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CGrappleAttachTrack_6d8d0;
}
namespace fn_fa9e1582 {
extern int gTypeA_6d910;
extern char DAT_00499170;
class CGrappleDamageTrack_6d950;
class TrackFactoryCaster_6d950 {
  public:
    virtual bool vfunc_0(int owner);
    virtual bool vfunc_1(int owner);
};
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d990 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_00499200;
class CGrappleDrainHealthTrack_6d9d0;
extern char DAT_00499298;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6d9d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern int gTypeA_6da10;
extern char DAT_004993c0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6da50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CGrappleEffectStopTrack_6da50 {};
extern char DAT_00499458;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6da90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CGrappleIntangibleTrack_6da90 {};
class CGrappleInvincibleTrack_6dad0;
extern char DAT_004994f0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6dad0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_00499588;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6db10 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CGrappleInvulnerableTrack_6db10 {};
extern char DAT_00499620;
class TrackFactoryCaster_6db50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrappleKeyPoseTrack_6db50;
extern "C" char hulk_at_003fcce4[];
class TrackFactoryCasterTemplate_6db80 {
  public:
    virtual ~TrackFactoryCasterTemplate_6db80() {}
    virtual void Cast();
    TrackFactoryCasterTemplate_6db80();
};
extern char DAT_004996b8;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6db90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern int gTypeA_6dc10;
extern char DAT_00499880;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6dc50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CGrappleSequenceTrack_6dc50 {};
class CGrappleSoundTrack_6dc90;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6dc90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_00499910;
class CGrappleSmartPropDropTrack_6dcd0;
extern char DAT_004999a8;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6dcd0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern int gTypeA_6dd10;
class CGrappleUninterruptibleTrack_6dd50;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6dd50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_00499ad8;
class CHeadTrackerTrack_6dd90;
class TrackFactoryCaster_6dd90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int a, hulk_at_00499b70;
extern char DAT_00499c00;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6ddd0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern int gTypeA_6de10;
extern char DAT_00499d20;
struct CIntangibleTrack_6de50;
class TrackFactoryCaster_6de50 {
  public:
    virtual int vfunc_0(void*);
};
struct CIntangibleToActorsTrack_6de90;
extern char DAT_00499db0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6de90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CInvulnerableTrack_6df10;
extern char DAT_00499ec8;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6df10 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
}
namespace fn_fa9e1582 {
extern char DAT_00499f50;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6df50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CJointTrack_6df50 {};
extern char DAT_00499fcc;
class TrackFactoryCaster_6df90 {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};
extern char DAT_0049a050;
class CJumpAttackTrack_6dfd0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6dfd0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049a0d4;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e010 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049a1f8;
class CMoveTrack_6e0d0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e0d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049a278;
struct CMoveAddTrack_6e110;
extern char DAT_0049a2fc;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e110 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
struct Info {
    int x;
};
extern char DAT_0049a37c;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e150 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049a410;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e190 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
}
namespace fn_fa9e1582 {
class CPropActorSetStateTrack_6e250;
extern char DAT_0049a5b8;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e250 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049a650;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e290 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
}
namespace fight {
class CPushBackAnimationTrack_6e290 {};
}
namespace fight {
class TrackFactoryCaster_6e310 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CHapticTrack_6e310;
}
namespace fn_fa9e1582 {
extern char DAT_0049a764;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e350 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CScrubberTrack_6e350;
}
namespace fn_fa9e1582 {
extern char DAT_0049a7e4;
class CSmartPropAttachTrack_6e390;
extern char DAT_0049a878;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e390 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049a910;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e3d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CSmartPropDetachTrack_6e3d0;
}
namespace fn_fa9e1582 {
extern char DAT_0049aad8;
class CSmartPropRemoveInstanceTrack_6e490;
int FUN_00344e74(hulk_intptr, int, void*, void*, int);
class TrackFactoryCaster_6e490 {
  public:
    virtual bool vfunc_0(int);
};
extern char DAT_0049ab78;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e4d0 {
  public:
    virtual bool test(void*) = 0;
    virtual void other() = 0;
};
}
namespace fn_fa9e1582 {
extern char DAT_0049ac10;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e510 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CSmartPropSpawnTrack_6e510 {};
class CSmartPropThrowTrack_6e550 {};
class TrackFactoryCaster_6e550 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* g1;
extern void* hulk_at_0049aca8;
extern char DAT_0049ad40;
class CSmartPropThrowingTrack_6e590;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e590 {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049ade0;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e5d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049ae78;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e610 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CSnapToWallTrack_6e610 {};
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e650 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
class CSoundTrack_6e650 {};
extern char DAT_0049aef8;
struct TypeDescriptor {
    char bytes[8];
};
extern TypeDescriptor sourceType;
extern TypeDescriptor hulk_at_0049af78;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e690 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CStageTrack_6e690;
}
namespace fn_fa9e1582 {
class CStunAnimationTrack_6e6d0;
extern "C++" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_0049b000;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e6d0 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049b088;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e710 {
  public:
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049b198;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e790 {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
}
namespace fn_fa9e1582 {
class CWallSlideTrack_6e7d0;
extern char DAT_0049b224;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e7d0 {
  public:
    virtual bool vfunc_0(CWallSlideTrack_6e7d0*);
    virtual void vfunc_1();
};
}
namespace fn_fa9e1582 {
extern char DAT_0049b2b8;
} // namespace fn_fa9e1582
namespace fight {
class TrackFactoryCaster_6e810 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CWeaponCollisionTrack_6e810;
}


// 0x0006d590 fight::TrackFactoryCasterTemplate<CClimbingTrack>::vfunc_0 (36 B): matches/0x0006d590.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCClimbingTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CClimbingTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (bool)((int)(FUN_00344e74((void*)a, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_00498994, 0) != 0));
}


// 0x0006d5d0 fight::TrackFactoryCasterTemplate<CCollisionTrack>::vfunc_0 (36 B): matches/0x0006d5d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCCollisionTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CCollisionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498a1c, 0) != 0;
}


// 0x0006d600 FUN_0006d600 (9 B): matches/0x0006d600.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0TrackFactoryCasterTemplate@fn_0006d600@@QAE@XZ
namespace fn_0006d600 {
extern "C++" { extern char hulk_at_003fcbd8[]; }
class TrackFactoryCasterTemplate {
  public:
    void* vptr;
    void* mObj;
    TrackFactoryCasterTemplate();
    TrackFactoryCasterTemplate* Self();
};
TrackFactoryCasterTemplate::TrackFactoryCasterTemplate() {
    void* q = &vptr;
    *(char**)q = (char*)((hulk_intptr)(hulk_at_003fcbd8 + 0x4));
}
TrackFactoryCasterTemplate* TrackFactoryCasterTemplate::Self() {
    return this;
}
} // namespace fn_0006d600


// 0x0006d610 fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_0 (36 B): matches/0x0006d610.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCComboMessageTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498aa8, 0) != 0;
}

namespace fn_fa9e1582 {

// 0x0006d640 FUN_0006d640 (9 B): matches/0x0006d640.cpp
// sym: ??0TrackFactoryCasterTemplate_6d640@fn_fa9e1582@@QAE@XZ
TrackFactoryCasterTemplate_6d640::TrackFactoryCasterTemplate_6d640() {}

} // namespace fn_fa9e1582

// 0x0006d650 fight::TrackFactoryCasterTemplate<CComboTimerTrack>::vfunc_0 (36 B): matches/0x0006d650.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCComboTimerTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CComboTimerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498b38, 0) != 0;
}


// 0x0006d690 fight::TrackFactoryCasterTemplate<CDamageTrack>::vfunc_0 (36 B): matches/0x0006d690.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_0006d690@@UAEHPAX@Z
namespace fn_0006d690 {
class CDamageTrack;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
extern int a, hulk_at_00498bbc;
extern "C++" int __cdecl FUN_00344e74(void*, int, int*, int*, int);
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_00498bbc, 0) != 0;
}
} // namespace fn_0006d690


// 0x0006d6d0 fight::TrackFactoryCasterTemplate<CDeathTrack>::vfunc_0 (36 B): matches/0x0006d6d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCDeathTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CDeathTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498c38, 0) != 0;
}


// 0x0006d710 fight::TrackFactoryCasterTemplate<CDrainHealthTrack>::vfunc_0 (36 B): matches/0x0006d710.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCDrainHealthTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CDrainHealthTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498cc0, 0) != 0;
}


// 0x0006d750 fight::TrackFactoryCasterTemplate<CDriftTrack>::vfunc_0 (36 B): matches/0x0006d750.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_0006d750@@UAE_NPBD@Z
namespace fn_0006d750 {
class CDriftTrack;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int a, hulk_at_00498d40;
bool fight::TrackFactoryCasterTemplate::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &a, &hulk_at_00498d40, 0) != 0;
}
} // namespace fn_0006d750


// 0x0006d790 fight::TrackFactoryCasterTemplate<CDropTrack>::vfunc_0 (36 B): matches/0x0006d790.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCDropTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CDropTrack>::vfunc_0(void* __p0) { CDropTrack_6d790 * p = (CDropTrack_6d790 *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498dbc, 0) != 0;
}


// 0x0006d7d0 fight::TrackFactoryCasterTemplate<CEffectTrack>::vfunc_0 (36 B): matches/0x0006d7d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCEffectTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CEffectTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498e3c, 0) != 0;
}


// 0x0006d810 fight::TrackFactoryCasterTemplate<CEffectStopTrack>::vfunc_0 (36 B): matches/0x0006d810.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCEffectStopTrack@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<CEffectStopTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0006d850 fight::TrackFactoryCasterTemplate<CExplosionTrack>::vfunc_0 (36 B): matches/0x0006d850.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCExplosionTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CExplosionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498f44, 0) != 0;
}


// 0x0006d890 fight::TrackFactoryCasterTemplate<CGrabTrack>::vfunc_0 (36 B): matches/0x0006d890.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrabTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrabTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (void*)&DAT_0049850c, (void*)&DAT_00498fc4, 0) != 0;
}


// 0x0006d8d0 fight::TrackFactoryCasterTemplate<CGrappleAttachTrack>::vfunc_0 (36 B): matches/0x0006d8d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleAttachTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleAttachTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499048, 0) != 0;
}


// 0x0006d910 fight::TrackFactoryCasterTemplate<CGrappleAutoTargetTrack>::vfunc_0 (36 B): matches/0x0006d910.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleAutoTargetTrack@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<CGrappleAutoTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_6d910, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0006d950 fight::TrackFactoryCasterTemplate<CGrappleDamageTrack>::vfunc_0 (36 B): matches/0x0006d950.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleDamageTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleDamageTrack>::vfunc_0(void* __p0) { hulk_intptr owner = (hulk_intptr)__p0;

    return FUN_00344e74(owner, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_00499170, 0) != 0;
}


// 0x0006d990 fight::TrackFactoryCasterTemplate<CGrappleDetachTrack>::vfunc_0 (36 B): matches/0x0006d990.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleDetachTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleDetachTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499200, 0) != 0;
}


// 0x0006d9d0 fight::TrackFactoryCasterTemplate<CGrappleDrainHealthTrack>::vfunc_0 (36 B): matches/0x0006d9d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleDrainHealthTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleDrainHealthTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499298, 0) != 0;
}


// 0x0006da10 fight::TrackFactoryCasterTemplate<CGrappleEffectTrack>::vfunc_0 (36 B): matches/0x0006da10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleEffectTrack@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<CGrappleEffectTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_6da10, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0006da50 fight::TrackFactoryCasterTemplate<CGrappleEffectStopTrack>::vfunc_0 (36 B): matches/0x0006da50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleEffectStopTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleEffectStopTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004993c0, 0) != 0;
}


// 0x0006da90 fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::vfunc_0 (36 B): matches/0x0006da90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleIntangibleTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499458, 0) != 0;
}


// 0x0006dad0 fight::TrackFactoryCasterTemplate<CGrappleInvincibleTrack>::vfunc_0 (36 B): matches/0x0006dad0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleInvincibleTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleInvincibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004994f0, 0) != 0;
}


// 0x0006db10 fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::vfunc_0 (36 B): matches/0x0006db10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleInvulnerableTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleInvulnerableTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499588, 0) != 0;
}


// 0x0006db50 fight::TrackFactoryCasterTemplate<CGrappleKeyPoseTrack>::vfunc_0 (36 B): matches/0x0006db50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleKeyPoseTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleKeyPoseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499620, 0) != 0;
}

namespace fn_fa9e1582 {

// 0x0006db80 FUN_0006db80 (9 B): matches/0x0006db80.cpp
// sym: ??0TrackFactoryCasterTemplate_6db80@fn_fa9e1582@@QAE@XZ
TrackFactoryCasterTemplate_6db80::TrackFactoryCasterTemplate_6db80() {
    *(hulk_intptr*)this = (hulk_intptr)hulk_at_003fcce4;
}

} // namespace fn_fa9e1582

// 0x0006db90 fight::TrackFactoryCasterTemplate<CGrappleLocoStrafe4Track>::vfunc_0 (36 B): matches/0x0006db90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleLocoStrafe4Track@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleLocoStrafe4Track>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004996b8, 0) != 0;
}


// 0x0006dbd0 fight::TrackFactoryCasterTemplate<CGrappleMotionTrailTrack>::vfunc_0 (36 B): matches/0x0006dbd0.cpp [wrapped: conflict: DAT_0049850c]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fn_0006dbd0@@UAE_NPAX@Z
namespace fn_0006dbd0 {
extern int FUN_00344e74(void* a, int b, void* c, void* d, int e);
extern char DAT_0049850c[];
extern char DAT_00499750[];
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void* a);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void* a);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(void* a) {
    return (int)FUN_00344e74(a, 0, DAT_0049850c, DAT_00499750, 0) != 0;
}
} // namespace fn_0006dbd0


// 0x0006dc10 fight::TrackFactoryCasterTemplate<CGrappleOpportunityTrack>::vfunc_0 (36 B): matches/0x0006dc10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleOpportunityTrack@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<CGrappleOpportunityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_6dc10, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0006dc50 fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack>::vfunc_0 (36 B): matches/0x0006dc50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleSequenceTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499880, 0) != 0;
}


// 0x0006dc90 fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_0 (36 B): matches/0x0006dc90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleSoundTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_00499910, 0) != 0;
}


// 0x0006dcd0 fight::TrackFactoryCasterTemplate<CGrappleSmartPropDropTrack>::vfunc_0 (36 B): matches/0x0006dcd0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleSmartPropDropTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSmartPropDropTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004999a8, 0) != 0;
}


// 0x0006dd10 fight::TrackFactoryCasterTemplate<CGrappleSwapTrack>::vfunc_0 (36 B): matches/0x0006dd10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleSwapTrack@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSwapTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_6dd10, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0006dd50 fight::TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack>::vfunc_0 (36 B): matches/0x0006dd50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCGrappleUninterruptibleTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499ad8, 0) != 0;
}


// 0x0006dd90 fight::TrackFactoryCasterTemplate<CHeadTrackerTrack>::vfunc_0 (36 B): matches/0x0006dd90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCHeadTrackerTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CHeadTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &a, &hulk_at_00499b70, 0)) != 0;
}


// 0x0006ddd0 fight::TrackFactoryCasterTemplate<CHeliDeathSpiralTrack>::vfunc_0 (36 B): matches/0x0006ddd0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCHeliDeathSpiralTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CHeliDeathSpiralTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499c00, 0) != 0;
}


// 0x0006de10 fight::TrackFactoryCasterTemplate<CHitAnimationTrack>::vfunc_0 (36 B): matches/0x0006de10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCHitAnimationTrack@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<CHitAnimationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_6de10, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0006de50 fight::TrackFactoryCasterTemplate<CIntangibleTrack>::vfunc_0 (36 B): matches/0x0006de50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCIntangibleTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CIntangibleTrack>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return (FUN_00344e74(a, 0, (void*)&DAT_0049850c, (void*)&DAT_00499d20, 0) != 0);
}


// 0x0006de90 fight::TrackFactoryCasterTemplate<CIntangibleToActorsTrack>::vfunc_0 (36 B): matches/0x0006de90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCIntangibleToActorsTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CIntangibleToActorsTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499db0, 0) != 0;
}


// 0x0006ded0 fight::TrackFactoryCasterTemplate<CInvincibleTrack>::vfunc_0 (36 B): matches/0x0006ded0.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster]
// sym: ?vfunc_0@TrackFactoryCasterTemplate_CInvincibleTrack@fight@fn_0006ded0@@UAE_NPBD@Z
namespace fn_0006ded0 {
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate_CInvincibleTrack : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C++" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern const int DAT_0049850c;
extern const int DAT_00499e40;
bool fight::TrackFactoryCasterTemplate_CInvincibleTrack::vfunc_0(const char* name) {
    return FUN_00344e74(name, 0, &DAT_0049850c, &DAT_00499e40, 0) != 0;
}
} // namespace fn_0006ded0


// 0x0006df10 fight::TrackFactoryCasterTemplate<CInvulnerableTrack>::vfunc_0 (36 B): matches/0x0006df10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCInvulnerableTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CInvulnerableTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499ec8, 0) != 0;
}


// 0x0006df50 fight::TrackFactoryCasterTemplate<CJointTrack>::vfunc_0 (36 B): matches/0x0006df50.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCJointTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CJointTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499f50, 0) != 0;
}


// 0x0006df90 fight::TrackFactoryCasterTemplate<CJumpTrack>::vfunc_0 (36 B): matches/0x0006df90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCJumpTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CJumpTrack>::vfunc_0(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return (bool)((int)(!!FUN_00344e74(a, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_00499fcc, 0)));
}


// 0x0006dfd0 fight::TrackFactoryCasterTemplate<CJumpAttackTrack>::vfunc_0 (36 B): matches/0x0006dfd0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCJumpAttackTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CJumpAttackTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)&DAT_0049850c, (void*)&DAT_0049a050, 0)) != 0;
}


// 0x0006e010 fight::TrackFactoryCasterTemplate<CKeyPoseTrack>::vfunc_0 (36 B): matches/0x0006e010.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCKeyPoseTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CKeyPoseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a0d4, 0) != 0;
}


// 0x0006e050 fight::TrackFactoryCasterTemplate<CMotionHitGroundHeightTrack>::vfunc_0 (36 B): matches/0x0006e050.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?Cast@TrackFactoryCasterTemplate@fight@fn_0006e050@@UAEHPAX@Z
namespace fn_0006e050 {
extern "C++" int __cdecl testCast(void*, int, void*, void*, int);
extern int gA, hulk_at_0049a160;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
class CMotionHitGroundHeightTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate::Cast(void* p) {
    return testCast(p, 0, &gA, &hulk_at_0049a160, 0) != 0;
}
} // namespace fn_0006e050

namespace fn_fa9e1582 {

// 0x0006e090 fight::TrackFactoryCasterTemplate<CMotionTrailTrack>::vfunc_0 (36 B): matches/0x0006e090.cpp
// sym: ?TrackFactoryCasterTemplate_CMotionTrailTrack_vfunc_0@fn_fa9e1582@@YGHPAX@Z
int __stdcall TrackFactoryCasterTemplate_CMotionTrailTrack_vfunc_0(void* p) {
    int r = ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)&DAT_0049850c, (void*)&DAT_0049a1f8, 0));
    return r != 0;
}

} // namespace fn_fa9e1582

// 0x0006e0d0 fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_0 (36 B): matches/0x0006e0d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCMoveTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((CMoveTrack_6e0d0*)p, 0, &DAT_0049850c, &DAT_0049a278, 0) != 0;
}


// 0x0006e110 fight::TrackFactoryCasterTemplate<CMoveAddTrack>::vfunc_0 (36 B): matches/0x0006e110.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCMoveAddTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CMoveAddTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a2fc, 0) != 0;
}


// 0x0006e150 fight::TrackFactoryCasterTemplate<CMoveAddYTrack>::vfunc_0 (36 B): matches/0x0006e150.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCMoveAddYTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CMoveAddYTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a37c, 0) != 0;
}


// 0x0006e190 fight::TrackFactoryCasterTemplate<COpportunityBallTrack>::vfunc_0 (36 B): matches/0x0006e190.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCOpportunityBallTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<COpportunityBallTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a410, 0) != 0;
}


// 0x0006e1d0 fight::TrackFactoryCasterTemplate<COrientTrack>::vfunc_0 (36 B): matches/0x0006e1d0.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCOrientTrack@fight@fn_0006e1d0@@@fight@fn_0006e1d0@@UAE_NPBD@Z
namespace fn_0006e1d0 {
extern int DAT_0049850c, DAT_0049a49c;
extern "C++" int __cdecl FUN_00344e74(const char*, int, const int*, const int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class COrientTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <> bool TrackFactoryCasterTemplate<COrientTrack>::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a49c, 0) != 0;
}
} // namespace fight
} // namespace fn_0006e1d0


// 0x0006e210 fight::TrackFactoryCasterTemplate<COrientTargetTrack>::vfunc_0 (36 B): matches/0x0006e210.cpp [wrapped: conflict: DAT_0049850c; FUN_00344e74; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCOrientTargetTrack@fn_0006e210@@@fight@fn_0006e210@@UAE_NPAX@Z
namespace fn_0006e210 {
extern int DAT_0049850c, DAT_0049a520;
extern "C++" void* __cdecl FUN_00344e74(void*, int, int*, int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class COrientTargetTrack {};
template <> bool fight::TrackFactoryCasterTemplate<COrientTargetTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a520, 0) != 0;
}
template class fight::TrackFactoryCasterTemplate<COrientTargetTrack>;
} // namespace fn_0006e210


// 0x0006e250 fight::TrackFactoryCasterTemplate<CPropActorSetStateTrack>::vfunc_0 (36 B): matches/0x0006e250.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCPropActorSetStateTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CPropActorSetStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a5b8, 0) != 0;
}


// 0x0006e290 fight::TrackFactoryCasterTemplate<CPushBackAnimationTrack>::vfunc_0 (36 B): matches/0x0006e290.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCPushBackAnimationTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CPushBackAnimationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a650, 0) != 0;
}


// 0x0006e2d0 fight::TrackFactoryCasterTemplate<CRageModeTrack>::vfunc_0 (36 B): matches/0x0006e2d0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_0006e2d0@@UAEHPAX@Z
namespace fn_0006e2d0 {
extern int a, hulk_at_0049a6dc;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CRageModeTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &a, &hulk_at_0049a6dc, 0)) != 0;
}
} // namespace fight
} // namespace fn_0006e2d0


// 0x0006e310 fight::TrackFactoryCasterTemplate<CHapticTrack>::vfunc_0 (36 B): matches/0x0006e310.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCHapticTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CHapticTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a764, 0) != 0;
}


// 0x0006e350 fight::TrackFactoryCasterTemplate<CScrubberTrack>::vfunc_0 (36 B): matches/0x0006e350.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCScrubberTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CScrubberTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a7e4, 0) != 0;
}


// 0x0006e390 fight::TrackFactoryCasterTemplate<CSmartPropAttachTrack>::vfunc_0 (36 B): matches/0x0006e390.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropAttachTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropAttachTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a878, 0) != 0;
}


// 0x0006e3d0 fight::TrackFactoryCasterTemplate<CSmartPropDetachTrack>::vfunc_0 (36 B): matches/0x0006e3d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropDetachTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropDetachTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a910, 0) != 0;
}


// 0x0006e410 fight::TrackFactoryCasterTemplate<CSmartPropDropTrack>::vfunc_0 (36 B): matches/0x0006e410.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_0006e410@@UAEHPAX@Z
namespace fn_0006e410 {
extern "C++" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, hulk_at_0049a9a0;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CSmartPropDropTrack {};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_0049a9a0, 0) != 0;
}
} // namespace fn_0006e410


// 0x0006e450 fight::TrackFactoryCasterTemplate<CSmartPropEventTrack>::vfunc_0 (36 B): matches/0x0006e450.cpp [wrapped: conflict: fight::TrackFactoryCaster]
// sym: ?vfunc_0@TrackFactoryCasterTemplateCSmartPropEventTrack@fight@fn_0006e450@@UAE_NPAX@Z
namespace fn_0006e450 {
extern "C++" int match(void*, int, void*, void*, int);
extern int gA, hulk_at_0049aa38;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplateCSmartPropEventTrack : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::TrackFactoryCasterTemplateCSmartPropEventTrack::vfunc_0(void* p) {
    return match(p, 0, &gA, &hulk_at_0049aa38, 0) != 0;
}
} // namespace fn_0006e450


// 0x0006e490 fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::vfunc_0 (36 B): matches/0x0006e490.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropRemoveInstanceTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::vfunc_0(void* __p0) { hulk_intptr param = (hulk_intptr)__p0;

    return !(FUN_00344e74(param, 0, (void*)&DAT_0049850c, (void*)&DAT_0049aad8, 0) == 0);
}


// 0x0006e4d0 fight::TrackFactoryCasterTemplate<CSmartPropSetStateTrack>::vfunc_0 (36 B): matches/0x0006e4d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropSetStateTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropSetStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049ab78, 0) != 0;
}


// 0x0006e510 fight::TrackFactoryCasterTemplate<CSmartPropSpawnTrack>::vfunc_0 (36 B): matches/0x0006e510.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropSpawnTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropSpawnTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049ac10, 0) != 0;
}


// 0x0006e550 fight::TrackFactoryCasterTemplate<CSmartPropThrowTrack>::vfunc_0 (36 B): matches/0x0006e550.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropThrowTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &g1, &hulk_at_0049aca8, 0) != 0;
}


// 0x0006e590 fight::TrackFactoryCasterTemplate<CSmartPropThrowingTrack>::vfunc_0 (36 B): matches/0x0006e590.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropThrowingTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropThrowingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (void*)&DAT_0049850c, (void*)&DAT_0049ad40, 0) != 0;
}


// 0x0006e5d0 fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_0 (36 B): matches/0x0006e5d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSmartPropUpdateAttachmentTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropUpdateAttachmentTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049ade0, 0) != 0;
}


// 0x0006e610 fight::TrackFactoryCasterTemplate<CSnapToWallTrack>::vfunc_0 (36 B): matches/0x0006e610.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSnapToWallTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CSnapToWallTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049ae78, 0) != 0;
}


// 0x0006e650 fight::TrackFactoryCasterTemplate<CSoundTrack>::vfunc_0 (36 B): matches/0x0006e650.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSoundTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CSoundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049aef8, 0) != 0;
}


// 0x0006e690 fight::TrackFactoryCasterTemplate<CStageTrack>::vfunc_0 (36 B): matches/0x0006e690.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCStageTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CStageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, (void*)(&sourceType), (void*)(&hulk_at_0049af78), 0) != 0;
}


// 0x0006e6d0 fight::TrackFactoryCasterTemplate<CStunAnimationTrack>::vfunc_0 (36 B): matches/0x0006e6d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCStunAnimationTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CStunAnimationTrack>::vfunc_0(void* __p0) { const char * p = (const char *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b000, 0) != 0;
}


// 0x0006e710 fight::TrackFactoryCasterTemplate<CSweepTrack>::vfunc_0 (36 B): matches/0x0006e710.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCSweepTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSweepTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (int)FUN_00344e74((void*)a, 0, (void*)&DAT_0049850c, (void*)&DAT_0049b088, 0) != 0;
}


// 0x0006e750 fight::TrackFactoryCasterTemplate<CTargetTrack>::vfunc_0 (36 B): matches/0x0006e750.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_0006e750@@UAEHPAX@Z
namespace fn_0006e750 {
class CTargetTrack {};
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
extern int FUN_00344e74(void*, int, void*, void*, int);
extern int a, hulk_at_0049b10c;
int fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_0049b10c, 0) != 0;
}
} // namespace fn_0006e750


// 0x0006e790 fight::TrackFactoryCasterTemplate<CUninterruptibleTrack>::vfunc_0 (36 B): matches/0x0006e790.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCUninterruptibleTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CUninterruptibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b198, 0) != 0;
}


// 0x0006e7d0 fight::TrackFactoryCasterTemplate<CWallSlideTrack>::vfunc_0 (36 B): matches/0x0006e7d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCWallSlideTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CWallSlideTrack>::vfunc_0(void* __p0) { CWallSlideTrack_6e7d0 * p = (CWallSlideTrack_6e7d0 *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b224, 0) != 0;
}


// 0x0006e810 fight::TrackFactoryCasterTemplate<CWeaponCollisionTrack>::vfunc_0 (36 B): matches/0x0006e810.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCWeaponCollisionTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CWeaponCollisionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b2b8, 0) != 0;
}

