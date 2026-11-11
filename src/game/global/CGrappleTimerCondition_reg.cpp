// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004fd40..0x00050500 (kind game, layer game, confidence high), dominant class CGrappleTimerCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe626ee4 {
#define TREE_TU_END }
namespace fn_fe626ee4 {} using namespace fn_fe626ee4;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe626ee4 {
struct CAxisArcCondition_4fd40;
class CStageCondition_4fd50 {};
class ParamValue_4fd50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fd50 : public ParamValue_4fd50 {
  public:
    virtual void f();
};
class CStageCondition_4fde0;
class ParamValue_4fde0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4fde0 : public ParamValue_4fde0 {
  public:
    int pad;
};
struct CAxisArcCondition_4fe20;
class CStageCondition_4fe30 {};
class ParamValue_4fe30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fe30 : public ParamValue_4fe30 {
  public:
    virtual void f();
};
class CStageCondition_4fec0;
class ParamValue_4fec0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4fec0 : public ParamValue_4fec0 {
  public:
    int pad;
};
class CStageCondition_4ff10;
class ParamValue_4ff10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4ff10 : public ParamValue_4ff10 {
  public:
    int pad;
};
struct CAxisArcCondition_4ff50;
class CStageCondition_4ff60 {};
class ParamValue_4ff60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4ff60 : public ParamValue_4ff60 {
  public:
    virtual void f();
};
class CStageCondition_4fff0;
class ParamValue_4fff0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4fff0 : public ParamValue_4fff0 {
  public:
    int pad;
};
class ParamValueEnum_50000 {
  public:
    ParamValueEnum_50000(int);
    virtual void f();
    char pad[12];
};
class ParamEnumConstList_50000 : public ParamValueEnum_50000 {
  public:
    ParamEnumConstList_50000(int, int, int, int);
    virtual void f();
    int a, b, c;
};
struct CAxisArcCondition_50030;
class CStageCondition_50040 {};
class ParamValue_50040 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_50040 : public ParamValue_50040 {
  public:
    virtual void f();
};
class CStageCondition_500d0;
class ParamValue_500d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_500d0 : public ParamValue_500d0 {
  public:
    int pad;
};
struct CAxisArcCondition_50110;
class CStageCondition_50120 {};
class ParamValue_50120 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_50120 : public ParamValue_50120 {
  public:
    virtual void f();
};
struct CAxisArcCondition_501a0;
class CStageCondition_501b0 {};
class ParamValue_501b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_501b0 : public ParamValue_501b0 {
  public:
    virtual void f();
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_50290;
class ParamValue_50290 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_50290 : public ParamValue_50290 {
  public:
    int pad;
};
struct CAxisArcCondition_502d0;
class CStageCondition_502e0 {};
class ParamValue_502e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_502e0 : public ParamValue_502e0 {
  public:
    virtual void f();
};
class CStageCondition_50370;
class ParamValue_50370 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_50370 : public ParamValue_50370 {
  public:
    int pad;
};
struct CAxisArcCondition_503b0;
class CStageCondition_503c0 {};
class ParamValue_503c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_503c0 : public ParamValue_503c0 {
  public:
    virtual void f();
};
class ParamValueBool_50410 {
  public:
    ParamValueBool_50410(int);
    virtual void f0();
    char pad[0x0c];
};
class ParamBool_50410 : public ParamValueBool_50410 {
  public:
    ParamBool_50410(int a, int b);
    int m10;
};
class CStageCondition_50450;
class ParamValue_50450 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_50450 : public ParamValue_50450 {
  public:
    int pad;
};
class CStageCondition_504a0;
class ParamValue_504a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_504a0 : public ParamValue_504a0 {
  public:
    int pad;
};
} // namespace fn_fe626ee4
namespace fight {
class ConditionFactoryCaster_504c0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
}
namespace fight {
class CAlertStatusCondition_504c0;
}
namespace fn_fe626ee4 {
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int g1, g2;

} // namespace fn_fe626ee4

// 0x0004fd40 fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_7 (6 B): matches/0x0004fd40.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004fd50 fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_6 (30 B): matches/0x0004fd50.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fd50 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4fd50*)&DAT_003f335c));
}


// 0x0004fd70 fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_8 (26 B): matches/0x0004fd70.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAlertStatusCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAlertStatusCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAlertStatusCondition>::**)(int))&this->f_18))(b);
}


// 0x0004fd90 fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_2 (11 B): matches/0x0004fd90.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004fdc0 fight::ParamBool<CRageModeCondition>::vfunc_6 (26 B): matches/0x0004fdc0.cpp
// sym: ?vfunc_6@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CRageModeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CRageModeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CRageModeCondition>*)a)->*(*(bool (fight::ParamBool<CRageModeCondition>::**)(int))&this->f_10))(b);
}


