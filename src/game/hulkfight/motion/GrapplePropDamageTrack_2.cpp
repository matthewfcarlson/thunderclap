// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185c70..0x00185d10 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrapplePropDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1e45645 {
#define TREE_TU_END }
namespace fn_f1e45645 {} using namespace fn_f1e45645;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1e45645 {
class CStageCondition_185c90;
class ParamValue_185c90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185c90 : public ParamValue_185c90 {
  public:
    int pad;
};
class CStageCondition_185ce0;
class ParamValue_185ce0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185ce0 : public ParamValue_185ce0 {
  public:
    int pad;
};

} // namespace fn_f1e45645

// 0x00185c70 fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_6 (26 B): matches/0x00185c70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00185c90 fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_2 (11 B): matches/0x00185c90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185cc0 fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_6 (26 B): matches/0x00185cc0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::**)(int))&this->f_10))(b);
}


// 0x00185ce0 fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_2 (11 B): matches/0x00185ce0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VGrapplePropDamageTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>::vfunc_2() {
    return this->f_10 == 0;
}

