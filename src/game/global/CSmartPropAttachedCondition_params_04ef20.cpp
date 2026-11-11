// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ef20..0x0004f060 (kind game, layer game, confidence high), dominant class CSmartPropAttachedCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f36efe38 {
#define TREE_TU_END }
namespace fn_f36efe38 {} using namespace fn_f36efe38;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f36efe38 {
class CStageCondition_4ef40;
class ParamValue_4ef40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4ef40 : public ParamValue_4ef40 {
  public:
    int pad;
};
struct CAxisArcCondition_4ef80;
class CStageCondition_4ef90 {};
class ParamValue_4ef90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4ef90 : public ParamValue_4ef90 {
  public:
    virtual void f();
};
class CStageCondition_4f020;
class ParamValue_4f020 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4f020 : public ParamValue_4f020 {
  public:
    int pad;
};

} // namespace fn_f36efe38

// 0x0004ef20 fight::ParamBool<CSmartPropAttachedCondition>::vfunc_6 (26 B): matches/0x0004ef20.cpp
// sym: ?vfunc_6@?$ParamBool@VCSmartPropAttachedCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropAttachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSmartPropAttachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSmartPropAttachedCondition>*)a)->*(*(bool (fight::ParamBool<CSmartPropAttachedCondition>::**)(int))&this->f_10))(b);
}


// 0x0004ef40 fight::ParamBool<CSmartPropAttachedCondition>::vfunc_2 (11 B): matches/0x0004ef40.cpp
// sym: ?vfunc_2@?$ParamBool@VCSmartPropAttachedCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<CSmartPropAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0004ef80 fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_7 (6 B): matches/0x0004ef80.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCSmartPropAttachedCondition@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0004ef90 fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_6 (30 B): matches/0x0004ef90.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCSmartPropAttachedCondition@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4ef90 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4ef90*)&DAT_003f335c));
}


// 0x0004efb0 fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_8 (26 B): matches/0x0004efb0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCSmartPropAttachedCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropAttachedCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropAttachedCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropAttachedCondition>::**)(int))&this->f_18))(b);
}


// 0x0004efd0 fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_2 (11 B): matches/0x0004efd0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCSmartPropAttachedCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0004f000 fight::ParamIntConstRange<CSmartPropAttachedCondition>::vfunc_6 (26 B): matches/0x0004f000.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VCSmartPropAttachedCondition@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropAttachedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropAttachedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropAttachedCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropAttachedCondition>::**)(int))&this->f_10))(b);
}


// 0x0004f020 fight::ParamIntConstRange<CSmartPropAttachedCondition>::vfunc_2 (11 B): matches/0x0004f020.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VCSmartPropAttachedCondition@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<CSmartPropAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}

