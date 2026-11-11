// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f060..0x0004f140 (kind game, layer game, confidence high), dominant class CSmartPropWeaponizableTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f12cfdc1 {
#define TREE_TU_END }
namespace fn_f12cfdc1 {} using namespace fn_f12cfdc1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f12cfdc1 {
struct CAxisArcCondition_4f060;
class CStageCondition_4f070 {};
class ParamValue_4f070 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f070 : public ParamValue_4f070 {
  public:
    virtual void f();
};
class CStageCondition_4f100;
class ParamValue_4f100 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f100 : public ParamValue_4f100 {
  public:
    int pad;
};

} // namespace fn_f12cfdc1

// 0x0004f060 fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_7 (6 B): matches/0x0004f060.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropWeaponizableTypeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f070 fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_6 (30 B): matches/0x0004f070.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropWeaponizableTypeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f070 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f070*)&DAT_003f335c));
}


// 0x0004f090 fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_8 (26 B): matches/0x0004f090.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropWeaponizableTypeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f0b0 fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_2 (11 B): matches/0x0004f0b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropWeaponizableTypeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f0e0 fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::vfunc_6 (26 B): matches/0x0004f0e0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCSmartPropWeaponizableTypeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f100 fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::vfunc_2 (11 B): matches/0x0004f100.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCSmartPropWeaponizableTypeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropWeaponizableTypeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