// 0x0004fde0 fight::ParamBool<CRageModeCondition>::vfunc_2 (11 B): matches/0x0004fde0.cpp
// sym: ?vfunc_2@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CRageModeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004fe20 fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_7 (6 B): matches/0x0004fe20.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004fe30 fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_6 (30 B): matches/0x0004fe30.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fe30 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4fe30*)&DAT_003f335c));
}


// 0x0004fe50 fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_8 (26 B): matches/0x0004fe50.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CGrappleTimerCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CGrappleTimerCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CGrappleTimerCondition>::**)(int))&this->f_18))(b);
}


// 0x0004fe70 fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_2 (11 B): matches/0x0004fe70.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004fea0 fight::ParamFloatConstRange<CGrappleTimerCondition>::vfunc_6 (26 B): matches/0x0004fea0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleTimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGrappleTimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGrappleTimerCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CGrappleTimerCondition>::**)(int))&this->f_10))(b);
}


// 0x0004fec0 fight::ParamFloatConstRange<CGrappleTimerCondition>::vfunc_2 (11 B): matches/0x0004fec0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGrappleTimerCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004fef0 fight::ParamBool<CGrappleTimerCondition>::vfunc_6 (26 B): matches/0x0004fef0.cpp
// sym: ?vfunc_6@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrappleTimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CGrappleTimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CGrappleTimerCondition>*)a)->*(*(bool (fight::ParamBool<CGrappleTimerCondition>::**)(int))&this->f_10))(b);
}


// 0x0004ff10 fight::ParamBool<CGrappleTimerCondition>::vfunc_2 (11 B): matches/0x0004ff10.cpp
// sym: ?vfunc_2@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CGrappleTimerCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004ff50 fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_7 (6 B): matches/0x0004ff50.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004ff60 fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_6 (30 B): matches/0x0004ff60.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4ff60 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4ff60*)&DAT_003f335c));
}


// 0x0004ff80 fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_8 (26 B): matches/0x0004ff80.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CInactivityTimerCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CInactivityTimerCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CInactivityTimerCondition>::**)(int))&this->f_18))(b);
}


// 0x0004ffa0 fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_2 (11 B): matches/0x0004ffa0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CInactivityTimerCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004ffd0 fight::ParamFloatConstRange<CInactivityTimerCondition>::vfunc_6 (26 B): matches/0x0004ffd0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CInactivityTimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CInactivityTimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CInactivityTimerCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CInactivityTimerCondition>::**)(int))&this->f_10))(b);
}


// 0x0004fff0 fight::ParamFloatConstRange<CInactivityTimerCondition>::vfunc_2 (11 B): matches/0x0004fff0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CInactivityTimerCondition>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fe626ee4 {

// 0x00050000 FUN_00050000 (46 B): matches/0x00050000.cpp
// sym: ??0ParamEnumConstList_50000@fn_fe626ee4@@QAE@HHHH@Z
ParamEnumConstList_50000::ParamEnumConstList_50000(int x, int y, int z, int w) : ParamValueEnum_50000(x), a(y), b(z), c(w) {}

} // namespace fn_fe626ee4

// 0x00050030 fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_7 (6 B): matches/0x00050030.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00050040 fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_6 (30 B): matches/0x00050040.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_50040 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_50040*)&DAT_003f335c));
}


// 0x00050060 fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_8 (26 B): matches/0x00050060.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCharacterFloatCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCharacterFloatCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCharacterFloatCondition>::**)(int))&this->f_18))(b);
}


// 0x00050080 fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_2 (11 B): matches/0x00050080.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x000500b0 fight::ParamFloatConstRange<CCharacterFloatCondition>::vfunc_6 (26 B): matches/0x000500b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCharacterFloatCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCharacterFloatCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCharacterFloatCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCharacterFloatCondition>::**)(int))&this->f_10))(b);
}


// 0x000500d0 fight::ParamFloatConstRange<CCharacterFloatCondition>::vfunc_2 (11 B): matches/0x000500d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCharacterFloatCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00050110 fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_7 (6 B): matches/0x00050110.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00050120 fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_6 (30 B): matches/0x00050120.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_50120 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_50120*)&DAT_003f335c));
}


// 0x00050140 fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_8 (26 B): matches/0x00050140.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCharacterBoolCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCharacterBoolCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCharacterBoolCondition>::**)(int))&this->f_18))(b);
}


// 0x00050160 fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_2 (11 B): matches/0x00050160.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x000501a0 fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_7 (6 B): matches/0x000501a0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x000501b0 fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_6 (30 B): matches/0x000501b0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_501b0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_501b0*)&DAT_003f335c));
}


