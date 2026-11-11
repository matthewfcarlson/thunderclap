// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004faf0..0x0004fb80 (kind game, layer game, confidence high), dominant class CGrappleCharacterTemplateCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff080e88 {
#define TREE_TU_END }
namespace fn_ff080e88 {} using namespace fn_ff080e88;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff080e88 {
struct CAxisArcCondition_4faf0;
class CStageCondition_4fb00 {};
class ParamValue_4fb00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fb00 : public ParamValue_4fb00 {
  public:
    virtual void f();
};

} // namespace fn_ff080e88

// 0x0004faf0 fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_7 (6 B): matches/0x0004faf0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCGrappleCharacterTemplateCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004fb00 fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_6 (30 B): matches/0x0004fb00.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fb00 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4fb00*)&DAT_003f335c));
}


// 0x0004fb20 fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_8 (26 B): matches/0x0004fb20.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCGrappleCharacterTemplateCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::**)(int))&this->f_18))(b);
}


// 0x0004fb40 fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_2 (11 B): matches/0x0004fb40.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCGrappleCharacterTemplateCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_2() {
    return this->f_18 == 0;
}

