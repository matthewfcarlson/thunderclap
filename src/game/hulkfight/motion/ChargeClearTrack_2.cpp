// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178a90..0x00178b30 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2f22c80 {
#define TREE_TU_END }
namespace fn_f2f22c80 {} using namespace fn_f2f22c80;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2f22c80 {
class CStageCondition_178ab0;
class ParamValue_178ab0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178ab0 : public ParamValue_178ab0 {
  public:
    int pad;
};
class CStageCondition_178b00;
class ParamValue_178b00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178b00 : public ParamValue_178b00 {
  public:
    int pad;
};

} // namespace fn_f2f22c80

// 0x00178a90 fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::vfunc_6 (26 B): matches/0x00178a90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeClearTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::**)(int))&this->f_10))(b);
}


// 0x00178ab0 fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::vfunc_2 (11 B): matches/0x00178ab0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeClearTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ChargeClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178ae0 fight::ParamBool<hulkfight::motion::ChargeClearTrack>::vfunc_6 (26 B): matches/0x00178ae0.cpp
// sym: ?vfunc_6@?$ParamBool@VChargeClearTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ChargeClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::ChargeClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::ChargeClearTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::ChargeClearTrack>::**)(int))&this->f_10))(b);
}


// 0x00178b00 fight::ParamBool<hulkfight::motion::ChargeClearTrack>::vfunc_2 (11 B): matches/0x00178b00.cpp
// sym: ?vfunc_2@?$ParamBool@VChargeClearTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ChargeClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}

