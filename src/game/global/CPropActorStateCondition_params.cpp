// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004f720..0x0004f800 (kind game, layer game, confidence high), dominant class CPropActorStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4eb38d5 {
#define TREE_TU_END }
namespace fn_f4eb38d5 {} using namespace fn_f4eb38d5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4eb38d5 {
struct CAxisArcCondition_4f720;
class CStageCondition_4f730 {};
class ParamValue_4f730 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f730 : public ParamValue_4f730 {
  public:
    virtual void f();
};
class CStageCondition_4f7c0;
class ParamValue_4f7c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f7c0 : public ParamValue_4f7c0 {
  public:
    int pad;
};

} // namespace fn_f4eb38d5

// 0x0004f720 fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_7 (6 B): matches/0x0004f720.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCPropActorStateCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004f730 fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_6 (30 B): matches/0x0004f730.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCPropActorStateCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f730 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f730*)&DAT_003f335c));
}


// 0x0004f750 fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_8 (26 B): matches/0x0004f750.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCPropActorStateCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CPropActorStateCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CPropActorStateCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CPropActorStateCondition>::**)(int))&this->f_18))(b);
}


// 0x0004f770 fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_2 (11 B): matches/0x0004f770.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCPropActorStateCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f7a0 fight::ParamIntConstRange<CPropActorStateCondition>::vfunc_6 (26 B): matches/0x0004f7a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCPropActorStateCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CPropActorStateCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CPropActorStateCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CPropActorStateCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CPropActorStateCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f7c0 fight::ParamIntConstRange<CPropActorStateCondition>::vfunc_2 (11 B): matches/0x0004f7c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCPropActorStateCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CPropActorStateCondition>::vfunc_2() {
    return this->f_10 == 0;
}

