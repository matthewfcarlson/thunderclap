// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110910..0x001109b0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenSupressTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa6dc583 {
#define TREE_TU_END }
namespace fn_fa6dc583 {} using namespace fn_fa6dc583;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fa6dc583 {
class CStageCondition_110930;
class ParamValue_110930 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110930 : public ParamValue_110930 {
  public:
    int pad;
};
class CStageCondition_110980;
class ParamValue_110980 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110980 : public ParamValue_110980 {
  public:
    int pad;
};

} // namespace fn_fa6dc583

// 0x00110910 fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::vfunc_6 (26 B): matches/0x00110910.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTokenSupressTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::**)(int))&this->f_10))(b);
}


// 0x00110930 fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::vfunc_2 (11 B): matches/0x00110930.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTokenSupressTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TokenSupressTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110960 fight::ParamBool<hulkfight::ai::TokenSupressTrack>::vfunc_6 (26 B): matches/0x00110960.cpp
// sym: ?vfunc_6@?$ParamBool@VTokenSupressTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TokenSupressTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TokenSupressTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TokenSupressTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TokenSupressTrack>::**)(int))&this->f_10))(b);
}


// 0x00110980 fight::ParamBool<hulkfight::ai::TokenSupressTrack>::vfunc_2 (11 B): matches/0x00110980.cpp
// sym: ?vfunc_2@?$ParamBool@VTokenSupressTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TokenSupressTrack>::vfunc_2() {
    return this->f_10 == 0;
}

