// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f520..0x0004f5b0 (kind game, layer game, confidence high), dominant class CSmartPropGrabbableNameCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb8920eb {
#define TREE_TU_END }
namespace fn_fb8920eb {} using namespace fn_fb8920eb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb8920eb {
struct CAxisArcCondition_4f520;
class CStageCondition_4f530 {};
class ParamValue_4f530 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f530 : public ParamValue_4f530 {
  public:
    virtual void f();
};

} // namespace fn_fb8920eb

// 0x0004f520 fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_7 (6 B): matches/0x0004f520.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropGrabbableNameCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f530 fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_6 (30 B): matches/0x0004f530.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f530 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f530*)&DAT_003f335c));
}


// 0x0004f550 fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_8 (26 B): matches/0x0004f550.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropGrabbableNameCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f570 fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_2 (11 B): matches/0x0004f570.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropGrabbableNameCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}

