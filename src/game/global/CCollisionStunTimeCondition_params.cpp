// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ee50..0x0004ef20 (kind game, layer game, confidence high), dominant class CCollisionStunTimeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd9d9941 {
#define TREE_TU_END }
namespace fn_fd9d9941 {} using namespace fn_fd9d9941;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd9d9941 {
struct CAxisArcCondition_4ee50;
class CStageCondition_4ee60 {};
class ParamValue_4ee60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4ee60 : public ParamValue_4ee60 {
  public:
    virtual void f();
};
class CStageCondition_4eef0;
class ParamValue_4eef0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4eef0 : public ParamValue_4eef0 {
  public:
    int pad;
};

} // namespace fn_fd9d9941

// 0x0004ee50 fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_7 (6 B): matches/0x0004ee50.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCollisionStunTimeCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004ee60 fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_6 (30 B): matches/0x0004ee60.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCollisionStunTimeCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4ee60 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4ee60*)&DAT_003f335c));
}


// 0x0004ee80 fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_8 (26 B): matches/0x0004ee80.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCollisionStunTimeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCollisionStunTimeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCollisionStunTimeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CCollisionStunTimeCondition>::**)(int))&this->f_18))(b);
}


// 0x0004eea0 fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_2 (11 B): matches/0x0004eea0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCollisionStunTimeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCollisionStunTimeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004eed0 fight::ParamFloatConstRange<CCollisionStunTimeCondition>::vfunc_6 (26 B): matches/0x0004eed0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCollisionStunTimeCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionStunTimeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCollisionStunTimeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCollisionStunTimeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCollisionStunTimeCondition>::**)(int))&this->f_10))(b);
}


// 0x0004eef0 fight::ParamFloatConstRange<CCollisionStunTimeCondition>::vfunc_2 (11 B): matches/0x0004eef0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCollisionStunTimeCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCollisionStunTimeCondition>::vfunc_2() {
    return this->f_10 == 0;
}

