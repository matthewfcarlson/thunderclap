// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186500..0x001865f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSpawnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8b17bec {
#define TREE_TU_END }
namespace fn_f8b17bec {} using namespace fn_f8b17bec;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8b17bec {
class CStageCondition_186520;
class ParamValue_186520 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186520 : public ParamValue_186520 {
  public:
    int pad;
};
class CStageCondition_186570;
class ParamValue_186570 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186570 : public ParamValue_186570 {
  public:
    int pad;
};
class CStageCondition_1865c0;
class ParamValue_1865c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1865c0 : public ParamValue_1865c0 {
  public:
    int pad;
};

} // namespace fn_f8b17bec

// 0x00186500 fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::vfunc_6 (26 B): matches/0x00186500.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x00186520 fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::vfunc_2 (11 B): matches/0x00186520.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186550 fight::ParamString<hulkfight::motion::PropSpawnTrack>::vfunc_6 (26 B): matches/0x00186550.cpp
// sym: ?vfunc_6@?$ParamString@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::PropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::motion::PropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::motion::PropSpawnTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::motion::PropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x00186570 fight::ParamString<hulkfight::motion::PropSpawnTrack>::vfunc_2 (11 B): matches/0x00186570.cpp
// sym: ?vfunc_2@?$ParamString@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::PropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001865a0 fight::ParamVector<hulkfight::motion::PropSpawnTrack>::vfunc_6 (26 B): matches/0x001865a0.cpp
// sym: ?vfunc_6@?$ParamVector@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::PropSpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::PropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::PropSpawnTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::PropSpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x001865c0 fight::ParamVector<hulkfight::motion::PropSpawnTrack>::vfunc_2 (11 B): matches/0x001865c0.cpp
// sym: ?vfunc_2@?$ParamVector@VPropSpawnTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::PropSpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}

