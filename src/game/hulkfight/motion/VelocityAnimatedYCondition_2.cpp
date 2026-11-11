// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169520..0x00169660 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5c7cb0f {
#define TREE_TU_END }
namespace fn_f5c7cb0f {} using namespace fn_f5c7cb0f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5c7cb0f {
class CStageCondition_169540;
class ParamValue_169540 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169540 : public ParamValue_169540 {
  public:
    int pad;
};
struct CAxisArcCondition_169580;
class CStageCondition_169590 {};
class ParamValue_169590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169590 : public ParamValue_169590 {
  public:
    virtual void f();
};
class CStageCondition_169620;
class ParamValue_169620 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169620 : public ParamValue_169620 {
  public:
    int pad;
};

} // namespace fn_f5c7cb0f

// 0x00169520 fight::ParamBool<hulkfight::motion::TargetingCondition>::vfunc_6 (26 B): matches/0x00169520.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetingCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::TargetingCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::TargetingCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::TargetingCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::TargetingCondition>::**)(int))&this->f_10))(b);
}


// 0x00169540 fight::ParamBool<hulkfight::motion::TargetingCondition>::vfunc_2 (11 B): matches/0x00169540.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetingCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::TargetingCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169580 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_7 (6 B): matches/0x00169580.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169590 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_6 (30 B): matches/0x00169590.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169590 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169590*)&DAT_003f335c));
}


// 0x001695b0 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_8 (26 B): matches/0x001695b0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::**)(int))&this->f_18))(b);
}


// 0x001695d0 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_2 (11 B): matches/0x001695d0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169600 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_6 (26 B): matches/0x00169600.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::**)(int))&this->f_10))(b);
}


// 0x00169620 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_2 (11 B): matches/0x00169620.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVelocityAnimatedYCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_2() {
    return this->f_10 == 0;
}

