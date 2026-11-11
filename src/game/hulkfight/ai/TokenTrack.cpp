// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110d00..0x00110da0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f30ffc79 {
#define TREE_TU_END }
namespace fn_f30ffc79 {} using namespace fn_f30ffc79;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f30ffc79 {
class CStageCondition_110d20;
class ParamValue_110d20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110d20 : public ParamValue_110d20 {
  public:
    int pad;
};
class CStageCondition_110d70;
class ParamValue_110d70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110d70 : public ParamValue_110d70 {
  public:
    int pad;
};

} // namespace fn_f30ffc79

// 0x00110d00 fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::vfunc_6 (26 B): matches/0x00110d00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTokenTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::**)(int))&this->f_10))(b);
}


// 0x00110d20 fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::vfunc_2 (11 B): matches/0x00110d20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTokenTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TokenTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110d50 fight::ParamBool<hulkfight::ai::TokenTrack>::vfunc_6 (26 B): matches/0x00110d50.cpp
// sym: ?vfunc_6@?$ParamBool@VTokenTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TokenTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TokenTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TokenTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TokenTrack>::**)(int))&this->f_10))(b);
}


// 0x00110d70 fight::ParamBool<hulkfight::ai::TokenTrack>::vfunc_2 (11 B): matches/0x00110d70.cpp
// sym: ?vfunc_2@?$ParamBool@VTokenTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TokenTrack>::vfunc_2() {
    return this->f_10 == 0;
}

