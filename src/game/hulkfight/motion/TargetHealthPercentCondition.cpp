// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001696f0..0x001697d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetHealthPercentCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7bda9bb {
#define TREE_TU_END }
namespace fn_f7bda9bb {} using namespace fn_f7bda9bb;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7bda9bb {
struct CAxisArcCondition_1696f0;
class CStageCondition_169700 {};
class ParamValue_169700 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169700 : public ParamValue_169700 {
  public:
    virtual void f();
};
class CStageCondition_169790;
class ParamValue_169790 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169790 : public ParamValue_169790 {
  public:
    int pad;
};

} // namespace fn_f7bda9bb

// 0x001696f0 fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_7 (6 B): matches/0x001696f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169700 fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_6 (30 B): matches/0x00169700.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169700 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169700*)&DAT_003f335c));
}


// 0x00169720 fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_8 (26 B): matches/0x00169720.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::**)(int))&this->f_18))(b);
}


// 0x00169740 fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_2 (11 B): matches/0x00169740.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TargetHealthPercentCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169770 fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::vfunc_6 (26 B): matches/0x00169770.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::**)(int))&this->f_10))(b);
}


// 0x00169790 fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::vfunc_2 (11 B): matches/0x00169790.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TargetHealthPercentCondition>::vfunc_2() {
    return this->f_10 == 0;
}

