// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169e50..0x00169f90 (kind game, layer game, confidence high), dominant class hulkfight::motion::VelocityAnimatedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f13c822e {
#define TREE_TU_END }
namespace fn_f13c822e {} using namespace fn_f13c822e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f13c822e {
class CStageCondition_169e70;
class ParamValue_169e70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169e70 : public ParamValue_169e70 {
  public:
    int pad;
};
struct CAxisArcCondition_169eb0;
class CStageCondition_169ec0 {};
class ParamValue_169ec0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169ec0 : public ParamValue_169ec0 {
  public:
    virtual void f();
};
class CStageCondition_169f50;
class ParamValue_169f50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169f50 : public ParamValue_169f50 {
  public:
    int pad;
};

} // namespace fn_f13c822e

// 0x00169e50 fight::ParamBool<hulkfight::motion::ThinkingCondition>::vfunc_6 (26 B): matches/0x00169e50.cpp
// sym: ?vfunc_6@?$ParamBool@VThinkingCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ThinkingCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::ThinkingCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::ThinkingCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::ThinkingCondition>::**)(int))&this->f_10))(b);
}


// 0x00169e70 fight::ParamBool<hulkfight::motion::ThinkingCondition>::vfunc_2 (11 B): matches/0x00169e70.cpp
// sym: ?vfunc_2@?$ParamBool@VThinkingCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ThinkingCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169eb0 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_7 (6 B): matches/0x00169eb0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169ec0 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_6 (30 B): matches/0x00169ec0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169ec0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169ec0*)&DAT_003f335c));
}


// 0x00169ee0 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_8 (26 B): matches/0x00169ee0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::**)(int))&this->f_18))(b);
}


// 0x00169f00 fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_2 (11 B): matches/0x00169f00.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::VelocityAnimatedCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169f30 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::vfunc_6 (26 B): matches/0x00169f30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::**)(int))&this->f_10))(b);
}


// 0x00169f50 fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::vfunc_2 (11 B): matches/0x00169f50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VVelocityAnimatedCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::VelocityAnimatedCondition>::vfunc_2() {
    return this->f_10 == 0;
}

