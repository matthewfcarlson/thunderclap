// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153b30..0x00153c20 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitFloatTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9e0140f {
#define TREE_TU_END }
namespace fn_f9e0140f {} using namespace fn_f9e0140f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9e0140f {
class CStageCondition_153b50;
class ParamValue_153b50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153b50 : public ParamValue_153b50 {
  public:
    int pad;
};
class CStageCondition_153ba0;
class ParamValue_153ba0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153ba0 : public ParamValue_153ba0 {
  public:
    int pad;
};
class CStageCondition_153bf0;
class ParamValue_153bf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153bf0 : public ParamValue_153bf0 {
  public:
    int pad;
};

} // namespace fn_f9e0140f

// 0x00153b30 fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::vfunc_6 (26 B): matches/0x00153b30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::**)(int))&this->f_10))(b);
}


// 0x00153b50 fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::vfunc_2 (11 B): matches/0x00153b50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitFloatTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153b80 fight::ParamBool<hulkfight::motion::HitFloatTrack>::vfunc_6 (26 B): matches/0x00153b80.cpp
// sym: ?vfunc_6@?$ParamBool@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitFloatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HitFloatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HitFloatTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HitFloatTrack>::**)(int))&this->f_10))(b);
}


// 0x00153ba0 fight::ParamBool<hulkfight::motion::HitFloatTrack>::vfunc_2 (11 B): matches/0x00153ba0.cpp
// sym: ?vfunc_2@?$ParamBool@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitFloatTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153bd0 fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::vfunc_6 (26 B): matches/0x00153bd0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::**)(int))&this->f_10))(b);
}


// 0x00153bf0 fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::vfunc_2 (11 B): matches/0x00153bf0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitFloatTrack>::vfunc_2() {
    return this->f_10 == 0;
}

