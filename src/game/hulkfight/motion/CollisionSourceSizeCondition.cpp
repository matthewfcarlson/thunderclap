// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152930..0x00152a20 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionSourceSizeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1641899 {
#define TREE_TU_END }
namespace fn_f1641899 {} using namespace fn_f1641899;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f1641899 {
class CStageCondition_152950;
class ParamValue_152950 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152950 : public ParamValue_152950 {
  public:
    int pad;
};
struct CAxisArcCondition_152990;
class CStageCondition_1529a0 {};
class ParamValue_1529a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1529a0 : public ParamValue_1529a0 {
  public:
    virtual void f();
};

} // namespace fn_f1641899

// 0x00152930 fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::vfunc_6 (26 B): matches/0x00152930.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionThrowCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::**)(int))&this->f_10))(b);
}


// 0x00152950 fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::vfunc_2 (11 B): matches/0x00152950.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionThrowCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionThrowCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152990 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_7 (6 B): matches/0x00152990.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001529a0 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_6 (30 B): matches/0x001529a0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1529a0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1529a0*)&DAT_003f335c));
}


// 0x001529c0 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_8 (26 B): matches/0x001529c0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::**)(int))&this->f_18))(b);
}


// 0x001529e0 fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_2 (11 B): matches/0x001529e0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionSourceSizeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

