// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152d00..0x00152e30 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitPushbackVelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc74a429 {
#define TREE_TU_END }
namespace fn_fc74a429 {} using namespace fn_fc74a429;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc74a429 {
class CStageCondition_152d20;
class ParamValue_152d20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152d20 : public ParamValue_152d20 {
  public:
    int pad;
};
struct CAxisArcCondition_152d60;
class CStageCondition_152d70 {};
class ParamValue_152d70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152d70 : public ParamValue_152d70 {
  public:
    virtual void f();
};
class CStageCondition_152e00;
class ParamValue_152e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152e00 : public ParamValue_152e00 {
  public:
    int pad;
};

} // namespace fn_fc74a429

// 0x00152d00 fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_6 (26 B): matches/0x00152d00.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionSourceIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::**)(int))&this->f_10))(b);
}


// 0x00152d20 fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_2 (11 B): matches/0x00152d20.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionSourceIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152d60 fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_7 (6 B): matches/0x00152d60.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152d70 fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_6 (30 B): matches/0x00152d70.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152d70 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152d70*)&DAT_003f335c));
}


// 0x00152d90 fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_8 (26 B): matches/0x00152d90.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::**)(int))&this->f_18))(b);
}


// 0x00152db0 fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_2 (11 B): matches/0x00152db0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00152de0 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_6 (26 B): matches/0x00152de0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::**)(int))&this->f_10))(b);
}


// 0x00152e00 fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_2 (11 B): matches/0x00152e00.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitPushbackVelocityCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_2() {
    return this->f_10 == 0;
}

