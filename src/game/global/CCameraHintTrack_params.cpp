// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006ca70..0x0006cb50 (kind game, layer game, confidence high), dominant class CCameraHintTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffce4a98 {
#define TREE_TU_END }
namespace fn_ffce4a98 {} using namespace fn_ffce4a98;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffce4a98 {
class CStageCondition_6ca90;
class ParamValue_6ca90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6ca90 : public ParamValue_6ca90 {
  public:
    int pad;
};
class CStageCondition_6cae0 {};
class ParamValue_6cae0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_6cae0 : public ParamValue_6cae0 {
  public:
    virtual void f();
};

} // namespace fn_ffce4a98

// 0x0006ca70 fight::ParamFloatConstRange<CCameraHintTrack>::vfunc_6 (26 B): matches/0x0006ca70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VCCameraHintTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCameraHintTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCameraHintTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCameraHintTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CCameraHintTrack>::**)(int))&this->f_10))(b);
}


// 0x0006ca90 fight::ParamFloatConstRange<CCameraHintTrack>::vfunc_2 (11 B): matches/0x0006ca90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VCCameraHintTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<CCameraHintTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0006cad0 fight::ParamEnumConstList<CCameraHintTrack>::vfunc_7 (6 B): matches/0x0006cad0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VCCameraHintTrack@@@fight@@UAEHH@Z
template <> int fight::ParamEnumConstList<CCameraHintTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0006cae0 fight::ParamEnumConstList<CCameraHintTrack>::vfunc_6 (30 B): matches/0x0006cae0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VCCameraHintTrack@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<CCameraHintTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_6cae0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_6cae0*)&DAT_003f335c));
}


// 0x0006cb00 fight::ParamEnumConstList<CCameraHintTrack>::vfunc_8 (26 B): matches/0x0006cb00.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VCCameraHintTrack@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCameraHintTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CCameraHintTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CCameraHintTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CCameraHintTrack>::**)(int))&this->f_18))(b);
}


// 0x0006cb20 fight::ParamEnumConstList<CCameraHintTrack>::vfunc_2 (11 B): matches/0x0006cb20.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VCCameraHintTrack@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<CCameraHintTrack>::vfunc_2() {
    return this->f_18 == 0;
}

