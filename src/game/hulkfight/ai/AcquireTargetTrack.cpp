// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127880..0x00127970 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f190d24b {
#define TREE_TU_END }
namespace fn_f190d24b {} using namespace fn_f190d24b;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f190d24b {
class CStageCondition_1278a0;
class ParamValue_1278a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1278a0 : public ParamValue_1278a0 {
  public:
    int pad;
};
class CStageCondition_1278f0;
class ParamValue_1278f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1278f0 : public ParamValue_1278f0 {
  public:
    int pad;
};
class CStageCondition_127940;
class ParamValue_127940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127940 : public ParamValue_127940 {
  public:
    int pad;
};

} // namespace fn_f190d24b

// 0x00127880 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::vfunc_6 (26 B): matches/0x00127880.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x001278a0 fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::vfunc_2 (11 B): matches/0x001278a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::AcquireTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001278d0 fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::vfunc_6 (26 B): matches/0x001278d0.cpp
// sym: ?vfunc_6@?$ParamBool@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::AcquireTargetTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x001278f0 fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::vfunc_2 (11 B): matches/0x001278f0.cpp
// sym: ?vfunc_2@?$ParamBool@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::AcquireTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127920 fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_6 (26 B): matches/0x00127920.cpp
// sym: ?vfunc_6@?$ParamVector@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::AcquireTargetTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x00127940 fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_2 (11 B): matches/0x00127940.cpp
// sym: ?vfunc_2@?$ParamVector@VAcquireTargetTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}

