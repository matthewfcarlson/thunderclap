// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153e50..0x00153f40 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f008e150 {
#define TREE_TU_END }
namespace fn_f008e150 {} using namespace fn_f008e150;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f008e150 {
class CStageCondition_153e70;
class ParamValue_153e70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153e70 : public ParamValue_153e70 {
  public:
    int pad;
};
class CStageCondition_153ec0;
class ParamValue_153ec0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153ec0 : public ParamValue_153ec0 {
  public:
    int pad;
};
class CStageCondition_153f10;
class ParamValue_153f10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153f10 : public ParamValue_153f10 {
  public:
    int pad;
};

} // namespace fn_f008e150

// 0x00153e50 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_6 (26 B): matches/0x00153e50.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::**)(int))&this->f_10))(b);
}


// 0x00153e70 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_2 (11 B): matches/0x00153e70.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153ea0 fight::ParamBool<hulkfight::motion::HitPushbackTrack>::vfunc_6 (26 B): matches/0x00153ea0.cpp
// sym: ?vfunc_6@?$ParamBool@VHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitPushbackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HitPushbackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HitPushbackTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HitPushbackTrack>::**)(int))&this->f_10))(b);
}


// 0x00153ec0 fight::ParamBool<hulkfight::motion::HitPushbackTrack>::vfunc_2 (11 B): matches/0x00153ec0.cpp
// sym: ?vfunc_2@?$ParamBool@VHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitPushbackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153ef0 fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_6 (26 B): matches/0x00153ef0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::**)(int))&this->f_10))(b);
}


// 0x00153f10 fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_2 (11 B): matches/0x00153f10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitPushbackTrack>::vfunc_2() {
    return this->f_10 == 0;
}

