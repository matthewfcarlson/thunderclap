// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127490..0x00127540 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7b9d47c {
#define TREE_TU_END }
namespace fn_f7b9d47c {} using namespace fn_f7b9d47c;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f7b9d47c {
class CStageCondition_1274b0;
class ParamValue_1274b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1274b0 : public ParamValue_1274b0 {
  public:
    int pad;
};
class CStageCondition_127500;
class ParamValue_127500 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127500 : public ParamValue_127500 {
  public:
    int pad;
};

} // namespace fn_f7b9d47c

// 0x00127490 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::vfunc_6 (26 B): matches/0x00127490.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x001274b0 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::vfunc_2 (11 B): matches/0x001274b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001274e0 fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::vfunc_6 (26 B): matches/0x001274e0.cpp
// sym: ?vfunc_6@?$ParamBool@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::AcquireTargetCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x00127500 fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::vfunc_2 (11 B): matches/0x00127500.cpp
// sym: ?vfunc_2@?$ParamBool@VAcquireTargetCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::AcquireTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}

