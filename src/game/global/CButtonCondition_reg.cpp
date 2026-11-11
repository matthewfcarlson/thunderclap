// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e030..0x0004e120 (kind game, layer game, confidence high), dominant class CButtonCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0f4f55e {
#define TREE_TU_END }
namespace fn_f0f4f55e {} using namespace fn_f0f4f55e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0f4f55e {
struct CAxisArcCondition_4e030;
class CStageCondition_4e040 {};
class ParamValue_4e040 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e040 : public ParamValue_4e040 {
  public:
    virtual void f();
};
class CStageCondition_4e0e0;
class ParamValue_4e0e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e0e0 : public ParamValue_4e0e0 {
  public:
    int pad;
};

} // namespace fn_f0f4f55e

// 0x0004e030 fight::ParamEnumConstList<CButtonCondition>::vfunc_7 (6 B): matches/0x0004e030.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCButtonCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CButtonCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e040 fight::ParamEnumConstList<CButtonCondition>::vfunc_6 (30 B): matches/0x0004e040.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCButtonCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CButtonCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e040 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e040*)&DAT_003f335c));
}


// 0x0004e060 fight::ParamEnumConstList<CButtonCondition>::vfunc_8 (26 B): matches/0x0004e060.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCButtonCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CButtonCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CButtonCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CButtonCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CButtonCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e080 fight::ParamEnumConstList<CButtonCondition>::vfunc_2 (11 B): matches/0x0004e080.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCButtonCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CButtonCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e0b0 fight::ParamValueFloat::vfunc_1 (6 B): matches/0x0004e0b0.cpp
// sym: ?vfunc_1@ParamValueFloat@fight@@UAEHXZ
int fight::ParamValueFloat::vfunc_1() {
    return 2;
}


// 0x0004e0c0 fight::ParamFloatConstRange<CButtonCondition>::vfunc_6 (26 B): matches/0x0004e0c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCButtonCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CButtonCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CButtonCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CButtonCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CButtonCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e0e0 fight::ParamFloatConstRange<CButtonCondition>::vfunc_2 (11 B): matches/0x0004e0e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCButtonCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CButtonCondition>::vfunc_2() {
    return this->f_10 == 0;
}

