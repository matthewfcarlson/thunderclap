// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006cb50..0x0006cc40 (kind game, layer game, confidence high), dominant class CJumpAttackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f68792e8 {
#define TREE_TU_END }
namespace fn_f68792e8 {} using namespace fn_f68792e8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f68792e8 {
class CStageCondition_6cb70;
class ParamValue_6cb70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cb70 : public ParamValue_6cb70 {
  public:
    int pad;
};
class CStageCondition_6cbc0;
class ParamValue_6cbc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cbc0 : public ParamValue_6cbc0 {
  public:
    int pad;
};
class CStageCondition_6cc10;
class ParamValue_6cc10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cc10 : public ParamValue_6cc10 {
  public:
    int pad;
};

} // namespace fn_f68792e8

// 0x0006cb50 fight::ParamFloatConstRange<CJumpAttackTrack>::vfunc_6 (26 B): matches/0x0006cb50.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCJumpAttackTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CJumpAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CJumpAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CJumpAttackTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CJumpAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cb70 fight::ParamFloatConstRange<CJumpAttackTrack>::vfunc_2 (11 B): matches/0x0006cb70.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCJumpAttackTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CJumpAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cba0 fight::ParamVector<CJumpAttackTrack>::vfunc_6 (26 B): matches/0x0006cba0.cpp
// sym: ?vfunc_6@?$ParamVector@VCJumpAttackTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<CJumpAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<CJumpAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CJumpAttackTrack>*)a)->*(*(bool (fight::ParamVector<CJumpAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cbc0 fight::ParamVector<CJumpAttackTrack>::vfunc_2 (11 B): matches/0x0006cbc0.cpp
// sym: ?vfunc_2@?$ParamVector@VCJumpAttackTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<CJumpAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cbf0 fight::ParamIntConstRange<CJumpAttackTrack>::vfunc_6 (26 B): matches/0x0006cbf0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCJumpAttackTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CJumpAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CJumpAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CJumpAttackTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CJumpAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cc10 fight::ParamIntConstRange<CJumpAttackTrack>::vfunc_2 (11 B): matches/0x0006cc10.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCJumpAttackTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CJumpAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}

