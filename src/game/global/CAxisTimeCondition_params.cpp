// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e200..0x0004e2e0 (kind game, layer game, confidence high), dominant class CAxisTimeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7929523 {
#define TREE_TU_END }
namespace fn_f7929523 {} using namespace fn_f7929523;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7929523 {
struct CAxisArcCondition_4e200;
class CStageCondition_4e210 {};
class ParamValue_4e210 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e210 : public ParamValue_4e210 {
  public:
    virtual void f();
};
class CStageCondition_4e2a0;
class ParamValue_4e2a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e2a0 : public ParamValue_4e2a0 {
  public:
    int pad;
};

} // namespace fn_f7929523

// 0x0004e200 fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_7 (6 B): matches/0x0004e200.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAxisTimeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e210 fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_6 (30 B): matches/0x0004e210.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAxisTimeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e210 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e210*)&DAT_003f335c));
}


// 0x0004e230 fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_8 (26 B): matches/0x0004e230.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAxisTimeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAxisTimeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAxisTimeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAxisTimeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e250 fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_2 (11 B): matches/0x0004e250.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAxisTimeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e280 fight::ParamFloatConstRange<CAxisTimeCondition>::vfunc_6 (26 B): matches/0x0004e280.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAxisTimeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisTimeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAxisTimeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAxisTimeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CAxisTimeCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e2a0 fight::ParamFloatConstRange<CAxisTimeCondition>::vfunc_2 (11 B): matches/0x0004e2a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAxisTimeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisTimeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

