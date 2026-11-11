// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169430..0x00169520 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastConeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1042c84 {
#define TREE_TU_END }
namespace fn_f1042c84 {} using namespace fn_f1042c84;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1042c84 {
class CStageCondition_169450;
class ParamValue_169450 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169450 : public ParamValue_169450 {
  public:
    int pad;
};
class CStageCondition_1694a0;
class ParamValue_1694a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1694a0 : public ParamValue_1694a0 {
  public:
    int pad;
};
class CStageCondition_1694f0;
class ParamValue_1694f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1694f0 : public ParamValue_1694f0 {
  public:
    int pad;
};

} // namespace fn_f1042c84

// 0x00169430 fight::ParamVector<hulkfight::motion::RayCastConeCondition>::vfunc_6 (26 B): matches/0x00169430.cpp
// sym: ?vfunc_6@?$ParamVector@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::RayCastConeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::RayCastConeCondition>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))(b);
}


// 0x00169450 fight::ParamVector<hulkfight::motion::RayCastConeCondition>::vfunc_2 (11 B): matches/0x00169450.cpp
// sym: ?vfunc_2@?$ParamVector@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::RayCastConeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169480 fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::vfunc_6 (26 B): matches/0x00169480.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))(b);
}


// 0x001694a0 fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::vfunc_2 (11 B): matches/0x001694a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastConeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001694d0 fight::ParamBool<hulkfight::motion::RayCastConeCondition>::vfunc_6 (26 B): matches/0x001694d0.cpp
// sym: ?vfunc_6@?$ParamBool@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::RayCastConeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::RayCastConeCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))(b);
}


// 0x001694f0 fight::ParamBool<hulkfight::motion::RayCastConeCondition>::vfunc_2 (11 B): matches/0x001694f0.cpp
// sym: ?vfunc_2@?$ParamBool@VRayCastConeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::RayCastConeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

