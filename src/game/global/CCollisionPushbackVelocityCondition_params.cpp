// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ebb0..0x0004ec90 (kind game, layer game, confidence high), dominant class CCollisionPushbackVelocityCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5af4af0 {
#define TREE_TU_END }
namespace fn_f5af4af0 {} using namespace fn_f5af4af0;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5af4af0 {
struct CAxisArcCondition_4ebb0;
class CStageCondition_4ebc0 {};
class ParamValue_4ebc0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4ebc0 : public ParamValue_4ebc0 {
  public:
    virtual void f();
};
class CStageCondition_4ec50;
class ParamValue_4ec50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4ec50 : public ParamValue_4ec50 {
  public:
    int pad;
};

} // namespace fn_f5af4af0

// 0x0004ebb0 fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_7 (6 B): matches/0x0004ebb0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionPushbackVelocityCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004ebc0 fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_6 (30 B): matches/0x0004ebc0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionPushbackVelocityCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4ebc0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4ebc0*)&DAT_003f335c));
}


// 0x0004ebe0 fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_8 (26 B): matches/0x0004ebe0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionPushbackVelocityCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::**)(int))&this->f_18))(b);
}


// 0x0004ec00 fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_2 (11 B): matches/0x0004ec00.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionPushbackVelocityCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionPushbackVelocityCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004ec30 fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::vfunc_6 (26 B): matches/0x0004ec30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionPushbackVelocityCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::**)(int))&this->f_10))(b);
}


// 0x0004ec50 fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::vfunc_2 (11 B): matches/0x0004ec50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionPushbackVelocityCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackVelocityCondition>::vfunc_2() {
    return this->f_10 == 0;
}

