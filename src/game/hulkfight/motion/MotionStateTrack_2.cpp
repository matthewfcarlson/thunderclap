// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001781f0..0x001782d0 (kind game, layer game, confidence high), dominant class hulkfight::motion::MotionStateTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3c36804 {
#define TREE_TU_END }
namespace fn_f3c36804 {} using namespace fn_f3c36804;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3c36804 {
class CStageCondition_178210;
class ParamValue_178210 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178210 : public ParamValue_178210 {
  public:
    int pad;
};
struct CAxisArcCondition_178250;
class CStageCondition_178260 {};
class ParamValue_178260 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_178260 : public ParamValue_178260 {
  public:
    virtual void f();
};

} // namespace fn_f3c36804

// 0x001781f0 fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::vfunc_6 (26 B): matches/0x001781f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMotionStateTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::**)(int))&this->f_10))(b);
}


// 0x00178210 fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::vfunc_2 (11 B): matches/0x00178210.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMotionStateTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00178250 fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_7 (6 B): matches/0x00178250.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VMotionStateTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00178260 fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_6 (30 B): matches/0x00178260.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VMotionStateTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_178260 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_178260*)&DAT_003f335c));
}


// 0x00178280 fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_8 (26 B): matches/0x00178280.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VMotionStateTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::**)(int))&this->f_18))(b);
}


// 0x001782a0 fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_2 (11 B): matches/0x001782a0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VMotionStateTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::MotionStateTrack>::vfunc_2() {
    return this->f_18 == 0;
}

