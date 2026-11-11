// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177690..0x00177860 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4eb6e53 {
#define TREE_TU_END }
namespace fn_f4eb6e53 {} using namespace fn_f4eb6e53;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4eb6e53 {
class CStageCondition_1776b0;
class ParamValue_1776b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1776b0 : public ParamValue_1776b0 {
  public:
    int pad;
};
class CStageCondition_177700;
class ParamValue_177700 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177700 : public ParamValue_177700 {
  public:
    int pad;
};
class CStageCondition_177750;
class ParamValue_177750 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177750 : public ParamValue_177750 {
  public:
    int pad;
};
struct CAxisArcCondition_177790;
class CStageCondition_1777a0 {};
class ParamValue_1777a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1777a0 : public ParamValue_1777a0 {
  public:
    virtual void f();
};
class CStageCondition_177830;
class ParamValue_177830 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177830 : public ParamValue_177830 {
  public:
    int pad;
};

} // namespace fn_f4eb6e53

// 0x00177690 fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_6 (26 B): matches/0x00177690.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x001776b0 fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_2 (11 B): matches/0x001776b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001776e0 fight::ParamVector<hulkfight::motion::JointTrackerTrack>::vfunc_6 (26 B): matches/0x001776e0.cpp
// sym: ?vfunc_6@?$ParamVector@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::JointTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::JointTrackerTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x00177700 fight::ParamVector<hulkfight::motion::JointTrackerTrack>::vfunc_2 (11 B): matches/0x00177700.cpp
// sym: ?vfunc_2@?$ParamVector@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::JointTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177730 fight::ParamBool<hulkfight::motion::JointTrackerTrack>::vfunc_6 (26 B): matches/0x00177730.cpp
// sym: ?vfunc_6@?$ParamBool@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::JointTrackerTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x00177750 fight::ParamBool<hulkfight::motion::JointTrackerTrack>::vfunc_2 (11 B): matches/0x00177750.cpp
// sym: ?vfunc_2@?$ParamBool@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00177790 fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_7 (6 B): matches/0x00177790.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001777a0 fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_6 (30 B): matches/0x001777a0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1777a0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1777a0*)&DAT_003f335c));
}


// 0x001777c0 fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_8 (26 B): matches/0x001777c0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_18))(b);
}


// 0x001777e0 fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_2 (11 B): matches/0x001777e0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::JointTrackerTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00177810 fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_6 (26 B): matches/0x00177810.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x00177830 fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_2 (11 B): matches/0x00177830.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VJointTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}

