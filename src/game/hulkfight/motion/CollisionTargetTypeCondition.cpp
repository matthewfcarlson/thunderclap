// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001532e0..0x00153370 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetTypeCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2bbe6af {
#define TREE_TU_END }
namespace fn_f2bbe6af {} using namespace fn_f2bbe6af;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2bbe6af {
struct CAxisArcCondition_1532e0;
class CStageCondition_1532f0 {};
class ParamValue_1532f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1532f0 : public ParamValue_1532f0 {
  public:
    virtual void f();
};

} // namespace fn_f2bbe6af

// 0x001532e0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_7 (6 B): matches/0x001532e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001532f0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_6 (30 B): matches/0x001532f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1532f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1532f0*)&DAT_003f335c));
}


// 0x00153310 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_8 (26 B): matches/0x00153310.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x00153330 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_2 (11 B): matches/0x00153330.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionTargetTypeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

