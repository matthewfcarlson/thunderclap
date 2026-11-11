// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e120..0x0004e200 (kind game, layer game, confidence high), dominant class CButtonValueCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f5dcba9c {
#define TREE_TU_END }
namespace fn_f5dcba9c {} using namespace fn_f5dcba9c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5dcba9c {
struct CAxisArcCondition_4e120;
class CStageCondition_4e130 {};
class ParamValue_4e130 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e130 : public ParamValue_4e130 {
  public:
    virtual void f();
};
class CStageCondition_4e1c0;
class ParamValue_4e1c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e1c0 : public ParamValue_4e1c0 {
  public:
    int pad;
};

} // namespace fn_f5dcba9c

// 0x0004e120 fight::ParamEnumConstList<CButtonValueCondition>::vfunc_7 (6 B): matches/0x0004e120.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCButtonValueCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CButtonValueCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e130 fight::ParamEnumConstList<CButtonValueCondition>::vfunc_6 (30 B): matches/0x0004e130.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCButtonValueCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CButtonValueCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e130 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e130*)&DAT_003f335c));
}


// 0x0004e150 fight::ParamEnumConstList<CButtonValueCondition>::vfunc_8 (26 B): matches/0x0004e150.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCButtonValueCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CButtonValueCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CButtonValueCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CButtonValueCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CButtonValueCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e170 fight::ParamEnumConstList<CButtonValueCondition>::vfunc_2 (11 B): matches/0x0004e170.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCButtonValueCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CButtonValueCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e1a0 fight::ParamFloatConstRange<CButtonValueCondition>::vfunc_6 (26 B): matches/0x0004e1a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCButtonValueCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CButtonValueCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CButtonValueCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CButtonValueCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CButtonValueCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e1c0 fight::ParamFloatConstRange<CButtonValueCondition>::vfunc_2 (11 B): matches/0x0004e1c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCButtonValueCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CButtonValueCondition>::vfunc_2() {
    return this->f_10 == 0;
}

