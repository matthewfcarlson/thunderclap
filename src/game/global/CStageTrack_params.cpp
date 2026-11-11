// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006cf00..0x0006cfa0 (kind game, layer game, confidence high), dominant class CStageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4e0be0a {
#define TREE_TU_END }
namespace fn_f4e0be0a {} using namespace fn_f4e0be0a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4e0be0a {
class CStageCondition_6cf20;
class ParamValue_6cf20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cf20 : public ParamValue_6cf20 {
  public:
    int pad;
};
class CStageCondition_6cf70;
class ParamValue_6cf70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6cf70 : public ParamValue_6cf70 {
  public:
    int pad;
};

} // namespace fn_f4e0be0a

// 0x0006cf00 fight::ParamFloatConstRange<CStageTrack>::vfunc_6 (26 B): matches/0x0006cf00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCStageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CStageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CStageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CStageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CStageTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cf20 fight::ParamFloatConstRange<CStageTrack>::vfunc_2 (11 B): matches/0x0006cf20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCStageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CStageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cf50 fight::ParamIntConstRange<CStageTrack>::vfunc_6 (26 B): matches/0x0006cf50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCStageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CStageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CStageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CStageTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CStageTrack>::**)(int))&this->f_10))(b);
}


// 0x0006cf70 fight::ParamIntConstRange<CStageTrack>::vfunc_2 (11 B): matches/0x0006cf70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCStageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CStageTrack>::vfunc_2() {
    return this->f_10 == 0;
}

