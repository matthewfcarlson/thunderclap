// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001788b0..0x00178950 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportRelativeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f44b3742 {
#define TREE_TU_END }
namespace fn_f44b3742 {} using namespace fn_f44b3742;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f44b3742 {
class CStageCondition_1788d0;
class ParamValue_1788d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1788d0 : public ParamValue_1788d0 {
  public:
    int pad;
};
class CStageCondition_178920;
class ParamValue_178920 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178920 : public ParamValue_178920 {
  public:
    int pad;
};

} // namespace fn_f44b3742

// 0x001788b0 fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::vfunc_6 (26 B): matches/0x001788b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::**)(int))&this->f_10))(b);
}


// 0x001788d0 fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::vfunc_2 (11 B): matches/0x001788d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TeleportRelativeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178900 fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::vfunc_6 (26 B): matches/0x00178900.cpp
// sym: ?vfunc_6@?$ParamVector@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::**)(int))&this->f_10))(b);
}


// 0x00178920 fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::vfunc_2 (11 B): matches/0x00178920.cpp
// sym: ?vfunc_2@?$ParamVector@VTeleportRelativeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TeleportRelativeTrack>::vfunc_2() {
    return this->f_10 == 0;
}

