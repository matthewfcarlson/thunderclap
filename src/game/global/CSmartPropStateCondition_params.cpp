// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f640..0x0004f720 (kind game, layer game, confidence high), dominant class CSmartPropStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe7006d9 {
#define TREE_TU_END }
namespace fn_fe7006d9 {} using namespace fn_fe7006d9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe7006d9 {
struct CAxisArcCondition_4f640;
class CStageCondition_4f650 {};
class ParamValue_4f650 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f650 : public ParamValue_4f650 {
  public:
    virtual void f();
};
class CStageCondition_4f6e0;
class ParamValue_4f6e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f6e0 : public ParamValue_4f6e0 {
  public:
    int pad;
};

} // namespace fn_fe7006d9

// 0x0004f640 fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_7 (6 B): matches/0x0004f640.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropStateCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f650 fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_6 (30 B): matches/0x0004f650.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropStateCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f650 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f650*)&DAT_003f335c));
}


// 0x0004f670 fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_8 (26 B): matches/0x0004f670.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropStateCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropStateCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f690 fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_2 (11 B): matches/0x0004f690.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropStateCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f6c0 fight::ParamIntConstRange<CSmartPropStateCondition>::vfunc_6 (26 B): matches/0x0004f6c0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCSmartPropStateCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropStateCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropStateCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropStateCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropStateCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f6e0 fight::ParamIntConstRange<CSmartPropStateCondition>::vfunc_2 (11 B): matches/0x0004f6e0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCSmartPropStateCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropStateCondition>::vfunc_2() {
    return this->f_10 == 0;
}

