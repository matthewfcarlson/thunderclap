// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186190..0x00186280 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainSpinTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9bf0e4c {
#define TREE_TU_END }
namespace fn_f9bf0e4c {} using namespace fn_f9bf0e4c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9bf0e4c {
class CStageCondition_1861b0;
class ParamValue_1861b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1861b0 : public ParamValue_1861b0 {
  public:
    int pad;
};
class CStageCondition_186200;
class ParamValue_186200 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186200 : public ParamValue_186200 {
  public:
    int pad;
};
class CStageCondition_186250;
class ParamValue_186250 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186250 : public ParamValue_186250 {
  public:
    int pad;
};

} // namespace fn_f9bf0e4c

// 0x00186190 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_6 (26 B): matches/0x00186190.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::**)(int))&this->f_10))(b);
}


// 0x001861b0 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2 (11 B): matches/0x001861b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001861e0 fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_6 (26 B): matches/0x001861e0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::**)(int))&this->f_10))(b);
}


// 0x00186200 fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2 (11 B): matches/0x00186200.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186230 fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::vfunc_6 (26 B): matches/0x00186230.cpp
// sym: ?vfunc_6@?$ParamVector@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::**)(int))&this->f_10))(b);
}


// 0x00186250 fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2 (11 B): matches/0x00186250.cpp
// sym: ?vfunc_2@?$ParamVector@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::BallAndChainSpinTrack>::vfunc_2() {
    return this->f_10 == 0;
}

