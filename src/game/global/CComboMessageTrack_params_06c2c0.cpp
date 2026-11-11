// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006c2c0..0x0006c3f0 (kind game, layer game, confidence high), dominant class CComboMessageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3f6b772 {
#define TREE_TU_END }
namespace fn_f3f6b772 {} using namespace fn_f3f6b772;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3f6b772 {
class CStageCondition_6c2e0;
class ParamValue_6c2e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c2e0 : public ParamValue_6c2e0 {
  public:
    int pad;
};
class CStageCondition_6c330;
class ParamValue_6c330 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6c330 : public ParamValue_6c330 {
  public:
    int pad;
};
struct CAxisArcCondition_6c370;
class CStageCondition_6c380 {};
class ParamValue_6c380 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_6c380 : public ParamValue_6c380 {
  public:
    virtual void f();
};

} // namespace fn_f3f6b772

// 0x0006c2c0 fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_6 (26 B): matches/0x0006c2c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCComboMessageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CComboMessageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CComboMessageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CComboMessageTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c2e0 fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_2 (11 B): matches/0x0006c2e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCComboMessageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c310 fight::ParamString<CComboMessageTrack>::vfunc_6 (26 B): matches/0x0006c310.cpp
// sym: ?vfunc_6@?$ParamString@VCComboMessageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<CComboMessageTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CComboMessageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CComboMessageTrack>*)a)->*(*(bool (fight::ParamString<CComboMessageTrack>::**)(int))&this->f_10))(b);
}


// 0x0006c330 fight::ParamString<CComboMessageTrack>::vfunc_2 (11 B): matches/0x0006c330.cpp
// sym: ?vfunc_2@?$ParamString@VCComboMessageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<CComboMessageTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006c370 fight::ParamEnumConstList<CComboMessageTrack>::vfunc_7 (6 B): matches/0x0006c370.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCComboMessageTrack@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<CComboMessageTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0006c380 fight::ParamEnumConstList<CComboMessageTrack>::vfunc_6 (30 B): matches/0x0006c380.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCComboMessageTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CComboMessageTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_6c380 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_6c380*)&DAT_003f335c));
}


// 0x0006c3a0 fight::ParamEnumConstList<CComboMessageTrack>::vfunc_8 (26 B): matches/0x0006c3a0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCComboMessageTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CComboMessageTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CComboMessageTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CComboMessageTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CComboMessageTrack>::**)(int))&this->f_18))(b);
}


// 0x0006c3c0 fight::ParamEnumConstList<CComboMessageTrack>::vfunc_2 (11 B): matches/0x0006c3c0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCComboMessageTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CComboMessageTrack>::vfunc_2() {
    return this->f_18 == 0;
}

