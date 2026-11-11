// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001865f0..0x00186680 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDestroyTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f776e6f9 {
#define TREE_TU_END }
namespace fn_f776e6f9 {} using namespace fn_f776e6f9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f776e6f9 {
class CStageCondition_186610;
class ParamValue_186610 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186610 : public ParamValue_186610 {
  public:
    int pad;
};
class CStageCondition_186660;
class ParamValue_186660 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186660 : public ParamValue_186660 {
  public:
    int pad;
};

} // namespace fn_f776e6f9

// 0x001865f0 fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_6 (26 B): matches/0x001865f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::**)(int))&this->f_10))(b);
}


// 0x00186610 fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_2 (11 B): matches/0x00186610.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186640 fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_6 (26 B): matches/0x00186640.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::**)(int))&this->f_10))(b);
}


// 0x00186660 fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_2 (11 B): matches/0x00186660.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropDestroyTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropDestroyTrack>::vfunc_2() {
    return this->f_10 == 0;
}

