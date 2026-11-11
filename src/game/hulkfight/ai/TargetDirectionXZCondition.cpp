// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127620..0x001276f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDirectionXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7e825af {
#define TREE_TU_END }
namespace fn_f7e825af {} using namespace fn_f7e825af;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f7e825af {
struct CAxisArcCondition_127620;
class CStageCondition_127630 {};
class ParamValue_127630 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_127630 : public ParamValue_127630 {
  public:
    virtual void f();
};
class CStageCondition_1276c0;
class ParamValue_1276c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1276c0 : public ParamValue_1276c0 {
  public:
    int pad;
};

} // namespace fn_f7e825af

// 0x00127620 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_7 (6 B): matches/0x00127620.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00127630 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_6 (30 B): matches/0x00127630.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_127630 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_127630*)&DAT_003f335c));
}


// 0x00127650 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_8 (26 B): matches/0x00127650.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::**)(int))&this->f_18))(b);
}


// 0x00127670 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_2 (11 B): matches/0x00127670.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001276a0 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::vfunc_6 (26 B): matches/0x001276a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::**)(int))&this->f_10))(b);
}


// 0x001276c0 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::vfunc_2 (11 B): matches/0x001276c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetDirectionXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionXZCondition>::vfunc_2() {
    return this->f_10 == 0;
}

