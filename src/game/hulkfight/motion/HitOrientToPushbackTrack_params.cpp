// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153a90..0x00153b30 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitOrientToPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbdf01c2 {
#define TREE_TU_END }
namespace fn_fbdf01c2 {} using namespace fn_fbdf01c2;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fbdf01c2 {
class CStageCondition_153ab0;
class ParamValue_153ab0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153ab0 : public ParamValue_153ab0 {
  public:
    int pad;
};
class CStageCondition_153b00;
class ParamValue_153b00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153b00 : public ParamValue_153b00 {
  public:
    int pad;
};

} // namespace fn_fbdf01c2

// 0x00153a90 fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_6 (26 B): matches/0x00153a90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::**)(int))&this->f_10))(b);
}


// 0x00153ab0 fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_2 (11 B): matches/0x00153ab0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153ae0 fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_6 (26 B): matches/0x00153ae0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::**)(int))&this->f_10))(b);
}


// 0x00153b00 fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_2 (11 B): matches/0x00153b00.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_2() {
    return this->f_10 == 0;
}

