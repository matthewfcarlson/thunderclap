// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00152b80..0x00152d00 (kind game, layer game, confidence high), dominant class hulkfight::motion::CollisionTargetSizeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f09a962c {
#define TREE_TU_END }
namespace fn_f09a962c {} using namespace fn_f09a962c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f09a962c {
class CStageCondition_152ba0;
class ParamValue_152ba0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152ba0 : public ParamValue_152ba0 {
  public:
    int pad;
};
class CStageCondition_152bf0;
class ParamValue_152bf0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152bf0 : public ParamValue_152bf0 {
  public:
    int pad;
};
class CStageCondition_152c40;
class ParamValue_152c40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152c40 : public ParamValue_152c40 {
  public:
    int pad;
};
struct CAxisArcCondition_152c80;
class CStageCondition_152c90 {};
class ParamValue_152c90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152c90 : public ParamValue_152c90 {
  public:
    virtual void f();
};

} // namespace fn_f09a962c

// 0x00152b80 fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_6 (26 B): matches/0x00152b80.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::**)(int))&this->f_10))(b);
}


// 0x00152ba0 fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_2 (11 B): matches/0x00152ba0.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152bd0 fight::ParamBool<hulkfight::motion::HitPushbackCondition>::vfunc_6 (26 B): matches/0x00152bd0.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitPushbackCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HitPushbackCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HitPushbackCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HitPushbackCondition>::**)(int))&this->f_10))(b);
}


// 0x00152bf0 fight::ParamBool<hulkfight::motion::HitPushbackCondition>::vfunc_2 (11 B): matches/0x00152bf0.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitPushbackCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152c20 fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_6 (26 B): matches/0x00152c20.cpp
// sym: ?vfunc_6@?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x00152c40 fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_2 (11 B): matches/0x00152c40.cpp
// sym: ?vfunc_2@?$ParamBool@VCollisionDevastatorCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::CollisionTargetIsTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00152c80 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_7 (6 B): matches/0x00152c80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00152c90 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_6 (30 B): matches/0x00152c90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152c90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_152c90*)&DAT_003f335c));
}


// 0x00152cb0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_8 (26 B): matches/0x00152cb0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::**)(int))&this->f_18))(b);
}


// 0x00152cd0 fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_2 (11 B): matches/0x00152cd0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCollisionTargetSizeCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

