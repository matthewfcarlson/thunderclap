// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006cc40..0x0006cd10 (kind game, layer game, confidence high), dominant class COrientTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f40cf32d {
#define TREE_TU_END }
namespace fn_f40cf32d {} using namespace fn_f40cf32d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f40cf32d {
class CStageCondition_6cc60;
class ParamValue_6cc60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cc60 : public ParamValue_6cc60 {
  public:
    int pad;
};
class CStageCondition_6ccb0;
class ParamValue_6ccb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6ccb0 : public ParamValue_6ccb0 {
  public:
    int pad;
};
class CStageCondition_6cd00;
class ParamValue_6cd00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cd00 : public ParamValue_6cd00 {
  public:
    int pad;
};

} // namespace fn_f40cf32d

// 0x0006cc40 fight::ParamFloatConstRange<COrientTrack>::vfunc_6 (26 B): matches/0x0006cc40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCOrientTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<COrientTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<COrientTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<COrientTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<COrientTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cc60 fight::ParamFloatConstRange<COrientTrack>::vfunc_2 (11 B): matches/0x0006cc60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCOrientTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<COrientTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cc90 fight::ParamBool<COrientTrack>::vfunc_6 (26 B): matches/0x0006cc90.cpp
// sym: ?vfunc_6@?$ParamBool@VCOrientTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<COrientTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<COrientTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<COrientTrack>*)a)->*(*(bool (fight::ParamBool<COrientTrack>::**)(int))&this->f_10))(b);
}


// 0x0006ccb0 fight::ParamBool<COrientTrack>::vfunc_2 (11 B): matches/0x0006ccb0.cpp
// sym: ?vfunc_2@?$ParamBool@VCOrientTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<COrientTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cce0 fight::ParamIntConstRange<COrientTrack>::vfunc_6 (26 B): matches/0x0006cce0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCOrientTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<COrientTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<COrientTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<COrientTrack>*)a)->*(*(bool (fight::ParamIntConstRange<COrientTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cd00 fight::ParamIntConstRange<COrientTrack>::vfunc_2 (11 B): matches/0x0006cd00.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCOrientTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<COrientTrack>::vfunc_2() {
    return this->f_10 == 0;
}

