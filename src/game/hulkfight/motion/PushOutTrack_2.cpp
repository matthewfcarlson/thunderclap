// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001782d0..0x00178460 (kind game, layer game, confidence high), dominant class hulkfight::motion::PushOutTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fcf7ae44 {
#define TREE_TU_END }
namespace fn_fcf7ae44 {} using namespace fn_fcf7ae44;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fcf7ae44 {
class CStageCondition_1782f0;
class ParamValue_1782f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1782f0 : public ParamValue_1782f0 {
  public:
    int pad;
};
class CStageCondition_178340;
class ParamValue_178340 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178340 : public ParamValue_178340 {
  public:
    int pad;
};
class CStageCondition_178390;
class ParamValue_178390 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178390 : public ParamValue_178390 {
  public:
    int pad;
};
class CStageCondition_1783e0;
class ParamValue_1783e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1783e0 : public ParamValue_1783e0 {
  public:
    int pad;
};
class CStageCondition_178430;
class ParamValue_178430 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178430 : public ParamValue_178430 {
  public:
    int pad;
};

} // namespace fn_fcf7ae44

// 0x001782d0 fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::vfunc_6 (26 B): matches/0x001782d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::**)(int))&this->f_10))(b);
}


// 0x001782f0 fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::vfunc_2 (11 B): matches/0x001782f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178320 fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::vfunc_6 (26 B): matches/0x00178320.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::**)(int))&this->f_10))(b);
}


// 0x00178340 fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::vfunc_2 (11 B): matches/0x00178340.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TargetBreakTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178370 fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::vfunc_6 (26 B): matches/0x00178370.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::**)(int))&this->f_10))(b);
}


// 0x00178390 fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::vfunc_2 (11 B): matches/0x00178390.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMomentumXZAddTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PushOutTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001783c0 fight::ParamVector<hulkfight::motion::PushOutTrack>::vfunc_6 (26 B): matches/0x001783c0.cpp
// sym: ?vfunc_6@?$ParamVector@VPushOutTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::PushOutTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::PushOutTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::PushOutTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::PushOutTrack>::**)(int))&this->f_10))(b);
}


// 0x001783e0 fight::ParamVector<hulkfight::motion::PushOutTrack>::vfunc_2 (11 B): matches/0x001783e0.cpp
// sym: ?vfunc_2@?$ParamVector@VPushOutTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::PushOutTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178410 fight::ParamBool<hulkfight::motion::PushOutTrack>::vfunc_6 (26 B): matches/0x00178410.cpp
// sym: ?vfunc_6@?$ParamBool@VPushOutTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PushOutTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PushOutTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PushOutTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PushOutTrack>::**)(int))&this->f_10))(b);
}


// 0x00178430 fight::ParamBool<hulkfight::motion::PushOutTrack>::vfunc_2 (11 B): matches/0x00178430.cpp
// sym: ?vfunc_2@?$ParamBool@VPushOutTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PushOutTrack>::vfunc_2() {
    return this->f_10 == 0;
}

