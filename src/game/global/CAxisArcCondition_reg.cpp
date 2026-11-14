// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00050500..0x00051480 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd94a027 {
#define TREE_TU_END }
namespace fn_fd94a027 {} using namespace fn_fd94a027;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fd94a027 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491d68;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50500 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CAxisArcCondition_50500 {};
class CAxisDoubleTapCondition_50580;
extern char DAT_00491ea0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50580 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CAxisPressCondition_50600;
class ConditionFactoryCaster_50600 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern char DAT_00491fd8;
extern char DAT_00492070;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50640 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00492108;
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);
class ConditionFactoryCaster_50680 {
  public:
    virtual int vfunc_0(int a);
};
extern char DAT_004921a0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_506c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00492238;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50700 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CButtonDownCondition_50700;
}
namespace fn_fd94a027 {
extern char DAT_004922d0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50740 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CButtonPressCondition_50740 {};
class CButtonReleaseCondition_50780;
extern char DAT_00492368;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50780 {
  public:
    virtual bool vfunc_0(CButtonReleaseCondition_50780*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00492408;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_507c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CButtonUpCondition_507c0 {};
extern char DAT_004924a0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50800 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_004925f8;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50880 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CCharacterTemplateVariationCondition_50880;
}
namespace fn_fd94a027 {
extern int hulk_at_00491ca8;
class CCollisionDirectionCondition_50940;
extern char DAT_004927d8;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50940 {
  public:
    virtual bool vfunc_0(CCollisionDirectionCondition_50940*);
    virtual void vfunc_1();
};
}
namespace fight {
class ConditionFactoryCaster_50980 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CCollisionFlagCondition_50980;
}
namespace fn_fd94a027 {
extern char DAT_00492878;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_509c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00492920;
extern char DAT_004929c8;
extern char DAT_00492a78;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50a40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00492b28;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50a80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CCollisionPushbackDirectionCondition_50a80 {};
extern char DAT_00492c90;
class ConditionFactoryCaster_50b00 {
  public:
    virtual int vfunc_0(void* obj);
    virtual int vfunc_1(void* obj);
};
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50b40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00492d40;
extern char DAT_00492e90;
class ConditionFactoryCaster_50bc0 {
  public:
    virtual int f0(int arg);
    virtual int f1();
};
struct TypeDesc;
extern char DAT_00492f30;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50c00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern int gTypeA_50c40;
class CGrappleAlertStatusCondition_50cc0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50cc0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00493118;
class CGrappleFightNodeCondition_50d40;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50d40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00493278;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50d80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CGrappleFightNodeParentCondition_50d80 {};
extern char DAT_00493328;
extern char DAT_004933d8;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50dc0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CGrappleFightNodeTimeCondition_50dc0 {};
extern char DAT_00493488;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50e00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CGrappleMotionStateCondition_50e00;
}
namespace fn_fd94a027 {
extern char DAT_00493528;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50e40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CGrappleSizeCondition_50e40 {};
extern char DAT_00493668;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50ec0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CInactivityTimerCondition_50f00 {};
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50f00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00493710;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_50f80 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class CIsGrappledCondition_50f80;
}
namespace fn_fd94a027 {
extern char DAT_00493858;
extern int gTypeA_50fc0;
extern char DAT_00493990;
class ConditionFactoryCaster_51000 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CIsInvincibleCondition_51000 {};
extern char DAT_00493ad0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_51080 {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
}
namespace fight {
class CMotionClimbAngleCondition_51080;
}
namespace fn_fd94a027 {
extern void* hulk_at_003f83e8[];
class ConditionFactoryCaster_510b0 {
  public:
    void* vptr;
    ConditionFactoryCaster_510b0() { vptr = hulk_at_003f83e8; }
};
class ConditionFactoryCasterTemplate_510b0 : public ConditionFactoryCaster_510b0 {
  public:
    virtual void Dummy();
    ConditionFactoryCasterTemplate_510b0();
};
class CMotionStateCondition_51100;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_51100 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
extern char DAT_00493c08;
extern char DAT_00493d40;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_51180 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CPropActorStateCondition_51180 {};
extern char DAT_00493de0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_51200 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace fight {
class CSmartPropAngleCondition_51200;
}
namespace fn_fd94a027 {
extern int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_00493e80;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_51240 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CSmartPropAttachedCondition_51240 {};
extern char DAT_00493f28;
extern char DAT_00493fd0;
class ConditionFactoryCaster_51280 {
  public:
    virtual int vfunc_0(void* a);
    virtual int vfunc_1(void* a);
};
extern int gTypeA_512c0;
} // namespace fn_fd94a027
namespace fight {
class ConditionFactoryCaster_51300 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
extern void* DAT_00491ca8;
}
namespace fight {
extern void* DAT_00494128;
}
namespace fight {
class ConditionFactoryCaster_51380 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_fd94a027 {
class CSmartPropStateCondition_51380 {};
extern char DAT_00494278;

} // namespace fn_fd94a027

// 0x00050500 fight::ConditionFactoryCasterTemplate<CAxisArcCondition>::vfunc_0 (36 B): matches/0x00050500.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAxisArcCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CAxisArcCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00491d68, 0) != 0;
}


// 0x00050540 fight::ConditionFactoryCasterTemplate<CAxisDirectionCondition>::vfunc_0 (36 B): matches/0x00050540.cpp [wrapped: conflict: fight::ConditionFactoryCaster]
// sym: ?vfunc_0@ConditionFactoryCasterTemplateCAxisDirectionCondition@fight@fn_00050540@@UAE_NPAX@Z
namespace fn_00050540 {
extern "C++" int __cdecl CastQuery(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplateCAxisDirectionCondition : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern void* a;
extern void* hulk_at_00491e00;
bool fight::ConditionFactoryCasterTemplateCAxisDirectionCondition::vfunc_0(void* p) {
    return CastQuery(p, 0, &a, &hulk_at_00491e00, 0) != 0;
}
} // namespace fn_00050540


// 0x00050580 fight::ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>::vfunc_0 (36 B): matches/0x00050580.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAxisDoubleTapCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00491ea0, 0) != 0;
}


// 0x000505c0 fight::ConditionFactoryCasterTemplate<CAxisDownCondition>::vfunc_0 (36 B): matches/0x000505c0.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_000505c0@@UAE_NPBD@Z
namespace fn_000505c0 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CAxisDownCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
extern "C++" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern void* a;
extern void* hulk_at_00491f40;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &a, &hulk_at_00491f40, 0) != 0;
}
} // namespace fn_000505c0


// 0x00050600 fight::ConditionFactoryCasterTemplate<CAxisPressCondition>::vfunc_0 (36 B): matches/0x00050600.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAxisPressCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CAxisPressCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00491fd8, 0) != 0;
}


