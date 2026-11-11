// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185aa0..0x00185b40 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropDropTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1ca404b {
#define TREE_TU_END }
namespace fn_f1ca404b {} using namespace fn_f1ca404b;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1ca404b {
class CStageCondition_185ac0;
class ParamValue_185ac0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185ac0 : public ParamValue_185ac0 {
  public:
    int pad;
};
class CStageCondition_185b10;
class ParamValue_185b10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185b10 : public ParamValue_185b10 {
  public:
    int pad;
};

} // namespace fn_f1ca404b

// 0x00185aa0 fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::vfunc_6 (26 B): matches/0x00185aa0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropDropTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::**)(int))&this->f_10))(b);
}


// 0x00185ac0 fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::vfunc_2 (11 B): matches/0x00185ac0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropDropTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185af0 fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::vfunc_6 (26 B): matches/0x00185af0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropDropTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::**)(int))&this->f_10))(b);
}


// 0x00185b10 fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::vfunc_2 (11 B): matches/0x00185b10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropDropTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropDropTrack>::vfunc_2() {
    return this->f_10 == 0;
}

