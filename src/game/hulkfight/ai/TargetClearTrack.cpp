// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001276f0..0x00127880 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f047cfc1 {
#define TREE_TU_END }
namespace fn_f047cfc1 {} using namespace fn_f047cfc1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f047cfc1 {
class CStageCondition_127710;
class ParamValue_127710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127710 : public ParamValue_127710 {
  public:
    int pad;
};
class CStageCondition_127760;
class ParamValue_127760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127760 : public ParamValue_127760 {
  public:
    int pad;
};
class CStageCondition_1277b0;
class ParamValue_1277b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1277b0 : public ParamValue_1277b0 {
  public:
    int pad;
};
class CStageCondition_127800;
class ParamValue_127800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127800 : public ParamValue_127800 {
  public:
    int pad;
};
class CStageCondition_127850;
class ParamValue_127850 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127850 : public ParamValue_127850 {
  public:
    int pad;
};

} // namespace fn_f047cfc1

// 0x001276f0 fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::vfunc_6 (26 B): matches/0x001276f0.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::**)(int))&this->f_10))(b);
}


// 0x00127710 fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::vfunc_2 (11 B): matches/0x00127710.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetFirstShotCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127740 fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::vfunc_6 (26 B): matches/0x00127740.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::**)(int))&this->f_10))(b);
}


// 0x00127760 fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::vfunc_2 (11 B): matches/0x00127760.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetInvincibleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127790 fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::vfunc_6 (26 B): matches/0x00127790.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x001277b0 fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::vfunc_2 (11 B): matches/0x001277b0.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::CanSeeTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001277e0 fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::vfunc_6 (26 B): matches/0x001277e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetClearTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::**)(int))&this->f_10))(b);
}


// 0x00127800 fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::vfunc_2 (11 B): matches/0x00127800.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetClearTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127830 fight::ParamBool<hulkfight::ai::TargetClearTrack>::vfunc_6 (26 B): matches/0x00127830.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetClearTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetClearTrack>::**)(int))&this->f_10))(b);
}


// 0x00127850 fight::ParamBool<hulkfight::ai::TargetClearTrack>::vfunc_2 (11 B): matches/0x00127850.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetFirstShotCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}

