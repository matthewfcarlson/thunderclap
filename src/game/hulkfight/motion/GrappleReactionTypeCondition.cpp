// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001693b0..0x00169430 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleReactionTypeCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff497719 {
#define TREE_TU_END }
namespace fn_ff497719 {} using namespace fn_ff497719;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ff497719 {
struct CAxisArcCondition_1693b0;
class CStageCondition_1693c0 {};
class ParamValue_1693c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1693c0 : public ParamValue_1693c0 {
  public:
    virtual void f();
};

} // namespace fn_ff497719

// 0x001693b0 fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_7 (6 B): matches/0x001693b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001693c0 fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_6 (30 B): matches/0x001693c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1693c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1693c0*)&DAT_003f335c));
}


// 0x001693e0 fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_8 (26 B): matches/0x001693e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x00169400 fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_2 (11 B): matches/0x00169400.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VGrappleReactionTypeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

