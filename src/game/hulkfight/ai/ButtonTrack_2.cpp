// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110b50..0x00110c30 (kind game, layer game, confidence high), dominant class hulkfight::ai::ButtonTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_feac1606 {
#define TREE_TU_END }
namespace fn_feac1606 {} using namespace fn_feac1606;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_feac1606 {
class CStageCondition_110b70;
class ParamValue_110b70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110b70 : public ParamValue_110b70 {
  public:
    int pad;
};
struct CAxisArcCondition_110bb0;
class CStageCondition_110bc0 {};
class ParamValue_110bc0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_110bc0 : public ParamValue_110bc0 {
  public:
    virtual void f();
};

} // namespace fn_feac1606

// 0x00110b50 fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::vfunc_6 (26 B): matches/0x00110b50.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VButtonTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::**)(int))&this->f_10))(b);
}


// 0x00110b70 fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::vfunc_2 (11 B): matches/0x00110b70.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VButtonTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ButtonTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110bb0 fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_7 (6 B): matches/0x00110bb0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VButtonTrack@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00110bc0 fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_6 (30 B): matches/0x00110bc0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VButtonTrack@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_110bc0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_110bc0*)&DAT_003f335c));
}


// 0x00110be0 fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_8 (26 B): matches/0x00110be0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VButtonTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::**)(int))&this->f_18))(b);
}


// 0x00110c00 fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_2 (11 B): matches/0x00110c00.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VButtonTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ButtonTrack>::vfunc_2() {
    return this->f_18 == 0;
}

