// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e3c0..0x0004e4a0 (kind game, layer game, confidence high), dominant class CAxisValueCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f93d5461 {
#define TREE_TU_END }
namespace fn_f93d5461 {} using namespace fn_f93d5461;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f93d5461 {
struct CAxisArcCondition_4e3c0;
class CStageCondition_4e3d0 {};
class ParamValue_4e3d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e3d0 : public ParamValue_4e3d0 {
  public:
    virtual void f();
};
class CStageCondition_4e460;
class ParamValue_4e460 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e460 : public ParamValue_4e460 {
  public:
    int pad;
};

} // namespace fn_f93d5461

// 0x0004e3c0 fight::ParamEnumConstList<CAxisValueCondition>::vfunc_7 (6 B): matches/0x0004e3c0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCAxisValueCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CAxisValueCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e3d0 fight::ParamEnumConstList<CAxisValueCondition>::vfunc_6 (30 B): matches/0x0004e3d0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCAxisValueCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CAxisValueCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e3d0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e3d0*)&DAT_003f335c));
}


// 0x0004e3f0 fight::ParamEnumConstList<CAxisValueCondition>::vfunc_8 (26 B): matches/0x0004e3f0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCAxisValueCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisValueCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAxisValueCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAxisValueCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CAxisValueCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e410 fight::ParamEnumConstList<CAxisValueCondition>::vfunc_2 (11 B): matches/0x0004e410.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCAxisValueCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CAxisValueCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004e440 fight::ParamFloatConstRange<CAxisValueCondition>::vfunc_6 (26 B): matches/0x0004e440.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCAxisValueCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisValueCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CAxisValueCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CAxisValueCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CAxisValueCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e460 fight::ParamFloatConstRange<CAxisValueCondition>::vfunc_2 (11 B): matches/0x0004e460.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCAxisValueCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CAxisValueCondition>::vfunc_2() {
    return this->f_10 == 0;
}

