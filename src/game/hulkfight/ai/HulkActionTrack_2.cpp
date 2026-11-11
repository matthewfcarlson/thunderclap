// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001109b0..0x00110a80 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1475c30 {
#define TREE_TU_END }
namespace fn_f1475c30 {} using namespace fn_f1475c30;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f1475c30 {
class CStageCondition_1109d0;
class ParamValue_1109d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1109d0 : public ParamValue_1109d0 {
  public:
    int pad;
};
class CStageCondition_110a20;
class ParamValue_110a20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110a20 : public ParamValue_110a20 {
  public:
    int pad;
};

} // namespace fn_f1475c30

// 0x001109b0 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::vfunc_6 (26 B): matches/0x001109b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::**)(int))&this->f_10))(b);
}


// 0x001109d0 fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::vfunc_2 (11 B): matches/0x001109d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AIHistoryCountTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110a00 fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::vfunc_6 (26 B): matches/0x00110a00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::**)(int))&this->f_10))(b);
}


// 0x00110a20 fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::vfunc_2 (11 B): matches/0x00110a20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAIHistoryCountTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f1475c30 {

// 0x00110a50 fight::ParamName<hulkfight::ai::HulkActionTrack>::vfunc_7 (12 B): matches/0x00110a50.cpp
// sym: ?vfunc_6@ParamBranch@fn_f1475c30@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f1475c30