// 0x00050640 fight::ConditionFactoryCasterTemplate<CAxisReleaseCondition>::vfunc_0 (36 B): matches/0x00050640.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAxisReleaseCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CAxisReleaseCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492070, 0) != 0;
}


// 0x00050680 fight::ConditionFactoryCasterTemplate<CAxisSpeedCondition>::vfunc_0 (36 B): matches/0x00050680.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAxisSpeedCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CAxisSpeedCondition>::vfunc_0(void* __p0) { int a = (int)__p0;

    return FUN_00344e74(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_00492108, 0) != 0;
}


// 0x000506c0 fight::ConditionFactoryCasterTemplate<CAxisUpCondition>::vfunc_0 (36 B): matches/0x000506c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAxisUpCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CAxisUpCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004921a0, 0) != 0;
}


// 0x00050700 fight::ConditionFactoryCasterTemplate<CButtonDownCondition>::vfunc_0 (36 B): matches/0x00050700.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCButtonDownCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CButtonDownCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (void*)&DAT_00491ca8, (void*)&DAT_00492238, 0) != 0;
}


// 0x00050740 fight::ConditionFactoryCasterTemplate<CButtonPressCondition>::vfunc_0 (36 B): matches/0x00050740.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCButtonPressCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CButtonPressCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004922d0, 0) != 0;
}


