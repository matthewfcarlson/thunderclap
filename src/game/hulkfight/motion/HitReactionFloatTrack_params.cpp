// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001535c0..0x00153720 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionFloatTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f28ebaec {
#define TREE_TU_END }
namespace fn_f28ebaec {} using namespace fn_f28ebaec;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f28ebaec {
class CStageCondition_1535e0;
class ParamValue_1535e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1535e0 : public ParamValue_1535e0 {
  public:
    int pad;
};
struct CAxisArcCondition_153620;
class CStageCondition_153630 {};
class ParamValue_153630 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_153630 : public ParamValue_153630 {
  public:
    virtual void f();
};
class CStageCondition_1536c0;
class ParamValue_1536c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1536c0 : public ParamValue_1536c0 {
  public:
    int pad;
};
class CStageCondition_153710;
class ParamValue_153710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153710 : public ParamValue_153710 {
  public:
    int pad;
};

} // namespace fn_f28ebaec

// 0x001535c0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_6 (26 B): matches/0x001535c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_10))(b);
}


// 0x001535e0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_2 (11 B): matches/0x001535e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153620 fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_7 (6 B): matches/0x00153620.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00153630 fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_6 (30 B): matches/0x00153630.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_153630 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_153630*)&DAT_003f335c));
}


// 0x00153650 fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_8 (26 B): matches/0x00153650.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_18))(b);
}


// 0x00153670 fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_2 (11 B): matches/0x00153670.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitReactionFloatTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001536a0 fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_6 (26 B): matches/0x001536a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_10))(b);
}


// 0x001536c0 fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_2 (11 B): matches/0x001536c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitReactionFloatTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001536f0 fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::vfunc_6 (26 B): matches/0x001536f0.cpp
// sym: ?vfunc_6@?$ParamBool@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::**)(int))&this->f_10))(b);
}


// 0x00153710 fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::vfunc_2 (11 B): matches/0x00153710.cpp
// sym: ?vfunc_2@?$ParamBool@VHitReactionFloatTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitReactionFloatTrack>::vfunc_2() {
    return this->f_10 == 0;
}

