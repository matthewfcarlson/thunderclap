// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185570..0x00185650 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropStateByIndexCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f710dcb0 {
#define TREE_TU_END }
namespace fn_f710dcb0 {} using namespace fn_f710dcb0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f710dcb0 {
class CStageCondition_185590;
class ParamValue_185590 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185590 : public ParamValue_185590 {
  public:
    int pad;
};
struct CAxisArcCondition_1855d0;
class CStageCondition_1855e0 {};
class ParamValue_1855e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1855e0 : public ParamValue_1855e0 {
  public:
    virtual void f();
};

} // namespace fn_f710dcb0

// 0x00185570 fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::vfunc_6 (26 B): matches/0x00185570.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::**)(int))&this->f_10))(b);
}


// 0x00185590 fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::vfunc_2 (11 B): matches/0x00185590.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001855d0 fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_7 (6 B): matches/0x001855d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001855e0 fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_6 (30 B): matches/0x001855e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1855e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1855e0*)&DAT_003f335c));
}


// 0x00185600 fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_8 (26 B): matches/0x00185600.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::**)(int))&this->f_18))(b);
}


// 0x00185620 fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_2 (11 B): matches/0x00185620.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VPropStateByIndexCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition>::vfunc_2() {
    return this->f_18 == 0;
}

