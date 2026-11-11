// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004fc90..0x0004fd40 (kind game, layer game, confidence high), dominant class CClimbableCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2271ba8 {
#define TREE_TU_END }
namespace fn_f2271ba8 {} using namespace fn_f2271ba8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2271ba8 {
class CStageCondition_4fcb0;
class ParamValue_4fcb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4fcb0 : public ParamValue_4fcb0 {
  public:
    int pad;
};
class CStageCondition_4fd00;
class ParamValue_4fd00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4fd00 : public ParamValue_4fd00 {
  public:
    int pad;
};

} // namespace fn_f2271ba8

// 0x0004fc90 fight::ParamFloatConstRange<CClimbableCondition>::vfunc_6 (26 B): matches/0x0004fc90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCClimbableCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClimbableCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CClimbableCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CClimbableCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CClimbableCondition>::**)(int))&this->f_10))(b);
}


// 0x0004fcb0 fight::ParamFloatConstRange<CClimbableCondition>::vfunc_2 (11 B): matches/0x0004fcb0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCClimbableCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CClimbableCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004fce0 fight::ParamBool<CClimbableCondition>::vfunc_6 (26 B): matches/0x0004fce0.cpp
// sym: ?vfunc_6@?$ParamBool@VCClimbableCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CClimbableCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CClimbableCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CClimbableCondition>*)a)->*(*(bool (fight::ParamBool<CClimbableCondition>::**)(int))&this->f_10))(b);
}


// 0x0004fd00 fight::ParamBool<CClimbableCondition>::vfunc_2 (11 B): matches/0x0004fd00.cpp
// sym: ?vfunc_2@?$ParamBool@VCClimbableCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CClimbableCondition>::vfunc_2() {
    return this->f_10 == 0;
}

