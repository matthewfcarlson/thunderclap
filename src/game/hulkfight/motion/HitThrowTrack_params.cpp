// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153480..0x001535c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4248072 {
#define TREE_TU_END }
namespace fn_f4248072 {} using namespace fn_f4248072;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4248072 {
class CStageCondition_1534a0;
class ParamValue_1534a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1534a0 : public ParamValue_1534a0 {
  public:
    int pad;
};
class CStageCondition_1534f0;
class ParamValue_1534f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1534f0 : public ParamValue_1534f0 {
  public:
    int pad;
};
class CStageCondition_153540;
class ParamValue_153540 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153540 : public ParamValue_153540 {
  public:
    int pad;
};
class CStageCondition_153590;
class ParamValue_153590 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153590 : public ParamValue_153590 {
  public:
    int pad;
};

} // namespace fn_f4248072

// 0x00153480 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_6 (26 B): matches/0x00153480.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::**)(int))&this->f_10))(b);
}


// 0x001534a0 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_2 (11 B): matches/0x001534a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorSetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001534d0 fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::vfunc_6 (26 B): matches/0x001534d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x001534f0 fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::vfunc_2 (11 B): matches/0x001534f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VInterruptAccumulatorSetTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153520 fight::ParamBool<hulkfight::motion::HitThrowTrack>::vfunc_6 (26 B): matches/0x00153520.cpp
// sym: ?vfunc_6@?$ParamBool@VHitThrowTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HitThrowTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00153540 fight::ParamBool<hulkfight::motion::HitThrowTrack>::vfunc_2 (11 B): matches/0x00153540.cpp
// sym: ?vfunc_2@?$ParamBool@VHitThrowTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153570 fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_6 (26 B): matches/0x00153570.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitThrowTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00153590 fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_2 (11 B): matches/0x00153590.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitThrowTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}

