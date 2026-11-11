// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004fc10..0x0004fc90 (kind game, layer game, confidence high), dominant class CMotionHitCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbcfdc1b {
#define TREE_TU_END }
namespace fn_fbcfdc1b {} using namespace fn_fbcfdc1b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbcfdc1b {
struct CAxisArcCondition_4fc10;
class CStageCondition_4fc20 {};
class ParamValue_4fc20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fc20 : public ParamValue_4fc20 {
  public:
    virtual void f();
};

} // namespace fn_fbcfdc1b

// 0x0004fc10 fight::ParamEnumConstList<CMotionHitCondition>::vfunc_7 (6 B): matches/0x0004fc10.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCMotionHitCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CMotionHitCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004fc20 fight::ParamEnumConstList<CMotionHitCondition>::vfunc_6 (30 B): matches/0x0004fc20.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCMotionHitCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CMotionHitCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fc20 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4fc20*)&DAT_003f335c));
}


// 0x0004fc40 fight::ParamEnumConstList<CMotionHitCondition>::vfunc_8 (26 B): matches/0x0004fc40.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCMotionHitCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CMotionHitCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CMotionHitCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CMotionHitCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CMotionHitCondition>::**)(int))&this->f_18))(b);
}


// 0x0004fc60 fight::ParamEnumConstList<CMotionHitCondition>::vfunc_2 (11 B): matches/0x0004fc60.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCMotionHitCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CMotionHitCondition>::vfunc_2() {
    return this->f_18 == 0;
}

