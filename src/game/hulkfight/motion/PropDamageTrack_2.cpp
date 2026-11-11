// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186460..0x00186500 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5f6afdd {
#define TREE_TU_END }
namespace fn_f5f6afdd {} using namespace fn_f5f6afdd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5f6afdd {
class CStageCondition_186480;
class ParamValue_186480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186480 : public ParamValue_186480 {
  public:
    int pad;
};
class CStageCondition_1864d0;
class ParamValue_1864d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1864d0 : public ParamValue_1864d0 {
  public:
    int pad;
};

} // namespace fn_f5f6afdd

// 0x00186460 fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::vfunc_6 (26 B): matches/0x00186460.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00186480 fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::vfunc_2 (11 B): matches/0x00186480.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001864b0 fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::vfunc_6 (26 B): matches/0x001864b0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x001864d0 fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::vfunc_2 (11 B): matches/0x001864d0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}

