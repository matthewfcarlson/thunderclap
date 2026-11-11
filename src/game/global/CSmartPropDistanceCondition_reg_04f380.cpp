// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f380..0x0004f520 (kind game, layer game, confidence high), dominant class CSmartPropDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffd3a66d {
#define TREE_TU_END }
namespace fn_ffd3a66d {} using namespace fn_ffd3a66d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffd3a66d {
class CStageCondition_4f3a0;
class ParamValue_4f3a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f3a0 : public ParamValue_4f3a0 {
  public:
    int pad;
};
struct CAxisArcCondition_4f3e0;
class CStageCondition_4f3f0 {};
class ParamValue_4f3f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f3f0 : public ParamValue_4f3f0 {
  public:
    virtual void f();
};
class CStageCondition_4f480;
class ParamValue_4f480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f480 : public ParamValue_4f480 {
  public:
    int pad;
};
class ParamValue_4f4b0 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class CStageCondition_4f4e0;
class ParamValue_4f4e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f4e0 : public ParamValue_4f4e0 {
  public:
    int pad;
};

} // namespace fn_ffd3a66d

// 0x0004f380 fight::ParamFloatConstRange<CSmartPropAngleCondition>::vfunc_6 (26 B): matches/0x0004f380.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCSmartPropAngleCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropAngleCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f3a0 fight::ParamFloatConstRange<CSmartPropAngleCondition>::vfunc_2 (11 B): matches/0x0004f3a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCSmartPropAngleCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004f3e0 fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_7 (6 B): matches/0x0004f3e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropDistanceCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f3f0 fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_6 (30 B): matches/0x0004f3f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropDistanceCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f3f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f3f0*)&DAT_003f335c));
}


// 0x0004f410 fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_8 (26 B): matches/0x0004f410.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropDistanceCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropDistanceCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropDistanceCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropDistanceCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f430 fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_2 (11 B): matches/0x0004f430.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropDistanceCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f460 fight::ParamFloatConstRange<CSmartPropDistanceCondition>::vfunc_6 (26 B): matches/0x0004f460.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCSmartPropAngleCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSmartPropDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSmartPropDistanceCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CSmartPropDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f480 fight::ParamFloatConstRange<CSmartPropDistanceCondition>::vfunc_2 (11 B): matches/0x0004f480.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCSmartPropAngleCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSmartPropDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004f4b0 fight::ParamValueVector::vfunc_1 (6 B): matches/0x0004f4b0.cpp
// sym: ?vfunc_1@ParamValueVector@fight@@UAEHXZ
int fight::ParamValueVector::vfunc_1() {
    return 7;
}


// 0x0004f4c0 fight::ParamVector<CSmartPropDistanceCondition>::vfunc_6 (26 B): matches/0x0004f4c0.cpp
// sym: ?vfunc_6@?$ParamVector@VCSmartPropDistanceCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CSmartPropDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CSmartPropDistanceCondition>*)a)->*(*(bool (fight::ParamVector<CSmartPropDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f4e0 fight::ParamVector<CSmartPropDistanceCondition>::vfunc_2 (11 B): matches/0x0004f4e0.cpp
// sym: ?vfunc_2@?$ParamVector@VCSmartPropDistanceCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CSmartPropDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}

