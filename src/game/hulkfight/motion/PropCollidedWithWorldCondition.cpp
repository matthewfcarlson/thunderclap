// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185730..0x001857d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropCollidedWithWorldCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8d15b14 {
#define TREE_TU_END }
namespace fn_f8d15b14 {} using namespace fn_f8d15b14;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8d15b14 {
class CStageCondition_185750;
class ParamValue_185750 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185750 : public ParamValue_185750 {
  public:
    int pad;
};
class CStageCondition_1857a0;
class ParamValue_1857a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1857a0 : public ParamValue_1857a0 {
  public:
    int pad;
};

} // namespace fn_f8d15b14

// 0x00185730 fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_6 (26 B): matches/0x00185730.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::**)(int))&this->f_10))(b);
}


// 0x00185750 fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_2 (11 B): matches/0x00185750.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185780 fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_6 (26 B): matches/0x00185780.cpp
// sym: ?vfunc_6@?$ParamBool@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::**)(int))&this->f_10))(b);
}


// 0x001857a0 fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_2 (11 B): matches/0x001857a0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropCollidedWithWorldCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropCollidedWithWorldCondition>::vfunc_2() {
    return this->f_10 == 0;
}

