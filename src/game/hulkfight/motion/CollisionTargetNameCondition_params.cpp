// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153120..0x001531b0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetNameCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4ace616 {
#define TREE_TU_END }
namespace fn_f4ace616 {} using namespace fn_f4ace616;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4ace616 {
struct CAxisArcCondition_153120;
class CStageCondition_153130 {};
class ParamValue_153130 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_153130 : public ParamValue_153130 {
  public:
    virtual void f();
};

} // namespace fn_f4ace616

// 0x00153120 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_7 (6 B): matches/0x00153120.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00153130 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_6 (30 B): matches/0x00153130.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_153130 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_153130*)&DAT_003f335c));
}


// 0x00153150 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_8 (26 B): matches/0x00153150.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::**)(int))&this->f_18))(b);
}


// 0x00153170 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_2 (11 B): matches/0x00153170.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionTargetNameCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}

