// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110300..0x001103e0 (kind game, layer game, confidence high), dominant class hulkfight::ai::InActiveCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4f13e59 {
#define TREE_TU_END }
namespace fn_f4f13e59 {} using namespace fn_f4f13e59;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f4f13e59 {
struct CAxisArcCondition_110300;
class CStageCondition_110310 {};
class ParamValue_110310 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_110310 : public ParamValue_110310 {
  public:
    virtual void f();
};
class CStageCondition_1103a0;
class ParamValue_1103a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1103a0 : public ParamValue_1103a0 {
  public:
    int pad;
};

} // namespace fn_f4f13e59

// 0x00110300 fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_7 (6 B): matches/0x00110300.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VInActiveCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00110310 fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_6 (30 B): matches/0x00110310.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VInActiveCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_110310 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_110310*)&DAT_003f335c));
}


// 0x00110330 fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_8 (26 B): matches/0x00110330.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VInActiveCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::**)(int))&this->f_18))(b);
}


// 0x00110350 fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_2 (11 B): matches/0x00110350.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VInActiveCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::InActiveCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00110380 fight::ParamBool<hulkfight::ai::InActiveCondition>::vfunc_6 (26 B): matches/0x00110380.cpp
// sym: ?vfunc_6@?$ParamBool@VInActiveCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::InActiveCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::InActiveCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::InActiveCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::InActiveCondition>::**)(int))&this->f_10))(b);
}


// 0x001103a0 fight::ParamBool<hulkfight::ai::InActiveCondition>::vfunc_2 (11 B): matches/0x001103a0.cpp
// sym: ?vfunc_2@?$ParamBool@VInActiveCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::InActiveCondition>::vfunc_2() {
    return this->f_10 == 0;
}

