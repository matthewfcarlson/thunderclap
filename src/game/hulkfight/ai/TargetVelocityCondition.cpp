// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127290..0x00127370 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdedab11 {
#define TREE_TU_END }
namespace fn_fdedab11 {} using namespace fn_fdedab11;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fdedab11 {
class CStageCondition_1272a0 {};
class ParamValue_1272a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1272a0 : public ParamValue_1272a0 {
  public:
    virtual void f();
};
class CStageCondition_127330;
class ParamValue_127330 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127330 : public ParamValue_127330 {
  public:
    int pad;
};

} // namespace fn_fdedab11

// 0x00127290 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_7 (6 B): matches/0x00127290.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEHH@Z
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_7(int index) {
    return this->f_14;
}


// 0x001272a0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_6 (30 B): matches/0x001272a0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1272a0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1272a0*)&DAT_003f335c));
}


// 0x001272c0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_8 (26 B): matches/0x001272c0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::**)(int))&this->f_18))(b);
}


// 0x001272e0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_2 (11 B): matches/0x001272e0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetVelocityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00127310 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::vfunc_6 (26 B): matches/0x00127310.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::**)(int))&this->f_10))(b);
}


// 0x00127330 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::vfunc_2 (11 B): matches/0x00127330.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetVelocityCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityCondition>::vfunc_2() {
    return this->f_10 == 0;
}

