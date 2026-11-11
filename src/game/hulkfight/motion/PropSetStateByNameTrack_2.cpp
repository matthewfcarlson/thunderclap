// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185960..0x00185a00 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByNameTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5f6e076 {
#define TREE_TU_END }
namespace fn_f5f6e076 {} using namespace fn_f5f6e076;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5f6e076 {
class CStageCondition_185980;
class ParamValue_185980 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185980 : public ParamValue_185980 {
  public:
    int pad;
};
class CStageCondition_1859d0;
class ParamValue_1859d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1859d0 : public ParamValue_1859d0 {
  public:
    int pad;
};

} // namespace fn_f5f6e076

// 0x00185960 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_6 (26 B): matches/0x00185960.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::**)(int))&this->f_10))(b);
}


// 0x00185980 fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_2 (11 B): matches/0x00185980.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001859b0 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_6 (26 B): matches/0x001859b0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::**)(int))&this->f_10))(b);
}


// 0x001859d0 fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_2 (11 B): matches/0x001859d0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>::vfunc_2() {
    return this->f_10 == 0;
}

