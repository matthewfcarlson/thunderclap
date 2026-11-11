// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110510..0x00110690 (kind game, layer game, confidence high), dominant class hulkfight::ai::PropsToSuckCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe2c2239 {
#define TREE_TU_END }
namespace fn_fe2c2239 {} using namespace fn_fe2c2239;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fe2c2239 {
struct CAxisArcCondition_110510;
class CStageCondition_110520 {};
class ParamValue_110520 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_110520 : public ParamValue_110520 {
  public:
    virtual void f();
};
class CStageCondition_1105b0;
class ParamValue_1105b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1105b0 : public ParamValue_1105b0 {
  public:
    int pad;
};
class CStageCondition_110600;
class ParamValue_110600 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110600 : public ParamValue_110600 {
  public:
    int pad;
};
class CStageCondition_110650;
class ParamValue_110650 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110650 : public ParamValue_110650 {
  public:
    int pad;
};

} // namespace fn_fe2c2239

// 0x00110510 fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_7 (6 B): matches/0x00110510.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00110520 fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_6 (30 B): matches/0x00110520.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_110520 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_110520*)&DAT_003f335c));
}


// 0x00110540 fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_8 (26 B): matches/0x00110540.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_18))(b);
}


// 0x00110560 fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_2 (11 B): matches/0x00110560.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::PropsToSuckCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00110590 fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_6 (26 B): matches/0x00110590.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_10))(b);
}


// 0x001105b0 fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_2 (11 B): matches/0x001105b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001105e0 fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::vfunc_6 (26 B): matches/0x001105e0.cpp
// sym: ?vfunc_6@?$ParamBool@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::PropsToSuckCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_10))(b);
}


// 0x00110600 fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::vfunc_2 (11 B): matches/0x00110600.cpp
// sym: ?vfunc_2@?$ParamBool@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::PropsToSuckCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00110630 fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_6 (26 B): matches/0x00110630.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::**)(int))&this->f_10))(b);
}


// 0x00110650 fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_2 (11 B): matches/0x00110650.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropsToSuckCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_2() {
    return this->f_10 == 0;
}

