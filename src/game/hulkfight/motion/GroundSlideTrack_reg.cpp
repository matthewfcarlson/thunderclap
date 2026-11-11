// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153d60..0x00153e50 (kind game, layer game, confidence high), dominant class hulkfight::motion::GroundSlideTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3487f27 {
#define TREE_TU_END }
namespace fn_f3487f27 {} using namespace fn_f3487f27;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3487f27 {
class CStageCondition_153d80;
class ParamValue_153d80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153d80 : public ParamValue_153d80 {
  public:
    int pad;
};
class CStageCondition_153dd0;
class ParamValue_153dd0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153dd0 : public ParamValue_153dd0 {
  public:
    int pad;
};
class ParamValueInt_153de0 {
  public:
    virtual void f();
    ParamValueInt_153de0(int);
};
class ParamIntConstRange_153de0 : public ParamValueInt_153de0 {
  public:
    virtual void f();
    char pad[12];
    int value;
    ParamIntConstRange_153de0(int a, int b);
};
class CStageCondition_153e20;
class ParamValue_153e20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153e20 : public ParamValue_153e20 {
  public:
    int pad;
};

} // namespace fn_f3487f27

// 0x00153d60 fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::vfunc_6 (26 B): matches/0x00153d60.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00153d80 fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::vfunc_2 (11 B): matches/0x00153d80.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153db0 fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_6 (26 B): matches/0x00153db0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::**)(int))&this->f_10))(b);
}


// 0x00153dd0 fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_2 (11 B): matches/0x00153dd0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f3487f27 {

// 0x00153de0 FUN_00153de0 (32 B): matches/0x00153de0.cpp
// sym: ??0ParamIntConstRange_153de0@fn_f3487f27@@QAE@HH@Z
ParamIntConstRange_153de0::ParamIntConstRange_153de0(int a, int b) : ParamValueInt_153de0(a), value(b) {}

} // namespace fn_f3487f27

// 0x00153e00 fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_6 (26 B): matches/0x00153e00.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VGroundSlideTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::**)(int))&this->f_10))(b);
}


// 0x00153e20 fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_2 (11 B): matches/0x00153e20.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VGroundSlideTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GroundSlideTrack>::vfunc_2() {
    return this->f_10 == 0;
}

