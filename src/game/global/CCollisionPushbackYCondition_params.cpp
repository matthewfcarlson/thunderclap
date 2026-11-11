// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ec90..0x0004ed70 (kind game, layer game, confidence high), dominant class CCollisionPushbackYCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f33a1636 {
#define TREE_TU_END }
namespace fn_f33a1636 {} using namespace fn_f33a1636;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f33a1636 {
struct CAxisArcCondition_4ec90;
class CStageCondition_4eca0 {};
class ParamValue_4eca0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4eca0 : public ParamValue_4eca0 {
  public:
    virtual void f();
};
class CStageCondition_4ed30;
class ParamValue_4ed30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4ed30 : public ParamValue_4ed30 {
  public:
    int pad;
};

} // namespace fn_f33a1636

// 0x0004ec90 fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_7 (6 B): matches/0x0004ec90.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionPushbackYCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004eca0 fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_6 (30 B): matches/0x0004eca0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionPushbackYCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4eca0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4eca0*)&DAT_003f335c));
}


// 0x0004ecc0 fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_8 (26 B): matches/0x0004ecc0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionPushbackYCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionPushbackYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionPushbackYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionPushbackYCondition>::**)(int))&this->f_18))(b);
}


// 0x0004ece0 fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_2 (11 B): matches/0x0004ece0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionPushbackYCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004ed10 fight::ParamFloatConstRange<CCollisionPushbackYCondition>::vfunc_6 (26 B): matches/0x0004ed10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionPushbackYCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionPushbackYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionPushbackYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionPushbackYCondition>::**)(int))&this->f_10))(b);
}


// 0x0004ed30 fight::ParamFloatConstRange<CCollisionPushbackYCondition>::vfunc_2 (11 B): matches/0x0004ed30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionPushbackYCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackYCondition>::vfunc_2() {
    return this->f_10 == 0;
}

