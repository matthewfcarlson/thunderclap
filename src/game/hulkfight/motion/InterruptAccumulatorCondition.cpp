// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00154000 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptAccumulatorCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fda7990a {
#define TREE_TU_END }
namespace fn_fda7990a {} using namespace fn_fda7990a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fda7990a {
class CStageCondition_153f60;
class ParamValue_153f60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153f60 : public ParamValue_153f60 {
  public:
    int pad;
};
extern "C" int __cdecl Check(void*, int, void*, void*, int);
} // namespace fn_fda7990a
namespace fight {
class ConditionFactoryCaster_153f80 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class InterruptAccumulatorCondition_153f80 {};
} }
namespace fn_fda7990a {
extern char DAT_004b1bf0;

} // namespace fn_fda7990a

// 0x00153f40 fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::vfunc_6 (26 B): matches/0x00153f40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VNoHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::**)(int))&this->f_10))(b);
}


// 0x00153f60 fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::vfunc_2 (11 B): matches/0x00153f60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VNoHitPushbackTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::NoHitPushbackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153f80 fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0 (36 B): matches/0x00153f80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b1bf0, 0) != 0;
}


// 0x00153fb0 fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0 (30 B): matches/0x00153fb0.cpp
// sym: ??_G?$ParamEnumConstList@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::InterruptAccumulatorCondition>::~ParamEnumConstList() {}


// 0x00153fd0 fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::vfunc_0 (30 B): matches/0x00153fd0.cpp
// sym: ??_G?$ParamFloatConstRange@VInterruptAccumulatorCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::InterruptAccumulatorCondition>::~ParamFloatConstRange() {}

