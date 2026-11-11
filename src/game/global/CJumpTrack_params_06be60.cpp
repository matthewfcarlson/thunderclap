// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006be60..0x0006bff0 (kind game, layer game, confidence high), dominant class CJumpTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc6ccd9d {
#define TREE_TU_END }
namespace fn_fc6ccd9d {} using namespace fn_fc6ccd9d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc6ccd9d {
class CStageCondition_6be80;
class ParamValue_6be80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6be80 : public ParamValue_6be80 {
  public:
    int pad;
};
class CStageCondition_6bed0;
class ParamValue_6bed0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bed0 : public ParamValue_6bed0 {
  public:
    int pad;
};
class CStageCondition_6bf20;
class ParamValue_6bf20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bf20 : public ParamValue_6bf20 {
  public:
    int pad;
};
class CStageCondition_6bf70;
class ParamValue_6bf70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bf70 : public ParamValue_6bf70 {
  public:
    int pad;
};
class CStageCondition_6bfc0;
class ParamValue_6bfc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bfc0 : public ParamValue_6bfc0 {
  public:
    int pad;
};

} // namespace fn_fc6ccd9d

// 0x0006be60 fight::ParamFloat<CScrubberTrack>::vfunc_6 (26 B): matches/0x0006be60.cpp
// sym: ?vfunc_6@?$ParamFloat@VCScrubberTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloat<CScrubberTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloat<CScrubberTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloat<CScrubberTrack>*)a)->*(*(bool (fight::ParamFloat<CScrubberTrack>::**)(int))&this->f_10))(b);
}


// 0x0006be80 fight::ParamFloat<CScrubberTrack>::vfunc_2 (11 B): matches/0x0006be80.cpp
// sym: ?vfunc_2@?$ParamFloat@VCScrubberTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloat<CScrubberTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006beb0 fight::ParamFloatConstRange<CClimbingTrack>::vfunc_6 (26 B): matches/0x0006beb0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCClimbingTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClimbingTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CClimbingTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CClimbingTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CClimbingTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bed0 fight::ParamFloatConstRange<CClimbingTrack>::vfunc_2 (11 B): matches/0x0006bed0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCClimbingTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClimbingTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006bf00 fight::ParamFloatConstRange<CJumpTrack>::vfunc_6 (26 B): matches/0x0006bf00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCClimbingTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CJumpTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CJumpTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bf20 fight::ParamFloatConstRange<CJumpTrack>::vfunc_2 (11 B): matches/0x0006bf20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCClimbingTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006bf50 fight::ParamIntConstRange<CJumpTrack>::vfunc_6 (26 B): matches/0x0006bf50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCJumpTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CJumpTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CJumpTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bf70 fight::ParamIntConstRange<CJumpTrack>::vfunc_2 (11 B): matches/0x0006bf70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCJumpTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006bfa0 fight::ParamBool<CJumpTrack>::vfunc_6 (26 B): matches/0x0006bfa0.cpp
// sym: ?vfunc_6@?$ParamBool@VCJumpTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CJumpTrack>*)a)->*(*(bool (fight::ParamBool<CJumpTrack>::**)(int))&this->f_10))(b);
}


// 0x0006bfc0 fight::ParamBool<CJumpTrack>::vfunc_2 (11 B): matches/0x0006bfc0.cpp
// sym: ?vfunc_2@?$ParamBool@VCJumpTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}

