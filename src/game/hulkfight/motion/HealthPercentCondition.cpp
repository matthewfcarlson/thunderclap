// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169d20..0x00169e50 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthPercentCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f23794d0 {
#define TREE_TU_END }
namespace fn_f23794d0 {} using namespace fn_f23794d0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f23794d0 {
class CStageCondition_169d40;
class ParamValue_169d40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169d40 : public ParamValue_169d40 {
  public:
    int pad;
};
struct CAxisArcCondition_169d80;
class CStageCondition_169d90 {};
class ParamValue_169d90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169d90 : public ParamValue_169d90 {
  public:
    virtual void f();
};
class CStageCondition_169e20;
class ParamValue_169e20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169e20 : public ParamValue_169e20 {
  public:
    int pad;
};

} // namespace fn_f23794d0

// 0x00169d20 fight::ParamBool<hulkfight::motion::ShoreNearCondition>::vfunc_6 (26 B): matches/0x00169d20.cpp
// sym: ?vfunc_6@?$ParamBool@VShoreNearCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ShoreNearCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::ShoreNearCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::ShoreNearCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::ShoreNearCondition>::**)(int))&this->f_10))(b);
}


// 0x00169d40 fight::ParamBool<hulkfight::motion::ShoreNearCondition>::vfunc_2 (11 B): matches/0x00169d40.cpp
// sym: ?vfunc_2@?$ParamBool@VShoreNearCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ShoreNearCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00169d80 fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_7 (6 B): matches/0x00169d80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169d90 fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_6 (30 B): matches/0x00169d90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHealthPercentCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169d90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169d90*)&DAT_003f335c));
}


// 0x00169db0 fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_8 (26 B): matches/0x00169db0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::**)(int))&this->f_18))(b);
}


// 0x00169dd0 fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_2 (11 B): matches/0x00169dd0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HealthPercentCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169e00 fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::vfunc_6 (26 B): matches/0x00169e00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::**)(int))&this->f_10))(b);
}


// 0x00169e20 fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::vfunc_2 (11 B): matches/0x00169e20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHealthPercentCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HealthPercentCondition>::vfunc_2() {
    return this->f_10 == 0;
}

