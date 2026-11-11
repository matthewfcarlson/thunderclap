// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001697d0..0x001698a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleHealthCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0b3000e {
#define TREE_TU_END }
namespace fn_f0b3000e {} using namespace fn_f0b3000e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f0b3000e {
struct CAxisArcCondition_1697d0;
class CStageCondition_1697e0 {};
class ParamValue_1697e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1697e0 : public ParamValue_1697e0 {
  public:
    virtual void f();
};
class CStageCondition_169870;
class ParamValue_169870 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169870 : public ParamValue_169870 {
  public:
    int pad;
};

} // namespace fn_f0b3000e

// 0x001697d0 fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_7 (6 B): matches/0x001697d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001697e0 fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_6 (30 B): matches/0x001697e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1697e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1697e0*)&DAT_003f335c));
}


// 0x00169800 fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_8 (26 B): matches/0x00169800.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::**)(int))&this->f_18))(b);
}


// 0x00169820 fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_2 (11 B): matches/0x00169820.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00169850 fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::vfunc_6 (26 B): matches/0x00169850.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::**)(int))&this->f_10))(b);
}


// 0x00169870 fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::vfunc_2 (11 B): matches/0x00169870.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>::vfunc_2() {
    return this->f_10 == 0;
}

