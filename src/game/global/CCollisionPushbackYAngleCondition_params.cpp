// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ed70..0x0004ee50 (kind game, layer game, confidence high), dominant class CCollisionPushbackYAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4ec2478 {
#define TREE_TU_END }
namespace fn_f4ec2478 {} using namespace fn_f4ec2478;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4ec2478 {
struct CAxisArcCondition_4ed70;
class CStageCondition_4ed80 {};
class ParamValue_4ed80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4ed80 : public ParamValue_4ed80 {
  public:
    virtual void f();
};
class CStageCondition_4ee10;
class ParamValue_4ee10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4ee10 : public ParamValue_4ee10 {
  public:
    int pad;
};

} // namespace fn_f4ec2478

// 0x0004ed70 fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_7 (6 B): matches/0x0004ed70.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionPushbackYAngleCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004ed80 fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_6 (30 B): matches/0x0004ed80.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionPushbackYAngleCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4ed80 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4ed80*)&DAT_003f335c));
}


// 0x0004eda0 fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_8 (26 B): matches/0x0004eda0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionPushbackYAngleCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::**)(int))&this->f_18))(b);
}


// 0x0004edc0 fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_2 (11 B): matches/0x0004edc0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionPushbackYAngleCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionPushbackYAngleCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004edf0 fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::vfunc_6 (26 B): matches/0x0004edf0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionPushbackYAngleCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::**)(int))&this->f_10))(b);
}


// 0x0004ee10 fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::vfunc_2 (11 B): matches/0x0004ee10.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionPushbackYAngleCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackYAngleCondition>::vfunc_2() {
    return this->f_10 == 0;
}