// 0x00050780 fight::ConditionFactoryCasterTemplate<CButtonReleaseCondition>::vfunc_0 (36 B): matches/0x00050780.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCButtonReleaseCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CButtonReleaseCondition>::vfunc_0(void* __p0) { CButtonReleaseCondition_50780 * p = (CButtonReleaseCondition_50780 *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492368, 0) != 0;
}


// 0x000507c0 fight::ConditionFactoryCasterTemplate<CButtonUpCondition>::vfunc_0 (36 B): matches/0x000507c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCButtonUpCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CButtonUpCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492408, 0) != 0;
}


// 0x00050800 fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition>::vfunc_0 (36 B): matches/0x00050800.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCharacterSizeCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CCharacterSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004924a0, 0) != 0;
}


// 0x00050840 fight::ConditionFactoryCasterTemplate<CCharacterTemplateCondition>::vfunc_0 (36 B): matches/0x00050840.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050840@@UAE_NPAX@Z
namespace fn_00050840 {
class CCharacterTemplateCondition;
extern void* a;
extern void* hulk_at_00492548;
extern "C++" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_00492548, 0) != 0;
}
} // namespace fn_00050840


// 0x00050880 fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::vfunc_0 (36 B): matches/0x00050880.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCharacterTemplateVariationCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CCharacterTemplateVariationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004925f8, 0) != 0;
}


// 0x000508c0 fight::ConditionFactoryCasterTemplate<CClimbableCondition>::vfunc_0 (36 B): matches/0x000508c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCClimbableCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CClimbableCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00050900 fight::ConditionFactoryCasterTemplate<CClimbEdgeCondition>::vfunc_0 (36 B): matches/0x00050900.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050900@@UAE_NPBD@Z
namespace fn_00050900 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern void* a;
extern void* hulk_at_00492738;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_00492738, 0) != 0;
}
} // namespace fn_00050900


// 0x00050940 fight::ConditionFactoryCasterTemplate<CCollisionDirectionCondition>::vfunc_0 (36 B): matches/0x00050940.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionDirectionCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionDirectionCondition>::vfunc_0(void* __p0) { CCollisionDirectionCondition_50940 * p = (CCollisionDirectionCondition_50940 *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004927d8, 0) != 0;
}


// 0x00050980 fight::ConditionFactoryCasterTemplate<CCollisionFlagCondition>::vfunc_0 (36 B): matches/0x00050980.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionFlagCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionFlagCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492878, 0) != 0;
}


// 0x000509c0 fight::ConditionFactoryCasterTemplate<CCollisionHeightCondition>::vfunc_0 (36 B): matches/0x000509c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionHeightCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionHeightCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492920, 0) != 0;
}


// 0x00050a00 fight::ConditionFactoryCasterTemplate<CCollisionHitLocationCondition>::vfunc_0 (36 B): matches/0x00050a00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionHitLocationCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionHitLocationCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004929c8, 0) != 0;
}


// 0x00050a40 fight::ConditionFactoryCasterTemplate<CCollisionInterruptCondition>::vfunc_0 (36 B): matches/0x00050a40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionInterruptCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionInterruptCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492a78, 0) != 0;
}


// 0x00050a80 fight::ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>::vfunc_0 (36 B): matches/0x00050a80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionPushbackDirectionCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492b28, 0) != 0;
}


// 0x00050ac0 fight::ConditionFactoryCasterTemplate<CCollisionPushbackVelocityCondition>::vfunc_0 (36 B): matches/0x00050ac0.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050ac0@@UAE_NPAX@Z
namespace fn_00050ac0 {
extern void* a;
extern void* hulk_at_00492be0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &a, &hulk_at_00492be0, 0)) != 0;
}
} // namespace fn_00050ac0


