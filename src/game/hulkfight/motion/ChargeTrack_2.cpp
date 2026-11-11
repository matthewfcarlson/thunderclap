// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177860..0x00177990 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb36527e {
#define TREE_TU_END }
namespace fn_fb36527e {} using namespace fn_fb36527e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb36527e {
class CStageCondition_177880;
class ParamValue_177880 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177880 : public ParamValue_177880 {
  public:
    int pad;
};
struct CAxisArcCondition_1778c0;
class CStageCondition_1778d0 {};
class ParamValue_1778d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1778d0 : public ParamValue_1778d0 {
  public:
    virtual void f();
};
class CStageCondition_177960;
class ParamValue_177960 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177960 : public ParamValue_177960 {
  public:
    int pad;
};

} // namespace fn_fb36527e

// 0x00177860 fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::vfunc_6 (26 B): matches/0x00177860.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VChargeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::**)(int))&this->f_10))(b);
}


// 0x00177880 fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::vfunc_2 (11 B): matches/0x00177880.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VChargeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::ChargeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001778c0 fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_7 (6 B): matches/0x001778c0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VChargeTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001778d0 fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_6 (30 B): matches/0x001778d0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VChargeTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1778d0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1778d0*)&DAT_003f335c));
}


// 0x001778f0 fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_8 (26 B): matches/0x001778f0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VChargeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::**)(int))&this->f_18))(b);
}


// 0x00177910 fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_2 (11 B): matches/0x00177910.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VChargeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::ChargeTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00177940 fight::ParamBool<hulkfight::motion::ChargeTrack>::vfunc_6 (26 B): matches/0x00177940.cpp
// sym: ?vfunc_6@?$ParamBool@VChargeTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ChargeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::ChargeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::ChargeTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::ChargeTrack>::**)(int))&this->f_10))(b);
}


// 0x00177960 fight::ParamBool<hulkfight::motion::ChargeTrack>::vfunc_2 (11 B): matches/0x00177960.cpp
// sym: ?vfunc_2@?$ParamBool@VChargeTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::ChargeTrack>::vfunc_2() {
    return this->f_10 == 0;
}

