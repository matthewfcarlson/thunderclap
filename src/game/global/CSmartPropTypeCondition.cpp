// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f220..0x0004f2b0 (kind game, layer game, confidence high), dominant class CSmartPropTypeCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa7fd08f {
#define TREE_TU_END }
namespace fn_fa7fd08f {} using namespace fn_fa7fd08f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa7fd08f {
struct CAxisArcCondition_4f220;
class CStageCondition_4f230 {};
class ParamValue_4f230 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f230 : public ParamValue_4f230 {
  public:
    virtual void f();
};

} // namespace fn_fa7fd08f

// 0x0004f220 fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_7 (6 B): matches/0x0004f220.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropTypeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f230 fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_6 (30 B): matches/0x0004f230.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropTypeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f230 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f230*)&DAT_003f335c));
}


// 0x0004f250 fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_8 (26 B): matches/0x0004f250.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropTypeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f270 fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_2 (11 B): matches/0x0004f270.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropTypeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

