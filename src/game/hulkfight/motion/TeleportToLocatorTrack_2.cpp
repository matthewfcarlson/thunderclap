// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178950..0x00178a90 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportToLocatorTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f862ca66 {
#define TREE_TU_END }
namespace fn_f862ca66 {} using namespace fn_f862ca66;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f862ca66 {
class CStageCondition_178970;
class ParamValue_178970 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178970 : public ParamValue_178970 {
  public:
    int pad;
};
class CStageCondition_1789c0;
class ParamValue_1789c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1789c0 : public ParamValue_1789c0 {
  public:
    int pad;
};
class CStageCondition_178a10;
class ParamValue_178a10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178a10 : public ParamValue_178a10 {
  public:
    int pad;
};
class CStageCondition_178a60;
class ParamValue_178a60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178a60 : public ParamValue_178a60 {
  public:
    int pad;
};

} // namespace fn_f862ca66

// 0x00178950 fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::vfunc_6 (26 B): matches/0x00178950.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VIntentionClearTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::**)(int))&this->f_10))(b);
}


// 0x00178970 fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::vfunc_2 (11 B): matches/0x00178970.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VIntentionClearTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::IntentionClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001789a0 fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::vfunc_6 (26 B): matches/0x001789a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VIntentionClearTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x001789c0 fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2 (11 B): matches/0x001789c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VIntentionClearTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001789f0 fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::vfunc_6 (26 B): matches/0x001789f0.cpp
// sym: ?vfunc_6@?$ParamString@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x00178a10 fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2 (11 B): matches/0x00178a10.cpp
// sym: ?vfunc_2@?$ParamString@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178a40 fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::vfunc_6 (26 B): matches/0x00178a40.cpp
// sym: ?vfunc_6@?$ParamVector@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x00178a60 fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2 (11 B): matches/0x00178a60.cpp
// sym: ?vfunc_2@?$ParamVector@VTeleportToLocatorTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::TeleportToLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}

