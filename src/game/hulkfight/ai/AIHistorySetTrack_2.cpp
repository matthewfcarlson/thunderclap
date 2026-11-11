// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110c30..0x00110d00 (kind game, layer game, confidence high), dominant class hulkfight::ai::AIHistorySetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f042a41f {
#define TREE_TU_END }
namespace fn_f042a41f {} using namespace fn_f042a41f;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f042a41f {
class CStageCondition_110c50;
class ParamValue_110c50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110c50 : public ParamValue_110c50 {
  public:
    int pad;
};
class CStageCondition_110ca0;
class ParamValue_110ca0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110ca0 : public ParamValue_110ca0 {
  public:
    int pad;
};

} // namespace fn_f042a41f

// 0x00110c30 fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::vfunc_6 (26 B): matches/0x00110c30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::**)(int))&this->f_10))(b);
}


// 0x00110c50 fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::vfunc_2 (11 B): matches/0x00110c50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AIHistorySetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110c80 fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::vfunc_6 (26 B): matches/0x00110c80.cpp
// sym: ?vfunc_6@?$ParamBool@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::AIHistorySetTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::**)(int))&this->f_10))(b);
}


// 0x00110ca0 fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::vfunc_2 (11 B): matches/0x00110ca0.cpp
// sym: ?vfunc_2@?$ParamBool@VAIHistorySetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::AIHistorySetTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f042a41f {

// 0x00110cd0 fight::ParamName<hulkfight::ai::AIHistorySetTrack>::vfunc_7 (12 B): matches/0x00110cd0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f042a41f@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f042a41f
