// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177ed0..0x00178010 (kind game, layer game, confidence high), dominant class hulkfight::motion::MoveJointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd8b5cc0 {
#define TREE_TU_END }
namespace fn_fd8b5cc0 {} using namespace fn_fd8b5cc0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd8b5cc0 {
class CStageCondition_177ef0;
class ParamValue_177ef0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177ef0 : public ParamValue_177ef0 {
  public:
    int pad;
};
class CStageCondition_177f40;
class ParamValue_177f40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177f40 : public ParamValue_177f40 {
  public:
    int pad;
};
class CStageCondition_177f90;
class ParamValue_177f90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177f90 : public ParamValue_177f90 {
  public:
    int pad;
};
class CStageCondition_177fe0;
class ParamValue_177fe0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177fe0 : public ParamValue_177fe0 {
  public:
    int pad;
};

} // namespace fn_fd8b5cc0

// 0x00177ed0 fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::vfunc_6 (26 B): matches/0x00177ed0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))(b);
}


// 0x00177ef0 fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::vfunc_2 (11 B): matches/0x00177ef0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MoveJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177f20 fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::vfunc_6 (26 B): matches/0x00177f20.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))(b);
}


// 0x00177f40 fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::vfunc_2 (11 B): matches/0x00177f40.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::MoveJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177f70 fight::ParamVector<hulkfight::motion::MoveJointTrack>::vfunc_6 (26 B): matches/0x00177f70.cpp
// sym: ?vfunc_6@?$ParamVector@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::MoveJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::MoveJointTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))(b);
}


// 0x00177f90 fight::ParamVector<hulkfight::motion::MoveJointTrack>::vfunc_2 (11 B): matches/0x00177f90.cpp
// sym: ?vfunc_2@?$ParamVector@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::MoveJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177fc0 fight::ParamBool<hulkfight::motion::MoveJointTrack>::vfunc_6 (26 B): matches/0x00177fc0.cpp
// sym: ?vfunc_6@?$ParamBool@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::MoveJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::MoveJointTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::MoveJointTrack>::**)(int))&this->f_10))(b);
}


// 0x00177fe0 fight::ParamBool<hulkfight::motion::MoveJointTrack>::vfunc_2 (11 B): matches/0x00177fe0.cpp
// sym: ?vfunc_2@?$ParamBool@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::MoveJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}

