// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185f70..0x00186010 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByIndexTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3813d39 {
#define TREE_TU_END }
namespace fn_f3813d39 {} using namespace fn_f3813d39;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3813d39 {
class CStageCondition_185f90;
class ParamValue_185f90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185f90 : public ParamValue_185f90 {
  public:
    int pad;
};
class CStageCondition_185fe0;
class ParamValue_185fe0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185fe0 : public ParamValue_185fe0 {
  public:
    int pad;
};

} // namespace fn_f3813d39

// 0x00185f70 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_6 (26 B): matches/0x00185f70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::**)(int))&this->f_10))(b);
}


// 0x00185f90 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_2 (11 B): matches/0x00185f90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185fc0 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_6 (26 B): matches/0x00185fc0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::**)(int))&this->f_10))(b);
}


// 0x00185fe0 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_2 (11 B): matches/0x00185fe0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropSetStateByIndexTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_2() {
    return this->f_10 == 0;
}

