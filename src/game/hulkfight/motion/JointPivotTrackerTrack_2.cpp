// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178500..0x001786d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::JointPivotTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f160d4ef {
#define TREE_TU_END }
namespace fn_f160d4ef {} using namespace fn_f160d4ef;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f160d4ef {
class CStageCondition_178520;
class ParamValue_178520 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178520 : public ParamValue_178520 {
  public:
    int pad;
};
class CStageCondition_178570;
class ParamValue_178570 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178570 : public ParamValue_178570 {
  public:
    int pad;
};
class CStageCondition_1785c0;
class ParamValue_1785c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1785c0 : public ParamValue_1785c0 {
  public:
    int pad;
};
struct CAxisArcCondition_178600;
class CStageCondition_178610 {};
class ParamValue_178610 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_178610 : public ParamValue_178610 {
  public:
    virtual void f();
};
class CStageCondition_1786a0;
class ParamValue_1786a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1786a0 : public ParamValue_1786a0 {
  public:
    int pad;
};

} // namespace fn_f160d4ef

// 0x00178500 fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6 (26 B): matches/0x00178500.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x00178520 fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2 (11 B): matches/0x00178520.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178550 fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6 (26 B): matches/0x00178550.cpp
// sym: ?vfunc_6@?$ParamVector@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x00178570 fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2 (11 B): matches/0x00178570.cpp
// sym: ?vfunc_2@?$ParamVector@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001785a0 fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6 (26 B): matches/0x001785a0.cpp
// sym: ?vfunc_6@?$ParamBool@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x001785c0 fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2 (11 B): matches/0x001785c0.cpp
// sym: ?vfunc_2@?$ParamBool@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178600 fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_7 (6 B): matches/0x00178600.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00178610 fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6 (30 B): matches/0x00178610.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_178610 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_178610*)&DAT_003f335c));
}


// 0x00178630 fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_8 (26 B): matches/0x00178630.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_18))(b);
}


// 0x00178650 fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2 (11 B): matches/0x00178650.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00178680 fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6 (26 B): matches/0x00178680.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x001786a0 fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2 (11 B): matches/0x001786a0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VJointPivotTrackerTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::JointPivotTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}

