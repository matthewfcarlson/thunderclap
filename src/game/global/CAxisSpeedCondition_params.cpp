// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e2e0..0x0004e3c0 (kind game, layer game, confidence high), dominant class CAxisSpeedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fceae395 {
#define TREE_TU_END }
namespace fn_fceae395 {} using namespace fn_fceae395;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fceae395 {
struct CAxisArcCondition_4e2e0;
class CStageCondition_4e2f0 {};
class ParamValue_4e2f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e2f0 : public ParamValue_4e2f0 {
  public:
    virtual void f();
};
class CStageCondition_4e380;
class ParamValue_4e380 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e380 : public ParamValue_4e380 {
  public:
    int pad;
};

} // namespace fn_fceae395

// 0x0004e2e0 fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_7 (6 B): matches/0x0004e2e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAxisSpeedCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e2f0 fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_6 (30 B): matches/0x0004e2f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAxisSpeedCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e2f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e2f0*)&DAT_003f335c));
}


// 0x0004e310 fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_8 (26 B): matches/0x0004e310.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAxisSpeedCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAxisSpeedCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAxisSpeedCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAxisSpeedCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e330 fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_2 (11 B): matches/0x0004e330.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAxisSpeedCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisSpeedCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e360 fight::ParamFloatConstRange<CAxisSpeedCondition>::vfunc_6 (26 B): matches/0x0004e360.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAxisSpeedCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisSpeedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAxisSpeedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAxisSpeedCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CAxisSpeedCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e380 fight::ParamFloatConstRange<CAxisSpeedCondition>::vfunc_2 (11 B): matches/0x0004e380.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAxisSpeedCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisSpeedCondition>::vfunc_2() {
    return this->f_10 == 0;
}

