// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127970..0x00127a00 (kind game, layer game, confidence high), dominant class hulkfight::ai::ClearProjectileDistanceTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8f865db {
#define TREE_TU_END }
namespace fn_f8f865db {} using namespace fn_f8f865db;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f8f865db {
class CStageCondition_127990;
class ParamValue_127990 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127990 : public ParamValue_127990 {
  public:
    int pad;
};
class CStageCondition_1279e0;
class ParamValue_1279e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1279e0 : public ParamValue_1279e0 {
  public:
    int pad;
};

} // namespace fn_f8f865db

// 0x00127970 fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_6 (26 B): matches/0x00127970.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::**)(int))&this->f_10))(b);
}


// 0x00127990 fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_2 (11 B): matches/0x00127990.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001279c0 fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_6 (26 B): matches/0x001279c0.cpp
// sym: ?vfunc_6@?$ParamBool@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::**)(int))&this->f_10))(b);
}


// 0x001279e0 fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_2 (11 B): matches/0x001279e0.cpp
// sym: ?vfunc_2@?$ParamBool@VClearProjectileDistanceTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_2() {
    return this->f_10 == 0;
}

