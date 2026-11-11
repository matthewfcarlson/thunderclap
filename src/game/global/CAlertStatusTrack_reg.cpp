// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006d090..0x0006d590 (kind game, layer game, confidence high), dominant class CAlertStatusTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbdb5a92 {
#define TREE_TU_END }
namespace fn_fbdb5a92 {} using namespace fn_fbdb5a92;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbdb5a92 {
class CStageCondition_6d0b0;
class ParamValue_6d0b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d0b0 : public ParamValue_6d0b0 {
  public:
    int pad;
};
struct CAxisArcCondition_6d0f0;
class CStageCondition_6d100 {};
class ParamValue_6d100 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_6d100 : public ParamValue_6d100 {
  public:
    virtual void f();
};
class CStageCondition_6d190;
class ParamValue_6d190 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d190 : public ParamValue_6d190 {
  public:
    int pad;
};
class CStageCondition_6d1e0;
class ParamValue_6d1e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d1e0 : public ParamValue_6d1e0 {
  public:
    int pad;
};
class CStageCondition_6d230;
class ParamValue_6d230 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d230 : public ParamValue_6d230 {
  public:
    int pad;
};
class CStageCondition_6d280;
class ParamValue_6d280 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d280 : public ParamValue_6d280 {
  public:
    int pad;
};
class CStageCondition_6d2d0;
class ParamValue_6d2d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d2d0 : public ParamValue_6d2d0 {
  public:
    int pad;
};
class CStageCondition_6d320;
class ParamValue_6d320 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d320 : public ParamValue_6d320 {
  public:
    int pad;
};
class CStageCondition_6d370;
class ParamValue_6d370 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d370 : public ParamValue_6d370 {
  public:
    int pad;
};
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_004985b8;
} // namespace fn_fbdb5a92
namespace fight {
class TrackFactoryCaster_6d3d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fbdb5a92 {
class CAlertStatusTrack_6d3d0 {};
class TrackFactoryCasterTemplate {
  public:
    virtual void Cast();
    TrackFactoryCasterTemplate();
};
extern char DAT_00498640;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fbdb5a92
namespace fight {
class TrackFactoryCaster_6d410 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CAutoTargetTrack_6d410;
}
namespace fn_fbdb5a92 {
extern char DAT_004986d0;
} // namespace fn_fbdb5a92
namespace fight {
class TrackFactoryCaster_6d450 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class TrackFactoryCaster_6d490 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace fight {
class CCameraHintTrack_6d490;
}
namespace fn_fbdb5a92 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_00498760;
extern char DAT_00498878;
} // namespace fn_fbdb5a92
namespace fight {
class TrackFactoryCaster_6d510 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fbdb5a92 {
class CClearHitRecordsTrack_6d510 {};
struct CClearCollisionStun_6d550;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00498908;
} // namespace fn_fbdb5a92
namespace fight {
class TrackFactoryCaster_6d550 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}


// 0x0006d090 fight::ParamFloatConstRange<CAlertStatusTrack>::vfunc_6 (26 B): matches/0x0006d090.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAlertStatusTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAlertStatusTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAlertStatusTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CAlertStatusTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d0b0 fight::ParamFloatConstRange<CAlertStatusTrack>::vfunc_2 (11 B): matches/0x0006d0b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAlertStatusTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d0f0 fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_7 (6 B): matches/0x0006d0f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0006d100 fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_6 (30 B): matches/0x0006d100.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_6d100 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_6d100*)&DAT_003f335c));
}


// 0x0006d120 fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_8 (26 B): matches/0x0006d120.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAlertStatusTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAlertStatusTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CAlertStatusTrack>::**)(int))&this->f_18))(b);
}


// 0x0006d140 fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_2 (11 B): matches/0x0006d140.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0006d170 fight::ParamFloatConstRange<CDeathTrack>::vfunc_6 (26 B): matches/0x0006d170.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDeathTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CDeathTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CDeathTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CDeathTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d190 fight::ParamFloatConstRange<CDeathTrack>::vfunc_2 (11 B): matches/0x0006d190.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CDeathTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d1c0 fight::ParamFloatConstRange<CAIHintTrack>::vfunc_6 (26 B): matches/0x0006d1c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAIHintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAIHintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAIHintTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CAIHintTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d1e0 fight::ParamFloatConstRange<CAIHintTrack>::vfunc_2 (11 B): matches/0x0006d1e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAIHintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d210 fight::ParamFloatConstRange<CClearCollisionStun>::vfunc_6 (26 B): matches/0x0006d210.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClearCollisionStun>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CClearCollisionStun>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CClearCollisionStun>*)a)->*(*(bool (fight::ParamFloatConstRange<CClearCollisionStun>::**)(int))&this->f_10))(b);
}


