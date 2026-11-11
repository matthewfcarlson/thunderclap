// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00185650..0x00185730 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropMissileCountCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa7f775a {
#define TREE_TU_END }
namespace fn_fa7f775a {} using namespace fn_fa7f775a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fa7f775a {
class CStageCondition_185670;
class ParamValue_185670 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_185670 : public ParamValue_185670 {
  public:
    int pad;
};
struct CAxisArcCondition_1856b0;
class CStageCondition_1856c0 {};
class ParamValue_1856c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1856c0 : public ParamValue_1856c0 {
  public:
    virtual void f();
};

} // namespace fn_fa7f775a

// 0x00185650 fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::vfunc_6 (26 B): matches/0x00185650.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::**)(int))&this->f_10))(b);
}


// 0x00185670 fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::vfunc_2 (11 B): matches/0x00185670.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001856b0 fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_7 (6 B): matches/0x001856b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001856c0 fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_6 (30 B): matches/0x001856c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1856c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1856c0*)&DAT_003f335c));
}


// 0x001856e0 fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_8 (26 B): matches/0x001856e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::**)(int))&this->f_18))(b);
}


// 0x00185700 fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_2 (11 B): matches/0x00185700.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VPropMissileCountCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition>::vfunc_2() {
    return this->f_18 == 0;
}

