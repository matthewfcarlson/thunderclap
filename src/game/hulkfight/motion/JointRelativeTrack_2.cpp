// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177a30..0x00177bc0 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointRelativeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8b1fffd {
#define TREE_TU_END }
namespace fn_f8b1fffd {} using namespace fn_f8b1fffd;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f8b1fffd {
class CStageCondition_177a50;
class ParamValue_177a50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177a50 : public ParamValue_177a50 {
  public:
    int pad;
};
class CStageCondition_177aa0;
class ParamValue_177aa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177aa0 : public ParamValue_177aa0 {
  public:
    int pad;
};
class CStageCondition_177af0;
class ParamValue_177af0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177af0 : public ParamValue_177af0 {
  public:
    int pad;
};
class CStageCondition_177b40;
class ParamValue_177b40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177b40 : public ParamValue_177b40 {
  public:
    int pad;
};
class CStageCondition_177b90;
class ParamValue_177b90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177b90 : public ParamValue_177b90 {
  public:
    int pad;
};

} // namespace fn_f8b1fffd

// 0x00177a30 fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::vfunc_6 (26 B): matches/0x00177a30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::**)(int))&this->f_10))(b);
}


// 0x00177a50 fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::vfunc_2 (11 B): matches/0x00177a50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::SnapToGroundTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177a80 fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_6 (26 B): matches/0x00177a80.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))(b);
}


// 0x00177aa0 fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_2 (11 B): matches/0x00177aa0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSnapToGroundTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177ad0 fight::ParamBool<hulkfight::motion::JointRelativeTrack>::vfunc_6 (26 B): matches/0x00177ad0.cpp
// sym: ?vfunc_6@?$ParamBool@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointRelativeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::JointRelativeTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))(b);
}


// 0x00177af0 fight::ParamBool<hulkfight::motion::JointRelativeTrack>::vfunc_2 (11 B): matches/0x00177af0.cpp
// sym: ?vfunc_2@?$ParamBool@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointRelativeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177b20 fight::ParamVector<hulkfight::motion::JointRelativeTrack>::vfunc_6 (26 B): matches/0x00177b20.cpp
// sym: ?vfunc_6@?$ParamVector@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::JointRelativeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::JointRelativeTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))(b);
}


// 0x00177b40 fight::ParamVector<hulkfight::motion::JointRelativeTrack>::vfunc_2 (11 B): matches/0x00177b40.cpp
// sym: ?vfunc_2@?$ParamVector@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::JointRelativeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177b70 fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_6 (26 B): matches/0x00177b70.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::**)(int))&this->f_10))(b);
}


// 0x00177b90 fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_2 (11 B): matches/0x00177b90.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VJointRelativeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::JointRelativeTrack>::vfunc_2() {
    return this->f_10 == 0;
}

