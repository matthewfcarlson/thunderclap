// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153910..0x001539f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitWaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2ce2565 {
#define TREE_TU_END }
namespace fn_f2ce2565 {} using namespace fn_f2ce2565;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f2ce2565 {
class CStageCondition_153930;
class ParamValue_153930 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153930 : public ParamValue_153930 {
  public:
    int pad;
};
struct CAxisArcCondition_153970;
class CStageCondition_153980 {};
class ParamValue_153980 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_153980 : public ParamValue_153980 {
  public:
    virtual void f();
};

} // namespace fn_f2ce2565

// 0x00153910 fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::vfunc_6 (26 B): matches/0x00153910.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitWaitTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::**)(int))&this->f_10))(b);
}


// 0x00153930 fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::vfunc_2 (11 B): matches/0x00153930.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitWaitTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitWaitTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153970 fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_7 (6 B): matches/0x00153970.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHitWaitTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00153980 fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_6 (30 B): matches/0x00153980.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHitWaitTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_153980 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_153980*)&DAT_003f335c));
}


// 0x001539a0 fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_8 (26 B): matches/0x001539a0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHitWaitTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::**)(int))&this->f_18))(b);
}


// 0x001539c0 fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_2 (11 B): matches/0x001539c0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHitWaitTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitWaitTrack>::vfunc_2() {
    return this->f_18 == 0;
}

