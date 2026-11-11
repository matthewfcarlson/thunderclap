// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e580..0x0004e660 (kind game, layer game, confidence high), dominant class CAxisDoubleTapCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_faa5990d {
#define TREE_TU_END }
namespace fn_faa5990d {} using namespace fn_faa5990d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faa5990d {
struct CAxisArcCondition_4e580;
class CStageCondition_4e590 {};
class ParamValue_4e590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e590 : public ParamValue_4e590 {
  public:
    virtual void f();
};
class CStageCondition_4e620;
class ParamValue_4e620 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e620 : public ParamValue_4e620 {
  public:
    int pad;
};

} // namespace fn_faa5990d

// 0x0004e580 fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_7 (6 B): matches/0x0004e580.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAxisDoubleTapCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e590 fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_6 (30 B): matches/0x0004e590.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAxisDoubleTapCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e590 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e590*)&DAT_003f335c));
}


// 0x0004e5b0 fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_8 (26 B): matches/0x0004e5b0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAxisDoubleTapCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAxisDoubleTapCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAxisDoubleTapCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAxisDoubleTapCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e5d0 fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_2 (11 B): matches/0x0004e5d0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAxisDoubleTapCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisDoubleTapCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e600 fight::ParamFloatConstRange<CAxisDoubleTapCondition>::vfunc_6 (26 B): matches/0x0004e600.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAxisDoubleTapCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisDoubleTapCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAxisDoubleTapCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAxisDoubleTapCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CAxisDoubleTapCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e620 fight::ParamFloatConstRange<CAxisDoubleTapCondition>::vfunc_2 (11 B): matches/0x0004e620.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAxisDoubleTapCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisDoubleTapCondition>::vfunc_2() {
    return this->f_10 == 0;
}

