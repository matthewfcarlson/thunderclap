// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e820..0x0004e8b0 (kind game, layer game, confidence high), dominant class CCharacterSizeCondition
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f63ce2d9 {
#define TREE_TU_END }
namespace fn_f63ce2d9 {} using namespace fn_f63ce2d9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f63ce2d9 {
struct CAxisArcCondition_4e820;
class CStageCondition_4e830 {};
class ParamValue_4e830 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e830 : public ParamValue_4e830 {
  public:
    virtual void f();
};

} // namespace fn_f63ce2d9

// 0x0004e820 fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_7 (6 B): matches/0x0004e820.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCharacterSizeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e830 fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_6 (30 B): matches/0x0004e830.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCharacterSizeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e830 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e830*)&DAT_003f335c));
}


// 0x0004e850 fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_8 (26 B): matches/0x0004e850.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCharacterSizeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCharacterSizeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCharacterSizeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCharacterSizeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004e870 fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_2 (11 B): matches/0x0004e870.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCharacterSizeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCharacterSizeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

