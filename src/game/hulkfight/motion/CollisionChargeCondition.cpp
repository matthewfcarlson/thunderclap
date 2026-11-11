// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152ff0..0x00153120 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionChargeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdfd0b48 {
#define TREE_TU_END }
namespace fn_fdfd0b48 {} using namespace fn_fdfd0b48;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fdfd0b48 {
struct CAxisArcCondition_152ff0;
class CStageCondition_153000 {};
class ParamValue_153000 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_153000 : public ParamValue_153000 {
  public:
    virtual void f();
};
class CStageCondition_153090;
class ParamValue_153090 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153090 : public ParamValue_153090 {
  public:
    int pad;
};
class CStageCondition_1530e0;
class ParamValue_1530e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1530e0 : public ParamValue_1530e0 {
  public:
    int pad;
};

} // namespace fn_fdfd0b48

// 0x00152ff0 fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_7 (6 B): matches/0x00152ff0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00153000 fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_6 (30 B): matches/0x00153000.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_153000 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_153000*)&DAT_003f335c));
}


// 0x00153020 fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_8 (26 B): matches/0x00153020.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::**)(int))&this->f_18))(b);
}


// 0x00153040 fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_2 (11 B): matches/0x00153040.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00153070 fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_6 (26 B): matches/0x00153070.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::**)(int))&this->f_10))(b);
}


// 0x00153090 fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_2 (11 B): matches/0x00153090.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001530c0 fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::vfunc_6 (26 B): matches/0x001530c0.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionChargeCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::**)(int))&this->f_10))(b);
}


// 0x001530e0 fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::vfunc_2 (11 B): matches/0x001530e0.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionChargeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

