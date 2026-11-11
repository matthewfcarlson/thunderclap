// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00169660..0x001696f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TargetLocomotionMotionStateCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb2850af {
#define TREE_TU_END }
namespace fn_fb2850af {} using namespace fn_fb2850af;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb2850af {
struct CAxisArcCondition_169660;
class CStageCondition_169670 {};
class ParamValue_169670 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169670 : public ParamValue_169670 {
  public:
    virtual void f();
};

} // namespace fn_fb2850af

// 0x00169660 fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_7 (6 B): matches/0x00169660.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00169670 fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_6 (30 B): matches/0x00169670.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169670 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_169670*)&DAT_003f335c));
}


// 0x00169690 fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_8 (26 B): matches/0x00169690.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::**)(int))&this->f_18))(b);
}


// 0x001696b0 fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_2 (11 B): matches/0x001696b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetLocomotionMotionStateCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}

