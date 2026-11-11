// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178460..0x00178500 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1acc222 {
#define TREE_TU_END }
namespace fn_f1acc222 {} using namespace fn_f1acc222;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1acc222 {
class CStageCondition_178480;
class ParamValue_178480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178480 : public ParamValue_178480 {
  public:
    int pad;
};
class CStageCondition_1784d0;
class ParamValue_1784d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1784d0 : public ParamValue_1784d0 {
  public:
    int pad;
};

} // namespace fn_f1acc222

// 0x00178460 fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::vfunc_6 (26 B): matches/0x00178460.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTeleportTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::**)(int))&this->f_10))(b);
}


// 0x00178480 fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::vfunc_2 (11 B): matches/0x00178480.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTeleportTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TeleportTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001784b0 fight::ParamVector<hulkfight::motion::TeleportTrack>::vfunc_6 (26 B): matches/0x001784b0.cpp
// sym: ?vfunc_6@?$ParamVector@VTeleportTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TeleportTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::TeleportTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::TeleportTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::TeleportTrack>::**)(int))&this->f_10))(b);
}


// 0x001784d0 fight::ParamVector<hulkfight::motion::TeleportTrack>::vfunc_2 (11 B): matches/0x001784d0.cpp
// sym: ?vfunc_2@?$ParamVector@VTeleportTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TeleportTrack>::vfunc_2() {
    return this->f_10 == 0;
}

