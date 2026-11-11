// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ea70..0x0004ebb0 (kind game, layer game, confidence high), dominant class CCollisionHeightCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f532f42c {
#define TREE_TU_END }
namespace fn_f532f42c {} using namespace fn_f532f42c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f532f42c {
class CStageCondition_4ea90;
class ParamValue_4ea90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4ea90 : public ParamValue_4ea90 {
  public:
    int pad;
};
struct CAxisArcCondition_4ead0;
class CStageCondition_4eae0 {};
class ParamValue_4eae0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4eae0 : public ParamValue_4eae0 {
  public:
    virtual void f();
};
class CStageCondition_4eb70;
class ParamValue_4eb70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4eb70 : public ParamValue_4eb70 {
  public:
    int pad;
};

} // namespace fn_f532f42c

// 0x0004ea70 fight::ParamBool<CCollisionInterruptCondition>::vfunc_6 (26 B): matches/0x0004ea70.cpp
// sym: ?vfunc_6@?$ParamBool@VCCollisionInterruptCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CCollisionInterruptCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CCollisionInterruptCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CCollisionInterruptCondition>*)a)->*(*(bool (fight::ParamBool<CCollisionInterruptCondition>::**)(int))&this->f_10))(b);
}


// 0x0004ea90 fight::ParamBool<CCollisionInterruptCondition>::vfunc_2 (11 B): matches/0x0004ea90.cpp
// sym: ?vfunc_2@?$ParamBool@VCCollisionInterruptCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CCollisionInterruptCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004ead0 fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_7 (6 B): matches/0x0004ead0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionHeightCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004eae0 fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_6 (30 B): matches/0x0004eae0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionHeightCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4eae0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4eae0*)&DAT_003f335c));
}


// 0x0004eb00 fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_8 (26 B): matches/0x0004eb00.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionHeightCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionHeightCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionHeightCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionHeightCondition>::**)(int))&this->f_18))(b);
}


// 0x0004eb20 fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_2 (11 B): matches/0x0004eb20.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionHeightCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionHeightCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004eb50 fight::ParamFloatConstRange<CCollisionHeightCondition>::vfunc_6 (26 B): matches/0x0004eb50.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionHeightCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionHeightCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionHeightCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionHeightCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionHeightCondition>::**)(int))&this->f_10))(b);
}


// 0x0004eb70 fight::ParamFloatConstRange<CCollisionHeightCondition>::vfunc_2 (11 B): matches/0x0004eb70.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionHeightCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionHeightCondition>::vfunc_2() {
    return this->f_10 == 0;
}