// 0x00050b00 fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::vfunc_0 (36 B): matches/0x00050b00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionPushbackYCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionPushbackYCondition>::vfunc_0(void* __p0) { void * obj = (void *)__p0;

    return (FUN_00344e74(obj, 0, (void*)&DAT_00491ca8, (void*)&DAT_00492c90, 0) != 0);
}


// 0x00050b40 fight::ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>::vfunc_0 (36 B): matches/0x00050b40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCCollisionPushbackYAngleCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492d40, 0) != 0;
}


// 0x00050b80 fight::ConditionFactoryCasterTemplate<CCollisionStunTimeCondition>::vfunc_0 (36 B): matches/0x00050b80.cpp [wrapped: conflict: FUN_00344e74; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050b80@@UAE_NPAX@Z
namespace fn_00050b80 {
class CCollisionStunTimeCondition;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* gA;
extern void* hulk_at_00492df0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &hulk_at_00492df0, 0) != 0;
}
} // namespace fight
} // namespace fn_00050b80


// 0x00050bc0 fight::ConditionFactoryCasterTemplate<CFightNodeCondition>::vfunc_0 (36 B): matches/0x00050bc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCFightNodeCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CFightNodeCondition>::vfunc_0(void* __p0) { int arg = (int)__p0;

    hulk_intptr r = FUN_00344e74(arg, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_00492e90, 0);
    return r != 0;
}


// 0x00050c00 fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition>::vfunc_0 (36 B): matches/0x00050c00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCFightNodeParentCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CFightNodeParentCondition>::vfunc_0(void* __p0) { void * y = (void *)__p0;

    return FUN_00344e74(y, 0, &DAT_00491ca8, &DAT_00492f30, 0) != 0;
}


// 0x00050c40 fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition>::vfunc_0 (36 B): matches/0x00050c40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCFightNodePrevCondition@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<CFightNodePrevCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_50c40, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00050c80 fight::ConditionFactoryCasterTemplate<CFightNodeTimeCondition>::vfunc_0 (36 B): matches/0x00050c80.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050c80@@UAE_NPAX@Z
namespace fn_00050c80 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* gA;
extern void* hulk_at_00493070;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &hulk_at_00493070, 0) != 0;
}
} // namespace fn_00050c80


// 0x00050cc0 fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::vfunc_0 (36 B): matches/0x00050cc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGrappleAlertStatusCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleAlertStatusCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493118, 0) != 0;
}


// 0x00050d00 fight::ConditionFactoryCasterTemplate<CGrappleCharacterTemplateCondition>::vfunc_0 (36 B): matches/0x00050d00.cpp [wrapped: conflict: fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050d00@@UAE_NPAX@Z
namespace fn_00050d00 {
extern void* gA;
extern void* hulk_at_004931c8;
namespace fight {
class ConditionFactoryCasterTemplate {
  public:
    virtual bool vfunc_0(void* p);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &gA, &hulk_at_004931c8, 0)) != 0;
}
} // namespace fn_00050d00


// 0x00050d40 fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::vfunc_0 (36 B): matches/0x00050d40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGrappleFightNodeCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493278, 0) != 0;
}


// 0x00050d80 fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_0 (36 B): matches/0x00050d80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGrappleFightNodeParentCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493328, 0) != 0;
}


// 0x00050dc0 fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::vfunc_0 (36 B): matches/0x00050dc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGrappleFightNodeTimeCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleFightNodeTimeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004933d8, 0) != 0;
}


// 0x00050e00 fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>::vfunc_0 (36 B): matches/0x00050e00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGrappleMotionStateCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493488, 0) != 0;
}


// 0x00050e40 fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>::vfunc_0 (36 B): matches/0x00050e40.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGrappleSizeCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493528, 0) != 0;
}


