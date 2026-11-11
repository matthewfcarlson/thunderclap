// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178010..0x00178150 (kind game, layer game, confidence high), dominant class hulkfight::motion::DriftToPositionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4f6aae0 {
#define TREE_TU_END }
namespace fn_f4f6aae0 {} using namespace fn_f4f6aae0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4f6aae0 {
class CStageCondition_178030;
class ParamValue_178030 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178030 : public ParamValue_178030 {
  public:
    int pad;
};
class CStageCondition_178080;
class ParamValue_178080 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178080 : public ParamValue_178080 {
  public:
    int pad;
};
class CStageCondition_1780d0;
class ParamValue_1780d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1780d0 : public ParamValue_1780d0 {
  public:
    int pad;
};
class CStageCondition_178120;
class ParamValue_178120 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178120 : public ParamValue_178120 {
  public:
    int pad;
};

} // namespace fn_f4f6aae0

// 0x00178010 fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::vfunc_6 (26 B): matches/0x00178010.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))(b);
}


// 0x00178030 fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::vfunc_2 (11 B): matches/0x00178030.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::DriftToPositionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178060 fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::vfunc_6 (26 B): matches/0x00178060.cpp
// sym: ?vfunc_6@?$ParamBool@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::DriftToPositionTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))(b);
}


// 0x00178080 fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::vfunc_2 (11 B): matches/0x00178080.cpp
// sym: ?vfunc_2@?$ParamBool@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::DriftToPositionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001780b0 fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::vfunc_6 (26 B): matches/0x001780b0.cpp
// sym: ?vfunc_6@?$ParamVector@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::DriftToPositionTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))(b);
}


// 0x001780d0 fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::vfunc_2 (11 B): matches/0x001780d0.cpp
// sym: ?vfunc_2@?$ParamVector@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::DriftToPositionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178100 fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_6 (26 B): matches/0x00178100.cpp
// sym: ?vfunc_6@?$ParamString@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::motion::DriftToPositionTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::motion::DriftToPositionTrack>::**)(int))&this->f_10))(b);
}


// 0x00178120 fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_2 (11 B): matches/0x00178120.cpp
// sym: ?vfunc_2@?$ParamString@VDriftToPositionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_2() {
    return this->f_10 == 0;
}

