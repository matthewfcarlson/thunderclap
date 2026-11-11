// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127540..0x00127620 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetVelocityXZCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f975265f {
#define TREE_TU_END }
namespace fn_f975265f {} using namespace fn_f975265f;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f975265f {
struct CAxisArcCondition_127540;
class CStageCondition_127550 {};
class ParamValue_127550 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_127550 : public ParamValue_127550 {
  public:
    virtual void f();
};
class CStageCondition_1275e0;
class ParamValue_1275e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1275e0 : public ParamValue_1275e0 {
  public:
    int pad;
};

} // namespace fn_f975265f

// 0x00127540 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_7 (6 B): matches/0x00127540.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00127550 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_6 (30 B): matches/0x00127550.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_127550 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_127550*)&DAT_003f335c));
}


// 0x00127570 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_8 (26 B): matches/0x00127570.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::**)(int))&this->f_18))(b);
}


// 0x00127590 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_2 (11 B): matches/0x00127590.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetVelocityXZCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001275c0 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::vfunc_6 (26 B): matches/0x001275c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::**)(int))&this->f_10))(b);
}


// 0x001275e0 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::vfunc_2 (11 B): matches/0x001275e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetVelocityXZCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityXZCondition>::vfunc_2() {
    return this->f_10 == 0;
}

