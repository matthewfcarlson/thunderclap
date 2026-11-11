// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153720..0x00153910 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitReactionTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd4c568f {
#define TREE_TU_END }
namespace fn_fd4c568f {} using namespace fn_fd4c568f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd4c568f {
class ParamValueFloat_153720 {
  public:
    ParamValueFloat_153720(int);
    virtual void f();
};
class ParamFloatConstRange_153720 : public ParamValueFloat_153720 {
  public:
    ParamFloatConstRange_153720(int, int);
    char pad[12];
    int value;
    virtual void f();
};
class CStageCondition_153760;
class ParamValue_153760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153760 : public ParamValue_153760 {
  public:
    int pad;
};
class CStageCondition_1537b0;
class ParamValue_1537b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1537b0 : public ParamValue_1537b0 {
  public:
    int pad;
};
struct CAxisArcCondition_1537f0;
class CStageCondition_153800 {};
class ParamValue_153800 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_153800 : public ParamValue_153800 {
  public:
    virtual void f();
};
class CStageCondition_153890;
class ParamValue_153890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153890 : public ParamValue_153890 {
  public:
    int pad;
};
class CStageCondition_1538e0;
class ParamValue_1538e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1538e0 : public ParamValue_1538e0 {
  public:
    int pad;
};


// 0x00153720 FUN_00153720 (32 B): matches/0x00153720.cpp
// sym: ??0ParamFloatConstRange_153720@fn_fd4c568f@@QAE@HH@Z
ParamFloatConstRange_153720::ParamFloatConstRange_153720(int a, int b) : ParamValueFloat_153720(a) {
    value = b;
}

} // namespace fn_fd4c568f

// 0x00153740 fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_6 (26 B): matches/0x00153740.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitPauseTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::**)(int))&this->f_10))(b);
}


// 0x00153760 fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_2 (11 B): matches/0x00153760.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitPauseTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00153790 fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::vfunc_6 (26 B): matches/0x00153790.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VHitPauseTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_10))(b);
}


// 0x001537b0 fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::vfunc_2 (11 B): matches/0x001537b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VHitPauseTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitReactionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001537f0 fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_7 (6 B): matches/0x001537f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VHitReactionTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00153800 fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_6 (30 B): matches/0x00153800.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VHitReactionTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_153800 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_153800*)&DAT_003f335c));
}


// 0x00153820 fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_8 (26 B): matches/0x00153820.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_18))(b);
}


// 0x00153840 fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_2 (11 B): matches/0x00153840.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::HitReactionTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00153870 fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::vfunc_6 (26 B): matches/0x00153870.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_10))(b);
}


// 0x00153890 fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::vfunc_2 (11 B): matches/0x00153890.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HitReactionTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001538c0 fight::ParamBool<hulkfight::motion::HitReactionTrack>::vfunc_6 (26 B): matches/0x001538c0.cpp
// sym: ?vfunc_6@?$ParamBool@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitReactionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::HitReactionTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::HitReactionTrack>::**)(int))&this->f_10))(b);
}


// 0x001538e0 fight::ParamBool<hulkfight::motion::HitReactionTrack>::vfunc_2 (11 B): matches/0x001538e0.cpp
// sym: ?vfunc_2@?$ParamBool@VHitReactionTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::HitReactionTrack>::vfunc_2() {
    return this->f_10 == 0;
}

