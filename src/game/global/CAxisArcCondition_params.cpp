// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e4a0..0x0004e580 (kind game, layer game, confidence high), dominant class CAxisArcCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2e8d082 {
#define TREE_TU_END }
namespace fn_f2e8d082 {} using namespace fn_f2e8d082;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2e8d082 {
struct CAxisArcCondition_4e4a0;
class CStageCondition_4e4b0 {};
class ParamValue_4e4b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e4b0 : public ParamValue_4e4b0 {
  public:
    virtual void f();
};
class CStageCondition_4e540;
class ParamValue_4e540 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e540 : public ParamValue_4e540 {
  public:
    int pad;
};

} // namespace fn_f2e8d082

// 0x0004e4a0 fight::ParamEnumConstList<CAxisArcCondition>::vfunc_7 (6 B): matches/0x0004e4a0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAxisArcCondition@@@fight@@UAEHH@Z
template <> int fight::ParamEnumConstList<CAxisArcCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e4b0 fight::ParamEnumConstList<CAxisArcCondition>::vfunc_6 (30 B): matches/0x0004e4b0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAxisArcCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAxisArcCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e4b0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e4b0*)&DAT_003f335c));
}


// 0x0004e4d0 fight::ParamEnumConstList<CAxisArcCondition>::vfunc_8 (26 B): matches/0x0004e4d0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAxisArcCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisArcCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAxisArcCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAxisArcCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAxisArcCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e4f0 fight::ParamEnumConstList<CAxisArcCondition>::vfunc_2 (11 B): matches/0x0004e4f0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAxisArcCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisArcCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e520 fight::ParamFloatConstRange<CAxisArcCondition>::vfunc_6 (26 B): matches/0x0004e520.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAxisArcCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisArcCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAxisArcCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAxisArcCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CAxisArcCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e540 fight::ParamFloatConstRange<CAxisArcCondition>::vfunc_2 (11 B): matches/0x0004e540.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAxisArcCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisArcCondition>::vfunc_2() {
    return this->f_10 == 0;
}

