// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f140..0x0004f220 (kind game, layer game, confidence high), dominant class CSmartPropWeaponTypeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4a37b5c {
#define TREE_TU_END }
namespace fn_f4a37b5c {} using namespace fn_f4a37b5c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4a37b5c {
struct CAxisArcCondition_4f140;
class CStageCondition_4f150 {};
class ParamValue_4f150 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f150 : public ParamValue_4f150 {
  public:
    virtual void f();
};
class CStageCondition_4f1e0;
class ParamValue_4f1e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f1e0 : public ParamValue_4f1e0 {
  public:
    int pad;
};

} // namespace fn_f4a37b5c

// 0x0004f140 fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_7 (6 B): matches/0x0004f140.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropWeaponTypeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f150 fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_6 (30 B): matches/0x0004f150.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropWeaponTypeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f150 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f150*)&DAT_003f335c));
}


// 0x0004f170 fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_8 (26 B): matches/0x0004f170.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropWeaponTypeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f190 fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_2 (11 B): matches/0x0004f190.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropWeaponTypeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropWeaponTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f1c0 fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::vfunc_6 (26 B): matches/0x0004f1c0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCSmartPropWeaponTypeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f1e0 fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::vfunc_2 (11 B): matches/0x0004f1e0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCSmartPropWeaponTypeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropWeaponTypeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

