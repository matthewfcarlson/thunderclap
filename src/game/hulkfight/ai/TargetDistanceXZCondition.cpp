// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127370..0x00127490 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetDistanceXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdca36c3 {
#define TREE_TU_END }
namespace fn_fdca36c3 {} using namespace fn_fdca36c3;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fdca36c3 {
struct CAxisArcCondition_127370;
class CStageCondition_127380 {};
class ParamValue_127380 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_127380 : public ParamValue_127380 {
  public:
    virtual void f();
};
class CStageCondition_127410;
class ParamValue_127410 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127410 : public ParamValue_127410 {
  public:
    int pad;
};
class CStageCondition_127460;
class ParamValue_127460 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127460 : public ParamValue_127460 {
  public:
    int pad;
};

} // namespace fn_fdca36c3

// 0x00127370 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_7 (6 B): matches/0x00127370.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00127380 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_6 (30 B): matches/0x00127380.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_127380 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_127380*)&DAT_003f335c));
}


// 0x001273a0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_8 (26 B): matches/0x001273a0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::**)(int))&this->f_18))(b);
}


// 0x001273c0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2 (11 B): matches/0x001273c0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001273f0 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::vfunc_6 (26 B): matches/0x001273f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::**)(int))&this->f_10))(b);
}


// 0x00127410 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2 (11 B): matches/0x00127410.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127440 fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::vfunc_6 (26 B): matches/0x00127440.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::**)(int))&this->f_10))(b);
}


// 0x00127460 fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2 (11 B): matches/0x00127460.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetDistanceXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetDistanceXZCondition>::vfunc_2() {
    return this->f_10 == 0;
}

