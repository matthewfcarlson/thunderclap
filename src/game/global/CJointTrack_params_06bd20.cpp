// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006bd20..0x0006be60 (kind game, layer game, confidence high), dominant class CJointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f81309e6 {
#define TREE_TU_END }
namespace fn_f81309e6 {} using namespace fn_f81309e6;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f81309e6 {
class CStageCondition_6bd40;
class ParamValue_6bd40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bd40 : public ParamValue_6bd40 {
  public:
    int pad;
};
class CStageCondition_6bd90;
class ParamValue_6bd90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bd90 : public ParamValue_6bd90 {
  public:
    int pad;
};
class CStageCondition_6bde0;
class ParamValue_6bde0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bde0 : public ParamValue_6bde0 {
  public:
    int pad;
};
class CStageCondition_6be30;
class ParamValue_6be30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6be30 : public ParamValue_6be30 {
  public:
    int pad;
};

} // namespace fn_f81309e6

// 0x0006bd20 fight::ParamFloatConstRange<CJointTrack>::vfunc_6 (26 B): matches/0x0006bd20.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCJointTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CJointTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CJointTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bd40 fight::ParamFloatConstRange<CJointTrack>::vfunc_2 (11 B): matches/0x0006bd40.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCJointTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006bd70 fight::ParamBool<CJointTrack>::vfunc_6 (26 B): matches/0x0006bd70.cpp
// sym: ?vfunc_6@?$ParamBool@VCJointTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CJointTrack>*)a)->*(*(bool (fight::ParamBool<CJointTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bd90 fight::ParamBool<CJointTrack>::vfunc_2 (11 B): matches/0x0006bd90.cpp
// sym: ?vfunc_2@?$ParamBool@VCJointTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006bdc0 fight::ParamVector<CJointTrack>::vfunc_6 (26 B): matches/0x0006bdc0.cpp
// sym: ?vfunc_6@?$ParamVector@VCJointTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CJointTrack>*)a)->*(*(bool (fight::ParamVector<CJointTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bde0 fight::ParamVector<CJointTrack>::vfunc_2 (11 B): matches/0x0006bde0.cpp
// sym: ?vfunc_2@?$ParamVector@VCJointTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006be10 fight::ParamIntConstRange<CJointTrack>::vfunc_6 (26 B): matches/0x0006be10.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCJointTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CJointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CJointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CJointTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CJointTrack>::**)(int))&this->f_10))(b);
}


// 0x0006be30 fight::ParamIntConstRange<CJointTrack>::vfunc_2 (11 B): matches/0x0006be30.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCJointTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}

