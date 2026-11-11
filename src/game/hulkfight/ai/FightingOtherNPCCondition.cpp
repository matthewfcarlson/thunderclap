// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110740..0x00110840 (kind game, layer game, confidence high), dominant class hulkfight::ai::FightingOtherNPCCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff0a3e73 {
#define TREE_TU_END }
namespace fn_ff0a3e73 {} using namespace fn_ff0a3e73;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_ff0a3e73 {
extern void* g_vftable[];
class ParamValueBool_110740 {
  public:
    ParamValueBool_110740(int a);
    virtual void f0();
    char pad[12];
};
class ParamBool_110740 : public ParamValueBool_110740 {
  public:
    ParamBool_110740(int a, int b);
    virtual void f0();
    int m10;
};
class CStageCondition_110780;
class ParamValue_110780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110780 : public ParamValue_110780 {
  public:
    int pad;
};
struct CAxisArcCondition_1107c0;
class CStageCondition_1107d0 {};
class ParamValue_1107d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1107d0 : public ParamValue_1107d0 {
  public:
    virtual void f();
};


// 0x00110740 FUN_00110740 (32 B): matches/0x00110740.cpp
// sym: ??0ParamBool_110740@fn_ff0a3e73@@QAE@HH@Z
ParamBool_110740::ParamBool_110740(int a, int b) : ParamValueBool_110740(a) {
    m10 = b;
}

} // namespace fn_ff0a3e73

// 0x00110760 fight::ParamBool<hulkfight::ai::TokenCondition>::vfunc_6 (26 B): matches/0x00110760.cpp
// sym: ?vfunc_6@?$ParamBool@VTokenCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TokenCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TokenCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TokenCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TokenCondition>::**)(int))&this->f_10))(b);
}


// 0x00110780 fight::ParamBool<hulkfight::ai::TokenCondition>::vfunc_2 (11 B): matches/0x00110780.cpp
// sym: ?vfunc_2@?$ParamBool@VTokenCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TokenCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001107c0 fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_7 (6 B): matches/0x001107c0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001107d0 fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_6 (30 B): matches/0x001107d0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1107d0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1107d0*)&DAT_003f335c));
}


// 0x001107f0 fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_8 (26 B): matches/0x001107f0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::**)(int))&this->f_18))(b);
}


// 0x00110810 fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_2 (11 B): matches/0x00110810.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFightingOtherNPCCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::FightingOtherNPCCondition>::vfunc_2() {
    return this->f_18 == 0;
}

