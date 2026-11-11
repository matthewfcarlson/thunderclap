// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152ab0..0x00152b80 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetPriorityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f26a987d {
#define TREE_TU_END }
namespace fn_f26a987d {} using namespace fn_f26a987d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f26a987d {
struct CAxisArcCondition_152ab0;
class CStageCondition_152ac0 {};
class ParamValue_152ac0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152ac0 : public ParamValue_152ac0 {
  public:
    virtual void f();
};
class CStageCondition_152b50;
class ParamValue_152b50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152b50 : public ParamValue_152b50 {
  public:
    int pad;
};

} // namespace fn_f26a987d

// 0x00152ab0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_7 (6 B): matches/0x00152ab0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152ac0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_6 (30 B): matches/0x00152ac0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152ac0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152ac0*)&DAT_003f335c));
}


// 0x00152ae0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_8 (26 B): matches/0x00152ae0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::**)(int))&this->f_18))(b);
}


// 0x00152b00 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_2 (11 B): matches/0x00152b00.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00152b30 fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_6 (26 B): matches/0x00152b30.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::**)(int))&this->f_10))(b);
}


// 0x00152b50 fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_2 (11 B): matches/0x00152b50.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCollisionTargetPriorityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_2() {
    return this->f_10 == 0;
}