// 0x000501d0 fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_8 (26 B): matches/0x000501d0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CFightNodePrevCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CFightNodePrevCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CFightNodePrevCondition>::**)(int))&this->f_18))(b);
}


// 0x000501f0 fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_2 (11 B): matches/0x000501f0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CFightNodePrevCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00050220 fight::ParamValue::vfunc_2 (3 B): matches/0x00050220.cpp
// sym: ?vfunc_2@ParamValue@fight@@UAE_NXZ
bool fight::ParamValue::vfunc_2() {
    return (bool)(0);
}


// 0x00050230 fight::ParamValueBranch::vfunc_1 (6 B): matches/0x00050230.cpp
// sym: ?vfunc_1@ParamValueBranch@fight@@UAEHXZ
int fight::ParamValueBranch::vfunc_1() {
    return 10;
}

namespace fn_fe626ee4 {

// 0x00050240 fight::ParamBranch<CFightNodePrevCondition>::vfunc_6 (12 B): matches/0x00050240.cpp
// sym: ?vfunc_6@ParamBranch@fn_fe626ee4@@UAEXPAX@Z
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fe626ee4

// 0x00050270 fight::ParamBool<CFightNodePrevCondition>::vfunc_6 (26 B): matches/0x00050270.cpp
// sym: ?vfunc_6@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CFightNodePrevCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CFightNodePrevCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CFightNodePrevCondition>*)a)->*(*(bool (fight::ParamBool<CFightNodePrevCondition>::**)(int))&this->f_10))(b);
}


// 0x00050290 fight::ParamBool<CFightNodePrevCondition>::vfunc_2 (11 B): matches/0x00050290.cpp
// sym: ?vfunc_2@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CFightNodePrevCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000502d0 fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_7 (6 B): matches/0x000502d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x000502e0 fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_6 (30 B): matches/0x000502e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_502e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_502e0*)&DAT_003f335c));
}


// 0x00050300 fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_8 (26 B): matches/0x00050300.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CIntentionSpeedCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CIntentionSpeedCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CIntentionSpeedCondition>::**)(int))&this->f_18))(b);
}


// 0x00050320 fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_2 (11 B): matches/0x00050320.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00050350 fight::ParamFloatConstRange<CIntentionSpeedCondition>::vfunc_6 (26 B): matches/0x00050350.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CIntentionSpeedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CIntentionSpeedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CIntentionSpeedCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CIntentionSpeedCondition>::**)(int))&this->f_10))(b);
}


// 0x00050370 fight::ParamFloatConstRange<CIntentionSpeedCondition>::vfunc_2 (11 B): matches/0x00050370.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CIntentionSpeedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000503b0 fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_7 (6 B): matches/0x000503b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x000503c0 fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_6 (30 B): matches/0x000503c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_503c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_503c0*)&DAT_003f335c));
}


// 0x000503e0 fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_8 (26 B): matches/0x000503e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CClimbEdgeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CClimbEdgeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CClimbEdgeCondition>::**)(int))&this->f_18))(b);
}


// 0x00050400 fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_2 (11 B): matches/0x00050400.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAlertStatusCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CClimbEdgeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

namespace fn_fe626ee4 {

// 0x00050410 FUN_00050410 (32 B): matches/0x00050410.cpp
// sym: ??0ParamBool_50410@fn_fe626ee4@@QAE@HH@Z
ParamBool_50410::ParamBool_50410(int a, int b) : ParamValueBool_50410(a) {
    *(void**)this = g_vftable;
    m10 = b;
}

} // namespace fn_fe626ee4

// 0x00050430 fight::ParamBool<CClimbEdgeCondition>::vfunc_6 (26 B): matches/0x00050430.cpp
// sym: ?vfunc_6@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CClimbEdgeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CClimbEdgeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CClimbEdgeCondition>*)a)->*(*(bool (fight::ParamBool<CClimbEdgeCondition>::**)(int))&this->f_10))(b);
}


// 0x00050450 fight::ParamBool<CClimbEdgeCondition>::vfunc_2 (11 B): matches/0x00050450.cpp
// sym: ?vfunc_2@?$ParamBool@VCRageModeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CClimbEdgeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00050480 fight::ParamFloatConstRange<CMotionClimbAngleCondition>::vfunc_6 (26 B): matches/0x00050480.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMotionClimbAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMotionClimbAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMotionClimbAngleCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CMotionClimbAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x000504a0 fight::ParamFloatConstRange<CMotionClimbAngleCondition>::vfunc_2 (11 B): matches/0x000504a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMotionClimbAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x000504c0 fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_0 (36 B): matches/0x000504c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCAlertStatusCondition@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<CAlertStatusCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &g1, &g2, 0) != 0;
}

