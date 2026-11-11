// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110220..0x00110300 (kind game, layer game, confidence high), dominant class hulkfight::ai::FormationReadyCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f53436f7 {
#define TREE_TU_END }
namespace fn_f53436f7 {} using namespace fn_f53436f7;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f53436f7 {
struct CAxisArcCondition_110220;
class CStageCondition_110230 {};
class ParamValue_110230 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_110230 : public ParamValue_110230 {
  public:
    virtual void f();
};
class CStageCondition_1102c0;
class ParamValue_1102c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1102c0 : public ParamValue_1102c0 {
  public:
    int pad;
};

} // namespace fn_f53436f7

// 0x00110220 fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_7 (6 B): matches/0x00110220.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00110230 fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_6 (30 B): matches/0x00110230.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_110230 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_110230*)&DAT_003f335c));
}


// 0x00110250 fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_8 (26 B): matches/0x00110250.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFormationReadyCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::**)(int))&this->f_18))(b);
}


// 0x00110270 fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_2 (11 B): matches/0x00110270.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFormationReadyCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001102a0 fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_6 (26 B): matches/0x001102a0.cpp
// sym: ?vfunc_6@?$ParamString@VFormationReadyCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::FormationReadyCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::FormationReadyCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::FormationReadyCondition>::**)(int))&this->f_10))(b);
}


// 0x001102c0 fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_2 (11 B): matches/0x001102c0.cpp
// sym: ?vfunc_2@?$ParamString@VFormationReadyCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_2() {
    return this->f_10 == 0;
}

