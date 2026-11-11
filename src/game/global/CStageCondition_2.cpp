// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004df40..0x0004e030 (kind game, layer game, confidence high), dominant class CStageCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f61fa68f {
#define TREE_TU_END }
namespace fn_f61fa68f {} using namespace fn_f61fa68f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f61fa68f {
struct CAxisArcCondition_4df40;
class CStageCondition_4df50 {};
class ParamValue_4df50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4df50 : public ParamValue_4df50 {
  public:
    virtual void f();
};
class pddiObject_4dfc0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_4dfc0 : public pddiObject_4dfc0 {};
class pddiBaseShader_4dfc0 : public pddiShader_4dfc0 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_4dfc0 : public pddiBaseShader_4dfc0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class CStageCondition_4dff0;
class ParamValue_4dff0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4dff0 : public ParamValue_4dff0 {
  public:
    int pad;
};

} // namespace fn_f61fa68f

// 0x0004df40 fight::ParamEnumConstList<CStageCondition>::vfunc_7 (6 B): matches/0x0004df40.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCStageCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CStageCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004df50 fight::ParamEnumConstList<CStageCondition>::vfunc_6 (30 B): matches/0x0004df50.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCStageCondition@@@fight@@UAEPAXHH@Z
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CStageCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4df50 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4df50*)&DAT_003f335c));
}


// 0x0004df70 fight::ParamEnumConstList<CStageCondition>::vfunc_8 (26 B): matches/0x0004df70.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCStageCondition@@@fight@@UAE_NHH@Z
template <> bool fight::ParamEnumConstList<CStageCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CStageCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CStageCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CStageCondition>::**)(int))&this->f_18))(b);
}


// 0x0004df90 fight::ParamEnumConstList<CStageCondition>::vfunc_2 (11 B): matches/0x0004df90.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCStageCondition@@@fight@@UAE_NXZ
template <> bool fight::ParamEnumConstList<CStageCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004dfc0 fight::ParamValueInt::vfunc_1 (6 B): matches/0x0004dfc0.cpp
// sym: ?vfunc_1@ParamValueInt@fight@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int fight::ParamValueInt::vfunc_1() {
    return 1;
}


// 0x0004dfd0 fight::ParamIntConstRange<CStageCondition>::vfunc_6 (26 B): matches/0x0004dfd0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCStageCondition@@@fight@@UAE_NHH@Z
template <> bool fight::ParamIntConstRange<CStageCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CStageCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CStageCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CStageCondition>::**)(int))&this->f_10))(b);
}


// 0x0004dff0 fight::ParamIntConstRange<CStageCondition>::vfunc_2 (11 B): matches/0x0004dff0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCStageCondition@@@fight@@UAE_NXZ
template <> bool fight::ParamIntConstRange<CStageCondition>::vfunc_2() {
    return this->f_10 == 0;
}

