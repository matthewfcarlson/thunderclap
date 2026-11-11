// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f5b0..0x0004f640 (kind game, layer game, confidence high), dominant class CSmartPropCSMableCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff02529f {
#define TREE_TU_END }
namespace fn_ff02529f {} using namespace fn_ff02529f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff02529f {
struct CAxisArcCondition_4f5b0;
class CStageCondition_4f5c0 {};
class ParamValue_4f5c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f5c0 : public ParamValue_4f5c0 {
  public:
    virtual void f();
};

} // namespace fn_ff02529f

// 0x0004f5b0 fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_7 (6 B): matches/0x0004f5b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropCSMableCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f5c0 fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_6 (30 B): matches/0x0004f5c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropCSMableCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f5c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f5c0*)&DAT_003f335c));
}


// 0x0004f5e0 fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_8 (26 B): matches/0x0004f5e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropCSMableCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropCSMableCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropCSMableCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropCSMableCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f600 fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_2 (11 B): matches/0x0004f600.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropCSMableCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_2() {
    return this->f_18 == 0;
}

