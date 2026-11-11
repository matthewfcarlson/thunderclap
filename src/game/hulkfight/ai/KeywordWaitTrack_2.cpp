// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110a80..0x00110b50 (kind game, layer game, confidence high), dominant class hulkfight::ai::KeywordWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3fd7430 {
#define TREE_TU_END }
namespace fn_f3fd7430 {} using namespace fn_f3fd7430;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f3fd7430 {
class CStageCondition_110aa0;
class ParamValue_110aa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110aa0 : public ParamValue_110aa0 {
  public:
    int pad;
};
class CStageCondition_110b20;
class ParamValue_110b20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110b20 : public ParamValue_110b20 {
  public:
    int pad;
};

} // namespace fn_f3fd7430

// 0x00110a80 fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::vfunc_6 (26 B): matches/0x00110a80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::**)(int))&this->f_10))(b);
}


// 0x00110aa0 fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::vfunc_2 (11 B): matches/0x00110aa0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::KeywordWaitTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f3fd7430 {

// 0x00110ad0 fight::ParamName<hulkfight::ai::KeywordWaitTrack>::vfunc_7 (12 B): matches/0x00110ad0.cpp
// sym: ?vfunc_6@ParamBranch@fn_f3fd7430@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f3fd7430

// 0x00110b00 fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::vfunc_6 (26 B): matches/0x00110b00.cpp
// sym: ?vfunc_6@?$ParamBool@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::KeywordWaitTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::**)(int))&this->f_10))(b);
}


// 0x00110b20 fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::vfunc_2 (11 B): matches/0x00110b20.cpp
// sym: ?vfunc_2@?$ParamBool@VKeywordWaitTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::KeywordWaitTrack>::vfunc_2() {
    return this->f_10 == 0;
}

