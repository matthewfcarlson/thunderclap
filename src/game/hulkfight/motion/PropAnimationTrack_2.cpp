// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185b40..0x00185c70 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAnimationTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc168308 {
#define TREE_TU_END }
namespace fn_fc168308 {} using namespace fn_fc168308;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc168308 {
class CStageCondition_185b60;
class ParamValue_185b60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185b60 : public ParamValue_185b60 {
  public:
    int pad;
};
class CStageCondition_185bb0;
class ParamValue_185bb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185bb0 : public ParamValue_185bb0 {
  public:
    int pad;
};
struct CAxisArcCondition_185bf0;
class CStageCondition_185c00 {};
class ParamValue_185c00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_185c00 : public ParamValue_185c00 {
  public:
    virtual void f();
};

} // namespace fn_fc168308

// 0x00185b40 fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_6 (26 B): matches/0x00185b40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x00185b60 fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_2 (11 B): matches/0x00185b60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185b90 fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_6 (26 B): matches/0x00185b90.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x00185bb0 fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_2 (11 B): matches/0x00185bb0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00185bf0 fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_7 (6 B): matches/0x00185bf0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00185c00 fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_6 (30 B): matches/0x00185c00.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_185c00 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_185c00*)&DAT_003f335c));
}


// 0x00185c20 fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_8 (26 B): matches/0x00185c20.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::**)(int))&this->f_18))(b);
}


// 0x00185c40 fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_2 (11 B): matches/0x00185c40.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VPropAnimationTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_2() {
    return this->f_18 == 0;
}

