// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004fa60..0x0004faf0 (kind game, layer game, confidence high), dominant class CCharacterTemplateVariationCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f50838da {
#define TREE_TU_END }
namespace fn_f50838da {} using namespace fn_f50838da;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f50838da {
struct CAxisArcCondition_4fa60;
class CStageCondition_4fa70 {};
class ParamValue_4fa70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fa70 : public ParamValue_4fa70 {
  public:
    virtual void f();
};

} // namespace fn_f50838da

// 0x0004fa60 fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_7 (6 B): matches/0x0004fa60.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCharacterTemplateVariationCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004fa70 fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_6 (30 B): matches/0x0004fa70.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fa70 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4fa70*)&DAT_003f335c));
}


// 0x0004fa90 fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_8 (26 B): matches/0x0004fa90.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCharacterTemplateVariationCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCharacterTemplateVariationCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::**)(int))&this->f_18))(b);
}


// 0x0004fab0 fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_2 (11 B): matches/0x0004fab0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCharacterTemplateVariationCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_2() {
    return this->f_18 == 0;
}

