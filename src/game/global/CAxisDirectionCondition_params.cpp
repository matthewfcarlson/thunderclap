// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e660..0x0004e740 (kind game, layer game, confidence high), dominant class CAxisDirectionCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3f6993b {
#define TREE_TU_END }
namespace fn_f3f6993b {} using namespace fn_f3f6993b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3f6993b {
struct CAxisArcCondition_4e660;
class CStageCondition_4e670 {};
class ParamValue_4e670 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e670 : public ParamValue_4e670 {
  public:
    virtual void f();
};
class CStageCondition_4e700;
class ParamValue_4e700 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e700 : public ParamValue_4e700 {
  public:
    int pad;
};

} // namespace fn_f3f6993b

// 0x0004e660 fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_7 (6 B): matches/0x0004e660.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAxisDirectionCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e670 fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_6 (30 B): matches/0x0004e670.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAxisDirectionCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e670 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e670*)&DAT_003f335c));
}


// 0x0004e690 fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_8 (26 B): matches/0x0004e690.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAxisDirectionCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAxisDirectionCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAxisDirectionCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAxisDirectionCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e6b0 fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_2 (11 B): matches/0x0004e6b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAxisDirectionCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisDirectionCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e6e0 fight::ParamFloatConstRange<CAxisDirectionCondition>::vfunc_6 (26 B): matches/0x0004e6e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAxisDirectionCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisDirectionCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAxisDirectionCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAxisDirectionCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CAxisDirectionCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e700 fight::ParamFloatConstRange<CAxisDirectionCondition>::vfunc_2 (11 B): matches/0x0004e700.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAxisDirectionCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisDirectionCondition>::vfunc_2() {
    return this->f_10 == 0;
}

