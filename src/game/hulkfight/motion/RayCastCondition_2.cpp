// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001699d0..0x00169b10 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f829f4f3 {
#define TREE_TU_END }
namespace fn_f829f4f3 {} using namespace fn_f829f4f3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f829f4f3 {
class CStageCondition_1699f0;
class ParamValue_1699f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1699f0 : public ParamValue_1699f0 {
  public:
    int pad;
};
class CStageCondition_169a40;
class ParamValue_169a40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169a40 : public ParamValue_169a40 {
  public:
    int pad;
};
class CStageCondition_169a90;
class ParamValue_169a90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169a90 : public ParamValue_169a90 {
  public:
    int pad;
};
class CStageCondition_169ae0;
class ParamValue_169ae0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169ae0 : public ParamValue_169ae0 {
  public:
    int pad;
};

} // namespace fn_f829f4f3

// 0x001699d0 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::vfunc_6 (26 B): matches/0x001699d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x001699f0 fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::vfunc_2 (11 B): matches/0x001699f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityXZAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169a20 fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_6 (26 B): matches/0x00169a20.cpp
// sym: ?vfunc_6@?$ParamVector@VRayCastCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::RayCastCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::RayCastCondition>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::RayCastCondition>::**)(int))&this->f_10))(b);
}


// 0x00169a40 fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_2 (11 B): matches/0x00169a40.cpp
// sym: ?vfunc_2@?$ParamVector@VRayCastCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169a70 fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::vfunc_6 (26 B): matches/0x00169a70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::**)(int))&this->f_10))(b);
}


// 0x00169a90 fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::vfunc_2 (11 B): matches/0x00169a90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVelocityXZAngleCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169ac0 fight::ParamBool<hulkfight::motion::RayCastCondition>::vfunc_6 (26 B): matches/0x00169ac0.cpp
// sym: ?vfunc_6@?$ParamBool@VRayCastCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::RayCastCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::RayCastCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::RayCastCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::RayCastCondition>::**)(int))&this->f_10))(b);
}


// 0x00169ae0 fight::ParamBool<hulkfight::motion::RayCastCondition>::vfunc_2 (11 B): matches/0x00169ae0.cpp
// sym: ?vfunc_2@?$ParamBool@VRayCastCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::RayCastCondition>::vfunc_2() {
    return this->f_10 == 0;
}

