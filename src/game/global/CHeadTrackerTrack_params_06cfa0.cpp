// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006cfa0..0x0006d090 (kind game, layer game, confidence high), dominant class CHeadTrackerTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f711e15c {
#define TREE_TU_END }
namespace fn_f711e15c {} using namespace fn_f711e15c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f711e15c {
class CStageCondition_6cfc0;
class ParamValue_6cfc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cfc0 : public ParamValue_6cfc0 {
  public:
    int pad;
};
class CStageCondition_6d010;
class ParamValue_6d010 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d010 : public ParamValue_6d010 {
  public:
    int pad;
};
class CStageCondition_6d060;
class ParamValue_6d060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6d060 : public ParamValue_6d060 {
  public:
    int pad;
};

} // namespace fn_f711e15c

// 0x0006cfa0 fight::ParamFloatConstRange<CHeadTrackerTrack>::vfunc_6 (26 B): matches/0x0006cfa0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCHeadTrackerTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CHeadTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CHeadTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CHeadTrackerTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CHeadTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cfc0 fight::ParamFloatConstRange<CHeadTrackerTrack>::vfunc_2 (11 B): matches/0x0006cfc0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCHeadTrackerTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CHeadTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cff0 fight::ParamVector<CHeadTrackerTrack>::vfunc_6 (26 B): matches/0x0006cff0.cpp
// sym: ?vfunc_6@?$ParamVector@VCHeadTrackerTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CHeadTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CHeadTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CHeadTrackerTrack>*)a)->*(*(bool (fight::ParamVector<CHeadTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d010 fight::ParamVector<CHeadTrackerTrack>::vfunc_2 (11 B): matches/0x0006d010.cpp
// sym: ?vfunc_2@?$ParamVector@VCHeadTrackerTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CHeadTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006d040 fight::ParamIntConstRange<CHeadTrackerTrack>::vfunc_6 (26 B): matches/0x0006d040.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCHeadTrackerTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CHeadTrackerTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CHeadTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CHeadTrackerTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CHeadTrackerTrack>::**)(int))&this->f_10))(b);
}


// 0x0006d060 fight::ParamIntConstRange<CHeadTrackerTrack>::vfunc_2 (11 B): matches/0x0006d060.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCHeadTrackerTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CHeadTrackerTrack>::vfunc_2() {
    return this->f_10 == 0;
}

