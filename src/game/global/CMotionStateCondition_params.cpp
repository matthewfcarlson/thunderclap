// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004fb80..0x0004fc10 (kind game, layer game, confidence high), dominant class CMotionStateCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbd6e288 {
#define TREE_TU_END }
namespace fn_fbd6e288 {} using namespace fn_fbd6e288;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbd6e288 {
struct CAxisArcCondition_4fb80;
class CStageCondition_4fb90 {};
class ParamValue_4fb90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fb90 : public ParamValue_4fb90 {
  public:
    virtual void f();
};

} // namespace fn_fbd6e288

// 0x0004fb80 fight::ParamEnumConstList<CMotionStateCondition>::vfunc_7 (6 B): matches/0x0004fb80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCMotionStateCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CMotionStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004fb90 fight::ParamEnumConstList<CMotionStateCondition>::vfunc_6 (30 B): matches/0x0004fb90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCMotionStateCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CMotionStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fb90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4fb90*)&DAT_003f335c));
}


// 0x0004fbb0 fight::ParamEnumConstList<CMotionStateCondition>::vfunc_8 (26 B): matches/0x0004fbb0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCMotionStateCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CMotionStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CMotionStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CMotionStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CMotionStateCondition>::**)(int))&this->f_18))(b);
}


// 0x0004fbd0 fight::ParamEnumConstList<CMotionStateCondition>::vfunc_2 (11 B): matches/0x0004fbd0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCMotionStateCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CMotionStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}

