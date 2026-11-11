// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186280..0x001863c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f339a25e {
#define TREE_TU_END }
namespace fn_f339a25e {} using namespace fn_f339a25e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f339a25e {
class CStageCondition_1862a0;
class ParamValue_1862a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1862a0 : public ParamValue_1862a0 {
  public:
    int pad;
};
class CStageCondition_1862f0;
class ParamValue_1862f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1862f0 : public ParamValue_1862f0 {
  public:
    int pad;
};
class CStageCondition_186340;
class ParamValue_186340 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186340 : public ParamValue_186340 {
  public:
    int pad;
};
class CStageCondition_186390;
class ParamValue_186390 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_186390 : public ParamValue_186390 {
  public:
    int pad;
};

} // namespace fn_f339a25e

// 0x00186280 fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::vfunc_6 (26 B): matches/0x00186280.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VShieldArcTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::**)(int))&this->f_10))(b);
}


// 0x001862a0 fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::vfunc_2 (11 B): matches/0x001862a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VShieldArcTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ShieldArcTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001862d0 fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_6 (26 B): matches/0x001862d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VShieldArcTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x001862f0 fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2 (11 B): matches/0x001862f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VShieldArcTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186320 fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_6 (26 B): matches/0x00186320.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x00186340 fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2 (11 B): matches/0x00186340.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00186370 fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::vfunc_6 (26 B): matches/0x00186370.cpp
// sym: ?vfunc_6@?$ParamBool@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::**)(int))&this->f_10))(b);
}


// 0x00186390 fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2 (11 B): matches/0x00186390.cpp
// sym: ?vfunc_2@?$ParamBool@VPropAddToCollisionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropAddToCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}

