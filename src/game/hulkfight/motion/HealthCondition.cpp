// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169f90..0x0016a050 (kind game, layer game, confidence high), dominant class hulkfight::motion::HealthCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5079aa7 {
#define TREE_TU_END }
namespace fn_f5079aa7 {} using namespace fn_f5079aa7;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5079aa7 {
struct CAxisArcCondition_169f90;
class CStageCondition_169fa0 {};
class ParamValue_169fa0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169fa0 : public ParamValue_169fa0 {
  public:
    virtual void f();
};
class CStageCondition_16a030;
class ParamValue_16a030 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_16a030 : public ParamValue_16a030 {
  public:
    int pad;
};

} // namespace fn_f5079aa7

// 0x00169f90 fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_7 (6 B): matches/0x00169f90.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHealthCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169fa0 fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_6 (30 B): matches/0x00169fa0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHealthCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169fa0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169fa0*)&DAT_003f335c));
}


// 0x00169fc0 fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_8 (26 B): matches/0x00169fc0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHealthCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::HealthCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::**)(int))&this->f_18))(b);
}


// 0x00169fe0 fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_2 (11 B): matches/0x00169fe0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHealthCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HealthCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0016a010 fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::vfunc_6 (26 B): matches/0x0016a010.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHealthCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::**)(int))&this->f_10))(b);
}


// 0x0016a030 fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::vfunc_2 (11 B): matches/0x0016a030.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHealthCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HealthCondition>::vfunc_2() {
    return this->f_10 == 0;
}