// 0x00050e80 fight::ConditionFactoryCasterTemplate<CGrappleTimerCondition>::vfunc_0 (36 B): matches/0x00050e80.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050e80@@UAE_NPAVCGrappleTimerCondition@3@@Z
namespace fn_00050e80 {
class CGrappleTimerCondition;
extern void* a;
extern void* hulk_at_004935c0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CGrappleTimerCondition*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CGrappleTimerCondition*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(CGrappleTimerCondition* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(p), 0, &a, &hulk_at_004935c0, 0)) != 0;
}
} // namespace fight
} // namespace fn_00050e80


// 0x00050ec0 fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition>::vfunc_0 (36 B): matches/0x00050ec0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCGroundDistanceCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CGroundDistanceCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493668, 0) != 0;
}


// 0x00050f00 fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>::vfunc_0 (36 B): matches/0x00050f00.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCInactivityTimerCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493710, 0) != 0;
}


// 0x00050f40 fight::ConditionFactoryCasterTemplate<CIntentionSpeedCondition>::vfunc_0 (36 B): matches/0x00050f40.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00050f40@@UAEHPAUCIntentionSpeedCondition@3@@Z
namespace fn_00050f40 {
struct CIntentionSpeedCondition;
extern void* gA;
extern void* hulk_at_004937b8;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(CIntentionSpeedCondition*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(CIntentionSpeedCondition*);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(CIntentionSpeedCondition* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(p), 0, &gA, &hulk_at_004937b8, 0)) != 0;
}
} // namespace fight
} // namespace fn_00050f40


// 0x00050f80 fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>::vfunc_0 (36 B): matches/0x00050f80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCIsGrappledCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493858, 0) != 0;
}


// 0x00050fc0 fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>::vfunc_0 (36 B): matches/0x00050fc0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCIsHelicopterCondition@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<CIsHelicopterCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_50fc0, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00051000 fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>::vfunc_0 (36 B): matches/0x00051000.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCIsInvincibleCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CIsInvincibleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493990, 0) != 0;
}


// 0x00051040 fight::ConditionFactoryCasterTemplate<CLuaNumberCondition>::vfunc_0 (36 B): matches/0x00051040.cpp [wrapped: conflict: DAT_00491ca8; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00051040@@UAE_NPBD@Z
namespace fn_00051040 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CLuaNumberCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C++" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern const void* DAT_00491ca8;
extern const void* DAT_00493a30;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* name) {
    return FUN_00344e74(name, 0, &DAT_00491ca8, &DAT_00493a30, 0) != 0;
}
} // namespace fn_00051040


// 0x00051080 fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::vfunc_0 (36 B): matches/0x00051080.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCMotionClimbAngleCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493ad0, 0) != 0;
}

namespace fn_fd94a027 {

// 0x000510b0 FUN_000510b0 (9 B): matches/0x000510b0.cpp
// sym: ??0ConditionFactoryCaster_510b0@fn_fd94a027@@QAE@XZ
ConditionFactoryCasterTemplate_510b0::ConditionFactoryCasterTemplate_510b0() {
    vptr = hulk_at_003f83e8;
}

} // namespace fn_fd94a027

// 0x000510c0 fight::ConditionFactoryCasterTemplate<CMotionHitCondition>::vfunc_0 (36 B): matches/0x000510c0.cpp [wrapped: conflict: DAT_00491ca8; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCMotionHitCondition@fn_000510c0@@@fight@fn_000510c0@@UAE_NPAX@Z
namespace fn_000510c0 {
class CMotionHitCondition;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_00491ca8, DAT_00493b70;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <> bool ConditionFactoryCasterTemplate<CMotionHitCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493b70, 0) != 0;
}
template class ConditionFactoryCasterTemplate<CMotionHitCondition>;
} // namespace fight
} // namespace fn_000510c0


// 0x00051100 fight::ConditionFactoryCasterTemplate<CMotionStateCondition>::vfunc_0 (36 B): matches/0x00051100.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCMotionStateCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493c08, 0) != 0;
}


