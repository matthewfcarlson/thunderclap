// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001539f0..0x00153a90 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8b55d83 {
#define TREE_TU_END }
namespace fn_f8b55d83 {} using namespace fn_f8b55d83;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8b55d83 {
class CStageCondition_153a10;
class ParamValue_153a10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153a10 : public ParamValue_153a10 {
  public:
    int pad;
};
class CStageCondition_153a60;
class ParamValue_153a60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153a60 : public ParamValue_153a60 {
  public:
    int pad;
};

} // namespace fn_f8b55d83

// 0x001539f0 fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_6 (26 B): matches/0x001539f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::**)(int))&this->f_10))(b);
}


// 0x00153a10 fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_2 (11 B): matches/0x00153a10.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153a40 fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_6 (26 B): matches/0x00153a40.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::**)(int))&this->f_10))(b);
}


// 0x00153a60 fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_2 (11 B): matches/0x00153a60.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VInterruptPriorityTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack>::vfunc_2() {
    return this->f_10 == 0;
}

