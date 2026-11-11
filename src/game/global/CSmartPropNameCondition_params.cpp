// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f2b0..0x0004f380 (kind game, layer game, confidence high), dominant class CSmartPropNameCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f540fe49 {
#define TREE_TU_END }
namespace fn_f540fe49 {} using namespace fn_f540fe49;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f540fe49 {
struct CAxisArcCondition_4f2b0;
class CStageCondition_4f2c0 {};
class ParamValue_4f2c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f2c0 : public ParamValue_4f2c0 {
  public:
    virtual void f();
};
class CStageCondition_4f350;
class ParamValue_4f350 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f350 : public ParamValue_4f350 {
  public:
    int pad;
};

} // namespace fn_f540fe49

// 0x0004f2b0 fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_7 (6 B): matches/0x0004f2b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropNameCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f2c0 fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_6 (30 B): matches/0x0004f2c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropNameCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f2c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f2c0*)&DAT_003f335c));
}


// 0x0004f2e0 fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_8 (26 B): matches/0x0004f2e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropNameCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropNameCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f300 fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_2 (11 B): matches/0x0004f300.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropNameCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f330 fight::ParamIntConstRange<CSmartPropNameCondition>::vfunc_6 (26 B): matches/0x0004f330.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCSmartPropNameCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropNameCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropNameCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropNameCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropNameCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f350 fight::ParamIntConstRange<CSmartPropNameCondition>::vfunc_2 (11 B): matches/0x0004f350.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCSmartPropNameCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropNameCondition>::vfunc_2() {
    return this->f_10 == 0;
}

