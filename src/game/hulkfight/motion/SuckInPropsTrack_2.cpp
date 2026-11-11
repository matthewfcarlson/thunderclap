// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178770..0x001788b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SuckInPropsTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f632f3fc {
#define TREE_TU_END }
namespace fn_f632f3fc {} using namespace fn_f632f3fc;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f632f3fc {
class CStageCondition_178790;
class ParamValue_178790 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178790 : public ParamValue_178790 {
  public:
    int pad;
};
class CStageCondition_1787e0;
class ParamValue_1787e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1787e0 : public ParamValue_1787e0 {
  public:
    int pad;
};
class CStageCondition_178830;
class ParamValue_178830 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178830 : public ParamValue_178830 {
  public:
    int pad;
};
class CStageCondition_178880;
class ParamValue_178880 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178880 : public ParamValue_178880 {
  public:
    int pad;
};

} // namespace fn_f632f3fc

// 0x00178770 fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::vfunc_6 (26 B): matches/0x00178770.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::**)(int))&this->f_10))(b);
}


// 0x00178790 fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::vfunc_2 (11 B): matches/0x00178790.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TargetIconDistanceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001787c0 fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::vfunc_6 (26 B): matches/0x001787c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::**)(int))&this->f_10))(b);
}


// 0x001787e0 fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::vfunc_2 (11 B): matches/0x001787e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CriticalMassDrainTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178810 fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_6 (26 B): matches/0x00178810.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::**)(int))&this->f_10))(b);
}


// 0x00178830 fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_2 (11 B): matches/0x00178830.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetIconDistanceTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178860 fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_6 (26 B): matches/0x00178860.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::**)(int))&this->f_10))(b);
}


// 0x00178880 fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_2 (11 B): matches/0x00178880.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VSuckInPropsTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::SuckInPropsTrack>::vfunc_2() {
    return this->f_10 == 0;
}