// 0x0006d230 fight::ParamFloatConstRange<CClearCollisionStun>::vfunc_2 (11 B): matches/0x0006d230.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClearCollisionStun>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d260 fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::vfunc_6 (26 B): matches/0x0006d260.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d280 fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::vfunc_2 (11 B): matches/0x0006d280.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d2b0 fight::ParamFloatConstRange<CWallSlideTrack>::vfunc_6 (26 B): matches/0x0006d2b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CWallSlideTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CWallSlideTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CWallSlideTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CWallSlideTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d2d0 fight::ParamFloatConstRange<CWallSlideTrack>::vfunc_2 (11 B): matches/0x0006d2d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CWallSlideTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d300 fight::ParamIntConstRange<CWallSlideTrack>::vfunc_6 (26 B): matches/0x0006d300.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCWallSlideTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CWallSlideTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CWallSlideTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CWallSlideTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CWallSlideTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d320 fight::ParamIntConstRange<CWallSlideTrack>::vfunc_2 (11 B): matches/0x0006d320.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCWallSlideTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CWallSlideTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d350 fight::ParamFloatConstRange<CTargetTrack>::vfunc_6 (26 B): matches/0x0006d350.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d370 fight::ParamFloatConstRange<CTargetTrack>::vfunc_2 (11 B): matches/0x0006d370.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAlertStatusTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d390 fight::TrackFactoryCasterTemplate<CAIHintTrack>::vfunc_0 (36 B): matches/0x0006d390.cpp [wrapped: conflict: DAT_0049850c; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?Cast@?$TrackFactoryCasterTemplate@VCAIHintTrack@fight@fn_0006d390@@@fight@fn_0006d390@@UAE_NPAX@Z
namespace fn_0006d390 {
extern char DAT_0049850c[];
extern char DAT_00498530[];
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
class CAIHintTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<fight::CAIHintTrack>::Cast(void* p) {
    return FUN_00344e74(p, 0, DAT_0049850c, DAT_00498530, 0) != 0;
}
} // namespace fn_0006d390


// 0x0006d3d0 fight::TrackFactoryCasterTemplate<CAlertStatusTrack>::vfunc_0 (36 B): matches/0x0006d3d0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCAlertStatusTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CAlertStatusTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004985b8, 0) != 0;
}

namespace fn_fbdb5a92 {

// 0x0006d400 FUN_0006d400 (9 B): matches/0x0006d400.cpp
// sym: ??0TrackFactoryCasterTemplate@fn_fbdb5a92@@QAE@XZ
TrackFactoryCasterTemplate::TrackFactoryCasterTemplate() {}

} // namespace fn_fbdb5a92

// 0x0006d410 fight::TrackFactoryCasterTemplate<CAutoTargetTrack>::vfunc_0 (36 B): matches/0x0006d410.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCAutoTargetTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CAutoTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498640, 0) != 0;
}


// 0x0006d450 fight::TrackFactoryCasterTemplate<CCameraDramaticTrack>::vfunc_0 (36 B): matches/0x0006d450.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCCameraDramaticTrack@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CCameraDramaticTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004986d0, 0) != 0;
}


// 0x0006d490 fight::TrackFactoryCasterTemplate<CCameraHintTrack>::vfunc_0 (36 B): matches/0x0006d490.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCCameraHintTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CCameraHintTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_00498760, 0) != 0;
}


// 0x0006d4d0 fight::TrackFactoryCasterTemplate<CCameraShakeTrack>::vfunc_0 (36 B): matches/0x0006d4d0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_0006d4d0@@UAEHH@Z
namespace fn_0006d4d0 {
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
};
} // namespace fight
extern int a, b;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(hulk_intptr, int, int*, int*, int);
int fight::TrackFactoryCasterTemplate::vfunc_0(int x) {
    return FUN_00344e74(x, 0, &a, &b, 0) != 0;
}
} // namespace fn_0006d4d0


// 0x0006d510 fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack>::vfunc_0 (36 B): matches/0x0006d510.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCClearHitRecordsTrack@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_00498878, 0) != 0;
}


// 0x0006d550 fight::TrackFactoryCasterTemplate<CClearCollisionStun>::vfunc_0 (36 B): matches/0x0006d550.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCClearCollisionStun@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CClearCollisionStun>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_00498908, 0) != 0;
}

