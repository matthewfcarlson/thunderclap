// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c490..0x0006c5d0 (kind game, layer game, confidence high), dominant class CSweepTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3ccc8a0 {
#define TREE_TU_END }
namespace fn_f3ccc8a0 {} using namespace fn_f3ccc8a0;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3ccc8a0 {
class CStageCondition_6c4b0;
class ParamValue_6c4b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c4b0 : public ParamValue_6c4b0 {
  public:
    int pad;
};
class CStageCondition_6c500;
class ParamValue_6c500 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c500 : public ParamValue_6c500 {
  public:
    int pad;
};
class ParamValueFloat_6c510 {
  public:
    ParamValueFloat_6c510(int);
    virtual void f();
};
class ParamFloatConstRange : public ParamValueFloat_6c510 {
  public:
    ParamFloatConstRange(int, int);
    char pad[12];
    int value;
    virtual void f();
};
class CStageCondition_6c550;
class ParamValue_6c550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c550 : public ParamValue_6c550 {
  public:
    int pad;
};
class CStageCondition_6c5a0;
class ParamValue_6c5a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c5a0 : public ParamValue_6c5a0 {
  public:
    int pad;
};

} // namespace fn_f3ccc8a0

// 0x0006c490 fight::ParamFloatConstRange<CMoveAddTrack>::vfunc_6 (26 B): matches/0x0006c490.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMoveAddTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMoveAddTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMoveAddTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMoveAddTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c4b0 fight::ParamFloatConstRange<CMoveAddTrack>::vfunc_2 (11 B): matches/0x0006c4b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMoveAddTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c4e0 fight::ParamFloatConstRange<CMoveAddYTrack>::vfunc_6 (26 B): matches/0x0006c4e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMoveAddYTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMoveAddYTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMoveAddYTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMoveAddYTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c500 fight::ParamFloatConstRange<CMoveAddYTrack>::vfunc_2 (11 B): matches/0x0006c500.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CMoveAddYTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f3ccc8a0 {

// 0x0006c510 FUN_0006c510 (32 B): matches/0x0006c510.cpp
// sym: ??0ParamFloatConstRange@fn_f3ccc8a0@@QAE@HH@Z
ParamFloatConstRange::ParamFloatConstRange(int a, int b) : ParamValueFloat_6c510(a) {
    value = b;
}

} // namespace fn_f3ccc8a0

// 0x0006c530 fight::ParamFloatConstRange<CSweepTrack>::vfunc_6 (26 B): matches/0x0006c530.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSweepTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CSweepTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CSweepTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CSweepTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c550 fight::ParamFloatConstRange<CSweepTrack>::vfunc_2 (11 B): matches/0x0006c550.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCMoveAddTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CSweepTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c580 fight::ParamIntConstRange<CSweepTrack>::vfunc_6 (26 B): matches/0x0006c580.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCSweepTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSweepTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSweepTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSweepTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSweepTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c5a0 fight::ParamIntConstRange<CSweepTrack>::vfunc_2 (11 B): matches/0x0006c5a0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCSweepTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSweepTrack>::vfunc_2() {
    return this->f_10 == 0;
}

