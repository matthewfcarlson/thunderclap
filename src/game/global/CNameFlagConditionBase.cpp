// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004e930..0x0004ea60 (kind game, layer game, confidence high), dominant class CNameFlagConditionBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe808e66 {
#define TREE_TU_END }
namespace fn_fe808e66 {} using namespace fn_fe808e66;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe808e66 {
class CStageCondition_4e950;
class ParamValue_4e950 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e950 : public ParamValue_4e950 {
  public:
    int pad;
};
class CStageCondition_4e9a0;
class ParamValue_4e9a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4e9a0 : public ParamValue_4e9a0 {
  public:
    int pad;
};
struct CAxisArcCondition_4e9e0;
class CStageCondition_4e9f0 {};
class ParamValue_4e9f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e9f0 : public ParamValue_4e9f0 {
  public:
    virtual void f();
};

} // namespace fn_fe808e66

// 0x0004e930 fight::ParamFloatConstRange<CCollisionDirectionCondition>::vfunc_6 (26 B): matches/0x0004e930.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionDirectionCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionDirectionCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionDirectionCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionDirectionCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionDirectionCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e950 fight::ParamFloatConstRange<CCollisionDirectionCondition>::vfunc_2 (11 B): matches/0x0004e950.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionDirectionCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionDirectionCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004e980 fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::vfunc_6 (26 B): matches/0x0004e980.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionDirectionCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::**)(int))&this->f_10))(b);
}


// 0x0004e9a0 fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::vfunc_2 (11 B): matches/0x0004e9a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionDirectionCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionPushbackDirectionCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004e9e0 fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_7 (6 B): matches/0x0004e9e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCNameFlagConditionBase@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004e9f0 fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_6 (30 B): matches/0x0004e9f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCNameFlagConditionBase@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e9f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4e9f0*)&DAT_003f335c));
}


// 0x0004ea10 fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_8 (26 B): matches/0x0004ea10.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCNameFlagConditionBase@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CNameFlagConditionBase>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CNameFlagConditionBase>*>(a)->*(*(bool (fight::ParamEnumConstList<CNameFlagConditionBase>::**)(int))&this->f_18))(b);
}


// 0x0004ea30 fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_2 (11 B): matches/0x0004ea30.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCNameFlagConditionBase@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_2() {
    return this->f_18 == 0;
}