// 0x00051140 fight::ConditionFactoryCasterTemplate<CNameFlagCondition>::vfunc_0 (36 B): matches/0x00051140.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00051140@@UAE_NPAX@Z
namespace fn_00051140 {
struct CNameFlagCondition {};
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C++" int __cdecl helper(void*, int, void*, void*, int);
extern void* a;
extern void* hulk_at_00493ca0;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return helper(p, 0, &a, &hulk_at_00493ca0, 0) != 0;
}
} // namespace fn_00051140


// 0x00051180 fight::ConditionFactoryCasterTemplate<CPropActorStateCondition>::vfunc_0 (36 B): matches/0x00051180.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCPropActorStateCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CPropActorStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493d40, 0) != 0;
}


// 0x000511c0 fight::ConditionFactoryCasterTemplate<CRageModeCondition>::vfunc_0 (36 B): matches/0x000511c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCRageModeCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CRageModeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return (int)FUN_00344e74(p, 0, (void*)&DAT_00491ca8, (void*)&DAT_00493de0, 0) != 0;
}


// 0x00051200 fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::vfunc_0 (36 B): matches/0x00051200.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSmartPropAngleCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropAngleCondition>::vfunc_0(void* __p0) { const char * name = (const char *)__p0;

    return FUN_00344e74(name, 0, &DAT_00491ca8, &DAT_00493e80, 0) != 0;
}


// 0x00051240 fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::vfunc_0 (36 B): matches/0x00051240.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSmartPropAttachedCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493f28, 0) != 0;
}


// 0x00051280 fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::vfunc_0 (36 B): matches/0x00051280.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSmartPropCSMableCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return (FUN_00344e74(a, 0, (void*)&DAT_00491ca8, (void*)&DAT_00493fd0, 0) != 0);
}


// 0x000512c0 fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::vfunc_0 (36 B): matches/0x000512c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSmartPropDistanceCondition@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_512c0, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00051300 fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::vfunc_0 (36 B): matches/0x00051300.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSmartPropGrabbableNameCondition@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00494128, 0) != 0;
}


// 0x00051340 fight::ConditionFactoryCasterTemplate<CSmartPropNameCondition>::vfunc_0 (36 B): matches/0x00051340.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00051340@@UAE_NPAX@Z
namespace fn_00051340 {
extern void* a;
extern void* hulk_at_004941d0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &a, &hulk_at_004941d0, 0)) != 0;
}
} // namespace fn_00051340


// 0x00051380 fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>::vfunc_0 (36 B): matches/0x00051380.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCSmartPropStateCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00494278, 0) != 0;
}


// 0x000513c0 fight::ConditionFactoryCasterTemplate<CSmartPropTypeCondition>::vfunc_0 (36 B): matches/0x000513c0.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_000513c0@@UAE_NPAX@Z
namespace fn_000513c0 {
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* hulk_at_00494318;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &hulk_at_00494318, 0) != 0;
}
} // namespace fn_000513c0


// 0x00051400 fight::ConditionFactoryCasterTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_0 (36 B): matches/0x00051400.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?Test@ConditionFactoryCasterTemplate@fight@fn_00051400@@UAE_NPAX@Z
namespace fn_00051400 {
extern void* gA;
extern void* hulk_at_004943c8;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::Test(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &gA, &hulk_at_004943c8, 0)) != 0;
}
} // namespace fn_00051400


// 0x00051440 fight::ConditionFactoryCasterTemplate<CSmartPropWeaponTypeCondition>::vfunc_0 (36 B): matches/0x00051440.cpp [wrapped: conflict: DAT_00491ca8; fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fight@fn_00051440@@UAE_NPAX@Z
namespace fn_00051440 {
struct CSmartPropWeaponTypeCondition;
extern "C++" int __cdecl FUN_00344e74(CSmartPropWeaponTypeCondition*, int, void*, void*, int);
extern void *DAT_00491ca8, *DAT_00494478;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74((CSmartPropWeaponTypeCondition*)p, 0, &DAT_00491ca8, &DAT_00494478, 0) != 0;
}
} // namespace fight
} // namespace fn_00051440

