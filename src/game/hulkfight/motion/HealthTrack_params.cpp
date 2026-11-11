// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153c20..0x00153d60 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7c7b9d6 {
#define TREE_TU_END }
namespace fn_f7c7b9d6 {} using namespace fn_f7c7b9d6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f7c7b9d6 {
class CStageCondition_153c40;
class ParamValue_153c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153c40 : public ParamValue_153c40 {
  public:
    int pad;
};
class CStageCondition_153c90;
class ParamValue_153c90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153c90 : public ParamValue_153c90 {
  public:
    int pad;
};
class CStageCondition_153ce0;
class ParamValue_153ce0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153ce0 : public ParamValue_153ce0 {
  public:
    int pad;
};
class CStageCondition_153d30;
class ParamValue_153d30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153d30 : public ParamValue_153d30 {
  public:
    int pad;
};

} // namespace fn_f7c7b9d6

// 0x00153c20 fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_6 (26 B): matches/0x00153c20.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::**)(int))&this->f_10))(b);
}


// 0x00153c40 fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_2 (11 B): matches/0x00153c40.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153c70 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::vfunc_6 (26 B): matches/0x00153c70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::**)(int))&this->f_10))(b);
}


// 0x00153c90 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::vfunc_2 (11 B): matches/0x00153c90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPushbackAddTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153cc0 fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::vfunc_6 (26 B): matches/0x00153cc0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::**)(int))&this->f_10))(b);
}


// 0x00153ce0 fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::vfunc_2 (11 B): matches/0x00153ce0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VClearFightParamsHitRecordTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HealthTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153d10 fight::ParamBool<hulkfight::motion::HealthTrack>::vfunc_6 (26 B): matches/0x00153d10.cpp
// sym: ?vfunc_6@?$ParamBool@VHealthTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HealthTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HealthTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HealthTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HealthTrack>::**)(int))&this->f_10))(b);
}


// 0x00153d30 fight::ParamBool<hulkfight::motion::HealthTrack>::vfunc_2 (11 B): matches/0x00153d30.cpp
// sym: ?vfunc_2@?$ParamBool@VHealthTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HealthTrack>::vfunc_2() {
    return this->f_10 == 0;
}

