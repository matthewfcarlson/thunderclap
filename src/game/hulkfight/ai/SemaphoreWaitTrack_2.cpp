// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110da0..0x00110e60 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc121c25 {
#define TREE_TU_END }
namespace fn_fc121c25 {} using namespace fn_fc121c25;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fc121c25 {
class CStageCondition_110dc0;
class ParamValue_110dc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110dc0 : public ParamValue_110dc0 {
  public:
    int pad;
};
class CStageCondition_110e40;
class ParamValue_110e40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110e40 : public ParamValue_110e40 {
  public:
    int pad;
};

} // namespace fn_fc121c25

// 0x00110da0 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::vfunc_6 (26 B): matches/0x00110da0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::**)(int))&this->f_10))(b);
}


// 0x00110dc0 fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::vfunc_2 (11 B): matches/0x00110dc0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::SemaphoreWaitTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fc121c25 {

// 0x00110df0 fight::ParamName<hulkfight::ai::SemaphoreWaitTrack>::vfunc_7 (12 B): matches/0x00110df0.cpp
// sym: ?vfunc_6@ParamBranch@fn_fc121c25@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fc121c25

// 0x00110e20 fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::vfunc_6 (26 B): matches/0x00110e20.cpp
// sym: ?vfunc_6@?$ParamBool@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::**)(int))&this->f_10))(b);
}


// 0x00110e40 fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::vfunc_2 (11 B): matches/0x00110e40.cpp
// sym: ?vfunc_2@?$ParamBool@VSemaphoreWaitTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::SemaphoreWaitTrack>::vfunc_2() {
    return this->f_10 == 0;
}

