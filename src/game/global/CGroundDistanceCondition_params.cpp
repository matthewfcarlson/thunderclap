// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e740..0x0004e820 (kind game, layer game, confidence high), dominant class CGroundDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc257f58 {
#define TREE_TU_END }
namespace fn_fc257f58 {} using namespace fn_fc257f58;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc257f58 {
struct CAxisArcCondition_4e740;
class CStageCondition_4e750 {};
class ParamValue_4e750 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e750 : public ParamValue_4e750 {
  public:
    virtual void f();
};
class CStageCondition_4e7e0;
class ParamValue_4e7e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e7e0 : public ParamValue_4e7e0 {
  public:
    int pad;
};

} // namespace fn_fc257f58

// 0x0004e740 fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_7 (6 B): matches/0x0004e740.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCGroundDistanceCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e750 fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_6 (30 B): matches/0x0004e750.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCGroundDistanceCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e750 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e750*)&DAT_003f335c));
}


// 0x0004e770 fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_8 (26 B): matches/0x0004e770.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCGroundDistanceCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CGroundDistanceCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CGroundDistanceCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CGroundDistanceCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e790 fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_2 (11 B): matches/0x0004e790.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCGroundDistanceCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGroundDistanceCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e7c0 fight::ParamFloatConstRange<CGroundDistanceCondition>::vfunc_6 (26 B): matches/0x0004e7c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCGroundDistanceCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGroundDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CGroundDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CGroundDistanceCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CGroundDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e7e0 fight::ParamFloatConstRange<CGroundDistanceCondition>::vfunc_2 (11 B): matches/0x0004e7e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCGroundDistanceCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CGroundDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}

