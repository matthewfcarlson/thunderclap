// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110690..0x00110740 (kind game, layer game, confidence high), dominant class hulkfight::ai::RandomKeyWordWaitCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fca7b994 {
#define TREE_TU_END }
namespace fn_fca7b994 {} using namespace fn_fca7b994;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fca7b994 {
struct CAxisArcCondition_110690;
class CStageCondition_1106a0 {};
class ParamValue_1106a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1106a0 : public ParamValue_1106a0 {
  public:
    virtual void f();
};
class CStageCondition_110730;
class ParamValue_110730 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110730 : public ParamValue_110730 {
  public:
    int pad;
};

} // namespace fn_fca7b994

// 0x00110690 fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_7 (6 B): matches/0x00110690.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001106a0 fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_6 (30 B): matches/0x001106a0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1106a0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1106a0*)&DAT_003f335c));
}


// 0x001106c0 fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_8 (26 B): matches/0x001106c0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::**)(int))&this->f_18))(b);
}


// 0x001106e0 fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_2 (11 B): matches/0x001106e0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00110710 fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_6 (26 B): matches/0x00110710.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::**)(int))&this->f_10))(b);
}


// 0x00110730 fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_2 (11 B): matches/0x00110730.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VRandomKeyWordWaitCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_2() {
    return this->f_10 == 0;
}

