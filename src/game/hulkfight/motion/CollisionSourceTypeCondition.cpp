// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152a20..0x00152ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceTypeCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4ad0cd2 {
#define TREE_TU_END }
namespace fn_f4ad0cd2 {} using namespace fn_f4ad0cd2;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4ad0cd2 {
struct CAxisArcCondition_152a20;
class CStageCondition_152a30 {};
class ParamValue_152a30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152a30 : public ParamValue_152a30 {
  public:
    virtual void f();
};

} // namespace fn_f4ad0cd2

// 0x00152a20 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_7 (6 B): matches/0x00152a20.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152a30 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_6 (30 B): matches/0x00152a30.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152a30 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152a30*)&DAT_003f335c));
}


// 0x00152a50 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_8 (26 B): matches/0x00152a50.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x00152a70 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_2 (11 B): matches/0x00152a70.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionSourceTypeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

