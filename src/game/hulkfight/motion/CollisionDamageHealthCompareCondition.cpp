// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001531b0..0x001532e0 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionDamageHealthCompareCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fea91657 {
#define TREE_TU_END }
namespace fn_fea91657 {} using namespace fn_fea91657;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fea91657 {
struct CAxisArcCondition_1531b0;
class CStageCondition_1531c0 {};
class ParamValue_1531c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1531c0 : public ParamValue_1531c0 {
  public:
    virtual void f();
};
class CStageCondition_153250;
class ParamValue_153250 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153250 : public ParamValue_153250 {
  public:
    int pad;
};
class CStageCondition_1532a0;
class ParamValue_1532a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1532a0 : public ParamValue_1532a0 {
  public:
    int pad;
};

} // namespace fn_fea91657

// 0x001531b0 fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_7 (6 B): matches/0x001531b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001531c0 fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_6 (30 B): matches/0x001531c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1531c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1531c0*)&DAT_003f335c));
}


// 0x001531e0 fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_8 (26 B): matches/0x001531e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::**)(int))&this->f_18))(b);
}


// 0x00153200 fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2 (11 B): matches/0x00153200.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00153230 fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_6 (26 B): matches/0x00153230.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::**)(int))&this->f_10))(b);
}


// 0x00153250 fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2 (11 B): matches/0x00153250.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153280 fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_6 (26 B): matches/0x00153280.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::**)(int))&this->f_10))(b);
}


// 0x001532a0 fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2 (11 B): matches/0x001532a0.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionDamageHealthCompareCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_2() {
    return this->f_10 == 0;
}

