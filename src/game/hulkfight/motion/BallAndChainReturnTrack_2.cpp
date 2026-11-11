// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185e80..0x00185f70 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainReturnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4195b7e {
#define TREE_TU_END }
namespace fn_f4195b7e {} using namespace fn_f4195b7e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4195b7e {
class CStageCondition_185ea0;
class ParamValue_185ea0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185ea0 : public ParamValue_185ea0 {
  public:
    int pad;
};
class CStageCondition_185ef0;
class ParamValue_185ef0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185ef0 : public ParamValue_185ef0 {
  public:
    int pad;
};
class CStageCondition_185f40;
class ParamValue_185f40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185f40 : public ParamValue_185f40 {
  public:
    int pad;
};

} // namespace fn_f4195b7e

// 0x00185e80 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_6 (26 B): matches/0x00185e80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::**)(int))&this->f_10))(b);
}


// 0x00185ea0 fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2 (11 B): matches/0x00185ea0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185ed0 fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_6 (26 B): matches/0x00185ed0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::**)(int))&this->f_10))(b);
}


// 0x00185ef0 fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2 (11 B): matches/0x00185ef0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185f20 fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::vfunc_6 (26 B): matches/0x00185f20.cpp
// sym: ?vfunc_6@?$ParamVector@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::**)(int))&this->f_10))(b);
}


// 0x00185f40 fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2 (11 B): matches/0x00185f40.cpp
// sym: ?vfunc_2@?$ParamVector@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::BallAndChainReturnTrack>::vfunc_2() {
    return this->f_10 == 0;
}

