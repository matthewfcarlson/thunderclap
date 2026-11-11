// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00178bd0..0x00178d00 (kind game, layer game, confidence high), dominant class hulkfight::motion::FootPivotTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2961c74 {
#define TREE_TU_END }
namespace fn_f2961c74 {} using namespace fn_f2961c74;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2961c74 {
class CStageCondition_178bf0;
class ParamValue_178bf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178bf0 : public ParamValue_178bf0 {
  public:
    int pad;
};
class CStageCondition_178c40;
class ParamValue_178c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178c40 : public ParamValue_178c40 {
  public:
    int pad;
};
class CStageCondition_178c90;
class ParamValue_178c90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178c90 : public ParamValue_178c90 {
  public:
    int pad;
};
class CStageCondition_178ce0;
class ParamValue_178ce0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178ce0 : public ParamValue_178ce0 {
  public:
    int pad;
};

} // namespace fn_f2961c74

// 0x00178bd0 fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::vfunc_6 (26 B): matches/0x00178bd0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))(b);
}


// 0x00178bf0 fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::vfunc_2 (11 B): matches/0x00178bf0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FootPivotTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178c20 fight::ParamVector<hulkfight::motion::FootPivotTrack>::vfunc_6 (26 B): matches/0x00178c20.cpp
// sym: ?vfunc_6@?$ParamVector@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FootPivotTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FootPivotTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))(b);
}


// 0x00178c40 fight::ParamVector<hulkfight::motion::FootPivotTrack>::vfunc_2 (11 B): matches/0x00178c40.cpp
// sym: ?vfunc_2@?$ParamVector@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FootPivotTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178c70 fight::ParamBool<hulkfight::motion::FootPivotTrack>::vfunc_6 (26 B): matches/0x00178c70.cpp
// sym: ?vfunc_6@?$ParamBool@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FootPivotTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::FootPivotTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))(b);
}


// 0x00178c90 fight::ParamBool<hulkfight::motion::FootPivotTrack>::vfunc_2 (11 B): matches/0x00178c90.cpp
// sym: ?vfunc_2@?$ParamBool@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FootPivotTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178cc0 fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::vfunc_6 (26 B): matches/0x00178cc0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::**)(int))&this->f_10))(b);
}


// 0x00178ce0 fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::vfunc_2 (11 B): matches/0x00178ce0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFootPivotTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FootPivotTrack>::vfunc_2() {
    return this->f_10 == 0;
}

